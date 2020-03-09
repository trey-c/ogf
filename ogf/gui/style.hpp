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
#include <ogf/primative/rect.hpp>

namespace Ogf
{

namespace Gui
{

class Style
{
public:
    Style();

    void set_background(const Primative::Color &c);
    void set_border(const Primative::Color &c, int r, int t);
    void set_padding(const Primative::Rect &p);
    void set_font(const Primative::Color &c, const std::string &f, int s);

    const Primative::Color &background_color() const;
    const Primative::Color &border_color() const;
    const Primative::Color &font_color() const;
    const Primative::Rect &padding() const;
    const int &border_thickness() const;
    const int &border_radius() const;
    const int &font_size() const;
    const std::string &font_family() const;

private:
    Primative::Color m_background_color;
    Primative::Color m_border_color;
    Primative::Color m_font_color;
    Primative::Rect m_padding;
    int m_border_thickness;
    int m_border_radius;
    int m_font_size;
    std::string m_font_family;
};

}

}