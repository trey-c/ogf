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

#include <ogf/gui/layout.hpp>

namespace Ogf
{

namespace Gui
{

class Box : public Layout
{
public:
    enum Orientation
    {
        VERTICAL,
        HORIZONTAL
    };

    Box(const Orientation &o, int g, Widget *w);

    void set_orientation(const Orientation &o);

    const Orientation &orientation() const;

    void children_allocate() override;

private:
    Orientation m_orientation;
    int m_gap;
};

}

}
