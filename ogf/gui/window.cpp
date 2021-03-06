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

#include <ogf/gui/window.hpp>

#include <dlg/dlg.hpp>
#include <ogf/core/application.hpp>

namespace Ogf
{

namespace Gui
{

Window::Window(const std::string &t, std::shared_ptr<Core::Application> a)
    : Widget(nullptr), m_client(nullptr), m_application(a), m_titlebar(nullptr)
{
    style().set_background(Primative::Color(33, 33, 33, 255));
    style().set_border(Primative::Color(33, 33, 33), 0, 5);

    _init_client(t);

    on_paint.clear();
    on_paint += [this](Backend::Painter &p) {
        paint_style(p);
        children_on_paint(p);
    };

    on_quit += [this]() {
        close(false);
    };

    m_titlebar = new Titlebar(t, this);
}

void Window::set_title(const std::string &t)
{
    m_client->set_title(t);
}

void Window::close(bool e)
{
    if (e)
        m_application->exit();

    hide();
}

void Window::use_native_titlebar()
{
    m_client->set_borderless(false);
    m_titlebar->hide();
}

void Window::use_no_titlebar()
{
    m_client->set_borderless(true);
    m_titlebar->hide();
}

void Window::show()
{
    m_client->map();

    m_titlebar->show_all();
    Widget::show();
}

void Window::hide()
{
    m_client->unmap();

    Widget::hide();
}

void Window::allocate_children()
{
    Primative::Point child_position;
    Primative::Size child_size;
    Primative::Size new_min_size;

    m_titlebar->set_size_easy(Primative::Size(size.width, 30));
    set_min_size(m_titlebar->min_size);

    for (auto child : children()) {
        if (child == m_titlebar)
            continue;

        child_position.x = style().border_thickness();
        child_position.y = style().border_thickness() + m_titlebar->size.height;

        child_size.width = size.width - (style().border_thickness() * 2);
        child_size.height = (size.height - (style().border_thickness() * 2) -
                             m_titlebar->size.height);

        child->position = child_position;
        child->set_size_easy(child_size);

        new_min_size.width =
            child->min_size.width + (style().border_thickness() * 2);
        new_min_size.height =
            child->min_size.height + (style().border_thickness() * 2);

        set_min_size(new_min_size);
    }
}

Backend::Client *Window::client()
{
    return m_client.get();
}

void Window::set_position(const Primative::Point &p)
{
    m_client->move(p);
}

void Window::set_size(const Primative::Size &s)
{
    m_client->resize(s);
}

void Window::set_min_size(const Primative::Size &s)
{
    if (min_size == s)
        return;

    min_size = s;

    m_client->set_size_limits(s, Primative::Size(0, 0));
}

void Window::repaint(bool r)
{
    if (r) {
        on_state_change();
    }

    m_client->paint();
}

void Window::_init_client(const std::string &t)
{
    m_client =
        m_application->driver()->create_client(Primative::Size(400, 400));

    m_client->on_paint += [this](Backend::Painter &p) {
        on_paint(*m_client->painter());
    };

    m_client->on_resize += [this](const Primative::Size &s) {
        size = s;

        on_state_change();
    };

    m_client->on_key_press += [this](int k, const Primative::Point &p) {
        on_key_press(k, p);

        on_quit();
    };

    m_client->on_mouse_move += [this](const Primative::Point &p) {
        on_mouse_move(p);
    };

    m_client->on_mouse_press += [this](int b, const Primative::Point &p) {
        on_mouse_press(b, p);
    };

    m_client->on_mouse_release += [this](int b, const Primative::Point &p) {
        on_mouse_release(b, p);
    };

    m_client->on_quit += [this]() {
        on_quit();
    };

    m_client->set_title(t);
    m_client->set_borderless(false);
}

}

}