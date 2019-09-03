/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c

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
#include "oslib_test_root.h"

/**
 * @file    oslib_test_sequence_001.c
 * @brief   Test Sequence 001 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * @page test_sequence_008 [8] Event Sources and Event Flags
=======
 * @page oslib_test_sequence_001 [1] Mailboxes
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 *
 * File: @ref oslib_test_sequence_001.c
 *
 * <h2>Description</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * This module implements the test sequence for the Events subsystem.
=======
 * This sequence tests the ChibiOS libraryfunctionalities related to
 * mailboxes.
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_EVENTS
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * - @subpage test_008_001
 * - @subpage test_008_002
 * - @subpage test_008_003
 * - @subpage test_008_004
 * - @subpage test_008_005
 * - @subpage test_008_006
 * - @subpage test_008_007
=======
 * - @subpage oslib_test_001_001
 * - @subpage oslib_test_001_002
 * - @subpage oslib_test_001_003
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 * .
 */

#if (CH_CFG_USE_EVENTS) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

static EVENTSOURCE_DECL(es1);
static EVENTSOURCE_DECL(es2);

static void h1(eventid_t id) {(void)id;test_emit_token('A');}
static void h2(eventid_t id) {(void)id;test_emit_token('B');}
static void h3(eventid_t id) {(void)id;test_emit_token('C');}
static ROMCONST evhandler_t evhndl[] = {h1, h2, h3};

static THD_FUNCTION(evt_thread3, p) {

  chThdSleepMilliseconds(50);
  chEvtSignal((thread_t *)p, 1);
}

static THD_FUNCTION(evt_thread7, p) {

  (void)p;
  chEvtBroadcast(&es1);
  chThdSleepMilliseconds(50);
  chEvtBroadcast(&es2);
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * @page test_008_001 [8.1] Events registration
=======
 * @page oslib_test_001_001 [1.1] Mailbox normal API, non-blocking tests
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 *
 * <h2>Description</h2>
 * Two event listeners are registered on an event source and then
 * unregistered in the same order.<br> The test expects that the even
 * source has listeners after the registrations and after the first
 * unregistration, then, after the second unegistration, the test
 * expects no more listeners.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * - [8.1.1] An Event Source is initialized.
 * - [8.1.2] Two Event Listeners are registered on the Event Source,
 *   the Event Source is tested to have listeners.
 * - [8.1.3] An Event Listener is unregistered, the Event Source must
 *   still have listeners.
 * - [8.1.4] An Event Listener is unregistered, the Event Source must
 *   not have listeners.
 * .
 */

static void test_008_001_execute(void) {
  event_listener_t el1, el2;

  /* [8.1.1] An Event Source is initialized.*/
  test_set_step(1);
  {
    chEvtObjectInit(&es1);
  }

  /* [8.1.2] Two Event Listeners are registered on the Event Source,
     the Event Source is tested to have listeners.*/
  test_set_step(2);
  {
    chEvtRegisterMask(&es1, &el1, 1);
    chEvtRegisterMask(&es1, &el2, 2);
    test_assert_lock(chEvtIsListeningI(&es1), "no listener");
  }

  /* [8.1.3] An Event Listener is unregistered, the Event Source must
     still have listeners.*/
  test_set_step(3);
  {
    chEvtUnregister(&es1, &el1);
    test_assert_lock(chEvtIsListeningI(&es1), "no listener");
  }

  /* [8.1.4] An Event Listener is unregistered, the Event Source must
     not have listeners.*/
  test_set_step(4);
  {
    chEvtUnregister(&es1, &el2);
    test_assert_lock(!chEvtIsListeningI(&es1), "stuck listener");
  }
}

static const testcase_t test_008_001 = {
  "Events registration",
  NULL,
  NULL,
  test_008_001_execute
};

/**
 * @page test_008_002 [8.2] Event Flags dispatching
 *
 * <h2>Description</h2>
 * The test dispatches three event flags and verifies that the
 * associated event handlers are invoked in LSb-first order.
 *
 * <h2>Test Steps</h2>
 * - [8.2.1] Three evenf flag bits are raised then chEvtDispatch() is
 *   invoked, the sequence of handlers calls is tested.
 * .
 */

static void test_008_002_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void test_008_002_execute(void) {

  /* [8.2.1] Three evenf flag bits are raised then chEvtDispatch() is
     invoked, the sequence of handlers calls is tested.*/
=======
 * - [1.1.1] Testing the mailbox size.
 * - [1.1.2] Resetting the mailbox, conditions are checked, no errors
 *   expected.
 * - [1.1.3] Testing the behavior of API when the mailbox is in reset
 *   state then return in active state.
 * - [1.1.4] Filling the mailbox using chMBPostTimeout() and
 *   chMBPostAheadTimeout() once, no errors expected.
 * - [1.1.5] Testing intermediate conditions. Data pointers must be
 *   aligned, semaphore counters are checked.
 * - [1.1.6] Emptying the mailbox using chMBFetchTimeout(), no errors
 *   expected.
 * - [1.1.7] Posting and then fetching one more message, no errors
 *   expected.
 * - [1.1.8] Testing final conditions. Data pointers must be aligned to
 *   buffer start, semaphore counters are checked.
 * .
 */

static void oslib_test_001_001_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void oslib_test_001_001_teardown(void) {
  chMBReset(&mb1);
}

static void oslib_test_001_001_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [1.1.1] Testing the mailbox size.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(1);
  {
    chEvtDispatch(evhndl, 7);
    test_assert_sequence("ABC", "invalid sequence");
  }
}

static const testcase_t test_008_002 = {
  "Event Flags dispatching",
  test_008_002_setup,
  NULL,
  test_008_002_execute
};

/**
 * @page test_008_003 [8.3] Events Flags wait using chEvtWaitOne()
 *
 * <h2>Description</h2>
 * Functionality of chEvtWaitOne() is tested under various scenarios.
 *
 * <h2>Test Steps</h2>
 * - [8.3.1] Setting three event flags.
 * - [8.3.2] Calling chEvtWaitOne() three times, each time a single
 *   flag must be returned in order of priority.
 * - [8.3.3] Getting current time and starting a signaler thread, the
 *   thread will set an event flag after 50mS.
 * - [8.3.4] Calling chEvtWaitOne() then verifying that the event has
 *   been received after 50mS and that the event flags mask has been
 *   emptied.
 * .
 */

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
static void test_008_003_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void test_008_003_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.3.1] Setting three event flags.*/
  test_set_step(1);
  {
    chEvtAddEvents(7);
  }

  /* [8.3.2] Calling chEvtWaitOne() three times, each time a single
     flag must be returned in order of priority.*/
=======
  /* [1.1.2] Resetting the mailbox, conditions are checked, no errors
     expected.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(2);
  {
    m = chEvtWaitOne(ALL_EVENTS);
    test_assert(m == 1, "single event error");
    m = chEvtWaitOne(ALL_EVENTS);
    test_assert(m == 2, "single event error");
    m = chEvtWaitOne(ALL_EVENTS);
    test_assert(m == 4, "single event error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.3.3] Getting current time and starting a signaler thread, the
     thread will set an event flag after 50mS.*/
  test_set_step(3);
  {
    target_time = test_wait_tick() + MS2ST(50);
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

  /* [8.3.4] Calling chEvtWaitOne() then verifying that the event has
     been received after 50mS and that the event flags mask has been
     emptied.*/
  test_set_step(4);
  {
    m = chEvtWaitOne(ALL_EVENTS);
    test_assert_time_window(target_time, target_time + ALLOWED_DELAY,
                            "out of time window");
    test_assert(m == 1, "event flag error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
=======
  /* [1.1.3] Testing the behavior of API when the mailbox is in reset
     state then return in active state.*/
  test_set_step(3);
  {
    msg1 = chMBPostTimeout(&mb1, (msg_t)0, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    msg1 = chMBPostAheadTimeout(&mb1, (msg_t)0, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    msg1 = chMBFetchTimeout(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    chMBResumeX(&mb1);
  }

  /* [1.1.4] Filling the mailbox using chMBPostTimeout() and
     chMBPostAheadTimeout() once, no errors expected.*/
  test_set_step(4);
  {
    for (i = 0; i < MB_SIZE - 1; i++) {
      msg1 = chMBPostTimeout(&mb1, 'B' + i, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
    }
    msg1 = chMBPostAheadTimeout(&mb1, 'A', TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
static const testcase_t test_008_003 = {
  "Events Flags wait using chEvtWaitOne()",
  test_008_003_setup,
  NULL,
  test_008_003_execute
};

/**
 * @page test_008_004 [8.4] Events Flags wait using chEvtWaitAny()
 *
 * <h2>Description</h2>
 * Functionality of chEvtWaitAny() is tested under various scenarios.
 *
 * <h2>Test Steps</h2>
 * - [8.4.1] Setting two, non contiguous, event flags.
 * - [8.4.2] Calling chEvtWaitAny() one time, the two flags must be
 *   returned.
 * - [8.4.3] Getting current time and starting a signaler thread, the
 *   thread will set an event flag after 50mS.
 * - [8.4.4] Calling chEvtWaitAny() then verifying that the event has
 *   been received after 50mS and that the event flags mask has been
 *   emptied.
 * .
 */

static void test_008_004_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void test_008_004_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.4.1] Setting two, non contiguous, event flags.*/
  test_set_step(1);
=======
  /* [1.1.5] Testing intermediate conditions. Data pointers must be
     aligned, semaphore counters are checked.*/
  test_set_step(5);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  {
    chEvtAddEvents(5);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.4.2] Calling chEvtWaitAny() one time, the two flags must be
     returned.*/
  test_set_step(2);
  {
    m = chEvtWaitAny(ALL_EVENTS);
    test_assert(m == 5, "unexpected pending bit");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
  }

  /* [8.4.3] Getting current time and starting a signaler thread, the
     thread will set an event flag after 50mS.*/
  test_set_step(3);
  {
    target_time = test_wait_tick() + MS2ST(50);
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

  /* [8.4.4] Calling chEvtWaitAny() then verifying that the event has
     been received after 50mS and that the event flags mask has been
     emptied.*/
  test_set_step(4);
=======
  /* [1.1.6] Emptying the mailbox using chMBFetchTimeout(), no errors
     expected.*/
  test_set_step(6);
  {
    for (i = 0; i < MB_SIZE; i++) {
      msg1 = chMBFetchTimeout(&mb1, &msg2, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
      test_emit_token(msg2);
    }
    test_assert_sequence("ABCD", "wrong get sequence");
  }

  /* [1.1.7] Posting and then fetching one more message, no errors
     expected.*/
  test_set_step(7);
  {
    msg1 = chMBPostTimeout(&mb1, 'B' + i, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
    msg1 = chMBFetchTimeout(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

  /* [1.1.8] Testing final conditions. Data pointers must be aligned to
     buffer start, semaphore counters are checked.*/
  test_set_step(8);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  {
    m = chEvtWaitAny(ALL_EVENTS);
    test_assert_time_window(target_time, target_time + ALLOWED_DELAY,
                            "out of time window");
    test_assert(m == 1, "event flag error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
static const testcase_t test_008_004 = {
  "Events Flags wait using chEvtWaitAny()",
  test_008_004_setup,
  NULL,
  test_008_004_execute
};

/**
 * @page test_008_005 [8.5] Events Flags wait using chEvtWaitAll()
=======
static const testcase_t oslib_test_001_001 = {
  "Mailbox normal API, non-blocking tests",
  oslib_test_001_001_setup,
  oslib_test_001_001_teardown,
  oslib_test_001_001_execute
};

/**
 * @page oslib_test_001_002 [1.2] Mailbox I-Class API, non-blocking tests
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 *
 * <h2>Description</h2>
 * Functionality of chEvtWaitAll() is tested under various scenarios.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * - [8.5.1] Setting two, non contiguous, event flags.
 * - [8.5.2] Calling chEvtWaitAll() one time, the two flags must be
 *   returned.
 * - [8.5.3] Setting one event flag.
 * - [8.5.4] Getting current time and starting a signaler thread, the
 *   thread will set another event flag after 50mS.
 * - [8.5.5] Calling chEvtWaitAll() then verifying that both event
 *   flags have been received after 50mS and that the event flags mask
 *   has been emptied.
 * .
 */

static void test_008_005_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void test_008_005_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.5.1] Setting two, non contiguous, event flags.*/
=======
 * - [1.2.1] Testing the mailbox size.
 * - [1.2.2] Resetting the mailbox, conditions are checked, no errors
 *   expected. The mailbox is then returned in active state.
 * - [1.2.3] Filling the mailbox using chMBPostI() and chMBPostAheadI()
 *   once, no errors expected.
 * - [1.2.4] Testing intermediate conditions. Data pointers must be
 *   aligned, semaphore counters are checked.
 * - [1.2.5] Emptying the mailbox using chMBFetchI(), no errors
 *   expected.
 * - [1.2.6] Posting and then fetching one more message, no errors
 *   expected.
 * - [1.2.7] Testing final conditions. Data pointers must be aligned to
 *   buffer start, semaphore counters are checked.
 * .
 */

static void oslib_test_001_002_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void oslib_test_001_002_teardown(void) {
  chMBReset(&mb1);
}

static void oslib_test_001_002_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [1.2.1] Testing the mailbox size.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(1);
  {
    chEvtAddEvents(5);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.5.2] Calling chEvtWaitAll() one time, the two flags must be
     returned.*/
=======
  /* [1.2.2] Resetting the mailbox, conditions are checked, no errors
     expected. The mailbox is then returned in active state.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(2);
  {
    m = chEvtWaitAll(5);
    test_assert(m == 5, "unexpected pending bit");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.5.3] Setting one event flag.*/
=======
  /* [1.2.3] Filling the mailbox using chMBPostI() and chMBPostAheadI()
     once, no errors expected.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(3);
  {
    chEvtAddEvents(4);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.5.4] Getting current time and starting a signaler thread, the
     thread will set another event flag after 50mS.*/
=======
  /* [1.2.4] Testing intermediate conditions. Data pointers must be
     aligned, semaphore counters are checked.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(4);
  {
    target_time = test_wait_tick() + MS2ST(50);
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.5.5] Calling chEvtWaitAll() then verifying that both event
     flags have been received after 50mS and that the event flags mask
     has been emptied.*/
=======
  /* [1.2.5] Emptying the mailbox using chMBFetchI(), no errors
     expected.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(5);
  {
    m = chEvtWaitAll(5);
    test_assert_time_window(target_time, target_time + ALLOWED_DELAY,
                            "out of time window");
    test_assert(m == 5, "event flags error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
static const testcase_t test_008_005 = {
  "Events Flags wait using chEvtWaitAll()",
  test_008_005_setup,
  NULL,
  test_008_005_execute
};

#if (CH_CFG_USE_EVENTS_TIMEOUT) || defined(__DOXYGEN__)
/**
 * @page test_008_006 [8.6] Events Flags wait timeouts
 *
 * <h2>Description</h2>
 * Timeout functionality is tested for chEvtWaitOneTimeout(),
 * chEvtWaitAnyTimeout() and chEvtWaitAllTimeout().
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_EVENTS_TIMEOUT
 * .
 *
 * <h2>Test Steps</h2>
 * - [8.6.1] The functions are invoked first with TIME_IMMEDIATE
 *   timeout, the timeout condition is tested.
 * - [8.6.2] The functions are invoked first with a 50mS timeout, the
 *   timeout condition is tested.
 * .
 */

static void test_008_006_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void test_008_006_execute(void) {
  eventmask_t m;

  /* [8.6.1] The functions are invoked first with TIME_IMMEDIATE
     timeout, the timeout condition is tested.*/
  test_set_step(1);
  {
    m = chEvtWaitOneTimeout(ALL_EVENTS, TIME_IMMEDIATE);
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAnyTimeout(ALL_EVENTS, TIME_IMMEDIATE);
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAllTimeout(ALL_EVENTS, TIME_IMMEDIATE);
    test_assert(m == 0, "spurious event");
  }

  /* [8.6.2] The functions are invoked first with a 50mS timeout, the
     timeout condition is tested.*/
  test_set_step(2);
=======
  /* [1.2.6] Posting and then fetching one more message, no errors
     expected.*/
  test_set_step(6);
  {
    msg1 = chMBPostTimeout(&mb1, 'B' + i, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
    msg1 = chMBFetchTimeout(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

  /* [1.2.7] Testing final conditions. Data pointers must be aligned to
     buffer start, semaphore counters are checked.*/
  test_set_step(7);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  {
    m = chEvtWaitOneTimeout(ALL_EVENTS, MS2ST(50));
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAnyTimeout(ALL_EVENTS, MS2ST(50));
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAllTimeout(ALL_EVENTS, MS2ST(50));
    test_assert(m == 0, "spurious event");
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
static const testcase_t test_008_006 = {
  "Events Flags wait timeouts",
  test_008_006_setup,
  NULL,
  test_008_006_execute
=======
static const testcase_t oslib_test_001_002 = {
  "Mailbox I-Class API, non-blocking tests",
  oslib_test_001_002_setup,
  oslib_test_001_002_teardown,
  oslib_test_001_002_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
};
#endif /* CH_CFG_USE_EVENTS_TIMEOUT */

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * @page test_008_007 [8.7] Broadcasting using chEvtBroadcast()
=======
 * @page oslib_test_001_003 [1.3] Mailbox timeouts
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
 *
 * <h2>Description</h2>
 * Functionality of chEvtBroadcast() is tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * - [8.7.1] Registering on two event sources associating them with
 *   flags 1 and 4.
 * - [8.7.2] Getting current time and starting a broadcaster thread,
 *   the thread broadcast the first Event Source immediately and the
 *   other after 50mS.
 * - [8.7.3] Calling chEvtWaitAll() then verifying that both event
 *   flags have been received after 50mS and that the event flags mask
 *   has been emptied.
 * - [8.7.4] Unregistering from the Event Sources.
 * .
 */

static void test_008_007_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
  chEvtObjectInit(&es1);
  chEvtObjectInit(&es2);
}

static void test_008_007_execute(void) {
  eventmask_t m;
  event_listener_t el1, el2;
  systime_t target_time;

  /* [8.7.1] Registering on two event sources associating them with
     flags 1 and 4.*/
  test_set_step(1);
  {
    chEvtRegisterMask(&es1, &el1, 1);
    chEvtRegisterMask(&es2, &el2, 4);
  }

  /* [8.7.2] Getting current time and starting a broadcaster thread,
     the thread broadcast the first Event Source immediately and the
     other after 50mS.*/
  test_set_step(2);
  {
    target_time = test_wait_tick() + MS2ST(50);
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread7, "A");
  }

  /* [8.7.3] Calling chEvtWaitAll() then verifying that both event
     flags have been received after 50mS and that the event flags mask
     has been emptied.*/
=======
 * - [1.3.1] Filling the mailbox.
 * - [1.3.2] Testing chMBPostTimeout(), chMBPostI(),
 *   chMBPostAheadTimeout() and chMBPostAheadI() timeout.
 * - [1.3.3] Resetting the mailbox. The mailbox is then returned in
 *   active state.
 * - [1.3.4] Testing chMBFetchTimeout() and chMBFetchI() timeout.
 * .
 */

static void oslib_test_001_003_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void oslib_test_001_003_teardown(void) {
  chMBReset(&mb1);
}

static void oslib_test_001_003_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [1.3.1] Filling the mailbox.*/
  test_set_step(1);
  {
    for (i = 0; i < MB_SIZE; i++) {
      msg1 = chMBPostTimeout(&mb1, 'B' + i, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
    }
  }

  /* [1.3.2] Testing chMBPostTimeout(), chMBPostI(),
     chMBPostAheadTimeout() and chMBPostAheadI() timeout.*/
  test_set_step(2);
  {
    msg1 = chMBPostTimeout(&mb1, 'X', 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBPostI(&mb1, 'X');
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    msg1 = chMBPostAheadTimeout(&mb1, 'X', 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBPostAheadI(&mb1, 'X');
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
  }

  /* [1.3.3] Resetting the mailbox. The mailbox is then returned in
     active state.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
  test_set_step(3);
  {
    m = chEvtWaitAll(5);
    test_assert_time_window(target_time, target_time + ALLOWED_DELAY,
                            "out of time window");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
  /* [8.7.4] Unregistering from the Event Sources.*/
  test_set_step(4);
  {
    chEvtUnregister(&es1, &el1);
    chEvtUnregister(&es2, &el2);
    test_assert(!chEvtIsListeningI(&es1), "stuck listener");
    test_assert(!chEvtIsListeningI(&es2), "stuck listener");
  }
}

static const testcase_t test_008_007 = {
  "Broadcasting using chEvtBroadcast()",
  test_008_007_setup,
  NULL,
  test_008_007_execute
=======
  /* [1.3.4] Testing chMBFetchTimeout() and chMBFetchI() timeout.*/
  test_set_step(4);
  {
    msg1 = chMBFetchTimeout(&mb1, &msg2, 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBFetchI(&mb1, &msg2);
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
  }
}

static const testcase_t oslib_test_001_003 = {
  "Mailbox timeouts",
  oslib_test_001_003_setup,
  oslib_test_001_003_teardown,
  oslib_test_001_003_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_008.c
 * @brief   Event Sources and Event Flags.
 */
const testcase_t * const test_sequence_008[] = {
  &test_008_001,
  &test_008_002,
  &test_008_003,
  &test_008_004,
  &test_008_005,
#if (CH_CFG_USE_EVENTS_TIMEOUT) || defined(__DOXYGEN__)
  &test_008_006,
#endif
  &test_008_007,
  NULL
};

#endif /* CH_CFG_USE_EVENTS */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const oslib_test_sequence_001_array[] = {
  &oslib_test_001_001,
  &oslib_test_001_002,
  &oslib_test_001_003,
  NULL
};

/**
 * @brief   Mailboxes.
 */
const testsequence_t oslib_test_sequence_001 = {
  "Mailboxes",
  oslib_test_sequence_001_array
};

#endif /* CH_CFG_USE_MAILBOXES */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_001.c
