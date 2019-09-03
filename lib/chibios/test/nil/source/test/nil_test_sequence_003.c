/*
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c

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
 * @file    nil_test_sequence_003.c
 * @brief   Test Sequence 003 code.
 *
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
 * @page test_sequence_002 [2] Threads Functionality
=======
 * @page nil_test_sequence_003 [3] Semaphores
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
 *
 * File: @ref nil_test_sequence_003.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/NIL functionalities related to
 * threading.
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
 * - @subpage test_002_001
 * - @subpage test_002_002
=======
 * - @subpage nil_test_003_001
 * - @subpage nil_test_003_002
 * - @subpage nil_test_003_003
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
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
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
 * @page test_002_001 [2.1] System Tick Counter functionality
=======
 * @page nil_test_003_001 [3.1] Semaphore primitives, no state change
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The functionality of the API @p chVTGetSystemTimeX() is tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
 * - [2.1.1] A System Tick Counter increment is expected, the test
 *   simply hangs if it does not happen.
 * .
 */

static void test_002_001_execute(void) {

  /* [2.1.1] A System Tick Counter increment is expected, the test
     simply hangs if it does not happen.*/
  test_set_step(1);
  {
    systime_t time = chVTGetSystemTimeX();
    while (time == chVTGetSystemTimeX()) {
    }
  }
}

static const testcase_t test_002_001 = {
  "System Tick Counter functionality",
  NULL,
  NULL,
  test_002_001_execute
};

/**
 * @page test_002_002 [2.2] Thread Sleep functionality
=======
 * - [3.1.1] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested.
 * - [3.1.2] The function chSemSignal() is invoked, after return the
 *   counter is tested.
 * - [3.1.3] The function chSemReset() is invoked, after return the
 *   counter is tested.
 * .
 */

static void nil_test_003_001_setup(void) {
  chSemObjectInit(&sem1, 1);
}

static void nil_test_003_001_teardown(void) {
  chSemReset(&sem1, 0);
}

static void nil_test_003_001_execute(void) {

  /* [3.1.1] The function chSemWait() is invoked, after return the
     counter and the returned message are tested.*/
  test_set_step(1);
  {
    msg_t msg;

    msg = chSemWait(&sem1);
    test_assert_lock(chSemGetCounterI(&sem1) == 0, "wrong counter value");
    test_assert(MSG_OK == msg, "wrong returned message");
  }

  /* [3.1.2] The function chSemSignal() is invoked, after return the
     counter is tested.*/
  test_set_step(2);
  {
    chSemSignal(&sem1);
    test_assert_lock(chSemGetCounterI(&sem1) == 1, "wrong counter value");
  }

  /* [3.1.3] The function chSemReset() is invoked, after return the
     counter is tested.*/
  test_set_step(3);
  {
    chSemReset(&sem1, 2);
    test_assert_lock(chSemGetCounterI(&sem1) == 2, "wrong counter value");
  }
}

static const testcase_t nil_test_003_001 = {
  "Semaphore primitives, no state change",
  nil_test_003_001_setup,
  nil_test_003_001_teardown,
  nil_test_003_001_execute
};

/**
 * @page nil_test_003_002 [3.2] Semaphore primitives, with state change
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The functionality of @p chThdSleep() and derivatives is tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
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

static void test_002_002_execute(void) {
  systime_t time;

  /* [2.2.1] The current system time is read then a sleep is performed
     for 100 system ticks and on exit the system time is verified
     again.*/
=======
 * - [3.2.1] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested. The semaphore is
 *   signaled by another thread.
 * - [3.2.2] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested. The semaphore is
 *   reset by another thread.
 * .
 */

static void nil_test_003_002_setup(void) {
  chSemObjectInit(&gsem1, 0);
}

static void nil_test_003_002_teardown(void) {
  chSemReset(&gsem1, 0);
}

static void nil_test_003_002_execute(void) {

  /* [3.2.1] The function chSemWait() is invoked, after return the
     counter and the returned message are tested. The semaphore is
     signaled by another thread.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chThdSleep(100);
    test_assert_time_window(time + 100,
                            time + 100 + 1,
                            "out of time window");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
  /* [2.2.2] The current system time is read then a sleep is performed
     for 100000 microseconds and on exit the system time is verified
     again.*/
=======
  /* [3.2.2] The function chSemWait() is invoked, after return the
     counter and the returned message are tested. The semaphore is
     reset by another thread.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMicroseconds(100000);
    test_assert_time_window(time + US2ST(100000),
                            time + US2ST(100000) + 1,
                            "out of time window");
  }
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c

  /* [2.2.3] The current system time is read then a sleep is performed
     for 100 milliseconds and on exit the system time is verified
     again.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMilliseconds(100);
    test_assert_time_window(time + MS2ST(100),
                            time + MS2ST(100) + 1,
                            "out of time window");
  }

  /* [2.2.4] The current system time is read then a sleep is performed
     for 1 second and on exit the system time is verified again.*/
  test_set_step(4);
  {
    time = chVTGetSystemTimeX();
    chThdSleepSeconds(1);
    test_assert_time_window(time + S2ST(1),
                            time + S2ST(1) + 1,
=======
}

static const testcase_t nil_test_003_002 = {
  "Semaphore primitives, with state change",
  nil_test_003_002_setup,
  nil_test_003_002_teardown,
  nil_test_003_002_execute
};

/**
 * @page nil_test_003_003 [3.3] Semaphores timeout
 *
 * <h2>Description</h2>
 * Timeout on semaphores is tested.
 *
 * <h2>Test Steps</h2>
 * - [3.3.1] The function chSemWaitTimeout() is invoked a first time,
 *   after return the system time, the counter and the returned message
 *   are tested.
 * - [3.3.2] The function chSemWaitTimeout() is invoked again, after
 *   return the system time, the counter and the returned message are
 *   tested.
 * .
 */

static void nil_test_003_003_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void nil_test_003_003_teardown(void) {
  chSemReset(&sem1, 0);
}

static void nil_test_003_003_execute(void) {
  systime_t time;
  msg_t msg;

  /* [3.3.1] The function chSemWaitTimeout() is invoked a first time,
     after return the system time, the counter and the returned message
     are tested.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    msg = chSemWaitTimeout(&sem1, TIME_MS2I(1000));
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(1000)),
                            chTimeAddX(time, TIME_MS2I(1000) + 1),
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
                            "out of time window");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
  /* [2.2.5] Function chThdSleepUntil() is tested with a timeline of
     "now" + 100 ticks.*/
  test_set_step(5);
  {
    time = chVTGetSystemTimeX();
    chThdSleepUntil(time + 100);
    test_assert_time_window(time + 100,
                            time + 100 + 1,
=======
  /* [3.3.2] The function chSemWaitTimeout() is invoked again, after
     return the system time, the counter and the returned message are
     tested.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    msg = chSemWaitTimeout(&sem1, TIME_MS2I(1000));
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(1000)),
                            chTimeAddX(time, TIME_MS2I(1000) + 1),
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
                            "out of time window");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
static const testcase_t test_002_002 = {
  "Thread Sleep functionality",
  NULL,
  NULL,
  test_002_002_execute
=======
static const testcase_t nil_test_003_003 = {
  "Semaphores timeout",
  nil_test_003_003_setup,
  nil_test_003_003_teardown,
  nil_test_003_003_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_002.c
 * @brief   Threads Functionality.
 */
const testcase_t * const test_sequence_002[] = {
  &test_002_001,
  &test_002_002,
  NULL
};
=======
 * @brief   Array of test cases.
 */
const testcase_t * const nil_test_sequence_003_array[] = {
  &nil_test_003_001,
  &nil_test_003_002,
  &nil_test_003_003,
  NULL
};

/**
 * @brief   Semaphores.
 */
const testsequence_t nil_test_sequence_003 = {
  "Semaphores",
  nil_test_sequence_003_array
};

#endif /* CH_CFG_USE_SEMAPHORES */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_003.c
