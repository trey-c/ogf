/*
 * Ogf - Ocicat GUI Framework
 * Copyright © 2020 Trey Cutter <treycutter@protonmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation version 2.1
 * of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <ogf/win32/client.hpp>

#include <dlg/dlg.hpp>
#include <ogf/backend/painter.hpp>
#include <string.h>
#include <windowsx.h>

namespace Ogf
{

namespace Win32
{

Client::Client(Driver &d, const Primative::Size &s)
    : Backend::Client(s), m_driver(&d)
{
    m_driver->add_client(*this);

    m_gl_context = std::make_unique<Gl::Context>();
    m_painter = std::make_unique<Backend::Painter>(*m_gl_context.get());

    _init_window(s);
}

Client::~Client()
{
    m_driver->remove_client(*this);
}

const Driver *Client::driver() const
{
    return m_driver;
}

Gl::Context *Client::gl_context()
{
    return m_gl_context.get();
}

void Client::map()
{
    ShowWindow(window, 1);

    UpdateWindow(window);
}

void Client::unmap()
{
    ShowWindow(window, 0);

    UpdateWindow(window);
}

void Client::move(const Primative::Point &p)
{
    SetWindowPos(window, 0, p.x, p.y, 0, 0, SWP_NOSIZE);

    UpdateWindow(window);
}

void Client::resize(const Primative::Size &s)
{
    if (size == s)
        return;

    ignore_resize = true;
    SetWindowPos(window, 0, 0, 0, s.width, s.height,
                 SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
    ignore_resize = false;
}

void Client::set_size_limits(const Primative::Size &min,
                             const Primative::Size &max)
{
    min_size = min;
}

void Client::set_borderless(bool b)
{
    if (b)
        SetWindowLongPtrW(window, GWL_STYLE,
                          WS_POPUP);
    else
        SetWindowLongPtr(window, GWLP_USERDATA, (LONG_PTR)this);

    UpdateWindow(window);
}

void Client::set_title(const std::string &t)
{
    SetWindowTextA(window, (LPCSTR)t.c_str());
}

void Client::paint()
{
    InvalidateRect(window, nullptr, false);
    UpdateWindow(window);
}

Backend::Painter *Client::painter() const
{
    return m_painter.get();
}

void Client::_init_window(const Primative::Size &s)
{
    WNDCLASS window_class;

    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = _window_proc;
    window_class.cbClsExtra = 0;
    window_class.cbWndExtra = 0;
    window_class.hInstance = m_driver->instance();
    window_class.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    window_class.lpszMenuName = nullptr;
    window_class.lpszClassName = TEXT("window");

    RegisterClass(&window_class);

    window = CreateWindowEx(0, TEXT("window"), nullptr, WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, s.width, s.height,
                            nullptr, nullptr, m_driver->instance(), nullptr);

    set_borderless(false);

    SetWindowLongPtr(window, GWLP_USERDATA, (LONG_PTR)this);

    UpdateWindow(window);
}

LRESULT CALLBACK Client::_window_proc(HWND win, UINT msg, WPARAM wp, LPARAM lp)
{
    auto client = (Client *)GetWindowLongPtr(win, GWLP_USERDATA);

    switch (msg) {
    case WM_MOUSEACTIVATE:
    case WM_CAPTURECHANGED: {
        return true;

        break;
    }
    case WM_SIZE: {
        RECT result;
        GetClientRect(win, &result);

        Primative::Size new_size(result.right - result.left,
                                 result.bottom - result.top);

        if (client && new_size != client->size &&
            client->ignore_resize == false) {
            client->size = new_size;
            client->on_resize(new_size);
        }

        return true;

        break;
    }
    case WM_KEYDOWN:
    case WM_KEYUP: {
        if (!client)
            return true;

        if (msg == WM_KEYDOWN) {
            client->on_key_press(
                wp, Primative::Point(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)));
        } else if (msg == WM_KEYUP) {
            client->on_key_release(
                wp, Primative::Point(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)));
        }

        return true;

        break;
    }
    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
    case WM_XBUTTONUP: {
        if (!client)
            return true;

        int button = 1;

        if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP)
            button = 1;
        else if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP)
            button = 2;
        else if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONUP)
            button = 3;
        else
            button += (3 + GET_XBUTTON_WPARAM(wp));

        if (msg == WM_LBUTTONDOWN || msg == WM_RBUTTONDOWN ||
            msg == WM_MBUTTONDOWN || msg == WM_XBUTTONDOWN) {
            client->on_mouse_release(
                button, Primative::Point(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)));
        } else {
            client->on_mouse_press(
                button, Primative::Point(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)));
        }

        return true;

        break;
    }
    case WM_MOUSEMOVE: {
        if (!client)
            return true;

        client->on_mouse_move(
            Primative::Point(GET_X_LPARAM(lp), GET_Y_LPARAM(lp)));

        return true;

        break;
    }
    case WM_PAINT: {
        if (!client)
            return true;

        PAINTSTRUCT paint_struct;
        auto dc = BeginPaint(win, &paint_struct);

        client->gl_context()->update_surface(cairo_win32_surface_create(dc));
        client->on_paint(*client->painter());
        client->gl_context()->flush();

        EndPaint(win, &paint_struct);
        dlg_info("win32: Painting");

        break;
    }
    case WM_GETMINMAXINFO: {
        LPMINMAXINFO min_max_info = (LPMINMAXINFO)lp;

        if (client) {
            min_max_info->ptMinTrackSize.x = client->min_size.width * 2;
            min_max_info->ptMinTrackSize.y = client->min_size.height * 2;
        }

        break;
    }
    case WM_DESTROY: {
        if (client)
            client->on_quit();

        break;
    }
    default:
        break;
    }

    return DefWindowProc(win, msg, wp, lp);
}

}

}