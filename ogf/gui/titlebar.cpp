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

#include <ogf/gui/titlebar.hpp>

#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Gui
{

Titlebar::Titlebar(const std::string &t, Widget *w)
    : Widget(w), m_client(nullptr), m_pressed(false), m_drag(false)
{
    style().set_background(Primative::Color(25, 25, 25, 255));
    style().set_border(Primative::Color(0, 0, 0), 0, 0);

    m_client = find_client();

    if (m_client)
        dlg_error("titlebar: Cannot find client");

    m_client->on_mouse_move += [this](const Primative::Point &p) {
        if (m_drag) {
            // int new_x = m_client->position.x + (p.x - m_mouse_position.x);
            // int new_y = m_client->position.y + (p.y - m_mouse_position.y);

            // m_client->move(Primative::Point(new_x, new_y));
        }

        if (m_pressed) {
            // int new_h = m_client->size.height + (p.y - m_mouse_position.y);

            // if (p.y <= 5)
            //     m_client->resize(Primative::Size(m_client->size.width,
            //     new_h));
        }

        children_on_mouse_move(p);
    };

    m_client->on_mouse_press += [this](int b, const Primative::Point &p) {
        m_mouse_position.x = p.x;
        m_mouse_position.y = p.y;

        m_pressed = true;

        if (!area().contains(p)) {
            m_drag = true;
        }

        children_on_mouse_press(b, p);
    };

    m_client->on_mouse_release += [this](int b, const Primative::Point &p) {
        m_pressed = false;
        m_drag = false;

        children_on_mouse_release(b, p);
    };

    m_box = new Box(Box::Orientation::HORIZONTAL, 5, this);

    m_title = new Label(t, m_box);
    m_title->set_text(t);

    m_spacer = new Spacer(true, Primative::Size(5, 5), m_box);

    m_min = new Button("-", m_box);
    m_max = new Button("[]", m_box);
    m_close = new Button("X", m_box);

    m_close->on_click += [&](Button &b) {
        m_client->on_quit();
    };
}

void Titlebar::allocate_children()
{
    m_box->set_size_easy(size);
    min_size = m_box->min_size;
}

}

}