/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c

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
 * @file    rt_test_sequence_006.c
 * @brief   Test Sequence 006 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_sequence_005 [5] Counter and Binary Semaphores
=======
 * @page rt_test_sequence_006 [6] Mutexes, Condition Variables and Priority Inheritance
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * File: @ref rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/RT functionalities related to
 * counter semaphores.
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - @subpage test_005_001
 * - @subpage test_005_002
 * - @subpage test_005_003
 * - @subpage test_005_004
 * - @subpage test_005_005
 * - @subpage test_005_006
=======
 * - @subpage rt_test_006_001
 * - @subpage rt_test_006_002
 * - @subpage rt_test_006_003
 * - @subpage rt_test_006_004
 * - @subpage rt_test_006_005
 * - @subpage rt_test_006_006
 * - @subpage rt_test_006_007
 * - @subpage rt_test_006_008
 * - @subpage rt_test_006_009
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 * .
 */

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#include "ch.h"

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
static semaphore_t sem1;
=======
#if CH_DBG_THREADS_PROFILING || defined(__DOXYGEN__)
/**
 * @brief   CPU pulse.
 * @note    The current implementation is not totally reliable.
 *
 * @param[in] duration      CPU pulse duration in milliseconds
 */
void test_cpu_pulse(unsigned duration) {
  systime_t start, end, now;

  start = chThdGetTicksX(chThdGetSelfX());
  end = chTimeAddX(start, TIME_MS2I(duration));
  do {
    now = chThdGetTicksX(chThdGetSelfX());
#if defined(SIMULATOR)
    _sim_check_for_interrupts();
#endif
  }
  while (chTimeIsInRangeX(now, start, end));
}
#endif /* CH_DBG_THREADS_PROFILING */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c

static THD_FUNCTION(thread1, p) {

  chSemWait(&sem1);
  test_emit_token(*(char *)p);
}

static THD_FUNCTION(thread2, p) {

  (void)p;
  chThdSleepMilliseconds(50);
  chSysLock();
  chSemSignalI(&sem1); /* For coverage reasons */
  chSchRescheduleS();
  chSysUnlock();
}

static THD_FUNCTION(thread3, p) {

  (void)p;
  chSemWait(&sem1);
  chSemSignal(&sem1);
}

static THD_FUNCTION(thread4, p) {

  chBSemSignal((binary_semaphore_t *)p);
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_001 [5.1] Semaphore primitives, no state change
=======
 * @page rt_test_006_001 [6.1] Priority enqueuing test
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * Wait, Signal and Reset primitives are tested. The testing thread
 * does not trigger a state change.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.1.1] The function chSemWait() is invoked, after return the
 *   counter and the returned message are tested.
 * - [5.1.2] The function chSemSignal() is invoked, after return the
 *   counter is tested.
 * - [5.1.3] The function chSemReset() is invoked, after return the
 *   counter is tested.
 * .
 */

static void test_005_001_setup(void) {
  chSemObjectInit(&sem1, 1);
}

static void test_005_001_teardown(void) {
  chSemReset(&sem1, 0);
}

static void test_005_001_execute(void) {

  /* [5.1.1] The function chSemWait() is invoked, after return the
     counter and the returned message are tested.*/
=======
 * - [6.1.1] Getting the initial priority.
 * - [6.1.2] Locking the mutex.
 * - [6.1.3] Five threads are created that try to lock and unlock the
 *   mutex then terminate. The threads are created in ascending
 *   priority order.
 * - [6.1.4] Unlocking the mutex, the threads will wakeup in priority
 *   order because the mutext queue is an ordered one.
 * .
 */

static void rt_test_006_001_setup(void) {
  chMtxObjectInit(&m1);
}

static void rt_test_006_001_execute(void) {
  tprio_t prio;

  /* [6.1.1] Getting the initial priority.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    msg_t msg;

    msg = chSemWait(&sem1);
    test_assert_lock(chSemGetCounterI(&sem1) == 0, "wrong counter value");
    test_assert(MSG_OK == msg, "wrong returned message");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.1.2] The function chSemSignal() is invoked, after return the
     counter is tested.*/
=======
  /* [6.1.2] Locking the mutex.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(2);
  {
    chSemSignal(&sem1);
    test_assert_lock(chSemGetCounterI(&sem1) == 1, "wrong counter value");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.1.3] The function chSemReset() is invoked, after return the
     counter is tested.*/
  test_set_step(3);
  {
    chSemReset(&sem1, 2);
    test_assert_lock(chSemGetCounterI(&sem1) == 2, "wrong counter value");
  }
}

static const testcase_t test_005_001 = {
  "Semaphore primitives, no state change",
  test_005_001_setup,
  test_005_001_teardown,
  test_005_001_execute
=======
  /* [6.1.3] Five threads are created that try to lock and unlock the
     mutex then terminate. The threads are created in ascending
     priority order.*/
  test_set_step(3);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, prio+1, thread1, "E");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, prio+2, thread1, "D");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, prio+3, thread1, "C");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, prio+4, thread1, "B");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, prio+5, thread1, "A");
  }

  /* [6.1.4] Unlocking the mutex, the threads will wakeup in priority
     order because the mutext queue is an ordered one.*/
  test_set_step(4);
  {
    chMtxUnlock(&m1);
    test_wait_threads();
    test_assert(prio == chThdGetPriorityX(), "wrong priority level");
    test_assert_sequence("ABCDE", "invalid sequence");
  }
}

static const testcase_t rt_test_006_001 = {
  "Priority enqueuing test",
  rt_test_006_001_setup,
  NULL,
  rt_test_006_001_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_002 [5.2] Semaphore enqueuing test
=======
 * @page rt_test_006_002 [6.2] Priority inheritance, simple case
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * Five threads with randomized priorities are enqueued to a semaphore
 * then awakened one at time. The test expects that the threads reach
 * their goal in FIFO order or priority order depending on the @p
 * CH_CFG_USE_SEMAPHORES_PRIORITY configuration setting.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.2.1] Five threads are created with mixed priority levels (not
 *   increasing nor decreasing). Threads enqueue on a semaphore
 *   initialized to zero.
 * - [5.2.2] The semaphore is signaled 5 times. The thread activation
 *   sequence is tested.
 * .
 */

static void test_005_002_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void test_005_002_execute(void) {

  /* [5.2.1] Five threads are created with mixed priority levels (not
     increasing nor decreasing). Threads enqueue on a semaphore
     initialized to zero.*/
=======
 * - [6.2.1] Getting the system time for test duration measurement.
 * - [6.2.2] The three contenders threads are created and let run
 *   atomically, the goals sequence is tested, the threads must
 *   complete in priority order.
 * - [6.2.3] Testing that all threads completed within the specified
 *   time windows (100mS...100mS+ALLOWED_DELAY).
 * .
 */

static void rt_test_006_002_setup(void) {
  chMtxObjectInit(&m1);
}

static void rt_test_006_002_execute(void) {
  systime_t time;

  /* [6.2.1] Getting the system time for test duration measurement.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+5, thread1, "A");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, chThdGetPriorityX()+1, thread1, "B");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, chThdGetPriorityX()+3, thread1, "C");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, chThdGetPriorityX()+4, thread1, "D");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, chThdGetPriorityX()+2, thread1, "E");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.2.2] The semaphore is signaled 5 times. The thread activation
     sequence is tested.*/
=======
  /* [6.2.2] The three contenders threads are created and let run
     atomically, the goals sequence is tested, the threads must
     complete in priority order.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(2);
  {
    chSemSignal(&sem1);
    chSemSignal(&sem1);
    chSemSignal(&sem1);
    chSemSignal(&sem1);
    chSemSignal(&sem1);
    test_wait_threads();
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
#if CH_CFG_USE_SEMAPHORES_PRIORITY
    test_assert_sequence("ADCEB", "invalid sequence");
#else
    test_assert_sequence("ABCDE", "invalid sequence");
#endif
  }
}

static const testcase_t test_005_002 = {
  "Semaphore enqueuing test",
  test_005_002_setup,
=======
    test_assert_sequence("ABC", "invalid sequence");
  }

  /* [6.2.3] Testing that all threads completed within the specified
     time windows (100mS...100mS+ALLOWED_DELAY).*/
  test_set_step(3);
  {
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(100)),
                            chTimeAddX(time, TIME_MS2I(100) + ALLOWED_DELAY),
                            "out of time window");
  }
}

static const testcase_t rt_test_006_002 = {
  "Priority inheritance, simple case",
  rt_test_006_002_setup,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  NULL,
  rt_test_006_002_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_003 [5.3] Semaphore timeout test
=======
 * @page rt_test_006_003 [6.3] Priority inheritance, complex case
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * The three possible semaphore waiting modes (do not wait, wait with
 * timeout, wait without timeout) are explored. The test expects that
 * the semaphore wait function returns the correct value in each of the
 * above scenario and that the semaphore structure status is correct
 * after each operation.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.3.1] Testing special case TIME_IMMEDIATE.
 * - [5.3.2] Testing non-timeout condition.
 * - [5.3.3] Testing timeout condition.
 * .
 */

static void test_005_003_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void test_005_003_execute(void) {
  unsigned i;
  systime_t target_time;
  msg_t msg;

  /* [5.3.1] Testing special case TIME_IMMEDIATE.*/
=======
 * - [6.3.1] Getting the system time for test duration measurement.
 * - [6.3.2] The five contenders threads are created and let run
 *   atomically, the goals sequence is tested, the threads must
 *   complete in priority order.
 * - [6.3.3] Testing that all threads completed within the specified
 *   time windows (110mS...110mS+ALLOWED_DELAY).
 * .
 */

static void rt_test_006_003_setup(void) {
  chMtxObjectInit(&m1); /* Mutex B.*/
  chMtxObjectInit(&m2); /* Mutex A.*/
}

static void rt_test_006_003_execute(void) {
  systime_t time;

  /* [6.3.1] Getting the system time for test duration measurement.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    msg = chSemWaitTimeout(&sem1, TIME_IMMEDIATE);
    test_assert(msg == MSG_TIMEOUT, "wrong wake-up message");
    test_assert(queue_isempty(&sem1.queue), "queue not empty");
    test_assert(sem1.cnt == 0, "counter not zero");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.3.2] Testing non-timeout condition.*/
=======
  /* [6.3.2] The five contenders threads are created and let run
     atomically, the goals sequence is tested, the threads must
     complete in priority order.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(2);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX() - 1,
                                   thread2, 0);
    msg = chSemWaitTimeout(&sem1, MS2ST(500));
    test_wait_threads();
    test_assert(msg == MSG_OK, "wrong wake-up message");
    test_assert(queue_isempty(&sem1.queue), "queue not empty");
    test_assert(sem1.cnt == 0, "counter not zero");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.3.3] Testing timeout condition.*/
  test_set_step(3);
  {
    target_time = test_wait_tick() + MS2ST(5 * 50);
    for (i = 0; i < 5; i++) {
      test_emit_token('A' + i);
      msg = chSemWaitTimeout(&sem1, MS2ST(50));
      test_assert(msg == MSG_TIMEOUT, "wrong wake-up message");
      test_assert(queue_isempty(&sem1.queue), "queue not empty");
      test_assert(sem1.cnt == 0, "counter not zero");
    }
    test_assert_sequence("ABCDE", "invalid sequence");
    test_assert_time_window(target_time, target_time + ALLOWED_DELAY,
=======
  /* [6.3.3] Testing that all threads completed within the specified
     time windows (110mS...110mS+ALLOWED_DELAY).*/
  test_set_step(3);
  {
    test_assert_time_window(chTimeAddX(time, TIME_MS2I(110)),
                            chTimeAddX(time, TIME_MS2I(110) + ALLOWED_DELAY),
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
                            "out of time window");
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
static const testcase_t test_005_003 = {
  "Semaphore timeout test",
  test_005_003_setup,
=======
static const testcase_t rt_test_006_003 = {
  "Priority inheritance, complex case",
  rt_test_006_003_setup,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  NULL,
  rt_test_006_003_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_004 [5.4] Testing chSemAddCounterI() functionality
=======
 * @page rt_test_006_004 [6.4] Priority return verification
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * The functon is tested by waking up a thread then the semaphore
 * counter value is tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.4.1] A thread is created, it goes to wait on the semaphore.
 * - [5.4.2] The semaphore counter is increased by two, it is then
 *   tested to be one, the thread must have completed.
 * .
 */

static void test_005_004_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void test_005_004_execute(void) {

  /* [5.4.1] A thread is created, it goes to wait on the semaphore.*/
=======
 * - [6.4.1] Getting current thread priority P(0) and assigning to the
 *   threads A and B priorities +1 and +2.
 * - [6.4.2] Spawning threads A and B at priorities P(A) and P(B).
 * - [6.4.3] Locking the mutex M1 before thread A has a chance to lock
 *   it. The priority must not change because A has not yet reached
 *   chMtxLock(M1). the mutex is not locked.
 * - [6.4.4] Waiting 100mS, this makes thread A reach chMtxLock(M1) and
 *   get the mutex. This must boost the priority of the current thread
 *   at the same level of thread A.
 * - [6.4.5] Locking the mutex M2 before thread B has a chance to lock
 *   it. The priority must not change because B has not yet reached
 *   chMtxLock(M2). the mutex is not locked.
 * - [6.4.6] Waiting 100mS, this makes thread B reach chMtxLock(M2) and
 *   get the mutex. This must boost the priority of the current thread
 *   at the same level of thread B.
 * - [6.4.7] Unlocking M2, the priority should fall back to P(A).
 * - [6.4.8] Unlocking M1, the priority should fall back to P(0).
 * .
 */

static void rt_test_006_004_setup(void) {
  chMtxObjectInit(&m1);
  chMtxObjectInit(&m2);
}

static void rt_test_006_004_teardown(void) {
  test_wait_threads();
}

static void rt_test_006_004_execute(void) {
  tprio_t p, pa, pb;

  /* [6.4.1] Getting current thread priority P(0) and assigning to the
     threads A and B priorities +1 and +2.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+1, thread1, "A");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.4.2] The semaphore counter is increased by two, it is then
     tested to be one, the thread must have completed.*/
  test_set_step(2);
  {
    chSysLock();
    chSemAddCounterI(&sem1, 2);
    chSchRescheduleS();
    chSysUnlock();
    test_wait_threads();
    test_assert_lock(chSemGetCounterI(&sem1) == 1, "invalid counter");
    test_assert_sequence("A", "invalid sequence");
  }
}

static const testcase_t test_005_004 = {
  "Testing chSemAddCounterI() functionality",
  test_005_004_setup,
  NULL,
  test_005_004_execute
=======
  /* [6.4.2] Spawning threads A and B at priorities P(A) and P(B).*/
  test_set_step(2);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, pa, thread4A, "A");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, pb, thread4B, "B");
  }

  /* [6.4.3] Locking the mutex M1 before thread A has a chance to lock
     it. The priority must not change because A has not yet reached
     chMtxLock(M1). the mutex is not locked.*/
  test_set_step(3);
  {
    chMtxLock(&m1);
    test_assert(chThdGetPriorityX() == p, "wrong priority level");
  }

  /* [6.4.4] Waiting 100mS, this makes thread A reach chMtxLock(M1) and
     get the mutex. This must boost the priority of the current thread
     at the same level of thread A.*/
  test_set_step(4);
  {
    chThdSleepMilliseconds(100);
    test_assert(chThdGetPriorityX() == pa, "wrong priority level");
  }

  /* [6.4.5] Locking the mutex M2 before thread B has a chance to lock
     it. The priority must not change because B has not yet reached
     chMtxLock(M2). the mutex is not locked.*/
  test_set_step(5);
  {
    chMtxLock(&m2);
    test_assert(chThdGetPriorityX() == pa, "wrong priority level");
  }

  /* [6.4.6] Waiting 100mS, this makes thread B reach chMtxLock(M2) and
     get the mutex. This must boost the priority of the current thread
     at the same level of thread B.*/
  test_set_step(6);
  {
    chThdSleepMilliseconds(100);
    test_assert(chThdGetPriorityX() == pb, "wrong priority level");
  }

  /* [6.4.7] Unlocking M2, the priority should fall back to P(A).*/
  test_set_step(7);
  {
    chMtxUnlock(&m2);
    test_assert(chThdGetPriorityX() == pa, "wrong priority level");
  }

  /* [6.4.8] Unlocking M1, the priority should fall back to P(0).*/
  test_set_step(8);
  {
    chMtxUnlock(&m1);
    test_assert(chThdGetPriorityX() == p, "wrong priority level");
  }
}

static const testcase_t rt_test_006_004 = {
  "Priority return verification",
  rt_test_006_004_setup,
  rt_test_006_004_teardown,
  rt_test_006_004_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_005 [5.5] Testing chSemWaitSignal() functionality
=======
 * @page rt_test_006_005 [6.5] Repeated locks, non recursive scenario
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * This test case explicitly addresses the @p chSemWaitSignal()
 * function. A thread is created that performs a wait and a signal
 * operations. The tester thread is awakened from an atomic wait/signal
 * operation. The test expects that the semaphore wait function returns
 * the correct value in each of the above scenario and that the
 * semaphore structure status is correct after each operation.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.5.1] An higher priority thread is created that performs
 *   non-atomical wait and signal operations on a semaphore.
 * - [5.5.2] The function chSemSignalWait() is invoked by specifying
 *   the same semaphore for the wait and signal phases. The counter
 *   value must be one on exit.
 * - [5.5.3] The function chSemSignalWait() is invoked again by
 *   specifying the same semaphore for the wait and signal phases. The
 *   counter value must be one on exit.
 * .
 */

static void test_005_005_setup(void) {
  chSemObjectInit(&sem1, 0);
}

static void test_005_005_teardown(void) {
  test_wait_threads();
}

static void test_005_005_execute(void) {

  /* [5.5.1] An higher priority thread is created that performs
     non-atomical wait and signal operations on a semaphore.*/
=======
 * - [6.5.1] Getting current thread priority for later checks.
 * - [6.5.2] Locking the mutex first time, it must be possible because
 *   it is not owned.
 * - [6.5.3] Locking the mutex second time, it must fail because it is
 *   already owned.
 * - [6.5.4] Unlocking the mutex then it must not be owned anymore and
 *   the queue must be empty.
 * - [6.5.5] Testing that priority has not changed after operations.
 * - [6.5.6] Testing chMtxUnlockAll() behavior.
 * - [6.5.7] Testing that priority has not changed after operations.
 * .
 */

static void rt_test_006_005_setup(void) {
  chMtxObjectInit(&m1);
}

static void rt_test_006_005_execute(void) {
  bool b;
  tprio_t prio;

  /* [6.5.1] Getting current thread priority for later checks.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()+1, thread3, 0);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.5.2] The function chSemSignalWait() is invoked by specifying
     the same semaphore for the wait and signal phases. The counter
     value must be one on exit.*/
=======
  /* [6.5.2] Locking the mutex first time, it must be possible because
     it is not owned.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(2);
  {
    chSemSignalWait(&sem1, &sem1);
    test_assert(queue_isempty(&sem1.queue), "queue not empty");
    test_assert(sem1.cnt == 0, "counter not zero");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.5.3] The function chSemSignalWait() is invoked again by
     specifying the same semaphore for the wait and signal phases. The
     counter value must be one on exit.*/
  test_set_step(3);
  {
    chSemSignalWait(&sem1, &sem1);
    test_assert(queue_isempty(&sem1.queue), "queue not empty");
    test_assert(sem1.cnt == 0, "counter not zero");
  }
}

static const testcase_t test_005_005 = {
  "Testing chSemWaitSignal() functionality",
  test_005_005_setup,
  test_005_005_teardown,
  test_005_005_execute
=======
  /* [6.5.3] Locking the mutex second time, it must fail because it is
     already owned.*/
  test_set_step(3);
  {
    b = chMtxTryLock(&m1);
    test_assert(!b, "not locked");
  }

  /* [6.5.4] Unlocking the mutex then it must not be owned anymore and
     the queue must be empty.*/
  test_set_step(4);
  {
    chMtxUnlock(&m1);
    test_assert(m1.owner == NULL, "still owned");
    test_assert(queue_isempty(&m1.queue), "queue not empty");
  }

  /* [6.5.5] Testing that priority has not changed after operations.*/
  test_set_step(5);
  {
    test_assert(chThdGetPriorityX() == prio, "wrong priority level");
  }

  /* [6.5.6] Testing chMtxUnlockAll() behavior.*/
  test_set_step(6);
  {
    b = chMtxTryLock(&m1);
    test_assert(b, "already locked");
    b = chMtxTryLock(&m1);
    test_assert(!b, "not locked");

    chMtxUnlockAll();
    test_assert(m1.owner == NULL, "still owned");
    test_assert(queue_isempty(&m1.queue), "queue not empty");
  }

  /* [6.5.7] Testing that priority has not changed after operations.*/
  test_set_step(7);
  {
    test_assert(chThdGetPriorityX() == prio, "wrong priority level");
  }
}

static const testcase_t rt_test_006_005 = {
  "Repeated locks, non recursive scenario",
  rt_test_006_005_setup,
  NULL,
  rt_test_006_005_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @page test_005_006 [5.6] Testing Binary Semaphores special case
=======
 * @page rt_test_006_006 [6.6] Repeated locks using, recursive scenario
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
 *
 * <h2>Description</h2>
 * This test case tests the binary semaphores functionality. The test
 * both checks the binary semaphore status and the expected status of
 * the underlying counting semaphore.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * - [5.6.1] Creating a binary semaphore in "taken" state, the state is
 *   checked.
 * - [5.6.2] Resetting the binary semaphore in "taken" state, the state
 *   must not change.
 * - [5.6.3] Starting a signaler thread at a lower priority.
 * - [5.6.4] Waiting for the binary semaphore to be signaled, the
 *   semaphore is expected to be taken.
 * - [5.6.5] Signaling the binary semaphore, checking the binary
 *   semaphore state to be "not taken" and the underlying counter
 *   semaphore counter to be one.
 * - [5.6.6] Signaling the binary semaphore again, the internal state
 *   must not change from "not taken".
 * .
 */

static void test_005_006_teardown(void) {
  test_wait_threads();
}

static void test_005_006_execute(void) {
  binary_semaphore_t bsem;
  msg_t msg;

  /* [5.6.1] Creating a binary semaphore in "taken" state, the state is
     checked.*/
=======
 * - [6.6.1] Getting current thread priority for later checks.
 * - [6.6.2] Locking the mutex first time, it must be possible because
 *   it is not owned.
 * - [6.6.3] Locking the mutex second time, it must be possible because
 *   it is recursive.
 * - [6.6.4] Unlocking the mutex then it must be still owned because
 *   recursivity.
 * - [6.6.5] Unlocking the mutex then it must not be owned anymore and
 *   the queue must be empty.
 * - [6.6.6] Testing that priority has not changed after operations.
 * - [6.6.7] Testing consecutive chMtxTryLock()/chMtxTryLockS() calls
 *   and a final chMtxUnlockAllS().
 * - [6.6.8] Testing consecutive chMtxLock()/chMtxLockS() calls and a
 *   final chMtxUnlockAll().
 * - [6.6.9] Testing that priority has not changed after operations.
 * .
 */

static void rt_test_006_006_setup(void) {
  chMtxObjectInit(&m1);
}

static void rt_test_006_006_execute(void) {
  bool b;
  tprio_t prio;

  /* [6.6.1] Getting current thread priority for later checks.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(1);
  {
    chBSemObjectInit(&bsem, true);
    test_assert_lock(chBSemGetStateI(&bsem) == true, "not taken");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.6.2] Resetting the binary semaphore in "taken" state, the state
     must not change.*/
=======
  /* [6.6.2] Locking the mutex first time, it must be possible because
     it is not owned.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(2);
  {
    chBSemReset(&bsem, true);
    test_assert_lock(chBSemGetStateI(&bsem) == true, "not taken");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.6.3] Starting a signaler thread at a lower priority.*/
=======
  /* [6.6.3] Locking the mutex second time, it must be possible because
     it is recursive.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(3);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE,
                                   chThdGetPriorityX()-1, thread4, &bsem);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.6.4] Waiting for the binary semaphore to be signaled, the
     semaphore is expected to be taken.*/
=======
  /* [6.6.4] Unlocking the mutex then it must be still owned because
     recursivity.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(4);
  {
    msg = chBSemWait(&bsem);
    test_assert_lock(chBSemGetStateI(&bsem) == true, "not taken");
    test_assert(msg == MSG_OK, "unexpected message");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.6.5] Signaling the binary semaphore, checking the binary
     semaphore state to be "not taken" and the underlying counter
     semaphore counter to be one.*/
=======
  /* [6.6.5] Unlocking the mutex then it must not be owned anymore and
     the queue must be empty.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
  test_set_step(5);
  {
    chBSemSignal(&bsem);
    test_assert_lock(chBSemGetStateI(&bsem) ==false, "still taken");
    test_assert_lock(chSemGetCounterI(&bsem.sem) == 1, "unexpected counter");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
  /* [5.6.6] Signaling the binary semaphore again, the internal state
     must not change from "not taken".*/
  test_set_step(6);
  {
    chBSemSignal(&bsem);
    test_assert_lock(chBSemGetStateI(&bsem) == false, "taken");
    test_assert_lock(chSemGetCounterI(&bsem.sem) == 1, "unexpected counter");
  }
}

static const testcase_t test_005_006 = {
  "Testing Binary Semaphores special case",
  NULL,
  test_005_006_teardown,
  test_005_006_execute
};
=======
  /* [6.6.6] Testing that priority has not changed after operations.*/
  test_set_step(6);
  {
    test_assert(chThdGetPriorityX() == prio, "wrong priority level");
  }

  /* [6.6.7] Testing consecutive chMtxTryLock()/chMtxTryLockS() calls
     and a final chMtxUnlockAllS().*/
  test_set_step(7);
  {
    b = chMtxTryLock(&m1);
    test_assert(b, "already locked");
    chSysLock();
    b = chMtxTryLockS(&m1);
    chSysUnlock();
    test_assert(b, "already locked");
    test_assert(m1.cnt == 2, "invalid recursion counter");
    chSysLock();
    chMtxUnlockAllS();
    chSysUnlock();
    test_assert(m1.owner == NULL, "still owned");
    test_assert(queue_isempty(&m1.queue), "queue not empty");
    test_assert(m1.cnt == 0, "invalid recursion counter");
  }

  /* [6.6.8] Testing consecutive chMtxLock()/chMtxLockS() calls and a
     final chMtxUnlockAll().*/
  test_set_step(8);
  {
    chMtxLock(&m1);
    test_assert(m1.owner != NULL, "not owned");
    chSysLock();
    chMtxLockS(&m1);
    chSysUnlock();
    test_assert(m1.owner != NULL, "not owned");
    test_assert(m1.cnt == 2, "invalid recursion counter");
    chMtxUnlockAll();
    test_assert(m1.owner == NULL, "still owned");
    test_assert(queue_isempty(&m1.queue), "queue not empty");
    test_assert(m1.cnt == 0, "invalid recursion counter");
  }

  /* [6.6.9] Testing that priority has not changed after operations.*/
  test_set_step(9);
  {
    test_assert(chThdGetPriorityX() == prio, "wrong priority level");
  }
}

static const testcase_t rt_test_006_006 = {
  "Repeated locks using, recursive scenario",
  rt_test_006_006_setup,
  NULL,
  rt_test_006_006_execute
};
#endif /* CH_CFG_USE_MUTEXES_RECURSIVE */

#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
/**
 * @page rt_test_006_007 [6.7] Condition Variable signal test
 *
 * <h2>Description</h2>
 * Five threads take a mutex and then enter a conditional variable
 * queue, the tester thread then proceeds to signal the conditional
 * variable five times atomically.<br> The test expects the threads to
 * reach their goal in increasing priority order regardless of the
 * initial order.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_CONDVARS
 * .
 *
 * <h2>Test Steps</h2>
 * - [6.7.1] Starting the five threads with increasing priority, the
 *   threads will queue on the condition variable.
 * - [6.7.2] Atomically signaling the condition variable five times
 *   then waiting for the threads to terminate in priority order, the
 *   order is tested.
 * .
 */

static void rt_test_006_007_setup(void) {
  chCondObjectInit(&c1);
  chMtxObjectInit(&m1);
}

static void rt_test_006_007_execute(void) {

  /* [6.7.1] Starting the five threads with increasing priority, the
     threads will queue on the condition variable.*/
  test_set_step(1);
  {
    tprio_t prio = chThdGetPriorityX();
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, prio+1, thread6, "E");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, prio+2, thread6, "D");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, prio+3, thread6, "C");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, prio+4, thread6, "B");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, prio+5, thread6, "A");
  }

  /* [6.7.2] Atomically signaling the condition variable five times
     then waiting for the threads to terminate in priority order, the
     order is tested.*/
  test_set_step(2);
  {
    chSysLock();
    chCondSignalI(&c1);
    chCondSignalI(&c1);
    chCondSignalI(&c1);
    chCondSignalI(&c1);
    chCondSignalI(&c1);
    chSchRescheduleS();
    chSysUnlock();
    test_wait_threads();
    test_assert_sequence("ABCDE", "invalid sequence");
  }
}

static const testcase_t rt_test_006_007 = {
  "Condition Variable signal test",
  rt_test_006_007_setup,
  NULL,
  rt_test_006_007_execute
};
#endif /* CH_CFG_USE_CONDVARS */

#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
/**
 * @page rt_test_006_008 [6.8] Condition Variable broadcast test
 *
 * <h2>Description</h2>
 * Five threads take a mutex and then enter a conditional variable
 * queue, the tester thread then proceeds to broadcast the conditional
 * variable.<br> The test expects the threads to reach their goal in
 * increasing priority order regardless of the initial order.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_CONDVARS
 * .
 *
 * <h2>Test Steps</h2>
 * - [6.8.1] Starting the five threads with increasing priority, the
 *   threads will queue on the condition variable.
 * - [6.8.2] Broarcasting on the condition variable then waiting for
 *   the threads to terminate in priority order, the order is tested.
 * .
 */

static void rt_test_006_008_setup(void) {
  chCondObjectInit(&c1);
  chMtxObjectInit(&m1);
}

static void rt_test_006_008_execute(void) {

  /* [6.8.1] Starting the five threads with increasing priority, the
     threads will queue on the condition variable.*/
  test_set_step(1);
  {
    tprio_t prio = chThdGetPriorityX();
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, prio+1, thread6, "E");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, prio+2, thread6, "D");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, prio+3, thread6, "C");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, prio+4, thread6, "B");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, prio+5, thread6, "A");
  }

  /* [6.8.2] Broarcasting on the condition variable then waiting for
     the threads to terminate in priority order, the order is tested.*/
  test_set_step(2);
  {
    chCondBroadcast(&c1);
    test_wait_threads();
    test_assert_sequence("ABCDE", "invalid sequence");
  }
}

static const testcase_t rt_test_006_008 = {
  "Condition Variable broadcast test",
  rt_test_006_008_setup,
  NULL,
  rt_test_006_008_execute
};
#endif /* CH_CFG_USE_CONDVARS */

#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
/**
 * @page rt_test_006_009 [6.9] Condition Variable priority boost test
 *
 * <h2>Description</h2>
 * This test case verifies the priority boost of a thread waiting on a
 * conditional variable queue. It tests this very specific situation in
 * order to improve code coverage. The created threads perform the
 * following operations: TA{lock(M2), lock(M1), wait(C1), unlock(M1),
 * unlock(M2)}, TB{lock(M2), wait(C1), unlock(M2)}. TC{lock(M1),
 * unlock(M1)}.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_CONDVARS
 * .
 *
 * <h2>Test Steps</h2>
 * - [6.9.1] Reading current base priority.
 * - [6.9.2] Thread A is created at priority P(+1), it locks M2, locks
 *   M1 and goes to wait on C1.
 * - [6.9.3] Thread C is created at priority P(+2), it enqueues on M1
 *   and boosts TA priority at P(+2).
 * - [6.9.4] Thread B is created at priority P(+3), it enqueues on M2
 *   and boosts TA priority at P(+3).
 * - [6.9.5] Signaling C1: TA wakes up, unlocks M1 and priority goes to
 *   P(+2). TB locks M1, unlocks M1 and completes. TA unlocks M2 and
 *   priority goes to P(+1). TC waits on C1. TA completes.
 * - [6.9.6] Signaling C1: TC wakes up, unlocks M1 and completes.
 * - [6.9.7] Checking the order of operations.
 * .
 */

static void rt_test_006_009_setup(void) {
  chCondObjectInit(&c1);
  chMtxObjectInit(&m1);
  chMtxObjectInit(&m2);
}

static void rt_test_006_009_execute(void) {
  tprio_t prio;

  /* [6.9.1] Reading current base priority.*/
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
  }

  /* [6.9.2] Thread A is created at priority P(+1), it locks M2, locks
     M1 and goes to wait on C1.*/
  test_set_step(2);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, prio+1, thread8, "A");
  }

  /* [6.9.3] Thread C is created at priority P(+2), it enqueues on M1
     and boosts TA priority at P(+2).*/
  test_set_step(3);
  {
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, prio+2, thread6, "C");
  }

  /* [6.9.4] Thread B is created at priority P(+3), it enqueues on M2
     and boosts TA priority at P(+3).*/
  test_set_step(4);
  {
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, prio+3, thread9, "B");
  }

  /* [6.9.5] Signaling C1: TA wakes up, unlocks M1 and priority goes to
     P(+2). TB locks M1, unlocks M1 and completes. TA unlocks M2 and
     priority goes to P(+1). TC waits on C1. TA completes.*/
  test_set_step(5);
  {
    chCondSignal(&c1);
  }

  /* [6.9.6] Signaling C1: TC wakes up, unlocks M1 and completes.*/
  test_set_step(6);
  {
    chCondSignal(&c1);
  }

  /* [6.9.7] Checking the order of operations.*/
  test_set_step(7);
  {
    test_wait_threads();
    test_assert_sequence("ABC", "invalid sequence");
  }
}

static const testcase_t rt_test_006_009 = {
  "Condition Variable priority boost test",
  rt_test_006_009_setup,
  NULL,
  rt_test_006_009_execute
};
#endif /* CH_CFG_USE_CONDVARS */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_005.c
 * @brief   Counter and Binary Semaphores.
 */
const testcase_t * const test_sequence_005[] = {
  &test_005_001,
  &test_005_002,
  &test_005_003,
  &test_005_004,
  &test_005_005,
  &test_005_006,
  NULL
};

#endif /* CH_CFG_USE_SEMAPHORES */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_006_array[] = {
  &rt_test_006_001,
#if (CH_DBG_THREADS_PROFILING) || defined(__DOXYGEN__)
  &rt_test_006_002,
#endif
#if (CH_DBG_THREADS_PROFILING) || defined(__DOXYGEN__)
  &rt_test_006_003,
#endif
  &rt_test_006_004,
#if (!CH_CFG_USE_MUTEXES_RECURSIVE) || defined(__DOXYGEN__)
  &rt_test_006_005,
#endif
#if (CH_CFG_USE_MUTEXES_RECURSIVE) || defined(__DOXYGEN__)
  &rt_test_006_006,
#endif
#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
  &rt_test_006_007,
#endif
#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
  &rt_test_006_008,
#endif
#if (CH_CFG_USE_CONDVARS) || defined(__DOXYGEN__)
  &rt_test_006_009,
#endif
  NULL
};

/**
 * @brief   Mutexes, Condition Variables and Priority Inheritance.
 */
const testsequence_t rt_test_sequence_006 = {
  "Mutexes, Condition Variables and Priority Inheritance",
  rt_test_sequence_006_array
};

#endif /* CH_CFG_USE_MUTEXES */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_006.c
