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
#include <ogf/gui/box.hpp>
#include <ogf/gui/button.hpp>
#include <ogf/gui/label.hpp>
#include <ogf/gui/spacer.hpp>

namespace Ogf
{

namespace Gui
{

class Titlebar : public Widget
{
public:
    Titlebar(const std::string &t, Widget *w);

    void allocate_children() override;

private:
    Backend::Client *m_client;

    Box *m_box;
    Label *m_title;
    Spacer *m_spacer;
    Button *m_min;
    Button *m_max;
    Button *m_close;

    bool m_pressed;
    bool m_drag;
    Primative::Point m_mouse_position;
};

}

}
