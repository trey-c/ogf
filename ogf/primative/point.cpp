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

#include <ogf/primative/point.hpp>

namespace Ogf
{

namespace Primative
{

Point::Point() : m_x(0), m_y(0)
{
}

Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

void Point::set_x(int x)
{
    m_x = x;
}

void Point::set_y(int y)
{
    m_y = y;
}

const int &Point::x() const
{
    return m_x;
}

const int &Point::y() const
{
    return m_y;
}

bool Point::operator==(const Point &p) const
{
    return (x() == p.x() && y() == p.y());
}

bool Point::operator!=(const Point &p) const
{
    return (x() != p.x() || y() != p.y());
}

const std::string Point::to_string() const
{
    return "Point(x: " + std::to_string(x()) + ", y: " + std::to_string(y()) +
           ")";
}

}

}