/*
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "hal.h"
#include "nil_test_root.h"

/**
 * @file    nil_test_sequence_002.c
 * @brief   Test Sequence 002 code.
 *
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * @page test_sequence_001 [1] Information
=======
 * @page nil_test_sequence_002 [2] Threads Functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
 *
 * File: @ref nil_test_sequence_002.c
 *
 * <h2>Description</h2>
 * This sequence reports configuration and version information about
 * the NIL kernel.
 *
 * <h2>Test Cases</h2>
 * - @subpage nil_test_002_001
 * - @subpage nil_test_002_002
 * .
 */

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#include "ch.h"

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * @page test_001_001 [1.1] Kernel Info
=======
 * @page nil_test_002_001 [2.1] System Tick Counter functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The version numbers are reported.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * - [1.1.1] Prints the version string.
=======
 * - [2.1.1] A System Tick Counter increment is expected, the test
 *   simply hangs if it does not happen.
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
 * .
 */

static void nil_test_002_001_execute(void) {

<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
  /* [1.1.1] Prints the version string.*/
=======
  /* [2.1.1] A System Tick Counter increment is expected, the test
     simply hangs if it does not happen.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
  test_set_step(1);
  {
    test_println("--- Product:                   ChibiOS/NIL");
    test_print("--- Stable Flag:               ");
    test_printn(CH_KERNEL_STABLE);
    test_println("");
    test_print("--- Version String:            ");
    test_println(CH_KERNEL_VERSION);
    test_print("--- Major Number:              ");
    test_printn(CH_KERNEL_MAJOR);
    test_println("");
    test_print("--- Minor Number:              ");
    test_printn(CH_KERNEL_MINOR);
    test_println("");
    test_print("--- Patch Number:              ");
    test_printn(CH_KERNEL_PATCH);
    test_println("");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
static const testcase_t test_001_001 = {
  "Kernel Info",
=======
static const testcase_t nil_test_002_001 = {
  "System Tick Counter functionality",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
  NULL,
  NULL,
  nil_test_002_001_execute
};

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * @page test_001_002 [1.2] Kernel Settings
=======
 * @page nil_test_002_002 [2.2] Thread Sleep functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The static kernel settings are reported.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * - [1.2.1] Prints the configuration options settings.
 * .
 */

static void test_001_002_execute(void) {

  /* [1.2.1] Prints the configuration options settings.*/
  test_set_step(1);
  {
    test_print("--- CH_CFG_NUM_THREADS:        ");
    test_printn(CH_CFG_NUM_THREADS);
    test_println("");
    test_print("--- CH_CFG_ST_RESOLUTION:      ");
    test_printn(CH_CFG_ST_RESOLUTION);
    test_println("");
    test_print("--- CH_CFG_ST_FREQUENCY:       ");
    test_printn(CH_CFG_ST_FREQUENCY);
    test_println("");
    test_print("--- CH_CFG_ST_TIMEDELTA:       ");
    test_printn(CH_CFG_ST_TIMEDELTA);
    test_println("");
    test_print("--- CH_CFG_USE_SEMAPHORES:     ");
    test_printn(CH_CFG_USE_SEMAPHORES);
    test_println("");
    test_print("--- CH_CFG_USE_MUTEXES:        ");
    test_printn(CH_CFG_USE_MUTEXES);
    test_println("");
    test_print("--- CH_CFG_USE_EVENTS:         ");
    test_printn(CH_CFG_USE_EVENTS);
    test_println("");
    test_print("--- CH_CFG_USE_MAILBOXES:      ");
    test_printn(CH_CFG_USE_MAILBOXES);
    test_println("");
    test_print("--- CH_CFG_USE_MEMCORE:        ");
    test_printn(CH_CFG_USE_MEMCORE);
    test_println("");
    test_print("--- CH_CFG_USE_HEAP:           ");
    test_printn(CH_CFG_USE_HEAP);
    test_println("");
    test_print("--- CH_CFG_USE_MEMPOOLS:       ");
    test_printn(CH_CFG_USE_MEMPOOLS);
    test_println("");
    test_print("--- CH_DBG_STATISTICS:         ");
    test_printn(CH_DBG_STATISTICS);
    test_println("");
    test_print("--- CH_DBG_SYSTEM_STATE_CHECK: ");
    test_printn(CH_DBG_SYSTEM_STATE_CHECK);
    test_println("");
    test_print("--- CH_DBG_ENABLE_CHECKS:      ");
    test_printn(CH_DBG_ENABLE_CHECKS);
    test_println("");
    test_print("--- CH_DBG_ENABLE_ASSERTS:     ");
    test_printn(CH_DBG_ENABLE_ASSERTS);
    test_println("");
    test_print("--- CH_DBG_ENABLE_STACK_CHECK: ");
    test_printn(CH_DBG_ENABLE_STACK_CHECK);
    test_println("");
  }
}

static const testcase_t test_001_002 = {
  "Kernel Settings",
=======
 * - [2.2.1] The current system time is read then a sleep is performed
 *   for 100 system ticks and on exit the system time is verified
 *   again.
 * - [2.2.2] The current system time is read then a sleep is performed
 *   for 100000 microseconds and on exit the system time is verified
 *   again.
 * - [2.2.3] The current system time is read then a sleep is performed
 *   for 100 milliseconds and on exit the system time is verified
 *   again.
 * - [2.2.4] The current system time is read then a sleep is performed
 *   for 1 second and on exit the system time is verified again.
 * - [2.2.5] Function chThdSleepUntil() is tested with a timeline of
 *   "now" + 100 ticks.
 * .
 */

static void nil_test_002_002_execute(void) {
  systime_t time;

  /* [2.2.1] The current system time is read then a sleep is performed
     for 100 system ticks and on exit the system time is verified
     again.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chThdSleep(100);
    test_assert_time_window(chTimeAddX(time, 100),
                            chTimeAddX(time, 100 + 1),
                            "out of time window");
  }

  /* [2.2.2] The current system time is read then a sleep is performed
     for 100000 microseconds and on exit the system time is verified
     again.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMicroseconds(100000);
    test_assert_time_window(chTimeAddX(time, TIME_US2I(100000)),
                            chTimeAddX(time, TIME_US2I(100000) + 1),
                            "out of time window");
  }

  /* [2.2.3] The current system time is read then a sleep is performed
     for 100 milliseconds and on exit the system time is verified
     again.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMilliseconds(100);
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(100)),
                            chTimeAddX(time, TIME_MS2I(100) + 1),
                            "out of time window");
  }

  /* [2.2.4] The current system time is read then a sleep is performed
     for 1 second and on exit the system time is verified again.*/
  test_set_step(4);
  {
    time = chVTGetSystemTimeX();
    chThdSleepSeconds(1);
    test_assert_time_window(chTimeAddX(time, TIME_S2I(1)),
                            chTimeAddX(time, TIME_S2I(1) + 1),
                            "out of time window");
  }

  /* [2.2.5] Function chThdSleepUntil() is tested with a timeline of
     "now" + 100 ticks.*/
  test_set_step(5);
  {
    time = chVTGetSystemTimeX();
    chThdSleepUntil(chTimeAddX(time, 100));
    test_assert_time_window(chTimeAddX(time, 100),
                            chTimeAddX(time, 100 + 1),
                            "out of time window");
  }
}

static const testcase_t nil_test_002_002 = {
  "Thread Sleep functionality",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
  NULL,
  NULL,
  nil_test_002_002_execute
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_001.c
 * @brief   Information.
=======
 * @brief   Array of test cases.
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_002.c
 */
const testcase_t * const nil_test_sequence_002_array[] = {
  &nil_test_002_001,
  &nil_test_002_002,
  NULL
};

/**
 * @brief   Threads Functionality.
 */
const testsequence_t nil_test_sequence_002 = {
  "Threads Functionality",
  nil_test_sequence_002_array
};
