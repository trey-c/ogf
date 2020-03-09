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

#include <ogf/primative/color.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    Primative::Color color(55, 155, 205);

    assert(color.r() == 55);
    assert(color.g() == 155);
    assert(color.b() == 205);
    assert(color.a() == 255);

    color.set_r(1);
    color.set_g(2);
    color.set_b(3);
    color.set_a(4);

    assert(color.r() == 1);
    assert(color.g() == 2);
    assert(color.b() == 3);
    assert(color.a() == 4);

    Primative::Color color1;
    Primative::Color color2;

    assert((color1 == color2) == true);
    assert((color1 != color2) == false);

    color1.set_r(33);

    assert((color1 == color2) == false);
    assert((color1 != color2) == true);

    return 0;
}