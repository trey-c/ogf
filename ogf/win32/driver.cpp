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

#include <ogf/win32/driver.hpp>

#include <dlg/dlg.hpp>
#include <ogf/primative/size.hpp>
#include <ogf/win32/client.hpp>

namespace Ogf
{

namespace Win32
{

Driver::Driver()
{
    m_instance = GetModuleHandle(nullptr);
}

Driver::~Driver()
{
}

const HINSTANCE &Driver::instance() const
{
    return m_instance;
}

int Driver::main_loop()
{
    MSG message;

    if (!running())
        return 0;

    while (GetMessage(&message, nullptr, 0, 0) && running()) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}

std::unique_ptr<Backend::Client> Driver::create_client(const Primative::Size &s)
{
    return std::make_unique<Client>(*this, s);
}

}

}