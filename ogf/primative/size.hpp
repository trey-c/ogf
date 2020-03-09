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

#include <string>

namespace Ogf
{

namespace Primative
{

class Size
{
public:
    Size();
    Size(int w, int h);

    void set_width(int w);
    void set_height(int h);

    const int &width() const;
    const int &height() const;

    bool operator==(const Size &s) const;
    bool operator!=(const Size &s) const;

    const std::string to_string() const;

private:
    int m_width;
    int m_height;
};

}

}