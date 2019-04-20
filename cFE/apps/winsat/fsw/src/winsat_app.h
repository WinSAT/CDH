/*=======================================================================================
** File Name:  winsat_app.h
**
** Title:  Header File for WINSAT Application
**
** $Author:    unk
** $Revision: 1.1 $
** $Date:      2019-04-19
**
** Purpose:  To define WINSAT's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2019-04-19 | unk | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _WINSAT_APP_H_
#define _WINSAT_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "winsat_platform_cfg.h"
#include "winsat_mission_cfg.h"
#include "winsat_private_ids.h"
#include "winsat_private_types.h"
#include "winsat_perfids.h"
#include "winsat_msgids.h"
#include "winsat_msg.h"



/*
** Local Defines
*/
#define WINSAT_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[WINSAT_EVT_CNT];

    /* CFE scheduling pipe */
    CFE_SB_PipeId_t  SchPipeId; 
    uint16           usSchPipeDepth;
    char             cSchPipeName[OS_MAX_API_NAME];

    /* CFE command pipe */
    CFE_SB_PipeId_t  CmdPipeId;
    uint16           usCmdPipeDepth;
    char             cCmdPipeName[OS_MAX_API_NAME];
    
    /* CFE telemetry pipe */
    CFE_SB_PipeId_t  TlmPipeId;
    uint16           usTlmPipeDepth;
    char             cTlmPipeName[OS_MAX_API_NAME];

    /* Task-related */
    uint32  uiRunStatus;
    
    /* Input data - from I/O devices or subscribed from other apps' output data.
       Data structure should be defined in winsat/fsw/src/winsat_private_types.h */
    WINSAT_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in winsat/fsw/src/winsat_private_types.h */
    WINSAT_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in winsat/fsw/src/winsat_msg.h */
    WINSAT_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} WINSAT_AppData_t;

/*
** External Global Variables
*/

/*
** Global Variables
*/

/*
** Local Variables
*/

/*
** Local Function Prototypes
*/
int32  WINSAT_InitApp(void);
int32  WINSAT_InitEvent(void);
int32  WINSAT_InitData(void);
int32  WINSAT_InitPipe(void);

void  WINSAT_AppMain(void);

void  WINSAT_CleanupCallback(void);

int32  WINSAT_RcvMsg(int32 iBlocking);

void  WINSAT_ProcessNewData(void);
void  WINSAT_ProcessNewCmds(void);
void  WINSAT_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  WINSAT_ReportHousekeeping(void);
void  WINSAT_SendOutData(void);

boolean  WINSAT_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _WINSAT_APP_H_ */

/*=======================================================================================
** End of file winsat_app.h
**=====================================================================================*/
    