/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c

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
#include "rt_test_root.h"

/**
 * @file    rt_test_sequence_008.c
 * @brief   Test Sequence 008 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
 * @page test_sequence_007 [7] Synchronous Messages
=======
 * @page rt_test_sequence_008 [8] Event Sources and Event Flags
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
 *
 * File: @ref rt_test_sequence_008.c
 *
 * <h2>Description</h2>
 * This module implements the test sequence for the Synchronous
 * Messages subsystem.
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MESSAGES
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
 * - @subpage test_007_001
=======
 * - @subpage rt_test_008_001
 * - @subpage rt_test_008_002
 * - @subpage rt_test_008_003
 * - @subpage rt_test_008_004
 * - @subpage rt_test_008_005
 * - @subpage rt_test_008_006
 * - @subpage rt_test_008_007
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
 * .
 */

#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

static THD_FUNCTION(msg_thread1, p) {

  chMsgSend(p, 'A');
  chMsgSend(p, 'B');
  chMsgSend(p, 'C');
  chMsgSend(p, 'D');
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
 * @page test_007_001 [7.1] Messages Server loop
=======
 * @page rt_test_008_001 [8.1] Events registration
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
 *
 * <h2>Description</h2>
 * A messenger thread is spawned that sends four messages back to the
 * tester thread.<br> The test expect to receive the messages in the
 * correct sequence and to not find a fifth message waiting.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
 * - [7.1.1] Starting the messenger thread.
 * - [7.1.2] Waiting for four messages then testing the receive order.
 * .
 */

static void test_007_001_execute(void) {
  thread_t *tp;
  msg_t msg;

  /* [7.1.1] Starting the messenger thread.*/
=======
 * - [8.1.1] An Event Source is initialized.
 * - [8.1.2] Two Event Listeners are registered on the Event Source,
 *   the Event Source is tested to have listeners.
 * - [8.1.3] An Event Listener is unregistered, the Event Source must
 *   still have listeners.
 * - [8.1.4] An Event Listener is unregistered, the Event Source must
 *   not have listeners.
 * .
 */

static void rt_test_008_001_execute(void) {
  event_listener_t el1, el2;

  /* [8.1.1] An Event Source is initialized.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() + 1,
                                   msg_thread1, chThdGetSelfX());
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
  /* [7.1.2] Waiting for four messages then testing the receive
     order.*/
  test_set_step(2);
  {
    unsigned i;

    for (i = 0; i < 4; i++) {
      tp = chMsgWait();
      msg = chMsgGet(tp);
      chMsgRelease(tp, msg);
      test_emit_token(msg);
    }
    test_wait_threads();
    test_assert_sequence("ABCD", "invalid sequence");
  }
}

static const testcase_t test_007_001 = {
  "Messages Server loop",
=======
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

static const testcase_t rt_test_008_001 = {
  "Events registration",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
  NULL,
  NULL,
  rt_test_008_001_execute
};

<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
=======
/**
 * @page rt_test_008_002 [8.2] Event Flags dispatching
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

static void rt_test_008_002_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void rt_test_008_002_execute(void) {

  /* [8.2.1] Three evenf flag bits are raised then chEvtDispatch() is
     invoked, the sequence of handlers calls is tested.*/
  test_set_step(1);
  {
    chEvtDispatch(evhndl, 7);
    test_assert_sequence("ABC", "invalid sequence");
  }
}

static const testcase_t rt_test_008_002 = {
  "Event Flags dispatching",
  rt_test_008_002_setup,
  NULL,
  rt_test_008_002_execute
};

/**
 * @page rt_test_008_003 [8.3] Events Flags wait using chEvtWaitOne()
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

static void rt_test_008_003_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void rt_test_008_003_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.3.1] Setting three event flags.*/
  test_set_step(1);
  {
    chEvtAddEvents(7);
  }

  /* [8.3.2] Calling chEvtWaitOne() three times, each time a single
     flag must be returned in order of priority.*/
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

  /* [8.3.3] Getting current time and starting a signaler thread, the
     thread will set an event flag after 50mS.*/
  test_set_step(3);
  {
    target_time = chTimeAddX(test_wait_tick(), TIME_MS2I(50));
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

  /* [8.3.4] Calling chEvtWaitOne() then verifying that the event has
     been received after 50mS and that the event flags mask has been
     emptied.*/
  test_set_step(4);
  {
    m = chEvtWaitOne(ALL_EVENTS);
    test_assert_time_window(target_time,
                            chTimeAddX(target_time, ALLOWED_DELAY),
                            "out of time window");
    test_assert(m == 1, "event flag error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }
}

static const testcase_t rt_test_008_003 = {
  "Events Flags wait using chEvtWaitOne()",
  rt_test_008_003_setup,
  NULL,
  rt_test_008_003_execute
};

/**
 * @page rt_test_008_004 [8.4] Events Flags wait using chEvtWaitAny()
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

static void rt_test_008_004_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void rt_test_008_004_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.4.1] Setting two, non contiguous, event flags.*/
  test_set_step(1);
  {
    chEvtAddEvents(5);
  }

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
    target_time = chTimeAddX(test_wait_tick(), TIME_MS2I(50));
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

  /* [8.4.4] Calling chEvtWaitAny() then verifying that the event has
     been received after 50mS and that the event flags mask has been
     emptied.*/
  test_set_step(4);
  {
    m = chEvtWaitAny(ALL_EVENTS);
    test_assert_time_window(target_time,
                            chTimeAddX(target_time, ALLOWED_DELAY),
                            "out of time window");
    test_assert(m == 1, "event flag error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }
}

static const testcase_t rt_test_008_004 = {
  "Events Flags wait using chEvtWaitAny()",
  rt_test_008_004_setup,
  NULL,
  rt_test_008_004_execute
};

/**
 * @page rt_test_008_005 [8.5] Events Flags wait using chEvtWaitAll()
 *
 * <h2>Description</h2>
 * Functionality of chEvtWaitAll() is tested under various scenarios.
 *
 * <h2>Test Steps</h2>
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

static void rt_test_008_005_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void rt_test_008_005_execute(void) {
  eventmask_t m;
  systime_t target_time;

  /* [8.5.1] Setting two, non contiguous, event flags.*/
  test_set_step(1);
  {
    chEvtAddEvents(5);
  }

  /* [8.5.2] Calling chEvtWaitAll() one time, the two flags must be
     returned.*/
  test_set_step(2);
  {
    m = chEvtWaitAll(5);
    test_assert(m == 5, "unexpected pending bit");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
  }

  /* [8.5.3] Setting one event flag.*/
  test_set_step(3);
  {
    chEvtAddEvents(4);
  }

  /* [8.5.4] Getting current time and starting a signaler thread, the
     thread will set another event flag after 50mS.*/
  test_set_step(4);
  {
    target_time = chTimeAddX(test_wait_tick(), TIME_MS2I(50));
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread3, chThdGetSelfX());
  }

  /* [8.5.5] Calling chEvtWaitAll() then verifying that both event
     flags have been received after 50mS and that the event flags mask
     has been emptied.*/
  test_set_step(5);
  {
    m = chEvtWaitAll(5);
    test_assert_time_window(target_time,
                            chTimeAddX(target_time, ALLOWED_DELAY),
                            "out of time window");
    test_assert(m == 5, "event flags error");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }
}

static const testcase_t rt_test_008_005 = {
  "Events Flags wait using chEvtWaitAll()",
  rt_test_008_005_setup,
  NULL,
  rt_test_008_005_execute
};

#if (CH_CFG_USE_EVENTS_TIMEOUT) || defined(__DOXYGEN__)
/**
 * @page rt_test_008_006 [8.6] Events Flags wait timeouts
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

static void rt_test_008_006_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
}

static void rt_test_008_006_execute(void) {
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
  {
    m = chEvtWaitOneTimeout(ALL_EVENTS, TIME_MS2I(50));
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAnyTimeout(ALL_EVENTS, TIME_MS2I(50));
    test_assert(m == 0, "spurious event");
    m = chEvtWaitAllTimeout(ALL_EVENTS, TIME_MS2I(50));
    test_assert(m == 0, "spurious event");
  }
}

static const testcase_t rt_test_008_006 = {
  "Events Flags wait timeouts",
  rt_test_008_006_setup,
  NULL,
  rt_test_008_006_execute
};
#endif /* CH_CFG_USE_EVENTS_TIMEOUT */

/**
 * @page rt_test_008_007 [8.7] Broadcasting using chEvtBroadcast()
 *
 * <h2>Description</h2>
 * Functionality of chEvtBroadcast() is tested.
 *
 * <h2>Test Steps</h2>
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

static void rt_test_008_007_setup(void) {
  chEvtGetAndClearEvents(ALL_EVENTS);
  chEvtObjectInit(&es1);
  chEvtObjectInit(&es2);
}

static void rt_test_008_007_execute(void) {
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
    target_time = chTimeAddX(test_wait_tick(), TIME_MS2I(50));
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   evt_thread7, "A");
  }

  /* [8.7.3] Calling chEvtWaitAll() then verifying that both event
     flags have been received after 50mS and that the event flags mask
     has been emptied.*/
  test_set_step(3);
  {
    m = chEvtWaitAll(5);
    test_assert_time_window(target_time,
                            chTimeAddX(target_time, ALLOWED_DELAY),
                            "out of time window");
    m = chEvtGetAndClearEvents(ALL_EVENTS);
    test_assert(m == 0, "stuck event");
    test_wait_threads();
  }

  /* [8.7.4] Unregistering from the Event Sources.*/
  test_set_step(4);
  {
    chEvtUnregister(&es1, &el1);
    chEvtUnregister(&es2, &el2);
    test_assert(!chEvtIsListeningI(&es1), "stuck listener");
    test_assert(!chEvtIsListeningI(&es2), "stuck listener");
  }
}

static const testcase_t rt_test_008_007 = {
  "Broadcasting using chEvtBroadcast()",
  rt_test_008_007_setup,
  NULL,
  rt_test_008_007_execute
};

>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_007.c
 * @brief   Synchronous Messages.
 */
const testcase_t * const test_sequence_007[] = {
  &test_007_001,
  NULL
};

#endif /* CH_CFG_USE_MESSAGES */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_008_array[] = {
  &rt_test_008_001,
  &rt_test_008_002,
  &rt_test_008_003,
  &rt_test_008_004,
  &rt_test_008_005,
#if (CH_CFG_USE_EVENTS_TIMEOUT) || defined(__DOXYGEN__)
  &rt_test_008_006,
#endif
  &rt_test_008_007,
  NULL
};

/**
 * @brief   Event Sources and Event Flags.
 */
const testsequence_t rt_test_sequence_008 = {
  "Event Sources and Event Flags",
  rt_test_sequence_008_array
};

#endif /* CH_CFG_USE_EVENTS */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_008.c
