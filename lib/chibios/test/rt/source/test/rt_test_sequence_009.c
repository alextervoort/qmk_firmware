/*
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c

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
 * @file    rt_test_sequence_009.c
 * @brief   Test Sequence 009 code.
 *
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * @page test_sequence_011 [11] Memory Heaps
=======
 * @page rt_test_sequence_009 [9] Dynamic threads
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
 *
 * File: @ref rt_test_sequence_009.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/RT functionalities related to memory
 * heaps.
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_HEAP
 * .
 *
 * <h2>Test Cases</h2>
 * - @subpage rt_test_009_001
 * - @subpage rt_test_009_002
 * .
 */

#if (CH_CFG_USE_HEAP) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#define ALLOC_SIZE 16
#define HEAP_SIZE (ALLOC_SIZE * 8)

memory_heap_t test_heap;

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * @page test_011_001 [11.1] Allocation and fragmentation
=======
 * @page rt_test_009_001 [9.1] Threads creation from Memory Heap
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
 *
 * <h2>Description</h2>
 * Series of allocations/deallocations are performed in carefully
 * designed sequences in order to stimulate all the possible code paths
 * inside the allocator. The test expects to find the heap back to the
 * initial status after each sequence.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * - [11.1.1] Testing initial conditions, the heap must not be
 *   fragmented and one free block present.
 * - [11.1.2] Trying to allocate an block bigger than available space,
 *   an error is expected.
 * - [11.1.3] Single block allocation using chHeapAlloc() then the
 *   block is freed using chHeapFree(), must not fail.
 * - [11.1.4] Using chHeapStatus() to assess the heap state. There must
 *   be at least one free block of sufficient size.
 * - [11.1.5] Allocating then freeing in the same order.
 * - [11.1.6] Allocating then freeing in reverse order.
 * - [11.1.7] Small fragments handling. Checking the behavior when
 *   allocating blocks with size not multiple of alignment unit.
 * - [11.1.8] Skipping a fragment, the first fragment in the list is
 *   too small so the allocator must pick the second one.
 * - [11.1.9] Allocating the whole available space.
 * - [11.1.10] Testing final conditions. The heap geometry must be the
 *   same than the one registered at beginning.
 * .
 */

static void test_011_001_setup(void) {
  chHeapObjectInit(&test_heap, test_buffer, sizeof(test_buffer));
}

static void test_011_001_execute(void) {
  void *p1, *p2, *p3;
  size_t n, sz;

  /* [11.1.1] Testing initial conditions, the heap must not be
     fragmented and one free block present.*/
=======
 * - [9.1.1] Getting base priority for threads.
 * - [9.1.2] Getting heap info before the test.
 * - [9.1.3] Creating thread 1, it is expected to succeed.
 * - [9.1.4] Creating thread 2, it is expected to succeed.
 * - [9.1.5] Creating thread 3, it is expected to fail.
 * - [9.1.6] Letting threads execute then checking the start order and
 *   freeing memory.
 * - [9.1.7] Getting heap info again for verification.
 * .
 */

static void rt_test_009_001_setup(void) {
  chHeapObjectInit(&heap1, test_buffer, sizeof test_buffer);
}

static void rt_test_009_001_execute(void) {
  size_t n1, total1, largest1;
  size_t n2, total2, largest2;
  tprio_t prio;

  /* [9.1.1] Getting base priority for threads.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(1);
  {
    test_assert(chHeapStatus(&test_heap, &sz, NULL) == 1, "heap fragmented");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.1.2] Trying to allocate an block bigger than available space,
     an error is expected.*/
=======
  /* [9.1.2] Getting heap info before the test.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(2);
  {
    p1 = chHeapAlloc(&test_heap, sizeof test_buffer * 2);
    test_assert(p1 == NULL, "allocation not failed");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.1.3] Single block allocation using chHeapAlloc() then the
     block is freed using chHeapFree(), must not fail.*/
=======
  /* [9.1.3] Creating thread 1, it is expected to succeed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(3);
  {
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    test_assert(p1 != NULL, "allocation failed");
    chHeapFree(p1);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.1.4] Using chHeapStatus() to assess the heap state. There must
     be at least one free block of sufficient size.*/
=======
  /* [9.1.4] Creating thread 2, it is expected to succeed.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(4);
  {
    size_t total_size, largest_size;

    n = chHeapStatus(&test_heap, &total_size, &largest_size);
    test_assert(n == 1, "missing free block");
    test_assert(total_size >= ALLOC_SIZE, "unexpected heap state");
    test_assert(total_size == largest_size, "unexpected heap state");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.1.5] Allocating then freeing in the same order.*/
  test_set_step(5);
  {
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    p2 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    p3 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    chHeapFree(p1);                                 /* Does not merge.*/
    chHeapFree(p2);                                 /* Merges backward.*/
    chHeapFree(p3);                                 /* Merges both sides.*/
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
  }

  /* [11.1.6] Allocating then freeing in reverse order.*/
=======
  /* [9.1.5] Creating thread 3, it is expected to fail.*/
  test_set_step(5);
  {
    threads[2] = chThdCreateFromHeap(&heap1,
                                     THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE * 32),
                                     "dyn3",
                                     prio-3, dyn_thread1, "C");
    test_assert(threads[2] == NULL, "thread creation not failed");
  }

  /* [9.1.6] Letting threads execute then checking the start order and
     freeing memory.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(6);
  {
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    p2 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    p3 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    chHeapFree(p3);                                 /* Merges forward.*/
    chHeapFree(p2);                                 /* Merges forward.*/
    chHeapFree(p1);                                 /* Merges forward.*/
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.1.7] Small fragments handling. Checking the behavior when
     allocating blocks with size not multiple of alignment unit.*/
=======
  /* [9.1.7] Getting heap info again for verification.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(7);
  {
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE + 1);
    p2 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    chHeapFree(p1);
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 2, "invalid state");
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    /* Note, the first situation happens when the alignment size is smaller
       than the header size, the second in the other cases.*/
    test_assert((chHeapStatus(&test_heap, &n, NULL) == 1) ||
                (chHeapStatus(&test_heap, &n, NULL) == 2), "heap fragmented");
    chHeapFree(p2);
    chHeapFree(p1);
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
  }

  /* [11.1.8] Skipping a fragment, the first fragment in the list is
     too small so the allocator must pick the second one.*/
  test_set_step(8);
  {
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    p2 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    chHeapFree(p1);
    test_assert( chHeapStatus(&test_heap, &n, NULL) == 2, "invalid state");
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE * 2); /* Skips first fragment.*/
    chHeapFree(p1);
    chHeapFree(p2);
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
  }

  /* [11.1.9] Allocating the whole available space.*/
  test_set_step(9);
  {
    (void)chHeapStatus(&test_heap, &n, NULL);
    p1 = chHeapAlloc(&test_heap, n);
    test_assert(p1 != NULL, "allocation failed");
    test_assert(chHeapStatus(&test_heap, NULL, NULL) == 0, "not empty");
    chHeapFree(p1);
  }

  /* [11.1.10] Testing final conditions. The heap geometry must be the
     same than the one registered at beginning.*/
  test_set_step(10);
  {
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
    test_assert(n == sz, "size changed");
  }
}

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
static const testcase_t test_011_001 = {
  "Allocation and fragmentation",
  test_011_001_setup,
=======
static const testcase_t rt_test_009_001 = {
  "Threads creation from Memory Heap",
  rt_test_009_001_setup,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  NULL,
  rt_test_009_001_execute
};

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * @page test_011_002 [11.2] Default Heap
=======
 * @page rt_test_009_002 [9.2] Threads creation from Memory Pool
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
 *
 * <h2>Description</h2>
 * The default heap is pre-allocated in the system. We test base
 * functionality.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * - [11.2.1] Single block allocation using chHeapAlloc() then the
 *   block is freed using chHeapFree(), must not fail.
 * - [11.2.2] Testing allocation failure.
 * .
 */

static void test_011_002_execute(void) {
  void *p1;
  size_t total_size, largest_size;

  /* [11.2.1] Single block allocation using chHeapAlloc() then the
     block is freed using chHeapFree(), must not fail.*/
=======
 * - [9.2.1] Adding four working areas to the pool.
 * - [9.2.2] Getting base priority for threads.
 * - [9.2.3] Creating the five threads.
 * - [9.2.4] Testing that only the fifth thread creation failed.
 * - [9.2.5] Letting them run, free the memory then checking the
 *   execution sequence.
 * - [9.2.6] Testing that the pool contains four elements again.
 * .
 */

static void rt_test_009_002_setup(void) {
  chPoolObjectInit(&mp1, THD_WORKING_AREA_SIZE(THREADS_STACK_SIZE), NULL);
}

static void rt_test_009_002_execute(void) {
  unsigned i;
  tprio_t prio;

  /* [9.2.1] Adding four working areas to the pool.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  test_set_step(1);
  {
    (void)chHeapStatus(NULL, &total_size, &largest_size);
    p1 = chHeapAlloc(&test_heap, ALLOC_SIZE);
    test_assert(p1 != NULL, "allocation failed");
    chHeapFree(p1);
  }

<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
  /* [11.2.2] Testing allocation failure.*/
  test_set_step(2);
  {
    p1 = chHeapAlloc(NULL, (size_t)-256);
    test_assert(p1 == NULL, "allocation not failed");
  }
}

static const testcase_t test_011_002 = {
  "Default Heap",
  NULL,
=======
  /* [9.2.2] Getting base priority for threads.*/
  test_set_step(2);
  {
    prio = chThdGetPriorityX();
  }

  /* [9.2.3] Creating the five threads.*/
  test_set_step(3);
  {
    threads[0] = chThdCreateFromMemoryPool(&mp1, "dyn1", prio-1, dyn_thread1, "A");
    threads[1] = chThdCreateFromMemoryPool(&mp1, "dyn2", prio-2, dyn_thread1, "B");
    threads[2] = chThdCreateFromMemoryPool(&mp1, "dyn3", prio-3, dyn_thread1, "C");
    threads[3] = chThdCreateFromMemoryPool(&mp1, "dyn4", prio-4, dyn_thread1, "D");
    threads[4] = chThdCreateFromMemoryPool(&mp1, "dyn5", prio-5, dyn_thread1, "E");
  }

  /* [9.2.4] Testing that only the fifth thread creation failed.*/
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

  /* [9.2.5] Letting them run, free the memory then checking the
     execution sequence.*/
  test_set_step(5);
  {
    test_wait_threads();
    test_assert_sequence("ABCD", "invalid sequence");
  }

  /* [9.2.6] Testing that the pool contains four elements again.*/
  test_set_step(6);
  {
    for (i = 0; i < 4; i++)
      test_assert(chPoolAlloc(&mp1) != NULL, "pool list empty");
    test_assert(chPoolAlloc(&mp1) == NULL, "pool list not empty");
  }
}

static const testcase_t rt_test_009_002 = {
  "Threads creation from Memory Pool",
  rt_test_009_002_setup,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
  NULL,
  rt_test_009_002_execute
};

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/rt/source/test/test_sequence_011.c
 * @brief   Memory Heaps.
 */
const testcase_t * const test_sequence_011[] = {
  &test_011_001,
  &test_011_002,
  NULL
};

#endif /* CH_CFG_USE_HEAP */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const rt_test_sequence_009_array[] = {
#if (CH_CFG_USE_HEAP) || defined(__DOXYGEN__)
  &rt_test_009_001,
#endif
#if (CH_CFG_USE_MEMPOOLS) || defined(__DOXYGEN__)
  &rt_test_009_002,
#endif
  NULL
};

/**
 * @brief   Dynamic threads.
 */
const testsequence_t rt_test_sequence_009 = {
  "Dynamic threads",
  rt_test_sequence_009_array
};

#endif /* CH_CFG_USE_DYNAMIC */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/rt/source/test/rt_test_sequence_009.c
