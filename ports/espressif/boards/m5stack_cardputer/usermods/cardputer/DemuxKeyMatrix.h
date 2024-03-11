/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2024 CDarius
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

#ifndef MICROPY_INCLUDED_SHARED_MODULE_CARDPUTER_DEMUXKEYMATRIX_H
#define MICROPY_INCLUDED_SHARED_MODULE_CARDPUTER_DEMUXKEYMATRIX_H

#include "py/obj.h"
#include "py/objtuple.h"

#include "common-hal/digitalio/DigitalInOut.h"
#include "shared-module/keypad/__init__.h"
#include "shared-module/keypad/EventQueue.h"

typedef struct {
    KEYPAD_SCANNER_COMMON_FIELDS;
    mp_obj_tuple_t *row_addr_digitalinouts;
    mp_obj_tuple_t *column_digitalinouts;
} cardputer_demuxkeymatrix_obj_t;

void cardputer_demuxkeymatrix_scan(cardputer_demuxkeymatrix_obj_t *self);

void common_hal_cardputer_demuxkeymatrix_construct(cardputer_demuxkeymatrix_obj_t *self, mp_uint_t num_row_addr_pins, const mcu_pin_obj_t *row_addr_pins[], mp_uint_t num_column_pins, const mcu_pin_obj_t *column_pins[], mp_float_t interval, size_t max_events);

void common_hal_cardputer_demuxkeymatrix_deinit(cardputer_demuxkeymatrix_obj_t *self);

void common_hal_cardputer_demuxkeymatrix_key_number_to_row_column(cardputer_demuxkeymatrix_obj_t *self, mp_uint_t key_number, mp_uint_t *row, mp_uint_t *column);
mp_uint_t common_hal_cardputer_demuxkeymatrix_row_column_to_key_number(cardputer_demuxkeymatrix_obj_t *self, mp_uint_t row, mp_uint_t column);

size_t common_hal_cardputer_demuxkeymatrix_get_column_count(cardputer_demuxkeymatrix_obj_t *self);
size_t common_hal_cardputer_demuxkeymatrix_get_row_count(cardputer_demuxkeymatrix_obj_t *self);

#endif  // MICROPY_INCLUDED_SHARED_MODULE_CARDPUTER_DEMUXKEYMATRIX_H
