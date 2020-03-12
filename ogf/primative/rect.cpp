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

#include <ogf/primative/rect.hpp>

namespace Ogf
{

namespace Primative
{

Rect::Rect() : x(0), y(0), width(0), height(0)
{
}

Rect::Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h)
{
}

Rect::Rect(const Point &p, const Size &s)
    : x(p.x), y(p.y), width(s.width), height(s.height)
{
}

bool Rect::contains(const Point &p) const
{
    return (p.x >= x && p.x < x + width && p.y >= y && p.y < y + height);
}

bool Rect::operator==(const Rect &r) const
{
    return (x == r.x && y == r.y && width == r.width && height == r.height);
}

bool Rect::operator!=(const Rect &r) const
{
    return (x != r.x || y != r.y || width != r.width || height != r.height);
}

const std::string Rect::to_string() const
{
    return "Rect(x: " + std::to_string(x) + ", y: " + std::to_string(y) +
           ", width: " + std::to_string(width) +
           ", height: " + std::to_string(height) + ")";
}

}

}