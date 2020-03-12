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
#include <ogf/backend/driver.hpp>

namespace Ogf
{

namespace Core
{

class Application
{
public:
    Application(int argc, char **argv);

    static std::shared_ptr<Application> shared(int argc, char **argv);

    int exec();
    void exit();

    Backend::Driver *driver() const;

private:
    std::unique_ptr<Backend::Driver> m_driver;

    void _init_driver();
};

}

}