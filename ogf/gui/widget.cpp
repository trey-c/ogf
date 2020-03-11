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
    : ignore_state_change(false), m_parent(nullptr), m_visible(false)
{
    _init_size_policy();

    on_parent_request += [](Widget &w) {
        dlg_error("Widget can't be a parent");
    };

    if (w)
        w->on_parent_request(*this);
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
}

void Widget::hide()
{
    m_visible = false;
}

Backend::Client *Widget::client()
{
    return nullptr;
}

void Widget::set_position(const Primative::Point &p)
{
    m_position = p;
}

void Widget::set_size(const Primative::Size &s)
{
    if (s.width() >= m_min_size.width())
        m_size.set_width(s.width());
    else
        m_size.set_width(m_min_size.width());

    if (s.height() >= m_min_size.height())
        m_size.set_height(s.height());
    else
        m_size.set_height(m_min_size.height());
}

void Widget::set_min_size(const Primative::Size &s)
{
    m_min_size = s;
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

const Primative::Point &Widget::position() const
{
    return m_position;
}

const Primative::Size &Widget::size() const
{
    return m_size;
}

const Primative::Size &Widget::min_size() const
{
    return m_min_size;
}

const Primative::Rect Widget::area() const
{
    return Primative::Rect(m_position, m_size);
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

void Widget::paint_style(Backend::Painter &p)
{
    p.color(m_style.background_color());
    p.rect(Primative::Rect(0, 0, size().width(), size().height()));
    p.fill();

    if (m_style.border_thickness() > 0) {
        p.color(m_style.border_color());
        p.rect(Primative::Rect(0, 0, size().width(), size().height()));
        p.stroke();
    }
}

void Widget::_init_size_policy()
{
    size_policy.vertical_stretch = false;
    size_policy.horizontal_stretch = false;
}

}

}