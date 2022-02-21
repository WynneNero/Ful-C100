#include "define.h"
#include "sw_timer.h"

#define SW_ONE_TICK_MS     5
#define MAX_U32  0x100000000 //0xffffffff
#define   SWTMR_RESERVE_NODE     0x00

struct SWTMR_NODE_ITEM swTmrNode[SWTMR_NODE_COUNT];
struct swTmrMgr  m_swTmrMgr;

void SwTmrMgr_Open(void)
{
    U8 i = 0;
    for(i=0; i<SWTMR_NODE_COUNT; i++)
    {
        swTmrNode[i].callbackFunc = NULL;
        swTmrNode[i].callbackParam = NULL;
        swTmrNode[i].flags = SWTMR_MODE_UNUSED;
        swTmrNode[i].timeoutTenths = 0;
        swTmrNode[i].timeToExpiry = 0;
    }
    m_swTmrMgr.swTmrOpenFlag = 1;
    m_swTmrMgr.sysTickForSwTmr = 0;

}

void SwTmrMgr_Close(void)
{
    U8 i = 0;
    for(i=0; i<SWTMR_NODE_COUNT; i++)
    {
        swTmrNode[i].flags = SWTMR_MODE_UNUSED;
    }
    m_swTmrMgr.swTmrOpenFlag = 0;
    m_swTmrMgr.sysTickForSwTmr = 0;
}


SWTMR_NODE_HANDLE SwTmrMgr_Start(SW_TMR_HDL hdl,U32 timeoutTenthMs, void(*callbackFunc)(void *), void *callbackArg, U8 isLoop)
{
    U64 timeExpiry = 0;

    if(SW_ONE_TICK_MS > timeoutTenthMs)
    {
        timeoutTenthMs = SW_ONE_TICK_MS;
    }

    timeoutTenthMs = timeoutTenthMs/SW_ONE_TICK_MS;

    if(isLoop)
    {
        swTmrNode[hdl].flags = SWTMR_MODE_PERIODIC;
    }
    else
    {
        swTmrNode[hdl].flags = SWTMR_MODE_ONESHOT;
    }
    swTmrNode[hdl].timeoutTenths = timeoutTenthMs;
    timeExpiry = (U64)timeoutTenthMs+m_swTmrMgr.sysTickForSwTmr;
    
    if(timeExpiry >= MAX_U32)
    {
        swTmrNode[hdl].timeToExpiry = (U32)(timeExpiry - MAX_U32);
    }
    else
    {
        swTmrNode[hdl].timeToExpiry = timeoutTenthMs+m_swTmrMgr.sysTickForSwTmr;
    }
    swTmrNode[hdl].callbackParam = callbackArg;
    swTmrNode[hdl].callbackFunc = callbackFunc;
	return hdl;
}

void SwTmrMgr_Stop(SW_TMR_HDL TimerHandle)
{
    swTmrNode[TimerHandle].flags = SWTMR_MODE_UNUSED;
    swTmrNode[TimerHandle].callbackFunc = NULL;
}


BOOL SwTmrMgr_TimerActive(SW_TMR_HDL tmrHdl)
{
    return (SWTMR_MODE_UNUSED != swTmrNode[tmrHdl].flags);
}
void SwTmrMgr_Proc(void)
{
    U8 i = 0;
    U64 timeExpiry = 0;
    if(m_swTmrMgr.swTmrOpenFlag)
    {
        m_swTmrMgr.sysTickForSwTmr++;
        for(i=SWTMR_RESERVE_NODE+1; i<SWTMR_NODE_COUNT; i++)
        {
            if(SWTMR_MODE_UNUSED != swTmrNode[i].flags)
            {
                if(m_swTmrMgr.sysTickForSwTmr == swTmrNode[i].timeToExpiry)
                {
                    if(SWTMR_MODE_PERIODIC == swTmrNode[i].flags)
                    {
                        timeExpiry = (U64)swTmrNode[i].timeoutTenths+m_swTmrMgr.sysTickForSwTmr;
                        if(timeExpiry >= MAX_U32)
                        {
                            swTmrNode[i].timeToExpiry = (U32)(timeExpiry - MAX_U32);
                        }
                        else
                        {
                            swTmrNode[i].timeToExpiry = timeExpiry;
                        }
                    }
                    else
                    {
                        swTmrNode[i].flags = SWTMR_MODE_UNUSED;
                    }

                    if(NULL != swTmrNode[i].callbackFunc)
                    {
                        swTmrNode[i].callbackFunc(swTmrNode[i].callbackParam);
                    }
                    else
                    {
                        swTmrNode[i].flags = SWTMR_MODE_UNUSED;
                    }
                }
            }
        }
    }
}




