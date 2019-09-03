/*
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c

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
 * @file    oslib_test_sequence_002.c
 * @brief   Test Sequence 002 code.
 *
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * @page test_sequence_005 [5] Mailboxes
=======
 * @page oslib_test_sequence_002 [2] Memory Pools
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
 *
 * File: @ref oslib_test_sequence_002.c
 *
 * <h2>Description</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * This sequence tests the ChibiOS/NIL functionalities related to
 * mailboxes.
=======
 * This sequence tests the ChibiOS library functionalities related to
 * memory pools.
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MAILBOXES
 * .
 *
 * <h2>Test Cases</h2>
 * - @subpage oslib_test_002_001
 * - @subpage oslib_test_002_002
 * - @subpage oslib_test_002_003
 * .
 */

#if (CH_CFG_USE_MAILBOXES) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#define ALLOWED_DELAY MS2ST(5)
#define MB_SIZE 4

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
static msg_t mb_buffer[MB_SIZE];
static MAILBOX_DECL(mb1, mb_buffer, MB_SIZE);
=======
static uint32_t objects[MEMORY_POOL_SIZE];
static MEMORYPOOL_DECL(mp1, sizeof (uint32_t), PORT_NATURAL_ALIGN, NULL);

#if CH_CFG_USE_SEMAPHORES
static GUARDEDMEMORYPOOL_DECL(gmp1, sizeof (uint32_t), PORT_NATURAL_ALIGN);
#endif

static void *null_provider(size_t size, unsigned align) {

  (void)size;
  (void)align;

  return NULL;
}
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * @page test_005_001 [5.1] Mailbox normal API, non-blocking tests
=======
 * @page oslib_test_002_001 [2.1] Loading and emptying a memory pool
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The mailbox normal API is tested without triggering blocking
 * conditions.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * - [5.1.1] Testing the mailbox size.
 * - [5.1.2] Resetting the mailbox, conditions are checked, no errors
 *   expected.
 * - [5.1.3] Testing the behavior of API when the mailbox is in reset
 *   state then return in active state.
 * - [5.1.4] Filling the mailbox using chMBPost() and chMBPostAhead()
 *   once, no errors expected.
 * - [5.1.5] Testing intermediate conditions. Data pointers must be
 *   aligned, semaphore counters are checked.
 * - [5.1.6] Emptying the mailbox using chMBFetch(), no errors
 *   expected.
 * - [5.1.7] Posting and then fetching one more message, no errors
 *   expected.
 * - [5.1.8] Testing final conditions. Data pointers must be aligned to
 *   buffer start, semaphore counters are checked.
 * .
 */

static void test_005_001_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void test_005_001_teardown(void) {
  chMBReset(&mb1);
}

static void test_005_001_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [5.1.1] Testing the mailbox size.*/
=======
 * - [2.1.1] Adding the objects to the pool using chPoolLoadArray().
 * - [2.1.2] Emptying the pool using chPoolAlloc().
 * - [2.1.3] Now must be empty.
 * - [2.1.4] Adding the objects to the pool using chPoolFree().
 * - [2.1.5] Emptying the pool using chPoolAlloc() again.
 * - [2.1.6] Now must be empty again.
 * - [2.1.7] Covering the case where a provider is unable to return
 *   more memory.
 * .
 */

static void oslib_test_002_001_setup(void) {
  chPoolObjectInit(&mp1, sizeof (uint32_t), NULL);
}

static void oslib_test_002_001_execute(void) {
  unsigned i;

  /* [2.1.1] Adding the objects to the pool using chPoolLoadArray().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(1);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "wrong size");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.2] Resetting the mailbox, conditions are checked, no errors
     expected.*/
=======
  /* [2.1.2] Emptying the pool using chPoolAlloc().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(2);
  {
    chMBReset(&mb1);
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "not empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == 0, "still full");
    test_assert_lock(mb1.buffer == mb1.wrptr, "write pointer not aligned to base");
    test_assert_lock(mb1.buffer == mb1.rdptr, "read pointer not aligned to base");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.3] Testing the behavior of API when the mailbox is in reset
     state then return in active state.*/
=======
  /* [2.1.3] Now must be empty.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(3);
  {
    msg1 = chMBPost(&mb1, (msg_t)0, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    msg1 = chMBPostAhead(&mb1, (msg_t)0, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    msg1 = chMBFetch(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_RESET, "not in reset state");
    chMBResumeX(&mb1);
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.4] Filling the mailbox using chMBPost() and chMBPostAhead()
     once, no errors expected.*/
=======
  /* [2.1.4] Adding the objects to the pool using chPoolFree().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(4);
  {
    for (i = 0; i < MB_SIZE - 1; i++) {
      msg1 = chMBPost(&mb1, 'B' + i, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
    }
    msg1 = chMBPostAhead(&mb1, 'A', TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.5] Testing intermediate conditions. Data pointers must be
     aligned, semaphore counters are checked.*/
=======
  /* [2.1.5] Emptying the pool using chPoolAlloc() again.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(5);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == 0, "still empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == MB_SIZE, "not full");
    test_assert_lock(mb1.rdptr == mb1.wrptr, "pointers not aligned");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.6] Emptying the mailbox using chMBFetch(), no errors
     expected.*/
=======
  /* [2.1.6] Now must be empty again.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(6);
  {
    for (i = 0; i < MB_SIZE; i++) {
      msg1 = chMBFetch(&mb1, &msg2, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
      test_emit_token(msg2);
    }
    test_assert_sequence("ABCD", "wrong get sequence");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.1.7] Posting and then fetching one more message, no errors
     expected.*/
=======
  /* [2.1.7] Covering the case where a provider is unable to return
     more memory.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(7);
  {
    msg1 = chMBPost(&mb1, 'B' + i, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
    msg1 = chMBFetch(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

  /* [5.1.8] Testing final conditions. Data pointers must be aligned to
     buffer start, semaphore counters are checked.*/
  test_set_step(8);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "not empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == 0, "still full");
    test_assert(mb1.buffer == mb1.wrptr, "write pointer not aligned to base");
    test_assert(mb1.buffer == mb1.rdptr, "read pointer not aligned to base");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
static const testcase_t test_005_001 = {
  "Mailbox normal API, non-blocking tests",
  test_005_001_setup,
  test_005_001_teardown,
  test_005_001_execute
=======
static const testcase_t oslib_test_002_001 = {
  "Loading and emptying a memory pool",
  oslib_test_002_001_setup,
  NULL,
  oslib_test_002_001_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
};

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * @page test_005_002 [5.2] Mailbox I-Class API, non-blocking tests
=======
 * @page oslib_test_002_002 [2.2] Loading and emptying a guarded memory pool without waiting
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The mailbox I-Class API is tested without triggering blocking
 * conditions.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * - [5.2.1] Testing the mailbox size.
 * - [5.2.2] Resetting the mailbox, conditions are checked, no errors
 *   expected.
 * - [5.2.3] Filling the mailbox using chMBPostI() and chMBPostAheadI()
 *   once, no errors expected.
 * - [5.2.4] Testing intermediate conditions. Data pointers must be
 *   aligned, semaphore counters are checked.
 * - [5.2.5] Emptying the mailbox using chMBFetchI(), no errors
 *   expected.
 * - [5.2.6] Posting and then fetching one more message, no errors
 *   expected.
 * - [5.2.7] Testing final conditions. Data pointers must be aligned to
 *   buffer start, semaphore counters are checked.
 * .
 */

static void test_005_002_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void test_005_002_teardown(void) {
  chMBReset(&mb1);
}

static void test_005_002_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [5.2.1] Testing the mailbox size.*/
=======
 * - [2.2.1] Adding the objects to the pool using
 *   chGuardedPoolLoadArray().
 * - [2.2.2] Emptying the pool using chGuardedPoolAllocTimeout().
 * - [2.2.3] Now must be empty.
 * - [2.2.4] Adding the objects to the pool using chGuardedPoolFree().
 * - [2.2.5] Emptying the pool using chGuardedPoolAllocTimeout() again.
 * - [2.2.6] Now must be empty again.
 * .
 */

static void oslib_test_002_002_setup(void) {
  chGuardedPoolObjectInit(&gmp1, sizeof (uint32_t));
}

static void oslib_test_002_002_execute(void) {
  unsigned i;

  /* [2.2.1] Adding the objects to the pool using
     chGuardedPoolLoadArray().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(1);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "wrong size");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.2.2] Resetting the mailbox, conditions are checked, no errors
     expected.*/
=======
  /* [2.2.2] Emptying the pool using chGuardedPoolAllocTimeout().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(2);
  {
    chSysLock();
    chMBResetI(&mb1);
    chSysUnlock();
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "not empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == 0, "still full");
    test_assert_lock(mb1.buffer == mb1.wrptr, "write pointer not aligned to base");
    test_assert_lock(mb1.buffer == mb1.rdptr, "read pointer not aligned to base");
    chMBResumeX(&mb1);
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.2.3] Filling the mailbox using chMBPostI() and chMBPostAheadI()
     once, no errors expected.*/
=======
  /* [2.2.3] Now must be empty.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(3);
  {
    for (i = 0; i < MB_SIZE - 1; i++) {
      chSysLock();
      msg1 = chMBPostI(&mb1, 'B' + i);
      chSysUnlock();
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
    }
    chSysLock();
    msg1 = chMBPostAheadI(&mb1, 'A');
    chSysUnlock();
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.2.4] Testing intermediate conditions. Data pointers must be
     aligned, semaphore counters are checked.*/
=======
  /* [2.2.4] Adding the objects to the pool using
     chGuardedPoolFree().*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(4);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == 0, "still empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == MB_SIZE, "not full");
    test_assert_lock(mb1.rdptr == mb1.wrptr, "pointers not aligned");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.2.5] Emptying the mailbox using chMBFetchI(), no errors
     expected.*/
=======
  /* [2.2.5] Emptying the pool using chGuardedPoolAllocTimeout()
     again.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(5);
  {
    for (i = 0; i < MB_SIZE; i++) {
      chSysLock();
      msg1 = chMBFetchI(&mb1, &msg2);
      chSysUnlock();
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
      test_emit_token(msg2);
    }
    test_assert_sequence("ABCD", "wrong get sequence");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
  /* [5.2.6] Posting and then fetching one more message, no errors
     expected.*/
=======
  /* [2.2.6] Now must be empty again.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
  test_set_step(6);
  {
    msg1 = chMBPost(&mb1, 'B' + i, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
    msg1 = chMBFetch(&mb1, &msg2, TIME_INFINITE);
    test_assert(msg1 == MSG_OK, "wrong wake-up message");
  }

  /* [5.2.7] Testing final conditions. Data pointers must be aligned to
     buffer start, semaphore counters are checked.*/
  test_set_step(7);
  {
    test_assert_lock(chMBGetFreeCountI(&mb1) == MB_SIZE, "not empty");
    test_assert_lock(chMBGetUsedCountI(&mb1) == 0, "still full");
    test_assert(mb1.buffer == mb1.wrptr, "write pointer not aligned to base");
    test_assert(mb1.buffer == mb1.rdptr, "read pointer not aligned to base");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
static const testcase_t test_005_002 = {
  "Mailbox I-Class API, non-blocking tests",
  test_005_002_setup,
  test_005_002_teardown,
  test_005_002_execute
=======
static const testcase_t oslib_test_002_002 = {
  "Loading and emptying a guarded memory pool without waiting",
  oslib_test_002_002_setup,
  NULL,
  oslib_test_002_002_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
};

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * @page test_005_003 [5.3] Mailbox timeouts
=======
 * @page oslib_test_002_003 [2.3] Guarded Memory Pools timeout
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
 *
 * <h2>Description</h2>
 * The mailbox API is tested for timeouts.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * - [5.3.1] Filling the mailbox.
 * - [5.3.2] Testing chMBPost(), chMBPostI(), chMBPostAhead() and
 *   chMBPostAheadI() timeout.
 * - [5.3.3] Resetting the mailbox.
 * - [5.3.4] Testing chMBFetch() and chMBFetchI() timeout.
 * .
 */

static void test_005_003_setup(void) {
  chMBObjectInit(&mb1, mb_buffer, MB_SIZE);
}

static void test_005_003_teardown(void) {
  chMBReset(&mb1);
}

static void test_005_003_execute(void) {
  msg_t msg1, msg2;
  unsigned i;

  /* [5.3.1] Filling the mailbox.*/
  test_set_step(1);
  {
    for (i = 0; i < MB_SIZE; i++) {
      msg1 = chMBPost(&mb1, 'B' + i, TIME_INFINITE);
      test_assert(msg1 == MSG_OK, "wrong wake-up message");
    }
  }

  /* [5.3.2] Testing chMBPost(), chMBPostI(), chMBPostAhead() and
     chMBPostAheadI() timeout.*/
  test_set_step(2);
  {
    msg1 = chMBPost(&mb1, 'X', 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBPostI(&mb1, 'X');
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    msg1 = chMBPostAhead(&mb1, 'X', 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBPostAheadI(&mb1, 'X');
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
  }

  /* [5.3.3] Resetting the mailbox.*/
  test_set_step(3);
  {
    chMBReset(&mb1);;
    chMBResumeX(&mb1);
  }

  /* [5.3.4] Testing chMBFetch() and chMBFetchI() timeout.*/
  test_set_step(4);
  {
    msg1 = chMBFetch(&mb1, &msg2, 1);
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
    chSysLock();
    msg1 = chMBFetchI(&mb1, &msg2);
    chSysUnlock();
    test_assert(msg1 == MSG_TIMEOUT, "wrong wake-up message");
  }
}

static const testcase_t test_005_003 = {
  "Mailbox timeouts",
  test_005_003_setup,
  test_005_003_teardown,
  test_005_003_execute
=======
 * - [2.3.1] Trying to allocate with 100mS timeout, must fail because
 *   the pool is empty.
 * .
 */

static void oslib_test_002_003_setup(void) {
  chGuardedPoolObjectInit(&gmp1, sizeof (uint32_t));
}

static void oslib_test_002_003_execute(void) {

  /* [2.3.1] Trying to allocate with 100mS timeout, must fail because
     the pool is empty.*/
  test_set_step(1);
  {
    test_assert(chGuardedPoolAllocTimeout(&gmp1, TIME_MS2I(100)) == NULL, "list not empty");
  }
}

static const testcase_t oslib_test_002_003 = {
  "Guarded Memory Pools timeout",
  oslib_test_002_003_setup,
  NULL,
  oslib_test_002_003_execute
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_005.c
 * @brief   Mailboxes.
 */
const testcase_t * const test_sequence_005[] = {
  &test_005_001,
  &test_005_002,
  &test_005_003,
  NULL
};

#endif /* CH_CFG_USE_MAILBOXES */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const oslib_test_sequence_002_array[] = {
  &oslib_test_002_001,
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &oslib_test_002_002,
#endif
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &oslib_test_002_003,
#endif
  NULL
};

/**
 * @brief   Memory Pools.
 */
const testsequence_t oslib_test_sequence_002 = {
  "Memory Pools",
  oslib_test_sequence_002_array
};

#endif /* CH_CFG_USE_MEMPOOLS */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_002.c
