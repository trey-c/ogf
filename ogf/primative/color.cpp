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

Color::Color() : m_r(255), m_g(255), m_b(255), m_a(255)
{
}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : m_r(r), m_g(g), m_b(b), m_a(a)
{
}

void Color::set_r(uint8_t r)
{
    m_r = r;
}

void Color::set_g(uint8_t g)
{
    m_g = g;
}

void Color::set_b(uint8_t b)
{
    m_b = b;
}

void Color::set_a(uint8_t a)
{
    m_a = a;
}

const uint8_t &Color::r() const
{
    return m_r;
}

const uint8_t &Color::g() const
{
    return m_g;
}

const uint8_t &Color::b() const
{
    return m_b;
}

const uint8_t &Color::a() const
{
    return m_a;
}

bool Color::operator==(const Color &c) const
{
    return (r() == c.r() && g() == c.g() && b() == c.b() && a() == c.a());
}

bool Color::operator!=(const Color &c) const
{
    return (r() != c.r() || g() != c.g() || b() != c.b() || a() != c.a());
}

const std::string Color::to_string() const
{
    return "Color(r: " + std::to_string(r()) + ", g: " + std::to_string(g()) +
           ", b: " + std::to_string(b()) + ", a: " + std::to_string(a()) + ")";
}

}

}