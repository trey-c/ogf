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

#include <ogf/xcb/font.hpp>

#include <string>

namespace Ogf
{

namespace Xcb
{

Font::Font(const std::string &f, int s) : Platform::Font(f, s)
{
    _update();
}

void Font::set_family(const std::string &f)
{
    Platform::Font::set_family(f);

    _update();
}

void Font::set_size(int s)
{
    Platform::Font::set_size(s);

    _update();
}

void Font::_update()
{
    auto family_fix = std::string(family()) + " " + std::to_string(size());

    m_gl_font.set_description(family_fix);
}

const Gl::PangoFont &Font::gl_font() const
{
    return m_gl_font;
}

}

}