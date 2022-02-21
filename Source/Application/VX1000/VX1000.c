/*------------------------------------------------------------------------------- */
/* VX1000.c                                                                       */
/* Vector VX1000 Application Driver for Renesas V850E2 and Renesas RH850          */
/* Version 3.00.03  20.01.2016                                                    */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* Don't modify this file, settings are defined in VX1000_cfg.h                   */
/*------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/  * advisory and required rules 11.x and 17.x "usage of pointers, pointer arithmetic                                      /
/    and casts between differently typed or differently qualified pointers"                                                /
/     - violated because copying data from and to arbitrary locations is the core feature of this module                   /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 19.1 "location of file inclusions"                                                                      /
/     - violated because there exists no MISRA-conform workaround without loosing essential functionality                  /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.4 "complete statement inside a macro"                                                                /
/     - todo (not worked around yet because it's not clear whether this is a user's requirement or not - see comment)      /
/                                                                                                                          /
/  * advisory rule 19.7 "functions vs. macros"                                                                             /
/     - violated because possible workarounds induce a significant performance loss                                        /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.15 "repeated file inclusion"                                                                         /
/     - just a phantom detection by the checker tool, no real violation                                                    /
/                                                                                                                          /
/  * advisory and required rules 5.2, 8.8, 12.13, 17.4, 19.4                                                               /
/     - only violated in dead code (function calcAdd32() - todo: solve before using this code in new features!)            /
/                                                                                (checked in MPC version v2.13)            /
/------------------------------------------------------------------------------------------------------------------------ */


#include "VX1000.h" /* PRQA S 0883*/ /* Actually not violating MISRA Rule 19.15: this file is included only once into this module */

#if !defined(VX1000_TARGET_X850)
#error This driver is not meant for the target that you are trying to use it for!
#endif /* !VX1000_TARGET_X850 */

#if defined(VX1000_MAILBOX_PRINTF)
#include <stdarg.h>
#if !defined(VX1000_PRINTF_MINIMAL)
#include <stdio.h> /* this violates MISRA Rule 20.9, but the user is responsible to turn off printf in production code while the features still are very useful in debug code */
#endif /* !VX1000_PRINTF_MINIMAL */
#endif /* VX1000_MAILBOX_PRINTF */

#define VX1000_FILE_VERSION_MAJOR_C    3U
#define VX1000_FILE_VERSION_MINOR_C    0U
#define VX1000_FILE_VERSION_PATCH_C    3U

#define VX1000_FILE_VERSION_C          ( ((((VX1000_FILE_VERSION_MAJOR_C) & 0xfU) << 12U) | (((VX1000_FILE_VERSION_MINOR_C) & 0x7fU) << 5U)) | (((VX1000_FILE_VERSION_STATUS) << 3U) | (VX1000_FILE_VERSION_PATCH_C & 0x7U)) )
#if ((VX1000_FILE_VERSION_C) != (VX1000_FILE_VERSION))
#error "version of VX1000.h does not match version of VX1000.c!"
#endif /* VX1000_FILE_VERSION_C != VX1000_FILE_VERSION */

/* A word about the version check: the configuration header has only major and minor while patchlevel  */
/* and status are ignored via inheritance from the lead versions. We use the warning directive because */
/* a mismatch is not as important as to signal an error. But if a compiler does not support warnings,  */
/* it will produce an error message which is OK, too. The user can correct the problem by reviewing    */
/* his configuration for incompatibilities and then incrementing the version numbers accordingly.      */
#define VX1000_FILE_VERSION_H ( ((((VX1000_FILE_VERSION_MAJOR_H) & 0xfU) << 12U) | (((VX1000_FILE_VERSION_MINOR_H) & 0x7fU) << 5U)) | (((VX1000_FILE_VERSION_STATUS) << 3U) | ((VX1000_FILE_VERSION_PATCH) & 0x7U)) )
#if ((VX1000_FILE_VERSION_H) != (VX1000_FILE_VERSION))
/* note: not all compilers support the warning directive, and an error directive would be too hard in this case:
#warning "version of VX1000_cfg.h does not match version of VX1000.h!"
*/
#endif /* VX1000_FILE_VERSION_H != VX1000_FILE_VERSION */


#if defined(VX1000_DISABLE_INSTRUMENTATION)

/* Some compilers (e.g. cosmic) fail creating completely empty object files. Allow the user to provide a workaround: */
VX1000_EMPTYFILE_DUMMYDECL

#else /* !VX1000_DISABLE_INSTRUMENTATION */


/* include user-defined lines with optional section pragmas to force individual linkage of VX1000 code and/or data: */
#define VX1000_BEGSECT_VXMODULE_C
#include "VX1000_cfg.h"
#define VX1000_BEGSECT_VXMODULE_C_UNDO


/* --- local prototypes --- */
#if defined(VX1000_STIM) && defined(VX1000_STIM_BENCHMARK)
static void VX1000_SUFFUN(vx1000_StimBenchmarkStimCheck)( void );
#endif /* VX1000_STIM && VX1000_STIM_BENCHMARK */
#if (defined(VX1000_OVERLAY) && (!defined(VX1000_COMPILED_FOR_SLAVECORES)))
static void VX1000_SUFFUN(vx1000_OverlayInit)( void );
#define VX1000_OVERLAY_INIT() VX1000_SUFFUN(vx1000_OverlayInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
static VX1000_UINT8 gVX1000_XCP_CalPage;
static VX1000_UINT8 gVX1000_ECU_CalPage;
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */
static void VX1000_SUFFUN(vx1000_EmemHdrInit)(void);
#if (defined(VX1000_INIT_CAL_PAGE)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE))
#define VX1000_OVERLAY_HW_INIT() VX1000_INIT_CAL_PAGE()   /* overload the VX1000 function by user callback (to e.g. CCP driver) */
#endif /* VX1000_INIT_CAL_PAGE && !VX1000_OVERLAY_VX_CONFIGURABLE */
#if (!defined(VX1000_INIT_CAL_PAGE)) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE))
static void VX1000_SUFFUN(vx1000_OverlayHwInit)(void);
#define VX1000_OVERLAY_HW_INIT() VX1000_SUFFUN(vx1000_OverlayHwInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_INIT_CAL_PAGE_INTERNAL
#endif /* !VX1000_INIT_CAL_PAGE & !VX1000_OVERLAY_VX_CONFIGURABLE */
static VX1000_UINT8 VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_UINT32 size, VX1000_UINT32 target, VX1000_UINT32 source1, VX1000_UINT32 source2);
#endif /* VX1000_OVERLAY & !VX1000_COMPILED_FOR_SLAVECORES */
#if ((!defined(VX1000_OVERLAY)) || ((defined(VX1000_COMPILED_FOR_SLAVECORES)) || defined(VX1000_OVERLAY_VX_CONFIGURABLE)))
#define VX1000_OVERLAY_HW_INIT() /* empty */
#endif /* !VX1000_OVERLAY | VX1000_COMPILED_FOR_SLAVECORES | VX1000_OVERLAY_VX_CONFIGURABLE */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#if !defined(VX1000_GET_CAL_PAGE)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_GetCalPage)( VX1000_UINT8 segment, VX1000_UINT8 mode );
#define VX1000_GET_CAL_PAGE(seg, mod) VX1000_SUFFUN(vx1000_GetCalPage)((VX1000_UINT8)(seg), (VX1000_UINT8)(mod)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_GET_CAL_PAGE_INTERNAL
#endif /* !VX1000_GET_CAL_PAGE */
static VX1000_UINT8 VX1000_SUFFUN(vx1000_SetCalPage)( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode, VX1000_UINT8 onStartup);
#define VX1000_WRP_SET_CAL_PAGE(seg, pag, mod, stup) VX1000_SUFFUN(vx1000_SetCalPage)((VX1000_UINT8)(seg), (VX1000_UINT8)(pag), (VX1000_UINT8)(mod), (VX1000_UINT8)(stup)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_WRP_SET_CAL_PAGE_VOID(seg, pag, mod, stup) (void)VX1000_WRP_SET_CAL_PAGE((seg), (pag), (mod), (stup)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#if defined(VX1000_SET_CAL_PAGE)
#define VX1000_SET_CAL_PAGE_EXTERNAL
#else /* !VX1000_SET_CAL_PAGE */
#define VX1000_SET_CAL_PAGE_INTERNAL
#endif /* !VX1000_SET_CAL_PAGE */
#else /* !VX1000_MAILBOX | !VX1000_MAILBOX_OVERLAY_CONTROL | VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_WRP_SET_CAL_PAGE(     seg, pag, mod, stup)  (VX1000_CRC_OUT_OF_RANGE)
#define VX1000_WRP_SET_CAL_PAGE_VOID(seg, pag, mod, stup)  /* empty */
#endif  /* !VX1000_MAILBOX | !VX1000_MAILBOX_OVERLAY_CONTROL | VX1000_COMPILED_FOR_SLAVECORES */
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)) && ((!defined(VX1000_COMPILED_FOR_SLAVECORES)) && !defined(VX1000_OVERLAY_VX_CONFIGURABLE))
#if !defined(VX1000_COPY_CAL_PAGE)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_CopyCalPage)( VX1000_UINT8 srcSeg, VX1000_UINT8 srcPage, VX1000_UINT8 dstSeg, VX1000_UINT8 dstPage );
#define VX1000_COPY_CAL_PAGE(sseg, spag, dseg, dpag) VX1000_SUFFUN(vx1000_CopyCalPage)((VX1000_UINT8)(sseg), (VX1000_UINT8)(spag), (VX1000_UINT8)(dseg), (VX1000_UINT8)(dpag)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_COPY_CAL_PAGE_INTERNAL
#endif /* !VX1000_COPY_CAL_PAGE */
#endif  /* VX1000_MAILBOX && VX1000_MAILBOX_OVERLAY_CONTROL && !VX1000_COMPILED_FOR_SLAVECORES && !VX1000_OVERLAY_VX_CONFIGURABLE */

#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
static VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayWriteEcuDescr)(void);
static VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayReadEcuDescr)(void);
#endif /* VX1000_OVERLAY & VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX & VX1000_MAILBOX & VX1000_MAILBOX_OVERLAY_CONTROL*/

#if (defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES)))
#if (defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH))
static volatile VX1000_UINT32 gVX1000_MX_mta;
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL || VX1000_MAILBOX_FLASH */
#if defined(VX1000_MAILBOX_PRINTF)
static void VX1000_SUFFUN(vx1000_MailboxPutchar)( VX1000_CHAR character );
#endif /* VX1000_MAILBOX_PRINTF */
#endif /* VX1000_MAILBOX & !VX1000_COMPILED_FOR_SLAVECORES */

#if defined(VX1000_STIM)
#if (!defined(VX1000_RESET_STIM_TIMEOUT)) || (!defined(VX1000_CHECK_STIM_TIMEOUT))
static VX1000_UINT32 VX1000_SUFFUN(SetTimeoutUs)(VX1000_UINT32 t);
static VX1000_UINT8 VX1000_SUFFUN(CheckTimeout)(VX1000_UINT32 timeout);
#endif /* !VX1000_RESET_STIM_TIMEOUT || !VX1000_CHECK_STIM_TIMEOUT */
#if defined(VX1000_STIM_FORCE_V1)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCheckCounters)(VX1000_UINT8 stim_event);
#if defined(VX1000_STIM_BY_OLDA)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCheckBuffer)(VX1000_UINT8 stim_event);
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCopyBuffer)(VX1000_UINT8 stim_event);
#if defined(VX1000_BYPASS_ALL_CHANS_STIMD)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassAreAllChansStimd)(void);
#endif /* VX1000_BYPASS_ALL_CHANS_STIMD */
#endif /* VX1000_STIM_BY_OLDA */
#endif /* VX1000_STIM_FORCE_V1 */
#if defined(VX1000_HOOK_BASED_BYPASSING)
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassHbbHookValid)(VX1000_UINT32 HookID);
#endif /* VX1000_HOOK_BASED_BYPASSING */
#endif /* VX1000_STIM */
#if defined(VX1000_DETECTION) || defined(VX1000_TARGET_TRICORE)
static void VX1000_SUFFUN(vx1000_DetectVxAsyncStart)(void);
#define VX1000_DETECT_VX_ASYNC_START()          VX1000_SUFFUN(vx1000_DetectVxAsyncStart)(); /* usable as a whole statement */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
static VX1000_UINT8 VX1000_SUFFUN(vx1000_DetectVxAsyncEnd)(void);
#define VX1000_DETECT_VX_ASYNC_END(     )       VX1000_SUFFUN(vx1000_DetectVxAsyncEnd)()    /* usable in/as an expression  */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DETECT_VX_ASYNC_END_VOID() (void)VX1000_SUFFUN(vx1000_DetectVxAsyncEnd)();   /* usable as a whole statement */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE */
#define VX1000_DETECT_VX_ASYNC_START()            /* empty */
#define VX1000_DETECT_VX_ASYNC_END(     )  (0)    /* means "no VX detected" */
#define VX1000_DETECT_VX_ASYNC_END_VOID()         /* empty */
#endif /* !VX1000_DETECTION & !VX1000_TARGET_TRICORE */

#define VX1000_CALPAGE_RAM             1
#define VX1000_CALPAGE_FLASH           0


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_InitAsyncStart                                                                                       */
/* API name:      VX1000_INIT_ASYNC_START                                                                                     */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000_* function.                                             */
/* Termination:   May leave internal data in an inconsistent state.                                                           */
/*                No problems on reactivation.                                                                                */
/* Precondition1: The timer used by VX1000_CLOCK() must be up and running.                                                    */
/* Description:   Initializes all global VX1000 data structures.                                                              */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_InitAsyncStart)(void)
{
#if !defined(VX1000_COMPILED_FOR_SLAVECORES)
#if defined(VX1000_RUNNING_ON_MAINCORE)
  if (VX1000_RUNNING_ON_MAINCORE()) /* always true on single-core MCU, otherwise needs compiler specific assembly */
#endif /* VX1000_RUNNING_ON_MAINCORE */
  {
#if defined(VX1000_TARGET_TRICORE)
    /* Tricore specific trace hardware init: */

#if !defined(VX1000_SW_RSTOUT_AVAILABLE)  /* TODO: this config switch shall be renamed because it actually specifies whether the RSTOUT communication between ECU and FW works or not */
    /* Check if last Reset was a SW Reset */
    VX1000_UINT32 scuRstatMasked;
    if (VX1000_ECU_IS_AURIX())
    {
      scuRstatMasked = (*(volatile VX1000_UINT32*)(volatile void*)((VX1000_UINT8*)0UL + (0xF0036050UL))) & 0x00000010UL;
    }
    else
    {
      scuRstatMasked = (*(volatile VX1000_UINT32*)(volatile void*)((VX1000_UINT8*)0UL + (0xF0000550UL))) & 0xFFFFFFFEUL;
    }
    if (scuRstatMasked == 0x00000010UL)
    {
      /* Check if the gVX1000 data structure is still valid */
      if ((gVX1000.MagicId == (VX1000_STRUCT_MAGIC)) && (gVX1000.Version == (VX1000_STRUCT_VERSION)))
      {
        VX1000_UINT32 t,n;

        /* Re-enable OLDA trace */
        /* Disable OLDA write trap generation (derivative dependent) */
        switch ((VX1000_MCREG_CBS_JTAGID) & (VX1000_JTAGID_PN_MASK))
        {
          case VX1000_JTAGID_PN_TC172x:
          case VX1000_JTAGID_PN_TC1798:
            (*(volatile VX1000_UINT32*)(volatile void*)((VX1000_UINT8*)0UL + (0xF8000520UL))) = 0x00000003UL; /* AudoMax trace control register OVRCON */
            break;
          case VX1000_JTAGID_PN_TC1387:
          case VX1000_JTAGID_PN_TC1767:
          case VX1000_JTAGID_PN_TC178x:
          case VX1000_JTAGID_PN_TC1797:
            (*(volatile VX1000_UINT32*)(volatile void*)((VX1000_UINT8*)0UL + (0xF8700804UL))) = 0x00000003UL; /* Tricore Memory Control Register register LMU_MEMCON */
            break;
          default:
            (*(volatile VX1000_UINT32*)(volatile void*)((VX1000_UINT8*)0UL + (0xF8700820UL))) = 0x00000003UL; /* Aurix Memory Control Register register LMU_MEMCON */
            break;
        }

        VX1000_SPECIAL_EVENT((VX1000_ECU_EVT_SW_RESET))
        gVX1000.ToolDetectState |= VX1000_TDS_APPRST;

        /* Wait 10ms */
        /* First create enough trace traffic to empty the tile buffer */
        /* Give VX a chance to set the timestamp offset */
        t = VX1000_CLOCK();
        n = 0;
        while (((VX1000_CLOCK()) - t) < ((VX1000_CLOCK_TICKS_PER_MS) * 10UL))
        {
          for (n++; n < 0x1000UL; n++)  /* Generate max. 64K Trace data */
          {
            VX1000_TIMESTAMP()
            VX1000_TIMESTAMP()
            VX1000_TIMESTAMP()
            VX1000_TIMESTAMP()
            VX1000_TIMESTAMP()
          }
        }
        return; /* Success */  /* TODO MISRA !!! */
      }
      else
      {
        VX1000_SPECIAL_EVENT((VX1000_ECU_EVT_SW_RESET_FAIL))
      }
    }
#endif /* !VX1000_SW_RSTOUT_AVAILABLE */
#endif /* VX1000_TARGET_TRICORE */

    /* Initialize the gVX1000 data structure   */
    gVX1000.MagicId = 0UL;
    VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    /* VX1000_STORE_EVENT(0) -- member 'Eventnumber' is not touched, to be sure no event is triggered */
    gVX1000.Version = VX1000_STRUCT_VERSION; /* note: bits 8..31 are checked by old FW versions to be 0x000000 */
    gVX1000.GetIdPtr = VX1000_ECUID_PTR; /* PRQA S 0311 */ /* GetIdPtr is never used for writing, so MISRA Rule 11.5 is not relevant here */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable either contains a pointer to an actual object or an integral magic number for "invalid" */  /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
    gVX1000.GetIdLen = VX1000_ECUID_LEN;
    gVX1000.XcpMailboxPtr = VX1000_MAILBOX_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
    gVX1000.StimCtrlPtr = VX1000_STIM_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
    gVX1000.RamSynchField = 0UL;
    gVX1000.ToolDetectState = 0UL;
    gVX1000.OldaPtr = VX1000_OLDA_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
    gVX1000.OvlPtr = VX1000_OVL_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
    gVX1000.ResMgmtPtr = VX1000_RES_MGMT_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
#if defined(VX1000_TARGET_TRICORE)
    gVX1000.OldaEventNumber = 0xF00004A0UL; /* on Tricore, we support ONLY the trigreg methods (via VX1000_MCREG_OCDS_TRIGS), not the RAM method */
#elif defined(VX1000_OLDA_AUDMBR_REG_ADDR)
    gVX1000.OldaEventNumber = VX1000_OLDA_AUDMBR_REG_ADDR; /* on SHx, we support conditionally the trigreg method (via AUD_MBR) */
#elif defined(VX1000_OLDA_DTS_BASE_ADDR)
    gVX1000.OldaEventNumber = VX1000_OLDA_DTS_BASE_ADDR;
#else  /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
    gVX1000.OldaEventNumber = 0UL;
#endif /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
    gVX1000.CalPtr = 0xFFFFFFFFUL ^ gVX1000.OldaEventNumber; /* note: unused CalPtr abused for OLDA in v3.x */
    gVX1000.ToolCtrlState = 0UL;
    gVX1000.FileVersion = VX1000_FILE_VERSION;
#if 0
//    /* start of obsolete code (we'll use another, yet to be defined method to store the info ...) */
//    /* ASAM/XCP timestamp info: bits 0..15: TIMESTAMP_TICKS (per UNIT), 16..18: TIMESTAMP_MODE.SIZE (always 4 with VX), /
//    /  19: TIMESTAMP_MODE.FIXED (always on with VX), 20..23: TIMESTAMP_MODE.UNIT , 24..31: currently reserved (0x00)   */
////#if   ((VX1000_CLOCK_TICKS_PER_MS) <= 65UL )
////    gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_S)          ) | (0x009c0000UL)); /* [s] */
////#elif ((VX1000_CLOCK_TICKS_PER_MS) <= 0xFFFFUL )
//    gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_MS)         ) | (0x006c0000UL)); /* [ms] */
////#elif ((VX1000_CLOCK_TICKS_PER_US) <= 0xFFFFUL )
////    gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_US)         ) | (0x003c0000UL)); /* [us] */
////#else
////    gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_US) / 1000UL) | (0x000c0000UL)); /* [ns] */
////#endif
    /* the newer high resolution approach, yet not agreed by all parties */
    /* attention: do not evaluate the resolution defines in the preprocessor because they may contain function calls! */
    /* step 1: reduce the fraction VX1000_CLOCK_TICKS_PER_BASE/VX1000_CLOCK_TICKS_BASE_NS by 2^x */
    /* step 2: initialise the signed shift count to 0 */
    /* step 3: while (VX1000_CLOCK_TICKS_BASE_NS) >= 1024) decrement shift count by 1 and divide VX1000_CLOCK_TICKS_BASE_NS by 2 */
    /* step 4: store the "mantissa" (no implicit bits, 0 is zero), the "signed exponent" to the power of 2 and the "denominator" */
    /*         similar to this code: */
    gVX1000.TimestampInfoMant = (VX1000_UINT32)(VX1000_CLOCK_TICKS_PER_BASE); /* will be used in v9 */
    gVX1000.TimestampInfoExpDiv = ((VX1000_UINT16)((VX1000_CLOCK_TICKS_BASE_NS) & 0x03FFU)) | ((VX1000_UINT16)(shiftcount)<<10U); /* will be used in v9 */
    /* the tool can use this formula to find out the resolution in ns: */
    /* res_ns = ((gVX1000.TimestampInfoExpDiv < 0)? (gVX1000.TimestampInfoMant >>-(gVX1000.TimestampInfoExpDiv>>10)):(gVX1000.TimestampInfoMant <<(gVX1000.TimestampInfoExpDiv>>10)))
    /         / (((gVX1000.TimestampInfoExpDiv & 0x03FF) != 0)? (gVX1000.TimestampInfoExpDiv & 0x03FF):(0x0400)); */
#else /* !0 */
    gVX1000.ErrLogAddr = VX1000_ERRLOG_ADDR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
    gVX1000.ErrLogSize = VX1000_ERRLOG_SIZE;
    gVX1000.ErrLogIndex = 0;
#if VX1000_ERRLOG_SIZE != 0   /* signal that the ring buffer index has not wrapped, yet: */
    ((VX1000_UINT16 *)(VX1000_ERRLOG_ADDR))[(VX1000_ERRLOG_SIZE) - 1] = 0U;  /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
#endif /* VX1000_ERRLOG_SIZE */
#endif /* !0 */
#if 0 /* slow clock support dropped to be able to support GHz clocks ... */
    if ((VX1000_CLOCK_TICKS_PER_MS) > 4294967UL)
    {
      VX1000_ERRLOGGER(VX1000_ERRLOG_TM_RESO_TOO_HIGH)
      gVX1000.TimerFreqHz = 0; /* resolution cannot be expressed in 32 bits */
    }
    else
#endif /* 0 */
    {
      gVX1000.TimerFreqkHz = VX1000_CLOCK_TICKS_PER_MS;
    }
    gVX1000.TimerAddr = VX1000_CLOCK_TIMER_ADDR; /* zero is interpreted as "not accessible" */
    gVX1000.TimerAddrRegion = 0; /* the VX FW currently supports only 0="memory-mapped hardware register in standard region" */
    gVX1000.TimerSize = VX1000_CLOCK_TIMER_SIZE; /* zero is interpreted as "not accessible" */
    gVX1000.TimerOffset = 0; /* the VX FW currently supports only 0="the LSB of the 32bit-value at TimerAddr is also the LSB of the actual count" */
    gVX1000.TimerDirection = 0;/* the VX FW currently supports only up-counting timers */
    gVX1000.StimDurArrayPtr = VX1000_STIM_DURARRAY_PTR;  /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
    gVX1000.OldaDurArrayPtr = VX1000_OLDA_DURARRAY_PTR;  /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
    gVX1000.FeatureFlags0 = 0UL
#if defined(VX1000_FKL_SUPPORT_ADDR)
                          | (VX1000_ECUFEAT_FKLINSTRUMENTED)
#endif /* VX1000_FKL_SUPPORT_ADDR */
#if defined(VX1000_STIM) && defined(VX1000_STIMWAIT_BENCHMARK)
                          | (VX1000_ECUFEAT_STIMWT_DURATION)
#endif /* VX1000_STIM && VX1000_STIMWAIT_BENCHMARK */
#if defined(VX1000_STIM) && defined(VX1000_STIM_BENCHMARK)
                          | (VX1000_ECUFEAT_STIMRT_DURATION)
#endif /* VX1000_STIM && VX1000_STIM_BENCHMARK */
#if (defined(VX1000_STIM) && defined(VX1000_STIM_BENCHMARK)) && defined(VX1000_STIM_HISTOGRAM)
                          | (VX1000_ECUFEAT_STIMRT_HISTOGR)
#endif /* VX1000_STIM && VX1000_STIM_BENCHMARK && VX1000_STIM_HISTOGRAM*/
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)
                          | (VX1000_ECUFEAT_MX_CALPAGE_GSC)
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_OVERLAY_CONTROL */
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_CAL_READ_WRITE)
                          | (VX1000_ECUFEAT_MX_CALPAGE_RW)
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_CAL_READ_WRITE */
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_FLASH)
                          | (VX1000_ECUFEAT_MX_FLASHSTART)
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_FLASH */
                          ;
    if ( ((volatile VX1000_UINT8 *)&gVX1000.ResMgmtPtr) != &(((volatile VX1000_UINT8 *)&gVX1000)[0x40]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_STRUCT_T, ResMgmtPtr)) != 0x40) throws even more warnings */
    {
      gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
      VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
    }
    VX1000_OLDA_INIT()
    VX1000_MAILBOX_INIT()
    VX1000_OVERLAY_INIT()
    VX1000_RES_MGMT_INIT()

#if defined(VX1000_STIM)
    VX1000_STIM_INIT()
    VX1000_STIM_BENCHMARK_INIT()
    gVX1000.Stim.TimeoutCtr = 0;
    gVX1000.Stim.TimeoutCtr2 = 0;
#endif /* VX1000_STIM */
    if ((VX1000_IS_BYPASS_RESUME_ALLOWED()) == 0)
    {
      gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_NO_BYP_RESUME);
    }

#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
    VX1000_HOOK_INIT()
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */

#if defined(VX1000_TARGET_TRICORE)
    /* Tricore: Lock DAP in 2 PIN mode to improve tool communication during coldstart */
    if (VX1000_ECU_IS_AURIX())
    {
      /* Register is ENDINIT protected! */
      /* ?! VX1000_MCREG_OCDS_OIFM =  0x00000000UL; ?! */ /* Two-pin DAP (legacy) */
      ; /* Semicolon here for MISRA */
    }
    else
    {
      /* This is only possible in 2 PIN mode with the VX1542 FPGA POD */
      VX1000_MCREG_OCDS_OCNTRL = 0x00000007UL;  /* DJMODE = 01 Two-pin DAP with disabled BYPASS */
    }
#endif /* VX1000_TARGET_TRICORE */

    gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_INIT);
    gVX1000.MagicId = (VX1000_UINT32)(VX1000_STRUCT_MAGIC);

    VX1000_DETECT_VX_ASYNC_START()

    VX1000_SPECIAL_EVENT(VX1000_EVENT_STRUCT_INIT) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
  }
#if defined(VX1000_RUNNING_ON_MAINCORE)
  else
#endif /* VX1000_RUNNING_ON_MAINCORE */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */
#if defined(VX1000_RUNNING_ON_MAINCORE) || defined(VX1000_COMPILED_FOR_SLAVECORES)
  {
    while (gVX1000.MagicId != (VX1000_UINT32)VX1000_STRUCT_MAGIC)
    {
      ; /* busy wait until another core initialized VX1000_DATA */
    }
  }
#endif /* VX1000_RUNNING_ON_MAINCORE | VX1000_COMPILED_FOR_SLAVECORES */


  /* optional: VX1000_BreakpointInit(); /-* has to be performed per core */

}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_InitAsyncEnd                                                                                         */
/* API name:      VX1000_INIT_ASYNC_END                                                                                       */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000_* function.                                             */
/* Termination:   May leave internal data in an inconsistent state.                                                           */
/*                No problems on reactivation.                                                                                */
/* Precondition1: vx1000_InitAsyncStart must have been called.                                                                */
/* Description:   Waits for end of start-up handshake with VX; Synchronises instrumentation on the cores.                     */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_InitAsyncEnd)(void)
{
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
  if (0==VX1000_RUNNING_ON_MAINCORE())
#endif /* VX1000_RUNNING_ON_MAINCORE & !VX1000_COMPILED_FOR_SLAVECORES */
#if defined(VX1000_RUNNING_ON_MAINCORE) || defined(VX1000_COMPILED_FOR_SLAVECORES)
  {
    if ((gVX1000.ToolDetectState & (VX1000_UINT32)((VX1000_TDS_COLDSTART_DELAY_REQ) | (VX1000_TDS_COLDSTART_DELAY))) != 0)
    {
      while (0 == (gVX1000.ToolDetectState & (VX1000_UINT32) ((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT))))
      {
        ; /* busy wait for the main core to complete the handshake */
      }
    }
#if defined(VX1000_OVLENBL_HW_INIT_PER_CORE)
    VX1000_OVERLAY_HW_INIT()
#endif /* VX1000_OVLENBL_HW_INIT_PER_CORE */
  }
#endif /* VX1000_RUNNING_ON_MAINCORE | VX1000_COMPILED_FOR_SLAVECORES */
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
  else
#endif /* VX1000_RUNNING_ON_MAINCORE & !VX1000_COMPILED_FOR_SLAVECORES */
#if !defined(VX1000_COMPILED_FOR_SLAVECORES)
  if (VX1000_DETECT_VX_ASYNC_END() != 0) /* complete the VX1000 handshake */
  {
    ; /* If tool detection was successful, no action on V850/RH850. Semicolon here for MISRA */
  }
  else
  {
#if defined(VX1000_TARGET_TRICORE)
    /* Lock DAP in the user selected pin mode */
    if (VX1000_ECU_IS_AURIX())
    {
      /* Register is ENDINIT protected! */
      /* ?! VX1000_MCREG_OCDS_OIFM = VX1000_OCDS_OIFM; ?! */
      ; /* Semicolon here for MISRA */
    }
    else
    {
      VX1000_MCREG_OCDS_OCNTRL = VX1000_OCDS_OCNTRL;
    }
#else  /* !VX1000_TARGET_TRICORE */
    ; /* If tool detection was not successful, no action on V850/RH850. Semicolon here for MISRA */
#endif /* !VX1000_TARGET_TRICORE */
  }
#if defined(VX1000_RUNNING_ON_MAINCORE)
  if (VX1000_RUNNING_ON_MAINCORE() != 0)
#endif /* VX1000_RUNNING_ON_MAINCORE */
  {
    VX1000_OVERLAY_HW_INIT()
  }
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_Init                                                                                                 */
/* API name:      VX1000_INIT                                                                                                 */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000_* function.                                             */
/* Termination:   May leave internal data in an inconsistent state.                                                           */
/*                No problems on reactivation.                                                                                */
/* Precondition1: The timer used by VX1000_CLOCK() must be up and running.                                                    */
/* Description:   Initializes all global VX1000 data structures and performs the VX startup handshaking.                      */
/* Devel state:   Deprecated (replaced by vx1000_InitAsyncStart)                                                              */
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Should not be used in new designs */
/* Only for compatibility in existing projects */
void VX1000_SUFFUN(vx1000_Init)(void)
{
  VX1000_INIT_ASYNC_START()
  VX1000_INIT_ASYNC_END()
}


/*------------------------------------------------------------------------------- */
/* Pre-restart handshake                                                          */
#if defined(VX1000_SOFTRESET_TIMEOUT_MS)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_PrepareSoftreset                                                                                     */
/* API name:      VX1000_PREPARE_SOFTRESET (expression) / VX1000_PREPARE_SOFTRESET_VOID (statement)                           */
/* Return value:  0: reset procedure confirmed by tool / 1: handshake failed (measurement won't be resumed after the reset)   */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_InitAsyncEnd() must have been called.                                                                */
/* Description:   Informs the VX1000 base module about a planned software reset.                                              */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_PrepareSoftreset)(void)
{
  VX1000_UINT32 t0, dt;
  VX1000_UINT8 retVal = 0; /* 0="accepted", 1="initiated", 2="acknowledged", 3="handled", 4="confirmed", {5,6}="timeout" */

  if ((gVX1000.ToolCtrlState & (VX1000_TCS_PRESENT)) != 0)  /* Handshake is only needed when a VX is connected */
  {
    VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    t0 = gVX1000.EventTimestamp;
    dt = (VX1000_SOFTRESET_TIMEOUT_MS) * (VX1000_CLOCK_TICKS_PER_MS);
#if (VX1000_CLOCK_TIMER_SIZE < 32) && (VX1000_CLOCK_TIMER_SIZE != 0)
    if ( dt > ((1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1) )
    {
      dt = (1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1;
      VX1000_ERRLOGGER(VX1000_ERRLOG_TM_DTSR_TOO_LONG)
    }
#endif /* VX1000_CLOCK_TIMER_SIZE */

    /* trigger a special event */
    VX1000_SPECIAL_EVENT(VX1000_ECU_EVT_SW_RESET_PREP) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
    retVal = 1;

    /* wait with timeout until the VX1000 acknowledges the special event by setting VX1000_TCS_SOFTRESET_PREP */
    while (retVal == 1)
    {
      if ((gVX1000.ToolCtrlState & (VX1000_UINT32)(VX1000_TCS_SOFTRESET_PREP)) != 0)
      {
        /* retVal = 2; */
        gVX1000.MagicId = 0;   /* destroy the MagicId */
        retVal = 3;

        /* wait with timeout until the VX1000 also confirmed that it saw the destroyed MagicId by resetting VX1000_TCS_SOFTRESET_PREP */
        while (retVal == 3)
        {
          if (0==(gVX1000.ToolCtrlState & (VX1000_UINT32)(VX1000_TCS_SOFTRESET_PREP)))
          {
            retVal = 4;
          }
          else if ((gVX1000.EventTimestamp - t0) >= dt)
          {
            retVal = 5; /* means "timeout" */
          }
          else
          {
            ; /* empty else is only here for MISRA */
          }
          VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
        } /* while() */
      }
      else if ((gVX1000.EventTimestamp - t0) >= dt)
      {
        retVal = 6; /* means "timeout" or "rejected" */
      }
      else
      {
        ; /* empty else is only here for MISRA */
      }
      VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    } /* while() */
    if (retVal == 4) /* reduce the return values to a simplified, boolean meaning */
    {
      retVal = 0;
    }
    else
    {
      retVal = 1;
    }
  }
  return retVal;
}
#endif /* VX1000_SOFTRESET_TIMEOUT_MS */

/*------------------------------------------------------------------------------- */
/* Tool detection */

#if defined(VX1000_DETECTION) || defined(VX1000_TARGET_TRICORE) /* on Tricore, this function is always present because it is needed in DAP init decision */

#if defined(VX1000_COLDSTART_CALIBRATION)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: calcAdd32                                                                                                   */
/* API name:      None                                                                                                        */
/* Return value:  Checksum                                                                                                    */
/* Parameter1:    Source address (must be a multiple of 4)                                                                    */
/*                Validity ensured by caller.                                                                                 */
/* Parameter2:    Byte count (must be a multiple of 4)                                                                        */
/*                Validity ensured by caller.                                                                                 */
/* Preemption:    TODO visza                                                                                                  */
/* Termination:   TODO visza                                                                                                  */
/* Precondition1: The source data must be accessible (concerning existence, power state, MMU/MPU rights).                     */
/* Description:   TODO visza                                                                                                  */
/* Devel state:   Specified                                                                                                   */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT32 VX1000_SUFFUN(calcAdd32)(VX1000_UINT32 addr, VX1000_UINT32 bytes); /* todo: move up */
static VX1000_UINT32 VX1000_SUFFUN(calcAdd32)(VX1000_UINT32 addr, VX1000_UINT32 bytes)  /* todo: shall this be used anywhere else? Otherwise why not inlining the few lines into vx1000_CalcFlashChecksum()? */
{
  VX1000_UINT32 sum32 = 0;
#if 0 /* todo: this is just a MISRA compliant but functional inequivalent idea for profiling vs. the #else-code below. Must not be used! */
  VX1000_UINT32 k, *data = (VX1000_UINT32 *)addr; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
  for (k = 0; k <= bytes; k += 4UL * 8UL)
  {
    sum32 += data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7];
    data = &data[8];
  }
#else /* !0 */
  VX1000_UINT32 *p, *pl;

  /* Don't change this \/ \/ \/ code, before you are sure that runtime will not be affected !! (note: 18 MISRA violations in this block!) */
  p  = (VX1000_UINT32 *)addr;
  pl = (VX1000_UINT32 *)(addr+bytes);
  do
  {
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
    sum32 += *p++;
  } while (p < pl);
  /* Don't change this /\ /\ /\ code, before you are sure that runtime will not be affected !! */
#endif /* !0 */
  return sum32;
}

/*todo: add check for existence && NZ of the defines and then move everything into the consistency check section in the header*/
#if (VX1000_OLDA_MEMORY_SIZE) < (((VX1000_COLDSTART_FLASH_SIZE) / (VX1000_COLDSTART_CHS_BLOCK_SIZE)) + 4) * 4
#error "VX1000_MEMORY_SIZE too small for FLASH checksum array"
#endif /* VX1000_OLDA_MEMORY_SIZE < ... */
#if ((VX1000_COLDSTART_FLASH_SIZE) % (VX1000_COLDSTART_CHS_BLOCK_SIZE)) != 0
#error "VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE != 0"
#endif /* VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_CalcFlashChecksum                                                                                    */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    TODO visza                                                                                                  */
/* Termination:   TODO visza                                                                                                  */
/* Precondition1: TODO visza                                                                                                  */
/* Description:   TODO visza                                                                                                  */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
/* todo: add the used global variables to the end of this module plus to the header plus add VX1000_COLDSTART_CHECKSUM_MAGIC */
extern void VX1000_SUFFUN(vx1000_CalcFlashChecksum)( void ); /* todo: move to header */
void VX1000_SUFFUN(vx1000_CalcFlashChecksum)( void )
{
  VX1000_UINT32 a;
  VX1000_UINT32 i, *p;

  p = (VX1000_UINT32*)gVX1000.Olda.MemoryAddr; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable either contains a pointer to an actual object or an integral magic number for "invalid" */
  p[0] = (VX1000_UINT32)(VX1000_COLDSTART_CHS_MAGIC);
  p[1] = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_ADDR);
  p[2] = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_SIZE);
  p[3] = (VX1000_UINT32)(VX1000_COLDSTART_CHS_BLOCK_SIZE);
  p = (VX1000_UINT32*)(gVX1000.Olda.MemoryAddr + 4*4); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable either contains a pointer to an actual object or an integral magic number for "invalid" */
  a = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_ADDR);
  for (i = 0; i < ((VX1000_COLDSTART_FLASH_SIZE) / (VX1000_COLDSTART_CHS_BLOCK_SIZE)); i++)
  {
    p[i] = VX1000_SUFFUN(calcAdd32)(a, (VX1000_COLDSTART_CHS_BLOCK_SIZE));
    a += VX1000_COLDSTART_CHS_BLOCK_SIZE;
  }
}

#endif /* VX1000_COLDSTART_CALIBRATION */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_DetectVxAsyncStart                                                                                   */
/* API name:      None (VX1000_DETECT_VX_ASYNC_START only used internally)                                                    */
/* Return value:  None                                                                                                        */
/* Parameter1:    None                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: The timer used by VX1000_CLOCK() must be up and running.                                                    */
/* Description:   Detect, whether a VX1000 is connected; if yes, initiate tool handshake.                                     */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_DetectVxAsyncStart)( void )
{
#if !defined(VX1000_COMPILED_FOR_SLAVECORES)
#if defined(VX1000_DETECT_XCP)
  /* Check whether there is a XCP on CAN connected and disable VX OLDA in that case */
  /* (Otherwise the probably-shared memory for the display tables would be overwritten by VX coldstart setup!)*/
  if ((xcp.SessionStatus & (SS_CONNECTED)) != 0)
  {
    gVX1000.Olda.MagicId = 0; /* XCP connected: Disable OLDA */
  }
  else
  {
    gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC; /* VX is alone: Re-enable OLDA */
    /* todo: the VX will not start using olda now by itself -> we have to request this somehow */
  }
#endif /* VX1000_DETECT_XCP */

  /* Check if 1st call after reset (&& on multi-core systems, whether we run on the main core) */
  if ((0==(gVX1000.ToolDetectState & ((VX1000_UINT32)VX1000_TDS_DETECT))) /* PRQA S 3415*/ /* Actually not violating MISRA Rule 12.4 because VX1000_RUNNING_ON_MAINCORE() by definition cannot have any desired side effect */
#if defined(VX1000_RUNNING_ON_MAINCORE)
  &&  (VX1000_RUNNING_ON_MAINCORE()) /* TODO: when not running on the main core, return gVX1000.ToolDetectState only if VX1000_DATA looks "already initialized"! */
#endif /* VX1000_RUNNING_ON_MAINCORE */
  )
  {
#if ((VX1000_CLOCK_TICKS_BASE_NS) < 100000UL) /* was: "#if ((VX1000_CLOCK_TICKS_PER_US) > 10)", but CLOCK_TICKS may be a function! */
    VX1000_UINT32 dt = (VX1000_DETECTION_TIMEOUT_US) * (VX1000_CLOCK_TICKS_PER_US);
#else /* VX1000_CLOCK_TICKS_BASE_NS */
    VX1000_UINT32 dt = ((VX1000_DETECTION_TIMEOUT_US) * (VX1000_CLOCK_TICKS_PER_MS)) / 1000UL;
#endif /* VX1000_CLOCK_TICKS_BASE_NS */
#if (VX1000_CLOCK_TIMER_SIZE < 32) && (VX1000_CLOCK_TIMER_SIZE != 0)
    if ( dt > ((1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1) )
    {
      dt = (1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1;
      VX1000_ERRLOGGER(VX1000_ERRLOG_TM_DTDT_TOO_LONG)
    }
#endif /* VX1000_CLOCK_TIMER_SIZE */
    VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_DETECT;
    gVX1000_DETECT_StartTime = gVX1000.EventTimestamp;

#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
    gVX1000_DETECT_StartTimeAsyncEnd = 0;
    gVX1000_DETECT_ToolDetectTime = 0;
    gVX1000_DETECT_ChecksumDoneTime = 0;
    gVX1000_DETECT_EndTime = 0;
    gVX1000_DETECT_EndTimeAsyncStart = 0;
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */

    /* Wait some time for tool presence indication, when ECU was reset, the tool may need some time to react */
    /* Check timeout VX1000_DETECTION_TIMEOUT_US */
    /* At xxx MHz Nexus Clock yyy ms were measured in the NIOS until VX1000_TCS_PRESENT was written to */
    /* ToolCtrlState after a reset had been detected. */
    do
    {
      /* Check tool presence */
      if ((gVX1000.ToolCtrlState & ((VX1000_TCS_PRESENT) | (VX1000_TCS_COLDSTART_DELAY))) != 0)
      {
#if defined(VX1000_OVLENBL_KEEP_AWAKE)
        if (VX1000_CAL_WAKEUP_REQUESTED())
        {
#if defined(VX1000_OVLENBL_RST_ON_CALWAKEUP)
          VX1000_OVL_RST_ON_CAL_WAKEUP_CB()
#endif /* VX1000_OVLENBL_RST_ON_CALWAKEUP */
          /* Decrement the presenceCounter so that cal_wakeup_active returns 1 when called next time */
          gVX1000.Ovl.ecuLastPresenceCounter--;
        }
#endif /* VX1000_OVLENBL_KEEP_AWAKE */

        /* Acknowledge tool detect */
        gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_DETECTED);

        if ((gVX1000.ToolCtrlState & (VX1000_TCS_COLDSTART_DELAY)) != 0)
        {
          gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_COLDSTART_DELAY_REQ);
        }
#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
        gVX1000_DETECT_ToolDetectTime = gVX1000.EventTimestamp;
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */

        break; /* note: this "early-out"-break can be removed safely if constant runtime is preferred (or for MISRA) */
      } /* Tool present */
      VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    } while ((gVX1000.EventTimestamp - gVX1000_DETECT_StartTime) < dt);
    gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_DETECT_DONE;
#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
    gVX1000_DETECT_EndTimeAsyncStart = VX1000_CLOCK();  /* here, gVX1000.EventTimestamp may be outdated (break's path) */
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */
  } /* 1st call */
  else
  {
    /* Just Check whether the VX is connected now and update the state accordingly */
    if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_PRESENT))) != 0)
    {
      gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_DETECTED); /* VX1000 connected */
    }
    else
    {
      gVX1000.ToolDetectState &= (VX1000_UINT32)~(VX1000_TDS_DETECTED); /* not connected */
    }
  }
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_DetectVxAsyncEnd                                                                                     */
/* API name:      None (VX1000_DETECT_VX_ASYNC_END only used internally)                                                      */
/* Return value:  VX1000_TDS_DETECTED if detected; 0 otherwise.                                                               */
/* Parameter1:    None                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_DetectVxAsyncStart must have been called.                                                            */
/* Description:   Update connection status and stall for remaining delay if required by tool (for downloading the             */
/*                coldstart measurement setup).                                                                               */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_DetectVxAsyncEnd)( void )
{
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
  if (0==(VX1000_RUNNING_ON_MAINCORE()))
#endif /* VX1000_RUNNING_ON_MAINCORE & !VX1000_COMPILED_FOR_SLAVECORES */
#if defined(VX1000_RUNNING_ON_MAINCORE) || defined(VX1000_COMPILED_FOR_SLAVECORES)
  {
    if ((gVX1000.ToolDetectState & (VX1000_UINT32)((VX1000_TDS_COLDSTART_DELAY_REQ) | (VX1000_TDS_COLDSTART_DELAY))) != 0)
    {
      while (0 == (gVX1000.ToolDetectState & (VX1000_UINT32) ((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT))))
      {
        ; /* busy wait for the main core to complete the handshake */
      }
    }
  }
#endif  /* VX1000_RUNNING_ON_MAINCORE | VX1000_COMPILED_FOR_SLAVECORES */
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
  else
#endif /* VX1000_RUNNING_ON_MAINCORE & !VX1000_COMPILED_FOR_SLAVECORES */
#if !defined(VX1000_COMPILED_FOR_SLAVECORES)
  if ((gVX1000.ToolDetectState & (VX1000_UINT32)(VX1000_TDS_COLDSTART_DELAY_REQ)) != 0)
  {
    VX1000_UINT32 dt = (VX1000_COLDSTART_TIMEOUT_MS) * (VX1000_CLOCK_TICKS_PER_MS);
#if (VX1000_CLOCK_TIMER_SIZE < 32) && (VX1000_CLOCK_TIMER_SIZE != 0)
    if ( dt > ((1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1) )
    {
      dt = (1UL << (VX1000_CLOCK_TIMER_SIZE)) - 1;
      VX1000_ERRLOGGER(VX1000_ERRLOG_TM_DTCS_TOO_LONG)
    }
#endif /* VX1000_CLOCK_TIMER_SIZE */
    VX1000_STORE_TIMESTAMP(VX1000_CLOCK())

#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
    gVX1000_DETECT_StartTimeAsyncEnd = gVX1000.EventTimestamp;
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */

    /* removed: gVX1000.ToolDetectState &= ~(VX1000_UINT32)VX1000_TDS_COLDSTART_DELAY_REQ; */
    gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_DELAY;

    /* Calculate checksums over the calibration areas and store in Olda memory */
    /* VX1000 may use this to optimize calibration download */
#if defined(VX1000_COLDSTART_CALIBRATION)
    gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_CHS_BUSY;
    VX1000_SUFFUN(vx1000_CalcFlashChecksum)();
    gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_CHS_DONE;
#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
    gVX1000_DETECT_ChecksumDoneTime = VX1000_CLOCK();  /* here, gVX1000.EventTimestamp is outdated */
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */
#endif /* VX1000_COLDSTART_CALIBRATION */

    for (gVX1000.ToolDetectState &= (VX1000_UINT32)~((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT));
    0 == (gVX1000.ToolDetectState & (VX1000_UINT32) ((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT)));)
    {
      if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_COLDSTART_DONE))) != 0)
      {
        /* Init acknowledge */
#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
        VX1000_SUFFUN(vx1000_OverlayWriteEcuDescr)();
#endif /* VX1000_OVERLAY & VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX & VX1000_MAILBOX & VX1000_MAILBOX_OVERLAY_CONTROL*/
        if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_SWITCH_TO_WP))) != 0)
        {
#if (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
          if (VX1000_WRP_SET_CAL_PAGE(0, 1, (VX1000_CAL_ECU) | (VX1000_CAL_XCP), 1) != 0)
#endif /* VX1000_MAILBOX & VX1000_MAILBOX_OVERLAY_CONTROL */
          {
            gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_ERROR);
          }
        }
        gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_COLDSTART_DONE);
      }
      else if ((gVX1000.EventTimestamp - gVX1000_DETECT_StartTime) >= dt)
      {
        /* Timeout acknowledge */
        gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_COLDSTART_TIMEOUT);
      }
      else
      {
        ; /* empty else only here for MISRA */
      }
      VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
    } /* for(;;) */

#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
    gVX1000_DETECT_EndTime = VX1000_CLOCK();  /* here, gVX1000.EventTimestamp may be outdated (break's path) */
#endif /* VX1000_COLDSTART_BENCHMARK && VX1000_OLDA */
  }
#if defined(VX1000_RUNNING_ON_MAINCORE)
  else
  {
    ; /* this dummy else case is here only for MISRA */
  }
#endif /* VX1000_RUNNING_ON_MAINCORE */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

  return (VX1000_UINT8)(gVX1000.ToolDetectState & (VX1000_UINT32)(VX1000_TDS_DETECTED));
}
#endif /* VX1000_DETECTION | VX1000_TARGET_TRICORE */



/*------------------------------------------------------------------------------- */
/* Breakpoint triggered actions                                                   */

/* optional: breakpoint externals and implementation */



#if defined(VX1000_OLDA)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OldaInit                                                                                             */
/* API name:      None                                                                                                        */
/* Return value:  None                                                                                                        */
/* Parameter1:    None                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Reset all Olda-related VX1000 structure data.                                                               */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_OldaInit)( void )
{
  gVX1000.Olda.Version = VX1000_OLDA_VERSION;
  gVX1000.Olda.Running = 0;
#if !defined(VX1000_OLDA_MEMORY_ADDR)
  gVX1000.Olda.MemoryAddr = (VX1000_UINT32)&gVX1000.Olda.Data[0]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
#else /* VX1000_OLDA_MEMORY_ADDR */
  gVX1000.Olda.MemoryAddr = VX1000_OLDA_MEMORY_ADDR;
#endif /* VX1000_OLDA_MEMORY_ADDR */
  gVX1000.Olda.MemorySize = VX1000_OLDA_MEMORY_SIZE;
  gVX1000.Olda.EventCount = 0;
  gVX1000.Olda.EventList = 0;
  gVX1000.Olda.TransferList = 0;
  gVX1000.Olda.SizeLengthNOffset = (VX1000_OLDA_SIZE_OFFSET) | ((VX1000_OLDA_SIZE_LENGTH) << 5);
  gVX1000.Olda.SizeSwapValue = VX1000_OLDA_SIZE_SWAP_VALUE;
  gVX1000.Olda.OldaFeatures = (((((((((((((VX1000_FEAT_OLDA_STIM)
                            | (VX1000_FEAT_OLDA_HBB))
                            | (VX1000_FEAT_OLDA_V8CMD_SP8N))
                            | (VX1000_FEAT_OLDA_V8CMD_CP8N))
                            | (VX1000_FEAT_OLDA_V8CMD_CP16N))
                            | (VX1000_FEAT_OLDA_V8CMD_CP32N))
                            | (VX1000_FEAT_OLDA_V8CMD_CP64N))
                            | (VX1000_FEAT_OLDA_V8CMD_DONE))
                            | (VX1000_FEAT_OLDA_V8CMD_WAIT))
                            | ((VX1000_FEAT_OLDA_V5_DYNSIZE) | ((VX1000_FEAT_OLDA_V7_COMPRESS) | (VX1000_FEAT_OLDA_V8CMD_CALLJITA))))
                            | ((VX1000_FEAT_OLDA_V7_BYTEDAQ) | (VX1000_FEAT_OLDA_V8CMD_SUBEVT)))
                            | (VX1000_FEAT_OLDA_BENCHMARK))
                            | (VX1000_FEAT_OLDA_OVERLOADDETECT))
                            | (VX1000_FEAT_OLDA_TRIGGER);
  gVX1000.Olda.Res1 = 0;
  gVX1000.Olda.Res2 = 0;

#if defined(VX1000_OLDA_BENCHMARK)
  {
    VX1000_UINT32 i;
    for (i = 0; i < VX1000_OLDA_EVENT_COUNT; i++) { gVX1000_OLDA_Duration[i] = 0; }
  }
#endif /* VX1000_OLDA_BENCHMARK */

  if ( ((volatile VX1000_UINT8 *)&gVX1000.Olda.MemoryAddr) != &(((volatile VX1000_UINT8 *)&gVX1000.Olda)[0x4]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard (offsetof((VX1000_OLDA_T, MemoryAddr)) != 0x4) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }

  gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OldaEvent                                                                                            */
/* API name:      VX1000_EVENT (user) / VX1000_OLDA_EVENT (internal only)                                                     */
/* Return value:  None                                                                                                        */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/*                Validity ensured by internal silent abort.                                                                  */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_OldaInit() must have been called.                                                                    */
/* Precondition2: The MMU must be programmed such that the source memory and the destination memory are visible.              */
/* Precondition3: The MPU must be programmed such that the source memory is readable and the destination memory is writeable. */
/* Description:   Processes all transfer descriptors assigned to parameter1, copies DAQ data to the olda buffer.              */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_OldaEvent)( VX1000_UINT8 eventNumber )
{
/* todo: use the V8 types by default, benchmark in bytes and make the word stuff the special handling */
#if !(defined(VX1000_SUPPORT_OLDA8CMD_CALLJITA) && defined(VX1000_OLDA_FORCE_V8))
#if !defined(VX1000_OLDA_FORCE_V8)
  VX1000_UINT8  size;
  VX1000_UINT32 *src = 0; /* note: few compilers warn about unused initialisation but more would warn if it was missing */ /* PRQA S 3197 */
  VX1000_UINT32 *dst;
#else /* VX1000_OLDA_FORCE_V8 */
  VX1000_UINT32 size;
  volatile VX1000_UINT8 *src = 0; /* note: few compilers warn about unused initialisation but more would warn if it was missing */ /* PRQA S 3197 */
  volatile VX1000_UINT8 *dst;
#endif /* VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_OLDA_FORCE_V7) && defined(VX1000_SUPPORT_OLDA7_BYTEDAQ)
  volatile VX1000_UINT8 *src2 = (volatile VX1000_UINT8 *)(&gVX1000); /* note: few compilers warn about unused initialisation but more would warn if it was missing */ /* PRQA S 3197 */
  volatile VX1000_UINT8 *dst2 = (volatile VX1000_UINT8 *)(&gVX1000); /* note: few compilers warn about unused initialisation but more would warn if it was missing */ /* PRQA S 3197 */ /* PRQA S 0303 */ /* accept violating MISRA Rule 11.3 in this dummy initialisation to avoid other violations like wrongly detected "null pointer usage" etc */
#endif /* VX1000_OLDA_FORCE_V7 && VX1000_SUPPORT_OLDA7_BYTEDAQ */
#if defined(VX1000_OLDA_FORCE_V7) || defined(VX1000_OLDA_FORCE_V8)
  VX1000_UINT32 sizeList = 0;
#endif /* VX1000_OLDA_FORCE_V7 || VX1000_OLDA_FORCE_V8 */
  VX1000_UINT16 i;
#if defined(VX1000_OLDA_FORCE_V7) || (defined(VX1000_OLDA_FORCE_V8) && (!defined(VX1000_MEMCPY)))
  VX1000_UINT32 j;
#endif /* VX1000_OLDA_FORCE_V7 || (VX1000_OLDA_FORCE_V8 && !VX1000_MEMCPY) */
#endif /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
  VX1000_OLDA_EVENT_T *event;
  VX1000_UINT32 t0;
  VX1000_UINT16 n;

#if defined(VX1000_OLDA_FORCE_V7) || defined(VX1000_OLDA_FORCE_V8)
  VX1000_DUMMYREAD(sizeList)   /* dummy usage to avoid compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#endif /* VX1000_OLDA_FORCE_V7 || VX1000_OLDA_FORCE_V8 */

  /* Take the timestamp first to have maximum precision.  */
  /* This timestamp will be needed for data trace as well */
  t0 = VX1000_CLOCK();
  VX1000_STORE_TIMESTAMP(t0)

  if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
  {
    /* OLDA is running */
    if (eventNumber < gVX1000.Olda.EventCount)
    {
      /* the eventNumer is valid */
      event = &gVX1000.Olda.EventList[eventNumber];
      n = event->TransferCount;
#if defined(VX1000_OLDA_BENCHMARK)
      gVX1000_OLDA_TransferSize[eventNumber]  = 0; /* Size of all transfers  */
      gVX1000_OLDA_TransferCount[eventNumber] = n; /* Count of the transfers */
#endif /* VX1000_OLDA_BENCHMARK */

      if (n != 0)
      {
        /* eventNumber is active, there's data to be copied */

        /* Take an individual copy of the timestamp for each event, gVX1000.EventTimestamp mustn't have changed meanwhile */
        event->EventTimestamp = t0;
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
        event->EventCounter++; /* Pre: increase the Event-Counter to detect Overruns */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

        /* Copy data to an intermediate location */
#if defined(VX1000_SUPPORT_OLDA8CMD_CALLJITA)  && defined(VX1000_OLDA_FORCE_V8)
        /* todo: verify that the JITA flag in gVX1000.Olda.UsedFeatures was set by the VX, otherwise there might be no valid code there (but this struct member has been removed recently) */
        ((VX1000_VUFUNCP_T)(gVX1000.Olda.TransferList[event->TransferIndex]))(event->TransferDest);
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
        event->EventCounter++; /* Post: increase the Event-Counter again to detect Overruns */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */
#else /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
        i = event->TransferIndex;
#if defined(VX1000_OLDA_FORCE_V8)
        dst = (volatile VX1000_UINT8*)(event->TransferDest); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#else /* !VX1000_OLDA_FORCE_V8 */
        dst = (VX1000_UINT32*)(event->TransferDest); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#endif /* !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_OLDA_FORCE_V7) && defined(VX1000_SUPPORT_OLDA7_BYTEDAQ)
        if (0==gVX1000.Olda.TransferList[i])  /* a first invalid size(-List) entry indicates that the descriptors of this event are encoded in byte-mode */
        {
          sizeList = 0;
          dst2 = (volatile VX1000_UINT8*)dst;
          ++i;
        }
#endif /* VX1000_OLDA_FORCE_V7 && VX1000_SUPPORT_OLDA7_BYTEDAQ */
        while (n > 0)
        {
          n--;
#if defined(VX1000_OLDA_FORCE_V8)
          src = (volatile VX1000_UINT8*)(gVX1000.Olda.TransferList[i]); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#else /* !VX1000_OLDA_FORCE_V8 */
          src = (VX1000_UINT32*)(gVX1000.Olda.TransferList[i]); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#endif /* !VX1000_OLDA_FORCE_V8 */
          i++;
#if !defined(VX1000_OLDA_FORCE_V8)
#if defined(VX1000_OLDA_FORCE_V7)
#if defined(VX1000_SUPPORT_OLDA7_BYTEDAQ)
          if (0==gVX1000.Olda.TransferList[event->TransferIndex]) /* was byte-mode activated by the FW? */
          {
            /* TransferList entry consists of up to 4 transfer sizes (8Bit), followed by up to 4 pure transfer address entries (32Bit) */
            if (0==sizeList)
            {
              sizeList = (VX1000_UINT32)src; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because both pointers and counters are transferred in the externally generated TransferList array and the code at runtime has to decode it */
              src = (VX1000_UINT32*)(gVX1000.Olda.TransferList[i]); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
              ++i;
            }
            size = (VX1000_UINT8)(sizeList & 0x000000FFUL); /* copy 0..255 bytes (this differs from normal DAQ which uses words) */
            sizeList >>= 8U;
#if defined(VX1000_OLDA_BENCHMARK)
            gVX1000_OLDA_TransferSize[eventNumber] += (size + 3UL) >> 2; /* Size of all transfers in DWORDs */
#endif /* VX1000_OLDA_BENCHMARK */
            src2 = (volatile VX1000_UINT8*)src;
#if defined(VX1000_MEMCPY)
            VX1000_MEMCPY((VX1000_UINT8*)(VX1000_UINT32)dst2, (VX1000_UINT8*)(VX1000_UINT32)src2, (VX1000_UINT32)size);  /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
            for (j = 0; j < size; ++j) { ((volatile VX1000_UINT8*)dst2)[j] = ((volatile VX1000_UINT8*)src2)[j]; }
#endif /* !VX1000_MEMCPY */
            dst2 = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT8*)dst2)[size]);
          }
          else
#endif /* VX1000_SUPPORT_OLDA7_BYTEDAQ */
          {
            size = (VX1000_UINT8)((VX1000_UINT32)src & 0x00000003UL); /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 to avoid re-computation of integer bits already being present in the pointer variable */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
            if ( 0==size )
            {
              /* TransferList entry consists of up to 5 transfer sizes [31..2] and size list identifier [1..0]==0 */
              sizeList = (VX1000_UINT32)src >> 2; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 to avoid re-computation of integer bits already being present in the pointer variable */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
              n++; /* undo decrement of remaining transfers because size list entry isn't a transfer */
              for (j = 0; (j < 5) && (n > 0); j++)
              {
                size = (VX1000_UINT8)(sizeList & 0x3FUL);
                sizeList >>= 6U;
                n--;
                src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
                i++;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers in DWORDs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                VX1000_MEMCPY(dst, src, size << 2);  /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
                dst += size; /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy based on computed pointers is a core feature of this application */
#else /* !VX1000_MEMCPY */
                while (size != 0)
                {
                  *dst = *src;
                  dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  size--;
                } /* while size */
#endif /* !VX1000_MEMCPY */
              }
            }
            else
            {
#if defined(VX1000_OLDA_BENCHMARK)
              gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers in DWORDs */
#endif /* VX1000_OLDA_BENCHMARK */
              /* TransferList entry consists of source address [31..2] and transfer size [1..0] in 32-bit-words */
              src = (VX1000_UINT32*)((VX1000_UINT32)src ^ size); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
#if defined(VX1000_MEMCPY)
              VX1000_MEMCPY(dst, src, size << 2); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
              dst += size; /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy based on computed pointers is a core feature of this application */
#else /* !VX1000_MEMCPY */
              while (size != 0)
              {
                *dst = *src;
                dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                size--;
              } /* while size */
#endif /* !VX1000_MEMCPY */
            }
          }
#else /* !VX1000_OLDA_FORCE_V7 */
          size = (VX1000_UINT8)(  ( (VX1000_UINT32)src & (  VX1000_OLDA_SIZE_MASK ) ) >> (VX1000_OLDA_SIZE_OFFSET) ); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
          src = (VX1000_UINT32*)( ( (VX1000_UINT32)src & (~(VX1000_OLDA_SIZE_MASK)) ) | (VX1000_OLDA_SIZE_REPLACEMENT) ); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#if defined(VX1000_OLDA_BENCHMARK)
          gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers in DWORDs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
          VX1000_MEMCPY(dst, src, size << 2); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
          dst += size; /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy based on computed pointers is a core feature of this application */
#else /* !VX1000_MEMCPY */
          while (size != 0)
          {
            *dst = *src;
            dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            size--;
          } /* while size */
#endif /* !VX1000_MEMCPY */
#endif /* !VX1000_OLDA_FORCE_V7 */
#else /* VX1000_OLDA_FORCE_V8 */
          switch ((VX1000_UINT8)((VX1000_UINT32)src & 0x000000FFUL))
          {
#if defined(VX1000_SUPPORT_OLDA8CMD_SP8N)
            case 0:
              for (sizeList = (VX1000_UINT32)src & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                ++i;
                dst = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT8*)dst)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_SP8N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP8N)
            case 1:
              for (sizeList = (VX1000_UINT32)src & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                src = (volatile VX1000_UINT8 *)(((VX1000_UINT32)src & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFFUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += size << 0; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT8*)(VX1000_UINT32)dst, (VX1000_UINT8*)(VX1000_UINT32)src, size << 0); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT8*)dst)[j] = ((volatile VX1000_UINT8*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                dst = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT8*)dst)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP8N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP16N)
            case 2:
              for (sizeList = (VX1000_UINT32)src & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                src = (volatile VX1000_UINT8 *)(((VX1000_UINT32)src & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFEUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += size << 1; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT8*)(VX1000_UINT32)dst, (VX1000_UINT8*)(VX1000_UINT32)src, size << 1); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT16*)dst)[j] = ((volatile VX1000_UINT16*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                dst = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT16*)dst)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP16N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP32N)
            case 3:
              for (sizeList = (VX1000_UINT32)src & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                src = (volatile VX1000_UINT8 *)(((VX1000_UINT32)src & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFCUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += size << 2; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT8*)(VX1000_UINT32)dst, (VX1000_UINT8*)(VX1000_UINT32)src, size << 2); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { dst[j] = src[j]; }
#endif /* !VX1000_MEMCPY */
                dst = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT32*)dst)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP32N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP64N)
            case 4:
              for (sizeList = (VX1000_UINT32)src & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                src = (volatile VX1000_UINT8 *)(((VX1000_UINT32)src & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFF8UL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += size << 3; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT8*)(VX1000_UINT32)dst, (VX1000_UINT8*)(VX1000_UINT32)src, size << 3); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT64*)dst)[j] = ((volatile VX1000_UINT64*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                dst = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT64*)dst)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP64N */
#if defined(VX1000_SUPPORT_OLDA8CMD_DONE)
            case 5:
              n = 0;
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_DONE */
#if defined(VX1000_SUPPORT_OLDA8CMD_SUBEVT)
            case 6:
              /* Trigger a sub-event so the VX1000 starts to fetch the existing data while the ECU in parallel prepares the remaining data */
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
              event->EventCounter += (((VX1000_UINT32)src) >> 16) & 0x00000001UL); /* For the final event, increase the Event-Counter to detect Overruns */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */
#if defined(VX1000_TARGET_TRICORE)
              if (VX1000_ECU_IS_AURIX())
              {
                VX1000_MCREG_OCDS_TRIGS = ((((VX1000_UINT32)src) >> 8) & 0x000000FFUL);
              }
              else
              {
                VX1000_MCREG_OCDS_TRIGS = (VX1000_UINT32)(1UL << ((((VX1000_UINT32)src) >> 8) & 0x000000FFUL));
              }
#elif defined(VX1000_OLDA_AUDMBR_REG_ADDR)
              (*(volatile VX1000_UINT16*)(volatile void*)((VX1000_UINT8*)0UL + (VX1000_OLDA_AUDMBR_REG_ADDR))) = ((((VX1000_UINT32)src) >> 8) & 0x000000FFUL);
#elif defined(VX1000_OLDA_DTS_BASE_ADDR)
              VX1000_ADD_MPC_TRIGS((((VX1000_UINT32)src) >> 8) & 0x000000FFUL) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
#else  /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
              VX1000_ATOMIC_XOR32X2((/*(VX1000_UINT32)*/&gVX1000.OldaEventNumber), (VX1000_UINT32)(1UL << ((((VX1000_UINT32)src) >> 8) & 0x000000FFUL)))
#endif /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_SUBEVT */
            default:
              VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,0UL, (src),(dst),(size),(sizeList)))  /* dummy accesses to prevent compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#if !defined(VX1000_MEMCPY)
              j++;
#endif /* !VX1000_MEMCPY */
              break;
          }
#endif /* VX1000_OLDA_FORCE_V8 */
        } /* while n*/
#if defined(VX1000_OLDA_FORCE_V8) && defined(VX1000_SUPPORT_OLDA8CMD_SUBEVT)
        /* If the driver offers sub-event support, the FW actually has to use it at least for the final event (to allow aliasing). So the event has already been triggered. */
#else /* !VX1000_OLDA_FORCE_V8 || !VX1000_SUPPORT_OLDA8CMD_SUBEVT */
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
        event->EventCounter++; /* Increase the Event-Counter to detect Overruns */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

        /* Trigger the VX1000 to copy the data */
#if defined(VX1000_TARGET_TRICORE)
        if (VX1000_ECU_IS_AURIX())
        {
          VX1000_MCREG_OCDS_TRIGS = (eventNumber);
        }
        else
        {
          VX1000_MCREG_OCDS_TRIGS = (1UL << eventNumber);
        }
#elif defined(VX1000_OLDA_AUDMBR_REG_ADDR)
        (*(volatile VX1000_UINT16*)(volatile void*)((VX1000_UINT8*)0UL + (VX1000_OLDA_AUDMBR_REG_ADDR))) = (1U << eventNumber);
#elif defined(VX1000_OLDA_DTS_BASE_ADDR)
        VX1000_ADD_MPC_TRIGS(eventNumber) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
#else  /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
        VX1000_ATOMIC_XOR32X2((/*(VX1000_UINT32)*/&gVX1000.OldaEventNumber), (VX1000_UINT32)(1UL << eventNumber))
#endif /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
#endif /* !VX1000_OLDA_FORCE_V8 || !VX1000_SUPPORT_OLDA8CMD_SUBEVT */
#endif /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
#if defined(VX1000_OLDA_BENCHMARK)
        gVX1000_OLDA_Duration[eventNumber] = (VX1000_CLOCK()) - t0; /* Timing measurement */
      }
      else
      {
        gVX1000_OLDA_Duration[eventNumber] = 0;
#endif /* VX1000_OLDA_BENCHMARK */
      } /* if (!)n */
    } /* if eventNumber */
  } /* if OLDA */
#if defined(VX1000_TARGET_TRICORE) && !defined(VX1000_SUPPRESS_TRACE_SUPPORT)
  /* Tricore only: Trigger a trace event to make events work with both serial and parallel pods */
  VX1000_STORE_EVENT(eventNumber) /* Had been removed due to EM00034754 but was readded due to EM00035042; as interims workaround for FW 1.8 is is configurable now via VX1000_SUPPRESS_TRACE_SUPPORT -- On V850/RH850, mailbox polling is so slow that this must be disabled */
#endif /* VX1000_TARGET_TRICORE & !VX1000_SUPPRESS_TRACE_SUPPORT */
  return;
}

#if defined(VX1000_STIM_BY_OLDA)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OldaStimRequestEvent                                                                                 */
/* API name:      VX1000_STIM_REQUEST_EVENT (internal)                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/*                Validity ensured by internal silent abort.                                                                  */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_OldaInit() must have been called.                                                                    */
/* Description:   Sends an event without copying any data (the associated STIM data is handled later by vx1000_StimTransfer). */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_OldaStimRequestEvent)( VX1000_UINT8 eventNumber )
{
  VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))
  if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
  {
    /* OLDA is running */
    if (eventNumber < gVX1000.Olda.EventCount)
    {
      /* eventNumer is valid */
#if !defined(VX1000_STIM_FORCE_V1)
      /* Take an individual copy of the timestamp for each event */
      gVX1000.Olda.EventList[eventNumber].EventTimestamp = gVX1000.EventTimestamp;
#else /* VX1000_STIM_FORCE_V1 */
      /* Do NOT copy the timestamp in this case, as the gVX1000.EventTimestamp  */
      /* field is used to store the location of the first timestamp in the OLDA */
      /* buffer. The timestamp is not explicitly needed for stim request events */
#endif /* VX1000_STIM_FORCE_V1 */
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
      gVX1000.Olda.EventList[eventNumber].EventCounter += 2; /* Increase the Event-Counter by two for Overrun detection */
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

      /* Trigger the VX1000 to copy the data */
#if defined(VX1000_TARGET_TRICORE)
      if (VX1000_ECU_IS_AURIX())
      {
        VX1000_MCREG_OCDS_TRIGS = (eventNumber);
      }
      else
      {
        VX1000_MCREG_OCDS_TRIGS = (1UL << eventNumber);
      }
#elif defined(VX1000_OLDA_AUDMBR_REG_ADDR)
      (*(volatile VX1000_UINT16*)(volatile void*)((VX1000_UINT8*)0UL + (VX1000_OLDA_AUDMBR_REG_ADDR))) = (1U << eventNumber);
#elif defined(VX1000_OLDA_DTS_BASE_ADDR)
      VX1000_ADD_MPC_TRIGS(eventNumber) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
#else  /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
      VX1000_ATOMIC_XOR32X2((/*(VX1000_UINT32)*/&gVX1000.OldaEventNumber), (VX1000_UINT32)(1UL << eventNumber))
#endif /* !VX1000_TARGET_TRICORE & !VX1000_OLDA_AUDMBR_REG_ADDR & !VX1000_OLDA_DTS_BASE_ADDR */
    }
  }
  VX1000_STORE_EVENT(eventNumber)
}

#endif /* VX1000_STIM_BY_OLDA */

#endif /* VX1000_OLDA */


#if defined(VX1000_STIM)

#if defined(VX1000_STIM_FORCE_V1)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassCheckCounters                                                                                  */
/* API name:      none                                                                                                        */
/* Return value:  1 if the counters are consistent with new data available                                                    */
/*                2 if no new data are available                                                                              */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/* Precondition1: stim_event must be a valid stim event in the range above                                                    */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Description:   Checks whether new stim data have been copied into the ECU                                                  */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCheckCounters)( VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = VX1000_STIM_RET_TIMEOUT;

  if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].EventType == VX1000_BYPASS_TYPE_DIRECT)
  {
    if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Ctr
    ==  (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr)
    {
      retVal = VX1000_STIM_RET_SUCCESS;
    }
  }
#if defined(VX1000_STIM_BY_OLDA)
  else
  {
    retVal = VX1000_SUFFUN(vx1000_BypassCheckBuffer)(stim_event);
  }
#endif /* VX1000_STIM_BY_OLDA */

  return retVal;
}
#endif /* VX1000_STIM_FORCE_V1 */

#if defined(VX1000_STIM_BY_OLDA)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimTransfer                                                                                         */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/*                Validity ensured by internal silent abort. // or: {internal assertion, caller }.                            */
/* Preemption:    This function must not be interrupted by any vx1000_* function.                                             */
/*                This function should not interrupt and should not be interrupted by code that reads the stimulation data.   */
/* Termination:   May leave the destination data in an inconsistent state.                                                    */
/*                Internal data stays valid, no problems on reactivation.                                                     */
/* Precondition1: vx1000_OldaInit() must have been called successfully.                                                       */
/* Precondition2: The MMU must be programmed such that the source memory and the destination memory are visible.              */
/* Precondition3: The MPU must be programmed such that the source memory is readable and the destination memory is writeable. */
/* Description:   Processes all transfer descriptors assigned to parameter1, copies data from olda buffer to the destinations.*/
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_StimTransfer)( VX1000_UINT8 eventNumber );
static void VX1000_SUFFUN(vx1000_StimTransfer)( VX1000_UINT8 eventNumber )
{
  VX1000_OLDA_EVENT_T *event;
  volatile VX1000_UINT8 *src;
#if !(defined(VX1000_SUPPORT_OLDA8CMD_CALLJITA) && defined(VX1000_OLDA_FORCE_V8))
  volatile VX1000_UINT8 *dst;
  VX1000_UINT8 size;
  VX1000_UINT16 i;
#if defined(VX1000_OLDA_FORCE_V7) || defined(VX1000_OLDA_FORCE_V8)
  VX1000_UINT32 j = 0, sizeList = 0; /* sizeList dummy initialisation to avoid compiler warnings */
#endif /* VX1000_OLDA_FORCE_V7 || VX1000_OLDA_FORCE_V8 */
#endif /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
  VX1000_UINT16 n;
#if defined(VX1000_OLDA_BENCHMARK) /* Timing measurement */
  VX1000_UINT32 t0;

  t0 = VX1000_CLOCK();
#endif /* VX1000_OLDA_BENCHMARK */
  if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
  {
    /* OLDA is running */
    if (eventNumber < gVX1000.Olda.EventCount)
    {
      /* eventNumer is valid */
      event = &gVX1000.Olda.EventList[eventNumber];
      src = (VX1000_UINT8*)event->TransferDest; /* yes: src is loaded from dst entry for stim */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
      n = event->TransferCount;
#if defined(VX1000_OLDA_BENCHMARK)
      gVX1000_OLDA_TransferSize[eventNumber]  = 0; /* Size of all transfers  */
      gVX1000_OLDA_TransferCount[eventNumber] = n; /* Count of the transfers */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_SUPPORT_OLDA8CMD_CALLJITA)  && defined(VX1000_OLDA_FORCE_V8)
        /* todo: verify that the JITA flag in gVX1000.Olda.UsedFeatures was set by the VX, otherwise there might be no valid code there: */
        ((VX1000_VUFUNCP_T)(gVX1000.Olda.TransferList[event->TransferIndex]))(event->TransferDest);
#else /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
      for (i = event->TransferIndex; (i == i) && (n > 0); i++) /* yes: check n, not i. The dummy-check of i is needed for MISRA */
      {
        /* eventNumber is active: data is to be copied */
#if !defined(VX1000_OLDA_FORCE_V8)
#if defined(VX1000_OLDA_FORCE_V7)
        /* TransferList entry consists of up to 4 transfer sizes, followed by up to 4 pure transfer address entries */
        if (j==0)
        {
          j = 4;
          sizeList = gVX1000.Olda.TransferList[i];
        }
        else
        {
          j--;
          dst = (VX1000_UINT8*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
          size = (VX1000_UINT8)(sizeList & 0x000000FFUL); /* copy 0..255 bytes (this differs from DAQ which uses words) */
          sizeList >>= 8U;
#else /* !VX1000_OLDA_FORCE_V7 */
        /* TransferList entry contains merged size and address information for exactly one transfer */
        {
          dst = (volatile VX1000_UINT8*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
          size = (VX1000_UINT8)( ( (VX1000_UINT32)dst & (  VX1000_OLDA_SIZE_MASK ) ) >> (VX1000_OLDA_SIZE_OFFSET) ); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
          dst = (volatile VX1000_UINT8*)( ( (VX1000_UINT32)dst & (~(VX1000_OLDA_SIZE_MASK)) ) | (VX1000_OLDA_SIZE_REPLACEMENT) ); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#endif /* !VX1000_OLDA_FORCE_V7 */
#if defined(VX1000_OLDA_BENCHMARK)
          gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
          /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
          VX1000_MEMCPY((VX1000_UINT32)dst, (VX1000_UINT32)src, size); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
          src += size; /* PRQA S 0488 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy based on computed pointers is a core feature of this application */
#else /* !VX1000_MEMCPY */
          while (size != 0)
          {
            *dst = *src;
            dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            size--;
          } /* while size */
#endif /* !VX1000_MEMCPY */
#else /* VX1000_OLDA_FORCE_V8 */
        {
          /* Hint: in the current implementation, we reuse the same command IDs for STIM and DAQ, however we interpret it in the opposite way */
          dst = (volatile VX1000_UINT8*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
          ++i;
          switch ((VX1000_UINT8)((VX1000_UINT32)dst & 0x000000FFUL))
          {
#if defined(VX1000_SUPPORT_OLDA8CMD_SP8N)
            case 0:
              for (sizeList = (VX1000_UINT32)dst & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                ++i;
                src = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT8*)src)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_SP8N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP8N)
            case 1:
              for (sizeList = (VX1000_UINT32)dst & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                dst = (volatile VX1000_UINT8*)(((VX1000_UINT32)dst & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFFUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += (VX1000_UINT32)size << 0; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT32)dst, (VX1000_UINT32)src, size << 0); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT8*)dst)[j] = ((volatile VX1000_UINT8*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                src = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT8*)src)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP8N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP16N)
            case 2:
              for (sizeList = (VX1000_UINT32)dst & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                dst = (volatile VX1000_UINT8*)(((VX1000_UINT32)dst & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFEUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += (VX1000_UINT32)size << 1; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT32)dst, (VX1000_UINT32)src, size << 1); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT16*)dst)[j] = ((volatile VX1000_UINT16*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                src = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT16*)src)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP16N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP32N)
            case 3:
              for (sizeList = (VX1000_UINT32)dst & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                dst = (volatile VX1000_UINT8*)(((VX1000_UINT32)dst & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFFCUL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += (VX1000_UINT32)size << 2; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT32)dst, (VX1000_UINT32)src, size << 2); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { dst[j] = src[j]; }
#endif /* !VX1000_MEMCPY */
                src = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT32*)src)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP32N */
#if defined(VX1000_SUPPORT_OLDA8CMD_CP64N)
            case 4:
              for (sizeList = (VX1000_UINT32)dst & 0x0000FF00UL; sizeList != 0; sizeList -= 0x00000100UL)
              {
                size = ((gVX1000.Olda.TransferList[i] >> 24) & 0x000000FFUL);
                dst = (volatile VX1000_UINT8*)(((VX1000_UINT32)dst & 0xFF000000UL) | (gVX1000.Olda.TransferList[i] & 0x00FFFFF8UL));
                ++i;
#if defined(VX1000_OLDA_BENCHMARK)
                gVX1000_OLDA_TransferSize[eventNumber] += (VX1000_UINT32)size << 3; /* Size of all transfers in BYTEs */
#endif /* VX1000_OLDA_BENCHMARK */
#if defined(VX1000_MEMCPY)
                /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
                VX1000_MEMCPY((VX1000_UINT32)dst, (VX1000_UINT32)src, size << 3); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
                for (j = 0; j < size; ++j) { ((volatile VX1000_UINT64*)dst)[j] = ((volatile VX1000_UINT64*)src)[j]; }
#endif /* !VX1000_MEMCPY */
                src = (volatile VX1000_UINT8*)&(((volatile VX1000_UINT64*)src)[size]);
              }
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_CP64N */
#if defined(VX1000_SUPPORT_OLDA8CMD_DONE)
            case 5:
              n = 1;
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_DONE */
#if defined(VX1000_SUPPORT_OLDA8CMD_WAIT)
            case 7:
              /* Wait for flag that the remaining part of the data is already valid */
#error The semantic of the address and index bits for this command is not specified, yet
              break;
#endif   /* VX1000_SUPPORT_OLDA8CMD_WAIT */
            default:
              VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,(VX1000_MAILBOX_ERR_SIZE), (src),(size),(sizeList),(j))) /* dummy accesses to prevent compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
              break;
          }
          --i;
#endif /* VX1000_OLDA_FORCE_V8 */
          n--;
        }
      } /* for */
#endif /* !VX1000_SUPPORT_OLDA8CMD_CALLJITA || !VX1000_OLDA_FORCE_V8 */
    }
#if defined(VX1000_OLDA_BENCHMARK)
    gVX1000_OLDA_Duration[eventNumber] = (VX1000_CLOCK()) - t0; /* Timing measurement */
#endif /* VX1000_OLDA_BENCHMARK */
  }
  return;
}

#if defined(VX1000_STIM_FORCE_V1)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassCheckBuffer                                                                                    */
/* API name:      none                                                                                                        */
/* Return value:  1 if the buffers is consistent with data from the last DAQ event                                            */
/*                2 if no new data is available or the buffer is being copied to                                              */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/* Precondition1: stim_event must be a valid stim event in the range above                                                    */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Description:   Checks whether the stim buffer for the given event contains data consistent with the last DAQ event         */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCheckBuffer)( VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = VX1000_STIM_RET_TIMEOUT;

  VX1000_UINT32 lastEcuTimestamp = gVX1000.Olda.EventList[(VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].DaqEvent].EventTimestamp;
  VX1000_UINT32 endTimestamp = *(VX1000_UINT32*)(gVX1000.Olda.EventList[stim_event].TransferDest - VX1000_BP_TIMESTAMP_SIZE);
  VX1000_UINT32 startTimestamp = *(VX1000_UINT32*)(gVX1000.Olda.EventList[stim_event].EventTimestamp);

  if ((lastEcuTimestamp == endTimestamp) && (lastEcuTimestamp == startTimestamp))
  {
    retVal = VX1000_STIM_RET_SUCCESS;
  }

  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassCopyBuffer                                                                                     */
/* API name:      none                                                                                                        */
/* Return value:  1 if the data have been successfully copied                                                                 */
/*                2 if data are inconsistent: a serious error has occurred, such as writing to the buffer during copying      */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/* Precondition1: Stimulation must be active and a DAQ event should have been sent before copying.                            */
/* Precondition2: BypassCheckBuffer must have been called before hand to check the buffer data are valid.                     */
/* Precondition3: stim_event must be a valid stim event in the range above                                                    */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Description:   Checks whether the stim buffer for the given event contains data consistent with the last DAQ event         */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassCopyBuffer)( VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = VX1000_STIM_RET_INACTIVE;      /* 0 means "Bypass inactive, enable the bypassed code" */
#if defined(VX1000_OLDA_BENCHMARK) /* Timing measurement */
  VX1000_UINT32 t0 = VX1000_CLOCK();
#endif /* VX1000_OLDA_BENCHMARK */

  /* Do not copy the timestamps at the start and end of the buffers */
  /* TODO: depending on OLDA mode, src and dst must be byte pointers sometimes! */
  VX1000_UINT32* src = (VX1000_UINT32*)(gVX1000.Olda.EventList[stim_event].EventTimestamp + VX1000_BP_TIMESTAMP_SIZE);
  VX1000_UINT32* dst = (VX1000_UINT32*)(gVX1000.Olda.EventList[stim_event].TransferDest);
  /* Size of the buffer in bytes */
  VX1000_UINT32 size = gVX1000.Olda.EventList[stim_event].TransferDest - gVX1000.Olda.EventList[stim_event].EventTimestamp - 2 * VX1000_BP_TIMESTAMP_SIZE;
#if defined(VX1000_OLDA_BENCHMARK)
  gVX1000_OLDA_TransferSize[stim_event]  = size; /* Size of all transfers */
  gVX1000_OLDA_TransferCount[stim_event] = 0;   /* Count of the transfers */
#endif /* VX1000_OLDA_BENCHMARK */

  /* Copy data using memcopy if available */
#if defined(VX1000_MEMCPY)
  VX1000_MEMCPY(dst, src, size);     /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_MEMCPY */
  /* TODO: depending on OLDA mode, the byte count must be used sometimes! */
  size >>= 2; /* Convert buffer size into 32-bit words */
  while (size != 0)
  {
    *dst = *src;
    dst++;     /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
    src++;     /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
    size--;
  }     /* while size */
#endif /* !VX1000_MEMCPY */

  /* Check the timestamp again: */
  if (VX1000_SUFFUN(vx1000_BypassCheckBuffer)(stim_event) == VX1000_STIM_RET_SUCCESS)
  {
    retVal = VX1000_STIM_RET_SUCCESS;
  }
  else
  {
    retVal = VX1000_STIM_RET_ERROR;
  }

#if defined(VX1000_OLDA_BENCHMARK)
  gVX1000_OLDA_Duration[stim_event] = (VX1000_CLOCK()) - t0; /* Timing measurement */
#endif /* VX1000_OLDA_BENCHMARK */

  return retVal;
}

#if defined(VX1000_BYPASS_ALL_CHANS_STIMD)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassAreAllChansStimd                                                                               */
/* API name:      none                                                                                                        */
/* Return value:  TRUE (active) or FALSE (inactive)                                                                           */
/* Precondition1:                                                                                                             */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Description:   Returns true if all channels have received valid stim data                                                  */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassAreAllChansStimd)(void)
{
  VX1000_UINT8 invalidCount = 0;
  VX1000_UINT8 retCode = 0;
  VX1000_UINT8 i;

  /* First check global enable if all channels flag already set */
  if (gVX1000.Stim.Enable != VX1000_STIM_GLOBAL_ALL_CHAN)
  {
    /* If not, loop over all stim events */
    for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
    {
      /* Has the stim channel been activated by the VX - ie do we care if it has stim data? */
      if (((VX1000_STIMEVENT_ARRAYNAME)[i].Enable > VX1000_STIM_INACTIVE)
      /* True if the channel has not yet received valid stim data */
      &&  ((VX1000_STIMEVENT_ARRAYNAME)[i].Enable < VX1000_STIM_BUFFER_VALID) )
      {
        ++invalidCount;
        break;
      }
    }
    if (invalidCount == 0)
    {
      gVX1000.Stim.Enable = VX1000_STIM_GLOBAL_ALL_CHAN;
      retCode = 1;
    }
  }
  else
  {
    retCode = 1;
  }

  return retCode;
}
#endif /* VX1000_BYPASS_ALL_CHANS_STIMD */

#endif /* VX1000_STIM_FORCE_V1 */

#endif /* VX1000_STIM_BY_OLDA */

#if (0==(VX1000_STIM_EVENT_OFFSET))
#define VX1000_IS_STIM_EVENT(e)  ((e) < ((VX1000_STIM_EVENT_OFFSET) + (VX1000_STIM_EVENT_COUNT))) /* PRQA S 3453 */ /* willingly violating MISRA Rule 19.7 because calling a function instead of executing a single machine instruction is far too inefficient for realtime applications */
#else /* VX1000_STIM_EVENT_OFFSET */
#define VX1000_IS_STIM_EVENT(e)  (((e) >= VX1000_STIM_EVENT_OFFSET) && \
                                  ((e) < ((VX1000_STIM_EVENT_OFFSET) + (VX1000_STIM_EVENT_COUNT)))) /* PRQA S 3453 */ /* willingly violating MISRA Rule 19.7 because introducing a new function function only for this specific preprocessor case increases code complexity too much */
#endif /* VX1000_STIM_EVENT_OFFSET */


#if (!defined(VX1000_RESET_STIM_TIMEOUT)) || (!defined(VX1000_CHECK_STIM_TIMEOUT))
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: SetTimeoutUs                                                                                                */
/* API name:      VX1000_RESET_STIM_TIMEOUT (internal)                                                                        */
/* Return value:  The absolute timeout time as clock value in [ticks].                                                        */
/* Parameter1:    t: the relative timeout time in [us].                                                                       */
/*                No invalid input possible.                                                                                  */
/* Preemption:    No problem inside this function, but the API must not hit into an existing SetTimeoutUs-CheckTimeout frame. */
/* Termination:   No effect                                                                                                   */
/* Precondition1: the timer used by VX1000_CLOCK() must already running (with the expected speed).                            */
/* Description:   Calculates the absolute due time.                                                                           */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT32 VX1000_SUFFUN(SetTimeoutUs)(VX1000_UINT32 t)
{
#if ((VX1000_CLOCK_TICKS_BASE_NS) < 100000UL) /* was: "#if ((VX1000_CLOCK_TICKS_PER_US) > 10)", but CLOCK_TICKS may be a function! */
  VX1000_UINT32 dt = t * (VX1000_CLOCK_TICKS_PER_US);
#else /* VX1000_CLOCK_TICKS_BASE_NS */
  VX1000_UINT32 dt = (t * (VX1000_CLOCK_TICKS_PER_MS)) / 1000UL;
#endif /* VX1000_CLOCK_TICKS_BASE_NS */
  if ( dt >= ((1UL << (((VX1000_CLOCK_TIMER_SIZE) - 1) & 0x1F)) /* dummy operation needed for MISRA: */ + ( 0UL & t) ) )
  {
    dt = (1UL << (((VX1000_CLOCK_TIMER_SIZE) - 1) & 0x1F)) - 1UL;
    VX1000_ERRLOGGER(VX1000_ERRLOG_TM_DTST_TOO_LONG)
  }
  return (VX1000_CLOCK()) + dt;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: CheckTimeout                                                                                                */
/* API name:      VX1000_CHECK_STIM_TIMEOUT (internal)                                                                        */
/* Return value:  true if action timed out, false otherwise.                                                                  */
/* Parameter1:    timeout: the deadline in [ticks].                                                                           */
/*                No invalid input possible.                                                                                  */
/* Preemption:    No problem                                                                                                  */
/* Termination:   No effect                                                                                                   */
/* Precondition1: SetTimeoutUs() must have been called before for an absolute time lying max. 0x7FFFFFFF ticks in the past.   */
/* Description:   checks whether the precomputed deadline has be passed already or not.                                       */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(CheckTimeout)(VX1000_UINT32 timeout)
{
  VX1000_UINT8 retVal = 0;  /* "no timeout, yet" */
  if (((timeout - (VX1000_CLOCK())) & (1UL << (((VX1000_CLOCK_TIMER_SIZE) - 1) & 0x1F))) != 0) { retVal = 1; }
  return retVal;
}

/* todo MISRA-C:2004 Rule 19.4: the next line violates(?) the "C macros shall only expand to a braced initialised, a constant, /
/  a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct."-rule!               /
/  Embracing it or wrapping into do-while-zero however did not make the QAC message vanish. So check why we need               /
/  this user-re-definable macro at all or whether we can manually expand it in the code. As far as I remember, the             /
/  possibility to use a user's variant had only been included because the built-in version was not thread-safe but some        /
/  users needed a thread-safe version and could overload the built-in implementation with their own, correct version. This     /
/  workaround would then no longer be needed ...                                                                              */
#define VX1000_RESET_STIM_TIMEOUT_V2(x,e) gVX1000_timeout[(e) - (VX1000_STIM_EVENT_OFFSET)] = VX1000_SUFFUN(SetTimeoutUs)((VX1000_UINT32)(x));  /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_CHECK_STIM_TIMEOUT_V2(e) VX1000_SUFFUN(CheckTimeout)(gVX1000_timeout[(e) - (VX1000_STIM_EVENT_OFFSET)]) /* Return true if timeout */  /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#else /* VX1000_RESET_STIM_TIMEOUT && VX1000_CHECK_STIM_TIMEOUT */
/* use the checks provided by the user */
#define VX1000_RESET_STIM_TIMEOUT_V2(x,e) VX1000_RESET_STIM_TIMEOUT(x) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_CHECK_STIM_TIMEOUT_V2(e)   VX1000_CHECK_STIM_TIMEOUT() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#endif /* VX1000_RESET_STIM_TIMEOUT && VX1000_CHECK_STIM_TIMEOUT */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimSkip                                                                                             */
/* API name:      VX1000_STIM_SKIP                                                                                            */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/* Precondition1:                                                                                                             */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Description:   Sends a stim skip event to tell the VX not to stimulate the next cycle (in effect a dummy STIM request)     */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimSkip)( VX1000_UINT8 stim_event )
{
  if (VX1000_STIM_ACTIVE(stim_event) != 0)
  {
    VX1000_SPECIAL_EVENT(VX1000_ECU_EVT_STIM_SKIP( stim_event ))
  }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimInit                                                                                             */
/* API name:      VX1000_STIM_INIT                                                                                            */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function should not interrupt and should not be interrupted by code that reads the stimulation data.   */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_InitAsyncStart must have been called.                                                                */
/* Description:   Initializes the stimulation control structures. Called in VX1000_INIT_ASYNC_START() and every time STIM     */
/*                is turned off                                                                                               */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimInit)(void)
{
  VX1000_UINT32 i;

  gVX1000.Stim.Control = 0;
  gVX1000.Stim.EvtOffset = VX1000_STIM_EVENT_OFFSET;
  gVX1000.Stim.EvtNumber = VX1000_STIM_EVENT_COUNT;

#if !defined(VX1000_STIM_FORCE_V1)
  gVX1000.Stim.Version = 0;
  for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
  {
    (VX1000_STIMEVENT_ARRAYNAME)[i].Ctr = 0;
    (VX1000_STIMEVENT_ARRAYNAME)[i].RqCtr = 0;
    (VX1000_STIMEVENT_ARRAYNAME)[i].Enable = 0;
#if !defined(VX1000_STIM_BY_OLDA)
    gVX1000.Stim.Event[i].Copying = 0;
#endif /* !VX1000_STIM_BY_OLDA */
  }
  gVX1000.Stim.Enable = 0;
#else /* VX1000_STIM_FORCE_V1 */
  gVX1000.Stim.Version = 1;
  gVX1000.Stim.EventPointer = (VX1000_UINT32)&gVX1000.Stim.Events; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#if defined(VX1000_HOOK_BASED_BYPASSING)
  gVX1000.Stim.hbbLUTNumber = VX1000_BYPASS_HBB_LUT_ENTRIES;
  gVX1000.Stim.hbbLUTPointer = (VX1000_UINT32)( VX1000_BYPASS_HBB_LUT_ADDR );
  gVX1000.Stim.hbbLUTVXPointer = 0;
#endif /* VX1000_HOOK_BASED_BYPASSING */
  gVX1000.Stim.Events.MagicId = VX1000_STIM_EVENT_MAGIC;
  gVX1000.Stim.Events.Version = 1;

  for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
  {
    (VX1000_STIMEVENT_ARRAYNAME)[i].DaqEvent = 0;
    (VX1000_STIMEVENT_ARRAYNAME)[i].Enable = VX1000_STIM_INACTIVE;
    (VX1000_STIMEVENT_ARRAYNAME)[i].EventType = VX1000_BYPASS_TYPE_DIRECT;
    (VX1000_STIMEVENT_ARRAYNAME)[i].Copying = 0;
    (VX1000_STIMEVENT_ARRAYNAME)[i].Ctr = 0;
    (VX1000_STIMEVENT_ARRAYNAME)[i].RqCtr = 0;
  }
  VX1000_SET_STIM_INFO()
  gVX1000.Stim.Enable = VX1000_STIM_GLOBAL_INACTIVE;
#endif /* VX1000_STIM_FORCE_V1 */
  if ( ((volatile VX1000_UINT8 *)&gVX1000.Stim.EvtOffset) != &(((volatile VX1000_UINT8 *)&gVX1000.Stim)[0x8]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_STIM_T, EvtOffset)) != 0x8) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }
  gVX1000.Stim.MagicId = (VX1000_UINT32)(VX1000_STIM_MAGIC);
}


#if defined(VX1000_STIM_BENCHMARK)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimBenchmarkInit                                                                                    */
/* API name:      VX1000_STIM_BENCHMARK_INIT                                                                                  */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: none                                                                                                        */
/* Description:   Initializes the STIM benchmark data.                                                                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimBenchmarkInit)( void )
{
  VX1000_UINT32 i;

  for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
  {
    gVX1000_STIM_Begin[i] = 0;
    gVX1000_STIM_Duration[i] = 0;
  }

#if defined(VX1000_STIM_HISTOGRAM)
  for (i = 0; i < 256; i++) { gVX1000_STIM_Histogram[i] = 0; }
  for (i = 0; i < 16; i++) { gVX1000_STIM_Histogram2[i] = 0; }
#endif /* VX1000_STIM_HISTOGRAM */
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimBenchmarkStimBegin                                                                               */
/* API name:      VX1000_STIM_BENCHMARK_STIM_BEGIN                                                                            */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                            */
/*                Validity has to be ensured by caller.                                                                       */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: The timer used by VX1000_CLOCK must already be up and running.                                              */
/* Description:   Remembers the start time of a stim transfer.                                                                */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimBenchmarkStimBegin)( VX1000_UINT8 stim_event )
{
  gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)] = VX1000_CLOCK(); /* Timing measurement */
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimBenchmarkStimEnd                                                                                 */
/* API name:      VX1000_STIM_BENCHMARK_STIM_END                                                                              */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                            */
/*                Validity has to be ensured by caller.                                                                       */
/* Parameter2:    flag signalling whether there was a stim timeout (TRUE) or not (FALSE)                                      */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: VX1000_STIM_BENCHMARK_STIM_BEGIN shall have been called before for the same event.                          */
/* Description:   Record de duration of the current stim transfer; also update the stim histogram.                            */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimBenchmarkStimEnd)( VX1000_UINT8 stim_event, VX1000_UINT8 timeout_flag )
{
  VX1000_UINT32 t0,t1,dt;

  t0 = gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)];
  if (t0 != 0)
  {
    gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)] = 0;
    t1 = VX1000_CLOCK();
    dt =  t1 - t0;
    gVX1000_STIM_Duration[stim_event - (VX1000_STIM_EVENT_OFFSET)] = dt; /* Last delay for each individual event */

    /* Build the histograms for event VX1000_STIM_HISTOGRAM */
#if defined(VX1000_STIM_HISTOGRAM)
    if (stim_event == (VX1000_STIM_HISTOGRAM))
    {
      gVX1000_STIM_Histogram2[0]++; /* Index 0 is the cycles with 0 timeouts counter ! */

      if (0==timeout_flag)
      {
        /* Build the delay histogram */
        /* 20us resolution, 0..5100us:     */
        if ((VX1000_CLOCK_TICKS_PER_MS) >= 50) /* note: this cannot be replaced by a preprocessor condition because the user may define VX1000_CLOCK_TICKS_PER_MS to a runtime evaluated formula/function */
        {
          t0 = (VX1000_UINT32)(dt / (VX1000_UINT32)((VX1000_CLOCK_TICKS_PER_MS) / 50UL));
        }
        else
        {
          t0 = (VX1000_UINT32)((VX1000_UINT32)(50UL * dt) / (VX1000_CLOCK_TICKS_PER_MS));
        }
        if (t0 >= 256UL) { t0 = 255UL; }
        gVX1000_STIM_Histogram[t0]++;
      }
      else
      {
        /* Build the timeout burst count histogram */
        /* 0..15 */
        t0 = gVX1000.Stim.TimeoutCtr2;
        if (t0 <= 15)
        {
          gVX1000_STIM_Histogram2[t0]++;
          gVX1000_STIM_Histogram2[t0-1]--; /* t0 is always >0 when timeout_flag is set */
        }
      }
    }
#else /* !VX1000_STIM_HISTOGRAM */
    VX1000_DUMMYREAD(timeout_flag) /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#endif /* !VX1000_STIM_HISTOGRAM */
  }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimBenchmarkStimCheck                                                                               */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: VX1000_STIM_INIT must have been called.                                                                     */
/* Description:                                                                                                               */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_StimBenchmarkStimCheck)( void )
{
#if defined(VX1000_STIM_HISTOGRAM)
  if (VX1000_STIM_ACTIVE(VX1000_STIM_HISTOGRAM) != 0)
  {
#if !defined(VX1000_STIM_FORCE_V1)
    if ((VX1000_STIMEVENT_ARRAYNAME)[(VX1000_STIM_HISTOGRAM) - (VX1000_STIM_EVENT_OFFSET)].Ctr
    ==  (VX1000_STIMEVENT_ARRAYNAME)[(VX1000_STIM_HISTOGRAM) - (VX1000_STIM_EVENT_OFFSET)].RqCtr)
#else /* VX1000_STIM_FORCE_V1 */
    if (VX1000_SUFFUN(vx1000_BypassCheckCounters)(VX1000_STIM_HISTOGRAM) == VX1000_STIM_RET_SUCCESS)
#endif /* VX1000_STIM_FORCE_V1 */
    {
      VX1000_STIM_BENCHMARK_STIM_END(VX1000_STIM_HISTOGRAM, 0)
    }
  }
#endif /* VX1000_STIM_HISTOGRAM */
}


#endif /* VX1000_STIM_BENCHMARK */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimControl                                                                                          */
/* API name:      VX1000_STIM_CONTROL / VX1000_BYPASS_CONTROL                                                                 */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: VX1000_STIM_INIT must have been called.                                                                     */
/* Description:   The Stim-Keep-Alive-Handler (to be called cyclically by the application).                                   */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimControl)(void)
{
  if ((gVX1000.Stim.Control != 0) && (0==gVX1000.Stim.Enable))
  {
#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
    /* Reset state of generic hooking -- the code is a little bit misplaced, isn't it ... */
#if defined(VX1000_HOOK_ENABLE)
    gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
    gVX1000_HookControl.active_id = 0xFFFFU;
#endif /* VX1000_HOOK_ENABLE */
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */

    /* Clear benchmark data */
    VX1000_STIM_BENCHMARK_INIT()

    gVX1000.Stim.TimeoutCtr = 0;
    gVX1000.Stim.TimeoutCtr2 = 0;

#if defined(VX1000_STIM_TYPE_0)
    VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ACK) /* Send an acknowledge STIM event when the ECU is ready for STIM  */ /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
#endif /* VX1000_STIM_TYPE_0 */

    gVX1000.Stim.Enable = VX1000_STIM_GLOBAL_VX_ENABLE;
  }
  else
  {
    /* Reinitialize STIM when VX1000 turns STIM off (but hold the timeout counters) */
    if ((0==gVX1000.Stim.Control) && (gVX1000.Stim.Enable != VX1000_STIM_GLOBAL_INACTIVE)) { VX1000_STIM_INIT() }
  }

#if defined(VX1000_STIM_BENCHMARK)
  /* STIM Benchmark: Specific measurements for a single event from request to acknowledge */
  VX1000_SUFFUN(vx1000_StimBenchmarkStimCheck)();
#endif /* VX1000_STIM_BENCHMARK */
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimActive                                                                                           */
/* API name:      VX1000_STIM_ACTIVE                                                                                          */
/* Return value:  TRUE (active) or FALSE (inactive)                                                                           */
/* Parameter1:    eventNumber E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                            */
/*                Validity has to be ensured by caller!                                                                       */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: VX1000_STIM_INIT must have been called.                                                                     */
/* Description:   Returns true if stim is active both globally and for a specific event.                                      */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_StimActive)( VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = 0;  /* "inactive" */
  if ((gVX1000.Stim.Control != 0) && (gVX1000.Stim.Enable != VX1000_STIM_GLOBAL_INACTIVE) && (VX1000_IS_STIM_EVENT(stim_event))
  && ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable != 0))
  {
    retVal = 1;  /* "active" */
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimRequest                                                                                          */
/* API name:      VX1000_STIM_REQUEST                                                                                         */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                            */
/*                Validity has to be ensured by caller!                                                                       */
/* Preemption:    This function must not interrupt and not be interrupted by vx1000_* functions operating on the same event.  */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Request a specific STIM data set associated to event stim_event.                                            */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_StimRequest)( VX1000_UINT8 stim_event )
{
  VX1000_STIM_BENCHMARK_STIM_BEGIN(stim_event)

#if defined(VX1000_STIM_FORCE_V1)
  /* Only if the event is "direct stimulation" instead of stim-by-olda, send a stim request */
  if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].EventType == VX1000_BYPASS_TYPE_DIRECT)
#endif /* VX1000_STIM_FORCE_V1 */
  {
    (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr++;
    VX1000_STIM_REQUEST_EVENT(stim_event)
  }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimWait                                                                                             */
/* API name:      VX1000_STIM_WAIT (expression) / VX1000_STIM_WAIT_VOID (statement) /                                         */
/*                VX1000_BYPASS_STIM (expression) / VX1000_BYPASS_STIM_VOID (statement)                                       */
/* Return value:  0 (data arrived before timeout or timeout but data still copied successfully)                               */
/*                1 (timeout, no new data arrived or error during copying and destination data corrupted)                     */
/* Parameter1:    eventNumber E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                            */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    flag: 0 (don't copy data / 1 (copy olda data)                                                               */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter3:    timeout in microseconds, starting from related call to VX1000_STIM_REQUEST                                  */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: VX1000_STIM_INIT must have been called initially.                                                           */
/* Precondition2: VX1000_STIM_REQUEST must have been called recently for the same event.                                      */
/* Description:   Busy wait until a specific STIM request is fulfilled.                                                       */
/*                Optionally processes all transfer descriptors assigned to parameter1 (only available with olda).            */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_StimWait)( VX1000_UINT8 stim_event, VX1000_UINT8 copy_enable, VX1000_UINT32 timeout_us )
{
  VX1000_UINT8 errorcode = 0U;
#if (!defined(VX1000_RESET_STIM_TIMEOUT)) || (!defined(VX1000_CHECK_STIM_TIMEOUT))
  static volatile VX1000_UINT32 gVX1000_timeout[VX1000_STIM_EVENT_COUNT]; /* can be per core and static */
#endif /* !VX1000_RESET_STIM_TIMEOUT || !VX1000_CHECK_STIM_TIMEOUT */

#if !defined(VX1000_STIM_FORCE_V1)
  VX1000_RESET_STIM_TIMEOUT_V2(timeout_us, stim_event)
  while ( (0==errorcode) /* Busy wait with timeout until direct stimulation is done (or olda stimulation data arrived) */
  && ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Ctr
  !=  (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr) )
  {
    if ((VX1000_CHECK_STIM_TIMEOUT_V2(stim_event)) != 0)
    {
#if !defined(VX1000_STIM_BY_OLDA)
      if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Copying != 0)
      {
        /* If timeout happened, but copying data has already started,    */
        /* give a second chance to complete within the next millisecond: */
        VX1000_RESET_STIM_TIMEOUT_V2(1000U, stim_event)
        while (0==errorcode)
        {
          if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Ctr
          ==  (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr)
          {
            errorcode = 1; /* timeout, but new data already valid */
          }
          else if ((VX1000_CHECK_STIM_TIMEOUT_V2(stim_event)) != 0)
          {
            VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ERR(stim_event)) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
            errorcode = 2; /* timeout, data incomplete */
          }
          else
          {
            ; /* empty else is only here for MISRA */
          }
        }
      }
      else
#endif /* !VX1000_STIM_BY_OLDA */
      {
        if ((VX1000_STIM_ACTIVE(stim_event)) != 0) { VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(stim_event)) } /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
        errorcode = 2; /* timeout, no new data */
      }
    } /* Timeout */
  } /* while */

  if (errorcode == 2) /* Timeout (no new valid data) --> increment timeout counter and timeout burst counter */
  {
    gVX1000.Stim.TimeoutCtr++;
    gVX1000.Stim.TimeoutCtr2++;
  }
  else /* either no timeout at all or timeout, but still all data arrived successfully */
  {
    gVX1000.Stim.TimeoutCtr2 = 0; /* Clear the timeout burst counter */
#if defined(VX1000_STIM_BY_OLDA)
    if (copy_enable != 0)
    {
      /* Copy the STIM data to final memory locations */
      VX1000_SUFFUN(vx1000_StimTransfer)(stim_event);
    }
#else  /* !VX1000_STIM_BY_OLDA */
    VX1000_DUMMYREAD(copy_enable) /* only here to prevent compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#endif /* !VX1000_STIM_BY_OLDA */
  }
  errorcode >>= 1;
  VX1000_STIM_BENCHMARK_STIM_END(stim_event, errorcode)
  return errorcode;
#else /* VX1000_STIM_FORCE_V1 */
  VX1000_UINT8 retVal = 2;

  if ((VX1000_STIM_ACTIVE(stim_event) != VX1000_STIM_GLOBAL_INACTIVE)
  &&  ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable >= VX1000_STIM_DAQ_SENT))
  {
    VX1000_RESET_STIM_TIMEOUT_V2(timeout_us, stim_event)

    /* Step 1: Busy wait to check for valid STIM data */
    /* Check whether new data have arrived - in the case of direct stim, counters are checked, for OLDA, the buffer timestamps */
    while ((errorcode==0) && (VX1000_SUFFUN(vx1000_BypassCheckCounters)(stim_event) != VX1000_STIM_RET_SUCCESS))
    {
      if ((VX1000_CHECK_STIM_TIMEOUT_V2(stim_event)) != 0)
      {
        /* Timeout handling only for direct events, otherwise, just ignore the data */
        if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].EventType == VX1000_BYPASS_TYPE_DIRECT)
        {
          if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Copying != 0)
          {
            /* If timeout happened, but copying data has already started,   */
            /* give a second chance to complete within the next millisecond: */
            VX1000_RESET_STIM_TIMEOUT_V2(1000U, stim_event)
            while (0==errorcode)
            {
              if (VX1000_SUFFUN(vx1000_BypassCheckCounters)(stim_event) == VX1000_STIM_RET_SUCCESS)
              {
                errorcode = 1; /* timeout, but new data already valid */
              }
              else if ((VX1000_CHECK_STIM_TIMEOUT_V2(stim_event)) != 0)
              {
                /* todo: the nesting of conditions is too deep for some compilers - rework this function! (VX1000_SPECIAL_EVENT is a macro with further conditions, especially on Tricore) */
                VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ERR(stim_event)) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
                errorcode = 3; /* timeout, data incomplete */
                (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable = VX1000_STIM_BUFFER_INVALID; /* Data invalid */
              }
              else
              {
                ; /* this empty else case and semicolon are only here for MISRA */
              }
            }
          }
          else
          {
            VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(stim_event)) /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
            errorcode = 2; /* timeout, no new data */
          }
        } /* direct stimulation */
        else
        {
          /* Do not send a timeout for OLDA-based stimulation */
          errorcode = 2; /* timeout, no new data */
        }
      }  /* Timeout */
    } /* while loop checking stim data validity */

    /* Step 2: Check the errorcode and copy data in the case of OLDA */
    if (errorcode < 2) /* todo: care for "The result of this logical operation is always 'false'." compiler warning */
    {
      /* Set data valid flag for the event */
      (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable = VX1000_STIM_BUFFER_VALID;
#if defined(VX1000_STIM_BY_OLDA)
      if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].EventType != VX1000_BYPASS_TYPE_DIRECT)
      {
        /* Copy data from VX-write to ECU-read buffer */
        if (VX1000_SUFFUN(vx1000_BypassCopyBuffer)(stim_event) != VX1000_STIM_RET_SUCCESS)
        {
          /* Flag errors during copying */
          (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable = VX1000_STIM_BUFFER_INVALID;
          errorcode = 3;
        }
        /* Copy the STIM data to final memory locations */
        else if ((copy_enable != 0)
        && ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].EventType == VX1000_BYPASS_TYPE_OLDA)
#if defined(VX1000_BYPASS_ALL_CHANS_STIMD)
        && (VX1000_SUFFUN(vx1000_BypassAreAllChansStimd)() == 1)) /* Only copy if valid stim data received from all other channels first */
#else /* VX1000_BYPASS_ALL_CHANS_STIMD */
        && ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable == VX1000_STIM_BUFFER_VALID))
#endif /* VX1000_BYPASS_ALL_CHANS_STIMD */
        {
          VX1000_SUFFUN(vx1000_StimTransfer)(stim_event);
        }
      }
#else /* !VX1000_STIM_BY_OLDA */
    if (copy_enable != 0)
    {
      ;  /* dummy access and empty statement here only to prevent compiler warning and to please MISRA */
    }
#endif /* !VX1000_STIM_BY_OLDA */
    }

    /* Step 3: Check the errorcode for timeouts and errors */
    /* todo: care for the "The result of this logical operation is always 'true'." compiler warning */
    if (errorcode >= 2) /* Timeout (no new valid data) --> increment timeout counter and timeout burst counter */
    {
      gVX1000.Stim.TimeoutCtr++;
      gVX1000.Stim.TimeoutCtr2++;
      if (errorcode == 3)
      {
        retVal = 3;
      }
      else
      {
        retVal = 2;
      }
    }
    else /* either no timeout at all or timeout, but still all data arrived successfully */
    {
      gVX1000.Stim.TimeoutCtr2 = 0; /* Clear the timeout burst counter */
      retVal = 0;
    }
    errorcode >>= 1;
    VX1000_STIM_BENCHMARK_STIM_END(stim_event, errorcode)
  } /* STIM event active & DAQ event sent */

  return retVal >> 1; /* turn the verbose internal status into the bool of the API */
#endif /* VX1000_STIM_FORCE_V1 */
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_Bypass                                                                                               */
/* API name:      VX1000_BYPASS (expression) / VX1000_BYPASS_VOID (statement)                                                 */
/* Return value:  status: 0 (bypassed code shall be activated because bypassing is not active)                                */
/*                1 (everything done, bypassed code shall be disabled)                                                        */
/*                2 (bypassing failed; it's up to the application design whether executing the bypassed code makes sense here)*/
/* Parameter1:    daq_event E [0,gVX1000.Olda.EventCount)                                                                     */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    stim_event E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                             */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter3:    timeout in microseconds, starting right now.                                                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Initiate a bypass by sending DAQ data to the tool and implicitly requesting a stimulation (daq_event),      */
/*                then busy wait with timeout for the tool to complete the stimulation (stim_event).                          */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_Bypass)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us)
{
  VX1000_UINT8 retVal = 0;    /* 0 means "Bypass inactive, enable the bypassed code" */

#if !defined(VX1000_STIM_FORCE_V1)
  if ((VX1000_STIM_ACTIVE(stim_event)) != 0)
  {
    VX1000_EVENT(daq_event)
    VX1000_STIM_REQUEST(stim_event)
    if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0)
#else /* VX1000_STIM_FORCE_V1 */
  if ((VX1000_BYPASS_DAQ(daq_event, stim_event)) == VX1000_STIM_RET_SUCCESS)
  {
    if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0) /* note: do NOT use VX1000_STIM_RET_SUCCESS here because STIM_WAIT's return codes differ from STIM_EVENT's! */
#endif /* VX1000_STIM_FORCE_V1 */
    {
      retVal = 2;           /* "Bypass active, timeout" */
    }
    else
    {
      retVal = 1;           /* "Bypass active, OK, disable the bypassed code" */
    }
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassTrigger                                                                                        */
/* API name:      VX1000_BYPASS_TRIGGER (expression) / VX1000_BYPASS_TRIGGER_VOID (statement)                                 */
/* Return value:  status: 0 (bypassed code shall be activated because bypassing is not active)                                */
/*                1 (everything done, bypassed code shall be disabled)                                                        */
/* Parameter1:    daq_event E [0,gVX1000.Olda.EventCount)                                                                     */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    stim_event E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                             */
/*                Validity has to be ensured by caller!                                                                       */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Initiate a bypass by sending DAQ data to the tool and implicitly requesting a stimulation (daq_event).      */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassTrigger)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = VX1000_STIM_RET_INACTIVE;  /* 0 means "Bypass inactive" */

  if (VX1000_STIM_ACTIVE(stim_event) != 0)
  {
    VX1000_EVENT(daq_event)
#if defined(VX1000_STIM_FORCE_V1)
    if ((VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable < VX1000_STIM_DAQ_SENT)
    {
      (VX1000_STIMEVENT_ARRAYNAME)[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable = VX1000_STIM_DAQ_SENT;
    }
#endif /* VX1000_STIM_FORCE_V1 */
    retVal = VX1000_STIM_RET_SUCCESS;              /* "Bypass active" */
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassDaq                                                                                            */
/* API name:      VX1000_BYPASS_DAQ (expression) / VX1000_BYPASS_DAQ_VOID (statement)                                         */
/* Return value:  status: 0 (bypassed code shall be activated because bypassing is not active)                                */
/*                1 (everything done, bypassed code shall be disabled)                                                        */
/* Parameter1:    daq_event E [0,gVX1000.Olda.EventCount)                                                                     */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    stim_event E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                             */
/*                Validity has to be ensured by caller!                                                                       */
/* Description:   Initiate a bypass by sending a DAQ event followed by a stim request                                         */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassDaq)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event )
{
  VX1000_UINT8 retVal = VX1000_BYPASS_TRIGGER(daq_event, stim_event);
  if (retVal != (VX1000_STIM_RET_INACTIVE))
  {
    VX1000_STIM_REQUEST(stim_event)
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassWait                                                                                           */
/* API name:      VX1000_BYPASS_WAIT (expression) / VX1000_BYPASS_WAIT_VOID (statement)                                       */
/* Return value:  status: 0 (bypassed code shall be activated because bypassing is not active)                                */
/*                1 (everything done, bypassed code shall be disabled)                                                        */
/*                2 (bypassing failed; it's up to the application design whether executing the bypassed code makes sense here)*/
/* Parameter1:    stim_event E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                             */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    timeout in microseconds, starting right now.                                                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Busy wait with timeout for the tool to complete a stimulation (stim_event) that has been initiated          */
/*                beforehand by an appropriate call to VX1000_BYPASS_TRIGGER.                                                 */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassWait)( VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us )
{
  VX1000_UINT8 retVal = 0;    /* 0 means "Bypass inactive, enable the bypassed code" */

  if (VX1000_STIM_ACTIVE(stim_event) != 0)
  {
    VX1000_STIM_REQUEST(stim_event)
    if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0) /* note: do NOT use VX1000_STIM_RET_SUCCESS here because STIM_WAIT's return codes differ from STIM_EVENT's! */
    {
      retVal = 2;           /* "Bypass active, timeout. It may be too late to enable the bypassed code" */
    }
    else
    {
      retVal = 1;           /* "Bypass active, ok, disable the bypassed code" */
    }
  }
  return retVal;
}

#if defined(VX1000_HOOK_BASED_BYPASSING)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbHookValid                                                                                   */
/* API name:      none                                                                                                        */
/* Return value:  status: 0 (the given hook is not valid: invalid ID, stim inactive, invalid LUT address, no valid stim data) */
/*                1 (the given hook is valid and has valid data ready)                                                        */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassHbbHookValid)(VX1000_UINT32 HookID)
{
  VX1000_UINT8 retVal = 0;
  /* First check whether the hook table has a valid pointer and if the hook is valid */
  if ( (gVX1000.Stim.hbbLUTVXPointer != 0) && (HookID < VX1000_BYPASS_HBB_LUT_ENTRIES) )
  {
    /* Is the stim event valid and the olda address set */
    if ( (VX1000_STIM_ACTIVE(VX1000_HBB_LUT(HookID).StimEvent)) && (VX1000_HBB_LUT(HookID).OldaAddress != 0xFFFF) )
    {
#if defined(VX1000_BYPASS_ALL_CHANS_STIMD) && defined(VX1000_STIM_FORCE_V1)
      /* Have all channels been stimulated */
      if (VX1000_SUFFUN(vx1000_BypassAreAllChansStimd)() == 1)
#else /* !VX1000_BYPASS_ALL_CHANS_STIMD || !VX1000_STIM_FORCE_V1 */
      /* Has this single channel been stimulated */
      if (gVX1000.Stim.Events.Event[VX1000_HBB_LUT(HookID).StimEvent - (VX1000_STIM_EVENT_OFFSET)].Enable == VX1000_STIM_BUFFER_VALID)
#endif /* !VX1000_BYPASS_ALL_CHANS_STIMD || !VX1000_STIM_FORCE_V1 */
      {
        {
          retVal = 1;
        }
      }
    }
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_8                                                                                    */
/* API name:      VX1000_BYPASS_HBB_GETVAL_8 (expression)                                                                     */
/* Return value:  VX1000_UINT8 corresponding to the stimulated value if hook is valid and data available                      */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassHbbGetVal_8) (VX1000_UINT32 HookID, VX1000_UINT8 DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    DefaultValue = *src;
  }
  return DefaultValue;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_16                                                                                   */
/* API name:      VX1000_BYPASS_HBB_GETVAL_16 (expression)                                                                    */
/* Return value:  VX1000_UINT16 corresponding to the stimulated value if hook is valid and data available                     */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT16 VX1000_SUFFUN(vx1000_BypassHbbGetVal_16) (VX1000_UINT32 HookID, VX1000_UINT16 DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    if ((((VX1000_UINT32)src) & 0x00000001UL) != 0)
    {
      VX1000_UINT8 i, *dst = (VX1000_UINT8*)&DefaultValue;
      for (i = 0; i < sizeof(DefaultValue); ++i)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      DefaultValue = *(VX1000_UINT16*)src;
    }
  }
  return DefaultValue;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_32                                                                                   */
/* API name:      VX1000_BYPASS_HBB_GETVAL_32 (expression)                                                                    */
/* Return value:  VX1000_UINT32 corresponding to the stimulated value if hook is valid and data available                     */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_BypassHbbGetVal_32)  (VX1000_UINT32 HookID, VX1000_UINT32 DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    if ((((VX1000_UINT32)src) & 0x00000003UL) != 0)
    {
      VX1000_UINT8 i, *dst = (VX1000_UINT8*)&DefaultValue;
      for (i = 0; i < sizeof(DefaultValue); ++i)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      DefaultValue = *(VX1000_UINT32*)src;
    }
  }
  return DefaultValue;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_64                                                                                   */
/* API name:      VX1000_BYPASS_HBB_GETVAL_64 (expression)                                                                    */
/* Return value:  VX1000_UINT64 corresponding to the stimulated value if hook is valid and data available                     */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT64 VX1000_SUFFUN(vx1000_BypassHbbGetVal_64)  (VX1000_UINT32 HookID, VX1000_UINT64 DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    if ((((VX1000_UINT32)src) & 0x00000003UL) != 0) /* hint: automotive PowerPC allows 64bit access also on 32bit boundaries */
    {
      VX1000_UINT8 i, *dst = (VX1000_UINT8*)&DefaultValue;
      for (i = 0; i < sizeof(DefaultValue); ++i)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      DefaultValue = *(VX1000_UINT64*)src;
    }
  }
  return DefaultValue;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_Float                                                                                */
/* API name:      VX1000_BYPASS_HBB_GETVAL_FLOAT (expression)                                                                 */
/* Return value:  VX1000_FLOAT corresponding to the stimulated value if hook is valid and data available                      */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_FLOAT VX1000_SUFFUN(vx1000_BypassHbbGetVal_Float)  (VX1000_UINT32 HookID, VX1000_FLOAT DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    if ((((VX1000_UINT32)src) & 0x00000003UL) != 0)
    {
      VX1000_UINT8 i, *dst = (VX1000_UINT8*)&DefaultValue;
      for (i = 0; i < sizeof(DefaultValue); ++i)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      DefaultValue = *(VX1000_FLOAT*)src;
    }
  }
  return DefaultValue;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_BypassHbbGetVal_Double                                                                               */
/* API name:      VX1000_BYPASS_HBB_GETVAL_DOUBLE (expression)                                                                */
/* Return value:  VX1000_DOUBLE corresponding to the stimulated value if hook is valid and data available                     */
/*                DefaultValue is returned otherwise                                                                          */
/* Parameter1:    HookID H [0,VX1000_BYPASS_HBB_LUT_ENTRIES)                                                                  */
/*                Validity checked by the function                                                                            */
/* Parameter2:    DefaultValue D to be returned if hook is not valid                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Check whether valid data corresponding to the given Hook ID is present in the buffer                        */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_DOUBLE VX1000_SUFFUN(vx1000_BypassHbbGetVal_Double)  (VX1000_UINT32 HookID, VX1000_DOUBLE DefaultValue)
{
  if ((VX1000_SUFFUN(vx1000_BypassHbbHookValid)(HookID)) != 0)
  {
    VX1000_UINT8 *src = (VX1000_UINT8*)(gVX1000.Olda.EventList[VX1000_HBB_LUT(HookID).StimEvent].TransferDest + VX1000_HBB_LUT(HookID).OldaAddress);
    if ((((VX1000_UINT32)src) & 0x00000003UL) != 0) /* hint: automotive PowerPC allows 64bit access also on 32bit boundaries */
    {
      VX1000_UINT8 i, *dst = (VX1000_UINT8*)&DefaultValue;
      for (i = 0; i < sizeof(DefaultValue); ++i)
      {
        dst[i] = src[i];
      }
    }
    else
    {
      DefaultValue = *(VX1000_DOUBLE*)src;
    }
  }
  return DefaultValue;
}

#endif /* VX1000_HOOK_BASED_BYPASSING */

/* Reuse the events copying flag as cycle delay counter: */
#define VX1000_CYCLE_DELAY_CTR(event) (VX1000_STIMEVENT_ARRAYNAME)[(event) - (VX1000_STIM_EVENT_OFFSET)].Copying /* PRQA S 3453 */ /* willingly violating MISRA Rule 19.7 because define is used as an lvalue and thus cannot be replaced by a function call */

/*#if defined(VX1000_STIM_BY_OLDA) -- now the parallel pods can stimulate even without OLDA */


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_Stimulate                                                                                            */
/* API name:      VX1000_STIMULATE (expression) / VX1000_STIMULATE_VOID (statement)                                           */
/* Return value:  status: 0 (bypassed code shall be activated because bypassing is not active)                                */
/*                1 (everything done, bypassed code shall be disabled)                                                        */
/*                2 (bypassing failed; it's up to the application design whether executing the bypassed code makes sense here)*/
/* Parameter1:    stim_trigger_event E [0,gVX1000.Olda.EventCount)                                                            */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter2:    stim_event E [VX1000_STIM_EVENT_OFFSET,gVX1000.Olda.EventCount)                                             */
/*                Validity has to be ensured by caller!                                                                       */
/* Parameter3:    cycle_delay specifies the number of cycles between the triggering and the associated stimulation.           */
/*                During first cycle_delay cycles there's no stimulation in the ECU; instead VX device fills its STIM FIFO.   */
/* Parameter4:    timeout in microseconds, starting right now.                                                                */
/*                Hint: the timeout may be chosen as small as zero when cycle_delay > 0                                       */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Initiate a bypass by requesting a stimulation (stim_trigger_event) without sending DAQ data,                */
/*                and after the first cycle_delay calls, also busy wait with timeout for the tool to actually complete        */
/*                the stimulation (stim_event). In the meantime, the requested data stay in the VX internal pipeline          */
/*                and are used later. This pipeline depth / initial delay has to be considered when generating the stim data. */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_Stimulate)( VX1000_UINT8 stim_trigger_event, VX1000_UINT8 stim_event,
                                              VX1000_UINT8 cycle_delay, VX1000_UINT32 timeout_us)
{
  VX1000_UINT8 retVal = 0; /* means "Stim not active" */

  if (0==cycle_delay)
  {
    /* If cycle_delay is 0, stimulation has normal bypass behaviour */
    retVal = VX1000_SUFFUN(vx1000_Bypass)(stim_trigger_event, stim_event, timeout_us);
  }
  else
  {
    if (VX1000_STIM_ACTIVE(stim_event) != 0)
    {
      if (0==(VX1000_CYCLE_DELAY_CTR(stim_event)))
      {
        /* Delay period has expired */
        /* Wait for stimulation data available in the OLDA buffer and stimulate */
#if !defined(VX1000_STIM_FORCE_V1)
        if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0)
        {
          /* We cannot distinguish the cases "EOF_stimfile reached, no more data" and    */
          /* "timeout requirement just too hard, stim data still waiting in the queue".  */
          /* In either case we do NOT try to pre-fetch further data and we always signal */
          /* "Stim (still) active, Timeout" to the caller: */
          retVal = 2;
        }
        else
        {
          VX1000_STIM_REQUEST(stim_event)     /* Request stimulation data */
          VX1000_EVENT(stim_trigger_event)    /* Trigger a stimulation */
          retVal = 1;                         /* Stim active, OK */
        }
      }
      else
      {
        VX1000_CYCLE_DELAY_CTR(stim_event)--;
        VX1000_EVENT(stim_trigger_event)      /* Trigger a stimulation */
        if (0==(VX1000_CYCLE_DELAY_CTR(stim_event)))
        {
          VX1000_STIM_REQUEST(stim_event)     /* Request stimulation data */
#else /* VX1000_STIM_FORCE_V1 */
        if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != VX1000_STIM_RET_SUCCESS)
        {
          /* We cannot distinguish the cases "EOF_stimfile reached, no more data" and    */
          /* "timeout requirement just too hard, stim data still waiting in the queue".  */
          /* In either case we do NOT try to pre-fetch further data and we always signal */
          /* "Stim (still) active, Timeout" to the caller: */
          retVal = 2;
        }
        else
        {
          VX1000_BYPASS_TRIGGER_VOID(stim_trigger_event, stim_event)    /* Trigger a stimulation */
          VX1000_STIM_REQUEST_EVENT(stim_event)     /* Request stimulation data */
          retVal = 1;                         /* Stim active, OK */
        }
      }
      else
      {
        VX1000_CYCLE_DELAY_CTR(stim_event)--;
        VX1000_BYPASS_TRIGGER_VOID(stim_trigger_event, stim_event)       /* Trigger a stimulation */
        if (0==(VX1000_CYCLE_DELAY_CTR(stim_event)))
        {
          VX1000_STIM_REQUEST_EVENT(stim_event)     /* Request stimulation data */
#endif /* VX1000_STIM_FORCE_V1 */
        }
        /* Stim not active, start-up delay still in progress */
      }
    } /* if Stim active */
    else
    {
      if (cycle_delay > 100) { cycle_delay = 100; } /* Silently ensures to not exceed the VX's maximum queue size */
      VX1000_CYCLE_DELAY_CTR(stim_event) = cycle_delay;
    } /* if Stim not active */
  } /* if cycle_delay > 0 */

  return retVal;
}
/*#endif /-* VX1000_STIM_BY_OLDA *-/ -- now the parallel pods can stimulate even without OLDA */

#endif /* VX1000_STIM */

#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
/*------------------------------------------------------------------------------- */
/* Generic Hooking */
#if defined(VX1000_HOOK_ENABLE)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_HookInit                                                                                             */
/* API name:      VX1000_HOOK_INIT (or none, has not been decided, yet whether it is called internally only)                  */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Initialize the hook control structure.                                                                      */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_HookInit)( void )
{
  VX1000_UINT8 i;

  gVX1000_HookControl.count = 0;
  gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
  gVX1000_HookControl.active_id = 0xFFFFU;
  for (i = 0; i < VX1000_HOOK_COUNT; i++)
  {
    /* Define standard behaviour copy=on, execute original code=off, DAQ=off */
    gVX1000_HookControl.table[i].id = 0xFFFFU;
#if defined(VX1000_STIM)
    gVX1000_HookControl.table[i].stim_event = 0xFFU;
#endif /* VX1000_STIM */
    gVX1000_HookControl.table[i].trigger_event = 0xFFU;
    gVX1000_HookControl.table[i].daq_event = 0xFFU;
    gVX1000_HookControl.table[i].control = VX1000_HOOK_COPY_ENABLE;
  }
  if ( ((volatile VX1000_UINT8 *)&gVX1000_HookControl.count) != &(((volatile VX1000_UINT8 *)&gVX1000_HookControl)[0x2]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_HOOK_T, count)) != 0x2) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }
  else
  {
    gVX1000_HookControl.magic = VX1000_HOOK_MAGIC;
  }
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_GenericEvent                                                                                         */
/* API name:      VX1000_GENERIC_EVENT                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    hook ID E [0,gVX1000_HookControl.count)                                                                     */
/*                Validity ensured by silent abort!                                                                           */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Trigger a generic event whose event ID is related to parameter1.                                            */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_GenericEvent)( VX1000_UINT16 hook_id )
{
  VX1000_UINT8 i;

  /* Lookup the hook id */
  if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
  {
    for (i = 0; (i < gVX1000_HookControl.count) && (gVX1000_HookControl.table[i].id != hook_id); i++)
    {
      /* just loop until we found a valid index 'i' pointing to hook_id or there are no indices left */
    }
    if (i < gVX1000_HookControl.count)
    {
      VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
    }
  }
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_EnterHook                                                                                            */
/* API name:      VX1000_HOOK_TRIGGER (expression) / VX1000_HOOK_TRIGGER_VOID (statement)                                     */
/* Return value:  flag whether to skip the original code (0 = "inactive bypass or active bypass and original code enabled",   */
/*                1="bypass active and original code disabled")                                                               */
/* Parameter1:    hook ID E [0,gVX1000_HookControl.count)                                                                     */
/*                Validity ensured by silent abort!                                                                           */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Trigger a generic bypass whose event IDs are related to parameter1.                                         */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_EnterHook)( VX1000_UINT16 hook_id )
{
  VX1000_UINT8 i, retVal = 0; /* means "enable the bypassed code" */

  /* Initialization check */
  if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
  {
    for (i = 0; (i < gVX1000_HookControl.count) && (gVX1000_HookControl.table[i].id != hook_id); i++)
    {
      /* just loop until we found a valid index 'i' pointing to hook_id or there are no indices left */
    }
    if (i < gVX1000_HookControl.count)
    {
#if defined(VX1000_STIM)
      /* i is a valid index -> found a bypass entry */
      if (VX1000_SUFFUN(vx1000_StimActive)(gVX1000_HookControl.table[i].stim_event) != 0)
      {
        /* This bypass is enabled by the tool, but check for nested bypasses first */
        if (gVX1000_HookControl.active_index >= gVX1000_HookControl.count)
        {
          /* Trigger this bypass */
          gVX1000_HookControl.active_index = i;
          gVX1000_HookControl.active_id = hook_id;
          VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
          VX1000_SUFFUN(vx1000_StimRequest)(gVX1000_HookControl.table[i].stim_event);
          if (0==(gVX1000_HookControl.table[i].control & (VX1000_HOOK_CODE_ALWAYS)))
          {
            retVal = 1; /* Bypass active normally --> don't execute the bypassed code */
          }
          /* else: Bypass active but original code enabled --> enable the bypassed code */
        }
        /* else: Nesting detected, don't execute this bypass --> enable the bypassed code */
      }
      else
#endif /* VX1000_STIM */
      {
        gVX1000_HookControl.active_index = i;
        gVX1000_HookControl.active_id = hook_id;
        if ((gVX1000_HookControl.table[i].control & (VX1000_HOOK_TRIGGER_EVENT_ENABLE)) != 0)
        {
          VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
        }
      }
      /* Bypass inactive --> enable the bypassed code */
    }
    /* else: Id not found, Bypass inactive --> enable the bypassed code */
  }
  /* else: Generic bypassing not initialized yet --> enable the bypassed code */
  return retVal;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_LeaveHook                                                                                            */
/* API name:      VX1000_HOOK_WAIT (expression) / VX1000_HOOK_WAIT_VOID (statement)                                           */
/* Return value:  status:                                                                                                     */
/*                0: bypass inactive                                                                                          */
/*                1: stimulation done, no timeout, OK                                                                         */
/*                2: stimulation not done, timeout                                                                            */
/*                3: stimulation not done, timeout, execute original code                                                     */
/* Parameter1:    hook ID E [0,gVX1000_HookControl.count)                                                                     */
/*                Validity ensured by silent abort!                                                                           */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Stimulate with timeout for a generic bypass whose event IDs are related to parameter1.                      */
/*                Optionally trigger an additional DAQ event.                                                                 */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_LeaveHook)( VX1000_UINT16 hook_id, VX1000_UINT32 timeout)
{
  VX1000_UINT16 idx, ident;
  VX1000_UINT8 retVal = 0; /* this means "bypass inactive" */

  if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
  {
    /* Generic bypassing is initialised */
    idx = gVX1000_HookControl.active_index;
    ident = gVX1000_HookControl.active_id;
    if ((idx < gVX1000_HookControl.count) && (ident == hook_id))
    {
      /* The specified generic bypass is being executed right now */
      gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
      gVX1000_HookControl.active_id = 0xFFFFU;
#if defined(VX1000_STIM)
      if (VX1000_SUFFUN(vx1000_StimActive)(gVX1000_HookControl.table[idx].stim_event) != 0)
      {
        if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_DAQ_EVENT_ENABLE)) != 0)
        {
          VX1000_EVENT(gVX1000_HookControl.table[idx].daq_event)    /* Trigger an additional DAQ event */
        }
        /* Wait */
        if (VX1000_SUFFUN(vx1000_StimWait)(gVX1000_HookControl.table[idx].stim_event
        ,(VX1000_UINT8)(gVX1000_HookControl.table[idx].control & (VX1000_UINT8)(VX1000_HOOK_COPY_ENABLE)), timeout) != 0)
        {
          if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_CODE_TIMEOUT)) != 0)
          {
            retVal = 3;  /* Timeout, execute original code */
          }
          else
          {
            retVal = 2; /* Timeout, no action */
          }
        }
        else
        {
          retVal = 1;   /* Bypass active, done, OK */
        }
      }
      else
#endif /* VX1000_STIM */
      {
        if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_DAQ_EVENT_ENABLE)) != 0)
        {
          VX1000_EVENT(gVX1000_HookControl.table[idx].daq_event)    /* Trigger an additional DAQ event */
        }
      } /* do not remove this pair of braces - it's required for MISRA */
      /* Bypass not startet by tool, Bypass inactive */
    }
    /* else: Id not found, Bypass inactive */
  }
  /* else: Generic bypassing not active at all */
  return retVal;
}

#endif /* VX1000_HOOK_ENABLE */
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */


#if (defined(VX1000_OVERLAY) && (!defined(VX1000_COMPILED_FOR_SLAVECORES)))
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayInit                                                                                          */
/* API name:      VX1000_OVERLAY_INIT                                                                                         */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Initialises the global variables that are used by the overlay functions.                                    */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_OverlayInit)(void)
{
  gVX1000.Ovl.presenceCounter = 0;
  gVX1000.Ovl.ovlConfigValue  = 0;
  gVX1000.Ovl.ovlConfigMask   = 0;
  gVX1000.Ovl.calFeaturesEnable = 0
#if defined(VX1000_OVLENBL_KEEP_AWAKE)
                                | (VX1000_OVLFEAT_KEEP_AWAKE)
#endif /* VX1000_OVLENBL_KEEP_AWAKE */
#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
                                | (VX1000_OVLFEAT_SYNC_PAGESWITCH)
#endif /* VX1000_OVLENBL_SYNC_PAGESWITCH */
#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
                                | (VX1000_OVLFEAT_PERSISTENT_EMEM)
#endif /* VX1000_OVLENBL_PERSISTENT_EMEM */
#if defined(VX1000_OVLENBL_RST_ON_CALWAKEUP)
                                | (VX1000_OVLFEAT_RST_ON_CALWAKEUP)
#endif /* VX1000_OVLENBL_RST_ON_CALWAKEUP */
#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)
                                | (VX1000_OVLFEAT_USE_VX_EPK_TRANS)
#endif /* VX1000_OVLENBL_USE_VX_EPK_TRANS */
#if defined(VX1000_OVLENBL_VALIDATE_PAGESW)
                                | (VX1000_OVLFEAT_VALIDATE_PAGESW)
#endif /* VX1000_OVLENBL_VALIDATE_PAGESW */
#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)
                                | (VX1000_OVLFEAT_CORE_SYNC_PAGESW)
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW */
#if defined(VX1000_OVERLAY_VX_CONFIGURABLE)
                                | (VX1000_OVLFEAT_VX)
#elif defined(VX1000_OVERLAY_USERMANAGED)
                                | (VX1000_OVLFEAT_USER)
#else /* any of the built-in methods of the driver*/
                                | (VX1000_OVLFEAT_DRIVER)
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE && !VX1000_OVERLAY_USERMANAGED */
#if (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
                                | (VX1000_OVLFEAT_ECU_REGS_VIA_MX)
#endif /* VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX & VX1000_MAILBOX & VX1000_MAILBOX_OVERLAY_CONTROL */
#if defined(VX1000_OVLENBL_RST_ON_SNCPAGESW)
                                | (VX1000_OVLFEAT_RST_ON_SNCPAGESW)
#endif /* VX1000_OVLENBL_RST_ON_SNCPAGESW */
                                ;

  gVX1000.Ovl.persistentECUEmemHeaderPtr = (VX1000_EMEM_HDR_T*)VX1000_EMEM_HDR_PTR;
#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW) || defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
  gVX1000.Ovl.ovlBusMasterMask = VX1000_OVL_CAL_BUS_MASTER;
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW */
  gVX1000.Ovl.ecuLastPresenceCounter = 0;
#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)
  gVX1000.Ovl.ovlEPKLength = (VX1000_UINT16)(VX1000_OVL_EPK_LENGTH);
  gVX1000.Ovl.ovlReferencePageDataEPKAddress = (VX1000_UINT32)(VX1000_OVL_EPK_REFPAGE_ADDR);
  gVX1000.Ovl.ovlWorkingPageDataEPKAddress = 0xFFFFFFFFUL;
#else /* !VX1000_OVLENBL_USE_VX_EPK_TRANS */
  gVX1000.Ovl.ovlEPKLength = 0U;
#if (defined(VX1000_OVERLAY_ADDR) && defined(VX1000_OVERLAY_SIZE)) && defined(VX1000_CALRAM_ADDR)
  for (gVX1000.Ovl.ovlReferencePageDataEPKAddress = VX1000_OVERLAY_SIZE; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic below */
       gVX1000.Ovl.ovlReferencePageDataEPKAddress > 0x0800UL;
       gVX1000.Ovl.ovlReferencePageDataEPKAddress >>= 1)
  {
    gVX1000.Ovl.ovlEPKLength += 0x1000U;
  }
  gVX1000.Ovl.ovlEPKLength |= (VX1000_UINT16)gVX1000.Ovl.ovlReferencePageDataEPKAddress;
  gVX1000.Ovl.ovlReferencePageDataEPKAddress = (VX1000_UINT32)(VX1000_OVERLAY_ADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
  gVX1000.Ovl.ovlWorkingPageDataEPKAddress = (VX1000_UINT32)(VX1000_CALRAM_PHYSADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable holds a 32bit flat pointer while the application may be compiled in near or segmented model where the bits have another meaning */
#else /* !VX1000_OVERLAY_ADDR || !VX1000_OVERLAY_SIZE || !VX1000_CALRAM_ADDR */
  gVX1000.Ovl.ovlReferencePageDataEPKAddress = 0UL;
  gVX1000.Ovl.ovlWorkingPageDataEPKAddress = 0UL;
#endif /* !VX1000_OVERLAY_ADDR || !VX1000_OVERLAY_SIZE || !VX1000_CALRAM_ADDR */
#endif /* !VX1000_OVLENBL_USE_VX_EPK_TRANS */
  gVX1000.Ovl.syncCalSwitchDataPtr = ((VX1000_UINT32)&gVX1000.Ovl.syncCalData);  /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */

  gVX1000.Ovl.version = VX1000_OVL_VERSION;

  if (gVX1000.Ovl.persistentECUEmemHeaderPtr != 0)
  {
    vx1000_EmemHdrInit();
  }

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
  gVX1000_XCP_CalPage = VX1000_CALPAGE_FLASH;
  gVX1000_ECU_CalPage = VX1000_CALPAGE_FLASH;
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */

#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
  gVX1000.Ovl.ovlConfigRegsPtr = ((VX1000_UINT32)&gVX1000.Ovl.ovlConfigRegs);
  if (VX1000_SUFFUN(vx1000_OverlayReadEcuDescr)() != 0)
  {
    gVX1000.Ovl.ovlConfigRegsPtr = 0;  /* the feature seems not to be supported, yet. The error is already logged by the callee */
  }
#else /* !VX1000_OVERLAY || !VX1000_OVERLAY_VX_CONFIGURABLE || !VX1000_OVLENBL_REGWRITE_VIA_MX || !VX1000_MAILBOX || !VX1000_MAILBOX_OVERLAY_CONTROL */
  gVX1000.Ovl.ovlConfigRegsPtr = 0;    /* the feature is disabled */
#endif /* !VX1000_OVERLAY || !VX1000_OVERLAY_VX_CONFIGURABLE || !VX1000_OVLENBL_REGWRITE_VIA_MX || !VX1000_MAILBOX || !VX1000_MAILBOX_OVERLAY_CONTROL */

  gVX1000.ToolDetectState &= ~(VX1000_TDS_WORKING_PAGE);
  if ( ((volatile VX1000_UINT8 *)&gVX1000.Ovl.ovlConfigValue) != &(((volatile VX1000_UINT8 *)&gVX1000.Ovl)[0x8]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_OVL_T, ovlConfigValue)) != 0x8) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }
  gVX1000.Ovl.magicId = VX1000_OVL_MAGIC;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_EmemHdrInit                                                                                          */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Reset the EmemHdr related VX1000 structure data                                                             */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_EmemHdrInit)(void)
{
  VX1000_EMEM_HDR_T *hdr = (VX1000_EMEM_HDR_T*)gVX1000.Ovl.persistentECUEmemHeaderPtr; /* TODO MISRA-C:2004 Rule 11.3 - mad typecast */
  volatile VX1000_UINT32 * const addr = (volatile VX1000_UINT32*)hdr;  /* PRQA S 0310 */ /* willingly violating MISRA Rule 11.4 because the physical memory must be initialised with a larger data type then the the access to the actual structure members */
  /* dummy access the memory of the magic ID, the version and reserved fields by 32bit-writes to initialise the ECC hardware: */
  addr[0] = addr[1] = 0UL;

  /* now the hardware will accept smaller-then-32bit accesses to the same memory. Do the actual initialisation */
  hdr->version = VX1000_EMEM_HDR_VERSION;
  hdr->reserved = 0; /* initialize the reserved field for CRC-reasons */
  hdr->magicId = VX1000_EMEM_HDR_MAGIC;
}

#endif /* VX1000_OVERLAY & !VX1000_COMPILED_FOR_SLAVECORES */


#if defined(VX1000_RES_MGMT) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_ResMgmtInit                                                                                          */
/* API name:      VX1000_RES_MGMT_INIT                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Reset the Resource Management related VX1000 structure data                                                 */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_ResMgmtInit)(void)
{
  gVX1000.ResMgmt.resMgmtEnable = 0UL; /* PRQA S 3198 */ /* this global volatile variable is accessed by debug tool in the background */

  gVX1000.ResMgmt.version = VX1000_RES_MGMT_VERSION;
  gVX1000.ResMgmt.ovlConfigItemStart  = (VX1000_UINT8)(VX1000_RES_MGMT_CFG_ITEM_START);
  gVX1000.ResMgmt.ovlConfigItemLength = (VX1000_UINT8)(VX1000_RES_MGMT_CFG_ITEM_LEN);

  gVX1000.ResMgmt.ovlRamStart   = (VX1000_UINT32)(VX1000_RES_MGMT_RAM_START);
  gVX1000.ResMgmt.ovlRamSize    = (VX1000_UINT32)(VX1000_RES_MGMT_RAM_SIZE);

  gVX1000.ResMgmt.resMgmtEnable = (VX1000_RES_MGMT_ENBLVAL_CFG_ITEM)
                                | (VX1000_RES_MGMT_ENBLVAL_OVL_RAM);
  if ( ((volatile VX1000_UINT8 *)&gVX1000.ResMgmt.resMgmtEnable) != &(((volatile VX1000_UINT8 *)&gVX1000.ResMgmt)[0x8]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_RES_MGMT_T, resMgmtEnable)) != 0x8) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }
  gVX1000.ResMgmt.magicId = VX1000_RES_MGMT_MAGIC;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_DisableAccess                                                                                        */
/* API name:      VX1000_DISABLE_ACCESS (expression) / VX1000_DISABLE_ACCESS_VOID (statement)                                 */
/* Return value:  0 Disabled access successfully                                                                              */
/*                1 VX1000 already detected. VX1000 access not disabled                                                       */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Disables the access of the VX1000 to the ECU resources. The VX1000 will prevent the MC from accessing       */
/*                the microcontroller when the VX1000 access is disabled                                                      */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_DisableAccess)( void )
{
  VX1000_UINT8 retVal = 0;
  if (VX1000_DETECTED())
  {
    retVal = 1;
  }
  else
  {
    VX1000_INVALIDATE_EMEM()
    gVX1000.ToolDetectState |= VX1000_TDS_VX_ACCESS_DISABLED;
  }
  return retVal;
}

#endif /* VX1000_RES_MGMT & !VX1000_COMPILED_FOR_SLAVECORES */


/*------------------------------------------------------------------------------- */
/* Calibration (_classic_ version with fixed settings from VX1000_cfg.h)          */

#if defined(VX1000_OVERLAY) && (!defined(VX1000_OVERLAY_VX_CONFIGURABLE))

#if defined(VX1000_INIT_CAL_PAGE_INTERNAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayHwInit                                                                                        */
/* API name:      VX1000_OVERLAY_HW_INIT (internal) - may be overloaded by user via VX1000_INIT_CAL_PAGE                      */
/* Return value:  none                                                                                                        */
/* Parameter1:    bit0: allow update of the status variables;                                                                 */
/*                bit1: allow RAM initialisation;                                                                             */
/*                bit2: allow reconfiguration of the remap registers                                                          */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:                                                                                                               */
/* Devel state:   Idea                                                                                                        */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_OverlayHwInit)(void)
{
  const VX1000_UINT32 overlaySize = (VX1000_UINT32)(VX1000_OVERLAY_SIZE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  const VX1000_UINT32 overlayAddr = (VX1000_UINT32)(VX1000_OVERLAY_ADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  const VX1000_UINT32 overlayPhys = (VX1000_UINT32)(VX1000_OVERLAY_PHYSADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  const VX1000_UINT32 calRamAddr  = (VX1000_UINT32)(VX1000_CALRAM_ADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  /* ensure that the mapping is not already/still active (even if not needed on all derivatives) */

  /* Initialize CALRAM: copy original flash content to RAM, then map RAM over flash (with cache inhibit etc.) */
  if ((!VX1000_DETECTED()) || ((gVX1000.ToolCtrlState & (VX1000_UINT32)(VX1000_TCS_SKIP_WP_INIT)) == 0))
  {
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_OVLENBL_HW_INIT_PER_CORE))
    if (VX1000_RUNNING_ON_MAINCORE() != 0)
#endif /* VX1000_RUNNING_ON_MAINCORE && !VX1000_OVLENBL_HW_INIT_PER_CORE */
    {
#if defined(VX1000_OVLENBL_HW_INIT_PER_CORE) || (!defined(VX1000_COMPILED_FOR_SLAVECORES))
      (void)VX1000_SUFFUN(vx1000_MapCalRam)(overlaySize, overlayAddr, overlayAddr, overlayPhys); /* ensure that the mapping is not already/still active (even if not needed on all derivatives) */
#endif /* VX1000_OVLENBL_HW_INIT_PER_CORE || !VX1000_COMPILED_FOR_SLAVECORES */
    }
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_OVLENBL_MEMCPY_PER_CORE)) /* hint: considering VX1000_OVLENBL_MEMCPY_PER_CORE actually not needed up to now (self-addresses can't be measured anyway) */
    if (VX1000_RUNNING_ON_MAINCORE() != 0)
#endif /* VX1000_RUNNING_ON_MAINCORE && !VX1000_OVLENBL_MEMCPY_PER_CORE */
    {
#if defined(VX1000_OVLENBL_MEMCPY_PER_CORE) || (!defined(VX1000_COMPILED_FOR_SLAVECORES))
#if defined(VX1000_MEMCPY) /* it's impossible to find type-casts that work with all compilers without warnings */
      VX1000_MEMCPY((void*)(calRamAddr),(void*)overlayAddr, overlaySize); /* FLASH->RAM */ /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
#else /* !VX1000_MEMCPY */
      if ((((overlaySize | overlayAddr) | calRamAddr) & 0x3UL) != 0UL)
      {
        VX1000_UINT32 cnt;
        volatile const VX1000_CHAR *pSrc = (volatile const VX1000_CHAR *)(overlayAddr); /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
        volatile VX1000_CHAR *pDst = (volatile VX1000_CHAR *)(calRamAddr); /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
        for (cnt = 0; cnt < overlaySize; cnt++)
        {
          pDst[cnt] = pSrc[cnt];
        }
      }
      else
      {
        VX1000_UINT32 cnt;
        volatile const VX1000_UINT32 *pSrc = (volatile const VX1000_UINT32 *)(overlayAddr); /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
        volatile VX1000_UINT32 *pDst = (volatile VX1000_UINT32 *)(calRamAddr); /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
        for (cnt = 0; cnt < (overlaySize >> 2U); cnt++)
        {
          pDst[cnt] = pSrc[cnt];
        }
      }
#endif /* !VX1000_MEMCPY */
#endif /* VX1000_OVLENBL_MEMCPY_PER_CORE || !VX1000_COMPILED_FOR_SLAVECORES */
    }
#if defined(VX1000_RUNNING_ON_MAINCORE) && (!defined(VX1000_OVLENBL_HW_INIT_PER_CORE))
    if (VX1000_RUNNING_ON_MAINCORE() != 0)
#endif /* VX1000_RUNNING_ON_MAINCORE && !VX1000_OVLENBL_HW_INIT_PER_CORE */
    {
#if defined(VX1000_OVLENBL_HW_INIT_PER_CORE) || (!defined(VX1000_COMPILED_FOR_SLAVECORES))
      VX1000_WRP_SET_CAL_PAGE_VOID(0, VX1000_CALPAGE_RAM, ((VX1000_CAL_ECU) | (VX1000_CAL_XCP)), 1)
#endif /* VX1000_OVLENBL_HW_INIT_PER_CORE || !VX1000_COMPILED_FOR_SLAVECORES */
    }
  }
}
#endif /* VX1000_INIT_CAL_PAGE_INTERNAL */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MapCalRam - may be overloaded internally for the used hardware                                       */
/* API name:      none                                                                                                        */
/* Return value:  status:                                                                                                     */
/*                0: requested overlay not possible                                                                           */
/*                1: mapping complete                                                                                         */
/* Parameter1:    Overlay window size                                                                                         */
/* Parameter2:    properly aligned virtual flash access address                                                               */
/* Parameter3:    overlay memory address                                                                                      */
/*                If Parameter2 == Parameter3, the overlay is turned off completely.                                          */
/* Parameter4:    physical address of Parameter3 (optional)                                                                   */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Derivative-specific method for enabling/disabling a single overlay window using V850 OVL feature.           */
/*                Note: The driver assumes exclusive ownership of the overlay unit.                                           */
/* Devel state:   Specified                                                                                                   */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_UINT32 size, VX1000_UINT32 target, VX1000_UINT32 source1, VX1000_UINT32 source2)
{
  VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_UNIMPL)
  ++size; ++target; ++source1; ++source2; /* dummy usage to avoid compiler warnings */
  return 0; /* not implemented */
}
#endif /* VX1000_OVERLAY & !VX1000_OVERLAY_VX_CONFIGURABLE */

#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL))
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayWriteEcuDescr                                                                                 */
/* API name:      none                                                                                                        */
/* Return value:  status:                                                                                                     */
/*                0: ovl regs pointed by gVX1000.Ovl.ovlConfigRegsPtr is written to ECU                                       */
/*                1: nothing is done                                                                                          */
/* Preemption:    todo vislwn                                                                                                 */
/* Termination:   todo vislwn                                                                                                 */
/* Precondition1: todo vislwn                                                                                                 */
/* Description:   todo vislwn                                                                                                 */
/* Devel state:   Idea                                                                                                        */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayWriteEcuDescr)(void)
{
  VX1000_UINT8 retVal = 1;
  VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_UNIMPL)
  return retVal;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayReadEcuDescr                                                                                  */
/* API name:      none                                                                                                        */
/* Return value:  status:                                                                                                     */
/*                0: ovl regs in ECU is read to struct pointed to by gVX1000.Ovl.ovlConfigRegsPtr                             */
/*                1: nothing is done                                                                                          */
/* Preemption:    todo vislwn                                                                                                 */
/* Termination:   todo vislwn                                                                                                 */
/* Precondition1: todo vislwn                                                                                                 */
/* Description:   This function reads ECU overlay regs to gVX1000.Ovl.ovlConfigRegsPtr structure.                             */
/*                It is called in vx1000_OverlayInit() when corresponding defines are activated in VX1000_cfg.h               */
/* Devel state:   Idea                                                                                                        */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayReadEcuDescr)(void)
{
  VX1000_UINT8 retVal = 1;
  VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_UNIMPL)
  return retVal;
}
#endif /* VX1000_OVERLAY & VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX & VX1000_MAILBOX & VX1000_MAILBOX_OVERLAY_CONTROL */

#if defined(VX1000_OVLENBL_KEEP_AWAKE)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_IsCalWakeupActive                                                                                    */
/* API name:      VX1000_IS_CAL_WAKEUP_ACTIVE                                                                                 */
/* Return value:  status:                                                                                                     */
/*                0: The download of the overlay image has completed (so the ECU can safely fall asleep again)                */
/*                1: The cause for the wakeup is still active                                                                 */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_InitAsyncStart must have been called.                                                                */
/* Description:   Returns whether the ECU must stay awake for calibration purposes. Since the last call of this function the  */
/*                VX1000 has requested the ECU to stay awake.                                                                 */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_IsCalWakeupActive)(void)
{
  VX1000_UINT8 retVal = 0;
  if (gVX1000.Ovl.ecuLastPresenceCounter != gVX1000.Ovl.presenceCounter)
  {
    retVal = 1;
  }
  gVX1000.Ovl.ecuLastPresenceCounter = gVX1000.Ovl.presenceCounter;
  return retVal;
}
#endif /* VX1000_OVLENBL_KEEP_AWAKE */

#if defined(VX1000_OVLENBL_PERSISTENT_EMEM)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_InvalidateEmem                                                                                       */
/* API name:      VX1000_INVALIDATE_EMEM                                                                                      */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Explicitly destroy the signature of VX-allocated persistent ECU-RAM to force reinitialisation if it.        */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_InvalidateEmem)(void)
{
  if (gVX1000.MagicId == (VX1000_UINT32)(VX1000_STRUCT_MAGIC))
  {
    if (gVX1000.OvlPtr != 0UL)
    {
      if (gVX1000.Ovl.persistentECUEmemHeaderPtr != 0UL)
      {
        VX1000_EMEM_HDR_T *hdr = (VX1000_EMEM_HDR_T*)gVX1000.Ovl.persistentECUEmemHeaderPtr;
        hdr->ememInitEnd = 0UL;
        hdr->ememInitEndInvert = 0UL;
        hdr->ememInitStart = 0UL;
        hdr->ememInitStartInvert = 0UL;
      }
    }
  }
}
#endif /* VX1000_OVLENBL_PERSISTENT_EMEM */


#if defined(VX1000_OVERLAY) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)

#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlaySetConfigDone                                                                                 */
/* API name:      VX1000_OVL_SET_CONFIG_DONE (normal operation) / VX1000_OVL_SET_CONFIG_DONE_STUP (start-up stage)            */
/*                may be overloaded by user                                                                                   */
/* Return value:  none                                                                                                        */
/* Parameter1:    XCP error code in case of failed page switch, 0 in case of success                                          */
/* Parameter2:    The ID of the page that is in use now                                                                       */
/* Parameter3:    A boolean that tells the driver whether to forward the result to the tool (TRUE) or not (FALSE)             */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: A page switch has to be requested and executed.                                                             */
/* Description:   Inform the driver (and optionally also the tool) about the final reaction to a page switch request.         */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_OverlaySetConfigDone)( VX1000_UINT8 cfgResult, VX1000_UINT8 page, VX1000_UINT8 onStartup )
{
#if defined(VX1000_COMPILED_FOR_SLAVECORES)
  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,cfgResult, page,onStartup,(0),(0))) /* dummy usage of unused operands */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#else /* !VX1000_COMPILED_FOR_SLAVECORES */
  VX1000_UINT32 txLen;
  VX1000_CHAR txBuf[8];

  if (0 == cfgResult)
  {
    txLen = 1;
    txBuf[0] = (VX1000_CHAR)-1;
    gVX1000_ECU_CalPage = page;
    if (page != 0)
    {
      gVX1000.ToolDetectState |= VX1000_TDS_WORKING_PAGE;
    }
    else
    {
      gVX1000.ToolDetectState &= ~(VX1000_TDS_WORKING_PAGE);
    }
  }
  else
  {
    txLen = 2;
    txBuf[0] = (VX1000_CHAR)-2;
    txBuf[1] = (VX1000_CHAR)cfgResult;
  }
  if (0==onStartup)
  {
    (void)VX1000_SUFFUN(vx1000_MailboxWrite)(txLen, txBuf);
  }
#endif /* VX1000_COMPILED_FOR_SLAVECORES */
}

#if defined(VX1000_OVL_SET_CONFIG_INTERNAL)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlaySetConfig                                                                                     */
/* API name:      VX1000_OVL_SET_CONFIG (expression) / VX1000_OVL_SET_CONFIG_VOID (statement) - may be overloaded by user     */
/* Return value:  status:                                                                                                     */
/*                0: Nothing done                                                                                             */
/*                1: Page switch done                                                                                         */
/*                2: Value not written correctly                                                                              */
/*                3: No single-master page-switch possible                                                                    */
/*                4: Generic error                                                                                            */
/* Parameter1:    Overlay windows to be activated/deactivated                                                                 */
/* Parameter2:    Resource Mask                                                                                               */
/* Parameter3:    Overlay Page                                                                                                */
/* Parameter4:    Masters to be activated                                                                                     */
/* Parameter5:    Masters resource Mask                                                                                       */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Derivative-specific method for enabling/disabling overlays.                                                 */
/* Devel state:   Specified                                                                                                   */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlaySetConfig)( VX1000_UINT32 value, VX1000_UINT32 mask, VX1000_UINT8 page,
                                                     VX1000_UINT32 master, VX1000_UINT32 calMaster )
{

  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT32,value, mask,page,master,calMaster)) /* dummy usage of unused operands */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
  VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_UNIMPL)

  return 0; /* "not implemented, yet" */
}
#endif /* VX1000_OVL_SET_CONFIG_INTERNAL */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_overlayIsPageSwitchReq                                                                               */
/* API name:      VX1000_OVL_IS_PAGESW_REQUESTED                                                                              */
/* Return value:  status:                                                                                                     */
/*                0: None of the interesting bus masters has a pending request to switch his page                             */
/*                1: At least one of the interesting masters shall switch his page                                            */
/* Parameter1:    A bit mask for up to 32 bus masters whose status the caller is interested in                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Returns whether there's a page switch request pending on any of the bus masters selected by the bit mask.   */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_overlayIsPageSwitchReq)(VX1000_UINT32 master)
{
  VX1000_UINT8 i, retVal = 0;
  if (gVX1000.Ovl.syncCalData.pageSwitchRequested != 0)
  {
    for (i = 0; (0==retVal) && (i < 32); i++)
    {
      if ((master & (1UL<<i)) != 0)
      {
        if (gVX1000.Ovl.syncCalData.coreDone[i] == 0)
        {
          retVal = 1;
        }
      }
    }
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayChkPageSwitchCore                                                                             */
/* API name:      VX1000_OVL_CHK_PAGESW_CORE (expression) / VX1000_OVL_CHK_PAGESW_CORE_VOID (statement)                       */
/* Return value:  status:                                                                                                     */
/*                0: All interesting bus masters finished the page switch                                                     */
/*                1: At least one of the interesting masters is still using the wrong page                                    */
/* Parameter1:    A bit mask for up to 32 bus masters whose status the caller is interested in                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Checks and remembers the switching status of the bus masters that are selected by the given bit mask.       */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayChkPageSwitchCore)( VX1000_UINT32 master )
{
  VX1000_UINT32 i;
  VX1000_UINT8 someNotReady = 0;
  VX1000_UINT8 result;
  if (gVX1000.Ovl.syncCalData.pageSwitchRequested != 0)
  {
    for (i = 0; i < 32; i++)
    {
      if ((master & (1UL<<i)) != 0)
      {
        if (gVX1000.Ovl.syncCalData.coreDone[i] == 0)
        {
          someNotReady = 1;
          result = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.syncCalData.overlayValue, gVX1000.Ovl.syncCalData.overlayMask
                                        , gVX1000.Ovl.syncCalData.targetPage, master, gVX1000.Ovl.ovlBusMasterMask);
          if (result == 0)
          {
            /* 0 means no error. returning 1 to signal done*/
            gVX1000.Ovl.syncCalData.coreDone[i] = 1;
          }
          else if (result == 1)
          {
            /* 1 is not a valid return value. Use Generic error instead */
            gVX1000.Ovl.syncCalData.coreDone[i] = 2;
          }
          else
          {
            gVX1000.Ovl.syncCalData.coreDone[i] = result;
          }
        }
      }
    }
  }
  return someNotReady;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OverlayChkPageSwitchDone                                                                             */
/* API name:      VX1000_OVL_CHK_PAGESW_DONE (expression) / VX1000_OVL_CHK_PAGESW_DONE_VOID (statement)                       */
/* Return value:  0: no page switch in progress                                                                               */
/*                1: switch in progress by some cores                                                                         */
/*                2: some cores reported a page switch error                                                                  */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Checks and remembers the switching status of all bus masters for which a page switch had been requested.    */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT8 VX1000_SUFFUN(vx1000_OverlayChkPageSwitchDone)( void )
{
  VX1000_UINT8 i;
  VX1000_UINT8 retVal = 0;
  VX1000_UINT8 someNotReady = 0;
  VX1000_UINT8 someHasErrors = 0;
  VX1000_UINT8 firstError = 0;
  if (gVX1000.Ovl.syncCalData.pageSwitchRequested != 0)
  {
    for (i = 0; i < 32; i++)
    {
      if ((gVX1000.Ovl.syncCalData.busMasterRequested & (1UL<<i)) != 0)
      {
        if (gVX1000.Ovl.syncCalData.coreDone[i] == 0)
        {
          someNotReady = 1;
        }
        else if (gVX1000.Ovl.syncCalData.coreDone[i] == 1)
        {
          /* Switch was executed correctly */
        }
        else
        {
          firstError = gVX1000.Ovl.syncCalData.coreDone[i];
          someHasErrors = 1;
        }
      }
    }
    if (someNotReady == 0)
    {
      retVal = 1;
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 0;
      VX1000_OVL_SET_CONFIG_DONE(firstError, gVX1000.Ovl.syncCalData.targetPage)
    }
    if (someHasErrors != 0)
    {
      retVal = 2;
    }
  }
  return retVal;
}

#endif /* VX1000_OVLENBL_SYNC_PAGESWITCH */

#endif /* VX1000_OVERLAY & VX1000_MAILBOX_OVERLAY_CONTROL */

#if defined(VX1000_OVERLAY) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)

#if defined(VX1000_GET_CAL_PAGE_INTERNAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_GetCalPage                                                                                           */
/* API name:      VX1000_GET_CAL_PAGE (internal) - may be overloaded by user                                                  */
/* Return value:  0: reference page / 1: working page                                                                         */
/* Parameter1:    overlay segment number E {0}                                                                                */
/* Parameter2:    Select between VX1000_CAL_ECU and VX1000_CAL_XCP                                                            */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Finds out whether the ECU or the XCP driver is currently using the working page or the reference page.      */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_GetCalPage)( VX1000_UINT8 segment, VX1000_UINT8 mode )
{
  VX1000_UINT8 retVal = gVX1000_ECU_CalPage;

  if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == (VX1000_CAL_ECU))
  {
    retVal = gVX1000_ECU_CalPage;
  }
  else if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == (VX1000_CAL_XCP))
  {
    retVal = gVX1000_XCP_CalPage;
  }
  else /* just here for MISRA */
  {
    VX1000_DUMMYREAD(segment) /* just to avoid compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
  }
  return retVal;
}
#endif /* VX1000_GET_CAL_PAGE_INTERNAL */



#if defined(VX1000_SET_CAL_PAGE_EXTERNAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_SetCalPage                                                                                           */
/* API name:      VX1000_WRP_SET_CAL_PAGE, VX1000_WRP_SET_CAL_PAGE_VOID (internal wrapper for user's VX1000_SET_CAL_PAGE)     */
/* Return value:  0: OK; !0: ERROR                                                                                            */
/* Parameter1:    overlay segment number E {0}                                                                                */
/* Parameter2:    Select between reference page and working page                                                              */
/* Parameter3:    Select between VX1000_CAL_ECU and VX1000_CAL_XCP                                                            */
/* Parameter4:    0: called by user action; 1: called internally by VX1000_DETECT_VX_ASYNC_END                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Call the user's implementation to physically switch the page, then update the driver's status accordingly.  */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_SetCalPage)( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode, VX1000_UINT8 onStartup )
{
  VX1000_UINT8 retVal = VX1000_SET_CAL_PAGE(segment, page, mode, onStartup);

  if (retVal != 0)
  {
    /* the user callback returned an error, so assume that the page state was not changed at all. */
    VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_USER_FAILED)
  }
  else if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == ((VX1000_CAL_ECU) | (VX1000_CAL_XCP)))
  {
    if (page != gVX1000_ECU_CalPage)
    {
      if (page == VX1000_CALPAGE_RAM)
      {
        gVX1000.ToolDetectState |= VX1000_TDS_WORKING_PAGE;
      }
      else
      {
        gVX1000.ToolDetectState &= (~VX1000_TDS_WORKING_PAGE);
      }
      gVX1000_XCP_CalPage = page;
      gVX1000_ECU_CalPage = page;
    }
  }
  else if ((mode & (VX1000_CAL_ECU)) != 0)
  {
    if (page != gVX1000_ECU_CalPage)
    {
      if (page == VX1000_CALPAGE_RAM)
      {
        gVX1000.ToolDetectState |= VX1000_TDS_WORKING_PAGE;
      }
      else
      {
        gVX1000.ToolDetectState &= (~VX1000_TDS_WORKING_PAGE);
      }
      gVX1000_ECU_CalPage = page;
    }
  }
  else if ((mode & (VX1000_CAL_XCP)) != 0)
  {
    gVX1000_XCP_CalPage = page;
  }
  else /* the empty else case is here only for MISRA */
  {
    VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,onStartup, segment,0,0,0)) /* just to avoid compiler warnings (VX1000_SET_CAL_PAGE() is a user macro that typically does not use the onStartup parameter) */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
  }

  return retVal;
}
#endif /* VX1000_SET_CAL_PAGE_EXTERNAL */

#if defined(VX1000_SET_CAL_PAGE_INTERNAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_SetCalPage                                                                                           */
/* API name:      VX1000_WRP_SET_CAL_PAGE, VX1000_WRP_SET_CAL_PAGE_VOID (complete internal version, may be overloaded by user)*/
/* Return value:  0: OK; !0: ERROR                                                                                            */
/* Parameter1:    overlay segment number E {0}                                                                                */
/* Parameter2:    Select between reference page and working page                                                              */
/* Parameter3:    Select between VX1000_CAL_ECU and VX1000_CAL_XCP                                                            */
/* Parameter4:    0: called by user action; 1: called internally by VX1000_DETECT_VX_ASYNC_END()                              */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   perform a page switch to the desired page                                                                   */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_SetCalPage)( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode, VX1000_UINT8 onStartup )
{
  VX1000_UINT8 retVal = 0;
#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)
  VX1000_UINT8 i;
#endif /* VX1000_OVLENBL_CORE_SYNC_PAGESW */
  if (segment != 0)
  {
    VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_TOO_MANY)
    retVal = VX1000_CRC_OUT_OF_RANGE; /* Only one segment supported */
  }
  else if (page > 1)
  {
    VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_INVALID_PAGE)
    retVal = VX1000_CRC_PAGE_NOT_VALID;
  }
#if defined(VX1000_OVERLAY_VX_CONFIGURABLE)
  else if ((mode & (VX1000_CAL_ECU)) != 0)
  {
    /* Hint: switching the VX1000_CAL_XCP is not relevant in this mode (it is handled by the VX). */

#if defined(VX1000_OVLENBL_VALIDATE_PAGESW)
    if (page != 0)
    {
#if defined(VX1000_OVLENBL_USE_VX_EPK_TRANS)
      retVal = (VX1000_UINT8)(VX1000_SYNCAL_VALIDATE_WP_CB(gVX1000.Ovl.ovlWorkingPageDataEPKAddress));
#else /* !VX1000_OVLENBL_USE_VX_EPK_TRANS */
      retVal = (VX1000_UINT8)(VX1000_SYNCAL_USRVALIDATE_WP_CB(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, gVX1000.Ovl.ovlBusMasterMask));
#endif /* !VX1000_OVLENBL_USE_VX_EPK_TRANS */
    }
    if (retVal != 0)
    {
      ; /* do nothing any more */
    }
    else
#endif /* VX1000_OVLENBL_VALIDATE_PAGESW */

#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)
    if (0==onStartup)
    {
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 0;
      gVX1000.Ovl.syncCalData.overlayValue = gVX1000.Ovl.ovlConfigValue;
      gVX1000.Ovl.syncCalData.overlayMask = gVX1000.Ovl.ovlConfigMask;
      gVX1000.Ovl.syncCalData.targetPage = page;
      gVX1000.Ovl.syncCalData.busMasterRequested = gVX1000.Ovl.ovlBusMasterMask;
      for (i = 0; i < 32; i++)
      {
        gVX1000.Ovl.syncCalData.coreDone[i] = 0;
      }
      VX1000_DUMMYREAD(gVX1000.Ovl.syncCalData.pageSwitchRequested) /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 1;
      /* The actual switch is done asynchronously */
      retVal = VX1000_CRC_CMD_BUSY;
    }
    else
    {
      retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
      VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page) /* the STUP version suppresses generation of a MX response */
    }
#else /* !VX1000_OVLENBL_CORE_SYNC_PAGESW */
    {
#if defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
      retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
      VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page) /* the STUP version suppresses generation of a MX response */
#else /* !VX1000_OVLENBL_SYNC_PAGESWITCH */
      retVal = 1;
#endif /* !VX1000_OVLENBL_SYNC_PAGESWITCH */
    }
#endif /* !VX1000_OVLENBL_CORE_SYNC_PAGESW */
  }
#else /* !VX1000_OVERLAY_VX_CONFIGURABLE */
  else if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == ((VX1000_CAL_ECU) | (VX1000_CAL_XCP)))
  { /* switch both the XCP and the ECU view */
#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)
    if (0==onStartup)
    {
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 0;
      gVX1000.Ovl.syncCalData.overlayValue = gVX1000.Ovl.ovlConfigValue;
      gVX1000.Ovl.syncCalData.overlayMask = gVX1000.Ovl.ovlConfigMask;
      gVX1000.Ovl.syncCalData.targetPage = page;
      gVX1000.Ovl.syncCalData.busMasterRequested = gVX1000.Ovl.ovlBusMasterMask;
      for (i = 0; i < 32; i++)
      {
        gVX1000.Ovl.syncCalData.coreDone[i] = 0;
      }
      VX1000_DUMMYREAD(gVX1000.Ovl.syncCalData.pageSwitchRequested) /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 1;
      /* The actual switch is done asynchronously */
      retVal = VX1000_CRC_CMD_BUSY;
    }
    else
    {
      retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
      VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page) /* the STUP version suppresses generation of a MX response */
    }
#elif defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
    retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
    VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page)  /* the STUP version suppresses generation of a MX response */
#else  /* !VX1000_OVLENBL_CORE_SYNC_PAGESW && !VX1000_OVLENBL_SYNC_PAGESWITCH */
    if (page != gVX1000_ECU_CalPage)
    { /* configuration changed */
      if (page == VX1000_CALPAGE_RAM)
      { /* RAM */
        (void)VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR, VX1000_CALRAM_ADDR, VX1000_CALRAM_PHYSADDR);
        gVX1000.ToolDetectState |= VX1000_TDS_WORKING_PAGE;
      }
      else
      { /* Flash */
        (void)VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_PHYSADDR);
        gVX1000.ToolDetectState &= (~VX1000_TDS_WORKING_PAGE);
      }
      gVX1000_ECU_CalPage = page;
    }
    gVX1000_XCP_CalPage = page;
#endif /* !VX1000_OVLENBL_CORE_SYNC_PAGESW && !VX1000_OVLENBL_SYNC_PAGESWITCH */
  }
  else if ((mode & (VX1000_CAL_ECU)) != 0)
  { /* switch only ECU view */
#if defined(VX1000_OVLENBL_CORE_SYNC_PAGESW)
    if (0==onStartup)
    {
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 0;
      gVX1000.Ovl.syncCalData.overlayValue = gVX1000.Ovl.ovlConfigValue;
      gVX1000.Ovl.syncCalData.overlayMask = gVX1000.Ovl.ovlConfigMask;
      gVX1000.Ovl.syncCalData.targetPage = page;
      gVX1000.Ovl.syncCalData.busMasterRequested = gVX1000.Ovl.ovlBusMasterMask;
      for (i = 0; i < 32; i++)
      {
        gVX1000.Ovl.syncCalData.coreDone[i] = 0;
      }
      VX1000_DUMMYREAD(gVX1000.Ovl.syncCalData.pageSwitchRequested) /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
      gVX1000.Ovl.syncCalData.pageSwitchRequested = 1;
      /* The actual switch is done asynchronously */
      retVal = VX1000_CRC_CMD_BUSY;
    }
    else
    {
      retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
      VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page) /* the STUP version suppresses generation of a MX response */
    }
#elif defined(VX1000_OVLENBL_SYNC_PAGESWITCH)
    retVal = VX1000_OVL_SET_CONFIG(gVX1000.Ovl.ovlConfigValue, gVX1000.Ovl.ovlConfigMask, page, gVX1000.Ovl.ovlBusMasterMask,  gVX1000.Ovl.ovlBusMasterMask);
    VX1000_OVL_SET_CONFIG_DONE_STUP(retVal, page)  /* the STUP version suppresses generation of a MX response */
#else  /* !VX1000_OVLENBL_CORE_SYNC_PAGESW && !VX1000_OVLENBL_SYNC_PAGESWITCH */
    if (page != gVX1000_ECU_CalPage)
    { /* configuration changed */
      if (page == VX1000_CALPAGE_RAM)
      { /* RAM */
        (void)VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR, VX1000_CALRAM_ADDR, VX1000_CALRAM_PHYSADDR);
        gVX1000.ToolDetectState |= VX1000_TDS_WORKING_PAGE;
      }
      else
      { /* Flash */
        (void)VX1000_SUFFUN(vx1000_MapCalRam)(VX1000_OVERLAY_SIZE, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_PHYSADDR);
        gVX1000.ToolDetectState &= (~VX1000_TDS_WORKING_PAGE);
      }
      gVX1000_ECU_CalPage = page;
    }
#endif /* !VX1000_OVLENBL_CORE_SYNC_PAGESW && !VX1000_OVLENBL_SYNC_PAGESWITCH */
  }
  else if ((mode & (VX1000_CAL_XCP)) != 0)
  { /* switch only XCP view */
    gVX1000_XCP_CalPage = page;
  }
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE */
  else /* the empty else case is here only for MISRA */
  {
    VX1000_DUMMYREAD(onStartup) /* just to avoid compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
  }

  return retVal;
}
#endif /* VX1000_SET_CAL_PAGE_INTERNAL */


#if defined(VX1000_COPY_CAL_PAGE_INTERNAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_CopyCalPage                                                                                          */
/* API name:      VX1000_COPY_CAL_PAGE (internal) - may be overloaded by user                                                 */
/* Return value:                                                                                                              */
/* Parameter1:                                                                                                                */
/* Parameter2:                                                                                                                */
/* Parameter3:                                                                                                                */
/* Parameter4:                                                                                                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   Copy the content of the reference page to the working page.                                                 */
/* Devel state:   Specified                                                                                                   */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_CopyCalPage)( VX1000_UINT8 srcSeg, VX1000_UINT8 srcPage, VX1000_UINT8 dstSeg, VX1000_UINT8 dstPage )
{
#if 0
  const VX1000_UINT32 overlaySize = (VX1000_UINT32)(VX1000_OVERLAY_SIZE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be of ptr-diff-type with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  const VX1000_UINT32 overlayAddr = (VX1000_UINT32)(VX1000_OVERLAY_ADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  const VX1000_UINT32 calRamAddr  = (VX1000_UINT32)(VX1000_CALRAM_ADDR); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because the define from the user may be a pointer with arbitrary qualifiers and to prevent other violations caused by pointer type conversions all over the place we have to go over a neutral integer */
  VX1000_UINT8 retVal = 0;
  /* Check parameters */
  /* Only copy from RAM to FLASH makes sense */
  if ((srcSeg | dstSeg) != 0) { retVal = VX1000_CRC_SEGMENT_NOT_VALID; /* Segments are not supported */ }
  else if (dstPage == srcPage) { retVal = VX1000_CRC_PAGE_NOT_VALID; /* Can not copy on itself */ }
  else if (0==dstPage) { retVal = VX1000_CRC_ACCESS_DENIED; /* Can not copy to FLASH page  */ }
  /* Initialize CALRAM */
  /* Initialize CALRAM, copy from FLASH to RAM */
  else
  {
    if (gVX1000_ECU_CalPage == (VX1000_CALPAGE_RAM))
    {
      /* To keep code generic, turn mapping temporarily off (even if not needed with e.g. VX1000_OVERLAY_DESCR_IDX which could use the shadow address range) */
      VX1000_WRP_SET_CAL_PAGE_VOID(0, VX1000_CALPAGE_FLASH, VX1000_CAL_ECU, /* VX1000_COPY_CAL_PAGE is called by the mailbox, not at start-up: */0)
    }
#if defined(VX1000_MEMCPY) /* it's impossible to find type casts that work with all compilers without warnings */
    VX1000_MEMCPY((void*)calRamAddr, (void*)overlayAddr, overlaySize); /* FLASH->RAM */ /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
#else /* !VX1000_MEMCPY */
    if ((((overlaySize | overlayAddr) | calRamAddr) & 0x3UL) != 0UL)
    {
      VX1000_UINT32 cnt;
      volatile const VX1000_CHAR *pSrc = (volatile const VX1000_CHAR *)overlayAddr; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
      volatile VX1000_CHAR *pDst = (volatile VX1000_CHAR *)calRamAddr; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
      for (cnt = 0; cnt < overlaySize; cnt++)
      {
        pDst[cnt] = pSrc[cnt];
      }
    }
    else
    {
      VX1000_UINT32 cnt;
      volatile const VX1000_UINT32 *pSrc = (volatile const VX1000_UINT32 *)overlayAddr; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
      volatile VX1000_UINT32 *pDst = (volatile VX1000_UINT32 *)calRamAddr; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because we have to convert the arbitrarily qualified pointers provided by the user to correctly qualified pointers or our purpose via intermediate step plain integer  */
      for (cnt = 0; cnt < (overlaySize >> 2U); cnt++)
      {
        pDst[cnt] = pSrc[cnt];
      }
    }
#endif /* !VX1000_MEMCPY */
    if (gVX1000_ECU_CalPage == (VX1000_CALPAGE_RAM))
    {
      VX1000_WRP_SET_CAL_PAGE_VOID(0, VX1000_CALPAGE_RAM, VX1000_CAL_ECU, /* VX1000_COPY_CAL_PAGE is called by the mailbox, not at start-up: */0)
    }
  }
#else /* !0 */
  /* CopyCalPage has to be done by the VX on V850/RH850 */
  VX1000_UINT8 retVal = 1 /* TODO: use an appropriate error code define! */;
  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,srcSeg, dstSeg,srcPage,dstPage,0)) /* dummy accesses to prevent compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
#endif /* !0 */
  return retVal;
}
#endif /* VX1000_COPY_CAL_PAGE_INTERNAL */


#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */


#endif /* VX1000_OVERLAY && !VX1000_COMPILED_FOR_SLAVECORES */


/*---------------------------------------------------------------------------- */
/* Mailbox */
#if defined(VX1000_MAILBOX) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))

#define VX1000_MAILBOX_FLG_CLR                0
#define VX1000_MAILBOX_FLG_SET                1

#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
static VX1000_UINT32 sFlgRdSplitPend;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
static VX1000_UINT32 sFlgWrSplitPend;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxInit                                                                                          */
/* API name:      VX1000_MAILBOX_INIT (internal)                                                                              */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox function.                                       */
/*                This function must not interrupt any vx1000 mailbox function.                                               */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_InitAsyncStart must have been called.                                                                */
/* Description:   Initialize the Master->Slave and Slave->Master mailboxes.                                                   */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_MailboxInit)(void)
{
#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
  sFlgRdSplitPend = VX1000_MAILBOX_FLG_CLR;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
  sFlgWrSplitPend = VX1000_MAILBOX_FLG_CLR;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */

  gVX1000.Mailbox.Version = 0;
  gVX1000.Mailbox.SlotSize = (VX1000_MAILBOX_SLOT_DWORDS) << 2;
  gVX1000.Mailbox.MS_ReadIdx = 0;
  gVX1000.Mailbox.MS_WriteIdx = 0;
  gVX1000.Mailbox.SM_ReadIdx = 0;
  gVX1000.Mailbox.SM_WriteIdx = 0;
  gVX1000.Mailbox.RstReq = 0;
  gVX1000.Mailbox.RstAck = 0;
  gVX1000.Mailbox.MS_Slots = VX1000_MAILBOX_SLOTS;
  gVX1000.Mailbox.SM_Slots = VX1000_MAILBOX_SLOTS;
  gVX1000.Mailbox.MS_Ptr = (VX1000_UINT32)gVX1000.Mailbox.MSData; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
  gVX1000.Mailbox.SM_Ptr = (VX1000_UINT32)gVX1000.Mailbox.SMData; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
  if ( ((volatile VX1000_UINT8 *)&gVX1000.Mailbox.MS_Ptr) != &(((volatile VX1000_UINT8 *)&gVX1000.Mailbox)[0xC]) ) /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalid linkage. Standard ((offsetof(VX1000_MAILBOX_T, MS_Ptr)) != 0xC) throws even more warnings */
  {
    gVX1000.ToolDetectState |= VX1000_TDS_ERROR;
    VX1000_ERRLOGGER(VX1000_ERRLOG_STRUCTS_PADDED)
  }
  gVX1000.Mailbox.MagicId = (VX1000_UINT32)VX1000_MAILBOX_MAGIC;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxWrite                                                                                         */
/* API name:      VX1000_MAILBOX_WRITE (expression) / VX1000_MAILBOX_WRITE_VOID (statement)                                   */
/* Return value:  Error code (0==OK)                                                                                          */
/* Parameter1:    len: message size in bytes.                                                                                 */
/* Parameter2:    pBuf: pointer to message data input.                                                                        */
/*                The caller is responsible that the pointer is valid and that the source memory is accessible.               */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Write len bytes from pBuf to the Slave->Master mailbox and notify the master.                               */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWrite)(VX1000_UINT32 len, /**/const/**/ VX1000_CHAR* pBuf)
{
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (0U==(VX1000_MAILBOX_FREE_WR_SLOTS))
  {
    retVal = VX1000_MAILBOX_ERR_FULL;
  }
  else if (0==pBuf)
  {
    retVal = VX1000_MAILBOX_ERR_NULL;
  }
  else if (len > ((VX1000_MAILBOX_SLOT_DWORDS) << 2))
  {
    retVal = VX1000_MAILBOX_ERR_SIZE;
  }
  else
  {
#if defined(VX1000_MEMCPY) /* it's impossible to find typecasts that work with all compilers without warnings */
    VX1000_MEMCPY((void*)((VX1000_UINT32)((volatile VX1000_UINT32*)(&gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1]))),(void*)(VX1000_UINT32)pBuf, len); /* PRQA S 0311 */ /*PRQA S 0303 */ /*PRQA S 0306 */ /* compiler warnings about differing prototype of this library function and potential mismatch of type qualifiers force violation of MISRA Rules 11.3 and 11.5 */
#else /* !VX1000_MEMCPY */
    VX1000_UINT32 cnt;
    volatile VX1000_CHAR *pDst = (volatile VX1000_CHAR *)&(gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1]);
    for (cnt = 0; cnt < len; cnt++)
    {
      pDst[cnt] = pBuf[cnt];
    }
#endif /* !VX1000_MEMCPY */
    gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][0] = len;
    gVX1000.Mailbox.SM_WriteIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.SM_WriteIdx);
    VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) /* note: EM00034754 did not mention to remove THIS one */ /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
  }
  return retVal;
}


#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxWriteSplit                                                                                    */
/* API name:      VX1000_MAILBOX_WRITESPLIT (expression) / VX1000_MAILBOX_WRITESPLIT_VOID (statement)                         */
/* Return value:  Error code (0==OK)                                                                                          */
/*                Additional data returned via pointer                                                                        */
/* Parameter1:    ppBuf (IN): pointer to a pointer variable.                                                                  */
/*                ppBuf (*OUT): pointer to the data field of the next free Slave->Master mailbox.                             */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Just find out the location of the next unused message buffer and return the info to the caller.             */
/*                Note: the mailbox state is not changed nor is the master notified (vx1000_MailboxWriteDone will do this).   */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteSplit)(VX1000_UINT32 **ppBuf)
{
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (0U==(VX1000_MAILBOX_FREE_WR_SLOTS))
  {
    retVal = VX1000_MAILBOX_ERR_FULL;
  }
  else if (0==ppBuf)
  {
    retVal = VX1000_MAILBOX_ERR_NULL;
  }
  else if (sFlgWrSplitPend != 0)
  {
    retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
  }
  else
  {
    sFlgWrSplitPend = VX1000_MAILBOX_FLG_SET;
    *ppBuf = (VX1000_UINT32 *)(VX1000_UINT32)&gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1]; /* PRQA S 0306 */ /* possible compiler warnings about loosing qualifiers force violating MISRA Rule 11.3 here by explicit dummy cast chain */
  }
  return retVal;
}


/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxWriteDone                                                                                     */
/* API name:      VX1000_MAILBOX_WRITEDONE (expression) / VX1000_MAILBOX_WRITEDONE_VOID (statement)                           */
/* Return value:  error code (0==OK)                                                                                          */
/* Parameter1:    len: the size of the entire message in bytes.                                                               */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxWriteSplit() must have been called successfully.                                              */
/* Description:   Finish a Slave->Master mailbox transfer that has been started with vx1000_MailboxWriteSplit().              */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteDone)(VX1000_UINT32 len)
{
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (len > ((VX1000_MAILBOX_SLOT_DWORDS) << 2))
  {
    retVal = VX1000_MAILBOX_ERR_SIZE;
  }
  else if (0==sFlgWrSplitPend)
  {
    retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
  }
  else
  {
    sFlgWrSplitPend = VX1000_MAILBOX_FLG_CLR;
    gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][0] = len;
    gVX1000.Mailbox.SM_WriteIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.SM_WriteIdx);
    VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) /* note: EM00034754 did not mention to remove THIS one */ /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because the user/compiler typically provides the HW address as an integer (it does not know the VX pointer types) */
  }
  return retVal;
}
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxRead                                                                                          */
/* API name:      VX1000_MAILBOX_READ (expression) / VX1000_MAILBOX_READ_VOID (statement)                                     */
/* Return value:  Error code (0==OK)                                                                                          */
/*                Additional data returned via pointers                                                                       */
/* Parameter1:    pLen (*IN): maximum allowed message size                                                                    */
/*                pLen (*OUT): actual message size if successful                                                              */
/* Parameter2:    pBuf (IN): destination for the next message                                                                 */
/*                The caller is responsible that the destination contains at least *pLen writeable bytes.                     */
/*                The function aborts with an error if the buffer is too small for the current message (no bytes copied).     */
/*                pBuf (*OUT): a copy of the entire message if successful.                                                    */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox read function.                                  */
/*                This function must not interrupt any vx1000 mailbox read function.                                          */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Read the data from next filled Master->Slave mailbox slot into pBuf and return the number of bytes in pLen. */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxRead)(VX1000_UINT32* pLen, VX1000_CHAR* pBuf)
{
  VX1000_UINT32 len;
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (0==(VX1000_MAILBOX_USED_RD_SLOTS))
  {
    retVal = VX1000_MAILBOX_ERR_EMPTY;
  }
  else if ((0==pLen) || (0==pBuf))
  {
    retVal = VX1000_MAILBOX_ERR_NULL;
  }
  else
  {
    len = gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][0];
    if (len > *pLen)
    {
      retVal = VX1000_MAILBOX_ERR_SIZE;
    }
#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
    else if (sFlgRdSplitPend != 0)
    {
      retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
    }
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
    else
    {
#if defined(VX1000_MEMCPY) /* it's impossible to find typecasts that work with all compilers without warnings */
      VX1000_MEMCPY(pBuf, (void*)((VX1000_UINT32)((volatile VX1000_UINT32*)(&gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1]))), len);  /*PRQA S 0303 */ /*PRQA S 0306 */ /* compiler warnings about differing prototype of this library function and potential mismatch of type qualifiers force violation of MISRA Rules 11.3 */
#else /* !VX1000_MEMCPY */
      VX1000_UINT32 cnt;
      volatile const VX1000_CHAR *pSrc = (volatile const VX1000_CHAR *)&(gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1]);
      for (cnt = 0; cnt < len; cnt++)
      {
        pBuf[cnt] = pSrc[cnt];
      }
#endif /* !VX1000_MEMCPY */
      *pLen = len;
      gVX1000.Mailbox.MS_ReadIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.MS_ReadIdx);
      /* VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) -- removed due to EM00034754 */
    }
  }
  return retVal;
}


#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxReadSplit                                                                                     */
/* API name:      VX1000_MAILBOX_READSPLIT (expression) / VX1000_MAILBOX_READSPLIT_VOID (statement)                           */
/* Return value:  Error code (0==OK)                                                                                          */
/*                Additional data returned via pointers                                                                       */
/* Parameter1:    pLen (IN): a pointer to a 32bit variable.                                                                   */
/*                pLen (*OUT): the byte count of the next message.                                                            */
/*                The caller is responsible that the pointer is valid and that the destination is writeable.                  */
/* Parameter1:    ppBuf (IN): a pointer to a pointer variable.                                                                */
/*                ppBuf (*OUT): pointer to the data field of the next unread message.                                         */
/*                The caller is responsible that the pointer is valid and that the destination is writeable.                  */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox read function.                                  */
/*                This function must not interrupt any vx1000 mailbox read function.                                          */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Just find out location and length of the next unread message and return the info to the caller.             */
/*                Note: the mailbox state is not changed nor is the master notified (vx1000_MailboxReadDone will do this).    */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadSplit)(VX1000_UINT32* pLen, VX1000_UINT32** ppBuf)
{
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (0==(VX1000_MAILBOX_USED_RD_SLOTS))
  {
    retVal = VX1000_MAILBOX_ERR_EMPTY;
  }
  else if ((0==pLen) || (0==ppBuf))
  {
    retVal = VX1000_MAILBOX_ERR_NULL;
  }
  else if (sFlgRdSplitPend != 0)
  {
    retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
  }
  else
  {
    sFlgRdSplitPend = VX1000_MAILBOX_FLG_SET;
    *pLen = gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][0];
    *ppBuf = (VX1000_UINT32*)(VX1000_UINT32)&gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1]; /* PRQA S 0306 */ /* possible compiler warnings about loosing qualifiers force violating MISRA Rule 11.3 here by explicit dummy cast chain */
  }
  return retVal;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxReadDone                                                                                      */
/* API name:      VX1000_MAILBOX_READDONE (expression) / VX1000_MAILBOX_READDONE_VOID (statement)                             */
/* Return value:  error code (0==OK)                                                                                          */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox read function.                                  */
/*                This function must not interrupt any vx1000 mailbox read function.                                          */
/* Termination:                                                                                                               */
/* Precondition1: mailboxReadSplit() must have been called successfully.                                                      */
/* Description:   Mark the filled Master->Slave mailbox slot as empty and notify the master afterwards.                       */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadDone)(void)
{
  VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

  if (0==sFlgRdSplitPend)
  {
    retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
  }
  else
  {
    sFlgRdSplitPend = VX1000_MAILBOX_FLG_CLR;
    gVX1000.Mailbox.MS_ReadIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.MS_ReadIdx);
    /* VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) -- removed due to EM00034754 */
  }
  return retVal;
}
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */

#define VX1000_CRM_CMD txBuf[0]
#define VX1000_CRM_ERR txBuf[1]
#define VX1000_CC_SET_MTA                      0xF6
#define VX1000_CC_BUILD_CHECKSUM               0xF3

/* XCP calibration memory handling */
#if defined(VX1000_MAILBOX_CAL_READ_WRITE)

/* XCP compliant protocol handler - though these defines are only visible inside this module, they still /
/  may conflict with stuff coming in via VX1000_cfg.h sub-includes, so better add VX1000_-prefixes      */
#define VX1000_CC_SHORT_DOWNLOAD               0xED
#define VX1000_CC_SHORT_UPLOAD                 0xF4

/* SHORT_DOWNLOAD */
#define VX1000_CRO_SHORT_DOWNLOAD_LEN          8 /* + CRO_SHORT_DOWNLOAD_SIZE */
#define VX1000_CRO_SHORT_DOWNLOAD_SIZE         rxBuf[(1)]
#define VX1000_CRO_SHORT_DOWNLOAD_EXT          rxBuf[(3)]
#define VX1000_CRO_SHORT_DOWNLOAD_ADDR         (*((VX1000_UINT32*)&rxBuf[(4)]))
#define VX1000_CRO_SHORT_DOWNLOAD_DATA         (&rxBuf[(8)])
#define VX1000_CRM_SHORT_DOWNLOAD_LEN          1

/* SHORT_UPLOAD */
#define VX1000_CRO_SHORT_UPLOAD_LEN            8
#define VX1000_CRO_SHORT_UPLOAD_SIZE           rxBuf[(1)]
#define VX1000_CRO_SHORT_UPLOAD_EXT            rxBuf[(3)]
#define VX1000_CRO_SHORT_UPLOAD_ADDR           (*((VX1000_UINT32*)&rxBuf[(4)]))
#define VX1000_CRM_SHORT_UPLOAD_DATA           (&txBuf[(1)])
#define VX1000_CRM_SHORT_UPLOAD_LEN            1 /* + CRO_SHORT_UPLOAD_SIZE */

#endif /* VX1000_MAILBOX_CAL_READ_WRITE */

/* XCP calibration page handling */
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX))
#define VX1000_CC_USRCMD                       0xF1
#define VX1000_CC_USC_WOVLCFG                  0x91
#define VX1000_CC_USC_WOVLCFG_DESCR            0x0
#define VX1000_CC_USC_WOVLCFG_OSELOVCCON       0x1
#define VX1000_CC_USC_WOVLCFG_OVCCON           0x2
#define VX1000_CC_USC_WOVLCFG_MAX              0x2

#define VX1000_CRO_SUB_CMD                     rxBuf[1]
#define VX1000_CRO_USC_WOVLCFG_MODE            rxBuf[2]
#define VX1000_CRO_USC_WOVLCFG_DESCRIDX        rxBuf[3]
#define VX1000_CRO_USC_WOVLCFG_OVCCON          rxBuf[4]

#define VX1000_CRM_USRCMD_LEN                  1
#endif /* VX1000_OVERLAY & VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX */

#define VX1000_CC_SET_CAL_PAGE                 0xEB
#define VX1000_CC_GET_CAL_PAGE                 0xEA
#define VX1000_CC_COPY_CAL_PAGE                0xE4

/* SET_CAL_PAGE */
#define VX1000_CRO_SET_CALPAGE_LEN             4
#define VX1000_CRO_SET_CALPAGE_MODE            rxBuf[(1)]
#define VX1000_CRO_SET_CALPAGE_SEG             rxBuf[(2)]
#define VX1000_CRO_SET_CALPAGE_PAGE            rxBuf[(3)]
#define VX1000_CRM_SET_CALPAGE_LEN             1

/* GET_CAL_PAGE */
#define VX1000_CRO_GET_CALPAGE_LEN             3
#define VX1000_CRO_GET_CALPAGE_MODE            rxBuf[(1)]
#define VX1000_CRO_GET_CALPAGE_SEG             rxBuf[(2)]
#define VX1000_CRM_GET_CALPAGE_LEN             4
#define VX1000_CRM_GET_CALPAGE_PAGE            txBuf[(3)]

/* COPY_CAL_PAGE */
#define VX1000_CRO_CPY_CALPAGE_LEN             5
#define VX1000_CRO_CPY_CALPAGE_SRCSEG          rxBuf[(1)]
#define VX1000_CRO_CPY_CALPAGE_SRCPAGE         rxBuf[(2)]
#define VX1000_CRO_CPY_CALPAGE_DSTSEG          rxBuf[(3)]
#define VX1000_CRO_CPY_CALPAGE_DSTPAGE         rxBuf[(4)]
#define VX1000_CRM_COPY_CAL_PAGE_LEN           1
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */

/* flash programming via mailbox */
#if defined(VX1000_MAILBOX_FLASH)

/* Commands: */
#define VX1000_CC_PROGRAM_START                0xD2
#define VX1000_CC_PROGRAM_CLEAR                0xD1
#define VX1000_CC_PROGRAM                      0xD0
#define VX1000_CC_PROGRAM_RESET                0xCF
#define VX1000_CC_GET_PGM_PROCESSORINFO        0xCE
#define VX1000_CC_GET_SECTOR_INFO              0xCD
#define VX1000_CC_PROGRAM_PREPARE              0xCC
#define VX1000_CC_PROGRAM_NEXT                 0xCA
#define VX1000_CC_PROGRAM_MAX                  0xC9
#define VX1000_CC_PROGRAM_VERIFY               0xC8

/* Data for: */
/* - PROGRAM_PREPARE */
#define VX1000_CRO_PGM_PREPARE_LEN             4
#define VX1000_CRO_PGM_PREPARE_SIZE            (*((VX1000_UINT16*)&rxBuf[(2)]))
#define VX1000_CRM_PGM_PREPARE_LEN             1

/* - PROGRAM_START */
#define VX1000_CRO_PGM_START_LEN               1
#define VX1000_CRM_PROGRAM_START_LEN           7
#define VX1000_CRM_PGM_COMM_MODE_PGM           txBuf[(2)]
#define VX1000_CRM_PGM_MAX_CTO_PGM             txBuf[(3)]
#define VX1000_CRM_PGM_MAX_BS_PGM              txBuf[(4)]
#define VX1000_CRM_PGM_MIN_ST_PGM              txBuf[(5)]
#define VX1000_CRM_PGM_QUEUE_SIZE_PGM          txBuf[(6)]

/* - PROGRAM_CLEAR */
#define VX1000_CRO_PGM_CLEAR_LEN               8
#define VX1000_CRO_PGM_CLEAR_MODE              rxBuf[(1)]
#define VX1000_CRO_PGM_CLEAR_SIZE              (*((VX1000_UINT32*)&rxBuf[(4)]))
#define VX1000_CRM_PGM_CLEAR_LEN               1

/* - PROGRAM */
#define VX1000_CRO_PGM_MAX_SIZE                ((VX1000_UINT8)((VX1000_MAILBOX_SLOT_DWORDS) << 2) - ...)
#define VX1000_CRO_PGM_LEN                     2 /* + CRO_PROGRAM_SIZE */
#define VX1000_CRO_PGM_SIZE                    rxBuf[(1)]
#define VX1000_CRO_PGM_DATA                    (&rxBuf[(2)])
#define VX1000_CRM_PGM_LEN                     1

#endif /* VX1000_MAILBOX_FLASH */

#if ((defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE))) && ((defined(VX1000_OVLENBL_REGWRITE_VIA_MX)) && (defined(VX1000_MAILBOX_OVERLAY_CONTROL)))
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_OvlWritEcuDescrMxHandler                                                                             */
/* API name:      none                                                                                                        */
/* Return value:  status:                                                                                                     */
/*                0: cmd are handled correctly                                                                                */
/*                1: nothing is done                                                                                          */
/* Parameter1:    subCmdCode E [0, VX1000_CC_USC_WOVLCFG_MAX]                                                                 */
/* Parameter2:    overlay descriptor index E [0, OVERLAY_DESCRIPTORS)                                                         */
/* Parameter3:    additional data of cmdMode                                                                                  */
/* Parameter4:                                                                                                                */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1:                                                                                                             */
/* Description:   This function writes ECU overlay registers according to values written by VX.                               */
/*                This function is called by vx1000_MailboxHandler() when subCmd of usrCmd is VX1000_CC_USC_WOVLCFG.          */
/* Devel state:   Idea                                                                                                        */
/*----------------------------------------------------------------------------------------------------------------------------*/
static VX1000_UINT8 VX1000_SUFFUN(vx1000_OvlWritEcuDescrMxHandler)(VX1000_UINT8 cmdMode, VX1000_UINT8 ovlIdx, VX1000_UINT32 xxx)
{
  VX1000_UINT8 retVal = 1;
  VX1000_ERRLOGGER(VX1000_ERRLOG_OVL_UNIMPL)
  VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_UINT8,cmdMode, ovlIdx,xxx,0,0)) /* interims dummy access */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
  return retVal;
}
#endif /* VX1000_OVERLAY && VX1000_OVERLAY_VX_CONFIGURABLE && VX1000_OVLENBL_REGWRITE_VIA_MX && VX1000_MAILBOX_OVERLAY_CONTROL */

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxHandler                                                                                       */
/* API name:      VX1000_MAILBOX_CONTROL                                                                                      */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox function.                                       */
/*                This function must not interrupt any vx1000 mailbox function.                                               */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   check the vx1000 mailbox system for pending requests and trigger the necessary reactions.                   */
/* Devel state:   Tested                                                                                                      */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_MailboxHandler)(void)
{
  VX1000_UINT32 rxLen, txLen;
  VX1000_CHAR rxBuf[12], txBuf[12];
  VX1000_UINT8 postponeAnswer = 0;

  rxLen = 8;
  if ((VX1000_MAILBOX_OK) == vx1000_MailboxRead(&rxLen, &rxBuf[0]))
  {
    txLen = 2;
    VX1000_CRM_CMD = (VX1000_CHAR)-1;
    VX1000_CRM_ERR = 0x00;
    switch ((VX1000_UINT8)rxBuf[0]) /* check CRO_CMD */
    {
    case (VX1000_UINT8)(VX1000_CC_SET_MTA):
      /* VX1000_CRM_ERR is already initialised */
      ((volatile VX1000_CHAR*)&gVX1000_MX_mta)[0] = rxBuf[(4 + 0)]; /* copy byte-wise to avoid misalignment exceptions on some MCUs */
      ((volatile VX1000_CHAR*)&gVX1000_MX_mta)[1] = rxBuf[(4 + 1)];
      ((volatile VX1000_CHAR*)&gVX1000_MX_mta)[2] = rxBuf[(4 + 2)];
      ((volatile VX1000_CHAR*)&gVX1000_MX_mta)[3] = rxBuf[(4 + 3)];
      txLen = 1;
      break;
#if defined(VX1000_MAILBOX_CAL_READ_WRITE)
    case (VX1000_UINT8)(VX1000_CC_SHORT_UPLOAD):
#if defined(VX1000_SHORT_UPLOAD)
      VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_SHORT_UPLOAD((VX1000_CRM_SHORT_UPLOAD_DATA), (VX1000_CRO_SHORT_UPLOAD_ADDR), (VX1000_CRO_SHORT_UPLOAD_SIZE)));
#elif defined(VX1000_MEMCPY)
      /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
      VX1000_MEMCPY((VX1000_UINT32)(VX1000_CRM_SHORT_UPLOAD_DATA), (VX1000_UINT32)(VX1000_CRO_SHORT_UPLOAD_ADDR), (VX1000_CRO_SHORT_UPLOAD_SIZE)); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_SHORT_UPLOAD && !VX1000_MEMCPY */
      {
        VX1000_UINT32 j;
        volatile VX1000_UINT8 *dst = (volatile VX1000_UINT8 *)(VX1000_UINT32)(VX1000_CRM_SHORT_UPLOAD_DATA);
        volatile VX1000_UINT8 *src = (volatile VX1000_UINT8 *)(VX1000_UINT32)(VX1000_CRO_SHORT_UPLOAD_ADDR);
        for (j = 0; j < (VX1000_UINT32)(VX1000_CRO_SHORT_UPLOAD_SIZE); ++j) { dst[j] = src[j]; }
      }
#endif /* !VX1000_SHORT_UPLOAD && !VX1000_MEMCPY */
      txLen = (VX1000_UINT32)(VX1000_CRM_SHORT_UPLOAD_LEN)+(VX1000_UINT32)(VX1000_CRO_SHORT_UPLOAD_SIZE);
      break;
    case (VX1000_UINT8)(VX1000_CC_SHORT_DOWNLOAD):
#if defined(VX1000_SHORT_DOWNLOAD)
      VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_SHORT_DOWNLOAD((VX1000_CRO_SHORT_DOWNLOAD_ADDR), (VX1000_CRO_SHORT_DOWNLOAD_DATA), (VX1000_CRO_SHORT_DOWNLOAD_SIZE)));
#elif defined(VX1000_MEMCPY)
      /* the ptr->int->ptr-casting is needed to avoid "-Wcast-qual" warnings regarding the volatile qualifier. */
      VX1000_MEMCPY((VX1000_UINT32)(VX1000_CRO_SHORT_DOWNLOAD_ADDR), (VX1000_UINT32)(VX1000_CRO_SHORT_DOWNLOAD_DATA), (VX1000_CRO_SHORT_DOWNLOAD_SIZE)); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this callback function may be declared either with or without memory qualifiers by the user */
#else /* !VX1000_SHORT_DOWNLOAD && !VX1000_MEMCPY */
      {
        VX1000_UINT32 j;
        volatile VX1000_UINT8 *dst = (volatile VX1000_UINT8 *)(VX1000_UINT32)(VX1000_CRO_SHORT_DOWNLOAD_ADDR);
        volatile VX1000_UINT8 *src = (volatile VX1000_UINT8 *)(VX1000_UINT32)(VX1000_CRO_SHORT_DOWNLOAD_DATA);
        for (j = 0; j < (VX1000_UINT32)(VX1000_CRO_SHORT_DOWNLOAD_SIZE); ++j) { dst[j] = src[j]; }
      }
#endif /* !VX1000_SHORT_DOWNLOAD && !VX1000_MEMCPY */
      txLen = VX1000_CRM_SHORT_DOWNLOAD_LEN;
      break;
#endif /* VX1000_MAILBOX_CAL_READ_WRITE */
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
    case (VX1000_UINT8)(VX1000_CC_GET_CAL_PAGE):
      VX1000_CRM_GET_CALPAGE_PAGE = (VX1000_CHAR)(VX1000_GET_CAL_PAGE((VX1000_CRO_GET_CALPAGE_SEG), (VX1000_CRO_GET_CALPAGE_MODE)));
      txLen = VX1000_CRM_GET_CALPAGE_LEN;
      break;
    case (VX1000_UINT8)(VX1000_CC_SET_CAL_PAGE):
      VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_WRP_SET_CAL_PAGE((VX1000_CRO_SET_CALPAGE_SEG), (VX1000_CRO_SET_CALPAGE_PAGE), (VX1000_CRO_SET_CALPAGE_MODE),0));
      if (VX1000_CRM_ERR == (VX1000_CHAR)(VX1000_CRC_CMD_BUSY))
      {
        postponeAnswer = 1; /* Asynchronous call. Mailbox answer will be sent in the callback done macro.*/
      }
      txLen = VX1000_CRM_SET_CALPAGE_LEN;
      break;
#if !defined(VX1000_OVERLAY_VX_CONFIGURABLE)
    case (VX1000_UINT8)(VX1000_CC_COPY_CAL_PAGE):
      VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_COPY_CAL_PAGE((VX1000_CRO_CPY_CALPAGE_SRCSEG), (VX1000_CRO_CPY_CALPAGE_SRCPAGE),
                                                          (VX1000_CRO_CPY_CALPAGE_DSTSEG), (VX1000_CRO_CPY_CALPAGE_DSTPAGE)));
      txLen = VX1000_CRM_COPY_CAL_PAGE_LEN;
      break;
#endif /* !VX1000_OVERLAY_VX_CONFIGURABLE */
#if (defined(VX1000_OVERLAY)) && (defined(VX1000_OVERLAY_VX_CONFIGURABLE)) && (defined(VX1000_OVLENBL_REGWRITE_VIA_MX))
    case (VX1000_UINT8)(VX1000_CC_USRCMD):
      if( (VX1000_UINT8)(rxBuf[1]) == VX1000_CC_USC_WOVLCFG)
      {
        VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_SUFFUN(vx1000_OvlWritEcuDescrMxHandler)((VX1000_CRO_USC_WOVLCFG_MODE), (VX1000_CRO_USC_WOVLCFG_DESCRIDX), *((VX1000_UINT32*)&(VX1000_CRO_USC_WOVLCFG_OVCCON))));
        txLen = VX1000_CRM_USRCMD_LEN;
      }
      else
      {
        VX1000_CRM_ERR = VX1000_CRC_CMD_UNKNOWN;
      }
      break;
#endif /* VX1000_OVERLAY & VX1000_OVERLAY_VX_CONFIGURABLE & VX1000_OVLENBL_REGWRITE_VIA_MX & VX1000_MAILBOX */
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */
#if defined(VX1000_MAILBOX_FLASH)
    case (VX1000_UINT8)(VX1000_CC_PROGRAM_PREPARE):
      /* The user callback has to cease normal ECU operation and return OK if this succeeded  */
      /* AND the FKL memory (from param1 to param2) does not interfere with current RAM usage */
      VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_PROGRAM_PREPARE( gVX1000_MX_mta, (VX1000_UINT32)(VX1000_CRO_PGM_PREPARE_SIZE) ));
      txLen = VX1000_CRM_PGM_PREPARE_LEN;
      break;
#if 0
//    case (VX1000_UINT8)(VX1000_CC_PROGRAM_START):
//      VX1000_CRM_PGM_COMM_MODE_PGM = 0;
//      VX1000_CRM_PGM_MAX_CTO_PGM = 8;
//      VX1000_CRM_PGM_MAX_BS_PGM = 1;
//      VX1000_CRM_PGM_MIN_ST_PGM = 0;
//      VX1000_CRM_PGM_QUEUE_SIZE_PGM = 1;
//      txLen = VX1000_CRM_PGM_START_LEN;
//      /* @@@@ Problem: how to actually program flash? */
//      break;
#endif /* 0 */
#endif /* VX1000_MAILBOX_FLASH */
    default:
      VX1000_CRM_ERR = VX1000_CRC_CMD_UNKNOWN;
    }
    if (0==postponeAnswer)
    {
      if ((VX1000_CRM_ERR) != 0)
      {
        VX1000_CRM_CMD = (VX1000_CHAR)-2;
        txLen = 2;
      }
      (void)VX1000_SUFFUN(vx1000_MailboxWrite)(txLen, txBuf);
    }
  }
}
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL, VX1000_MAILBOX_FLASH */

#if defined(VX1000_MAILBOX_PRINTF)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxPutchar                                                                                       */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    a character to be transmitted                                                                               */
/*                No invalid input possible.                                                                                  */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Output a single character to vx1000 mailbox system.                                                         */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
static void VX1000_SUFFUN(vx1000_MailboxPutchar)( VX1000_CHAR character )
{
  static VX1000_CHAR vx1000EvBuf[(VX1000_MAILBOX_SLOT_DWORDS) << 2]; /* note: instead of this local buffer, we _could_ use the writeSplit feature, but _then_ the user would have to disable context switches during prints! */
  static VX1000_UINT32 vx1000EvLen;

  if ((vx1000EvBuf[0] != (VX1000_CHAR)-4) || (vx1000EvBuf[1] != (VX1000_CHAR)1) || (vx1000EvLen >= ((VX1000_MAILBOX_SLOT_DWORDS) << 2))) /* PRQA S 3355 */ /* though it's true that this algorithm speculates on probabilities, MISRA Rule 13.7 is NOT violated (the checker ignored the static nature of the variables) */
  {
    /* initialize the protocol header once */
    vx1000EvBuf[0] = (VX1000_CHAR)-4; /* SERV */
    vx1000EvBuf[1] = (VX1000_CHAR)1;  /* SERV_TEXT */
    vx1000EvLen = 2;
  }
  vx1000EvBuf[vx1000EvLen] = character;
  vx1000EvLen++;
  if ( (vx1000EvLen >= ((VX1000_MAILBOX_SLOT_DWORDS) << 2)) || (0==character) ) /* PRQA S 3356 */ /* though it's true that this algorithm speculates on probabilities, MISRA Rule 13.7 is NOT violated (the checker ignored the static nature of the variables) */
  {
    (void)VX1000_SUFFUN(vx1000_MailboxWrite)(vx1000EvLen, vx1000EvBuf);
    vx1000EvLen = 2;
  }
}

#if !defined(VX1000_PRINTF_MINIMAL)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxPrintf                                                                                        */
/* API name:      VX1000_PRINTF                                                                                               */
/* Return value:  none                                                                                                        */
/* Parameter1:    pointer to ASCIIZ string in stdio-printf format (token support according to linked compiler library)        */
/*                Validity has to be ensured by the caller; bad input may lead to crash!                                      */
/* Parameter2+:   variadic list of additional printf input.                                                                   */
/*                Validity has to be ensured by the caller; bad input may lead to crash!                                      */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Full version of classic printf() with output redirected to vx1000 mailbox system.                           */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
/* The full printf library function not only occupies two dozens of Kbytes TEXT but also allocates */
/* a rather huge amount of stack upon calls so it is not well suited for multitasking environments */
void VX1000_SUFFUN(vx1000_MailboxPrintf)( const VX1000_CHAR *format, ... ) /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
{
  va_list argptr;
  VX1000_CHAR buf[256];

  va_start(argptr, format);
  (void)vsprintf((VX1000_CHAR*)buf, (const VX1000_CHAR*)format, argptr);
  va_end(argptr); /* PRQA S 3199 */ /* it depends on the used compiler whether this statement has useful side effects or not */

  /* Transmit the text message */
  {
    VX1000_CHAR *p = buf;
    while (*p != 0)
    {
      VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)*p);
      p++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
    }
  }

  /* Transmit the terminating 0x00. */
  VX1000_SUFFUN(vx1000_MailboxPutchar)( 0x00 );
}
#else /* VX1000_PRINTF_MINIMAL */
/* This reduced printf implementation does not support features like float support or argument */
/* repetition, but it usually uses less TEXT and RAM usage is only a few bytes at runtime.     */

#define PF_NONE          0U
#define PF_IN_TOKEN      1U
#define PF_IN_WIDTH      2U
#define PF_AFTER_WIDTH   4U
#define PF_IN_PREC       8U
#define PF_AFTER_PREC   16U
#define PF_IN_SIZE      32U
#define PF_AFTER_SIZE   64U
#define PF_INVALID     128U
#define GENBIN2DECAUXSTAGE(B)                                                                                                   \
if (number >=(2*(B))){ if (number >=(6*(B))){ if (number >=(8*(B))) { if (number >=(9*(B))){ number -= 9*(B); *p = '9'; p++;}   \
                                                                      else                 { number -= 8*(B); *p = '8'; p++;}}  \
                                              else                  { if (number >=(7*(B))){ number -= 7*(B); *p = '7'; p++;}   \
                                                                      else                 { number -= 6*(B); *p = '6'; p++;}}} \
                       else                 { if (number >=(4*(B))) { if (number >=(5*(B))){ number -= 5*(B); *p = '5'; p++;}   \
                                                                      else                 { number -= 4*(B); *p = '4'; p++;}}  \
                                              else                  { if (number >=(3*(B))){ number -= 3*(B); *p = '3'; p++;}   \
                                                                      else                 { number -= 2*(B); *p = '2'; p++;}}}}\
else                 { if (number >=(1*(B)))                                               { number -= 1*(B); *p = '1'; p++;}   \
                       else                                                                { number -= 0*(B); *p = '0'; p++;}}

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_MailboxPrintf                                                                                        */
/* API name:      VX1000_PRINTF                                                                                               */
/* Return value:  none                                                                                                        */
/* Parameter1:    pointer to ASCIIZ string in stdio-printf format (not all tokens supported!)                                 */
/*                Validity has to be ensured by the caller; bad input may lead to crash!                                      */
/* Parameter2+:   variadic list of additional printf input.                                                                   */
/*                Validity has to be ensured by the caller; bad input may lead to crash!                                      */
/* Preemption:    This function must not be interrupted by any vx1000 mailbox write function.                                 */
/*                This function must not interrupt any vx1000 mailbox write function.                                         */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_MailboxInit() must have been called.                                                                 */
/* Description:   Minimal version of classic printf() with output redirected to vx1000 mailbox system.                        */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_MailboxPrintf)( const VX1000_CHAR *format, ... ) /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
{
  va_list arglist;
  VX1000_LONG number;
  VX1000_LDOUBL fdummy = 0.0;
  VX1000_CHAR *p2, numbuf[24];
  VX1000_INT   i, width=0, prec=0, size=0, basesize=0;
  VX1000_CHAR  frmchr, digif=0, filler=0, alignleft=0, showpos=0, showbase=0, *p, signedtype=0, floattype=0;
  VX1000_UINT8 state, continuer;

  va_start(arglist, format);
  state = (PF_NONE);
  for (; *format != 0; format++) /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
  {
    continuer = 0;
    frmchr = *format;
    if (state == (PF_NONE))
    {
      if (frmchr == '%')
      {
        state = (PF_IN_TOKEN);
        width = prec = size = basesize = 0;
        floattype = signedtype = 0;
        filler = showpos = ' ';
      }
      else
      {
        VX1000_SUFFUN(vx1000_MailboxPutchar)(frmchr);
      }
      continuer = 1;
    }
    if ((0==continuer) && (frmchr == '%'))
    {
      if (state == (PF_IN_TOKEN)) /* no real token, just an escaped "%" */
      {
        state = (PF_NONE);
        VX1000_SUFFUN(vx1000_MailboxPutchar)(frmchr);
      }
      else
      {
        state |= (PF_INVALID);
      }
      continuer = 1;
    }
    if ((0==continuer) && ((frmchr >= '0') && (frmchr <= '9')))
    {
      frmchr -= '0';
      switch (state & ((PF_IN_WIDTH) | (PF_IN_PREC) | (PF_IN_SIZE))) /* continue in a number */
      {
        case (PF_IN_WIDTH): width = (10 * width) + (VX1000_INT)frmchr; continuer = 1; break;
        case (PF_IN_PREC):  prec  = (10 * prec ) + (VX1000_INT)frmchr; VX1000_DUMMYREAD(prec)/* just to avoid compiler warnings */ continuer = 1; break; /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
        case (PF_IN_SIZE):  size  = (10 * size ) + (VX1000_INT)frmchr; continuer = 1; break;
        default:  /* only here for MISRA */
          break; /* only here for MISRA */
      }
      if ((0==continuer) && (0==(state & (PF_AFTER_WIDTH)))) /* start reading width number */
      {
        state |= (PF_IN_WIDTH);
        width = (VX1000_INT)frmchr;
        if (frmchr==0) { filler = '0'; }
        continuer = 1;
      }
      if ((0==continuer) && (0==(state & (PF_AFTER_PREC)))) /* start reading precision number */
      {
        state |= (PF_IN_PREC);
        prec = (VX1000_INT)frmchr;
        VX1000_DUMMYREAD(prec) /* just to avoid compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
        continuer = 1;
      }
      if (0==continuer)
      {
        state |= (PF_INVALID);
      }
      continuer = 1;
    }
    if (0==continuer)
    {
      switch (state & ((PF_IN_WIDTH) | (PF_IN_PREC) | (PF_IN_SIZE))) /* stop any number */
      {
        case (PF_IN_WIDTH): state ^= (PF_IN_WIDTH) | (PF_AFTER_WIDTH); break;
        case (PF_IN_PREC):  state ^= (PF_IN_PREC)  | (PF_AFTER_PREC);  break;
        case (PF_IN_SIZE):  state ^= (PF_IN_SIZE)  | (PF_AFTER_SIZE);  break;
        default:  /* only here for MISRA */
          break; /* only here for MISRA */
      }
    }
    if ((0==continuer) && (frmchr == 'l'))
    {
      state |= (PF_IN_SIZE);
      size += (VX1000_INT)(8 * (sizeof(VX1000_LONG) - sizeof(VX1000_INT)));
      if (size > 64) { state |= (PF_INVALID); }
      continuer = 1;
    }
    if (0==continuer)
    {
      switch (frmchr) /* get the format specifier */
      {
        case '#':
          showbase = 1;
          continuer = 1;
          break;
        case '+':
          showpos = '+';
          continuer = 1;
          break;
        case '-':
          alignleft = 1;
          continuer = 1;
          break;
        case 'L':
          state |= (PF_AFTER_SIZE);
          size = 256;
          continuer = 1;
          break;
        case 'I': /* Microsoft specific size: start reading the number */
          state |= (PF_IN_SIZE);
          continuer = 1;
          break;
        case 'c':
          VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)va_arg(arglist, VX1000_INT));
          state = (PF_NONE);
          continuer = 1;
          break;
        case 's':
          /* todo: care for alignment */
          p = (VX1000_CHAR*)va_arg(arglist, VX1000_CHAR*);
          while (*p != 0) { VX1000_SUFFUN(vx1000_MailboxPutchar)(*p); p++; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
          state = (PF_NONE);
          continuer = 1;
          break;
        case 'o':
          digif = '7';
          basesize = 8 * sizeof(VX1000_INT);
          break;
        case 'd':
          /* fall-through to 'i' */
        case 'i':
          signedtype = 1;
          /* fall-through to 'u' */
        case 'u': /* PRQA S 2003 */ /* cannot avoid violating MISRA Rule 15.2 because multiple labels shall use the same code so break cannot be used (and replication the code isn't an option either because it degrades maintainability) */
          digif = '9';
          basesize = 8 * sizeof(VX1000_INT);
          break;
        case 'X':
          digif = 'F';
          basesize = 8 * sizeof(VX1000_INT);
          break;
        case 'x':
          digif = 'f';
          basesize = 8 * sizeof(VX1000_INT);
          break;
        case 'e':
        case 'E':
          /* scientific floats are not supported */
          basesize = 128;
          floattype= 1;
          break;
        case 'f':
        case 'F':
        case 'g':
        case 'G':
          /* fixed floats are not supported */
          basesize = 64;
          floattype= 1;
          break;
        default:
          state |= (PF_INVALID);
      }
    }
    if ((0==continuer) && (0==(state & (PF_INVALID))))
    {
      state = (PF_NONE);
      if (size < basesize) { size = basesize; }
      if (floattype != 0)
      {
        switch (size)
        {
          /* floats currently are not supported - just advance the pointer and print a hash sign as place holder */
          case 64:  VX1000_SUFFUN(vx1000_MailboxPutchar)('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, /*float*/VX1000_DOUBLE); continuer = 1; break;
          case 128: VX1000_SUFFUN(vx1000_MailboxPutchar)('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, VX1000_DOUBLE);          continuer = 1; break;
          case 256: VX1000_SUFFUN(vx1000_MailboxPutchar)('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, VX1000_LDOUBL);          continuer = 1; break;
          default:    /* only here for MISRA */
            VX1000_DUMMYREAD(fdummy) /* just to avoid compiler warnings */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
            break;    /* only here for MISRA */
        }
      }
      else
      {
        switch (size)
        {
          case 8 * sizeof(VX1000_INT): number = (VX1000_LONG)va_arg(arglist, VX1000_INT);   break;
          default:                     number = (VX1000_LONG)va_arg(arglist, VX1000_LONG);  break;
          }
          if (signedtype != 0)
          {
            if (number < 0)
            {
              number = -number;
              showpos = '-';
            }
        }
        if (showpos != ' ') { VX1000_SUFFUN(vx1000_MailboxPutchar)(showpos); }
        switch (digif)
        {
          case '7':
            i = 11;
            numbuf[i] = 0;
            while (i != 0)
            {
              i--; numbuf[i] = (VX1000_CHAR)(0x7UL & (VX1000_UINT32)number);
              numbuf[i] += '0';
              number >>= 3; /* PRQA S 0502 */ /* Actually not violating MISRA Rule 12.7 because any bits shifted in are masked before usage of the result */
            }
            break;
          case '9':
            /*numbuf[10] = 0;*/
            p = numbuf;
            if ((VX1000_UINT32)number >= (2 * 1000000000UL))  { if ((((VX1000_UINT32)number) & 0xFFFFFFFFUL) >= (((VX1000_UINT32)(4UL * 1000000000UL))+(0xF0000000UL & (VX1000_UINT32)(VX1000_UINT8)(digif))))
                                                                     { number -= 2 * 1000000000L;
                                                                       number -= 2 * 1000000000L; *p = '4'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                               else             { if ((((VX1000_UINT32)number) & 0xFFFFFFFFUL) >= (((VX1000_UINT32)(3UL * 1000000000UL))+(0xF0000000UL & (VX1000_UINT32)(VX1000_UINT8)(digif))))
                                                                     { number -= 2 * 1000000000L;
                                                                       number -= 1 * 1000000000L; *p = '3'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                                                  else
                                                                     { number -= 2 * 1000000000L; *p = '2'; p++;}}} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            else                             { if ((VX1000_UINT32)number >= (1 * 1000000000UL))
                                                                     { number -= 1 * 1000000000L; *p = '1'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                               else
                                                                     { number -= 0 * 1000000000L; *p = '0'; p++;}} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(100000000L) /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(10000000L)  /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(1000000L)   /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(100000L)    /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(10000L)     /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(1000L)      /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(100L)       /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(10L)        /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            GENBIN2DECAUXSTAGE(1L)         /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            *p = 0;
            VX1000_DUMMYREAD(VX1000_DISCARD4DUMMYARGS(VX1000_LONG,number, p[0],0,0,0)) /* dummy accesses to avoid compiler warnings. */ /* PRQA S 3112 */ /* The code in this user callback may violate MISRA Rule 14.2 because the dedicated goal of this code is to actually have no (side) effect at all (except avoiding possible warnings by some compiles */
            break;
          case 'F': /* fallthrough to 'f' */
          case 'f':
            digif -= 15;
            i = 8;
            numbuf[i] = 0;
            while (i != 0)
            {
              frmchr = (VX1000_CHAR)(0xfUL & (VX1000_UINT32)number);
              number >>= 4; /* PRQA S 0502 */ /* Actually not violating MISRA Rule 12.7 because any bits shifted in are masked before usage of the result */
              frmchr += (VX1000_CHAR)((frmchr > 9) ? digif : (VX1000_CHAR)'0');
              i--; numbuf[i] = frmchr;
            }
            break;
          default:  /* only here for MISRA */
            break; /* only here for MISRA */
        }
        for (p = numbuf; *p == '0'; p++) { } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
        if (0==*p) { p--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because strcat and thus pointer decrementation is a core feature of this application */
        if (alignleft == 1)
        {
          if ((showbase == 1) && (digif != '9'))
          {
            VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)'0');
            if (digif != '7') { VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)'x'); }
          }
          for (; *p != 0; p++) { VX1000_SUFFUN(vx1000_MailboxPutchar)(*p); width--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
          for (--width; width >= 0; width--) { VX1000_SUFFUN(vx1000_MailboxPutchar)(' ');  }
        }
        else
        {
          for (p2 = p; *p2 != 0; p2++) { width--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
          for (--width; width >= 0; width--) { VX1000_SUFFUN(vx1000_MailboxPutchar)(filler); }
          if ((showbase == 1) && (digif != '9'))
          {
            VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)'0');
            if (digif != '7') { VX1000_SUFFUN(vx1000_MailboxPutchar)((VX1000_CHAR)'x'); }
          }
          for (; *p != 0; p++) { VX1000_SUFFUN(vx1000_MailboxPutchar)(*p); } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
        }
        continuer = 1;
      }
    }
    if (0==continuer)
    {
      /* reaching here means we misunderstood the format string and assumed stupid argument. /
      /  type. To avoid invalid pointer accesses to any following arguments, we leave now:  */
      VX1000_SUFFUN(vx1000_MailboxPutchar)('!');VX1000_SUFFUN(vx1000_MailboxPutchar)(64);VX1000_SUFFUN(vx1000_MailboxPutchar)('!');
      break; /* the for loop */
    }
  } /* for */
  va_end(arglist); /* PRQA S 3199 */ /* it depends on the used compiler whether this statement has useful side effects or not */
  /* Transmit the terminating 0x00. */
  VX1000_SUFFUN(vx1000_MailboxPutchar)( (VX1000_UINT8)0x00U );
}
#endif /* VX1000_PRINTF_MINIMAL */



#endif /* VX1000_MAILBOX_PRINTF */
#endif /* VX1000_MAILBOX  && !VX1000_COMPILED_FOR_SLAVECORES */


#if defined(VX1000_FKL_SUPPORT_ADDR) && (!defined(VX1000_COMPILED_FOR_SLAVECORES))
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_FlashPrepareLoop                                                                                     */
/* API name:      VX1000_DETECT_FKL_REQUESTS                                                                                  */
/* Return value:  none                                                                                                        */
/* Parameter1:    none                                                                                                        */
/* Preemption:                                                                                                                */
/* Termination:   May leave entire system in an invalid state.                                                                */
/* Precondition1: vx1000_InitAsyncEnd() must have been called.                                                                */
/* Description:   Prevents the application from writing to RAM to enable successful flash kernel download;                    */
/*                Busy waits for trigger command to jump to the transferred address.                                          */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_FlashPrepareLoop)(void)
{
  gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_FKL_REQ_DETECTED);
  VX1000_DISABLE_ALL_INTERRUPTS()                /* prevent other tasks / ISRs from overwriting RAM / reading flash */
  VX1000_STOP_OS_TIMING_PROTECTION()             /* prevent Autosar OS in SC2 / SC4 from killing the loop/kernel */
  VX1000_STOP_OTHER_CORES()                      /* prevent other cores (or DMA/PEC) from overwriting RAM / reading flash */
  VX1000_ENABLE_STD_RAM_MAPPING()                /* repair non-default RAM mapping (the FKL is linked to standard location) */

  (VX1000_FKL_WORKSPACE)->DeprotectState     = (VX1000_UINT16)(VX1000_FKL_STATE1CODE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  (VX1000_FKL_WORKSPACE)->DeprotectTrigger   = (VX1000_UINT16)(VX1000_FKL_TOSTATE1CODE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  (VX1000_FKL_WORKSPACE)->TransitionTimeout  = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  (VX1000_FKL_WORKSPACE)->WdgData1           = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  (VX1000_FKL_WORKSPACE)->WdgData2           = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  (VX1000_FKL_WORKSPACE)->WdgData3_FklParam3 = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
  *(VX1000_UINT32*)&((VX1000_FKL_WORKSPACE)->EntryPoint) = (VX1000_UINT32)0xFFFFFFFFUL; /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow invalidation of the function pointer */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */

#if !defined(VX1000_FKL_BOUNCEBACK)
  /* Now normal operation of the ECU (Appl + XCP instrumentation) is stopped: tell the tool how to further communicate: */
  gVX1000.MagicId = (VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR);
  gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_FKL_FORCED_IDLE);
  /* Once the tool accepted the new communication area, no longer access gVX1000, because that location is likely to be */
  /* reused for storing the flash kernel code, so reads would return invalid data and writes could destroy the kernel.  */

  while (1) /* intentional infinite loop (can be left by pseudo call to FKL or by watchdog reset) */
  {
    /* The code inside this loop must not use stack (access non-register-ed local variables or call non-FKL functions) */
    /* (if that can't be ensured, we'd have to reload the SP with (VX1000_FKL_SUPPORT_ADDR-16): HW-SPECIFIC ASSEMBLY!) */
    if ( (((VX1000_FKL_WORKSPACE)->TransitionTimeout != 0) && ((VX1000_FKL_WORKSPACE)->TransitionTimeout != 0))   /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
    &&   (((VX1000_FKL_WORKSPACE)->TransitionTimeout != 0) && ((VX1000_FKL_WORKSPACE)->TransitionTimeout != 0)) ) /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
    {
      (VX1000_FKL_WORKSPACE)->TransitionTimeout--; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
      VX1000_SERVE_WATCHDOG(&((VX1000_FKL_WORKSPACE)->WdgData1))
    }
    else
    {
      switch ((((VX1000_UINT32)((VX1000_FKL_WORKSPACE)->DeprotectState) << 8U) << 8U) | (VX1000_FKL_WORKSPACE)->DeprotectTrigger) /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
      {
      case ((VX1000_UINT32)(VX1000_FKL_STATE1CODE) << 16) | (VX1000_FKL_TOSTATE1CODE):
        /* still in the initialisation phase */
        break;
      case ((VX1000_UINT32)(VX1000_FKL_STATE1CODE) << 16) | (VX1000_FKL_TOSTATE2CODE):
        (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE2CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        break;
      case ((VX1000_UINT32)(VX1000_FKL_STATE2CODE) << 16) | (VX1000_FKL_TOSTATE3CODE):
        (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE3CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        break;
      case ((VX1000_UINT32)(VX1000_FKL_STATE3CODE) << 16) | (VX1000_FKL_TOSTATE4CODE):
        (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE4CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        break;
      case ((VX1000_UINT32)(VX1000_FKL_STATE4CODE) << 16) | (VX1000_FKL_TOSTATE5CODE):
        (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE5CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        break;
      case ((VX1000_UINT32)(VX1000_FKL_STATE5CODE) << 16) | (VX1000_FKL_LAUNCHCODE):
        (VX1000_FKL_WORKSPACE)->TransitionTimeout = 1UL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        if (*(VX1000_UINT32*)&((VX1000_FKL_WORKSPACE)->EntryPoint) != 0xFFFFFFFFUL)  /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalidated function pointer */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        {
          ((VX1000_FKL_WORKSPACE)->EntryPoint)((VX1000_FKL_WORKSPACE)->FklParam1, (VX1000_FKL_WORKSPACE)->FklParam2, (VX1000_FKL_WORKSPACE)->WdgData3_FklParam3);  /* call the FKL: will not return here */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
        }
        break;
      default:
        /* bad trigger sequence detected */
        while (1) /* intentional infinite loop without watchdog serving, will lead to watchdog reset */
        {
          /* intentionally left empty */
        }
        /*break; /-* unreachable code, intentionally here to please MISRA checkers */
      }
    }
  }
#else /* VX1000_FKL_BOUNCEBACK */
  /* The user wants that the request is reflected back to the tool. */
  gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_FKL_REQ_IGNORED);
  /* While the API now returns to the application, the VX device will start trying to force the ECU into debug/freeze mode */
#endif /* VX1000_FKL_BOUNCEBACK */
}
#endif /* VX1000_FKL_SUPPORT_ADDR  && !VX1000_COMPILED_FOR_SLAVECORES */

#if (VX1000_ERRLOG_SIZE != 0)
/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_ErrLogger                                                                                            */
/* API name:      VX1000_ERRLOGGER                                                                                            */
/* Return value:  none                                                                                                        */
/* Parameter1:    An error code.                                                                                              */
/* Preemption:                                                                                                                */
/* Termination:                                                                                                               */
/* Precondition1: vx1000_InitAsyncStart() must have been called.                                                              */
/* Description:   Log the error code to a ring buffer for later debug/support purposes                                        */
/* Devel state:   Implemented                                                                                                 */
/*----------------------------------------------------------------------------------------------------------------------------*/
void VX1000_SUFFUN(vx1000_ErrLogger)( VX1000_UINT16 errorcode )
{
  VX1000_UINT8 currentI, nextI;
  VX1000_UINT16 *logbuf = (VX1000_UINT16 *)gVX1000.ErrLogAddr; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */

  VX1000_ENTER_SPINLOCK()
  currentI = gVX1000.ErrLogIndex;
  nextI = currentI + 1;
  if (nextI >= gVX1000.ErrLogSize) { nextI = 0; }
  gVX1000.ErrLogIndex = nextI;
  VX1000_LEAVE_SPINLOCK()
  logbuf[currentI] = errorcode;
}
#endif /* VX1000_ERRLOG_SIZE */

#if !defined(VX1000_COMPILED_FOR_SLAVECORES) /* global data have to exist only once (in shared memory) */

/* The following is VX1000_DATA, but split to allow separate linkage of gVX1000 at a user-defined address */
VX1000_STIM_BENCHMARK_DATA
VX1000_ECUID_DATA
VX1000_OLDA_BENCHMARK_DATA
VX1000_COLDSTART_BENCHMARK_DATA
#if !defined(VX1000_HOOKS_ARE_OUTSOURCED)
VX1000_HOOK_CONTROL_DATA
#endif /* !VX1000_HOOKS_ARE_OUTSOURCED */

/* include user-defined lines with optional section pragmas to force individual linkage of VX1000 structure data. */
#define VX1000_BEGSECT_VXSTRUCT_C
#include "VX1000_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
/*DESAYSV add self difine the RAN Address to 0xFEBFFB80 uidq1158 */
#pragma ghs section bss = ".vx1000"			/*set the address to : 0xFEBFFB80*/
#define VX1000_BEGSECT_VXSTRUCT_C_UNDO
VX1000_STRUCT_DATA
#pragma ghs section bss = default

/* include user-defined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_ENDSECT_VXSTRUCT_C
#include "VX1000_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_ENDSECT_VXSTRUCT_C_UNDO

#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

/* Note that we were using nested section switches here (which might be unsupported by some compilers but has the    */
/* advantage of not requiring #undefs (those would violate the MISRA coding guidelines) nor VX1000_xxxSECT_2         */
/* defines (those would spoil the yyy_cfg.h file). This means that we SHOULDN'T PLACE ANY FURTHER CODE OR DATA       */
/* below (with the exception of external user code/data that explicitly shall NOT go into VX sections).              */

/* include user-defined lines with optional section pragmas to restore standard linkage of code and/or data: */
#define VX1000_ENDSECT_VXMODULE_C
#include "VX1000_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_ENDSECT_VXMODULE_C_UNDO

#if !defined(VX1000_COMPILED_FOR_SLAVECORES) /* global data have to exist only once (in shared memory) */

/* include user-defined lines with optional section pragmas to force individual linkage of EMEM header data. */
#define VX1000_BEGSECT_EMEM_HDR_C
#include "VX1000_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_BEGSECT_EMEM_HDR_C_UNDO

VX1000_EMEM_HDR_DATA

/* include user-defined lines with optional section pragmas to restore standard linkage of code and/or data: */
#define VX1000_ENDSECT_EMEM_HDR_C
#include "VX1000_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_ENDSECT_EMEM_HDR_C_UNDO

#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

