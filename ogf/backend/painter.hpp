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

#include <memory>
#include <ogf/backend/font.hpp>
#include <ogf/gl/context.hpp>
#include <ogf/primative/color.hpp>
#include <ogf/primative/rect.hpp>

namespace Ogf
{

namespace Backend
{

class Painter
{
public:
    Painter(Gl::Context &ctx);

    void color(const Primative::Color &c);
    void rect(const Primative::Rect &r);
    void fill();
    void stroke();
    void save();
    void restore();
    void clip();
    void move(const Primative::Point &p);
    void translate(const Primative::Point &p);
    void text(const Font &f, const std::string &t);
    std::unique_ptr<Font> create_font(const std::string &f, int s);
    Primative::Size predict_text_size(const Font &f, const std::string &t);

private:
    Gl::Context *m_gl_context;
};

}

}