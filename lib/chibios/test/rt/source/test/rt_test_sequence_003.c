/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c

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
 * @file    rt_test_sequence_003.c
 * @brief   Test Sequence 003 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @page test_sequence_002 [2] System layer and port interface
=======
 * @page rt_test_sequence_003 [3] Threads Functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
 *
 * File: @ref rt_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The functionality of the system layer and port interface is tested.
 * Basic RT functionality is taken for granted or this test suite could
 * not even be executed. Errors in implementation are detected by
 * executing this sequence with the state checker enabled
 * (CH_DBG_STATE_CHECKER=TRUE).
 *
 * <h2>Test Cases</h2>
 * - @subpage rt_test_003_001
 * - @subpage rt_test_003_002
 * - @subpage rt_test_003_003
 * - @subpage rt_test_003_004
 * .
 */

/****************************************************************************
 * Shared code.
 ****************************************************************************/

/* Timer callback for testing system functions in ISR context.*/
static void vtcb(void *p) {
  syssts_t sts;

  (void)p;

  /* Testing normal case.*/
  chSysLockFromISR();
  chSysUnlockFromISR();

  /* Reentrant case.*/
  chSysLockFromISR();
  sts = chSysGetStatusAndLockX();
  chSysRestoreStatusX(sts);
  chSysUnlockFromISR();
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @page test_002_001 [2.1] System integrity functionality
=======
 * @page rt_test_003_001 [3.1] Thread Sleep functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The system self-test functionality is invoked in order to make an
 * initial system state assessment and for coverage.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * - [2.1.1] Testing Ready List integrity.
 * - [2.1.2] Testing Virtual Timers List integrity.
 * - [2.1.3] Testing Registry List integrity.
 * - [2.1.4] Testing Port-defined integrity.
 * .
 */

static void test_002_001_execute(void) {
  bool result;

  /* [2.1.1] Testing Ready List integrity.*/
  test_set_step(1);
  {
    chSysLock();
    result = chSysIntegrityCheckI(CH_INTEGRITY_RLIST);
    chSysUnlock();
    test_assert(result == false, "ready list check failed");
  }

  /* [2.1.2] Testing Virtual Timers List integrity.*/
  test_set_step(2);
  {
    chSysLock();
    result = chSysIntegrityCheckI(CH_INTEGRITY_VTLIST);
    chSysUnlock();
    test_assert(result == false, "virtual timers list check failed");
  }

  /* [2.1.3] Testing Registry List integrity.*/
  test_set_step(3);
  {
    chSysLock();
    result = chSysIntegrityCheckI(CH_INTEGRITY_REGISTRY);
    chSysUnlock();
    test_assert(result == false, "registry list check failed");
  }

  /* [2.1.4] Testing Port-defined integrity.*/
  test_set_step(4);
  {
    chSysLock();
    result = chSysIntegrityCheckI(CH_INTEGRITY_PORT);
    chSysUnlock();
    test_assert(result == false, "port layer check failed");
  }
}

static const testcase_t test_002_001 = {
  "System integrity functionality",
=======
 * - [3.1.1] The current system time is read then a sleep is performed
 *   for 100 system ticks and on exit the system time is verified
 *   again.
 * - [3.1.2] The current system time is read then a sleep is performed
 *   for 100000 microseconds and on exit the system time is verified
 *   again.
 * - [3.1.3] The current system time is read then a sleep is performed
 *   for 100 milliseconds and on exit the system time is verified
 *   again.
 * - [3.1.4] The current system time is read then a sleep is performed
 *   for 1 second and on exit the system time is verified again.
 * - [3.1.5] Function chThdSleepUntil() is tested with a timeline of
 *   "now" + 100 ticks.
 * .
 */

static void rt_test_003_001_execute(void) {
  systime_t time;

  /* [3.1.1] The current system time is read then a sleep is performed
     for 100 system ticks and on exit the system time is verified
     again.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chThdSleep(100);
    test_assert_time_window(chTimeAddX(time, 100),
                            chTimeAddX(time, 100 + CH_CFG_ST_TIMEDELTA + 1),
                            "out of time window");
  }

  /* [3.1.2] The current system time is read then a sleep is performed
     for 100000 microseconds and on exit the system time is verified
     again.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMicroseconds(100000);
    test_assert_time_window(chTimeAddX(time, TIME_US2I(100000)),
                            chTimeAddX(time, TIME_US2I(100000) + CH_CFG_ST_TIMEDELTA + 1),
                            "out of time window");
  }

  /* [3.1.3] The current system time is read then a sleep is performed
     for 100 milliseconds and on exit the system time is verified
     again.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMilliseconds(100);
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(100)),
                            chTimeAddX(time, TIME_MS2I(100) + CH_CFG_ST_TIMEDELTA + 1),
                            "out of time window");
  }

  /* [3.1.4] The current system time is read then a sleep is performed
     for 1 second and on exit the system time is verified again.*/
  test_set_step(4);
  {
    time = chVTGetSystemTimeX();
    chThdSleepSeconds(1);
    test_assert_time_window(chTimeAddX(time, TIME_S2I(1)),
                            chTimeAddX(time, TIME_S2I(1) + CH_CFG_ST_TIMEDELTA + 1),
                            "out of time window");
  }

  /* [3.1.5] Function chThdSleepUntil() is tested with a timeline of
     "now" + 100 ticks.*/
  test_set_step(5);
  {
    time = chVTGetSystemTimeX();
    chThdSleepUntil(chTimeAddX(time, 100));
    test_assert_time_window(chTimeAddX(time, 100),
                            chTimeAddX(time, 100 + CH_CFG_ST_TIMEDELTA + 1),
                            "out of time window");
  }
}

static const testcase_t rt_test_003_001 = {
  "Thread Sleep functionality",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  NULL,
  NULL,
  rt_test_003_001_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @page test_002_002 [2.2] Critical zones functionality
=======
 * @page rt_test_003_002 [3.2] Ready List functionality, threads priority order
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The critical zones API is invoked for coverage.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * - [2.2.1] Testing chSysGetStatusAndLockX() and
 *   chSysRestoreStatusX(), non reentrant case.
 * - [2.2.2] Testing chSysGetStatusAndLockX() and
 *   chSysRestoreStatusX(), reentrant case.
 * - [2.2.3] Testing chSysUnconditionalLock().
 * - [2.2.4] Testing chSysUnconditionalUnlock().
 * - [2.2.5] Testing from ISR context using a virtual timer.
 * .
 */

static void test_002_002_execute(void) {
  syssts_t sts;
  virtual_timer_t vt;

  /* [2.2.1] Testing chSysGetStatusAndLockX() and
     chSysRestoreStatusX(), non reentrant case.*/
=======
 * - [3.2.1] Creating 5 threads with increasing priority, execution
 *   sequence is tested.
 * - [3.2.2] Creating 5 threads with decreasing priority, execution
 *   sequence is tested.
 * - [3.2.3] Creating 5 threads with pseudo-random priority, execution
 *   sequence is tested.
 * .
 */

static void rt_test_003_002_execute(void) {

  /* [3.2.1] Creating 5 threads with increasing priority, execution
     sequence is tested.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  test_set_step(1);
  {
    sts = chSysGetStatusAndLockX();
    chSysRestoreStatusX(sts);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
  /* [2.2.2] Testing chSysGetStatusAndLockX() and
     chSysRestoreStatusX(), reentrant case.*/
=======
  /* [3.2.2] Creating 5 threads with decreasing priority, execution
     sequence is tested.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  test_set_step(2);
  {
    chSysLock();
    sts = chSysGetStatusAndLockX();
    chSysRestoreStatusX(sts);
    chSysUnlock();
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
  /* [2.2.3] Testing chSysUnconditionalLock().*/
=======
  /* [3.2.3] Creating 5 threads with pseudo-random priority, execution
     sequence is tested.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  test_set_step(3);
  {
    chSysUnconditionalLock();
    chSysUnconditionalLock();
    chSysUnlock();
  }

  /* [2.2.4] Testing chSysUnconditionalUnlock().*/
  test_set_step(4);
  {
    chSysLock();
    chSysUnconditionalUnlock();
    chSysUnconditionalUnlock();
  }

  /* [2.2.5] Testing from ISR context using a virtual timer.*/
  test_set_step(5);
  {
    chVTObjectInit(&vt);
    chVTSet(&vt, 1, vtcb, NULL);
    chThdSleep(10);

    test_assert(chVTIsArmed(&vt) == false, "timer still armed");
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
static const testcase_t test_002_002 = {
  "Critical zones functionality",
=======
static const testcase_t rt_test_003_002 = {
  "Ready List functionality, threads priority order",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  NULL,
  NULL,
  rt_test_003_002_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @page test_002_003 [2.3] Interrupts handling functionality
=======
 * @page rt_test_003_003 [3.3] Priority change test
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The interrupts handling API is invoked for coverage.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * - [2.3.1] Testing chSysSuspend(), chSysDisable() and chSysEnable().
 * .
 */

static void test_002_003_execute(void) {

  /* [2.3.1] Testing chSysSuspend(), chSysDisable() and
     chSysEnable().*/
  test_set_step(1);
  {
    chSysSuspend();
    chSysDisable();
    chSysSuspend();
    chSysEnable();
  }
}

static const testcase_t test_002_003 = {
  "Interrupts handling functionality",
=======
 * - [3.3.1] Thread priority is increased by one then a check is
 *   performed.
 * - [3.3.2] Thread priority is returned to the previous value then a
 *   check is performed.
 * .
 */

static void rt_test_003_003_execute(void) {
  tprio_t prio, p1;

  /* [3.3.1] Thread priority is increased by one then a check is
     performed.*/
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
    p1 = chThdSetPriority(prio + 1);
    test_assert(p1 == prio, "unexpected returned priority level");
    test_assert(chThdGetPriorityX() == prio + 1, "unexpected priority level");
  }

  /* [3.3.2] Thread priority is returned to the previous value then a
     check is performed.*/
  test_set_step(2);
  {
    p1 = chThdSetPriority(p1);
    test_assert(p1 == prio + 1, "unexpected returned priority level");
    test_assert(chThdGetPriorityX() == prio, "unexpected priority level");
  }
}

static const testcase_t rt_test_003_003 = {
  "Priority change test",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  NULL,
  NULL,
  rt_test_003_003_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @page test_002_004 [2.4] System Tick Counter functionality
=======
 * @page rt_test_003_004 [3.4] Priority change test with Priority Inheritance
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The functionality of the API @p chVTGetSystemTimeX() is tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * - [2.4.1] A System Tick Counter increment is expected, the test
 *   simply hangs if it does not happen.
 * .
 */

static void test_002_004_execute(void) {

  /* [2.4.1] A System Tick Counter increment is expected, the test
     simply hangs if it does not happen.*/
  test_set_step(1);
  {
    systime_t time = chVTGetSystemTimeX();
    while (time == chVTGetSystemTimeX()) {
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    }
  }
}

static const testcase_t test_002_004 = {
  "System Tick Counter functionality",
=======
 * - [3.4.1] Simulating a priority boost situation (prio > realprio).
 * - [3.4.2] Raising thread priority above original priority but below
 *   the boosted level.
 * - [3.4.3] Raising thread priority above the boosted level.
 * - [3.4.4] Restoring original conditions.
 * .
 */

static void rt_test_003_004_execute(void) {
  tprio_t prio, p1;

  /* [3.4.1] Simulating a priority boost situation (prio > realprio).*/
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
    chThdGetSelfX()->prio += 2;
    test_assert(chThdGetPriorityX() == prio + 2, "unexpected priority level");
  }

  /* [3.4.2] Raising thread priority above original priority but below
     the boosted level.*/
  test_set_step(2);
  {
    p1 = chThdSetPriority(prio + 1);
    test_assert(p1 == prio, "unexpected returned priority level");
    test_assert(chThdGetSelfX()->prio == prio + 2, "unexpected priority level");
    test_assert(chThdGetSelfX()->realprio == prio + 1, "unexpected returned real priority level");
  }

  /* [3.4.3] Raising thread priority above the boosted level.*/
  test_set_step(3);
  {
    p1 = chThdSetPriority(prio + 3);
    test_assert(p1 == prio + 1, "unexpected returned priority level");
    test_assert(chThdGetSelfX()->prio == prio + 3, "unexpected priority level");
    test_assert(chThdGetSelfX()->realprio == prio + 3, "unexpected real priority level");
  }

  /* [3.4.4] Restoring original conditions.*/
  test_set_step(4);
  {
    chSysLock();
    chThdGetSelfX()->prio = prio;
    chThdGetSelfX()->realprio = prio;
    chSysUnlock();
  }
}

static const testcase_t rt_test_003_004 = {
  "Priority change test with Priority Inheritance",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  NULL,
  NULL,
  rt_test_003_004_execute
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_002.c
 * @brief   System layer and port interface.
 */
const testcase_t * const test_sequence_002[] = {
  &test_002_001,
  &test_002_002,
  &test_002_003,
  &test_002_004,
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_003_array[] = {
  &rt_test_003_001,
  &rt_test_003_002,
  &rt_test_003_003,
#if (CH_CFG_USE_MUTEXES) || defined(__DOXYGEN__)
  &rt_test_003_004,
#endif
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_003.c
  NULL
};

/**
 * @brief   Threads Functionality.
 */
const testsequence_t rt_test_sequence_003 = {
  "Threads Functionality",
  rt_test_sequence_003_array
};
