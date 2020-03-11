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

#include <list>
#include <memory>
#include <ogf/backend/client.hpp>

namespace Ogf
{

namespace Backend
{

class Driver
{
public:
    Driver();
    virtual ~Driver() = default;

    virtual int main_loop() = 0;
    virtual std::unique_ptr<Client> create_client(const Primative::Size &s) = 0;

    void add_client(Client &c);
    void remove_client(Client &c);
    void exit();

    const std::list<Client *> &clients() const;
    const bool &running() const;

private:
    std::list<Client *> m_clients;
    bool m_running;
};

}

}
