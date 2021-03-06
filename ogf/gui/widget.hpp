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
#include <ogf/backend/client.hpp>
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

    Primative::Point position;
    Primative::Size size;
    Primative::Size min_size;

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

    virtual void add(Widget &w);
    virtual void remove(Widget &w);
    virtual void repaint(bool r);
    virtual void show();
    virtual void hide();

    void show_all();

    void set_parent(Widget &w);
    void set_style(const Style &s);
    void set_hovered(bool h);
    void set_size_easy(const Primative::Size &s);

    Widget *parent() const;
    Style &style();
    const bool &visible() const;
    const bool &hovered() const;
    const Primative::Rect area() const;
    const std::vector<Widget *> &children() const;

    virtual Backend::Client *client();

    Backend::Client *find_client();

protected:
    bool ignore_state_change;

    virtual void allocate_children();

    void children_on_paint(Backend::Painter &p);
    void children_on_key_press(int k, const Primative::Point &p);
    void children_on_key_release(int k, const Primative::Point &p);
    void children_on_mouse_move(const Primative::Point &p);
    void children_on_mouse_press(int b, const Primative::Point &p);
    void children_on_mouse_release(int b, const Primative::Point &p);
    void children_on_state_change();
    void paint_style(Backend::Painter &p);

    Primative::Point child_position_offset(const Widget *w,
                                           const Primative::Point &p);

private:
    Widget *m_parent;
    Style m_style;
    bool m_visible;
    bool m_hovered;
    std::vector<Widget *> m_children;

    void _init_size_policy();
};

}

}