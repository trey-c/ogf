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

#include <ogf/gui/style.hpp>

#include <assert.h>

using namespace Ogf;

int main()
{
    auto style = Gui::Style();

    style.set_background(Primative::Color(Primative::Color(45, 45, 45)));
    style.set_border(Primative::Color(55, 55, 55), 10, 25);
    style.set_padding(Primative::Rect(10, 15, 20, 30));
    style.set_font(Primative::Color(65, 65, 65), "Test", 20);

    assert(style.background_color() == Primative::Color(45, 45, 45));
    assert(style.border_color() == Primative::Color(55, 55, 55));
    assert(style.font_color() == Primative::Color(65, 65, 65));
    assert(style.border_radius() == 10);
    assert(style.border_thickness() == 25);
    assert(style.padding() == Primative::Rect(10, 15, 20, 30));
    assert(style.font_family() == "Test");
    assert(style.font_size() == 20);

    return 0;
}