// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2020 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "supervisor/board.h"
#include "mpconfigboard.h"
#include "shared-bindings/microcontroller/Pin.h"
#include "components/driver/gpio/include/driver/gpio.h"
#include "components/hal/include/hal/gpio_hal.h"
#include "common-hal/microcontroller/Pin.h"

bool espressif_board_reset_pin_number(gpio_num_t pin_number) {
    if (pin_number == 2) {
        // Turn on NeoPixel and I2C power by default.
        config_pin_as_output_with_level(pin_number, true);
        return true;
    }

    return false;
}

// Use the MP_WEAK supervisor/shared/board.c versions of routines not defined here.
