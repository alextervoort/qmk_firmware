[#ftl]
[#import "/@ftllibs/libutils.ftl" as utils /]
[@pp.dropOutputFile /]
<<<<<<< HEAD
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
[#list instance.sequences.sequence as sequence]
  [@pp.changeOutputFile name="test_sequence_" + (sequence_index + 1)?string("000") + ".h" /]
[@utils.EmitIndentedCCode "" 2 instance.description.copyright.value[0] /]

/**
 * @file    test_sequence_${(sequence_index + 1)?string("000")}.h
 * @brief   Test Sequence ${(sequence_index + 1)?string("000")} header.
 */

#ifndef TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H
#define TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H

extern const testcase_t * const test_sequence_${(sequence_index + 1)?string("000")}[];

#endif /* TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H */
=======
[#assign conf = {"instance":instance} /]
[#assign prefix_lower = conf.instance.global_data_and_code.code_prefix.value[0]?trim?lower_case /]
[#assign prefix_upper =conf. instance.global_data_and_code.code_prefix.value[0]?trim?upper_case /]
[#list conf.instance.sequences.sequence as sequence]
  [@pp.changeOutputFile name=prefix_lower+"test_sequence_" + (sequence_index + 1)?string("000") + ".h" /]
[@utils.EmitIndentedCCode "" 2 conf.instance.description.copyright.value[0] /]

/**
 * @file    ${prefix_lower}test_sequence_${(sequence_index + 1)?string("000")}.h
 * @brief   Test Sequence ${(sequence_index + 1)?string("000")} header.
 */

#ifndef ${prefix_upper}TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H
#define ${prefix_upper}TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H

extern const testsequence_t ${prefix_lower}test_sequence_${(sequence_index + 1)?string("000")};

#endif /* ${prefix_upper}TEST_SEQUENCE_${(sequence_index + 1)?string("000")}_H */
>>>>>>> 3f9756043d9305fb929d6b3308b80a4ab3c24ddb
[/#list]
