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

#include <ogf/xcb/client.hpp>

#include <cairo-xcb.h>
#include <dlg/dlg.hpp>
#include <ogf/backend/painter.hpp>
#include <string.h>
#include <xcb/xcb_icccm.h>

namespace Ogf
{

namespace Xcb
{

Client::Client(Driver &d, const Primative::Size &s)
    : Backend::Client(s), m_driver(&d)
{
    m_driver->add_client(*this);
    size = s;

    m_gl_context = std::make_unique<Gl::Context>();
    m_painter = std::make_unique<Backend::Painter>(*m_gl_context.get());

    _init_window();
}

Client::~Client()
{
    m_driver->remove_client(*this);
}

const xcb_window_t &Client::window() const
{
    return m_window;
}

const Driver *Client::driver() const
{
    return m_driver;
}

void Client::map()
{
    xcb_map_window(m_driver->connection(), m_window);

    xcb_flush(m_driver->connection());
}

void Client::unmap()
{
    xcb_unmap_window(m_driver->connection(), m_window);

    xcb_flush(m_driver->connection());
}

void Client::move(const Primative::Point &p)
{
    int flags = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y;
    int values[] = {p.x, p.y};

    xcb_configure_window(m_driver->connection(), m_window, flags, values);

    xcb_flush(m_driver->connection());
}

void Client::resize(const Primative::Size &s)
{
    if (size == s)
        return;

    int flags = XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
    int values[] = {s.width, s.height};

    ignore_resize = true;
    xcb_configure_window(m_driver->connection(), m_window, flags, values);

    xcb_flush(m_driver->connection());
    ignore_resize = false;
}

void Client::set_size_limits(const Primative::Size &min,
                             const Primative::Size &max)
{
    xcb_size_hints_t hints;

    min_size.width = min.width;
    min_size.height = min.height;

    xcb_icccm_size_hints_set_min_size(&hints, static_cast<int16_t>(min.width),
                                      static_cast<int16_t>(min.height));

    xcb_icccm_size_hints_set_max_size(&hints, static_cast<int16_t>(max.width),
                                      static_cast<int16_t>(max.height));

    /* I don't know why but the display server loves to crash here */
    // xcb_icccm_set_wm_size_hints(m_driver->connection(), m_window,
    //                             XCB_ATOM_WM_NORMAL_HINTS, &hints);

    xcb_flush(m_driver->connection());
}

void Client::set_borderless(bool b)
{
    struct
    {
        uint32_t flags;
        uint32_t functions;
        uint32_t decorations;
    } wm_hints;

    wm_hints.flags = 2;
    wm_hints.functions = 0;
    wm_hints.decorations = !b;

    xcb_intern_atom_cookie_t cookie3 =
        xcb_intern_atom(m_driver->connection(), 0, strlen("_MOTIF_WM_HINTS"),
                        "_MOTIF_WM_HINTS");
    xcb_intern_atom_reply_t *reply3 =
        xcb_intern_atom_reply(m_driver->connection(), cookie3, nullptr);

    xcb_change_property(m_driver->connection(), XCB_PROP_MODE_REPLACE, m_window,
                        reply3->atom, reply3->atom, 32, 5, &wm_hints);

    xcb_flush(m_driver->connection());

    free(reply3);
}

void Client::set_title(const std::string &t)
{
    xcb_change_property(m_driver->connection(), XCB_PROP_MODE_REPLACE, m_window,
                        XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, strlen(t.c_str()),
                        t.c_str());
    xcb_flush(m_driver->connection());
}

void Client::paint()
{
    m_gl_context->update_surface(cairo_xcb_surface_create(
        m_driver->connection(), m_window, m_driver->find_visual(), size.width,
        size.height));

    on_paint(*m_painter.get());

    m_gl_context->flush();
    xcb_flush(m_driver->connection());
}

Backend::Painter *Client::painter() const
{
    return m_painter.get();
}

void Client::_init_window()
{
    int mask = 0;
    int values[3];

    m_window = xcb_generate_id(m_driver->connection());

    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = m_driver->screen()->white_pixel;
    values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_BUTTON_PRESS |
                XCB_BUTTON_RELEASE | XCB_MOTION_NOTIFY | XCB_KEY_PRESS |
                XCB_KEY_RELEASE | XCB_EXPOSE | XCB_EVENT_MASK_STRUCTURE_NOTIFY |
                XCB_EVENT_MASK_POINTER_MOTION;

    xcb_create_window(m_driver->connection(), m_driver->screen()->root_depth,
                      m_window, m_driver->screen()->root,
                      static_cast<int16_t>(0), static_cast<int16_t>(0),
                      static_cast<int16_t>(size.width),
                      static_cast<int16_t>(size.height),
                      static_cast<int16_t>(10), XCB_WINDOW_CLASS_INPUT_OUTPUT,
                      m_driver->screen()->root_visual, mask, values);

    update_geometry();

    _init_atoms();
}

void Client::_init_atoms()
{
    auto protocol_cookie =
        xcb_intern_atom(m_driver->connection(), 1, 12, "WM_PROTOCOLS");

    auto delete_window_cookie =
        xcb_intern_atom(m_driver->connection(), 0, 16, "WM_DELETE_WINDOW");

    atoms.wm_protocols =
        xcb_intern_atom_reply(m_driver->connection(), protocol_cookie, 0);
    atoms.wm_delete_window =
        xcb_intern_atom_reply(m_driver->connection(), delete_window_cookie, 0);

    xcb_change_property(m_driver->connection(), XCB_PROP_MODE_REPLACE, m_window,
                        (*atoms.wm_protocols).atom, 4, 32, 1,
                        &(*atoms.wm_delete_window).atom);
}

void Client::update_geometry()
{
    auto cookie = xcb_get_geometry(m_driver->connection(), m_window);
    auto reply =
        xcb_get_geometry_reply(m_driver->connection(), cookie, nullptr);

    if (!reply)
        return;

    position.x = reply->x;
    position.y = reply->y;
    size.width = reply->width;
    size.height = reply->height;

    free(reply);
}

}

}