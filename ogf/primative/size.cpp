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

#include <ogf/primative/size.hpp>

namespace Ogf
{

namespace Primative
{

Size::Size() : width(0), height(0)
{
}

Size::Size(int w, int h) : width(w), height(h)
{
}

bool Size::operator==(const Size &s) const
{
    return (width == s.width && height == s.height);
}

bool Size::operator!=(const Size &s) const
{
    return (width != s.width || height != s.height);
}

const std::string Size::to_string() const
{
    return "Size(width: " + std::to_string(width) +
           ", height: " + std::to_string(height) + ")";
}

}

}