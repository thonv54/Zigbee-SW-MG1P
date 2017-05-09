

/*******************************************************************************
 *
 * Copyright (c) 2016
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description: 
 *
 * Author: Thonv
 *
 * Last Changed By:  $Author: thonv $
 * Revision:         $Revision: 1.0.0.0 $
 * Last Changed:     $Date: 2016-05-20 10:20:00 (Fri, 20 May 2016) $
 *
 ******************************************************************************/
#ifndef __APPEVENT_H__
#define __APPEVENT_H__

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/

#include "app/framework/include/af.h"
#include "typedefs.h"

/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define ROUTER

typedef struct {
    int16u TimesMax;
    int16u TimesCnt;
}NwkJoinEventData_str;

typedef struct{
    int16u TimeCountDown;
}DeviceResetEventData_str;
/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/
extern NwkJoinEventData_str  NwkJoinEventData;
extern EmberEventControl NwkJoinEventControl;

extern DeviceResetEventData_str  DeviceResetEventData;
extern EmberEventControl DeviceResetEventControl;

extern EmberEventControl UartSendEventControl;
extern EmberEventControl UartGetEventControl;

extern EmberEventControl SendDeviceStatusEventControl;
extern EmberEventControl SendIeeeResponseEventControl;


extern EmberEventControl CheckMCReadyEventControl;

extern EmberEventControl CheckConnectionFromHcEventControl;
extern int32u LastTimeGetConnectionFromHc;


/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/






#endif


