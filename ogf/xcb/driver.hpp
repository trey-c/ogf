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

#include <ogf/platform/driver.hpp>
#include <xcb/xcb.h>

namespace Ogf
{

namespace Xcb
{

class Driver : public Platform::Driver
{
public:
    Driver();
    ~Driver();

    xcb_connection_t *connection() const;
    xcb_screen_t *screen() const;

    std::unique_ptr<Platform::Client> create_client() override;
    std::unique_ptr<Platform::Painter>
    create_painter(Platform::Client &w) override;
    int main_loop() override;

private:
    xcb_connection_t *m_connection;
    xcb_screen_t *m_screen;

    void _filter_event(xcb_generic_event_t *event);
    Platform::Client *_find_client(xcb_window_t *w);
};

}

}
