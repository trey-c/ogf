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

#include <ogf/primative/point.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    Primative::Point point(3, 5);

    assert(point.x == 3);
    assert(point.y == 5);

    Primative::Point point1;
    Primative::Point point2;

    assert((point1 == point2) == true);
    assert((point1 != point2) == false);

    point1.x = 27;

    assert((point1 == point2) == false);
    assert((point1 != point2) == true);

    return 0;
}
