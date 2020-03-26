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

#include <ogf/gui/spacer.hpp>

namespace Ogf
{

namespace Gui
{

Spacer::Spacer(bool s, const Primative::Size &min, Widget *w) : Widget(w)
{
    min_size = min;

    size_policy.horizontal_stretch = s;
    size_policy.vertical_stretch = s;
}

void Spacer::set_space(bool s, const Primative::Size &min)
{
    min_size = min;

    size_policy.horizontal_stretch = s;
    size_policy.vertical_stretch = s;

    repaint(true);
}

}

}