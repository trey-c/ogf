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
 * License along with this library; if not, write to the Fzree Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <demo/window.hpp>

using namespace Ogf;

Window::Window(std::shared_ptr<Core::Application> a)
    : Gui::Window("Demo Application", a), m_counter(0)
{
    _build_ui();
}

void Window::_build_ui()
{
    m_box = new Gui::Box(Gui::Box::Orientation::VERTICAL, 5, this);

    m_status = new Gui::Label("Counter", m_box);
    m_status->size_policy.vertical_stretch = true;
    m_status->set_text("Counter");

    m_clicker = new Gui::Button("Clicker", m_box);
    m_reset = new Gui::Button("Reset", m_box);
    
    m_clicker->on_click += [this](Gui::Button &b) {
        m_status->set_text("Clicker " + std::to_string(++m_counter));
        m_status->repaint(true);
    };

    m_reset->on_click += [this](Gui::Button &b) {
        m_status->set_text("Clicker was reseted at " +
                           std::to_string(m_counter));
        m_counter = 0;
        m_status->repaint(true);
    };
}