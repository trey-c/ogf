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

#include "ogf/core/application.hpp"
#include <ogf/gui/button.hpp>
#include <ogf/gui/window.hpp>

class Window : public Ogf::Gui::Window
{
public:
    Window(std::shared_ptr<Ogf::Core::Application> a);

private:
    Ogf::Gui::Box *m_box;
    Ogf::Gui::Label *m_status;
    Ogf::Gui::Button *m_clicker;
    Ogf::Gui::Button *m_reset;
    int m_counter;

    void _build_ui();
};