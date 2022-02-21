/***********************************************************************
 *
 * MODULE NAME:
 * DESCRIPTION:   simple software timer
 * AUTHOR:     huangxiaoqing
 * DATE: 2015.10.25
 *
 ***********************************************************************/
#ifndef __SOFT_TIMER_MGR_H__
#define __SOFT_TIMER_MGR_H__

#define SWTMR_NODE_COUNT  SW_TMR_MAX
#define   SWTMR_INVALID_NODE      0

typedef U32 SWTMR_NODE_HANDLE;
typedef enum
{
    SWTMR_INVALID_NODE_HDL = SWTMR_INVALID_NODE,
    DEBUG_TEST_TMR, 
    PDC_DETECT_TMR,
    PDC_ALERT_CONTINUE_TMR,
    PDC_FUNCTION_STATUS_UPDATE_TMR,
    RADAR_POWER_CTRL_TMR,
    GEAR_DETECT_TMR,
    USS_SELF_DETECT_WARN_TMR,
    USS_CLR_BLIND_LOCK_TMR,
    SW_TMR_MAX   
}SW_TMR_HDL;

enum
{
    SWTMR_MODE_UNUSED   = 0,
    SWTMR_MODE_ONESHOT  = 1,
    SWTMR_MODE_PERIODIC = 2,

};

struct swTmrMgr
{
    U32 sysTickForSwTmr;
    U8   swTmrOpenFlag;
};

struct SWTMR_NODE_ITEM
{
    U8 flags;
    U32 timeoutTenths;
    U32 timeToExpiry;
    void (*callbackFunc)(void *);
    void *callbackParam;
};

void SwTmrMgr_Open(void);
void SwTmrMgr_Close(void);

SWTMR_NODE_HANDLE SwTmrMgr_Start(SW_TMR_HDL hdl,U32 timeoutTenths, void(*callbackFunc)(void *), void *callbackArg, U8 isLoop);
void SwTmrMgr_Stop(SW_TMR_HDL TimerHandle);
void SwTmrMgr_Proc(void);
BOOL SwTmrMgr_TimerActive(SW_TMR_HDL tmrHdl);


#endif

