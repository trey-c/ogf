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

#include <ogf/gui/layout.hpp>

#include <dlg/dlg.hpp>

namespace Ogf
{

namespace Gui
{

Layout::Layout(Widget *w) : Widget(w)
{
    on_paint += [this](Platform::Painter &p) {
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
        children_allocate();
    };

    on_parent_request.clear();
    on_parent_request += [this](Widget &w) {
        add(w);
    };
}

void Layout::add(Widget &w)
{
    if (w.parent())
        return;

    w.set_parent(*this);

    m_children.push_back(&w);

    on_state_change();
}

void Layout::remove(Widget &w)
{
    m_children.remove(&w);

    on_state_change();
}

void Layout::show_all()
{
    show();

    for (auto child : m_children) {
        child->show();
    }
}

void Layout::children_on_paint(Platform::Painter &p)
{
    for (auto child : m_children) {
        p.save();
        p.translate(child->position());

        p.rect(Primative::Rect(0, 0, child->size().width(),
                               child->size().height()));
        p.clip();

        child->on_paint(p);
        p.restore();
    }
}

void Layout::children_on_key_press(int k, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_key_press(k, _child_mouse_offset(child, p));
    }
}

void Layout::children_on_key_release(int k, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_key_release(k, _child_mouse_offset(child, p));
    }
}

void Layout::children_on_mouse_move(const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p)) {
            if (!child->hovered()) {
                child->set_hovered(true);
                child->on_mouse_enter();
            }

            child->on_mouse_move(_child_mouse_offset(child, p));
        } else {
            if (child->hovered()) {
                child->set_hovered(false);
                child->on_mouse_leave();
            }
        }
    }
}

void Layout::children_on_mouse_press(int b, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_mouse_press(b, _child_mouse_offset(child, p));
    }
}

void Layout::children_on_mouse_release(int b, const Primative::Point &p)
{
    for (auto child : m_children) {
        if (child->area().contains(p))
            child->on_mouse_release(b, _child_mouse_offset(child, p));
    }
}

const std::list<Widget *> &Layout::children() const
{
    return m_children;
}

void Layout::children_allocate()
{
}

Primative::Point Layout::_child_mouse_offset(const Widget *w,
                                             const Primative::Point &p)
{
    return Primative::Point(p.x() - w->position().x(),
                            p.y() - w->position().y());
}

}

}