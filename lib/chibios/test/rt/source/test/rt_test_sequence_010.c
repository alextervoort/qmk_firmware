/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c

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
 * @file    rt_test_sequence_010.c
 * @brief   Test Sequence 010 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * @page test_sequence_012 [12] Dynamic threads
=======
 * @page rt_test_sequence_010 [10] Benchmarks
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
 *
 * File: @ref rt_test_sequence_010.c
 *
 * <h2>Description</h2>
 * This module implements the test sequence for the dynamic thread
 * creation APIs.
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_DYNAMIC
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * - @subpage test_012_001
 * - @subpage test_012_002
=======
 * - @subpage rt_test_010_001
 * - @subpage rt_test_010_002
 * - @subpage rt_test_010_003
 * - @subpage rt_test_010_004
 * - @subpage rt_test_010_005
 * - @subpage rt_test_010_006
 * - @subpage rt_test_010_007
 * - @subpage rt_test_010_008
 * - @subpage rt_test_010_009
 * - @subpage rt_test_010_010
 * - @subpage rt_test_010_011
 * - @subpage rt_test_010_012
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
 * .
 */

#if (CH_CFG_USE_DYNAMIC) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
#if CH_CFG_USE_HEAP
static memory_heap_t heap1;
=======
#if CH_CFG_USE_SEMAPHORES || defined(__DOXYGEN__)
static semaphore_t sem1;
#endif
#if CH_CFG_USE_MUTEXES || defined(__DOXYGEN__)
static mutex_t mtx1;
#endif

static void tmo(void *param) {(void)param;}

#if CH_CFG_USE_MESSAGES
static THD_FUNCTION(bmk_thread1, p) {
  thread_t *tp;
  msg_t msg;

  (void)p;
  do {
    tp = chMsgWait();
    msg = chMsgGet(tp);
    chMsgRelease(tp, msg);
  } while (msg);
}

NOINLINE static unsigned int msg_loop_test(thread_t *tp) {
  systime_t start, end;

  uint32_t n = 0;
  start = test_wait_tick();
  end = chTimeAddX(start, TIME_MS2I(1000));
  do {
    (void)chMsgSend(tp, 1);
    n++;
#if defined(SIMULATOR)
    _sim_check_for_interrupts();
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
#endif
#if CH_CFG_USE_MEMPOOLS
static memory_pool_t mp1;
#endif

static THD_FUNCTION(dyn_thread1, p) {

  test_emit_token(*(char *)p);
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
#if (CH_CFG_USE_HEAP) || defined(__DOXYGEN__)
/**
 * @page test_012_001 [12.1] Threads creation from Memory Heap
=======
#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
/**
 * @page rt_test_010_001 [10.1] Messages performance #1
 *
 * <h2>Description</h2>
 * A message server thread is created with a lower priority than the
 * client thread, the messages throughput per second is measured and
 * the result printed on the output log.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MESSAGES
 * .
 *
 * <h2>Test Steps</h2>
 * - [10.1.1] The messenger thread is started at a lower priority than
 *   the current thread.
 * - [10.1.2] The number of messages exchanged is counted in a one
 *   second time window.
 * - [10.1.3] Score is printed.
 * .
 */

static void rt_test_010_001_execute(void) {
  uint32_t n;

  /* [10.1.1] The messenger thread is started at a lower priority than
     the current thread.*/
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()-1, bmk_thread1, NULL);
  }

  /* [10.1.2] The number of messages exchanged is counted in a one
     second time window.*/
  test_set_step(2);
  {
    n = msg_loop_test(threads[0]);
    test_wait_threads();
  }

  /* [10.1.3] Score is printed.*/
  test_set_step(3);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_print(" msgs/S, ");
    test_printn(n << 1);
    test_println(" ctxswc/S");
  }
}

static const testcase_t rt_test_010_001 = {
  "Messages performance #1",
  NULL,
  NULL,
  rt_test_010_001_execute
};
#endif /* CH_CFG_USE_MESSAGES */

#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
/**
 * @page rt_test_010_002 [10.2] Messages performance #2
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
 *
 * <h2>Description</h2>
 * Two threads are started by allocating the memory from the Memory
 * Heap then a third thread is started with a huge stack
 * requirement.<br> The test expects the first two threads to
 * successfully start and the third one to fail.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_HEAP
 * .
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * - [12.1.1] Getting base priority for threads.
 * - [12.1.2] Getting heap info before the test.
 * - [12.1.3] Creating thread 1, it is expected to succeed.
 * - [12.1.4] Creating thread 2, it is expected to succeed.
 * - [12.1.5] Creating thread 3, it is expected to fail.
 * - [12.1.6] Letting threads execute then checking the start order and
 *   freeing memory.
 * - [12.1.7] Getting heap info again for verification.
 * .
 */

static void test_012_001_setup(void) {
  chHeapObjectInit(&heap1, test_buffer, sizeof test_buffer);
}

static void test_012_001_execute(void) {
  size_t n1, total1, largest1;
  size_t n2, total2, largest2;
  tprio_t prio;

  /* [12.1.1] Getting base priority for threads.*/
=======
 * - [10.2.1] The messenger thread is started at an higher priority
 *   than the current thread.
 * - [10.2.2] The number of messages exchanged is counted in a one
 *   second time window.
 * - [10.2.3] Score is printed.
 * .
 */

static void rt_test_010_002_execute(void) {
  uint32_t n;

  /* [10.2.1] The messenger thread is started at an higher priority
     than the current thread.*/
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+1, bmk_thread1, NULL);
  }

  /* [10.2.2] The number of messages exchanged is counted in a one
     second time window.*/
  test_set_step(2);
  {
    n = msg_loop_test(threads[0]);
    test_wait_threads();
  }

  /* [10.2.3] Score is printed.*/
  test_set_step(3);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_print(" msgs/S, ");
    test_printn(n << 1);
    test_println(" ctxswc/S");
  }
}

static const testcase_t rt_test_010_002 = {
  "Messages performance #2",
  NULL,
  NULL,
  rt_test_010_002_execute
};
#endif /* CH_CFG_USE_MESSAGES */

#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
/**
 * @page rt_test_010_003 [10.3] Messages performance #3
 *
 * <h2>Description</h2>
 * A message server thread is created with an higher priority than the
 * client thread, four lower priority threads crowd the ready list, the
 * messages throughput per second is measured while the ready list and
 * the result printed on the output log.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MESSAGES
 * .
 *
 * <h2>Test Steps</h2>
 * - [10.3.1] The messenger thread is started at an higher priority
 *   than the current thread.
 * - [10.3.2] Four threads are started at a lower priority than the
 *   current thread.
 * - [10.3.3] The number of messages exchanged is counted in a one
 *   second time window.
 * - [10.3.4] Score is printed.
 * .
 */

static void rt_test_010_003_execute(void) {
  uint32_t n;

  /* [10.3.1] The messenger thread is started at an higher priority
     than the current thread.*/
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+1, bmk_thread1, NULL);
  }

  /* [10.3.2] Four threads are started at a lower priority than the
     current thread.*/
  test_set_step(2);
  {
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, chThdGetPriorityX()-2, bmk_thread3, NULL);
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, chThdGetPriorityX()-3, bmk_thread3, NULL);
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, chThdGetPriorityX()-4, bmk_thread3, NULL);
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, chThdGetPriorityX()-5, bmk_thread3, NULL);
  }

  /* [10.3.3] The number of messages exchanged is counted in a one
     second time window.*/
  test_set_step(3);
  {
    n = msg_loop_test(threads[0]);
    test_wait_threads();
  }

  /* [10.3.4] Score is printed.*/
  test_set_step(4);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_print(" msgs/S, ");
    test_printn(n << 1);
    test_println(" ctxswc/S");
  }
}

static const testcase_t rt_test_010_003 = {
  "Messages performance #3",
  NULL,
  NULL,
  rt_test_010_003_execute
};
#endif /* CH_CFG_USE_MESSAGES */

/**
 * @page rt_test_010_004 [10.4] Context Switch performance
 *
 * <h2>Description</h2>
 * A thread is created that just performs a @p chSchGoSleepS() into a
 * loop, the thread is awakened as fast is possible by the tester
 * thread.<br> The Context Switch performance is calculated by
 * measuring the number of iterations after a second of continuous
 * operations.
 *
 * <h2>Test Steps</h2>
 * - [10.4.1] Starting the target thread at an higher priority level.
 * - [10.4.2] Waking up the thread as fast as possible in a one second
 *   time window.
 * - [10.4.3] Stopping the target thread.
 * - [10.4.4] Score is printed.
 * .
 */

static void rt_test_010_004_execute(void) {
  thread_t *tp;
  uint32_t n;

  /* [10.4.1] Starting the target thread at an higher priority level.*/
  test_set_step(1);
  {
    tp = threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+1,
                                        bmk_thread4, NULL);
  }

  /* [10.4.2] Waking up the thread as fast as possible in a one second
     time window.*/
  test_set_step(2);
  {
    systime_t start, end;

    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chSysLock();
      chSchWakeupS(tp, MSG_OK);
      chSchWakeupS(tp, MSG_OK);
      chSchWakeupS(tp, MSG_OK);
      chSchWakeupS(tp, MSG_OK);
      chSysUnlock();
      n += 4;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.4.3] Stopping the target thread.*/
  test_set_step(3);
  {
    chSysLock();
    chSchWakeupS(tp, MSG_TIMEOUT);
    chSysUnlock();
    test_wait_threads();
  }

  /* [10.4.4] Score is printed.*/
  test_set_step(4);
  {
    test_print("--- Score : ");
    test_printn(n * 2);
    test_println(" ctxswc/S");
  }
}

static const testcase_t rt_test_010_004 = {
  "Context Switch performance",
  NULL,
  NULL,
  rt_test_010_004_execute
};

/**
 * @page rt_test_010_005 [10.5] Threads performance, full cycle
 *
 * <h2>Description</h2>
 * Threads are continuously created and terminated into a loop. A full
 * chThdCreateStatic() / @p chThdExit() / @p chThdWait() cycle is
 * performed in each iteration.<br> The performance is calculated by
 * measuring the number of iterations after a second of continuous
 * operations.
 *
 * <h2>Test Steps</h2>
 * - [10.5.1] A thread is created at a lower priority level and its
 *   termination detected using @p chThdWait(). The operation is
 *   repeated continuously in a one-second time window.
 * - [10.5.2] Score is printed.
 * .
 */

static void rt_test_010_005_execute(void) {
  uint32_t n;
  tprio_t prio = chThdGetPriorityX() - 1;
  systime_t start, end;

  /* [10.5.1] A thread is created at a lower priority level and its
     termination detected using @p chThdWait(). The operation is
     repeated continuously in a one-second time window.*/
  test_set_step(1);
  {
    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chThdWait(chThdCreateStatic(wa[0], WA_SIZE, prio, bmk_thread3, NULL));
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.5.2] Score is printed.*/
  test_set_step(2);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_println(" threads/S");
  }
}

static const testcase_t rt_test_010_005 = {
  "Threads performance, full cycle",
  NULL,
  NULL,
  rt_test_010_005_execute
};

/**
 * @page rt_test_010_006 [10.6] Threads performance, create/exit only
 *
 * <h2>Description</h2>
 * Threads are continuously created and terminated into a loop. A
 * partial @p chThdCreateStatic() / @p chThdExit() cycle is performed
 * in each iteration, the @p chThdWait() is not necessary because the
 * thread is created at an higher priority so there is no need to wait
 * for it to terminate.<br> The performance is calculated by measuring
 * the number of iterations after a second of continuous operations.
 *
 * <h2>Test Steps</h2>
 * - [10.6.1] A thread is created at an higher priority level and let
 *   terminate immediately. The operation is repeated continuously in a
 *   one-second time window.
 * - [10.6.2] Score is printed.
 * .
 */

static void rt_test_010_006_execute(void) {
  uint32_t n;
  tprio_t prio = chThdGetPriorityX() + 1;
  systime_t start, end;

  /* [10.6.1] A thread is created at an higher priority level and let
     terminate immediately. The operation is repeated continuously in a
     one-second time window.*/
  test_set_step(1);
  {
    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
#if CH_CFG_USE_REGISTRY
      chThdRelease(chThdCreateStatic(wa[0], WA_SIZE, prio, bmk_thread3, NULL));
#else
      chThdCreateStatic(wa[0], WA_SIZE, prio, bmk_thread3, NULL);
#endif
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.6.2] Score is printed.*/
  test_set_step(2);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_println(" threads/S");
  }
}

static const testcase_t rt_test_010_006 = {
  "Threads performance, create/exit only",
  NULL,
  NULL,
  rt_test_010_006_execute
};

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
/**
 * @page rt_test_010_007 [10.7] Mass reschedule performance
 *
 * <h2>Description</h2>
 * Five threads are created and atomically rescheduled by resetting the
 * semaphore where they are waiting on. The operation is performed into
 * a continuous loop.<br> The performance is calculated by measuring
 * the number of iterations after a second of continuous operations.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Steps</h2>
 * - [10.7.1] Five threads are created at higher priority that
 *   immediately enqueue on a semaphore.
 * - [10.7.2] The semaphore is reset waking up the five threads. The
 *   operation is repeated continuously in a one-second time window.
 * - [10.7.3] The five threads are terminated.
 * - [10.7.4] The score is printed.
 * .
 */

static void rt_test_010_007_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void rt_test_010_007_execute(void) {
  uint32_t n;

  /* [10.7.1] Five threads are created at higher priority that
     immediately enqueue on a semaphore.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.1.2] Getting heap info before the test.*/
  test_set_step(2);
  {
    n1 = chHeapStatus(&heap1, &total1, &largest1);
    test_assert(n1 == 1, "heap fragmented");
  }

  /* [12.1.3] Creating thread 1, it is expected to succeed.*/
=======
  /* [10.7.2] The semaphore is reset waking up the five threads. The
     operation is repeated continuously in a one-second time window.*/
  test_set_step(2);
  {
    systime_t start, end;

    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chSemReset(&sem1, 0);
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.7.3] The five threads are terminated.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(3);
  {
    threads[0] = chThdCreateFromHeap(&heap1,
                                     THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE),
                                     "dyn1",
                                     prio-1, dyn_thread1, "A");
    test_assert(threads[0] != NULL, "thread creation failed");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.1.4] Creating thread 2, it is expected to succeed.*/
=======
  /* [10.7.4] The score is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(4);
  {
    threads[1] = chThdCreateFromHeap(&heap1,
                                     THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE),
                                     "dyn2",
                                     prio-2, dyn_thread1, "B");
    test_assert(threads[1] != NULL, "thread creation failed");
  }
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c

  /* [12.1.5] Creating thread 3, it is expected to fail.*/
  test_set_step(5);
=======
}

static const testcase_t rt_test_010_007 = {
  "Mass reschedule performance",
  rt_test_010_007_setup,
  NULL,
  rt_test_010_007_execute
};
#endif /* CH_CFG_USE_SEMAPHORES */

/**
 * @page rt_test_010_008 [10.8] Round-Robin voluntary reschedule
 *
 * <h2>Description</h2>
 * Five threads are created at equal priority, each thread just
 * increases a variable and yields.<br> The performance is calculated
 * by measuring the number of iterations after a second of continuous
 * operations.
 *
 * <h2>Test Steps</h2>
 * - [10.8.1] The five threads are created at lower priority. The
 *   threds have equal priority and start calling @p chThdYield()
 *   continuously.
 * - [10.8.2] Waiting one second then terminating the 5 threads.
 * - [10.8.3] The score is printed.
 * .
 */

static void rt_test_010_008_execute(void) {
  uint32_t n;

  /* [10.8.1] The five threads are created at lower priority. The
     threds have equal priority and start calling @p chThdYield()
     continuously.*/
  test_set_step(1);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  {
    threads[2] = chThdCreateFromHeap(&heap1,
                                     THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE * 1024),
                                     "dyn3",
                                     prio-3, dyn_thread1, "C");
    test_assert(threads[2] == NULL, "thread creation not failed");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.1.6] Letting threads execute then checking the start order and
     freeing memory.*/
  test_set_step(6);
=======
  /* [10.8.2] Waiting one second then terminating the 5 threads.*/
  test_set_step(2);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  {
    test_wait_threads();
    test_assert_sequence("AB", "invalid sequence");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.1.7] Getting heap info again for verification.*/
  test_set_step(7);
=======
  /* [10.8.3] The score is printed.*/
  test_set_step(3);
  {
    test_print("--- Score : ");
    test_printn(n);
    test_println(" ctxswc/S");
  }
}

static const testcase_t rt_test_010_008 = {
  "Round-Robin voluntary reschedule",
  NULL,
  NULL,
  rt_test_010_008_execute
};

/**
 * @page rt_test_010_009 [10.9] Virtual Timers set/reset performance
 *
 * <h2>Description</h2>
 * A virtual timer is set and immediately reset into a continuous
 * loop.<br> The performance is calculated by measuring the number of
 * iterations after a second of continuous operations.
 *
 * <h2>Test Steps</h2>
 * - [10.9.1] Two timers are set then reset without waiting for their
 *   counter to elapse. The operation is repeated continuously in a
 *   one-second time window.
 * - [10.9.2] The score is printed.
 * .
 */

static void rt_test_010_009_execute(void) {
  static virtual_timer_t vt1, vt2;
  uint32_t n;

  /* [10.9.1] Two timers are set then reset without waiting for their
     counter to elapse. The operation is repeated continuously in a
     one-second time window.*/
  test_set_step(1);
  {
    systime_t start, end;

    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chSysLock();
      chVTDoSetI(&vt1, 1, tmo, NULL);
      chVTDoSetI(&vt2, 10000, tmo, NULL);
      chVTDoResetI(&vt1);
      chVTDoResetI(&vt2);
      chSysUnlock();
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.9.2] The score is printed.*/
  test_set_step(2);
  {
    test_print("--- Score : ");
    test_printn(n * 2);
    test_println(" timers/S");
  }
}

static const testcase_t rt_test_010_009 = {
  "Virtual Timers set/reset performance",
  NULL,
  NULL,
  rt_test_010_009_execute
};

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
/**
 * @page rt_test_010_010 [10.10] Semaphores wait/signal performance
 *
 * <h2>Description</h2>
 * A counting semaphore is taken/released into a continuous loop, no
 * Context Switch happens because the counter is always non
 * negative.<br> The performance is calculated by measuring the number
 * of iterations after a second of continuous operations.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Steps</h2>
 * - [10.10.1] A semaphore is teken and released. The operation is
 *   repeated continuously in a one-second time window.
 * - [10.10.2] The score is printed.
 * .
 */

static void rt_test_010_010_setup(void) {
  chSemObjectInit(&sem1, 1);
}

static void rt_test_010_010_execute(void) {
  uint32_t n;

  /* [10.10.1] A semaphore is teken and released. The operation is
     repeated continuously in a one-second time window.*/
  test_set_step(1);
  {
    systime_t start, end;

    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chSemWait(&sem1);
      chSemSignal(&sem1);
      chSemWait(&sem1);
      chSemSignal(&sem1);
      chSemWait(&sem1);
      chSemSignal(&sem1);
      chSemWait(&sem1);
      chSemSignal(&sem1);
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.10.2] The score is printed.*/
  test_set_step(2);
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  {
    n2 = chHeapStatus(&heap1, &total2, &largest2);
    test_assert(n1 == n2, "fragmentation changed");
    test_assert(total1 == total2, "total free space changed");
    test_assert(largest1 == largest2, "largest fragment size changed");
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
static const testcase_t test_012_001 = {
  "Threads creation from Memory Heap",
  test_012_001_setup,
  NULL,
  test_012_001_execute
=======
static const testcase_t rt_test_010_010 = {
  "Semaphores wait/signal performance",
  rt_test_010_010_setup,
  NULL,
  rt_test_010_010_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
};
#endif /* CH_CFG_USE_HEAP */

#if (CH_CFG_USE_MEMPOOLS) || defined(__DOXYGEN__)
/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * @page test_012_002 [12.2] Threads creation from Memory Pool
=======
 * @page rt_test_010_011 [10.11] Mutexes lock/unlock performance
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
 *
 * <h2>Description</h2>
 * Five thread creation are attempted from a pool containing only four
 * elements.<br> The test expects the first four threads to
 * successfully start and the last one to fail.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MEMPOOLS
 * .
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * - [12.2.1] Adding four working areas to the pool.
 * - [12.2.2] Getting base priority for threads.
 * - [12.2.3] Creating the five threads.
 * - [12.2.4] Testing that only the fifth thread creation failed.
 * - [12.2.5] Letting them run, free the memory then checking the
 *   execution sequence.
 * - [12.2.6] Testing that the pool contains four elements again.
 * .
 */

static void test_012_002_setup(void) {
  chPoolObjectInit(&mp1, THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE), NULL);
}

static void test_012_002_execute(void) {
  unsigned i;
  tprio_t prio;

  /* [12.2.1] Adding four working areas to the pool.*/
=======
 * - [10.11.1] A mutex is locked and unlocked. The operation is
 *   repeated continuously in a one-second time window.
 * - [10.11.2] The score is printed.
 * .
 */

static void rt_test_010_011_setup(void) {
  chMtxObjectInit(&mtx1);
}

static void rt_test_010_011_execute(void) {
  uint32_t n;

  /* [10.11.1] A mutex is locked and unlocked. The operation is
     repeated continuously in a one-second time window.*/
  test_set_step(1);
  {
    systime_t start, end;

    n = 0;
    start = test_wait_tick();
    end = chTimeAddX(start, TIME_MS2I(1000));
    do {
      chMtxLock(&mtx1);
      chMtxUnlock(&mtx1);
      chMtxLock(&mtx1);
      chMtxUnlock(&mtx1);
      chMtxLock(&mtx1);
      chMtxUnlock(&mtx1);
      chMtxLock(&mtx1);
      chMtxUnlock(&mtx1);
      n++;
#if defined(SIMULATOR)
      _sim_check_for_interrupts();
#endif
    } while (chVTIsSystemTimeWithinX(start, end));
  }

  /* [10.11.2] The score is printed.*/
  test_set_step(2);
  {
    test_print("--- Score : ");
    test_printn(n * 4);
    test_println(" lock+unlock/S");
  }
}

static const testcase_t rt_test_010_011 = {
  "Mutexes lock/unlock performance",
  rt_test_010_011_setup,
  NULL,
  rt_test_010_011_execute
};
#endif /* CH_CFG_USE_MUTEXES */

/**
 * @page rt_test_010_012 [10.12] RAM Footprint
 *
 * <h2>Description</h2>
 * The memory size of the various kernel objects is printed.
 *
 * <h2>Test Steps</h2>
 * - [10.12.1] The size of the system area is printed.
 * - [10.12.2] The size of a thread structure is printed.
 * - [10.12.3] The size of a virtual timer structure is printed.
 * - [10.12.4] The size of a semaphore structure is printed.
 * - [10.12.5] The size of a mutex is printed.
 * - [10.12.6] The size of a condition variable is printed.
 * - [10.12.7] The size of an event source is printed.
 * - [10.12.8] The size of an event listener is printed.
 * - [10.12.9] The size of a mailbox is printed.
 * .
 */

static void rt_test_010_012_execute(void) {

  /* [10.12.1] The size of the system area is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(1);
  {
    for (i = 0; i < 4; i++)
      chPoolFree(&mp1, wa[i]);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.2.2] Getting base priority for threads.*/
=======
  /* [10.12.2] The size of a thread structure is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(2);
  {
    prio = chThdGetPriorityX();
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.2.3] Creating the five threads.*/
=======
  /* [10.12.3] The size of a virtual timer structure is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(3);
  {
    threads[0] = chThdCreateFromMemoryPool(&mp1, "dyn1", prio-1, dyn_thread1, "A");
    threads[1] = chThdCreateFromMemoryPool(&mp1, "dyn2", prio-2, dyn_thread1, "B");
    threads[2] = chThdCreateFromMemoryPool(&mp1, "dyn3", prio-3, dyn_thread1, "C");
    threads[3] = chThdCreateFromMemoryPool(&mp1, "dyn4", prio-4, dyn_thread1, "D");
    threads[4] = chThdCreateFromMemoryPool(&mp1, "dyn5", prio-5, dyn_thread1, "E");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.2.4] Testing that only the fifth thread creation failed.*/
=======
  /* [10.12.4] The size of a semaphore structure is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(4);
  {
    test_assert((threads[0] != NULL) &&
                (threads[1] != NULL) &&
                (threads[2] != NULL) &&
                (threads[3] != NULL),
                "thread creation failed");
    test_assert(threads[4] == NULL,
                "thread creation not failed");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.2.5] Letting them run, free the memory then checking the
     execution sequence.*/
=======
  /* [10.12.5] The size of a mutex is printed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
  test_set_step(5);
  {
    test_wait_threads();
    test_assert_sequence("ABCD", "invalid sequence");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
  /* [12.2.6] Testing that the pool contains four elements again.*/
  test_set_step(6);
  {
    for (i = 0; i < 4; i++)
      test_assert(chPoolAlloc(&mp1) != NULL, "pool list empty");
    test_assert(chPoolAlloc(&mp1) == NULL, "pool list not empty");
  }
}

static const testcase_t test_012_002 = {
  "Threads creation from Memory Pool",
  test_012_002_setup,
  NULL,
  test_012_002_execute
=======
  /* [10.12.6] The size of a condition variable is printed.*/
  test_set_step(6);
  {
#if CH_CFG_USE_CONDVARS || defined(__DOXYGEN__)
    test_print("--- CondV.: ");
    test_printn(sizeof(condition_variable_t));
    test_println(" bytes");
#endif
  }

  /* [10.12.7] The size of an event source is printed.*/
  test_set_step(7);
  {
#if CH_CFG_USE_EVENTS || defined(__DOXYGEN__)
    test_print("--- EventS: ");
    test_printn(sizeof(event_source_t));
    test_println(" bytes");
#endif
  }

  /* [10.12.8] The size of an event listener is printed.*/
  test_set_step(8);
  {
#if CH_CFG_USE_EVENTS || defined(__DOXYGEN__)
    test_print("--- EventL: ");
    test_printn(sizeof(event_listener_t));
    test_println(" bytes");
#endif
  }

  /* [10.12.9] The size of a mailbox is printed.*/
  test_set_step(9);
  {
#if CH_CFG_USE_MAILBOXES || defined(__DOXYGEN__)
    test_print("--- MailB.: ");
    test_printn(sizeof(mailbox_t));
    test_println(" bytes");
#endif
  }
}

static const testcase_t rt_test_010_012 = {
  "RAM Footprint",
  NULL,
  NULL,
  rt_test_010_012_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
};
#endif /* CH_CFG_USE_MEMPOOLS */

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_012.c
 * @brief   Dynamic threads.
 */
const testcase_t * const test_sequence_012[] = {
#if (CH_CFG_USE_HEAP) || defined(__DOXYGEN__)
  &test_012_001,
#endif
#if (CH_CFG_USE_MEMPOOLS) || defined(__DOXYGEN__)
  &test_012_002,
#endif
  NULL
};

#endif /* CH_CFG_USE_DYNAMIC */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_010_array[] = {
#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
  &rt_test_010_001,
#endif
#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
  &rt_test_010_002,
#endif
#if (CH_CFG_USE_MESSAGES) || defined(__DOXYGEN__)
  &rt_test_010_003,
#endif
  &rt_test_010_004,
  &rt_test_010_005,
  &rt_test_010_006,
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &rt_test_010_007,
#endif
  &rt_test_010_008,
  &rt_test_010_009,
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &rt_test_010_010,
#endif
#if (CH_CFG_USE_MUTEXES) || defined(__DOXYGEN__)
  &rt_test_010_011,
#endif
  &rt_test_010_012,
  NULL
};

/**
 * @brief   Benchmarks.
 */
const testsequence_t rt_test_sequence_010 = {
  "Benchmarks",
  rt_test_sequence_010_array
};
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_010.c
