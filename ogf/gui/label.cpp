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

#include <ogf/gui/label.hpp>

#include <dlg/dlg.hpp>
#include <string.h>

namespace Ogf
{

namespace Gui
{

Label::Label(const std::string &t, Widget *w) : Widget(w)
{
    set_text(t);

    style().set_font(Primative::Color(255, 255, 255), "Sans", 11);

    on_paint.clear();
    on_paint = [this](Backend::Painter &p) {
        Primative::Point text_position;

        text_position.x = (position.x + size.width / 2) - (min_size.width / 2);
        text_position.y = (position.y + size.height / 2) - (min_size.height);

        if (!m_font.get())
            dlg_error("label: Font null");

        p.color(style().font_color());
        p.move(text_position);
        p.text(*m_font.get(), m_text);
    };
}

void Label::set_text(const std::string &t)
{
    m_text = t;
    min_size = _predict_min_size();
}

const std::string &Label::text() const
{
    return m_text;
}

Primative::Size Label::_predict_min_size()
{
    auto client = find_client();

    if (client) {
        m_font = client->painter()->create_font(style().font_family(),
                                                style().font_size());

        return client->painter()->predict_text_size(*m_font.get(), m_text);
    } else {
        return Primative::Size(m_text.length(), style().font_size());
    }
}

}

}
