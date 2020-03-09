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

#include <ogf/platform/client.hpp>
#include <ogf/xcb/driver.hpp>

namespace Ogf
{

namespace Xcb
{

class Client : public Platform::Client
{
public:
    Client(Driver &d);
    ~Client();

    struct
    {
        xcb_intern_atom_reply_t *wm_protocols;
        xcb_intern_atom_reply_t *wm_delete_window;
    } atoms;

    const xcb_window_t &window() const;
    const Driver *driver() const;

    void map() override;
    void unmap() override;
    void move(const Primative::Point &p) override;
    void resize(const Primative::Size &s) override;
    void set_size_limits(const Primative::Size &min,
                         const Primative::Size &max) override;
    void set_title(const std::string &t) override;
    Platform::Painter *painter() const override;

private:
    Driver *m_driver;
    xcb_window_t m_window;
    std::unique_ptr<Platform::Painter> m_painter;

    void _init_window();
    void _init_atoms();
};

}

}
