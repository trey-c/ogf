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

#include <ogf/platform/font.hpp>

namespace Ogf
{

namespace Platform
{

Font::Font(const std::string &f, int s) : m_family(f), m_size(s)
{
}

void Font::set_family(const std::string &f)
{
    m_family = f;
}

void Font::set_size(int s)
{
    m_size = s;
}

const char *Font::family() const
{
    return m_family.c_str();
}

const int &Font::size() const
{
    return m_size;
}

}

}