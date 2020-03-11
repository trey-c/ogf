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

#include <ogf/gl/context.hpp>

#include <dlg/dlg.hpp>
#include <glib.h>

namespace Ogf
{

namespace Gl
{

Context::Context() : m_cr(nullptr), m_surface(nullptr)
{
}

void PangoFont::set_description(const std::string &s)
{
    description = pango_font_description_from_string(s.c_str());
}

Primative::Size Context::text_ink_size(const PangoFont &f, const std::string &t)
{
    cairo_surface_t *temp = nullptr;

    if (!m_cr) {
        dlg_warn("gl: cairo context null");

        temp = cairo_image_surface_create(CAIRO_FORMAT_RGB24, 100, 100);
        update_surface(temp);
    }

    auto layout = pango_cairo_create_layout(m_cr);
    PangoRectangle ink, logical;

    pango_layout_set_font_description(layout, f.description);
    pango_layout_set_text(layout, t.c_str(), -1);
    pango_layout_get_pixel_extents(layout, &ink, &logical);

    g_object_unref(layout);

    if (temp)
        flush();

    return Primative::Size(ink.width, ink.height);
}

void Context::text(const PangoFont &f, const std::string &t)
{
    auto layout = pango_cairo_create_layout(m_cr);

    pango_layout_set_font_description(layout, f.description);
    pango_layout_set_text(layout, t.c_str(), -1);

    pango_cairo_update_layout(m_cr, layout);
    pango_cairo_show_layout(m_cr, layout);

    g_object_unref(layout);
}

void Context::update_surface(cairo_surface_t *s)
{
    m_cr = cairo_create(s);
    m_surface = s;
}

void Context::flush()
{
    cairo_surface_flush(m_surface);

    cairo_destroy(m_cr);
    cairo_surface_destroy(m_surface);

    m_cr = nullptr;
    m_surface = nullptr;
}

void Context::color(const Primative::Color &c)
{
    cairo_set_source_rgba(m_cr, (static_cast<double>(c.r()) / 256),
                          (static_cast<double>(c.g()) / 256),
                          (static_cast<double>(c.b()) / 256),
                          (static_cast<double>(c.a()) / 256));
}

void Context::rectangle(const Primative::Rect &r)
{
    cairo_rectangle(m_cr, r.x(), r.y(), r.width(), r.height());
}

void Context::fill()
{
    cairo_fill(m_cr);
}

void Context::stroke()
{
    cairo_stroke(m_cr);
}

void Context::save()
{
    cairo_save(m_cr);
}

void Context::restore()
{
    cairo_restore(m_cr);
}

void Context::clip()
{
    cairo_clip(m_cr);
}

void Context::move_to(const Primative::Point &p)
{
    cairo_move_to(m_cr, p.x(), p.y());
}

void Context::translate(const Primative::Point &p)
{
    cairo_translate(m_cr, p.x(), p.y());
}

}

}