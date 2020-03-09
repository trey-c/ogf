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

#include <ogf/platform/driver.hpp>

namespace Ogf
{

namespace Platform
{

Driver::Driver() : m_running(true)
{
}

void Driver::add_client(Client &c)
{
    m_clients.push_back(&c);
}

void Driver::remove_client(Client &c)
{
    m_clients.remove(&c);
}

void Driver::exit()
{
    m_running = false;
}

const std::list<Client *> &Driver::clients() const
{
    return m_clients;
}

const bool &Driver::running() const
{
    return m_running;
}

}

}
