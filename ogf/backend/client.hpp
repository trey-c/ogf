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
#include <nytl/callback.hpp>
#include <ogf/backend/painter.hpp>

namespace Ogf
{

namespace Backend
{

class Client
{
public:
    Client(const Primative::Size &s);
    virtual ~Client() = default;

    bool ignore_resize;
    Primative::Size size;
    Primative::Size min_size;

    nytl::Callback<void()> on_quit;
    nytl::Callback<void(Backend::Painter &p)> on_paint;
    nytl::Callback<void(const Primative::Size &s)> on_resize;
    nytl::Callback<void(int k, const Primative::Point &p)> on_key_press;
    nytl::Callback<void(int k, const Primative::Point &p)> on_key_release;
    nytl::Callback<void(const Primative::Point &p)> on_mouse_move;
    nytl::Callback<void(int b, const Primative::Point &p)> on_mouse_press;
    nytl::Callback<void(int b, const Primative::Point &p)> on_mouse_release;

    virtual void map() = 0;
    virtual void unmap() = 0;
    virtual void move(const Primative::Point &p) = 0;
    virtual void resize(const Primative::Size &s) = 0;
    virtual void set_size_limits(const Primative::Size &min,
                                 const Primative::Size &max) = 0;
    virtual void set_title(const std::string &t) = 0;
    virtual void paint() = 0;
    virtual Painter *painter() const = 0;
};

}

}