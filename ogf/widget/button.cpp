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

#include <ogf/widget/button.hpp>

#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Widget
{

Button::Button(const std::string &t, Gui::Widget *w)
    : Layout(w), m_label(t, this)
{
    m_label.set_text(t);
    m_label.show();

    style().set_background(Primative::Color(55, 55, 55, 255));
    style().set_border(Primative::Color(15, 15, 15), 0, 10);

    on_mouse_press.clear();
    on_mouse_press += [this](int b, const Primative::Point &p) {
        /* Active color */
        style().set_background(Primative::Color(45, 45, 45, 255));
        repaint(false);

        children_on_mouse_press(b, p);
    };

    on_mouse_release.clear();
    on_mouse_release += [this](int b, const Primative::Point &p) {
        on_click(*this);

        /* Hover color */
        style().set_background(Primative::Color(65, 65, 65, 255));
        repaint(false);

        children_on_mouse_release(b, p);
    };

    on_mouse_enter += [this]() {
        dlg_debug("Mouse entered button with label '{}'", label().text());

        /* Hovered color */
        style().set_background(Primative::Color(65, 65, 65, 255));
        repaint(false);
    };

    on_mouse_leave += [this]() {
        dlg_debug("Mouse left button with label '{}'", label().text());

        /* Default color */
        style().set_background(Primative::Color(55, 55, 55, 255));
        repaint(false);
    };

    /* Should be called in Label::set_text */
    on_state_change();
}

Label &Button::label()
{
    return m_label;
}

void Button::children_allocate()
{
    m_label.set_position(Primative::Point(0, 0));
    m_label.set_size(size());

    Primative::Size new_min_size;
    new_min_size.set_width(m_label.min_size().width() +
                           (style().border_thickness() * 2));
    new_min_size.set_height(m_label.min_size().height() +
                            (style().border_thickness() * 2));

    set_min_size(new_min_size);
}

}

}
