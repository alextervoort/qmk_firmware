/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c

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
 * @file    rt_test_sequence_002.c
 * @brief   Test Sequence 002 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * @page test_sequence_001 [1] Information
=======
 * @page rt_test_sequence_002 [2] System layer and port interface
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
 *
 * File: @ref rt_test_sequence_002.c
 *
 * <h2>Description</h2>
 * This sequence reports configuration and version information about
 * the RT kernel.
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * - @subpage test_001_001
 * - @subpage test_001_002
=======
 * - @subpage rt_test_002_001
 * - @subpage rt_test_002_002
 * - @subpage rt_test_002_003
 * - @subpage rt_test_002_004
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
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
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * @page test_001_001 [1.1] Kernel Info
=======
 * @page rt_test_002_001 [2.1] System integrity functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The version numbers are reported.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * - [1.1.1] Prints the version string.
 * .
 */

static void test_001_001_execute(void) {

  /* [1.1.1] Prints the version string.*/
  test_set_step(1);
  {
    test_println("--- Product:                   ChibiOS/RT");
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

static const testcase_t test_001_001 = {
  "Kernel Info",
=======
 * - [2.1.1] Testing Ready List integrity.
 * - [2.1.2] Testing Virtual Timers List integrity.
 * - [2.1.3] Testing Registry List integrity.
 * - [2.1.4] Testing Port-defined integrity.
 * .
 */

static void rt_test_002_001_execute(void) {
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

static const testcase_t rt_test_002_001 = {
  "System integrity functionality",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
  NULL,
  NULL,
  rt_test_002_001_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * @page test_001_002 [1.2] Kernel Settings
=======
 * @page rt_test_002_002 [2.2] Critical zones functionality
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The static kernel settings are reported.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * - [1.2.1] Prints the configuration options settings.
 * .
 */

static void test_001_002_execute(void) {

  /* [1.2.1] Prints the configuration options settings.*/
  test_set_step(1);
  {
    test_print("--- CH_CFG_ST_RESOLUTION:      ");
    test_printn(CH_CFG_ST_RESOLUTION);
    test_println("");
    test_print("--- CH_CFG_ST_FREQUENCY:       ");
    test_printn(CH_CFG_ST_FREQUENCY);
    test_println("");
    test_print("--- CH_CFG_ST_TIMEDELTA:       ");
    test_printn(CH_CFG_ST_TIMEDELTA);
    test_println("");
    test_print("--- CH_CFG_TIME_QUANTUM:       ");
    test_printn(CH_CFG_TIME_QUANTUM);
    test_println("");
    test_print("--- CH_CFG_MEMCORE_SIZE:       ");
    test_printn(CH_CFG_MEMCORE_SIZE);
    test_println("");
    test_print("--- CH_CFG_NO_IDLE_THREAD:     ");
    test_printn(CH_CFG_NO_IDLE_THREAD);
    test_println("");
    test_print("--- CH_CFG_OPTIMIZE_SPEED:     ");
    test_printn(CH_CFG_OPTIMIZE_SPEED);
    test_println("");
    test_print("--- CH_CFG_USE_TM:             ");
    test_printn(CH_CFG_USE_TM);
    test_println("");
    test_print("--- CH_CFG_USE_REGISTRY:       ");
    test_printn(CH_CFG_USE_REGISTRY);
    test_println("");
    test_print("--- CH_CFG_USE_WAITEXIT:       ");
    test_printn(CH_CFG_USE_WAITEXIT);
    test_println("");
    test_print("--- CH_CFG_USE_SEMAPHORES:     ");
    test_printn(CH_CFG_USE_SEMAPHORES);
    test_println("");
    test_print("--- CH_CFG_USE_SEMAPHORES_PRI: ");
    test_printn(CH_CFG_USE_SEMAPHORES_PRIORITY);
    test_println("");
    test_print("--- CH_CFG_USE_MUTEXES:        ");
    test_printn(CH_CFG_USE_MUTEXES);
    test_println("");
    test_print("--- CH_CFG_USE_MUTEXES_RECURS: ");
    test_printn(CH_CFG_USE_MUTEXES_RECURSIVE);
    test_println("");
    test_print("--- CH_CFG_USE_CONDVARS:       ");
    test_printn(CH_CFG_USE_CONDVARS);
    test_println("");
    test_print("--- CH_CFG_USE_CONDVARS_TIMEO: ");
    test_printn(CH_CFG_USE_CONDVARS_TIMEOUT);
    test_println("");
    test_print("--- CH_CFG_USE_EVENTS:         ");
    test_printn(CH_CFG_USE_EVENTS);
    test_println("");
    test_print("--- CH_CFG_USE_EVENTS_TIMEOUT: ");
    test_printn(CH_CFG_USE_EVENTS_TIMEOUT);
    test_println("");
    test_print("--- CH_CFG_USE_MESSAGES:       ");
    test_printn(CH_CFG_USE_MESSAGES);
    test_println("");
    test_print("--- CH_CFG_USE_MESSAGES_PRI:   ");
    test_printn(CH_CFG_USE_MESSAGES_PRIORITY);
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
    test_print("--- CH_CFG_USE_DYNAMIC:        ");
    test_printn(CH_CFG_USE_DYNAMIC);
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
    test_print("--- CH_DBG_TRACE_MASK:         ");
    test_printn(CH_DBG_TRACE_MASK);
    test_println("");
    test_print("--- CH_DBG_TRACE_BUFFER_SIZE:  ");
    test_printn(CH_DBG_TRACE_BUFFER_SIZE);
    test_println("");
    test_print("--- CH_DBG_ENABLE_STACK_CHECK: ");
    test_printn(CH_DBG_ENABLE_STACK_CHECK);
    test_println("");
    test_print("--- CH_DBG_FILL_THREADS:       ");
    test_printn(CH_DBG_FILL_THREADS);
    test_println("");
    test_print("--- CH_DBG_THREADS_PROFILING:  ");
    test_printn(CH_DBG_THREADS_PROFILING);
    test_println("");
  }
}

static const testcase_t test_001_002 = {
  "Kernel Settings",
=======
 * - [2.2.1] Testing chSysGetStatusAndLockX() and
 *   chSysRestoreStatusX(), non reentrant case.
 * - [2.2.2] Testing chSysGetStatusAndLockX() and
 *   chSysRestoreStatusX(), reentrant case.
 * - [2.2.3] Testing chSysUnconditionalLock().
 * - [2.2.4] Testing chSysUnconditionalUnlock().
 * - [2.2.5] Testing from ISR context using a virtual timer.
 * .
 */

static void rt_test_002_002_execute(void) {
  syssts_t sts;
  virtual_timer_t vt;

  /* [2.2.1] Testing chSysGetStatusAndLockX() and
     chSysRestoreStatusX(), non reentrant case.*/
  test_set_step(1);
  {
    sts = chSysGetStatusAndLockX();
    chSysRestoreStatusX(sts);
  }

  /* [2.2.2] Testing chSysGetStatusAndLockX() and
     chSysRestoreStatusX(), reentrant case.*/
  test_set_step(2);
  {
    chSysLock();
    sts = chSysGetStatusAndLockX();
    chSysRestoreStatusX(sts);
    chSysUnlock();
  }

  /* [2.2.3] Testing chSysUnconditionalLock().*/
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

static const testcase_t rt_test_002_002 = {
  "Critical zones functionality",
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
  NULL,
  NULL,
  rt_test_002_002_execute
};

<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
=======
/**
 * @page rt_test_002_003 [2.3] Interrupts handling functionality
 *
 * <h2>Description</h2>
 * The interrupts handling API is invoked for coverage.
 *
 * <h2>Test Steps</h2>
 * - [2.3.1] Testing chSysSuspend(), chSysDisable() and chSysEnable().
 * .
 */

static void rt_test_002_003_execute(void) {

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

static const testcase_t rt_test_002_003 = {
  "Interrupts handling functionality",
  NULL,
  NULL,
  rt_test_002_003_execute
};

/**
 * @page rt_test_002_004 [2.4] System Tick Counter functionality
 *
 * <h2>Description</h2>
 * The functionality of the API @p chVTGetSystemTimeX() is tested.
 *
 * <h2>Test Steps</h2>
 * - [2.4.1] A System Tick Counter increment is expected, the test
 *   simply hangs if it does not happen.
 * .
 */

static void rt_test_002_004_execute(void) {

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

static const testcase_t rt_test_002_004 = {
  "System Tick Counter functionality",
  NULL,
  NULL,
  rt_test_002_004_execute
};

>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_001.c
 * @brief   Information.
 */
const testcase_t * const test_sequence_001[] = {
  &test_001_001,
  &test_001_002,
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_002_array[] = {
  &rt_test_002_001,
  &rt_test_002_002,
  &rt_test_002_003,
  &rt_test_002_004,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_002.c
  NULL
};

/**
 * @brief   System layer and port interface.
 */
const testsequence_t rt_test_sequence_002 = {
  "System layer and port interface",
  rt_test_sequence_002_array
};
