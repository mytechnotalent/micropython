/*
 * This file is part of the MicroPython project's My Techno Talent fork, 
 * https://github.com/mytechnotalent/micropython/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2017 Damien P. George, and others
 * Copyright (c) 2020 My Techno Talent, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

 // Include required definitions first.
#include "py/obj.h"
#include "py/runtime.h"
#include "py/builtin.h"

// This is the function which will be called from Python as example.add_ints(a, b).
STATIC mp_obj_t example_add_ints(mp_obj_t a_obj, mp_obj_t b_obj) {
    // Extract the ints from the MicroPython input objects.
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);

    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(a + b);
}
// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(example_add_ints_obj, example_add_ints);

// This is the function which will be called from Python as example.subtract_ints(a, b).
STATIC mp_obj_t example_subtract_ints(mp_obj_t a_obj, mp_obj_t b_obj) {
    // Extract the ints from the MicroPython input objects.
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);

    // Calculate the addition and convert to MicroPython object.
    return mp_obj_new_int(a - b);
}
// Define a Python reference to the function above.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(example_subtract_ints_obj, example_subtract_ints);

// Define all properties of the example module.
// Table entries are key/value pairs of the attribute name (a string).
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be.
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t example_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_example) },
    { MP_ROM_QSTR(MP_QSTR_add_ints), MP_ROM_PTR(&example_add_ints_obj) },
    { MP_ROM_QSTR(MP_QSTR_subtract_ints), MP_ROM_PTR(&example_subtract_ints_obj) },
};
STATIC MP_DEFINE_CONST_DICT(example_module_globals, example_module_globals_table);

// Define module object.
const mp_obj_module_t example_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&example_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_example, example_user_cmodule, MODULE_EXAMPLE_ENABLED);