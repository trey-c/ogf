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

#include <cairo/cairo.h>
#include <memory>
#include <ogf/primative/color.hpp>
#include <ogf/primative/rect.hpp>
#include <ogf/primative/size.hpp>
#include <pango/pangocairo.h>
#include <string>

namespace Ogf
{

namespace Gl
{

struct PangoFont
{
    PangoFontDescription *description;

    void set_description(const std::string &s);
};

class Context
{
public:
    Context();

    Primative::Size text_ink_size(const PangoFont &f, const std::string &t);
    void text(const PangoFont &f, const std::string &t);
    void update_surface(cairo_surface_t *s);
    void flush();
    void color(const Primative::Color &c);
    void rectangle(const Primative::Rect &r);
    void fill();
    void stroke();
    void save();
    void restore();
    void clip();
    void move_to(const Primative::Point &p);
    void translate(const Primative::Point &p);

private:
    cairo_t *m_cr;
    cairo_surface_t *m_surface;
};

}

}