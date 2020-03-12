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

namespace Ogf
{

namespace Primative
{

Color::Color() : r(255), g(255), b(255), a(255)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a)
{
}

const std::string Color::to_string() const
{
    return "Color(r: " + std::to_string(r) + ", g: " + std::to_string(g) +
           ", b: " + std::to_string(b) + ", a: " + std::to_string(a) + ")";
}

bool Color::operator==(const Color &c) const
{
    return (r == c.r && g == c.g && b == c.b && a == c.a);
}

bool Color::operator!=(const Color &c) const
{
    return (r != c.r || g != c.g || b != c.b || a != c.a);
}

}

}