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

#include <ogf/backend/driver.hpp>

#include <cairo-win32.h>

namespace Ogf
{

namespace Win32
{

class Driver : public Backend::Driver
{
public:
    Driver();
    ~Driver();

    const HINSTANCE &instance() const;

    std::unique_ptr<Backend::Client>
    create_client(const Primative::Size &s) override;
    int main_loop() override;

private:
    HINSTANCE m_instance;
};

}

}
