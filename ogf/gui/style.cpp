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

#include <ogf/gui/style.hpp>

namespace Ogf
{

namespace Gui
{

Style::Style()
{
}

void Style::set_background(const Primative::Color &c)
{
    m_background_color = c;
}

void Style::set_border(const Primative::Color &c, int r, int t)
{
    m_border_color = c;
    m_border_radius = r;
    m_border_thickness = t;
}

void Style::set_padding(const Primative::Rect &p)
{
    m_padding = p;
}

void Style::set_font(const Primative::Color &c, const std::string &f, int s)
{
    m_font_color = c;
    m_font_family = f;
    m_font_size = s;
}

const Primative::Color &Style::background_color() const
{
    return m_background_color;
}

const Primative::Color &Style::border_color() const
{
    return m_border_color;
}

const Primative::Color &Style::font_color() const
{
    return m_font_color;
}

const Primative::Rect &Style::padding() const
{
    return m_padding;
}

const int &Style::border_thickness() const
{
    return m_border_thickness;
}

const int &Style::border_radius() const
{
    return m_border_radius;
}

const int &Style::font_size() const
{
    return m_font_size;
}

const std::string &Style::font_family() const
{
    return m_font_family;
}

}

}