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

#include <ogf/xcb/painter.hpp>

#include <cairo/cairo-xcb.h>
#include <ogf/xcb/font.hpp>

namespace Ogf
{

namespace Xcb
{

Painter::Painter(Client &c) : m_client(&c)
{
    _init_gl_context();
}

void Painter::begin_frame()
{
    cairo_xcb_surface_set_size(m_gl_context->surface(),
                               m_client->size().width(),
                               m_client->size().height());

    m_gl_context->clear();
}

void Painter::end_frame()
{
    m_gl_context->flush();

    m_gl_context->restore();
}

void Painter::color(const Primative::Color &c)
{
    m_gl_context->color(c);
}

void Painter::rect(const Primative::Rect &r)
{
    m_gl_context->rectangle(r);
}

void Painter::fill()
{
    m_gl_context->fill();
}

void Painter::stroke()
{
    m_gl_context->stroke();
}

void Painter::save()
{
    m_gl_context->save();
}

void Painter::restore()
{
    m_gl_context->restore();
}

void Painter::clip()
{
    m_gl_context->clip();
}

void Painter::move(const Primative::Point &p)
{
    m_gl_context->move_to(p);
}

void Painter::translate(const Primative::Point &p)
{
    m_gl_context->translate(p);
}

void Painter::text(const Platform::Font &f, const std::string &t)
{
    m_gl_context->text(static_cast<const Font &>(f).gl_font(), t);
}

std::unique_ptr<Platform::Font> Painter::create_font(const std::string &f,
                                                     int s)
{
    return std::make_unique<Font>(f, s);
}

Primative::Size Painter::predict_text_size(const Platform::Font &f,
                                           const std::string &t)
{
    return m_gl_context->text_ink_size(static_cast<const Font &>(f).gl_font(),
                                       t);
}

void Painter::_init_gl_context()
{
    m_gl_context = std::make_unique<Gl::Context>(cairo_xcb_surface_create(
        m_client->driver()->connection(), m_client->window(), _find_visual(),
        m_client->size().width(), m_client->size().height()));
}

xcb_visualtype_t *Painter::_find_visual()
{
    auto depth_iter =
        xcb_screen_allowed_depths_iterator(m_client->driver()->screen());

    for (; depth_iter.rem; xcb_depth_next(&depth_iter)) {
        auto visual_iter = xcb_depth_visuals_iterator(depth_iter.data);

        for (; visual_iter.rem; xcb_visualtype_next(&visual_iter)) {
            if (m_client->driver()->screen()->root_visual ==
                visual_iter.data->visual_id) {
                return visual_iter.data;
            }
        }
    }
    return nullptr;
}

}

}
