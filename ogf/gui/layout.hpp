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

#pragma once

#include <list>
#include <ogf/gui/widget.hpp>

namespace Ogf
{

namespace Gui
{

class Layout : public Widget
{
public:
    Layout(Widget *w);

    virtual void add(Widget &w);
    virtual void remove(Widget &w);

    void show_all();
    void children_on_paint(Backend::Painter &p);
    void children_on_key_press(int k, const Primative::Point &p);
    void children_on_key_release(int k, const Primative::Point &p);
    void children_on_mouse_move(const Primative::Point &p);
    void children_on_mouse_press(int b, const Primative::Point &p);
    void children_on_mouse_release(int b, const Primative::Point &p);
    void children_on_state_change();

    const std::list<Widget *> &children() const;

protected:
    virtual void children_allocate();

private:
    std::list<Widget *> m_children;

    Primative::Point _child_mouse_offset(const Widget *w,
                                         const Primative::Point &p);
};

}

}