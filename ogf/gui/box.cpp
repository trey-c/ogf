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
    Primative::Size new_child_size;
    int length = children().capacity();
    int num_stretched = 0;
    int i = 0;

    for (auto child : children()) {
        i++;

        if (m_orientation == Orientation::HORIZONTAL) {
            if (child->size_policy.horizontal_stretch)
                num_stretched++;

            new_min_size.width += (i == length - 1) ?
                                      child->min_size.width :
                                      child->min_size.width + m_gap;

            new_min_size.height =
                std::max(new_min_size.height, child->min_size.height);

        } else if (m_orientation == Orientation::VERTICAL) {
            if (child->size_policy.vertical_stretch)
                num_stretched++;

            new_min_size.height += (i == length - 1) ?
                                       child->min_size.height :
                                       child->min_size.height + m_gap;

            new_min_size.width =
                std::max(new_min_size.width, child->min_size.width);
        }
    }

    min_size = new_min_size;

    for (auto child : children()) {
        child->position = new_child_pos;

        if (m_orientation == Orientation::HORIZONTAL) {
            if (child->size_policy.horizontal_stretch)
                new_child_size.width =
                    (m_gap * num_stretched) +
                    ((size.width - min_size.width) / num_stretched);
            else
                new_child_size.width = child->size.width;

            new_child_size = Primative::Size(new_child_size.width, size.height);
            child->set_size_easy(new_child_size);

            new_child_pos.x += child->size.width + m_gap;
        } else if (m_orientation == Orientation::VERTICAL) {
            if (child->size_policy.vertical_stretch)
                new_child_size.height =
                    (m_gap * num_stretched) +
                    ((size.height - min_size.height) / num_stretched);
            else
                new_child_size.height = child->size.height;

            new_child_size = Primative::Size(size.width, new_child_size.height);
            child->set_size_easy(new_child_size);

            new_child_pos.y += child->size.height + m_gap;
        }
    }
}

}

}