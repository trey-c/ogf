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

#include <ogf/gui/box.hpp>

#include <algorithm>
#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Gui
{

Box::Box(const Orientation &o, int g, Widget *w)
    : Widget(w), m_orientation(o), m_gap(g)
{
    on_paint.clear();
    on_paint += [this](Backend::Painter &p) {
        children_on_paint(p);
    };
}

void Box::set_orientation(const Orientation &o)
{
    m_orientation = o;
}

const Box::Orientation &Box::orientation() const
{
    return m_orientation;
}

void Box::allocate_children()
{
    Primative::Size new_min_size;
    Primative::Point new_child_pos;

    int i = 0;
    int length = children().capacity();
    for (auto child : children()) {
        i++;

        if (i == length - 1) {
            if (m_orientation == Orientation::HORIZONTAL)
                new_min_size.width += child->min_size.width;
            else if (m_orientation == Orientation::VERTICAL)
                new_min_size.height += child->min_size.height;
        } else {
            if (m_orientation == Orientation::HORIZONTAL)
                new_min_size.width += child->min_size.width + m_gap;
            else if (m_orientation == Orientation::VERTICAL)
                new_min_size.height += child->min_size.height + m_gap;
        }

        if (m_orientation == Orientation::HORIZONTAL)
            new_min_size.height =
                std::max(new_min_size.height, child->min_size.height);
        else if (m_orientation == Orientation::VERTICAL)
            new_min_size.width =
                std::max(new_min_size.width, child->min_size.width);
    }

    min_size = new_min_size;

    for (auto child : children()) {
        child->position = new_child_pos;

        if (m_orientation == Orientation::HORIZONTAL) {
            child->set_size_easy(
                Primative::Size(child->size.width, size.height));
            new_child_pos.x += child->size.width + m_gap;
        } else if (m_orientation == Orientation::VERTICAL) {
            child->set_size_easy(
                Primative::Size(size.width, child->size.height));
            new_child_pos.y += child->size.height + m_gap;
        }
    }
}

}

}