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

#include <ogf/win32/client.hpp>

#include <assert.h>
#include <dlg/dlg.hpp>

using namespace Ogf;

int main(int argc, char **argv)
{
    Win32::Driver driver;

    auto client = driver.create_client(Primative::Size(100, 100));

    auto font = client->painter()->create_font("Sans Bold", 11);

    client->on_paint += [&](Backend::Painter &p) {
        client->painter()->rect(Primative::Rect(0, 0, client->size().width(),
                                                client->size().height()));
        client->painter()->color(Primative::Color(33, 33, 33));
        client->painter()->fill();
        client->painter()->color(Primative::Color(255, 255, 255));
        client->painter()->text(*font.get(), "Test Text");
        client->painter()->fill();
    };

    client->resize(Primative::Size(800, 800));
    client->paint();

    client->on_mouse_press += [](int b, const Primative::Point &p) {
        dlg_debug("Pressed {}", b);
    };

    client->on_mouse_release += [](int b, const Primative::Point &p) {
        dlg_debug("Released {}", b);
    };

    client->on_quit += [&]() {
        driver.exit();
    };

    return driver.main_loop();
}