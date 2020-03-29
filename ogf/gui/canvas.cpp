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

#include <ogf/gui/canvas.hpp>

namespace Ogf
{

namespace Gui
{

Canvas::Canvas(Widget *w) : Widget(w)
{
    on_paint.clear();
    on_paint = [this](Backend::Painter &p) {
        draw(p);
    };

    min_size = Primative::Size(5, 5);
}

void Canvas::draw(Backend::Painter &p)
{
    p.rect(Primative::Rect(0, 0, size.width, size.height));
    p.color(Primative::Color(255, 255, 255));
    p.fill();
}

}

}