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

#include <stdint.h>
#include <string>

namespace Ogf
{

namespace Primative
{

class Color
{
public:
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    void set_r(uint8_t r);
    void set_g(uint8_t g);
    void set_b(uint8_t b);
    void set_a(uint8_t a);

    const uint8_t &r() const;
    const uint8_t &g() const;
    const uint8_t &b() const;
    const uint8_t &a() const;

    bool operator==(const Color &c) const;
    bool operator!=(const Color &c) const;

    const std::string to_string() const;

private:
    uint8_t m_r;
    uint8_t m_g;
    uint8_t m_b;
    uint8_t m_a;
};

}

}