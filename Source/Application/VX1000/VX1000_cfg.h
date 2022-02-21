/* ------------------------------------------------------------------------------ */
/* VX1000_cfg.h                                                                   */
/* Vector VX1000 Application Driver for Renesas V850E2 and Renesas RH850          */
/* Version 3.00  04.01.2016                                                       */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* User specific configuration settings                                           */
/* ------------------------------------------------------------------------------ */

#if !defined(VX1000_TARGET_X850)
#define VX1000_TARGET_X850
#endif /* !VX1000_TARGET_X850 */

#ifdef XCP_DEBUG
#define VX1000If_IsVX1000DriverAccessEnabled 1
#else
#define VX1000If_IsVX1000DriverAccessEnabled 0
#endif

/* ----------------------------------------------------------------------------- */
/* Note: VX1000_cfg.h serves multiple purposes and is included                   */
/* several times with different predefines being set to select the wanted        */
/* purpose. IT IS INTENTED that some lines may be repeatedly processed (namely   */
/* the "memmap" part) while the rest (the configuration part) actually IS        */
/* PROTECTED from double inclusion even though your static code analyser tool    */
/* might not see this and state a warning or error about lacking protection.     */
/* Those wrong messages can be safely ignored.                                   */
/* So first come the alternative-memmap parts:                                   */

#if defined(VX1000_BEGSECT_VXSTRUCT_H) && (!defined(VX1000_BEGSECT_VXSTRUCT_H_UNDO)) /* explicit multiple inclusion */

/* ----------------------------------------------------------------------------- */
/* Optionally define the memory section were the global VX1000 data shall be     */
/* placed. The address of the variable gVX1000 in this memory section must be    */
/* transferred to the VxConfig or VxPlugin settings, therefore a fixed linkage   */
/* has advantages. The used memory area must not be cached !                     */
/* When using HSSL pods, the memory section must be covered by a trace window.   */
/* The following lines will be placed via #include mechanism right before the    */
/* declaration of the VX1000 structure in the header file of the driver and      */
/* must match the tool chain that you're using to build the application.         */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_headers
*/


#elif defined(VX1000_BEGSECT_VXSTRUCT_C) && (!defined(VX1000_BEGSECT_VXSTRUCT_C_UNDO))

/* ----------------------------------------------------------------------------- */
/* Code lines to trigger usage of the (optional) memory section for VX1000 data. */
/* These lines will be placed via #include mechanism right before the allocation */
/* of the VX1000 structure in the module file of the driver and must match the   */
/* tool chain that you're using to build the application.                        */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_modules
*/


#elif defined(VX1000_ENDSECT_VXSTRUCT_H) && (!defined(VX1000_ENDSECT_VXSTRUCT_H_UNDO))

/* ----------------------------------------------------------------------------- */
/* Code lines to close the (optional) memory section of the global VX1000 data.  */
/* These lines will be placed via #include mechanism right after the declaration */
/* of the VX1000 structure in the header file of the driver and must match the   */
/* tool chain that you're using to build the application.                        */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_headers
*/


#elif defined(VX1000_ENDSECT_VXSTRUCT_C) && (!defined(VX1000_ENDSECT_VXSTRUCT_C_UNDO))

/* ----------------------------------------------------------------------------- */
/* Code lines to close the (optional) memory section of the global VX1000 data.  */
/* These lines will be placed via #include mechanism right after the allocation  */
/* of the VX1000 structure in the module file of the driver and must match the   */
/* tool chain that you're using to build the application.                        */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_modules
 */


#elif defined(VX1000_BEGSECT_VXMODULE_H) && (!defined(VX1000_BEGSECT_VXMODULE_H_UNDO))

/* ----------------------------------------------------------------------------- */
/* Optional Code lines that you may want to place at the beginning of the        */
/* header file of the driver, e.g. with #pragmas to force a special linkage.     */
/* If you enabled structure padding for your software project, a pragma that     */
/* disables padding must be specified here because the VX1000 structure members  */
/* are accessed by external tools via fixed offsets expecting no padding.        */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_headers
*/
#pragma pack(1) /* syntax valid for both GCC and for GHS as well as for Renesas-CX; may need adaptation for other compilers */


#elif defined(VX1000_BEGSECT_VXMODULE_C) && (!defined(VX1000_BEGSECT_VXMODULE_C_UNDO))

/* ----------------------------------------------------------------------------- */
/* Optional Code lines that you may want to place at the beginning of the        */
/* module file of the driver, e.g. with #pragmas to force a special linkage      */
/* or to raise the compiler's optimisation level for only this module.           */
/* If you enabled structure padding for your software project, a pragma that     */
/* disables padding must be specified here because the VX1000 structure members  */
/* are accessed by external tools via fixed offsets expecting no padding.        */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_modules
*/


#elif defined(VX1000_ENDSECT_VXMODULE_H) && (!defined(VX1000_ENDSECT_VXMODULE_H_UNDO))

/* ----------------------------------------------------------------------------- */
/* Optional Code lines that you may want to place at the end of the              */
/* header file of the driver, e.g. with #pragmas to restore standard linkage.    */
/* If you changed the structure padding setting for the VX1000 code, you should  */
/* provide a pragma here that restores the settings to your application default. */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_headers
*/
#if defined(__CX__)
/* Renesas CX compiler syntax */
#pragma pack(4)
#else /* !__CX__ */
/* GHS compiler syntax */
#pragma pack()
#endif /* !__CX__ */


#elif defined(VX1000_ENDSECT_VXMODULE_C) && (!defined(VX1000_ENDSECT_VXMODULE_C_UNDO))

/* ----------------------------------------------------------------------------- */
/* Optional Code lines that you may want to place at the end of the              */
/* module file of the driver, e.g. with #pragmas to restore standard linkage.    */
/* If you changed the structure padding setting for the VX1000 code, you should  */
/* provide a pragma here that restores the settings to your application default. */

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_modules
*/


#elif defined(VX1000_BEGSECT_EMEM_HDR_H) && (!defined(VX1000_BEGSECT_EMEM_HDR_H_UNDO))

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_headers
*/


#elif defined(VX1000_BEGSECT_EMEM_HDR_C) && (!defined(VX1000_BEGSECT_EMEM_HDR_C_UNDO))

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_forcing_special_linkage_in_modules
*/


#elif defined(VX1000_ENDSECT_EMEM_HDR_H) && (!defined(VX1000_ENDSECT_EMEM_HDR_H_UNDO))

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_headers
*/


#elif defined(VX1000_ENDSECT_EMEM_HDR_C) && (!defined(VX1000_ENDSECT_EMEM_HDR_C_UNDO))

/*
___optional_and_compiler_dependent_section_pragmas_or_defines_and_includes_for_restoring_previous_linkage_in_modules
*/





/* ----------------------------------------------------------------------------- */
/* Now follows the normal configuration header that auto-protects itself from    */
/* repeated inclusion. This part contains the configuration of the various       */
/* features. If you turn a feature off, the associated code and data will not    */
/* be present in your application, but you may still call the associated API     */
/* because the driver provides empty defines with that API name in that case     */
/* so you do NOT need to "conditionalise" your code via preprocessor #ifs ...    */
#elif !defined(VX1000_CFG_H)
#define VX1000_CFG_H


/* ----------------------------------------------------------------------------- */
/* This specifies the version numbers of the configuration template that this    */
/* file was derived from. It is used in the compatibility check between the      */
/* configuration file, the driver header file and the driver module file.        */

#define VX1000_FILE_VERSION_MAJOR_H    3U
#define VX1000_FILE_VERSION_MINOR_H    0U


/* ----------------------------------------------------------------------------- */
/* If for production code the entire VX1000 functionality shall be disabled      */
/* transparently, enable the following define. This way, the driver module will  */
/* not produce any code or constants, will not use RAM, and the driver header    */
/* will provide empty API macros so that the application code needs no change.   */

/*
#define VX1000_DISABLE_INSTRUMENTATION
*/


/* ----------------------------------------------------------------------------- */
/* Optionally define a compiler dependent expression that just evaluates to the  */
/* value of the 2nd parameter (whose expected type is the 1st parameter) but as  */
/* a side effect may perform a dummy access of the four remaining parameters in  */
/* a way that prevents compiler warnings about unused or needlessly initialised  */
/* variables inside the calling code if needed. Be aware that those parameters   */
/* can be of any type, e.g. constants, immediates, variables or pointers with    */
/* arbitrary qualifiers like const or volatile. If you leave this undefined the  */
/* default definition to just "(R)" will become active which definitely does     */
/* not produce any code to be executed but cannot prevent any warning.           */

#define VX1000_DISCARD4DUMMYARGS(T, R, A1, A2, A3, A4)  ((R) + (T)(0UL & (((VX1000_UINT32)(A1) & (VX1000_UINT32)(A2)) | ((VX1000_UINT32)(A3) & (VX1000_UINT32)(A4))))) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 becasue the goal of this expression is that the compiler does NOT generate any code for it so a function call is the opposite from what is needed here */

/* ----------------------------------------------------------------------------- */
/* Optionally define a compiler dependent statement that just reads the value    */
/* of its macro parameter without modifying it or relying on it to be of a       */
/* specific type (it can be e.g. a constant, immediate, variable or a pointer    */
/* with arbitrary qualifiers like const or volatile). If you leave this          */
/* undefined the default definition to "" will become active. You may want to    */
/* find a solution per tool chain, e.g. for 100% coverage it is good to HAVE     */
/* code generated for it (e.g. a NOP) while for normal compilation you want no   */
/* code that would have to be executed at runtime and for MISRA or LINT checkers */
/* you definitely need a statement that actually touches the parameter.          */

#define VX1000_DUMMYREAD(X) (void)(X);


#if defined(VX1000_DISABLE_INSTRUMENTATION)
/* ----------------------------------------------------------------------------- */
/* As some compilers fail creating completely empty object files or fail         */
/* linking those, you may provide this define as a workaround that makes the     */
/* driver module look "somehow non-empty" to compiler and linker.                */

/*
#define VX1000_EMPTYFILE_DUMMYDECL     ___some_dummy_constant_declaration_or_function_declaration
*/

#else /* !VX1000_DISABLE_INSTRUMENTATION */

/* ----------------------------------------------------------------------------- */
/* Optionally define the compiler dependent type for 64bit variables for OLDAv8  */

/*
#define VX1000_UINT64                  ___the_64bit_interger_type_that_is_provided_by_the_used_compiler_for_this_plattform
*/


/* ----------------------------------------------------------------------------- */
/* Define the target ECU identification string (for XCP GET_ID)                  */
/* This is optional and may be used by CANape to auto-select the correct         */
/* A2L database when connecting to an unidentified ECU. Just leave this          */
/* undefined if you do not want to exploit this feature.                         */

/*
#define VX1000_ECUID                   ___a_quoted_constant_string_that_contains_the_desired_file_name
#define VX1000_ECUID_LEN               ___the_count_of_characters_in_VX1000_ECUID_excluding_the_terminating_zero_byte
*/


/* ----------------------------------------------------------------------------- */
/* To allow re-compilation of the driver code for different targets with common  */
/* linkage of the data (e.g. to have the code replicated into the local IRAMs of */
/* each core, or when the cores are differently equipped with instruction set    */
/* extensions or when the cores use completely different instruction sets, like  */
/* HC12<>XGATE, ARM<>THUMB, BookE<>VLE, Tricore<>XC800, ...), you may provide    */
/* a string that will serve as function suffix. A second effect is that the      */
/* code is optimized with respect to main/slave-core nature of the driver        */
/* architecture: the objects for the slave cores' functions will not contain     */
/* code to detect whether they run on the main core, nor the main-core-only      */
/* features (like mailbox etc.) Just leave this undefined if the driver shall    */
/* be executed on the main core (or on a single-core MCU).                       */

/*
#define VX1000_COMPILED_FOR_SLAVECORES ___an_optional_unique_sequence_of_some_letters_and_digits
*/


/* ----------------------------------------------------------------------------- */
/* Some configuration settings cannot be checked at compile time. The driver     */
/* therefore performs several runtime checks. Some of these checks happen in     */
/* response to XCP requests which allows to transmit the result to the XCP       */
/* master but other checks happen implicitly during start-up. In the latter case */
/* there is no XCP channel to transmit the error code and therefore the driver   */
/* offers the possibility to log these error codes into a ring buffer in RAM.    */
/* You may optionally specify the size of that ring buffer here, where the       */
/* default value of 0 means that there is no logging at all.                     */

/*
#define VX1000_ERRLOG_SIZE             ___optional_count_of_entries_in_the_fault_collection_buffer
*/

/* ----------------------------------------------------------------------------- */
/* The timer resolution of VX1000_CLOCK() is important for correct detection     */
/* of timeouts, for benchmarking and time-stamping DAQ packets. For your         */
/* convenience, there are various ways do specify the resolution using just      */
/* a single define or using a pair of defines which allows to specify fractions. */
/* Either either VX1000_CLOCK_TICKS_PER_US or VX1000_CLOCK_TICKS_PER_MS or       */
/* VX1000_CLOCK_TICKS_PER_S must be define OR for rational numbers the pair      */
/* VX1000_CLOCK_TICKS_PER_BASE and VX1000_CLOCK_TICKS_BASE_NS                    */

#define VX1000_CLOCK_TICKS_PER_MS      100   /*1us*/

/* ----------------------------------------------------------------------------- */
/* If you want to synchronise/syntonise events in this ECU to events in further  */
/* ECUs or in the PC, you have to provide two additional details about the time  */
/* base of the driver. Just leave this undefined if you don't need that feature, */
/* then the VX blindly trusts VX1000_CLOCK(), assuming full 32bit time stamps.   */

/*
#define VX1000_CLOCK_TIMER_ADDR        ___an_optional_pointer_to_the_memory_mapped_32bit_register_that_VX1000_CLOCK_timestamps_are_based_on
#define VX1000_CLOCK_TIMER_SIZE        ___the_count_of_valid_bits_in_the_timer_hardware_register_rounded_down_to_0_or_16_or_24_or_32
*/

/* ----------------------------------------------------------------------------- */
/* Depending on the used VX hardware, the correct measurement mode must be       */
/* selected. For MSSL pods (VX1542/VX1543/VX1544), the driver must help the      */
/* hardware to efficiently transmit distributed data and to maintain data        */
/* consistency, which is enabled by defining VX1000_OLDA. When however using     */
/* an HSSL pod (VX1450/VX1451/VX1452) the feature is not needed and this         */
/* must be undefined.                                                            */

#define VX1000_OLDA


#if defined(VX1000_OLDA)

/* ----------------------------------------------------------------------------- */
/* Define the memory size in bytes for the OLDA DAQ transfer tables.             */
/* Size needs to be at least the amount of measurement data + 4 Byte for each    */
/* memory gap.                                                                   */

#define VX1000_OLDA_MEMORY_SIZE        1024//  ___the_size_in_bytes_to_be_allocated_by_the_driver_as_copy_buffers


/* ----------------------------------------------------------------------------- */
/* Optionally define VX1000_OLDA_MEMORY_ADDR to reuse user space for VX at that  */
/* address. (Otherwise VX1000_OLDA_MEMORY_SIZE bytes will be allocated           */
/* automatically inside the VX1000_DATA structure.)                              */

/*
#define VX1000_OLDA_MEMORY_ADDR        ___optional_address_of_a_RAM_area_that_can_be_used_exclusively_by_the_VX
*/


/* ----------------------------------------------------------------------------- */
/* To turn on benchmarks of the event copy durations, needs 8bytes RAM per event */

/*
#define VX1000_OLDA_BENCHMARK
*/


/* ----------------------------------------------------------------------------- */
/* Enable Olda overload detection.                                               */

/*
#define VX1000_OLDA_OVERLOAD_DETECTION
*/


/* ----------------------------------------------------------------------------- */
/* You may want to use classic OLDA v6 format for the transfer table entries     */
/* because it needs 20% less RAM for the transfer descriptors. The drawback is   */
/* that it cannot enable access to all ECU memory locations as V7 would do.      */
/* Furthermore it is not usable when coldstart/VX detection shall be available!  */

/*
#define VX1000_OLDA_FORCE_V6
*/

/* ----------------------------------------------------------------------------- */
/* To override the default encoding of OLDA v6 transfer table entries            */

/*
#define VX1000_OLDA_SIZE_LENGTH        ___a_value_relevant_only_for_OLDAv6_between_4_and_7
#define VX1000_OLDA_SIZE_OFFSET        ___a_value_relevant_only_for_OLDAv6_providing_the_bit_index
#define VX1000_OLDA_SIZE_SWAP_VALUE    ___a_value_relevant_only_for_OLDAv6_that_contains_VX1000_OLDA_SIZE_LENGTH_addressbits_at_VX1000_OLDA_SIZE_OFFSET_that_are_equal_among_all_measurements
*/


/* ----------------------------------------------------------------------------- */
/* Here you can enable features that may help to improve OLDA performance. The   */
/* effect is not deterministic, so you should benchmark all versions to finally  */
/* decide what shall be enabled or disabled. If you don't care for performance   */
/* and RAM usage, just leave everything undefined.                               */

#define VX1000_SUPPORT_OLDA7_BYTEDAQ
#define VX1000_SUPPORT_OLDA7_COMPRESS


/* ----------------------------------------------------------------------------- */
/* If you're using a VX FW v3.1 or higher, you may want to experience OLDA v8    */
/* because it may help to optimise resource utilisation. The drawback is that    */
/* it cannot be used when coldstart/VX detection shall be usable. There are      */
/* several sub-options to trim the behaviour of the driver and the VX.           */

/*
#define VX1000_OLDA_FORCE_V8

#define VX1000_SUPPORT_OLDA8CMD_CALLJITA
#define VX1000_SUPPORT_OLDA8CMD_SUBEVT
#define VX1000_SUPPORT_OLDA8CMD_WAIT
#define VX1000_SUPPORT_OLDA8CMD_DONE
#define VX1000_SUPPORT_OLDA8CMD_CP64N
#define VX1000_SUPPORT_OLDA8CMD_CP32N
#define VX1000_SUPPORT_OLDA8CMD_CP16N
#define VX1000_SUPPORT_OLDA8CMD_CP8N
#define VX1000_SUPPORT_OLDA8CMD_SP8N
*/

#endif /* VX1000_OLDA */


/* ----------------------------------------------------------------------------- */
/* Disable or enable and configure the stimulation / bypassing feature           */

/*
#define VX1000_STIM
*/

#if defined(VX1000_STIM)

/* ----------------------------------------------------------------------------- */
/* Configure the stimulation / bypassing feature. The event number range may     */
/* be chosen freely, the maximum range is 0..31. Each event needs 4 Bytes RAM,   */
/* so you may want to specify a smaller range.                                   */

#define VX1000_STIM_EVENT_OFFSET       0     /* ___index_of_the_first_STIM_event */
#define VX1000_STIM_EVENT_COUNT        31    /* ___count_of_available_STIM_events*/


/* ----------------------------------------------------------------------------- */
/* Enable indirect stimulation to optimize performance against memory usage.     */
/* Needs additional memory (amount of bypass data + 4 byte per memory gap)       */
#if defined(VX1000_OLDA)
#define VX1000_STIM_BY_OLDA
#endif /* VX1000_OLDA */


/* ----------------------------------------------------------------------------- */
/* To turn on basic benchmarking of all bypass round trip times, just define     */
/* VX1000_STIM_BENCHMARK. This will only use little RAM and runtime resources.   */

/*
#define VX1000_STIM_BENCHMARK
*/


/* ----------------------------------------------------------------------------- */
/* To turn on advanced benchmarking (of one particular STIM channel) you can     */
/* define VX1000_STIM_HISTOGRAM to the desired channel number. This debug        */
/* feature eats one kilobyte of RAM. Leave undefined to disable the feature.     */

/*
#define VX1000_STIM_HISTOGRAM          ((VX1000_STIM_EVENT_OFFSET) +0)
*/

/* ----------------------------------------------------------------------------- */
/* STIM version 0 works out of the box, is supported by all FW versions and does */
/* not need additional RAM or configuration settings. However several advanced   */
/* features are only available in STIM version 1 (only supported by FW 1.8 and   */
/* newer!) If you want to use the advanced features, define VX1000_STIM_FORCE_V1 */
/* and configure the particular features below.                                  */

/*
#define VX1000_STIM_FORCE_V1
*/


#if defined (VX1000_STIM_FORCE_V1)
/* ----------------------------------------------------------------------------- */
/* configuration of STIM version 1 special features                              */


/* ----------------------------------------------------------------------------- */
/* Define the STIM behaviour after ECU resets                                    */

#define VX1000_IS_BYPASS_RESUME_ALLOWED() ___an_expression_that_returns_TRUE_if_and_only_if_bypassing_shall_be_resumed_after_an_ECU_reset()


/* ----------------------------------------------------------------------------- */
/* Inform the VX1000 how a specific XCP event is to be handled. For each STIM    */
/* event, the following information must be provided: What is the associated     */
/* DAQ event (for the bypassing upload path) and which STIM type out of          */
/* {VX1000_BYPASS_TYPE_DIRECT, VX1000_BYPASS_TYPE_OLDA, VX1000_BYPASS_TYPE_HOOK} */
/* shall be used.                                                                */

#define VX1000_SET_STIM_INFO() do                                                                        \
  {                                                                                                      \
    VX1000_REGISTER_STIM_EVENT(___associated_DAQ_event_ID, ___first_STIM_event_ID, ___desired_STIM_type) \
    ...                                                                                                  \
    VX1000_REGISTER_STIM_EVENT(___associated_DAQ_event_ID, ___last_STIM_event_ID , ___desired_STIM_type) \
  } while (0); /* dummy loop only here for MISRA */



/* ----------------------------------------------------------------------------- */
/* Depending on the STIM type, the driver can be forced to wait for all channels */
/* to have receive complete/valid STIM data before the application will see data */

/*
#define VX1000_BYPASS_ALL_CHANS_STIMD
*/


/* ----------------------------------------------------------------------------- */
/* If the STIM type VX1000_BYPASS_TYPE_HOOK shall be used,                       */
/* VX1000_HOOK_BASED_BYPASSING must be enabled and configured below              */

/*
#define VX1000_HOOK_BASED_BYPASSING
*/


/* ----------------------------------------------------------------------------- */
/* Specify where in RAM the hook based bypassing lookup table resides            */

/*
#define VX1000_BYPASS_HBB_LUT_ADDR     ___address_of_the_HBB_lookup_table
*/


/* ----------------------------------------------------------------------------- */
/* Specify how many entries in the hook based bypassing lookup table exist       */

/*
#define VX1000_BYPASS_HBB_LUT_ENTRIES  ___number_of_entries_in_the_HBB_lookup_table
*/

#endif /* VX1000_STIM_FORCE_V1 */

#endif /* VX1000_STIM */

/* ----------------------------------------------------------------------------- */
/* Define the maximum coldstart delay from VX1000_INIT_ASYNC_START to            */
/* VX1000_INIT_ASYNC_END in milliseconds (a value of 0 disables the delay).      */

/*
#define VX1000_COLDSTART_TIMEOUT_MS    ___the_number_of_milliseconds_to_wait_for_tool_during_coldstart
*/

/* ----------------------------------------------------------------------------- */
/* Turn on benchmarking of the cold start behaviour (undef this to save memory)  */

/*
#define VX1000_COLDSTART_BENCHMARK
*/


/* ----------------------------------------------------------------------------- */
/* Depending on the wiring of the ECU, software reset may not be visible for the */
/* VX and the measurement will not be restarted automatically when the ECU       */
/* finished booting. As a workaround, the driver provides a handshake mechanism  */
/* that allows the application to inform the VX via the VX1000_PREPARE_SOFTRESET */
/* API right before performing the reset. The maximum allowed delay of the       */
/* handshake must be specified here. If it is not defined, the API will be empty */

/*
#define VX1000_SOFTRESET_TIMEOUT_MS    ___the_number_of_milliseconds_to_wait_for_tool_before_a_softreset
*/


/* ----------------------------------------------------------------------------- */
/* VX1000 Detection                                                              */

/*
#define VX1000_DETECTION
*/
#define VX1000_DETECTION_TIMEOUT_US    ___the_number_of_microseconds_to_wait_for_tool_response_during_presence_check


/* ----------------------------------------------------------------------------- */
/* Enable and configure cold start calibration (is this implemented?)            */

/*
#define VX1000_COLDSTART_CALIBRATION
#define VX1000_COLDSTART_FLASH_ADDR     0x1234
#define VX1000_COLDSTART_FLASH_SIZE     64
#define VX1000_COLDSTART_CHS_BLOCK_SIZE 64
*/


/* ----------------------------------------------------------------------------- */
/* Calibration of flash at runtime is possible if the MCU supports it and if     */
/* the following defines are configured properly. The sub-feature of page        */
/* switching allows transaction-based calibrate and to undo the entire           */
/* calibration with a single command. Because this feature may alter also        */
/* code being executed by the ECU, you should know well what you're doing.       */

/*
#define VX1000_OVERLAY
*/


#if defined(VX1000_OVERLAY)

/* ----------------------------------------------------------------------------- */
/* By default, the overlay is activated in VX1000_INIT() call and stays active   */
/* all the time. If you need more control and want to switch between the overlay */
/* pages, this can be enabled by defining VX1000_MAILBOX_OVERLAY_CONTROL         */

#define VX1000_MAILBOX_OVERLAY_CONTROL


/* ----------------------------------------------------------------------------- */
/* By default, the overlay is configured statically by the defines in this       */
/* header. For some derivatives, you can enable dynamic configuration of the     */
/* overlay(s) based on the requests of the tool to gain better resource          */
/* utilisation.                                                                  */

/*
#define VX1000_OVERLAY_VX_CONFIGURABLE
*/

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE)


/* ----------------------------------------------------------------------------- */
/* Enable the desired overlay features depending on the ECU capabilities         */

/* Can the application handle keep-awakes correctly?                             */
#define VX1000_OVLENBL_KEEP_AWAKE
/* Does the application want to verify the working page before page switch?      */
#define VX1000_OVLENBL_VALIDATE_PAGESW
/* Has the EMEM a dedicated power supply?                                        */
#define VX1000_OVLENBL_PERSISTENT_EMEM
/* Will the application perform a soft-reset after it detected a CAL-Wakeup?     */
#define VX1000_OVLENBL_RST_ON_CALWAKEUP
/* Shall the EPK address of the WP be calculated by the VX1000?                  */
#define VX1000_OVLENBL_USE_VX_EPK_TRANS

#else /* !VX1000_OVERLAY_VX_CONFIGURABLE */

/* ----------------------------------------------------------------------------- */
/* A static definition of the overlay memory areas must be provided in this mode */
/* By default, the driver assumes that the application uses a 1:1 address        */
/* mapping to access the memory and thus the defines VX1000_OVERLAY_PHYSADDR     */
/* and VX1000_CALRAM_PHYSADDR need only to be provided if both the MCU provides  */
/* the feature of non-1:1 mappings and the application actually makes use of it. */

#define VX1000_OVERLAY_SIZE            ___the_size_of_the_to_be_overlaid_flash_area_of_supported_granularity
#define VX1000_OVERLAY_ADDR            ___the_address_of_the_to_be_overlaid_flash_area_of_supported_alignment
#define VX1000_CALRAM_ADDR             ___the_address_of_the_unused_RAM_area_that_shall_overlay_the_flash



#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE */

/* ----------------------------------------------------------------------------- */
/* Core synchronous page switching means that each core switches the overlay     */
/* unit in the microcontroller for its own. In a multicore system there are      */
/* several points in time where the page switch is performed (corresponding to   */
/* the number of cores). Each core may switch its page outside of all tasks      */
/* that are running on this core. This option is only possible when the          */
/* microcontroller's overlay unit supports independent page switches for the     */
/* cores. On the other hand it is a must on those multicore systems where each   */
/* core brings an independent overlay unit that can only be programmed by the    */
/* core itself (e.g. core-internal MMU; see VX1000_OVLENBL_HW_INIT_PER_CORE).    */
/* The feature is enabled when VX1000_OVLENBL_CORE_SYNC_PAGESW is defined.       */

/*
#define VX1000_OVLENBL_CORE_SYNC_PAGESW
*/

/* ----------------------------------------------------------------------------- */
/* Synchronous calibration page switching means that the ECU is signaled by      */
/* the VX1000 to perform a page switch. The VX1000 preconfigures the overlay     */
/* registers and signals the ECU which overlay register sets should be           */
/* enabled/disabled. Before the ECU performs the page switch additional          */  
/* validation checks can be performed. If the application requires a             */
/* task- or core- synchronous page switching, the application is responsible     */
/* for executing the page switch only in synchronised situations. If you leave   */
/* VX1000_OVLENBL_SYNC_PAGESWITCH undefined the VX1000 will switch the page in   */
/* the background without ECU application interaction.                           */

/*
#define VX1000_OVLENBL_SYNC_PAGESWITCH
*/


#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) || defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
/* ----------------------------------------------------------------------------- */
/* In multi-core (or better "multi-bus-master") environments, it may be          */
/* desirable to make the overlay visible to only some of the bus masters while   */
/* the remaining masters shall continue accessing the reference page. For this   */
/* purpose you have to define a bit mask VX1000_OVL_CAL_BUS_MASTER according     */
/* to the PFlash register definition of your MCU.                                */

#define VX1000_OVL_CAL_BUS_MASTER      ___a_derivative_dependent_bitmask_of_relevant_PFLASH_busmasters


/* ----------------------------------------------------------------------------- */
/* If the application performs an ECU reset after page switches (e.g. as very    */
/* rude method for synchronising multiple cores and DMA controllers) the VX must */
/* be informed beforehand about this behaviour by enabling the following define. */

/*
#define VX1000_OVLENBL_RST_ON_SNCPAGESW
*/

#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW || VX1000_OVLENBL_SYNC_PAGESWITCH */


#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)
/* ----------------------------------------------------------------------------- */
/* Configure the parameters of some special feature.                             */
/* (For the average use-case this may just be left undefined.)                   */

#define VX1000_OVL_EPK_REFPAGE_ADDR    ___the_correct_address
#define VX1000_OVL_EPK_LENGTH          ___the_correct_size

#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS */

#endif /* VX1000_OVERLAY */



/* ----------------------------------------------------------------------------- */
/* Enable the mailbox to forward some XCP commands between tool and application  */
/* It can be used e.g. for printf, page switching, copy page or page relocation  */
/* The sub features can be enable or disabled individually and are only active   */
/* if VX1000_MAILBOX is defined. The default mailbox has a reasonable size for   */
/* the average purpose but the size may still be overridden below                */

/*
#define VX1000_MAILBOX
*/
/*
#define VX1000_MAILBOX_SLOTS           ___an_optional_number_that_must_be_a_power_of_two
#define VX1000_MAILBOX_SLOT_DWORDS     ___an_optional_number_that_must_be_greater_than_two
*/

/* ----------------------------------------------------------------------------- */
/* Enable this to allow the application to send formatted XCP SERV_TEXT messages */

/*
#define VX1000_MAILBOX_PRINTF
*/

/* ----------------------------------------------------------------------------- */
/* Enable this if a reduced printf version instead of the full one is sufficient */

/*
#define VX1000_PRINTF_MINIMAL
*/


/* ----------------------------------------------------------------------------- */
/* Enable these to provide a special upload or download API                      */

/*
#define VX1000_MAILBOX_PROVIDE_SPLITREAD
#define VX1000_MAILBOX_PROVIDE_SPLITWRITE
*/
/*
#define VX1000_MAILBOX_CAL_READ_WRITE
*/




/* ----------------------------------------------------------------------------- */
/* XCP FKL loading support _without_ entering debug mode.                        */
/* This is only needed for flash programming if the device cannot be driven      */
/* externally into debug halt state, e.g.when the MCU must permanently serve     */
/* an external watchdog. End of RAM is always a good place for this; the 32      */
/* aligned bytes are only used by the VX during flash kernel start and may be    */
/* used during normal operation for other purposes. The only requirement to this */
/* address is that it does not overlap the FKL space.                            */

/*
#define VX1000_FKL_SUPPORT_ADDR        ___an_address_of_32_bytes_unused_RAM
*/


/* ----------------------------------------------------------------------------- */
/* This enables and configures the Resource Management feature.                  */
/* This features helps to divide the resources of the micro-controller between   */
/* the application of the ECU and the VX1000 AppDriver.                          */

/*
#define VX1000_RES_MGMT
*/

#if defined(VX1000_RES_MGMT)
/* ----------------------------------------------------------------------------- */
/* With this define the switches VX1000_RES_MGMT_RAM_START and                   */
/* VX1000_RES_MGMT_RAM_SIZE are used to specify a memory-region that the VX1000  */
/* AppDriver and the VX1000 hardware should use exclusively for measurement and  */
/* calibration purposes (e.g. overlay, data trace, OLDA). This memory region     */
/* shall not be accessed by the ECU application. Especially RAM checks/tests     */
/* or memory/CRC initialisations are not permitted. As a result of this          */
/* requirement the gVX1000 structure and the overlay EMEM headers (EMEM_HDR)     */
/* shall not be located in this resource management memory region. If            */
/* VX1000_OLDA_MEMORY_ADDR is explicitly defined, this memory shall not be       */
/* located in the resource management memory region. Usually this feature is     */
/* used to divide the emulation memory of a development device                   */

/*
#define VX1000_RES_MGMT_ENABLE_OVL_RAM
#define VX1000_RES_MGMT_RAM_START      ___the_correct_address  -- note: had been called VX1000_RES_MGMT_OVL_RAM_START in the past
#define VX1000_RES_MGMT_RAM_SIZE       ___the_correct_size     -- note: had been called VX1000_RES_MGMT_OVL_RAM_SIZE in the past
*/

/* ----------------------------------------------------------------------------- */
/* This feature is used to specify which overlay-register-items shall be used    */
/* by the VX1000 Application System. The switches VX1000_RES_MGMT_CFG_ITEM_START */
/* and VX1000_RES_MGMT_CFG_ITEM_LEN are used to select the register region       */
/* (e.g. Start=0, Len=32). All other overlay-register-items are ignored during   */
/* overlay-calculation. If nothing is specified the VX1000 will use all          */
/* available Overlay-Registers. Normally this feature is not required and        */
/* therefore not enabled.                                                        */

/*
#define VX1000_RES_MGMT_ENABLE_CFG_ITEM
#define VX1000_RES_MGMT_CFG_ITEM_START ___the_correct_address
#define VX1000_RES_MGMT_CFG_ITEM_LEN   ___the_correct_size
*/

#endif /* VX1000_RES_MGMT */



/* ----------------------------------------------------------------------------- */
/* You should include here the header(s) that provide the data types and the     */
/* prototypes or SFR definitions that you will use as the application callbacks  */
/* At this point, the selection of the used VX driver features is complete and   */
/* the included header(s) may evaluate the above defines to provide only the     */
/* desired functionality. This way, you will not run into compiler or MISRA      */
/* warnings about uncalled functions and such.                                   */

/*
#include "___my_header_that_provides_the_needed_declarations.h"
*/




/* ----------------------------------------------------------------------------- */
/* The driver needs a stable high resolution time base to correctly detect       */
/* communication timeouts and optionally for time stamping the XCP packets.      */
/* In particular, the time base is needed for the following features             */
/*   1. DAQ over DATA TRACE with timestamps that relate to the ECU time          */
/*   2. DAQ over JTAG is used (for Nexus class 2+)                               */
/*   3. to validate/reject STIM_v1 packets                                       */
/*   4. to check bypass timeouts                                                 */
/*   5. to check coldstart delay timeouts                                        */
/*   6. to check soft-reset notification timeouts                                */


#define VX1000_CLOCK()           (*(unsigned int *)(((unsigned int)0xFFD70100) + 0x0004u))   // (unsigned int)(*(&Systemtick_10us))//0  /* dummy, actually: (VX1000_UINT32)(___a_function_or_hw_register_that_returns_a_freerunning_32bit_time()) */



/* ----------------------------------------------------------------------------- */
/* If the XCP features shall be used on more than one core, the driver needs     */
/* an indicator whether it is running on the "main" core that is actively        */
/* initialising a stable high resolution time base to correctly detect           */
/* communication timeouts and optionally for time stamping the XCP packets       */

/*
#define VX1000_RUNNING_ON_MAINCORE()   ___a_function_that_returns_true_if_and_only_if_executed_from_one_core_that_is_declared_the_main_core()
*/


/* ----------------------------------------------------------------------------- */
/* If the VX API is called interruptible in multitasking systems but the MCU     */
/* offers HW sync mechanisms via atomic read-modify-write memory access          */
/* instructions, you may optimise execution speed by defining some of these.     */

/*
#define VX1000_ATOMIC_XOR32(A, D)      ___an_optional_function_that_XORs_value_D_to_memory_at_address_A(...);
#define VX1000_ATOMIC_AND32(A, D)      ___an_optional_function_that_ANDs_value_D_to_memory_at_address_A(...);
#define VX1000_ATOMIC_OR32(A, D)       ___an_optional_function_that_ORs_value_D_to_memory_at_address_A(...);
#define VX1000_ATOMIC_XOR32X2(A, D)    ___an_optional_function_that_XORs_value_D_to_memories_at_address_A_and_Aplus4(...);
*/

/* ----------------------------------------------------------------------------- */
/* On multicore systems, define an appropriate MUTEX mechanism to interlock      */
/* code running on different cores. If you leave this undefined, the driver will */
/* assume a non-preemptive single core system and not try do be thread-safe.     */

/*
#define VX1000_ENTER_SPINLOCK()        ___a_function_that_suppresses_execution_of_any_other_thread_until_VX1000_LEAVE_SPINLOCK_is_called();
#define VX1000_LEAVE_SPINLOCK()        ___a_function_that_restores_the_suppression_state_from_before_VX1000_ENTER_SPINLOCK_was_called();
*/


/* ----------------------------------------------------------------------------- */
/* On systems with cheap 64bit-RAM that does not allow 8/16/32bit-writes define  */
/* an appropriate memcpy function that performs the required 64bit               */
/* read-modify-write accesses where needed. The function may safely assume that  */
/* source and destination ranges do not overlap.                                 */

/*
#define VX1000_MEMCPY(D, S, L)         ___a_function_that_safely_copies_L_bytes_from_S_to_D(...);
*/



/* ----------------------------------------------------------------------------- */
/* If the application uses Autosar single pointer calibration via XCP, the       */
/* VX blindly sends all up- and download via mailbox to the application and it   */
/* is up to the application to inject the currently active address translation   */

/*
#define VX1000_SHORT_UPLOAD(D, S, L)   ___a_function_that_proprietarily_copies_L_bytes_from_S_to_D(...);
#define VX1000_SHORT_DOWNLOAD(D, S, L) ___a_function_that_proprietarily_copies_L_bytes_from_S_to_D(...);
*/


#if defined(VX1000_OVERLAY)

#if !defined(VX1000_OVERLAY_VX_CONFIGURABLE)

/* ----------------------------------------------------------------------------- */
/* As you did not provide configuration of the built-in overlay handling, you    */
/* must provide callbacks for manual handling the hardware and memory sections.  */
/* You probably may want to reuse the API of an XCP on CAN driver but as well    */
/* you may provide your very own implementation of all these callbacks:          */

#define VX1000_INIT_CAL_PAGE()                       ___a_function_that_initialises_the_calpage_handler();
#define VX1000_GET_CAL_PAGE(seg, mod)                ((VX1000_UINT8)___a_function_that_handles_XCP_get_calpage_command(...))
#define VX1000_SET_CAL_PAGE(seg, pag, mod, startup)  ((VX1000_UINT8)___a_function_that_handles_XCP_set_calpage_command(...))  /* note: the 4th parameter is only needed for FW >= 1.7 */
#define VX1000_COPY_CAL_PAGE(sseg, spag, dseg, dpag) ((VX1000_UINT8)___a_function_that_handles_XCP_copy_calpage_command(...))

#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE */


/* ----------------------------------------------------------------------------- */
/* If desired by the application, the driver may call hook functions in some     */
/* situations. Just define some of the following callback defines to let your    */
/* code be called                                                                */

/*
#define VX1000_OVL_RST_ON_CAL_WAKEUP_CB()                    ___a_void_function_with_userdefined_behaviour();
*/
/*
#define VX1000_SYNCAL_VALIDATE_WP_CB(addr)                   ___an_expression_or_function_whose_return_value_influences_the_behaviour_of_the_builtin_VX1000_SET_CAL_PAGE_function(...)
#define VX1000_SYNCAL_USRVALIDATE_WP_CB(value, mask, master) ___an_expression_or_function_whose_return_value_influences_the_behaviour_of_the_builtin_VX1000_SET_CAL_PAGE_function(...)
*/
#endif /* VX1000_OVERLAY */



#if defined(VX1000_FKL_SUPPORT_ADDR)
/* ----------------------------------------------------------------------------- */
/* Hint: must be a macro or an ASM function because it must not use stack OR     */
/* it may use stack but then VX1000_ENABLE_STANDARD_RAM_MAPPING() must ensure    */
/* that the used stack does not overlap with the FKL space by updating r3. If    */
/* you're really sure about a particular functionality being not needed for a    */
/* use-case you must explicitly define it empty and don't forget comments then.  */

#define VX1000_SERVE_WATCHDOG(x)           ___a_macro_that_serves_the_watchdog();
#define VX1000_DISABLE_ALL_INTERRUPTS()    ___a_function_that_prevents_any_context_switching_to_other_tasks_or_ISRs();
#define VX1000_STOP_OS_TIMING_PROTECTION() ___a_function_that_prevents_the_calling_process_being_killed_after_violating_its_time_budget();
#define VX1000_STOP_OTHER_CORES()          ___a_function_that_prevents_that_other_busmasters_write_to_RAM();
#define VX1000_ENABLE_STD_RAM_MAPPING()    ___a_function_that_disables_address_translation();

#endif /* VX1000_FKL_SUPPORT_ADDR */


#endif /* !VX1000_DISABLE_INSTRUMENTATION */



#if 0 /* --- template code start --- */
/*========================================================= */
/*                                                          */
/* Essential API of the VX1000 application driver           */
/*                                                          */
/*========================================================= */

/*--------------------------------------------------------- */
/* Initialize the global data needed for VX1000             */
/* Must be called after reset during initialisation         */
/* before any other VX1000_xxxx() routine is called !!      */
VX1000_INIT()

/*--------------------------------------------------------- */
/* Measurement data acquisition                             */
/* Trigger an universal event (OLDA) (0..30) with timestamp */
VX1000_EVENT(DaqEvent)

/*--------------------------------------------------------- */
/* Stimulation and Bypassing                                */
/* Stimulation control function                             */
/* Call this periodically in a low priority background task */
VX1000_STIM_CONTROL()

/*--------------------------------------------------------- */
/* Stimulation and Bypassing                                */
/* Check if stimulation for a stimulation event is turned   */
/* on (return !=0 true) and bypass. TimeOut is in ms        */
r = VX1000_BYPASS(DaqEvent, StimEvent, TimeOut);



/*========================================================= */
/*                                                          */
/* Code instrumentation example of a simple application     */
/*                                                          */
/*========================================================= */


/* Inclusion ===================================== */
/* Import the API of the VX1000 application driver */
#include "VX1000.h"

void main( void )
{
  /* Initialisation =================================== */
  /* Must be called before any other VX1000 API is used */
  VX1000_INIT()

  ...

  while (1)
  {
    ...
    if (task0 != 0)
    {
      ...

      /* Measurement =========================== */
      /* Trigger XCP measurement event number 0  */
      VX1000_EVENT(0)

      /* Bypassing =========================================================================== */
      /* Event number 2 is the bypass stimulation event, it indicates that                     */
      /* the ECU is now waiting for completion of the stimulation                              */
      /* Event number 1 is the bypass trigger event, it is used to trigger                     */
      /* calculation of the bypass in the tool, as long as the bypass is                       */
      /* not activated in the tool, this event is not executed                                 */
      /* 2000 is the timeout in ms, in case of timeout, the original code will not be executed */
      if (0 == VX1000_BYPASS(1, 2, 2000U))
      {
        /* ... this was the original code that is going to be bypassed. It is still executed   */
        /* in the cases when no VX is connected or no measurement is running ...               */
        out = function(in);
      }

      ...
    }
    /* Bypassing ============================================================================= */
    /* Call this macro cyclically outside of any bypassed code to enable and disable waiting   */
    /* for stimulation data at measurement start/stop                                          */
    VX1000_STIM_CONTROL()
  }
}

void task1(void)
{
  ...

  /* Measurement =============================== */
  /* Trigger XCP measurement event number 7      */
  VX1000_EVENT(7)

  ...
}

#endif /* --- template code stop --- */


#endif /* !VX1000_CFG_H (or any MEMMAP-part) */

