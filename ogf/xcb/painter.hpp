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
#include <ogf/xcb/client.hpp>

namespace Ogf
{

namespace Xcb
{

class Painter : public Platform::Painter
{
public:
    Painter(Client &c);

    void begin_frame() override;
    void end_frame() override;
    void color(const Primative::Color &c) override;
    void rect(const Primative::Rect &r) override;
    void fill() override;
    void stroke() override;
    void save() override;
    void restore() override;
    void clip() override;
    void translate(const Primative::Point &p) override;
    void move(const Primative::Point &p) override;
    void text(const Platform::Font &f, const std::string &t) override;
    std::unique_ptr<Platform::Font> create_font(const std::string &f,
                                                int s) override;
    Primative::Size predict_text_size(const Platform::Font &f,
                                      const std::string &t) override;

private:
    Client *m_client;
    std::unique_ptr<Gl::Context> m_gl_context;

    void _init_gl_context();
    xcb_visualtype_t *_find_visual();
};

}

}