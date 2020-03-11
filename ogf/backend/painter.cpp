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

#include <ogf/backend/painter.hpp>

#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Backend
{

Painter::Painter(Gl::Context &ctx) : m_gl_context(&ctx)
{
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

void Painter::text(const Font &f, const std::string &t)
{
    m_gl_context->text(f.gl_font(), t);
}

std::unique_ptr<Backend::Font> Painter::create_font(const std::string &f, int s)
{
    return std::make_unique<Font>(f, s);
}

Primative::Size Painter::predict_text_size(const Font &f, const std::string &t)
{
    return m_gl_context->text_ink_size(f.gl_font(), t);
}

}

}