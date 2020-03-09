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

#include <ogf/core/application.hpp>

#ifdef OGF_XCB
#include <ogf/xcb/driver.hpp>
#endif

namespace Ogf
{

namespace Core
{

Application::Application(int argc, char **argv)
{
    _init_driver();
}

std::shared_ptr<Application> Application::shared(int argc, char **argv)
{
    return std::make_shared<Application>(argc, argv);
}

int Application::exec()
{
    return m_driver->main_loop();
}

void Application::exit()
{
    m_driver->exit();
}

Platform::Driver *Application::driver() const
{
    return m_driver.get();
}

void Application::_init_driver()
{
#ifdef OGF_XCB
    m_driver = std::make_unique<Xcb::Driver>();
#endif
}

}

}