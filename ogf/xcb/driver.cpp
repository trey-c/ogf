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

#include <ogf/xcb/driver.hpp>

#include <dlg/dlg.hpp>
#include <ogf/primative/size.hpp>
#include <ogf/xcb/client.hpp>

namespace Ogf
{

namespace Xcb
{

Driver::Driver()
{
    m_connection = xcb_connect(NULL, NULL);
    m_screen = xcb_setup_roots_iterator(xcb_get_setup(m_connection)).data;
}

Driver::~Driver()
{
    xcb_disconnect(m_connection);
}

xcb_visualtype_t *Driver::find_visual()
{
    auto depth_iter = xcb_screen_allowed_depths_iterator(m_screen);

    for (; depth_iter.rem; xcb_depth_next(&depth_iter)) {
        auto visual_iter = xcb_depth_visuals_iterator(depth_iter.data);

        for (; visual_iter.rem; xcb_visualtype_next(&visual_iter)) {
            if (m_screen->root_visual == visual_iter.data->visual_id) {
                return visual_iter.data;
            }
        }
    }
    return nullptr;
}

xcb_connection_t *Driver::connection() const
{
    return m_connection;
}

xcb_screen_t *Driver::screen() const
{
    return m_screen;
}

int Driver::main_loop()
{
    xcb_generic_event_t *event;

    if (!running())
        return 0;

    while ((event = xcb_wait_for_event(m_connection)) && running()) {
        _filter_event(event);

        free(event);
    }

    return 0;
}

std::unique_ptr<Backend::Client> Driver::create_client(const Primative::Size &s)
{
    return std::make_unique<Client>(*this, s);
}

void Driver::_filter_event(xcb_generic_event_t *event)
{
    switch (event->response_type & ~0x80) {
    case XCB_EXPOSE: {
        auto *ev = (xcb_expose_event_t *)event;

        auto client = _find_client(&ev->window);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->paint();
        break;
    }
    case XCB_KEY_PRESS: {
        auto *ev = (xcb_key_press_event_t *)event;

        auto client = _find_client(&ev->event);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->on_key_press(ev->detail,
                             Primative::Point(ev->event_x, ev->event_y));
        break;
    }
    case XCB_KEY_RELEASE: {
        auto *ev = (xcb_key_release_event_t *)event;

        auto client = _find_client(&ev->event);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->on_key_release(ev->detail,
                               Primative::Point(ev->event_x, ev->event_y));
        break;
    }
    case XCB_MOTION_NOTIFY: {
        auto *ev = (xcb_motion_notify_event_t *)event;

        auto client = _find_client(&ev->event);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->on_mouse_move(Primative::Point(ev->event_x, ev->event_y));
        break;
    }
    case XCB_BUTTON_PRESS: {
        auto *ev = (xcb_motion_notify_event_t *)event;

        auto client = _find_client(&ev->event);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->on_mouse_press(ev->detail,
                               Primative::Point(ev->event_x, ev->event_y));
        break;
    }
    case XCB_BUTTON_RELEASE: {
        auto *ev = (xcb_motion_notify_event_t *)event;

        auto client = _find_client(&ev->event);

        if (!client)
            return;

        xcb_flush(m_connection);
        client->on_mouse_release(ev->detail,
                                 Primative::Point(ev->event_x, ev->event_y));
        break;
    }
    case XCB_CONFIGURE_NOTIFY: {
        auto *ev = (xcb_configure_notify_event_t *)event;

        auto client = static_cast<Xcb::Client *>(_find_client(&ev->event));

        if (!client || client->ignore_resize)
            return;

        client->update_geometry();
        client->on_resize(client->size);
        break;
    }

    case XCB_CLIENT_MESSAGE: {
        auto *ev = (xcb_client_message_event_t *)event;
        auto client = static_cast<Xcb::Client *>(_find_client(&ev->window));

        if (!client)
            return;

        if (ev->data.data32[0] == client->atoms.wm_delete_window->atom) {
            client->on_quit();
        }

        break;
    }

    default:
        break;
    }
}

Backend::Client *Driver::_find_client(xcb_window_t *w)
{
    for (Backend::Client *c : clients()) {
        if (static_cast<Xcb::Client *>(c)->window() == *w)
            return c;
    }

    return nullptr;
}

}

}