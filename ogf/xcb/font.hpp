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
#include <ogf/platform/font.hpp>

namespace Ogf
{

namespace Xcb
{

class Font : public Platform::Font
{
public:
    Font(const std::string &f, int s);

    const Gl::PangoFont &gl_font() const;

    void set_family(const std::string &f) override;
    void set_size(int s) override;

private:
    Gl::PangoFont m_gl_font;

    void _update();
};

}

}