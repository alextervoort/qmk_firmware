[#ftl]
[#import "/@ftllibs/libutils.ftl" as utils /]
<<<<<<< HEAD
[@pp.dropOutputFile /]
[@pp.changeOutputFile name="test_root.h" /]
[#list conf.*.application.instances.instance as inst]
=======
[#list xml.*.application.instances.instance as inst]
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb
  [#if inst.@id?string == "org.chibios.spc5.components.portable.chibios_unitary_tests_engine"]
    [#assign instance = inst /]
    [#break]
  [/#if]
[/#list]
<<<<<<< HEAD
[@utils.EmitIndentedCCode "" 2 instance.description.copyright.value[0] /]

/**
 * @file    test_root.h
 * @brief   Test Suite root structures header.
 */

#ifndef TEST_ROOT_H
#define TEST_ROOT_H

[#list instance.sequences.sequence as sequence]
#include "test_sequence_${(sequence_index + 1)?string("000")}.h"
=======
[#assign conf = {"instance":instance} /]
[#assign prefix_lower = conf.instance.global_data_and_code.code_prefix.value[0]?trim?lower_case /]
[#assign prefix_upper = conf.instance.global_data_and_code.code_prefix.value[0]?trim?upper_case /]
[@pp.dropOutputFile /]
[@pp.changeOutputFile name=prefix_lower+"test_root.h" /]
[@utils.EmitIndentedCCode "" 2 conf.instance.description.copyright.value[0] /]

/**
 * @file    ${prefix_lower}test_root.h
 * @brief   Test Suite root structures header.
 */

#ifndef ${prefix_upper}TEST_ROOT_H
#define ${prefix_upper}TEST_ROOT_H

#include "ch_test.h"

[#list conf.instance.sequences.sequence as sequence]
#include "${prefix_lower}test_sequence_${(sequence_index + 1)?string("000")}.h"
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb
[/#list]

#if !defined(__DOXYGEN__)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

<<<<<<< HEAD
extern const testcase_t * const *test_suite[];
=======
extern const testsuite_t ${prefix_lower}test_suite;
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Shared definitions.                                                       */
/*===========================================================================*/

<<<<<<< HEAD
[#if instance.global_data_and_code.global_definitions.value[0]?trim?length > 0]
[@utils.EmitIndentedCCode "" 2 instance.global_data_and_code.global_definitions.value[0] /]
=======
[#if conf.instance.global_data_and_code.global_definitions.value[0]?trim?length > 0]
[@utils.EmitIndentedCCode "" 2 conf.instance.global_data_and_code.global_definitions.value[0] /]
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb

[/#if]
#endif /* !defined(__DOXYGEN__) */

<<<<<<< HEAD
#endif /* TEST_ROOT_H */
=======
#endif /* ${prefix_upper}TEST_ROOT_H */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb
