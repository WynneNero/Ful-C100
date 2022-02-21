/*------------------------------------------------------------------------------- */
/* VX1000.h                                                                       */
/* Vector VX1000 Application Driver for Renesas V850E2 and Renesas RH850          */
/* Version 3.00.03  21.01.2016                                                    */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* Don't modify this file, settings are defined in VX1000_cfg.h                   */
/*------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/  * required rule 2.2 "usage of c++ comments"                                                                             /
/     - violated because there exists no MISRA-conform variadic macro definition                                           /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 12.11 "wraparound in const unsigned int computation"                                                    /
/     - violated only in a preprocessor assertion                                                                          /
/                                                                                                                          /
/  * required rule 19.4 "complete statement inside a macro"                                                                /
/     - todo                                                                                                               /
/                                                                                                                          /
/  * advisory rule 19.7 "functions vs. macros"                                                                             /
/     - violated because a MISRA-conform workaround would induce configuration-dependent MISRA violations in user's code   /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.10 "macro parameter used without parentheses"                                                        /
/     - todo ( hint: a dummy-"##" might serve as a workaround... )                                                         /
/                                                                                                                          /
/------------------------------------------------------------------------------------------------------------------------ */

#if !defined(VX1000_H)
#define VX1000_H


/*------------------------------------------------------------------------------ */
/* Driver's version and status                                                   */

#define VX1000_FILE_VERSION_STATUS  (VX1000_ALPHA)  /* VX1000_RELEASED / VX1000_TESTED / VX1000_BETA / VX1000_ALPHA; a change does NOT force version increase */
#define VX1000_FILE_VERSION_MAJOR   3U   /* major version number (1..16); a change initially forces ALPHA status */
#define VX1000_FILE_VERSION_MINOR   0U   /* minor version number (0..99); a change initially forces BETA status  */
#define VX1000_FILE_VERSION_PATCH   3U   /* patch level (0..7); a change does NOT change VERSION_STATUS */

#define VX1000_FILE_VERSION ( ((((VX1000_FILE_VERSION_MAJOR) & 0xfU) << 12U) | (((VX1000_FILE_VERSION_MINOR) & 0x7fU) << 5U)) | (((VX1000_FILE_VERSION_STATUS) << 3U) | ((VX1000_FILE_VERSION_PATCH) & 0x7U)) )


/*------------------------------------------------------------------------------ */
/* data types                                                                    */
/* The user header must be able to provide callback prototypes with VX data types, therefore the types must be located before the header include */
typedef unsigned long  VX1000_UINT32; /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef unsigned short VX1000_UINT16; /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef unsigned char  VX1000_UINT8;  /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef signed long    VX1000_INT32;  /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef signed short   VX1000_INT16;  /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef signed char    VX1000_INT8;   /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef int            VX1000_INT;    /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef long           VX1000_LONG;   /* needed for "sizeof" expression */ /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef char           VX1000_CHAR;   /* used by strings, __date etc.; compile options may specify whether signed or not */ /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef float          VX1000_FLOAT;  /* needed for "sizeof" expression */ /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef double         VX1000_DOUBLE; /* needed for "sizeof" expression */ /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef long double    VX1000_LDOUBL; /* needed for "sizeof" expression */ /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef void (*VX1000_VVFUNCP_T)(void);                                    /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef void (*VX1000_VUFUNCP_T)(VX1000_UINT32);                           /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */


/*------------------------------------------------------------------------------ */
/* constants                                                                     */
#define VX1000_RELEASED                0x0U
#define VX1000_TESTED                  0x1U
#define VX1000_BETA                    0x2U
#define VX1000_ALPHA                   0x3U


/*------------------------------------------------------------------------------ */
/* Configuration                                                                 */

/* Include user specified defines and fetch prototypes of user callbacks (has to be done before switching sections) */
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */

#if !defined(VX1000_TARGET_X850)
#error This driver is not meant for the target that you are trying to use it for!
#endif /* !VX1000_TARGET_X850 */

/* no 64bit integer data type known on V850 ... */

#if !defined(VX1000_DUMMYREAD)
#define VX1000_DUMMYREAD(X)            /* empty */
#endif /* !VX1000_DUMMYREAD */

#if !defined(VX1000_DISCARD4DUMMYARGS)
#define VX1000_DISCARD4DUMMYARGS(T, R, A1, A2, A3, A4)  (R)
#endif /* !VX1000_DISCARD4DUMMYARGS */


#if !defined(VX1000_DISABLE_INSTRUMENTATION)
/*------------------------------------------------------------------------------ */
/* optional forced special linkage                                               */

/* include user-defined lines with optional section pragmas to force individual linkage of VX1000 code and/or data: */
#define VX1000_BEGSECT_VXMODULE_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_BEGSECT_VXMODULE_H_UNDO
#endif /* !VX1000_DISABLE_INSTRUMENTATION */


#if defined(VX1000_COMPILED_FOR_SLAVECORES)
/* On multi-core systems with different instruction sets, the same function must exist multiple times, so add suffixes: */
#define VX1000_SUFFU3(F,S) F ## _ ## S /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#define VX1000_SUFFU2(F,S) VX1000_SUFFU3(F,S) /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#define VX1000_SUFFUN(F) VX1000_SUFFU2(F,VX1000_COMPILED_FOR_SLAVECORES)  /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#else /* !VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_SUFFUN(F) F /* direct mapping */ /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */


/*------------------------------------------------------------------------------ */
/* VX1000 default parameters                                                     */

#if !defined(VX1000_ENTER_SPINLOCK)
#define VX1000_ENTER_SPINLOCK()
#endif /* !VX1000_ENTER_SPINLOCK */
#if !defined(VX1000_LEAVE_SPINLOCK)
#define VX1000_LEAVE_SPINLOCK()
#endif /* !VX1000_LEAVE_SPINLOCK */
#if !defined(VX1000_ATOMIC_XOR32)
#define VX1000_ATOMIC_XOR32(A, D)                           \
  VX1000_ENTER_SPINLOCK()                                   \
  ((volatile VX1000_UINT32*)(volatile void*)(A))[0] ^= (D); \
  VX1000_LEAVE_SPINLOCK() /* note: VX1000_ATOMIC_XOR32 is never "called" by the user and VX code ensures that it is always braced by the caller where due, so no bracing here */
#endif /* !VX1000_ATOMIC_XOR32 */
#if !defined(VX1000_ATOMIC_XOR32X2)
#define VX1000_ATOMIC_XOR32X2(A, D)                         \
  VX1000_ENTER_SPINLOCK()                                   \
  ((volatile VX1000_UINT32*)(volatile void*)(A))[0] ^= (D); \
  ((volatile VX1000_UINT32*)(volatile void*)(A))[1] ^= (D); \
  VX1000_LEAVE_SPINLOCK() /* note: VX1000_ATOMIC_XOR32X2 is never "called" by the user and VX code ensures that it is always braced by the caller where due, so no bracing here */
#endif /* !VX1000_ATOMIC_XOR32X2 */

#if !defined(VX1000_ATOMIC_AND32)
#define VX1000_ATOMIC_AND32(A, D)                           \
  VX1000_ENTER_SPINLOCK()                                   \
  ((volatile VX1000_UINT32*)(volatile void*)(A))[0] &= (D); \
  VX1000_LEAVE_SPINLOCK() /* note: VX1000_ATOMIC_AND32 is never "called" by the user and VX code ensures that it is always braced by the caller where due, so no bracing here */
#endif /* !VX1000_ATOMIC_AND32 */

#if !defined(VX1000_ATOMIC_OR32)
#define VX1000_ATOMIC_OR32(A, D)                            \
  VX1000_ENTER_SPINLOCK()                                   \
  ((volatile VX1000_UINT32*)(volatile void*)(A))[0] |= (D); \
  VX1000_LEAVE_SPINLOCK() /* note: VX1000_ATOMIC_OR32 is never "called" by the user and VX code ensures that it is always braced by the caller where due, so no bracing here */
#endif /* !VX1000_ATOMIC_OR32 */

#if !defined(VX1000_MAILBOX_SLOT_DWORDS)
#define VX1000_MAILBOX_SLOT_DWORDS     (1UL + 2UL) /* must be at least 3 (=4 bytes size info + 8 bytes payload (=XCP command)) */
#endif /* !VX1000_MAILBOX_SLOT_DWORDS */
#if !defined(VX1000_MAILBOX_SLOTS)
#define VX1000_MAILBOX_SLOTS           8U
#endif /* !VX1000_MAILBOX_SLOTS */

#if !defined(VX1000_OLDA_HIPRIOMASK)
#define VX1000_OLDA_HIPRIOMASK         0UL
#endif /* !VX1000_OLDA_HIPRIOMASK */

#if !defined(VX1000_IS_BYPASS_RESUME_ALLOWED)
#define VX1000_IS_BYPASS_RESUME_ALLOWED() 0
#endif /* VX1000_IS_BYPASS_RESUME_ALLOWED */

#if (!defined(VX1000_OLDA_FORCE_V6)) && (!defined(VX1000_OLDA_FORCE_V7)) && (!defined(VX1000_OLDA_FORCE_V8))
#define VX1000_OLDA_FORCE_V7
#endif /* !VX1000_OLDA_FORCE_V6 && !VX1000_OLDA_FORCE_V7 && !VX1000_OLDA_FORCE_V8 */

#if !defined(VX1000_OVERLAY_PHYSADDR)
#define VX1000_OVERLAY_PHYSADDR        VX1000_OVERLAY_ADDR
#endif /* !VX1000_OVERLAY_PHYSADDR */

#if !defined(VX1000_CALRAM_PHYSADDR)
#define VX1000_CALRAM_PHYSADDR         VX1000_CALRAM_ADDR
#endif /* !VX1000_CALRAM_PHYSADDR */

#if !defined(VX1000_ERRLOG_SIZE)
#define VX1000_ERRLOG_SIZE             0
#endif /* !VX1000_ERRLOG_SIZE */


#if defined(VX1000_CLOCK_TICKS_PER_BASE)

#if (!defined(VX1000_CLOCK_TICKS_BASE_NS)) && (!defined(VX1000_DISABLE_INSTRUMENTATION))
#error Please define VX1000_CLOCK_TICKS_BASE_NS as the time bas in ns during which VX1000_CLOCK_TICKS_PER_BASE ticks occur
#endif /* !VX1000_CLOCK_TICKS_BASE_NS && !VX1000_DISABLE_INSTRUMENTATION */

#else /* !VX1000_CLOCK_TICKS_PER_BASE */

#if defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_BASE_NS     1000000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_BASE_NS     1000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_BASE_NS     1000UL
#elif !defined(VX1000_DISABLE_INSTRUMENTATION)
#error Please define VX1000_CLOCK_TICKS_PER_US or VX1000_CLOCK_TICKS_PER_MS or VX1000_CLOCK_TICKS_PER_S
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_CLOCK_TICKS_PER_BASE */

#if !defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_S       ((1000000000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_S */

#if !defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_MS      ((1000000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_MS */

#if !defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_US      ((1000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_US */

#if !defined(VX1000_CLOCK_TIMER_SIZE)
#define VX1000_CLOCK_TIMER_SIZE        32 /* legacy mode of VX1000_CLOCK() */
#endif /* !VX1000_CLOCK_TIMER_SIZE */

#if !defined(VX1000_CLOCK_TIMER_ADDR)
#define VX1000_CLOCK_TIMER_ADDR        0UL /* turns the synchronisation feature off */
#endif /* !VX1000_CLOCK_TIMER_ADDR */

/* Default timeouts for VX detection in us and cold start initialization in ms */
#if !defined(VX1000_DETECTION_TIMEOUT_US)
#define VX1000_DETECTION_TIMEOUT_US    50UL
#endif /* !VX1000_DETECTION_TIMEOUT_US */
#if !defined(VX1000_COLDSTART_TIMEOUT_MS)
#define VX1000_COLDSTART_TIMEOUT_MS    20UL
#endif /* !VX1000_COLDSTART_TIMEOUT_MS */


/*------------------------------------------------------------------------------ */
/* Defines                                                                       */

#if defined(VX1000_DISABLE_INSTRUMENTATION)

#define VX1000_STORE_TIMESTAMP(t)    /*VX1000_DUMMYREAD((t))*/
#define VX1000_STORE_EVENT(e)        /*VX1000_DUMMYREAD((e))*/

#else /* !VX1000_DISABLE_INSTRUMENTATION */

/* Store the time t into gVX1000.EventTimestamp (use all 32bit -- is only avoided in VX1000_FAST_TRACE_EVENT.  */
#define VX1000_STORE_TIMESTAMP(t) gVX1000.EventTimestamp = (t);

/* Store the event ID e into gVX1000.EventNumber (use all 32bit -- is only avoided in VX1000_FAST_TRACE_EVENT. */
#define VX1000_STORE_EVENT(e) gVX1000.EventNumber = (e);
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* Special Events */
#define VX1000_EVENT_RAMZERO_START     0x00010000UL
#define VX1000_EVENT_RAMZERO_DONE      0x00010001UL
#define VX1000_EVENT_RAMSYNC_START     0x00010002UL
#define VX1000_EVENT_MAILBOX_INIT      0x00020000UL
#define VX1000_EVENT_MAILBOX_UPDATE    0x00020001UL
#define VX1000_EVENT_MAILBOX_RESETREQ  0x00020002UL
#define VX1000_EVENT_STIM_INIT         0x00030100UL
#define VX1000_EVENT_STIM_ACK          0x00030101UL
#define VX1000_EVENT_STIM_TIMEOUT(e)  (0x00030200UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STIM_ERR(e)      (0x00030300UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STRUCT_INIT       0x00040000UL
#define VX1000_EVENT_GP(e)            (0x00050000UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_ECU_EVT_SW_RESET        VX1000_EVENT_GP(0x00000001UL)
#define VX1000_ECU_EVT_OLDA_OVERLOAD   VX1000_EVENT_GP(0x00000002UL)
#define VX1000_ECU_EVT_SW_RESET_FAIL   VX1000_EVENT_GP(0x00000003UL)
#define VX1000_ECU_EVT_SW_RESET_PREP   VX1000_EVENT_GP(0x00000004UL)
#define VX1000_ECU_EVT_STIM_SKIP(e)   (VX1000_EVENT_GP(0x00008000UL) | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */

/*------------------------------------------------------------------------------ */
/* Check the configuration for plausibility                                      */
#if !defined(VX1000_DISABLE_INSTRUMENTATION)

#if ((VX1000_CLOCK_TIMER_SIZE != 0) && (VX1000_CLOCK_TIMER_SIZE != 16)) && ((VX1000_CLOCK_TIMER_SIZE != 24) && (VX1000_CLOCK_TIMER_SIZE != 32))
#error VX1000_CLOCK_TIMER_SIZE supports only these values: 0, 16, 24, 32! (you may round down to gain a valid configuration)
#endif /* VX1000_CLOCK_TIMER_SIZE */

#if defined(VX1000_OLDA_FORCE_V6) && defined(VX1000_OLDA_FORCE_V7)
#error VX1000_OLDA_FORCE_V6 and VX1000_OLDA_FORCE_V7 cannot be enabled at the same time. Please make up your mind!
#endif /* VX1000_OLDA_FORCE_V6 && VX1000_OLDA_FORCE_V7 */

#if defined(VX1000_OLDA_FORCE_V6) && defined(VX1000_OLDA_FORCE_V8)
#error VX1000_OLDA_FORCE_V6 and VX1000_OLDA_FORCE_V8 cannot be enabled at the same time. Please make up your mind!
#endif /* VX1000_OLDA_FORCE_V6 && VX1000_OLDA_FORCE_V8 */

#if defined(VX1000_OLDA_FORCE_V7) && defined(VX1000_OLDA_FORCE_V8)
#error VX1000_OLDA_FORCE_V7 and VX1000_OLDA_FORCE_V8 cannot be enabled at the same time. Please make up your mind!
#endif /* VX1000_OLDA_FORCE_V7 && VX1000_OLDA_FORCE_V8 */

#if defined(VX1000_STIM_BY_OLDA) && (!defined(VX1000_OLDA))
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_OLDA is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_OLDA */

#if defined(VX1000_STIM_BY_OLDA) && (!defined(VX1000_STIM))
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_STIM is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_STIM */

/* To save memory, the number range for stim events may be reduced, maximum is 31  */
#if !defined(VX1000_STIM_EVENT_COUNT)
#define VX1000_STIM_EVENT_COUNT 31   /* Count of STIM events used starting from VX1000_STIM_EVENT_OFFSET */
#elif VX1000_STIM_EVENT_COUNT > 31
#error "VX1000_STIM_EVENT_COUNT must be <= 31"
#endif /* VX1000_STIM_EVENT_COUNT && VX1000_STIM_EVENT_COUNT > 31*/

#if !defined(VX1000_STIM_EVENT_OFFSET)
#define VX1000_STIM_EVENT_OFFSET 0U   /* Number of the first STIM event */
#elif (VX1000_STIM_EVENT_OFFSET > 30)
#error "Event numbers must be <= 30!"
#endif /* VX1000_STIM_EVENT_OFFSET && VX1000_STIM_EVENT_OFFSET > 30 */

#if !defined(VX1000_OLDA_EVENT_COUNT)
#define VX1000_OLDA_EVENT_COUNT 31U
#elif VX1000_OLDA_EVENT_COUNT > 31U
#error "VX1000_OLDA_EVENT_COUNT must be <= 31U!"
#endif /* VX1000_OLDA_EVENT_COUNT && VX1000_OLDA_EVENT_COUNT > 31 */

#if (defined(VX1000_SUPPORT_OLDA8CMD_CP64N) && defined(VX1000_OLDA_FORCE_V8)) && (!defined(VX1000_UINT64))
#error VX1000_SUPPORT_OLDA8CMD_CP64N cannot be enabled while VX1000_UINT64 is not provided!
#endif /* VX1000_SUPPORT_OLDA8CMD_CP64N && VX1000_OLDA_FORCE_V8 && !VX1000_UINT64 */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_STIM_BY_OLDA))
#error VX1000_HOOK_BASED_BYPASSING cannot be enabled while VX1000_STIM_BY_OLDA is disabled!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_STIM_BY_OLDA */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_BYPASS_HBB_LUT_ENTRIES))
#error VX1000_BYPASS_HBB_LUT_ENTRIES must be defined to a value >0 if VX1000_HOOK_BASED_BYPASSING shall be used!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_BYPASS_HBB_LUT_ENTRIES */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_BYPASS_HBB_LUT_ADDR))
#error VX1000_BYPASS_HBB_LUT_ADDR must be defined if VX1000_HOOK_BASED_BYPASSING shall be used!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_BYPASS_HBB_LUT_ADDR */

#if defined(VX1000_HOOK_BASED_BYPASSING) && (!defined(VX1000_STIM_FORCE_V1))
#error VX1000_HOOK_BASED_BYPASSING cannot be enabled while VX1000_STIM_FORCE_V1 is disabled!
#endif /* VX1000_HOOK_BASED_BYPASSING && !VX1000_STIM_FORCE_V1 */

#if defined(VX1000_BYPASS_ALL_CHANS_STIMD) && (!defined(VX1000_STIM_FORCE_V1))
#error VX1000_BYPASS_ALL_CHANS_STIMD cannot be enabled while VX1000_STIM_FORCE_V1 is disabled!
#endif /* VX1000_BYPASS_ALL_CHANS_STIMD && !VX1000_STIM_FORCE_V1 */

#if defined(VX1000_STIM_FORCE_V1) && (!defined(VX1000_SET_STIM_INFO))
#error VX1000_SET_STIM_INFO() must be defined properly when VX1000_STIM_FORCE_V1 is enabled!
#endif /* VX1000_STIM_FORCE_V1 && !VX1000_SET_STIM_INFO */

#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
#if defined(VX1000_HOOK_ENABLE) && (!defined(VX1000_HOOK_COUNT))
#error VX1000_HOOK_COUNT must be also defined when VX1000_HOOK_ENABLE is enabled!
#endif /* VX1000_HOOK_ENABLE && !VX1000_HOOK_COUNT */

#if defined(VX1000_HOOK_COUNT)
#if (VX1000_HOOK_COUNT > 255) || (VX1000_HOOK_COUNT == 0)
#error VX1000_HOOK_COUNT must be defined in the range [1..255]
#endif /* RANGE(VX1000_HOOK_COUNT) */
#endif /* VX1000_HOOK_COUNT */
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */

#if defined(VX1000_OVERLAY)

#if (defined(VX1000_INIT_CAL_PAGE) && defined(VX1000_GET_CAL_PAGE)) && (defined(VX1000_SET_CAL_PAGE) && defined(VX1000_COPY_CAL_PAGE))
#define VX1000_OVERLAY_USERMANAGED
#endif /* VX1000_INIT_CAL_PAGE && VX1000_GET_CAL_PAGE && VX1000_SET_CAL_PAGE && VX1000_COPY_CAL_PAGE */

#if defined(VX1000_OVERLAY_VX_CONFIGURABLE) && (defined(VX1000_OVERLAY_USERMANAGED))
#error VX1000_xxx_CAL_PAGE() user callbacks will NOT be executed because VX1000_OVERLAY_VX_CONFIGURABLE is enabled
#endif /* VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVERLAY_USERMANAGED */

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))
#error To use VX1000_OVERLAY, configure VX1000_OVERLAY_VX_CONFIGURABLE or all VX1000_xxx_CAL_PAGE() macros in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#if (!defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (!defined(VX1000_OVERLAY_USERMANAGED))

/* check completeness of the common settings */
#if ((!defined(VX1000_OVERLAY_ADDR)) || (!defined(VX1000_OVERLAY_SIZE)) || (!defined(VX1000_CALRAM_ADDR)) )
#error Please define the overlay parameters VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR and VX1000_CALRAM_ADDR in VX1000_cfg.h !
#endif /* !VX1000_OVERLAY_ADDR | !VX1000_OVERLAY_SIZE | !VX1000_CALRAM_ADDR */

#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */

#endif /* VX1000_OVERLAY */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVLENBL_VALIDATE_PAGESW))
#error VX1000_OVLENBL_USE_VX_EPK_TRANS cannot be enabled while VX1000_OVLENBL_VALIDATE_PAGESW is disabled!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVLENBL_VALIDATE_PAGESW */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_SYNCAL_VALIDATE_WP_CB))
#error VX1000_SYNCAL_VALIDATE_WP_CB must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVLENBL_USE_VX_EPK_TRANS */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVL_EPK_REFPAGE_ADDR))
#error VX1000_OVL_EPK_REFPAGE_ADDR must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVL_EPK_REFPAGE_ADDR */

#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS) && (!defined(VX1000_OVL_EPK_LENGTH))
#error VX1000_OVL_EPK_LENGTH must be configured to be able to use the EPK translation!
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS & !VX1000_OVL_EPK_LENGTH */

#if defined(VX1000_OVLENBL_VALIDATE_PAGESW) && (!(defined(VX1000_SYNCAL_USRVALIDATE_WP_CB) || defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)))
#error VX1000_OVLENBL_VALIDATE_PAGESW cannot be enabled while neither VX1000_SYNCAL_USRVALIDATE_WP_CB nor EPK translation are configured!
#endif /* VX1000_OVLENBL_VALIDATE_PAGESW & !VX1000_SYNCAL_USRVALIDATE_WP_CB & !VX1000_OVLENBL_USE_VX_EPK_TRANS */

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) && (!defined(VX1000_OVL_CAL_BUS_MASTER))
#error VX1000_OVLENBL_CORE_SYNC_PAGESW cannot be enabled while VX1000_OVL_CAL_BUS_MASTER is not configured!
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW & !VX1000_OVL_CAL_BUS_MASTER */

#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH) && (!defined(VX1000_OVL_CAL_BUS_MASTER))
#error VX1000_OVLENBL_SYNC_PAGESWITCH cannot be enabled while VX1000_OVL_CAL_BUS_MASTER is not configured!
#endif /* VX1000_OVLENBL_SYNC_PAGESWITCH & !VX1000_OVL_CAL_BUS_MASTER */

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) && (!defined(VX1000_OVLENBL_SYNC_PAGESWITCH))
#error VX1000_OVLENBL_CORE_SYNC_PAGESW cannot be used without VX1000_OVLENBL_SYNC_PAGESWITCH!
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW & !VX1000_OVLENBL_SYNC_PAGESWITCH */

#if defined(VX1000_OVLENBL_RST_ON_CALWAKEUP) && (!defined(VX1000_OVL_RST_ON_CAL_WAKEUP_CB))
#error VX1000_OVL_RST_ON_CAL_WAKEUP_CB() must be configured because VX1000_OVLENBL_RST_ON_CALWAKEUP is enabled!
#endif /* VX1000_OVLENBL_RST_ON_CALWAKEUP & !VX1000_OVL_RST_ON_CAL_WAKEUP_CB */

#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#if (VX1000_MAILBOX_SLOT_DWORDS) < 3U
#error VX1000_MAILBOX_SLOT_DWORDS must be at least 3 ! /* 4 bytes + 8 bytes xcp command = 12bytes = 3 dwords */
#endif /* VX1000_MAILBOX_SLOT_DWORDS */
#if (VX1000_MAILBOX_SLOTS < 1) || (((VX1000_MAILBOX_SLOTS) & ((VX1000_MAILBOX_SLOTS) - 1)) != 0)
#error VX1000_MAILBOX_SLOTS must be a power of 2 !
#endif /* VX1000_MAILBOX_SLOTS */
#endif /* VX1000_MAILBOX & ! VX1000_COMPILED_FOR_SLAVECORES */

#if (defined(VX1000_DETECTION) && defined(VX1000_OLDA)) && (defined(VX1000_OLDA_FORCE_V6))
/* The coldstart settings in VxConfig lack the "SwapValue" field, therefore VX can only handle address encodings that are not based on swapValue -> only v7 encoding possible */
#error Coldstart/VX1000Detection is incompatible to olda v6 --> either disable VX1000_DETECTION or VX1000_OLDA_FORCE_V6!
#endif /* VX1000_DETECTION && VX1000_OLDA_FORCE_V6 */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* States */

/* ToolDetectState */
#define VX1000_TDS_INIT                  0x00000001UL    /* VX1000_INIT() has been called */
#define VX1000_TDS_DETECT                0x00000002UL    /* VX1000_DETECT_VX() has been called */
#define VX1000_TDS_DETECTED              0x00000004UL    /* VX1000 was detected by VX1000_DETECT_VX() */
#define VX1000_TDS_COLDSTART_DELAY_REQ   0x00000008UL    /* Coldstart delay request has been accepted by VX */
#define VX1000_TDS_COLDSTART_DONE        0x00000010UL    /* Coldstart handshake successfully executed */
#define VX1000_TDS_COLDSTART_TIMEOUT     0x00000020UL    /* Coldstart handshake resulted in timeout */
#define VX1000_TDS_COLDSTART_DELAY       0x00000040UL    /* Coldstart Delay has been entered */
#define VX1000_TDS_APPRST                0x00000080UL    /* Resume after application reset done */
#define VX1000_TDS_FKL_REQ_DETECTED      0x00000100UL    /* FlashPrepare request detected: trying to handle it */
#define VX1000_TDS_FKL_REQ_IGNORED       0x00000200UL    /* FlashPrepare request could not be served right now; app still runs */
#define VX1000_TDS_FKL_FORCED_IDLE       0x00000400UL    /* request served: ECU stays idle; FKL can be downloaded by the tool; */
                                                         /* gVX1000.MagicId contains a pointer to the new communication space. */
#define VX1000_TDS_DETECT_DONE           0x00000800UL    /* VX1000 Tooldetection sequence finished */
#define VX1000_TDS_ERROR                 0x00001000UL    /* VX1000_INIT() detected a misconfiguration */
#define VX1000_TDS_VX_ACCESS_DISABLED    0x00002000UL    /* The VX has NO access to the ECU, another tool is connected */
#define VX1000_TDS_WORKING_PAGE          0x00004000UL    /* 0: ECU is on reference page / 1: ECU is on working page */

#define VX1000_TDS_COLDSTART_CHS_BUSY    0x00010000UL    /* Coldstart checksum calculation ongoing */
#define VX1000_TDS_COLDSTART_CHS_DONE    0x00020000UL    /* Coldstart checksum calculation done */

#define VX1000_TDS_NO_BYP_RESUME         0x00040000UL    /* Inform VX1000 not to resume VX bypassing */

/* ToolCtrlState */
#define VX1000_TCS_PRESENT               0x00000001UL    /* VX1000 is present */
#define VX1000_TCS_COLDSTART_DELAY       0x00000002UL    /* VX1000 requests coldstart delay */
#define VX1000_TCS_COLDSTART_DONE        0x00000004UL    /* VX1000 coldstart configuration done */
#define VX1000_TCS_FKL_REQUEST           0x00000008UL    /* VX1000 requests the appl to go idle and prepare to jump to a pointer */
#define VX1000_TCS_SOFTRESET_PREP        0x00000010UL    /* VX1000 acknowledges a soft-reset announcement */
#define VX1000_TCS_SWITCH_TO_WP          0x00000020UL    /* Tell the ECU to switch to WP */
#define VX1000_TCS_CAL_WAKEUP            0x00000040UL    /* The VX1000 has woken up the ECU */
#define VX1000_TCS_SKIP_WP_INIT          0x00000080UL    /* Inform the ECU that the WP's RAM content is still intact */

/*------------------------------------------------------------------------------ */
/* VX1000 Detection                                                              */

#if defined(VX1000_DETECTION) || (defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_DISABLE_INSTRUMENTATION)))
/* Check whether a VX1000 was already detected by VX1000_DETECT_VX() */
/*#define VX1000_DETECTED()   ((gVX1000.ToolCtrlState  & (VX1000_TDS_DETECTED)) != 0) //really "Ctrl & TDS"? and not #define VX1000_DETECTED() ((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0)*/
#define VX1000_DETECTED() (((gVX1000.ToolCtrlState & (VX1000_TCS_PRESENT)) != 0UL) || ((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0UL))
#else /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE | VX1000_DISABLE_INSTRUMENTATION */
#define VX1000_DETECTED()                (0)             /* means "no VX detected" */
#endif /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE | VX1000_DISABLE_INSTRUMENTATION */


/*------------------------------------------------------------------------------ */
/* Coldstart                                                                     */

#define VX1000_COLDSTART_CHS_MAGIC 0xFEC70A09UL
#if (defined(VX1000_DETECTION) || (defined(VX1000_TARGET_TRICORE) && (!defined(VX1000_DISABLE_INSTRUMENTATION)))) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
extern volatile VX1000_UINT32 gVX1000_DETECT_StartTime;
#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
extern volatile VX1000_UINT32 gVX1000_DETECT_StartTimeAsyncEnd, gVX1000_DETECT_ToolDetectTime, gVX1000_DETECT_ChecksumDoneTime, gVX1000_DETECT_EndTimeAsyncStart, gVX1000_DETECT_EndTime;
#define VX1000_COLDSTART_BENCHMARK_DATA volatile VX1000_UINT32 gVX1000_DETECT_StartTime, gVX1000_DETECT_StartTimeAsyncEnd, gVX1000_DETECT_ToolDetectTime, gVX1000_DETECT_ChecksumDoneTime, gVX1000_DETECT_EndTimeAsyncStart, gVX1000_DETECT_EndTime;
#else /* !VX1000_COLDSTART_BENCHMARK || !VX1000_OLDA*/
#define VX1000_COLDSTART_BENCHMARK_DATA volatile VX1000_UINT32 gVX1000_DETECT_StartTime;
#endif /* !VX1000_COLDSTART_BENCHMARK || !VX1000_OLDA*/
#else  /* (!VX1000_DETECTION & !VX1000_TARGET_TRICORE) | VX1000_DISABLE_INSTRUMENTATION | VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_COLDSTART_BENCHMARK_DATA /* empty */
#endif /* (!VX1000_DETECTION & !VX1000_TARGET_TRICORE) | VX1000_DISABLE_INSTRUMENTATION | VX1000_COMPILED_FOR_SLAVECORES */


/*------------------------------------------------------------------------------ */
/* Flash kernel download support                                                 */
#if defined(VX1000_FKL_SUPPORT_ADDR)
extern void VX1000_SUFFUN(vx1000_FlashPrepareLoop)(void);
#define VX1000_DETECT_FKL_REQUESTS()                                                                                          \
  if ((gVX1000.MagicId == (VX1000_UINT32)(VX1000_STRUCT_MAGIC)) && ((gVX1000.ToolCtrlState & (VX1000_TCS_FKL_REQUEST)) != 0)) \
  {                                                                                                                           \
    VX1000_SUFFUN(vx1000_FlashPrepareLoop)();                                                                                 \
  }

typedef void VX1000_FKL_FCT(VX1000_UINT32, VX1000_UINT32, VX1000_UINT32); /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
typedef struct
{
  VX1000_UINT16 DeprotectTrigger;        /*  0+ */
  VX1000_UINT16 DeprotectState;          /*  2+ */
  VX1000_UINT32 TransitionTimeout;       /*  4+ */
  VX1000_UINT32 WdgData1;                /*  8+ */
  VX1000_UINT32 WdgData2;                /* 12+ */
  VX1000_UINT32 WdgData3_FklParam3;      /* 16+ , it depends on the platform whether the watchdog handler or the kernel needs more parameters */
  VX1000_UINT32 FklParam1;               /* 20+ */
  VX1000_FKL_FCT *EntryPoint;            /* 24+ */
  VX1000_UINT32 FklParam2;               /* 28+ */
} VX1000_FKL_WORKSPACE_T;                /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
#define VX1000_FKL_WORKSPACE             ((VX1000_FKL_WORKSPACE_T*)(void*)(0xFFFFffe0UL & (VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR)))
#define VX1000_FKL_TRANSITION_TIMEOUT    0xffffffffUL
#define VX1000_FKL_STATE1CODE            0x1243U
#define VX1000_FKL_STATE2CODE            0x2486U
#define VX1000_FKL_STATE3CODE            0x36c9U
#define VX1000_FKL_STATE4CODE            0x480cU
#define VX1000_FKL_STATE5CODE            0x5a4fU
#define VX1000_FKL_TOSTATE1CODE          0x6bf0U
#define VX1000_FKL_TOSTATE2CODE          0x7a0fU
#define VX1000_FKL_TOSTATE3CODE          0x891eU
#define VX1000_FKL_TOSTATE4CODE          0x98e1U
#define VX1000_FKL_TOSTATE5CODE          0xa72dU
#define VX1000_FKL_LAUNCHCODE            0xb6d2U
#else  /* !VX1000_FKL_SUPPORT_ADDR */
#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_DETECT_FKL_REQUESTS()   /* empty */
#else /* !VX1000_DISABLE_INSTRUMENTATION)*/
#define VX1000_DETECT_FKL_REQUESTS()                                                           \
  if ((gVX1000.ToolCtrlState & (VX1000_TCS_FKL_REQUEST)) != 0)                                 \
  {                                                                                            \
    gVX1000.ToolDetectState |= (VX1000_TDS_FKL_REQ_DETECTED) | (VX1000_TDS_FKL_REQ_IGNORED);   \
  }
#endif /* !VX1000_DISABLE_INSTRUMENTATION */
#endif /* !VX1000_FKL_SUPPORT_ADDR */


/*------------------------------------------------------------------------------ */
/* VX1000 Mailbox                                                                */

#define VX1000_MAILBOX_OK              0UL
#define VX1000_MAILBOX_ERR_FULL        1UL
#define VX1000_MAILBOX_ERR_EMPTY       2UL
#define VX1000_MAILBOX_ERR_INDICES     3UL
#define VX1000_MAILBOX_ERR_SEQUENCE    4UL
#define VX1000_MAILBOX_ERR_SIZE        5UL
#define VX1000_MAILBOX_SLOT_RSVD       6UL
#define VX1000_MAILBOX_ERR_NULL        7UL
#define VX1000_MAILBOX_ERR_SPLIT_PEND  8UL

#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))

#define VX1000_MAILBOX_MAGIC           0xFEC70A06UL
#define VX1000_MAILBOX_FREE_WR_SLOTS   (((VX1000_UINT8)(gVX1000.Mailbox.SM_ReadIdx-gVX1000.Mailbox.SM_WriteIdx-1)) & ((VX1000_MAILBOX_SLOTS)-1U))
#define VX1000_MAILBOX_USED_RD_SLOTS   (((VX1000_UINT32)(gVX1000.Mailbox.MS_WriteIdx - gVX1000.Mailbox.MS_ReadIdx)) & ((VX1000_MAILBOX_SLOTS) - 1U))
#define VX1000_MAILBOX_NEXT(idx)       (((idx) + 1U) & ((VX1000_MAILBOX_SLOTS) - 1U))  /* PRQA S 3453 */ /* Accepting violation of MISRA Rule 19.7 because a function call would consume unnecessarily high resources */

typedef struct
{
  VX1000_UINT32  MagicId;                                                  /* 0x00 */
  VX1000_UINT32  Version;                                                  /* 0x04 */
  VX1000_UINT16  SlotSize;                                                 /* 0x08 */
  VX1000_UINT8   MS_Slots;                                                 /* 0x0A */
  VX1000_UINT8   SM_Slots;                                                 /* 0x0B */
  VX1000_UINT32  MS_Ptr;                                                   /* 0x0C */
  VX1000_UINT32  SM_Ptr;                                                   /* 0x10 */
  VX1000_UINT8   MS_ReadIdx;                                               /* 0x14 */
  VX1000_UINT8   MS_WriteIdx;                                              /* 0x15 */
  VX1000_UINT8   SM_ReadIdx;                                               /* 0x16 */
  VX1000_UINT8   SM_WriteIdx;                                              /* 0x17 */
  VX1000_UINT16  RstReq;                                                   /* 0x18 */
  VX1000_UINT16  RstAck;                                                   /* 0x1A */
  VX1000_UINT32  MSData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS]; /* 0x1C */
  VX1000_UINT32  SMData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS]; /* no fix offset */
} VX1000_MAILBOX_T;

#define VX1000_CRC_CMD_UNKNOWN         0x20U
#define VX1000_CRC_CMD_BUSY            0x10U
#define VX1000_CRC_CMD_SYNTAX          0x21U
#define VX1000_CRC_OUT_OF_RANGE        0x22U
#define VX1000_CRC_WRITE_PROTECTED     0x23U
#define VX1000_CRC_ACCESS_DENIED       0x24U
#define VX1000_CRC_ACCESS_LOCKED       0x25U
#define VX1000_CRC_PAGE_NOT_VALID      0x26U
#define VX1000_CRC_PAGE_MODE_NOT_VALID 0x27U
#define VX1000_CRC_SEGMENT_NOT_VALID   0x28U

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
#define VX1000_CAL_ECU                 0x01U
#define VX1000_CAL_XCP                 0x02U
#define VX1000_CAL_ALL                 0x80U
#endif /* VX1000_OVERLAY_CONTROL */

extern void VX1000_SUFFUN(vx1000_MailboxInit)(void);
#define VX1000_MAILBOX_INIT() VX1000_SUFFUN(vx1000_MailboxInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)
extern void VX1000_SUFFUN(vx1000_MailboxHandler)(void);
#define VX1000_MAILBOX_CONTROL() VX1000_SUFFUN(vx1000_MailboxHandler)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX_OVERLAY_CONTROL & !VX1000_MAILBOX_FLASH */
#define VX1000_MAILBOX_CONTROL() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX_OVERLAY_CONTROL & !VX1000_MAILBOX_FLASH */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWrite)(VX1000_UINT32 len, const VX1000_CHAR* pBuf);
#define VX1000_MAILBOX_WRITE(     L, B)       VX1000_SUFFUN(vx1000_MailboxWrite)((L), (const VX1000_CHAR*)(B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxWrite)((L), (const VX1000_CHAR*)(B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxRead)(VX1000_UINT32* pLen, VX1000_CHAR* pBuf);
#define VX1000_MAILBOX_READ(     L, B)       VX1000_SUFFUN(vx1000_MailboxRead)((L), (B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxRead)((L), (B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_DATA VX1000_MAILBOX_T Mailbox;
#define VX1000_MAILBOX_PTR ((VX1000_UINT32)&gVX1000.Mailbox)

#else /* !VX1000_MAILBOX | VX1000_COMPILED_FOR_SLAVECORES */

#define VX1000_MAILBOX_INIT() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_CONTROL() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE(     L, B) VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (L),((const VX1000_CHAR*)(B)-(const VX1000_CHAR*)(0)),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_WRITE_VOID(L, B) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), (L),((const VX1000_CHAR*)(B)-(const VX1000_CHAR*)(0)),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_READ(     L, B)  VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ((VX1000_UINT32*)(L)-(VX1000_UINT32*)(0)),((VX1000_CHAR*)(B)-(VX1000_CHAR*)(0)),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_READ_VOID(L, B)  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ((VX1000_UINT32*)(L)-(VX1000_UINT32*)(0)),((VX1000_CHAR*)(B)-(VX1000_CHAR*)(0)),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_DATA
#define VX1000_MAILBOX_PTR 0UL

#endif /* !VX1000_MAILBOX | VX1000_COMPILED_FOR_SLAVECORES */

#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteDone)(VX1000_UINT32 len);
#define VX1000_MAILBOX_WRITEDONE(      L)       VX1000_SUFFUN(vx1000_MailboxWriteDone)((L))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L) (void)VX1000_SUFFUN(vx1000_MailboxWriteDone)((L)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteSplit)(VX1000_UINT32** ppBuf);
#define VX1000_MAILBOX_WRITESPLIT(     B)       VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B) (void)VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITWRITE || VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_MAILBOX_WRITEDONE(      L) VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_SIZE), (L),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_SIZE), (L),(0),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT(     B) VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), ((VX1000_UINT32**)(B)-(VX1000_UINT32**)(0)),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_FULL), ((VX1000_UINT32**)(B)-(VX1000_UINT32**)(0)),(0),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITWRITE || VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadDone)(void);
#define VX1000_MAILBOX_READDONE(     )       VX1000_SUFFUN(vx1000_MailboxReadDone)()  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID() (void)VX1000_SUFFUN(vx1000_MailboxReadDone)(); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadSplit)(VX1000_UINT32* pLen, VX1000_UINT32** ppBuf);
#define VX1000_MAILBOX_READSPLIT(     L, B)       VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITREAD || VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_MAILBOX_READDONE(     ) (VX1000_MAILBOX_ERR_SPLIT_PEND) /* todo: find a better one */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT(     L, B) VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ((VX1000_UINT32*)(L)-(VX1000_UINT32*)(0)),((VX1000_UINT32**)(B)-(VX1000_UINT32**)(0)),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#define VX1000_MAILBOX_READSPLIT_VOID(L, B) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(VX1000_MAILBOX_ERR_EMPTY), ((VX1000_UINT32*)(L)-(VX1000_UINT32*)(0)),((VX1000_UINT32**)(B)-(VX1000_UINT32**)(0)),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */ /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because pointer arithmetic is the only simple way to cast qualified pointers to integers with only-level-4 violations */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITREAD || VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PRINTF)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
void VX1000_SUFFUN(vx1000_MailboxPrintf)( const VX1000_CHAR *format, ... ); /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
#define VX1000_PRINTF VX1000_SUFFUN(vx1000_MailboxPrintf)
#else  /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF || VX1000_COMPILED_FOR_SLAVECORES */
/* todo: check whether "#define VX1000_PRINTF (void)" would be a bearable alternative to the c++ comment (preprocessors might throw it away during expansion!) */
#define VX1000_PRINTF  (void) /* PRQA S 1011 */ /* uses this c++ comment starter to disable rest of line - yes: violates MISRA Rule 2.2 and fails on multiline statements ... */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF || VX1000_COMPILED_FOR_SLAVECORES */


/*------------------------------------------------------------------------------ */
/* VX1000 ECU ID                                                                 */

#if defined(VX1000_ECUID) && defined(VX1000_ECUID_LEN)
extern const VX1000_UINT8 gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U];
#define VX1000_ECUID_DATA const VX1000_UINT8 gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U] = VX1000_ECUID;
#define VX1000_ECUID_PTR ((VX1000_UINT32)/*(void*)(VX1000_UINT8*)*/&gVX1000_ECUID[0]) /* Note: some compilers complain about this direct cast, others complain about about loosing const when going via UINT8* and again others complain about const void ... */
#else /* !VX1000_ECUID || !VX1000_ECUID_LEN */
#define VX1000_ECUID_DATA
#define VX1000_ECUID_PTR  0UL
#define VX1000_ECUID_LEN  0U
#endif /* !VX1000_ECUID || !VX1000_ECUID_LEN */


/*------------------------------------------------------------------------------ */
/* OLDA                                                                          */

#if defined(VX1000_OLDA)

#if defined(VX1000_OLDA_FORCE_V7)
#define VX1000_OLDA_VERSION            0x07U /* Olda Version 7 + 0x10 * Plattform code 0x0 (same as MPC56x) */
#define VX1000_OLDA_SIZE_SWAP_VALUE    0x00000000UL     /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_LENGTH        0x0              /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_OFFSET        0x0              /* dummy value, only used in coldstart verification */
#elif defined(VX1000_OLDA_FORCE_V8)
#define VX1000_OLDA_VERSION            0x08U /* Olda Version 7 + 0x10 * Plattform code 0x0 (same as MPC56x) */
#define VX1000_OLDA_SIZE_SWAP_VALUE    0x00000000UL     /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_LENGTH        0x0              /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_OFFSET        0x0              /* dummy value, only used in coldstart verification */
#else /* !VX1000_OLDA_FORCE_xx */
#define VX1000_OLDA_VERSION            0x06U /* Olda Version 6 + 0x10 * Plattform code 0x0 (same as PowerPC)*/
/* As olda_V6 allows overloading of the SWAP, LENGTH and OFFSET defaults via the CFG file, first check if already defined: */
#if !defined(VX1000_OLDA_SIZE_SWAP_VALUE)
#define VX1000_OLDA_SIZE_SWAP_VALUE    0x0000003bUL     /* all V850 addresses have these bits set: 0x0EC00000 */
#endif /* !VX1000_OLDA_SIZE_SWAP_VALUE */
#if !defined(VX1000_OLDA_SIZE_LENGTH)
#define VX1000_OLDA_SIZE_LENGTH        6UL              /* size/4 is encoded within 6 bit */
#endif /* !VX1000_OLDA_SIZE_LENGTH */
#if !defined(VX1000_OLDA_SIZE_OFFSET)
#define VX1000_OLDA_SIZE_OFFSET        22UL             /* Default address format is with mask 0xF03FFFFF */
#endif /* !VX1000_OLDA_SIZE_OFFSET */
#if ( ((VX1000_OLDA_SIZE_LENGTH) < 4U) || ((VX1000_OLDA_SIZE_LENGTH) > 7U) )
#error "VX1000_OLDA_SIZE_LENGTH not in allowed range of 4..7!"
#endif /* ! 4 <= VX1000_OLDA_SIZE_LENGTH <= 7 */
#if ((VX1000_OLDA_SIZE_OFFSET) + (VX1000_OLDA_SIZE_LENGTH) > 32U)
#error "VX1000_OLDA_SIZE_OFFSET + VX1000_OLDA_SIZE_LENGTH exceeds DWORD border!"
#endif /* VX1000_OLDA_SIZE_OFFSET + VX1000_OLDA_SIZE_LENGTH > 32 */
#endif /* !VX1000_OLDA_FORCE_V7 */

#define VX1000_OLDA_MAGIC              0x2603U


/* Generate Olda Size mask and replacement */
#define VX1000_OLDA_SIZE_MASK ( ((1UL << (VX1000_OLDA_SIZE_LENGTH)) - 1UL) << (VX1000_OLDA_SIZE_OFFSET))
#define VX1000_OLDA_SIZE_REPLACEMENT ((VX1000_UINT32) (((VX1000_OLDA_SIZE_SWAP_VALUE) << (VX1000_OLDA_SIZE_OFFSET)) & (VX1000_OLDA_SIZE_MASK)))

#if (((VX1000_OLDA_SIZE_SWAP_VALUE) & (~((1UL << (VX1000_OLDA_SIZE_LENGTH)) - 1UL))) != 0UL) /* PRQA S 3302 */ /* Accepted violation of MISRA Rule 12.11 because this formula deals with bitfields and not with numbers */
#error Overlapping data fields inside the olda descriptors (SIZE_SWAP_VALUE vs. SIZE_LENGTH)!
#endif /* VX1000_OLDA_SIZE_SWAP_VALUE , VX1000_OLDA_SIZE_LENGTH */


/* Default memory size */
#if !defined(VX1000_OLDA_MEMORY_SIZE) && !defined(VX1000_DISABLE_INSTRUMENTATION)
#error VX1000_OLDA_MEMORY_SIZE must be defined in VX1000_cfg.h!
#endif /* !VX1000_OLDA_MEMORY_SIZE */


/* Feature flags */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE0   (((0x0U << 15U) | (0x0U << 4U)) | (0x0U << 3U)) /* all targtes: 32bits in gVX1000 */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE1   (((0x0U << 15U) | (0x0U << 4U)) | (0x1U << 3U)) /* SHx: 16bits in AUDMBR; PowerPC: 32bits + 32duplicatebits in DTS; TC1xxx: 32bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE2   (((0x0U << 15U) | (0x1U << 4U)) | (0x0U << 3U)) /* TC24x..TC29x: 32bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE3   (((0x0U << 15U) | (0x1U << 4U)) | (0x1U << 3U)) /* TC21x..TC23x: 16bits in TRIGS; reserved on other targets */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE4   (((0x1U << 15U) | (0x0U << 4U)) | (0x0U << 3U)) /* all targtes: 32bits + 32inversebits in gVX1000 */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE5   (((0x1U << 15U) | (0x0U << 4U)) | (0x1U << 3U)) /* reserved */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE6   (((0x1U << 15U) | (0x1U << 4U)) | (0x0U << 3U)) /* reserved */
#define VX1000_FEAT_OLDA_TRIGGER_TYPE7   (((0x1U << 15U) | (0x1U << 4U)) | (0x1U << 3U)) /* reserved */

#if defined(VX1000_OLDA_BENCHMARK)
#define VX1000_FEAT_OLDA_BENCHMARK (1U << 14U)
#else /* !VX1000_OLDA_BENCHMARK */
#define VX1000_FEAT_OLDA_BENCHMARK (0U << 14U)
#endif /* !VX1000_OLDA_BENCHMARK */
/* note: meaning of bits 1,6,7..13 depends on the actually used olda version */
#if defined(VX1000_SUPPORT_OLDA8CMD_SP8N)  && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_SP8N     (1U << 13U)
#else /* !VX1000_SUPPORT_OLDA8CMD_SP8N    || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_SP8N     (0U << 13U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_SP8N   || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP8N)  && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_CP8N     (1U << 12U)
#else /* !VX1000_SUPPORT_OLDA8CMD_CP8N    || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_CP8N     (0U << 12U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_CP8N   || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP16N) && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_CP16N    (1U << 11U)
#else /* !VX1000_SUPPORT_OLDA8CMD_CP16N   || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_CP16N    (0U << 11U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_CP16N  || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP32N) && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_CP32N    (1U << 10U)
#else /* !VX1000_SUPPORT_OLDA8CMD_CP32N   || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_CP32N    (0U << 10U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_CP32N  || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP64N) && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_CP64N    (1U << 9U)
#else /* !VX1000_SUPPORT_OLDA8CMD_CP64N   || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_CP64N    (0U << 9U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_CP64N  || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_DONE)  && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_DONE     (1U << 8U)
#else /* !VX1000_SUPPORT_OLDA8CMD_DONE    || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_DONE     (0U << 8U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_DONE   || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_WAIT)  && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_WAIT     (1U << 7U)
#else /* !VX1000_SUPPORT_OLDA8CMD_WAIT    || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_WAIT     (0U << 7U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_WAIT   || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA8CMD_SUBEVT)&& defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_SUBEVT   (1U << 6U)
#else /* !VX1000_SUPPORT_OLDA8CMD_SUBEVT  || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_SUBEVT   (0U << 6U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_SUBEVT || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_SUPPORT_OLDA7_BYTEDAQ) && defined(VX1000_OLDA_FORCE_V7)
#define VX1000_FEAT_OLDA_V7_BYTEDAQ     (1U << 6U)
#else /* !VX1000_SUPPORT_OLDA7_BYTEDAQ  || !VX1000_OLDA_FORCE_V7 */
#define VX1000_FEAT_OLDA_V7_BYTEDAQ     (0U << 6U)
#endif /* !VX1000_SUPPORT_OLDA7_BYTEDAQ || !VX1000_OLDA_FORCE_V7 */
#if defined(VX1000_HOOK_BASED_BYPASSING)
#define VX1000_FEAT_OLDA_HBB            (1U << 5U)
#else /* !VX1000_HOOK_BASED_BYPASSING */
#define VX1000_FEAT_OLDA_HBB            (0U << 5U)
#endif /* !VX1000_HOOK_BASED_BYPASSING */
#define VX1000_FEAT_OLDA_TRIGGER        (VX1000_FEAT_OLDA_TRIGGER_TYPE4) /* on V850/RH850, no hw support for event triggering is available */
#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_FEAT_OLDA_STIM           (1U << 2U)
#else /* !VX1000_STIM_BY_OLDA */
#define VX1000_FEAT_OLDA_STIM           (0U << 2U)
#endif /* !VX1000_STIM_BY_OLDA */
#define VX1000_FEAT_OLDA_V5_DYNSIZE     (0U << 1U) /* V5 no longer used */
#if defined(VX1000_SUPPORT_OLDA7_COMPRESS)  && defined(VX1000_OLDA_FORCE_V7)
#define VX1000_FEAT_OLDA_V7_COMPRESS    (1U << 1U)
#else /* !VX1000_SUPPORT_OLDA7_COMPRESS  || !VX1000_OLDA_FORCE_V7 */
#define VX1000_FEAT_OLDA_V7_COMPRESS    (0U << 1U)
#endif /* !VX1000_SUPPORT_OLDA7_COMPRESS || !VX1000_OLDA_FORCE_V7 */
#if defined(VX1000_SUPPORT_OLDA8CMD_CALLJITA)  && defined(VX1000_OLDA_FORCE_V8)
#define VX1000_FEAT_OLDA_V8CMD_CALLJITA (1U << 1U)
#else /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA  || !VX1000_OLDA_FORCE_V8 */
#define VX1000_FEAT_OLDA_V8CMD_CALLJITA (0U << 1U)
#endif /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
#define VX1000_FEAT_OLDA_OVERLOADDETECT (1U << 0U)
#else /* !VX1000_OLDA_OVERLOAD_DETECTION */
#define VX1000_FEAT_OLDA_OVERLOADDETECT (0U << 0U)
#endif /* !VX1000_OLDA_OVERLOAD_DETECTION */

/* advice the compiler to pack the data of the following structures byte-wise ==> todo: shall be moved to userconfig (VX1000_BEGSECT_VXMODULE_H) */
#pragma pack(1) /* syntax valid for both GCC and for GHS as well as for Renesas-CX; may need adaptation for other compilers */
typedef struct
{
  VX1000_UINT32   EventCounter;
  VX1000_UINT32   EventTimestamp;  /* NB: for OLDA stimulation, this field is used to store the address of the stimulation buffer */
  VX1000_UINT32   TransferDest;
  VX1000_UINT16   TransferIndex;
  VX1000_UINT16   TransferCount;
} VX1000_OLDA_EVENT_T;

typedef struct
{
  VX1000_UINT16        MagicId;              /* 0x00 */
  VX1000_UINT8         Version;              /* 0x02 */
  VX1000_UINT8         Running;              /* 0x03 */
  VX1000_UINT32        MemoryAddr;           /* 0x04 */
  VX1000_UINT16        MemorySize;           /* 0x08 */
  VX1000_UINT16        EventCount;           /* 0x0A */
  VX1000_OLDA_EVENT_T *EventList;            /* 0x0C */
  VX1000_UINT32       *TransferList;         /* 0x10 */
  VX1000_UINT8         SizeLengthNOffset;    /* 0x14 */
  VX1000_UINT8         SizeSwapValue;        /* 0x15 */
  VX1000_UINT16        OldaFeatures;         /* 0x16 */
  VX1000_UINT32        Res1;                 /* 0x18 */
  VX1000_UINT32        Res2;                 /* 0x1C */
#if !defined(VX1000_OLDA_MEMORY_ADDR)
  VX1000_UINT32        Data[(VX1000_OLDA_MEMORY_SIZE) / 4UL];
#endif /* !VX1000_OLDA_MEMORY_ADDR */
} VX1000_OLDA_T;

/* restore previous padding strategy for the application ==> todo: shall be moved to userconfig (VX1000_ENDSECT_VXMODULE_H) */
#if defined(__CX__)
/* Renesas CX compiler syntax */
#pragma pack(4)
#else /* !__CX__ */
/* GHS compiler syntax */
#pragma pack()
#endif /* !__CX__ */

extern void VX1000_SUFFUN(vx1000_OldaInit)( void );
#define VX1000_OLDA_INIT()             VX1000_SUFFUN(vx1000_OldaInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_OldaEvent)( VX1000_UINT8 eventNumber );
#define VX1000_OLDA_EVENT(x)           VX1000_SUFFUN(vx1000_OldaEvent)((x)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OLDA_DATA               VX1000_OLDA_T Olda;
#define VX1000_OLDA_PTR                ((VX1000_UINT32)&gVX1000.Olda)

#if defined(VX1000_OLDA_BENCHMARK)
extern VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];
extern VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT];
extern VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
#define VX1000_OLDA_BENCHMARK_DATA                                     \
  VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];        \
  VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT];    \
  VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
#define VX1000_OLDA_DURARRAY_PTR       (VX1000_UINT32)gVX1000_OLDA_Duration
#else /* !VX1000_OLDA_BENCHMARK */
#define VX1000_OLDA_BENCHMARK_DATA
#define VX1000_OLDA_DURARRAY_PTR       0UL
#endif /* VX1000_OLDA_BENCHMARK */

#else /* !VX1000_OLDA */

#define VX1000_OLDA_EVENT(x)           /*VX1000_DUMMYREAD((x))*/
#define VX1000_OLDA_INIT()
#define VX1000_OLDA_DATA
#define VX1000_OLDA_PTR                0UL
#define VX1000_OLDA_BENCHMARK_DATA
#define VX1000_OLDA_DURARRAY_PTR       0UL

#endif /* !VX1000_OLDA */


/*------------------------------------------------------------------------------ */
/* Driver Error Logger                                                           */

#define VX1000_ERRLOG_NO_ERROR         0x0000U /* no error at all */

#define VX1000_ERRLOG_STRUCTS_PADDED   0x0101U /* due to bad compiler settings, the VX1000 structures were padded (but they must be packed) */
#define VX1000_ERRLOG_JTAGID_UNKNOWN   0x0102U /* the driver found a derivative that it does not know how to handle (e.g. support was de-configured to reduce code size) */

#define VX1000_ERRLOG_TM_RESO_TOO_LOW  0x0201U /* the resolution of the timer is too low for some features */
#define VX1000_ERRLOG_TM_RESO_TOO_HIGH 0x0202U /* the resolution of the timer is too high for some features */
#define VX1000_ERRLOG_TM_DT_IS_ZERO    0x0203U /* due to a low resolution, the conversion from a non-zero time resulted in a tick count of zero */
#define VX1000_ERRLOG_TM_DTDT_TOO_LONG 0x0204U /* the user requested a VX1000_DETECT() timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTCS_TOO_LONG 0x0205U /* the user requested a VX1000_INIT() timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTST_TOO_LONG 0x0206U /* the user called the STIM API with a timeout that cannot be represented within the available bit slice */
#define VX1000_ERRLOG_TM_DTSR_TOO_LONG 0x0207U /* the user requested a VX1000_PREPARE_SOFTRESET() timeout that cannot be represented within the available bit slice */

#define VX1000_ERRLOG_OVL_INVALID_PAGE 0x0401U /* the XCP master requested a page number > 1 which is not supported by the driver */
#define VX1000_ERRLOG_OVL_INVALID_SIZE 0x0402U /* the user specified an overlay size that is not supported by the hardware/driver */
#define VX1000_ERRLOG_OVL_MISALIGNED   0x0403U /* the user specified an overlay alignment that is not supported by the hardware/driver */
#define VX1000_ERRLOG_OVL_TOO_MANY     0x0404U /* the XCP master requested a segment number > 1 which is not supported by the driver */
#define VX1000_ERRLOG_OVL_USER_FAILED  0x0405U /* a user's overlay callback returned a value != 0 */
#define VX1000_ERRLOG_OVL_UNIMPL       0x0406U /* code was triggered that is not implemented for the derivative it is executed on */

#if (VX1000_ERRLOG_SIZE != 0)
extern void VX1000_SUFFUN(vx1000_ErrLogger)( VX1000_UINT16 errorcode );
#define VX1000_ERRLOGGER(E)            VX1000_SUFFUN(vx1000_ErrLogger)(E); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_ERRLOG_DATA             VX1000_UINT16 ErrLog[VX1000_ERRLOG_SIZE];
#define VX1000_ERRLOG_ADDR             (VX1000_UINT32)gVX1000.ErrLog
#else /* !VX1000_ERRLOG_SIZE */
#define VX1000_ERRLOGGER(E)            /* empty */
#define VX1000_ERRLOG_DATA             /* empty */
#define VX1000_ERRLOG_ADDR             0UL
#endif /* !VX1000_ERRLOG_SIZE */


/*------------------------------------------------------------------------------ */
/* VX1000 Stimulation                                                            */

/* STIM event API return codes */
#define VX1000_STIM_RET_INACTIVE       0
#define VX1000_STIM_RET_SUCCESS        1
#define VX1000_STIM_RET_TIMEOUT        2
#define VX1000_STIM_RET_ERROR          3

#if defined(VX1000_STIM)

#define VX1000_STIM_MAGIC              0xFEC70A07UL
#define VX1000_STIM_EVENT_MAGIC        0xFEC70A19UL

#if !defined(VX1000_STIM_FORCE_V1)
typedef struct
{
  VX1000_UINT32 MagicId;           /* 0x00 */
  VX1000_UINT16 Version;           /* 0x04 */
  VX1000_UINT16 Control;           /* 0x06 */
  VX1000_UINT8  EvtOffset;         /* 0x08 */
  VX1000_UINT8  EvtNumber;         /* 0x09 */
  VX1000_UINT16 Reserved;          /* 0x0A */
  struct VX1000_stim_event         /* 0x0C */
  {
    VX1000_UINT8 Ctr;              /* 0x0C + 4*e */
    VX1000_UINT8 RqCtr;            /* 0x0D + 4*e */
    VX1000_UINT8 Enable;           /* 0x0E + 4*e */
    VX1000_UINT8 Copying;          /* 0x0F + 4*e */
  } Event[VX1000_STIM_EVENT_COUNT];
  VX1000_UINT16 Enable;            /* 0x0C + 4*VX1000_STIM_EVENT_COUNT */
  VX1000_UINT16 TimeoutCtr;        /* 0x0E + 4*VX1000_STIM_EVENT_COUNT */
  VX1000_UINT16 TimeoutCtr2;       /* 0x10 + 4*VX1000_STIM_EVENT_COUNT */
} VX1000_STIM_T;
#define VX1000_STIMEVENT_ARRAYNAME gVX1000.Stim.Event
#else /* VX1000_STIM_FORCE_V1 */
typedef struct
{
  VX1000_UINT32 MagicId;           /* 0x20 + 0x00 */
  VX1000_UINT32 Version;           /* 0x20 + 0x04 */
  struct VX1000_stim_event         /* 0x20 + 0x08 */
  {
    VX1000_UINT8 EventType;        /* 0x20 + 0x08 + 8*e */
    VX1000_UINT8 DaqEvent;         /* 0x20 + 0x09 + 8*e */
    VX1000_UINT8 Enable;           /* 0x20 + 0x0A + 8*e */
    VX1000_UINT8 Copying;          /* 0x20 + 0x0B + 8*e */
    VX1000_UINT8 Ctr;              /* 0x20 + 0x0C + 8*e */
    VX1000_UINT8 RqCtr;            /* 0x20 + 0x0D + 8*e */
    VX1000_UINT16 Reserved;        /* 0x20 + 0x0E + 8*e */
  } Event[VX1000_STIM_EVENT_COUNT];
} VX1000_STIM_EVENT_T;

typedef struct VX1000_hbb_table
{
  VX1000_UINT8 StimEvent;
  VX1000_UINT8 Reserved;
  VX1000_UINT16 OldaAddress;
} VX1000_HBB_VX_TABLE_ENTRY_T;

typedef struct
{
  VX1000_UINT32 MagicId;           /* 0x00 */
  VX1000_UINT16 Version;           /* 0x04 */
  VX1000_UINT16 Control;           /* 0x06 */
  VX1000_UINT8 EvtOffset;          /* 0x08 */
  VX1000_UINT8 EvtNumber;          /* 0x09 */
  VX1000_UINT16 Enable;            /* 0x0a */
  VX1000_UINT32 EventPointer;      /* 0x0c */
  VX1000_UINT16 TimeoutCtr;        /* 0x10 */
  VX1000_UINT16 TimeoutCtr2;       /* 0x12 */
  VX1000_UINT32 hbbLUTNumber;      /* 0x14 */
  VX1000_UINT32 hbbLUTPointer;     /* 0x18 */
  VX1000_UINT32 hbbLUTVXPointer;   /* 0x1c */
  VX1000_STIM_EVENT_T Events;      /* 0x20 */ /* attention: no reserved field for future extensions! */
} VX1000_STIM_T;
#define VX1000_STIMEVENT_ARRAYNAME gVX1000.Stim.Events.Event
#endif /* VX1000_STIM_FORCE_V1 */

/* STIM event enable flag     */
#define VX1000_STIM_INACTIVE         0
#define VX1000_STIM_VX_ENABLE        1
#define VX1000_STIM_DAQ_SENT         2
#define VX1000_STIM_BUFFER_VALID     3
#define VX1000_STIM_BUFFER_INVALID   4

/* STIM event global enable   */
#define VX1000_STIM_GLOBAL_INACTIVE  0
#define VX1000_STIM_GLOBAL_VX_ENABLE 1
#define VX1000_STIM_GLOBAL_ALL_CHAN  2

/* STIM event types           */
#define VX1000_BYPASS_TYPE_DIRECT    1
#define VX1000_BYPASS_TYPE_OLDA      2
#define VX1000_BYPASS_TYPE_HOOK      3

/* Copy Active Flag meanings - used for direct stimulation  */
#define VX1000_BP_CPACT_WAITING_DAQ  0
#define VX1000_BP_CPACT_WAITING_STIM 1
#define VX1000_BP_CPACT_DATA_READY   2
#define VX1000_BP_CPACT_COPYING      3

#define VX1000_BP_TIMESTAMP_SIZE     4


/* stim API */
extern void VX1000_SUFFUN(vx1000_StimInit)(void);
#define VX1000_STIM_INIT() VX1000_SUFFUN(vx1000_StimInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DATA VX1000_STIM_T Stim;
#define VX1000_STIM_PTR ((VX1000_UINT32)&gVX1000.Stim)
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_StimWait)( VX1000_UINT8 stim_event, VX1000_UINT8 copy_enable, VX1000_UINT32 timeout_us );
#define VX1000_STIM_WAIT(     E, T)       VX1000_SUFFUN(vx1000_StimWait)((E), 1, (T) )  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T) (void)VX1000_SUFFUN(vx1000_StimWait)((E), 1, (T) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_Stimulate)( VX1000_UINT8 stim_trigger_event, VX1000_UINT8 stim_event,
                                                     VX1000_UINT8 cycle_delay, VX1000_UINT32 timeout_us);
#define VX1000_STIMULATE(     D, S, P, T)       VX1000_SUFFUN(vx1000_Stimulate)((D), (S), (P), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T) (void)VX1000_SUFFUN(vx1000_Stimulate)((D), (S), (P), (T)); /* usable as a whole statement */
 /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimControl)( void );
#define VX1000_STIM_CONTROL()   VX1000_SUFFUN(vx1000_StimControl)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_CONTROL() VX1000_SUFFUN(vx1000_StimControl)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassTrigger)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event );
#define VX1000_BYPASS_TRIGGER(     D, S)       VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S) (void)VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassDaq) ( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event );
#define VX1000_BYPASS_DAQ(     D, S)  VX1000_SUFFUN(vx1000_BypassDaq) ((D), (S)) /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ_VOID(D, S)  (void)VX1000_SUFFUN(vx1000_BypassDaq) ((D), (S)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM(     S ) VX1000_SUFFUN(vx1000_StimWait)((S), 1, 0 )  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM_VOID(S) (void)VX1000_SUFFUN(vx1000_StimWait)((S), 1, 0 ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassWait)( VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us);
#define VX1000_BYPASS_WAIT(     S, T)       VX1000_SUFFUN(vx1000_BypassWait)((S), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T) (void)VX1000_SUFFUN(vx1000_BypassWait)((S), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_Bypass)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us );
#define VX1000_BYPASS(      D, S, T)       VX1000_SUFFUN(vx1000_Bypass)( (D), (S), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID( D, S, T) (void)VX1000_SUFFUN(vx1000_Bypass)( (D), (S), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_REGISTER_STIM_EVENT(daq_event, stim_event, stim_type) do                                \
  {                                                                                                    \
    if ((VX1000_IS_STIM_EVENT((stim_event))) != 0)                                                     \
    {                                                                                                  \
      (VX1000_STIMEVENT_ARRAYNAME)[(stim_event) - (VX1000_STIM_EVENT_OFFSET)].DaqEvent = (daq_event);  \
      (VX1000_STIMEVENT_ARRAYNAME)[(stim_event) - (VX1000_STIM_EVENT_OFFSET)].EventType = (stim_type); \
    }                                                                                                  \
  } while(0);

#if defined(VX1000_STIM_BENCHMARK)
extern volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT];
extern volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT];
#if defined(VX1000_STIM_HISTOGRAM)
extern volatile VX1000_UINT32 gVX1000_STIM_Histogram[256];
extern volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16];
#define VX1000_STIM_BENCHMARK_DATA                                       \
  volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT];    \
  volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT]; \
  volatile VX1000_UINT32 gVX1000_STIM_Histogram[256];                    \
  volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16];
#else /* !VX1000_STIM_HISTOGRAM */
#define VX1000_STIM_BENCHMARK_DATA                                       \
  volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT];    \
  volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT];
#endif /* !VX1000_STIM_HISTOGRAM */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkInit)( void );
#define VX1000_STIM_BENCHMARK_INIT() VX1000_SUFFUN(vx1000_StimBenchmarkInit)(); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkStimBegin)( VX1000_UINT8 stim_event );
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E) VX1000_SUFFUN(vx1000_StimBenchmarkStimBegin)( (E) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkStimEnd)( VX1000_UINT8 stim_event, VX1000_UINT8 timeout_flag );
#define VX1000_STIM_BENCHMARK_STIM_END(E, F) VX1000_SUFFUN(vx1000_StimBenchmarkStimEnd)( (E), (F) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DURARRAY_PTR       (VX1000_UINT32)gVX1000_STIM_Duration
#else /* !VX1000_STIM_BENCHMARK */
#define VX1000_STIM_BENCHMARK_DATA
#define VX1000_STIM_BENCHMARK_INIT() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_END(E, F) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DURARRAY_PTR       0UL
#endif /* !VX1000_STIM_BENCHMARK */

#define VX1000_STIM_TIMEOUTS gVX1000.Stim.TimeoutCtr
#define VX1000_STIM_TIMEOUTS_IN_SEQ gVX1000.Stim.TimeoutCtr2

extern VX1000_UINT8 VX1000_SUFFUN(vx1000_StimActive)( VX1000_UINT8 stim_event );
#define VX1000_STIM_ACTIVE(S) VX1000_SUFFUN(vx1000_StimActive)((S))   /* usable in/as an expression */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimRequest)( VX1000_UINT8 stim_event );
#define VX1000_STIM_REQUEST(S) VX1000_SUFFUN(vx1000_StimRequest)((S)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimSkip)( VX1000_UINT8 stim_event );
#define VX1000_STIM_SKIP(S) VX1000_SUFFUN(vx1000_StimSkip)((S)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#if defined(VX1000_STIM_BY_OLDA)
extern void VX1000_SUFFUN(vx1000_OldaStimRequestEvent)( VX1000_UINT8 eventNumber );
#define VX1000_STIM_REQUEST_EVENT(x) VX1000_SUFFUN(vx1000_OldaStimRequestEvent)((x)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_STIM_BY_OLDA */
#define VX1000_STIM_REQUEST_EVENT(x) VX1000_EVENT((x)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_STIM_BY_OLDA */

#else /* !VX1000_STIM */

#define VX1000_STIM_INIT()                   /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DATA                     /* empty */
#define VX1000_STIM_PTR                      0UL /* "invalid" */
#define VX1000_STIM_BENCHMARK_DATA           /* empty */
#define VX1000_STIM_WAIT(     E, T)          VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1, (E),(T),(0),(0)) /* return code for "timeout" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T)          VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,1, (E),(T),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE(     D, S, P, T)    VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(P),(T))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T)    VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(P),(T)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_ACTIVE(S)                VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (S),(0),(0),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_CONTROL()                /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST(S)               VX1000_DUMMYREAD((S))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_SKIP(S)                  VX1000_DUMMYREAD((S))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_CONTROL()              /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ(     D, S)         VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(0),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_DAQ_VOID(D, S)         VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM(      S)          VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (S),(0),(0),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_STIM_VOID( S)          VX1000_DUMMYREAD(S)/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER(     D, S)     VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(0),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S)     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT(     S, T)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (S),(T),(0),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T)        VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (S),(T),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS(     D, S, T)          VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(T),(0))/* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID(D, S, T)          VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (D),(S),(T),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_INIT()         /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E)  VX1000_DUMMYREAD(E)/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_END(E, F) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0, (E),(F),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_REGISTER_STIM_EVENT(D, S, T)  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0, (D),(S),(T),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DURARRAY_PTR             0UL

#endif /* !VX1000_STIM */

/* Hook based bypassing macros */
#if defined(VX1000_HOOK_BASED_BYPASSING) && defined(VX1000_STIM)

#define VX1000_HBB_LUT( H )                     ((VX1000_HBB_VX_TABLE_ENTRY_T*)gVX1000.Stim.hbbLUTVXPointer)[(H)]
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassHbbGetVal_8) ( VX1000_UINT32 HookID, VX1000_UINT8 DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_8( H, D )      VX1000_SUFFUN(vx1000_BypassHbbGetVal_8) ((H), (D))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT16 VX1000_SUFFUN(vx1000_BypassHbbGetVal_16) ( VX1000_UINT32 HookID, VX1000_UINT16 DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_16( H, D )     VX1000_SUFFUN(vx1000_BypassHbbGetVal_16) ((H), (D))   /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_BypassHbbGetVal_32) ( VX1000_UINT32 HookID, VX1000_UINT32 DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_32( H, D )     VX1000_SUFFUN(vx1000_BypassHbbGetVal_32) ((H), (D))   /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT64 VX1000_SUFFUN(vx1000_BypassHbbGetVal_64) ( VX1000_UINT32 HookID, VX1000_UINT64 DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_64( H, D )     VX1000_SUFFUN(vx1000_BypassHbbGetVal_64) ((H), (D))   /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_FLOAT VX1000_SUFFUN(vx1000_BypassHbbGetVal_Float) ( VX1000_UINT32 HookID, VX1000_FLOAT DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_FLOAT( H, D )  VX1000_SUFFUN(vx1000_BypassHbbGetVal_Float) ((H), (D))      /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_DOUBLE VX1000_SUFFUN(vx1000_BypassHbbGetVal_Double) ( VX1000_UINT32 HookID, VX1000_DOUBLE DefaultValue );
#define VX1000_BYPASS_HBB_GETVAL_DOUBLE( H, D ) VX1000_SUFFUN(vx1000_BypassHbbGetVal_Double) ((H), (D))       /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */

#define VX1000_HBB_LUT( H )                     VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (H),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_8( H, D )      ((VX1000_UINT8)(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(D), (H),(0),(0),(0)))) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_16( H, D )     ((VX1000_UINT16)(VX1000_DISCARD4DUMMYARGS(VX1000_UINT16,(D), (H),(0),(0),(0)))) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_32( H, D )     VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(D), (H),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_64( H, D )     VX1000_DISCARD4DUMMYARGS((VX1000_UINT64),(D), (H),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_FLOAT( H, D )  VX1000_DISCARD4DUMMYARGS(VX1000_FLOAT,(D), (H),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_HBB_GETVAL_DOUBLE( H, D ) VX1000_DISCARD4DUMMYARGS(VX1000_DOUBLE,(D), (H),(0),(0),(0)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_HOOK_BASED_BYPASSING || !VX1000_STIM */

#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
/*------------------------------------------------------------------------------ */
/* VX1000 Generic Hooking Control                                                */

#if defined(VX1000_HOOK_ENABLE)

#define VX1000_HOOK_MAGIC                0x2603U
#define VX1000_HOOK_COPY_ENABLE          (1U << 0U)   /* Enable copy of stim data */
#define VX1000_HOOK_CODE_ALWAYS          (1U << 1U)   /* Run the original code always */
#define VX1000_HOOK_CODE_TIMEOUT         (1U << 2U)   /* Run the original code after timeout */
#define VX1000_HOOK_CODE_RESERVED        (1U << 3U)
#define VX1000_HOOK_TRIGGER_EVENT_ENABLE (1U << 4U)   /* Trigger stim_event always, even if there is no bypass  */
#define VX1000_HOOK_DAQ_EVENT_ENABLE     (1U << 5U)   /* Trigger daq_event always immediately after original code,
                                                      /  even if there is no bypass */
typedef struct
{
  VX1000_UINT16 magic;
  VX1000_UINT16 count;
  VX1000_UINT16 active_id;
  VX1000_UINT16 active_index;
  struct
  {
    VX1000_UINT16 id;
#if defined(VX1000_STIM)
    VX1000_UINT8 stim_event;
#endif /* VX1000_STIM */
    VX1000_UINT8 trigger_event;
    VX1000_UINT8 daq_event;
    VX1000_UINT8 control;
  } table[VX1000_HOOK_COUNT];
} VX1000_HOOK_T; /* PRQA S 3205 */ /* Accepting to define a type that might be unused in some users' configurations/applications */
extern volatile VX1000_HOOK_T gVX1000_HookControl;
#define VX1000_HOOK_CONTROL_DATA volatile VX1000_HOOK_T gVX1000_HookControl;
extern void VX1000_SUFFUN(vx1000_HookInit)( void );
#define VX1000_HOOK_INIT() VX1000_SUFFUN(vx1000_HookInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_EnterHook)( VX1000_UINT16 hook_id );
#define VX1000_HOOK_TRIGGER(     I)       VX1000_SUFFUN(vx1000_EnterHook)((I))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER_VOID(I) (void)VX1000_SUFFUN(vx1000_EnterHook)((I)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_LeaveHook)( VX1000_UINT16 hook_id, VX1000_UINT32 timeout);
#define VX1000_HOOK_WAIT(     I, T)       VX1000_SUFFUN(vx1000_LeaveHook)((I), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT_VOID(I, T) (void)VX1000_SUFFUN(vx1000_LeaveHook)((I), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK(id, timeout, code)                                                                                       \
  if (VX1000_SUFFUN(vx1000_EnterHook)((id)) == 0)                                                                            \
  {                                                                                                                          \
    code /* PRQA S 3410 */ /*Cannot avoid violating MISRA Rule 19.10 because this parameter cannot be set into parentheses*/ \
    VX1000_SUFFUN(vx1000_LeaveHook)((id), (timeout));                                                                        \
  }                                                                                                                          \
  else                                                                                                                       \
  {                                                                                                                          \
    if (VX1000_SUFFUN(vx1000_LeaveHook)((id), (timeout)) == 3U)                                                              \
    {                                                                                                                        \
      code /*PRQA S 3410*/ /*Cannot avoid violating MISRA Rule 19.10 because this parameter cannot be set into parentheses*/ \
    }                                                                                                                        \
  } /* PRQA S 3453 */ /* Impossible to not violate MISRA Rule 19.7 because a conform function would have to execute code passed as an argument */

extern void VX1000_SUFFUN(vx1000_GenericEvent)( VX1000_UINT16 hook_id );
#define VX1000_GENERIC_EVENT(id) VX1000_SUFFUN(vx1000_GenericEvent)((id)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_HOOK_ENABLE */

#define VX1000_HOOK_CONTROL_DATA        /* empty */
#define VX1000_HOOK_INIT()              /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER(     I)     (/*(VX1000_UINT8)*/(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (I),(0),(0),(0))))/* this means "execute original code" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER_VOID(I)     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (I),(0),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT(     I, T)     (/*(VX1000_UINT8)*/(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (I),(T),(0),(0))))/* this means "bypassing inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT_VOID(I, T)     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (I),(T),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK(id, code)           /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_GENERIC_EVENT(I)         VX1000_DUMMYREAD((I))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_HOOK_ENABLE */
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */


/*------------------------------------------------------------------------------ */
/* Calibration                                                                   */

#if defined(VX1000_CAL)

#include "cc_autosar.h"
#define CC_PTR ((VX1000_UINT32)&gCC)

#else /* !VX1000_CAL */

#define CC_PTR 0UL

#endif /* !VX1000_CAL */


/*------------------------------------------------------------------------------ */
/* Overlay                                                                       */

#if defined(VX1000_OVERLAY)

#define VX1000_OVL_MAGIC                 0xfec70a17UL
#define VX1000_EMEM_HDR_MAGIC            0xfec81b28UL

#define VX1000_OVLFEAT_KEEP_AWAKE        (1UL << 0) /* VX may suppress ECU falling asleep and/or shut down */
#define VX1000_OVLFEAT_SYNC_PAGESWITCH   (1UL << 1) /* ... */
#define VX1000_OVLFEAT_PERSISTENT_EMEM   (1UL << 2) /* ... */
#define VX1000_OVLFEAT_RST_ON_CALWAKEUP  (1UL << 3) /* ... */
#define VX1000_OVLFEAT_USE_VX_EPK_TRANS  (1UL << 4) /* ... */
#define VX1000_OVLFEAT_VALIDATE_PAGESW   (1UL << 5) /* ... */
#define VX1000_OVLFEAT_CORE_SYNC_PAGESW  (1UL << 6) /* After a page switch request, cores will switch their respective pages individually */
#define VX1000_OVLFEAT_NONE              (0x0UL << 7)
#define VX1000_OVLFEAT_USER              (0x1UL << 7)
#define VX1000_OVLFEAT_DRIVER            (0x2UL << 7)
#define VX1000_OVLFEAT_VX                (0x3UL << 7)
#define VX1000_OVLFEAT_ECU_REGS_VIA_MX   (1UL << 9)  /* overlay registers are configured over mailbox */
#define VX1000_OVLFEAT_RST_ON_SNCPAGESW  (1UL << 10) /* ECU will perform an ECU Reset on Sync_Cal_Page_Switch */

typedef struct s_ecu_ovl_descriptor
{    /* 4x4 = 16B = 0x10 */
  /* ... */
} VX1000_OVL_DESCRIPTOR_T;
typedef struct s_ecu_ovl_config_regs
{   /* 16*1*64 + 4*2 + 2 + 2 = 1036 = 0x40C Bytes */
  /* ... */
} VX1000_OVL_CONFIG_REGS_T;

typedef struct s_ecu_page_switch
{
  VX1000_UINT32 magicId;
  VX1000_UINT16 version;
  VX1000_UINT8  pageSwitchRequested;
  VX1000_UINT8  targetPage;
  VX1000_UINT32 overlayValue;
  VX1000_UINT32 overlayMask;
  VX1000_UINT32 busMasterRequested;
  VX1000_UINT8  coreDone[32];
} VX1000_SYNCAL_PAGE_SWITCH_T;

/* Structure for EMEM invalidation when cal-wakeup and EMEM-supply is used */
typedef struct s_ecu_emem_hdr
{
  VX1000_UINT32 magicId;
  VX1000_UINT16 version;
  VX1000_UINT16 reserved;
  VX1000_UINT32 ememInitEnd;           /* VX-RW, ECU-RO */
  VX1000_UINT32 ememInitEndInvert;     /* VX-RW, ECU-RO */
  VX1000_UINT32 ememInitStart;         /* VX-RW, ECU-RW */
  VX1000_UINT32 ememInitStartInvert;   /* VX-RW, ECU-RW */
#define VX1000_EMEM_HDR_VERSION 1
} VX1000_EMEM_HDR_T;

typedef struct
{
  VX1000_UINT32 magicId;                        /* 0x00 */
  VX1000_UINT16 version;                        /* 0x04 */
  VX1000_UINT16 presenceCounter;                /* 0x06 */
  VX1000_UINT32 ovlConfigValue;                 /* 0x08 */
  VX1000_UINT32 ovlConfigMask;                  /* 0x0C */
  VX1000_UINT32 calFeaturesEnable;              /* 0x10 */
  VX1000_EMEM_HDR_T* persistentECUEmemHeaderPtr;/* 0x14 */
  VX1000_UINT32 ovlBusMasterMask;               /* 0x18 */
  VX1000_UINT16 ecuLastPresenceCounter;         /* 0x1C */
  VX1000_UINT16 ovlEPKLength;                   /* 0x1E */
  VX1000_UINT32 ovlReferencePageDataEPKAddress; /* 0x20 */
  VX1000_UINT32 ovlWorkingPageDataEPKAddress;   /* 0x24 */
  VX1000_UINT32 syncCalSwitchDataPtr;           /* 0x28 */
  VX1000_UINT32 ovlConfigRegsPtr;               /* 0x2C */
  VX1000_SYNCAL_PAGE_SWITCH_T syncCalData;      /* 0x30 */
  VX1000_OVL_CONFIG_REGS_T ovlConfigRegs;
#define VX1000_OVL_VERSION             4
} VX1000_OVL_T;

#define VX1000_OVL_DATA                VX1000_OVL_T Ovl;
#define VX1000_OVL_PTR                 ((VX1000_UINT32)(&gVX1000.Ovl))

#if defined(VX1000_COMPILED_FOR_SLAVECORES)
#define VX1000_OVERLAY_INIT()  /* empty */
#endif /* VX1000_COMPILED_FOR_SLAVECORES */

#define VX1000_CAL_WAKEUP_REQUESTED() ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_CAL_WAKEUP))) != 0)

#if defined(VX1000_OVLENBL_KEEP_AWAKE)
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_IsCalWakeupActive)( void );
#define VX1000_IS_CAL_WAKEUP_ACTIVE()  VX1000_SUFFUN(vx1000_IsCalWakeupActive)()
#else /* !VX1000_OVLENBL_KEEP_AWAKE */
#define VX1000_IS_CAL_WAKEUP_ACTIVE()  0 /* provide return value for "not active" */
#endif /* !VX1000_OVLENBL_KEEP_AWAKE */

#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
#if !defined(VX1000_OVL_SET_CONFIG)
#define VX1000_OVL_SET_CONFIG_INTERNAL
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlaySetConfig)( VX1000_UINT32 value, VX1000_UINT32 mask, VX1000_UINT8 page, VX1000_UINT32 master, VX1000_UINT32 calMaster );
#define VX1000_OVL_SET_CONFIG(value,mask,page,master,calMasters) VX1000_SUFFUN(vx1000_OverlaySetConfig)((value),(mask),(page),(master),(calMasters)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(value,mask,page,master,calMasters) (void)VX1000_OVL_SET_CONFIG((value),(mask),(page),(master),(calMasters));
#endif /* !VX1000_OVL_SET_CONFIG */

extern void VX1000_SUFFUN(vx1000_OverlaySetConfigDone)( VX1000_UINT8 cfgResult, VX1000_UINT8 page, VX1000_UINT8 onStartup );
#define VX1000_OVL_SET_CONFIG_DONE(result, page) VX1000_SUFFUN(vx1000_OverlaySetConfigDone)((result),(page), 0);
#define VX1000_OVL_SET_CONFIG_DONE_STUP(result,page) VX1000_SUFFUN(vx1000_OverlaySetConfigDone)((result),(page), 1);

extern VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)( void );
#define VX1000_OVL_CHK_PAGESW_DONE() VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)()
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()  (void)VX1000_OVL_CHK_PAGESW_DONE();

extern VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)( VX1000_UINT32 master );
#define VX1000_OVL_CHK_PAGESW_CORE(cores) VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)((cores)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(cores) (void)VX1000_OVL_CHK_PAGESW_CORE((cores));

extern VX1000_UINT8 VX1000_SUFFUN(vx1000_overlayIsPageSwitchReq)( VX1000_UINT32 master );
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores) VX1000_SUFFUN(vx1000_overlayIsPageSwitchReq)((cores)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_OVLENBL_SYNC_PAGESWITCH */

#if !defined(VX1000_OVL_SET_CONFIG)
#define VX1000_OVL_SET_CONFIG(value,mask,page,master,calMasters)   VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(0), (value),(mask),(page),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(master), (calMasters),(0),(0),(0)))/* return value for "nothing done" */  /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(value,mask,page,master,calMasters) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(value), (mask),(page),(master),(calMasters)))/* empty */  /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVL_SET_CONFIG */
#define VX1000_OVL_SET_CONFIG_DONE(result, page)     VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_DONE_STUP(result,page) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE()                 ((VX1000_UINT8)(1)) /* provide return value "not ready" */
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()            /* empty */
#define VX1000_OVL_CHK_PAGESW_CORE(cores)            VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,((VX1000_UINT8)(1)), (cores),(0),(0),(0))/* provide return value "not ready" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(cores)       VX1000_DUMMYREAD((cores))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores)        VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (cores),(0),(0),(0))/* provide return value "no" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_OVLENBL_SYNC_PAGESWITCH */

#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
#define VX1000_EMEM_HDR_DATA             volatile VX1000_EMEM_HDR_T gVXEmemHdr;
#define VX1000_EMEM_HDR_PTR              ((VX1000_UINT32)&gVXEmemHdr)
extern void VX1000_SUFFUN(vx1000_InvalidateEmem)( void );
#define VX1000_INVALIDATE_EMEM()         VX1000_SUFFUN(vx1000_InvalidateEmem)();

#else /* !VX1000_OVLENBL_PERSISTENT_EMEM */

#define VX1000_EMEM_HDR_DATA             /* empty */
#define VX1000_EMEM_HDR_PTR              0UL
#define VX1000_INVALIDATE_EMEM()         /* empty */

#endif /* !VX1000_OVLENBL_PERSISTENT_EMEM */

/* provide empty user callbacks if not already specified by the user: */
#if !defined(VX1000_OVL_RST_ON_CAL_WAKEUP_CB)
#define VX1000_OVL_RST_ON_CAL_WAKEUP_CB() /* empty */
#endif /* !VX1000_OVL_RST_ON_CAL_WAKEUP_CB */


#else /* !VX1000_OVERLAY */

#define VX1000_OVERLAY_INIT()            /* empty */
#define VX1000_OVL_PTR                   0UL
#define VX1000_OVL_DATA                  /* empty */
#define VX1000_EMEM_HDR_DATA             /* empty */
#define VX1000_EMEM_HDR_PTR              0UL
#define VX1000_INVALIDATE_EMEM()         /* empty */
#define VX1000_CAL_WAKEUP_REQUESTED()    0 /* provide return value for "no request" */
#define VX1000_IS_CAL_WAKEUP_ACTIVE()    0 /* provide return value for "not active" */
#if !defined(VX1000_OVL_SET_CONFIG)
#define VX1000_OVL_SET_CONFIG(value,mask,page,master,calMasters)      VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(0), (value),(mask),(page),VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(master), (calMasters),(0),(0),(0)))  /* return value for "nothing done" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_VOID(value,mask,page,master,calMasters) VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,(value), (mask),(page),(master),(calMasters)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVL_SET_CONFIG */
#define VX1000_OVL_SET_CONFIG_DONE(result, page)                      VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_SET_CONFIG_DONE_STUP(result,page)                  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (result),(page),(0),(0)))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_DONE()                                  ((VX1000_UINT8)(1))         /* provide return value for "not ready" ? */
#define VX1000_OVL_CHK_PAGESW_DONE_VOID()                             /* empty */
#define VX1000_OVL_CHK_PAGESW_CORE(cores)                             VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,((VX1000_UINT8)(1)), (cores),(0),(0),(0))/* provide return value for "not ready" ? */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_CHK_PAGESW_CORE_VOID(cores)                        VX1000_DUMMYREAD((cores))/* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OVL_IS_PAGESW_REQUESTED(cores)                         VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,0, (cores),(0),(0),(0))/* provide return value "no" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_OVERLAY */

/*------------------------------------------------------------------------------ */
/* VX1000_RES_MGMT                                                               */
/* Note: this is a pure project specific feature.                                */
/* The specification comes from the customer, so do not improve.                 */

#if defined(VX1000_RES_MGMT)

#define VX1000_RES_MGMT_MAGIC            0xfec70a18UL

typedef struct
{
  VX1000_UINT32 magicId;                 /* 0x00 */ /* Version 2 */
  VX1000_UINT16 version;                 /* 0x04 */
  /* Resource 0 */
  VX1000_UINT8  ovlConfigItemStart;      /* 0x06 */
  VX1000_UINT8  ovlConfigItemLength;     /* 0x07 */
  VX1000_UINT32 resMgmtEnable;           /* 0x08 */
  /* Resource 1 */
  VX1000_UINT32 ovlRamStart;             /* 0x0C */
  VX1000_UINT32 ovlRamSize;              /* 0x10 */
} VX1000_RES_MGMT_T;

#define VX1000_RES_MGMT_RES_CONFIG_ITEM  (1UL << 0)
#define VX1000_RES_MGMT_RES_OVL_RAM      (1UL << 1)

#define VX1000_RES_MGMT_DATA             VX1000_RES_MGMT_T ResMgmt;
#define VX1000_RES_MGMT_PTR              ((VX1000_UINT32)&gVX1000.ResMgmt)
extern void VX1000_SUFFUN(vx1000_ResMgmtInit)( void );
#define VX1000_RES_MGMT_INIT()           VX1000_SUFFUN(vx1000_ResMgmtInit)();
#define VX1000_ENABLE_ACCESS()           gVX1000.ToolDetectState &= ~(VX1000_TDS_VX_ACCESS_DISABLED);
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_DisableAccess)( void );
#define VX1000_DISABLE_ACCESS()          VX1000_SUFFUN(vx1000_DisableAccess)()
#define VX1000_DISABLE_ACCESS_VOID()     (void)VX1000_SUFFUN(vx1000_DisableAccess)();
#define VX1000_IS_ACCESS_DISABLED()      ((gVX1000.ToolDetectState & (VX1000_TDS_VX_ACCESS_DISABLED)) != 0UL)
#define VX1000_RES_MGMT_VERSION          1

/* Resource Overlay Configuration Item */
#if !defined(VX1000_RES_MGMT_CFG_ITEM_START)
#define VX1000_RES_MGMT_CFG_ITEM_START 0
#endif /* !VX1000_RES_MGMT_CFG_ITEM_START */

#if !defined(VX1000_RES_MGMT_CFG_ITEM_LEN)
#define VX1000_RES_MGMT_CFG_ITEM_LEN   32
#endif /* !VX1000_RES_MGMT_CFG_ITEM_LEN */

#if !defined(VX1000_RES_MGMT_ENABLE_CFG_ITEM)
#define VX1000_RES_MGMT_ENBLVAL_CFG_ITEM 0
#else /* VX1000_RES_MGMT_ENABLE_CFG_ITEM */
#define VX1000_RES_MGMT_ENBLVAL_CFG_ITEM VX1000_RES_MGMT_RES_CONFIG_ITEM
#endif /* VX1000_RES_MGMT_ENABLE_CFG_ITEM */

/* Resource Ram */
#if !defined(VX1000_RES_MGMT_RAM_START)
#define VX1000_RES_MGMT_RAM_START  0
#endif /* !VX1000_RES_MGMT_RAM_START */

#if !defined(VX1000_RES_MGMT_RAM_SIZE)
#define VX1000_RES_MGMT_RAM_SIZE   0
#endif /* !VX1000_RES_MGMT_RAM_SIZE */

#if !defined(VX1000_RES_MGMT_ENABLE_OVL_RAM)
#define VX1000_RES_MGMT_ENBLVAL_OVL_RAM 0
#else /* VX1000_RES_MGMT_ENABLE_OVL_RAM */
#define VX1000_RES_MGMT_ENBLVAL_OVL_RAM VX1000_RES_MGMT_RES_OVL_RAM
#endif /* VX1000_RES_MGMT_OVL_ENABLE */


#else /* !VX1000_RES_MGMT */

#define VX1000_RES_MGMT_INIT()         /* empty */
#define VX1000_DISABLE_ACCESS_VOID()   /* empty */
#define VX1000_DISABLE_ACCESS()        (0) /* provide return value for "there is no VX anyway" */
#define VX1000_ENABLE_ACCESS()         /* empty */
#define VX1000_IS_ACCESS_DISABLED()    (1) /* provide return value for "tool is disabled" */
#define VX1000_RES_MGMT_PTR            0UL
#define VX1000_RES_MGMT_DATA           /* empty */

#endif /* !VX1000_RES_MGMT */


#if defined(VX1000_DISABLE_INSTRUMENTATION)

#define VX1000_DATA                     /* empty */
#define VX1000_INIT()                   /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_START()       /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_INIT_ASYNC_END()         /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET()      (0) /* provide return value for "accepted" */
#define VX1000_EVENT(e)                 VX1000_DUMMYREAD((e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP_EVENT(e, t)    VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (e),(t),(0),(0))) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP_UPDATE(t)      VX1000_DUMMYREAD((t)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_TIMESTAMP()              /* empty */

#else /* !VX1000_DISABLE_INSTRUMENTATION */

/*------------------------------------------------------------------------------ */
/* User functions and macros for DAQ                                             */

#if defined(VX1000_OLDA)

/* Trigger a universal event (TRACE or OLDA; event numbers 0 to 30) */
#define VX1000_EVENT(x)  VX1000_OLDA_EVENT((x)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

/* Trigger a special event (EventNumber=0..0xFFFFFFFF, OldaEventNumbers=31/30) */
/* Note that we can't do the "gVX1000.Olda.EventList[31].EventCounter += 2;" because the array's */
/* size is dynamically assigned by the VX at runtime depending on the current DAQ configuration! */
#define VX1000_SPECIAL_EVENT(e) do                                                     \
  {                                                                                    \
    VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))                                           \
    VX1000_STORE_EVENT((VX1000_UINT32)(e))                                             \
    VX1000_ATOMIC_XOR32X2((/*(VX1000_UINT32)*/&gVX1000.OldaEventNumber), 0x80000000UL) \
  } while(0); /* this never-looping while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_OLDA */

/* Trigger an event or special event (TRACE only; event numbers 0 to 250 and 0x00010000 to 0x0FFFFFFF)*/
#define VX1000_EVENT(e) do                       \
  {                                              \
    VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))     \
    VX1000_STORE_EVENT((e))                      \
  } while(0); /* this never-looping while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#define VX1000_SPECIAL_EVENT(e) VX1000_EVENT((e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_OLDA */

/* Update the ECU timestamp with a given value */
#define VX1000_TIMESTAMP_UPDATE(t)               \
  VX1000_STORE_TIMESTAMP((VX1000_UINT32)(t)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

/* Trigger an event with a given value for ECU timestamp */
#define VX1000_TIMESTAMP_EVENT(e, t) do          \
  {                                              \
    VX1000_STORE_TIMESTAMP((VX1000_UINT32)(t))   \
    VX1000_STORE_EVENT((e))                      \
  } while(0); /* this never-loop-while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */


/* Update the timestamp (optional, only needed if timestamp update rate by events is too slow): */
#define VX1000_TIMESTAMP() VX1000_STORE_TIMESTAMP((VX1000_CLOCK())) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */



/*------------------------------------------------------------------------------ */
/* VX1000 data structure                                                         */
/* Version history (as "new in version"):                                        */
/*  4: OldaPtr                                                                   */
/*  5: Olda integrated at fixed position 0x40                                    */
/*  6: CalPtr                                                                    */
/*  7: ToolCtrlState (written by tool)                                           */
/*  8: ResMgmtPtr, OvlPtr                                                        */
/*  9: FileVersion, FeatureFlags0, TimerXXX, xxxDur-pointers, ErrLog             */

#define VX1000_STRUCT_VERSION          9UL
#define VX1000_STRUCT_MAGIC            0xFEC70A08UL

#define VX1000_ECUFEAT_FKLINSTRUMENTED (1UL << 0) /* The application provides support to download and start an external flash kernel*/
#define VX1000_ECUFEAT_MX_FLASHSTART   (1UL << 1) /* reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_FLASHMODIFY  (1UL << 2) /* reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_SOFTRESET    (1UL << 3) /* reserved for mailbox flashing */
#define VX1000_ECUFEAT_MX_CALPAGE_RW   (1UL << 4) /* The application wants to handle calpage up/downloads manually via mailbox callbacks */
#define VX1000_ECUFEAT_MX_CALPAGE_GSC  (1UL << 5) /* The application provides mailbox handling for get/set/copy calpage commands */
#define VX1000_ECUFEAT_STIMWT_DURATION (1UL << 6) /* The application provides a snapshot of all STIM events' busy waiting times */
#define VX1000_ECUFEAT_STIMRT_DURATION (1UL << 7) /* The application provides a snapshot of all STIM events' round trip times and a global timeout counter */
#define VX1000_ECUFEAT_STIMRT_HISTOGR  (1UL << 8) /* The application provides a histogram of one STIM event's round trip times since ECU boot */

typedef struct
{
  VX1000_UINT32   EventNumber;         /* 0x00 */
  VX1000_UINT32   EventTimestamp;
  VX1000_UINT32   MagicId;
  VX1000_UINT32   Version;
  VX1000_UINT32   GetIdPtr;            /* 0x10 */
  VX1000_UINT32   GetIdLen;
  VX1000_UINT32   XcpMailboxPtr;
  VX1000_UINT32   StimCtrlPtr;
  VX1000_UINT32   RamSynchField;       /* 0x20 */
  VX1000_UINT32   ToolDetectState;
  VX1000_UINT32   OldaPtr;
  VX1000_UINT32   OldaEventNumber;
  VX1000_UINT32   CalPtr;              /* 0x30 */
  VX1000_UINT32   ToolCtrlState;
  VX1000_UINT32   ErrLogAddr;          /* previous: VX1000_UINT32 TimestampInfoMant is no longer used, redefined in v9 */
  VX1000_UINT8    ErrLogSize;          /* previous: VX1000_INT16  TimestampInfoExpDiv, no longer used, redefined in v9 */
  VX1000_UINT8    ErrLogIndex;
  VX1000_UINT16   FileVersion;
  VX1000_UINT32   ResMgmtPtr;          /* 0x40 */
  VX1000_UINT32   OvlPtr;
  VX1000_UINT32   FeatureFlags0;
  VX1000_UINT32   TimerFreqkHz;
  VX1000_UINT32   TimerAddr;           /* 0x50 */
  VX1000_UINT8    TimerAddrRegion;
  VX1000_UINT8    TimerSize;
  VX1000_UINT8    TimerOffset;
  VX1000_UINT8    TimerDirection;
  VX1000_UINT32   StimDurArrayPtr;
  VX1000_UINT32   OldaDurArrayPtr;
                                       /* 0x60; */
  /* note: no pointer to VX1000_COLDSTART_BENCHMARK_DATA because that info is not settled, yet */
  /* note: no pointer to VX1000_HOOK_CONTROL_DATA because that part of the driver is typically outsourced now */
  /* note: no pointers to gVX1000_OLDA_TransferCount[] and gVX1000_OLDA_TransferSize[] because the VX can collect such info internally */

  VX1000_OLDA_DATA                     /* no fix offset (note: FW < 1.8 expected 0x40 during cold-start!) */

  VX1000_STIM_DATA                     /* no fix offset */

  VX1000_MAILBOX_DATA                  /* no fix offset */

  VX1000_OVL_DATA                      /* no fix offset */

  VX1000_RES_MGMT_DATA                 /* no fix offset */

  VX1000_ERRLOG_DATA                   /* no fix offset */

  /* note: other VX data not included by now to not loose backward compatibility of old A2L files; this will be changed changed when */
  /* there'd be a user's requirement for specific linkage of all VX objects or there is a requirement to split ROM and RAM anyway... */
} VX1000_STRUCT_T;

/*------------------------------------------------------------------------------ */
/* VX1000_INIT_ASYNC_START(), VX1000_INIT_ASYNC_END(); legacy VX1000_DATA dummy  */
/* API for declaring and initialising the global VX1000 data needed for VX1000   */
/* Must be called before any other VX1000_xxxx() routine is called but _after_   */
/* timestamp provider has been initialised                                       */

extern void VX1000_SUFFUN(vx1000_Init)(void);
#define VX1000_INIT() VX1000_SUFFUN(vx1000_Init)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_InitAsyncStart)(void);
#define VX1000_INIT_ASYNC_START() VX1000_SUFFUN(vx1000_InitAsyncStart)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_InitAsyncEnd)(void);
#define VX1000_INIT_ASYNC_END() VX1000_SUFFUN(vx1000_InitAsyncEnd)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#if defined(VX1000_SOFTRESET_TIMEOUT_MS)
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_PrepareSoftreset)(void);
#define VX1000_PREPARE_SOFTRESET() VX1000_SUFFUN(vx1000_PrepareSoftreset)() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID() (void)VX1000_SUFFUN(vx1000_PrepareSoftreset)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_SOFTRESET_TIMEOUT_MS */
#define VX1000_PREPARE_SOFTRESET()      (0) /* provide return value for "accepted" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_PREPARE_SOFTRESET_VOID() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_SOFTRESET_TIMEOUT_MS */

/* Define the global data needed for VX1000 (the user must ensure that the VX1000_STRUCT_DATA part is linked first!) */
#define VX1000_DATA /* now an empty dummy because the actual data is already declared in VX1000.c module directly! */

/* include user-defined lines with optional section pragmas to force individual linkage of VX1000 structure data. */
/* Note that we're using nested section switches here (which might be unsupported by some compilers but has the  */
/* advantage of not requiring #undefs as those would violate the MISRA coding guidelines).                       */
#define VX1000_BEGSECT_VXSTRUCT_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_BEGSECT_VXSTRUCT_H_UNDO

#if defined(VX1000_STRUCT_ADDR)
#error "VX1000_STRUCT_ADDR must not be defined (in VX1000_cfg.h), because this feature is not supported for this microcontroller!"
#else /* !VX1000_STRUCT_ADDR */
#if defined(VX1000_MEMORY_SECTION)
#define VX1000_STRUCT_DATA VX1000_MEMORY_SECTION volatile VX1000_STRUCT_T gVX1000;
#else /* !VX1000_MEMORY_SECTION */
#define VX1000_STRUCT_DATA volatile VX1000_STRUCT_T gVX1000;
#endif /* !VX1000_MEMORY_SECTION */
#endif /* !VX1000_STRUCT_ADDR */
extern VX1000_STRUCT_DATA

/* include user-defined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_ENDSECT_VXSTRUCT_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_ENDSECT_VXSTRUCT_H_UNDO

/* include user-defined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_ENDSECT_VXMODULE_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_ENDSECT_VXMODULE_H_UNDO

#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
/* include user-defined lines with optional section pragmas to force individual linkage of EMEM header data. */
#define VX1000_BEGSECT_EMEM_HDR_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_BEGSECT_EMEM_HDR_H_UNDO

extern VX1000_EMEM_HDR_DATA

/* include user-defined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_ENDSECT_EMEM_HDR_H
#include "VX1000_cfg.h"  /* PRQA S 0883*/ /* Willingly violating MISRA Rule 19.15: this file is included multiple times because it contains multiple disjunct parts that each are filtered exactly once by preprocessor conditions */ /* PRQA S 5087*/ /* Willingly violating MISRA Rule 19.1: this file is included multiple at exactly those lines where it is needed to expand to the desired lines. Inclusion/expansion of those lines at the top of this file would not make sense and lead to compile errors */
#define VX1000_ENDSECT_EMEM_HDR_H_UNDO
#endif /* VX1000_OVLENBL_PERSISTENT_EMEM */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_H */

