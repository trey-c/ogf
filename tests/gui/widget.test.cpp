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

#include <ogf/gui/widget.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    auto widget = Gui::Widget(nullptr);

    widget.size_policy.vertical_stretch = true;
    assert(widget.size_policy.vertical_stretch == true);
    assert(widget.size_policy.horizontal_stretch == false);

    assert(!widget.visible());
    widget.show();
    assert(widget.visible());
    widget.hide();
    assert(!widget.visible());

    return 0;
}