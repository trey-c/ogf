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

#include <dlg/dlg.hpp>
#include <ogf/core/application.hpp>
#include <ogf/widget/button.hpp>
#include <ogf/widget/window.hpp>

using namespace Ogf;

int main(int argc, char **argv)
{
    auto application = Core::Application::shared(argc, argv);

    auto window = Widget::Window("Demo Application", application);
    auto button = Widget::Button("Button", &window);

    button.on_click += [&](Widget::Button &b) {
        static int counter = 0;

        b.label().set_text("Clicked " + std::to_string(counter++));
        dlg_info("Button with label '{}' clicked", b.label().text());
    };
    window.on_quit += [&]() {
        application->exit();
    };

    window.show_all();

    return application->exec();
}
