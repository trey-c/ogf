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

#include <ogf/gl/context.hpp>
#include <ogf/primative/size.hpp>
#include <string>

namespace Ogf
{

namespace Backend
{

class Font
{
public:
    Font(const std::string &f, int s);

    void set_family(const std::string &f);
    void set_size(int s);

    const char *family() const;
    const int &size() const;

    const Gl::PangoFont &gl_font() const;

private:
    std::string m_family;
    int m_size;

    Gl::PangoFont m_gl_font;

    void _init();
};

}

}