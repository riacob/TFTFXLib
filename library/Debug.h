/**
 * @file debug.h
 * @author Riccardo Iacob
 * @brief Handles debugging
 * @version 0.1
 * @date 2023-07-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

#define DEBUG true

// If DEBUG is enabled, define the debug statements
#if DEBUG == true
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
// If DEBUG is disabled, do not define the debug statements
#else
#define debug(x)
#define debugln(x)
#endif

#endif