/*
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c

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
 * @file    nil_test_sequence_004.c
 * @brief   Test Sequence 004 code.
 *
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * @page test_sequence_003 [3] Semaphores
=======
 * @page nil_test_sequence_004 [4] Suspend/Resume and Event Flags
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
 *
 * File: @ref nil_test_sequence_004.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/NIL functionalities related to
 * counter semaphores.
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * - @subpage test_003_001
 * - @subpage test_003_002
 * - @subpage test_003_003
=======
 * - @subpage nil_test_004_001
 * - @subpage nil_test_004_002
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
 * .
 */

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#include "ch.h"

static semaphore_t sem1;

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * @page test_003_001 [3.1] Semaphore primitives, no state change
=======
 * @page nil_test_004_001 [4.1] Suspend and Resume functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
 *
 * <h2>Description</h2>
 * Wait, Signal and Reset primitives are tested. The testing thread
 * does not trigger a state change.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * - [3.1.1] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested.
 * - [3.1.2] The function chSemSignal() is invoked, after return the
 *   counter is tested.
 * - [3.1.3] The function chSemReset() is invoked, after return the
 *   counter is tested.
 * .
 */

static void test_003_001_setup(void) {
  chSemObjectInit(&sem1, 1);
}

static void test_003_001_teardown(void) {
  chSemReset(&sem1, 0);
}

static void test_003_001_execute(void) {

  /* [3.1.1] The function chSemWait() is invoked, after return the
     counter and the returned message are tested.*/
=======
 * - [4.1.1] The function chThdSuspendTimeoutS() is invoked, the thread
 *   is remotely resumed with message @p MSG_OK. On return the message
 *   and the state of the reference are tested.
 * - [4.1.2] The function chThdSuspendTimeoutS() is invoked, the thread
 *   is not resumed so a timeout must occur. On return the message and
 *   the state of the reference are tested.
 * .
 */

static void nil_test_004_001_setup(void) {
  tr1 = NULL;
}

static void nil_test_004_001_execute(void) {
  systime_t time;
  msg_t msg;

  /* [4.1.1] The function chThdSuspendTimeoutS() is invoked, the thread
     is remotely resumed with message @p MSG_OK. On return the message
     and the state of the reference are tested.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
  test_set_step(1);
  {
    msg_t msg;

    msg = chSemWait(&sem1);
    test_assert_lock(chSemGetCounterI(&sem1) == 0, "wrong counter value");
    test_assert(MSG_OK == msg, "wrong returned message");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
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

static const testcase_t test_003_001 = {
  "Semaphore primitives, no state change",
  test_003_001_setup,
  test_003_001_teardown,
  test_003_001_execute
=======
  /* [4.1.2] The function chThdSuspendTimeoutS() is invoked, the thread
     is not resumed so a timeout must occur. On return the message and
     the state of the reference are tested.*/
  test_set_step(2);
  {
    chSysLock();
    time = chVTGetSystemTimeX();
    msg = chThdSuspendTimeoutS(&tr1, TIME_MS2I(1000));
    chSysUnlock();
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(1000)),
                            chTimeAddX(time, TIME_MS2I(1000) + 1),
                            "out of time window");
    test_assert(NULL == tr1, "not NULL");
    test_assert(MSG_TIMEOUT == msg, "wrong returned message");
  }
}

static const testcase_t nil_test_004_001 = {
  "Suspend and Resume functionality",
  nil_test_004_001_setup,
  NULL,
  nil_test_004_001_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
};

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * @page test_003_002 [3.2] Semaphore primitives, with state change
=======
 * @page nil_test_004_002 [4.2] Events Flags functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
 *
 * <h2>Description</h2>
 * Wait, Signal and Reset primitives are tested. The testing thread
 * triggers a state change.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * - [3.2.1] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested. The semaphore is
 *   signaled by another thread.
 * - [3.2.2] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested. The semaphore is
 *   reset by another thread.
 * .
 */

static void test_003_002_setup(void) {
  chSemObjectInit(&gsem1, 0);
}

static void test_003_002_teardown(void) {
  chSemReset(&gsem1, 0);
}

static void test_003_002_execute(void) {

  /* [3.2.1] The function chSemWait() is invoked, after return the
     counter and the returned message are tested. The semaphore is
     signaled by another thread.*/
  test_set_step(1);
  {
    msg_t msg;

    msg = chSemWait(&gsem1);
    test_assert_lock(chSemGetCounterI(&gsem1) == 0, "wrong counter value");
    test_assert(MSG_OK == msg, "wrong returned message");
  }

  /* [3.2.2] The function chSemWait() is invoked, after return the
     counter and the returned message are tested. The semaphore is
     reset by another thread.*/
=======
 * - [4.2.1] A set of event flags are set on the current thread then
 *   the function chEvtWaitAnyTimeout() is invoked, the function is
 *   supposed to return immediately because the event flags are already
 *   pending, after return the events mask is tested.
 * - [4.2.2] The pending event flags mask is cleared then the function
 *   chEvtWaitAnyTimeout() is invoked, after return the events mask is
 *   tested. The thread is signaled by another thread.
 * - [4.2.3] The function chEvtWaitAnyTimeout() is invoked, no event
 *   can wakeup the thread, the function must return because timeout.
 * .
 */

static void nil_test_004_002_execute(void) {
  systime_t time;
  eventmask_t events;

  /* [4.2.1] A set of event flags are set on the current thread then
     the function chEvtWaitAnyTimeout() is invoked, the function is
     supposed to return immediately because the event flags are already
     pending, after return the events mask is tested.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chEvtSignal(chThdGetSelfX(), 0x55);
    events = chEvtWaitAnyTimeout(ALL_EVENTS, TIME_MS2I(1000));
    test_assert((eventmask_t)0 != events, "timed out");
    test_assert((eventmask_t)0x55 == events, "wrong events mask");
  }

  /* [4.2.2] The pending event flags mask is cleared then the function
     chEvtWaitAnyTimeout() is invoked, after return the events mask is
     tested. The thread is signaled by another thread.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
  test_set_step(2);
  {
    msg_t msg;

    msg = chSemWait(&gsem2);
    test_assert_lock(chSemGetCounterI(&gsem2) == 0,"wrong counter value");
    test_assert(MSG_RESET == msg, "wrong returned message");
  }
}

static const testcase_t test_003_002 = {
  "Semaphore primitives, with state change",
  test_003_002_setup,
  test_003_002_teardown,
  test_003_002_execute
};

/**
 * @page test_003_003 [3.3] Semaphores timeout
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

static void test_003_003_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void test_003_003_teardown(void) {
  chSemReset(&sem1, 0);
}

static void test_003_003_execute(void) {
  systime_t time;
  msg_t msg;

  /* [3.3.1] The function chSemWaitTimeout() is invoked a first time,
     after return the system time, the counter and the returned message
     are tested.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
    msg = chSemWaitTimeout(&sem1, MS2ST(1000));
    test_assert_time_window(time + MS2ST(1000),
                            time + MS2ST(1000) + 1,
                            "out of time window");
    test_assert_lock(chSemGetCounterI(&sem1) == 0, "wrong counter value");
    test_assert(MSG_TIMEOUT == msg, "wrong timeout message");
  }

  /* [3.3.2] The function chSemWaitTimeout() is invoked again, after
     return the system time, the counter and the returned message are
     tested.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    msg = chSemWaitTimeout(&sem1, MS2ST(1000));
    test_assert_time_window(time + MS2ST(1000),
                            time + MS2ST(1000) + 1,
=======
    chThdGetSelfX()->epmask = 0;
    events = chEvtWaitAnyTimeout(ALL_EVENTS, TIME_MS2I(1000));
    test_assert((eventmask_t)0 != events, "timed out");
    test_assert((eventmask_t)0x55 == events, "wrong events mask");
  }

  /* [4.2.3] The function chEvtWaitAnyTimeout() is invoked, no event
     can wakeup the thread, the function must return because timeout.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    events = chEvtWaitAnyTimeout(0, TIME_MS2I(1000));
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(1000)),
                            chTimeAddX(time, TIME_MS2I(1000) + 1),
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
                            "out of time window");
    test_assert_lock(chSemGetCounterI(&sem1) == 0, "wrong counter value");
    test_assert(MSG_TIMEOUT == msg, "wrong timeout message");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
static const testcase_t test_003_003 = {
  "Semaphores timeout",
  test_003_003_setup,
  test_003_003_teardown,
  test_003_003_execute
=======
static const testcase_t nil_test_004_002 = {
  "Events Flags functionality",
  NULL,
  NULL,
  nil_test_004_002_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_003.c
 * @brief   Semaphores.
 */
const testcase_t * const test_sequence_003[] = {
  &test_003_001,
  &test_003_002,
  &test_003_003,
  NULL
};

#endif /* CH_CFG_USE_SEMAPHORES */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const nil_test_sequence_004_array[] = {
  &nil_test_004_001,
#if (CH_CFG_USE_EVENTS) || defined(__DOXYGEN__)
  &nil_test_004_002,
#endif
  NULL
};

/**
 * @brief   Suspend/Resume and Event Flags.
 */
const testsequence_t nil_test_sequence_004 = {
  "Suspend/Resume and Event Flags",
  nil_test_sequence_004_array
};
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/nil/source/test/nil_test_sequence_004.c
