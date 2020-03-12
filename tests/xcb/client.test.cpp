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

#include <ogf/xcb/client.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    Xcb::Driver driver;

    auto client = driver.create_client(Primative::Size(640, 480));

    auto font = client->painter()->create_font("Sans Bold", 11);

    client->on_paint += [&](Backend::Painter &p) {
        client->painter()->rect(
            Primative::Rect(0, 0, client->size.width, client->size.height));
        client->painter()->color(Primative::Color(33, 33, 33));
        client->painter()->fill();
        client->painter()->color(Primative::Color(255, 255, 255));
        client->painter()->text(*font.get(), "Test Text");
        client->painter()->fill();
    };

    client->map();

    client->set_title("Test");
    // assert(client->size() == Primative::Size(10, 10));

    client->resize(Primative::Size(100, 100));
    client->set_size_limits(Primative::Size(100, 100), Primative::Size(-1, -1));
    client->paint();

    client->on_quit += [&]() {
        driver.exit();
    };

    // client->on_quit();

    return driver.main_loop();
}