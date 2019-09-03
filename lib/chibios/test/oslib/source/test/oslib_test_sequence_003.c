/*
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
    ChibiOS - Copyright (C) 2006..2017 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c

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
 * @file    oslib_test_sequence_003.c
 * @brief   Test Sequence 003 code.
 *
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * @page test_sequence_006 [6] Memory Pools
=======
 * @page oslib_test_sequence_003 [3] Memory Heaps
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
 *
 * File: @ref oslib_test_sequence_003.c
 *
 * <h2>Description</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * This sequence tests the ChibiOS/NIL functionalities related to
 * memory pools.
=======
 * This sequence tests the ChibiOS library functionalities related to
 * memory heaps.
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
 *
 * <h2>Conditions</h2>
 * This sequence is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MEMPOOLS
 * .
 *
 * <h2>Test Cases</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * - @subpage test_006_001
 * - @subpage test_006_002
 * - @subpage test_006_003
=======
 * - @subpage oslib_test_003_001
 * - @subpage oslib_test_003_002
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
 * .
 */

#if (CH_CFG_USE_MEMPOOLS) || defined(__DOXYGEN__)

/****************************************************************************
 * Shared code.
 ****************************************************************************/

#define MEMORY_POOL_SIZE 4

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
static uint32_t objects[MEMORY_POOL_SIZE];
static MEMORYPOOL_DECL(mp1, sizeof (uint32_t), NULL);

#if CH_CFG_USE_SEMAPHORES
static GUARDEDMEMORYPOOL_DECL(gmp1, sizeof (uint32_t));
#endif

static void *null_provider(size_t size, unsigned align) {

  (void)size;
  (void)align;

  return NULL;
}
=======
static memory_heap_t test_heap;
static uint8_t test_heap_buffer[HEAP_SIZE];
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * @page test_006_001 [6.1] Loading and emptying a memory pool
=======
 * @page oslib_test_003_001 [3.1] Allocation and fragmentation
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The memory pool functionality is tested by loading and emptying it,
 * all conditions are tested.
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * - [6.1.1] Adding the objects to the pool using chPoolLoadArray().
 * - [6.1.2] Emptying the pool using chPoolAlloc().
 * - [6.1.3] Now must be empty.
 * - [6.1.4] Adding the objects to the pool using chPoolFree().
 * - [6.1.5] Emptying the pool using chPoolAlloc() again.
 * - [6.1.6] Now must be empty again.
 * - [6.1.7] Covering the case where a provider is unable to return
 *   more memory.
 * .
 */

static void test_006_001_setup(void) {
  chPoolObjectInit(&mp1, sizeof (uint32_t), NULL);
}

static void test_006_001_execute(void) {
  unsigned i;

  /* [6.1.1] Adding the objects to the pool using chPoolLoadArray().*/
=======
 * - [3.1.1] Testing initial conditions, the heap must not be
 *   fragmented and one free block present.
 * - [3.1.2] Trying to allocate an block bigger than available space,
 *   an error is expected.
 * - [3.1.3] Single block allocation using chHeapAlloc() then the block
 *   is freed using chHeapFree(), must not fail.
 * - [3.1.4] Using chHeapStatus() to assess the heap state. There must
 *   be at least one free block of sufficient size.
 * - [3.1.5] Allocating then freeing in the same order.
 * - [3.1.6] Allocating then freeing in reverse order.
 * - [3.1.7] Small fragments handling. Checking the behavior when
 *   allocating blocks with size not multiple of alignment unit.
 * - [3.1.8] Skipping a fragment, the first fragment in the list is too
 *   small so the allocator must pick the second one.
 * - [3.1.9] Allocating the whole available space.
 * - [3.1.10] Testing final conditions. The heap geometry must be the
 *   same than the one registered at beginning.
 * .
 */

static void oslib_test_003_001_setup(void) {
  chHeapObjectInit(&test_heap, test_heap_buffer, sizeof(test_heap_buffer));
}

static void oslib_test_003_001_execute(void) {
  void *p1, *p2, *p3;
  size_t n, sz;

  /* [3.1.1] Testing initial conditions, the heap must not be
     fragmented and one free block present.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(1);
  {
    chPoolLoadArray(&mp1, objects, MEMORY_POOL_SIZE);
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.1.2] Emptying the pool using chPoolAlloc().*/
  test_set_step(2);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      test_assert(chPoolAlloc(&mp1) != NULL, "list empty");
  }

  /* [6.1.3] Now must be empty.*/
=======
  /* [3.1.2] Trying to allocate an block bigger than available space,
     an error is expected.*/
  test_set_step(2);
  {
    p1 = chHeapAlloc(&test_heap, sizeof test_heap_buffer * 2);
    test_assert(p1 == NULL, "allocation not failed");
  }

  /* [3.1.3] Single block allocation using chHeapAlloc() then the block
     is freed using chHeapFree(), must not fail.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(3);
  {
    test_assert(chPoolAlloc(&mp1) == NULL, "list not empty");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.1.4] Adding the objects to the pool using chPoolFree().*/
=======
  /* [3.1.4] Using chHeapStatus() to assess the heap state. There must
     be at least one free block of sufficient size.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(4);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      chPoolFree(&mp1, &objects[i]);
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.1.5] Emptying the pool using chPoolAlloc() again.*/
=======
  /* [3.1.5] Allocating then freeing in the same order.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(5);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      test_assert(chPoolAlloc(&mp1) != NULL, "list empty");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.1.6] Now must be empty again.*/
=======
  /* [3.1.6] Allocating then freeing in reverse order.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(6);
  {
    test_assert(chPoolAlloc(&mp1) == NULL, "list not empty");
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.1.7] Covering the case where a provider is unable to return
     more memory.*/
  test_set_step(7);
  {
    chPoolObjectInit(&mp1, sizeof (uint32_t), null_provider);
    test_assert(chPoolAlloc(&mp1) == NULL, "provider returned memory");
  }
}

static const testcase_t test_006_001 = {
  "Loading and emptying a memory pool",
  test_006_001_setup,
=======
  /* [3.1.7] Small fragments handling. Checking the behavior when
     allocating blocks with size not multiple of alignment unit.*/
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

  /* [3.1.8] Skipping a fragment, the first fragment in the list is too
     small so the allocator must pick the second one.*/
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

  /* [3.1.9] Allocating the whole available space.*/
  test_set_step(9);
  {
    (void)chHeapStatus(&test_heap, &n, NULL);
    p1 = chHeapAlloc(&test_heap, n);
    test_assert(p1 != NULL, "allocation failed");
    test_assert(chHeapStatus(&test_heap, NULL, NULL) == 0, "not empty");
    chHeapFree(p1);
  }

  /* [3.1.10] Testing final conditions. The heap geometry must be the
     same than the one registered at beginning.*/
  test_set_step(10);
  {
    test_assert(chHeapStatus(&test_heap, &n, NULL) == 1, "heap fragmented");
    test_assert(n == sz, "size changed");
  }
}

static const testcase_t oslib_test_003_001 = {
  "Allocation and fragmentation",
  oslib_test_003_001_setup,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  NULL,
  oslib_test_003_001_execute
};

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * @page test_006_002 [6.2] Loading and emptying a guarded memory pool without waiting
=======
 * @page oslib_test_003_002 [3.2] Default Heap
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
 *
 * <h2>Description</h2>
 * The memory pool functionality is tested by loading and emptying it,
 * all conditions are tested.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Steps</h2>
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * - [6.2.1] Adding the objects to the pool using
 *   chGuardedPoolLoadArray().
 * - [6.2.2] Emptying the pool using chGuardedPoolAllocTimeout().
 * - [6.2.3] Now must be empty.
 * - [6.2.4] Adding the objects to the pool using chGuardedPoolFree().
 * - [6.2.5] Emptying the pool using chGuardedPoolAllocTimeout() again.
 * - [6.2.6] Now must be empty again.
 * .
 */

static void test_006_002_setup(void) {
  chGuardedPoolObjectInit(&gmp1, sizeof (uint32_t));
}

static void test_006_002_execute(void) {
  unsigned i;

  /* [6.2.1] Adding the objects to the pool using
     chGuardedPoolLoadArray().*/
=======
 * - [3.2.1] Single block allocation using chHeapAlloc() then the block
 *   is freed using chHeapFree(), must not fail.
 * - [3.2.2] Testing allocation failure.
 * .
 */

static void oslib_test_003_002_execute(void) {
  void *p1;
  size_t total_size, largest_size;

  /* [3.2.1] Single block allocation using chHeapAlloc() then the block
     is freed using chHeapFree(), must not fail.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(1);
  {
    chGuardedPoolLoadArray(&gmp1, objects, MEMORY_POOL_SIZE);
  }

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
  /* [6.2.2] Emptying the pool using chGuardedPoolAllocTimeout().*/
=======
  /* [3.2.2] Testing allocation failure.*/
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  test_set_step(2);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      test_assert(chGuardedPoolAllocTimeout(&gmp1, TIME_IMMEDIATE) != NULL, "list empty");
  }

  /* [6.2.3] Now must be empty.*/
  test_set_step(3);
  {
    test_assert(chGuardedPoolAllocTimeout(&gmp1, TIME_IMMEDIATE) == NULL, "list not empty");
  }

  /* [6.2.4] Adding the objects to the pool using
     chGuardedPoolFree().*/
  test_set_step(4);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      chGuardedPoolFree(&gmp1, &objects[i]);
  }

  /* [6.2.5] Emptying the pool using chGuardedPoolAllocTimeout()
     again.*/
  test_set_step(5);
  {
    for (i = 0; i < MEMORY_POOL_SIZE; i++)
      test_assert(chGuardedPoolAllocTimeout(&gmp1, TIME_IMMEDIATE) != NULL, "list empty");
  }

  /* [6.2.6] Now must be empty again.*/
  test_set_step(6);
  {
    test_assert(chGuardedPoolAllocTimeout(&gmp1, TIME_IMMEDIATE) == NULL, "list not empty");
  }
}

<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
static const testcase_t test_006_002 = {
  "Loading and emptying a guarded memory pool without waiting",
  test_006_002_setup,
=======
static const testcase_t oslib_test_003_002 = {
  "Default Heap",
  NULL,
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
  NULL,
  oslib_test_003_002_execute
};
#endif /* CH_CFG_USE_SEMAPHORES */

#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
/**
 * @page test_006_003 [6.3] Guarded Memory Pools timeout
 *
 * <h2>Description</h2>
 * The timeout features for the Guarded Memory Pools is tested.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_SEMAPHORES
 * .
 *
 * <h2>Test Steps</h2>
 * - [6.3.1] Trying to allocate with 100mS timeout, must fail because
 *   the pool is empty.
 * .
 */

static void test_006_003_setup(void) {
  chGuardedPoolObjectInit(&gmp1, sizeof (uint32_t));
}

static void test_006_003_execute(void) {

  /* [6.3.1] Trying to allocate with 100mS timeout, must fail because
     the pool is empty.*/
  test_set_step(1);
  {
    test_assert(chGuardedPoolAllocTimeout(&gmp1, MS2ST(100)) == NULL, "list not empty");
  }
}

static const testcase_t test_006_003 = {
  "Guarded Memory Pools timeout",
  test_006_003_setup,
  NULL,
  test_006_003_execute
};
#endif /* CH_CFG_USE_SEMAPHORES */

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
<<<<<<< HEAD:test/nil/source/test/test_sequence_006.c
 * @brief   Memory Pools.
 */
const testcase_t * const test_sequence_006[] = {
  &test_006_001,
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &test_006_002,
#endif
#if (CH_CFG_USE_SEMAPHORES) || defined(__DOXYGEN__)
  &test_006_003,
#endif
  NULL
};

#endif /* CH_CFG_USE_MEMPOOLS */
=======
 * @brief   Array of test cases.
 */
const testcase_t * const oslib_test_sequence_003_array[] = {
  &oslib_test_003_001,
  &oslib_test_003_002,
  NULL
};

/**
 * @brief   Memory Heaps.
 */
const testsequence_t oslib_test_sequence_003 = {
  "Memory Heaps",
  oslib_test_sequence_003_array
};

#endif /* CH_CFG_USE_HEAP */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb:test/oslib/source/test/oslib_test_sequence_003.c
