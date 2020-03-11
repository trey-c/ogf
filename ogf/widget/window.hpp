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
#include <ogf/Backend/client.hpp>
#include <ogf/gui/layout.hpp>
#include <string>

namespace Ogf
{

namespace Widget
{

class Window : public Gui::Layout
{
public:
    Window(const std::string &t, std::shared_ptr<Core::Application> a);

    nytl::Callback<void()> on_quit;

    void set_title(const std::string &t);
    void close(bool e);

    void children_allocate() override;
    void show() override;
    void hide() override;
    Backend::Client *client() override;

    void set_position(const Primative::Point &p) override;
    void set_size(const Primative::Size &s) override;
    void set_min_size(const Primative::Size &s) override;
    void repaint(bool r) override;

private:
    std::unique_ptr<Backend::Client> m_client;
    std::shared_ptr<Core::Application> m_application;

    void _init_client(const std::string &t);
};

}

}
