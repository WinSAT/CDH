/*=======================================================================================
** File Name:  winsat_msg.h
**
** Title:  Message Definition Header File for WINSAT Application
**
** $Author:    unk
** $Revision: 1.1 $
** $Date:      2019-04-19
**
** Purpose:  To define WINSAT's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2019-04-19 | unk | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _WINSAT_MSG_H_
#define _WINSAT_MSG_H_

/*
** Pragmas
*/

/*
** Include Files
*/



/*
** Local Defines
*/

/*
** WINSAT command codes
*/
#define WINSAT_NOOP_CC                 0
#define WINSAT_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} WINSAT_HkTlm_t;


#endif /* _WINSAT_MSG_H_ */

/*=======================================================================================
** End of file winsat_msg.h
**=====================================================================================*/
    