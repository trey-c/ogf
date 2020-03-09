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

#include <ogf/widget/label.hpp>

#include <assert.h>

using namespace Ogf;

int main(int argc, char **argv)
{
    auto label1 = Widget::Label("Test", nullptr);
    auto label2 = Widget::Label("Test 2", nullptr);

    assert(label1.min_size().width() < label2.min_size().width());

    label1.set_text("Test Change");

    assert(label1.min_size().width() > label2.min_size().width());

    return 0;
}