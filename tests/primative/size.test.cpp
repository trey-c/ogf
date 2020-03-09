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

#include <ogf/primative/size.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    Primative::Size size(9, 4);

    assert(size.width() == 9);
    assert(size.height() == 4);

    size.set_width(1);
    size.set_height(2);

    assert(size.width() == 1);
    assert(size.height() == 2);

    Primative::Size size1;
    Primative::Size size2;

    assert((size1 == size2) == true);
    assert((size1 != size2) == false);

    size1.set_width(90);

    assert((size1 == size2) == false);
    assert((size1 != size2) == true);

    return 0;
}
