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

#include <nytl/nonCopyable.hpp>
#include <ogf/Backend/client.hpp>
#include <ogf/core/application.hpp>
#include <ogf/gui/style.hpp>
#include <ogf/primative/point.hpp>
#include <ogf/primative/size.hpp>

namespace Ogf
{

namespace Gui
{

class Widget : public nytl::NonCopyable
{
public:
    Widget(Widget *w);
    virtual ~Widget() = default;

    nytl::Callback<void()> on_state_change;
    nytl::Callback<void(Backend::Painter &p)> on_paint;
    nytl::Callback<void(int k, const Primative::Point &p)> on_key_press;
    nytl::Callback<void(int k, const Primative::Point &p)> on_key_release;
    nytl::Callback<void(const Primative::Point &p)> on_mouse_move;
    nytl::Callback<void(int b, const Primative::Point &p)> on_mouse_press;
    nytl::Callback<void(int b, const Primative::Point &p)> on_mouse_release;
    nytl::Callback<void()> on_mouse_enter;
    nytl::Callback<void()> on_mouse_leave;

    struct
    {
        bool vertical_stretch;
        bool horizontal_stretch;
    } size_policy;

    virtual void repaint(bool r);
    virtual void show();
    virtual void hide();
    virtual Backend::Client *client();

    virtual void set_position(const Primative::Point &p);
    virtual void set_size(const Primative::Size &s);
    virtual void set_min_size(const Primative::Size &s);
    void set_parent(Widget &w);
    void set_style(const Style &s);
    void set_hovered(bool h);

    Widget *parent() const;
    Style &style();
    const bool &visible() const;
    const bool &hovered() const;
    const Primative::Point &position() const;
    const Primative::Size &size() const;
    const Primative::Size &min_size() const;
    const Primative::Rect area() const;

    Backend::Client *find_client();

protected:
    bool ignore_state_change;
    nytl::Callback<void(Widget &w)> on_parent_request;

    void paint_style(Backend::Painter &p);

private:
    Widget *m_parent;
    Style m_style;
    bool m_visible;
    bool m_hovered;
    Primative::Point m_position;
    Primative::Size m_size;
    Primative::Size m_min_size;

    void _init_size_policy();
};

}

}