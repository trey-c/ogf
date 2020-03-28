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

#include <ogf/gui/widget.hpp>

#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Gui
{

Widget::Widget(Widget *w)
    : min_size(1, 1),
      ignore_state_change(false),
      m_parent(nullptr),
      m_visible(false)
{
    _init_size_policy();

    on_paint += [this](Backend::Painter &p) {
        paint_style(p);

        children_on_paint(p);
    };

    on_key_press += [this](int k, const Primative::Point &p) {
        children_on_key_press(k, p);
    };

    on_mouse_move += [this](const Primative::Point &p) {
        children_on_mouse_move(p);
    };

    on_mouse_press += [this](int b, const Primative::Point &p) {
        children_on_mouse_press(b, p);
    };

    on_mouse_release += [this](int b, const Primative::Point &p) {
        children_on_mouse_release(b, p);
    };

    on_state_change += [this]() {
        if (ignore_state_change)
            return;

        allocate_children();

        children_on_state_change();
    };

    if (w)
        w->add(*this);
}

void Widget::add(Widget &w)
{
    if (w.parent())
        return;

    w.set_parent(*this);

    m_children.push_back(&w);
}

void Widget::remove(Widget &w)
{
    m_children.erase(std::remove(m_children.begin(), m_children.end(), &w),
                     m_children.end());
}

void Widget::repaint(bool r)
{
    if (m_parent)
        m_parent->repaint(r);
    else
        dlg_warn("widget: Can't repaint without parent");
}

void Widget::show()
{
    m_visible = true;

    on_state_change();
}

void Widget::hide()
{
    m_visible = false;
}

void Widget::show_all()
{
    for (auto child : m_children) {
        child->show_all();
    }

    show();
}

void Widget::set_parent(Widget &w)
{
    m_parent = &w;
}

void Widget::set_style(const Style &s)
{
    m_style = s;
}

void Widget::set_hovered(bool h)
{
    m_hovered = h;
}

void Widget::set_size_easy(const Primative::Size &s)
{
    size.width = s.width >= min_size.width ? s.width : min_size.width;
    size.height = s.height >= min_size.height ? s.height : min_size.height;
}

Widget *Widget::parent() const
{
    return m_parent;
}

Style &Widget::style()
{
    return m_style;
}

const bool &Widget::visible() const
{
    return m_visible;
}

const bool &Widget::hovered() const
{
    return m_hovered;
}

const Primative::Rect Widget::area() const
{
    return Primative::Rect(position, size);
}

const std::vector<Widget *> &Widget::children() const
{
    return m_children;
}

void Widget::allocate_children()
{
}

void Widget::children_on_paint(Backend::Painter &p)
{
    for (auto child : m_children) {
        p.save();
        p.translate(child->position);

        p.rect(Primative::Rect(0, 0, child->size.width, child->size.height));
        p.clip();

        child->on_paint(p);
        p.restore();
    }
}

void Widget::children_on_key_press(int k, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_key_press(k, child_position_offset(child, p));
    }
}

void Widget::children_on_key_release(int k, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_key_release(k, child_position_offset(child, p));
    }
}

void Widget::children_on_mouse_move(const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p)) {
            if (!child->hovered()) {
                child->set_hovered(true);
                child->on_mouse_enter();
            }

            child->on_mouse_move(child_position_offset(child, p));
        } else {
            if (child->hovered()) {
                child->set_hovered(false);
                child->on_mouse_leave();
            }
        }
    }
}

void Widget::children_on_mouse_press(int b, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_mouse_press(b, child_position_offset(child, p));
    }
}

void Widget::children_on_mouse_release(int b, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_mouse_release(b, child_position_offset(child, p));
    }
}

void Widget::children_on_state_change()
{
    for (auto child : m_children) {
        child->on_state_change();
    }
}

void Widget::paint_style(Backend::Painter &p)
{
    p.color(m_style.background_color());
    p.rect(Primative::Rect(0, 0, size.width, size.height));
    p.fill();

    if (m_style.border_thickness() > 0) {
        p.color(m_style.border_color());
        p.rect(Primative::Rect(0, 0, size.width, size.height));
        p.stroke();
    }
}

Primative::Point Widget::child_position_offset(const Widget *w,
                                               const Primative::Point &p)
{
    return Primative::Point(p.x - w->position.x, p.y - w->position.y);
}

Backend::Client *Widget::client()
{
    return nullptr;
}

Backend::Client *Widget::find_client()
{
    auto widget = &(*this);

    while (widget->parent() != nullptr)
        widget = widget->parent();

    if (!widget->client())
        dlg_warn("widget: Cannot find client");

    return widget->client();
}

void Widget::_init_size_policy()
{
    size_policy.vertical_stretch = false;
    size_policy.horizontal_stretch = false;
}

}

}