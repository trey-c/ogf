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

#include <ogf/backend/font.hpp>
#include <ogf/gui/widget.hpp>

namespace Ogf
{

namespace Gui
{

class Label : public Widget
{
public:
    Label(const std::string &t, Widget *w);

    void set_text(const std::string &t);

    const std::string &text() const;

private:
    std::string m_text;
    std::unique_ptr<Backend::Font> m_font;

    Primative::Size _predict_min_size();
};

}

}
