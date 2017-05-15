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

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "device.h"
#include "macro.h"
#include "typedefs.h"
#include "halDelay.h"
#include "app/framework/include/af.h"
#include "ZigbeeUtility.h"
#include "Uart_Transmitter.h"
#include "Uart_Receiver.h"
#include "app/util/zigbee-framework/zigbee-device-common.h"

#include "AppEvent.h"


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/
EmberEventControl NwkJoinEventControl;
NwkJoinEventData_str NwkJoinEventData;

EmberEventControl DeviceResetEventControl;
DeviceResetEventData_str DeviceResetEventData;

EmberEventControl UartSendEventControl;
EmberEventControl UartGetEventControl;
EmberEventControl SendDeviceStatusEventControl;
EmberEventControl CheckConnectionFromHcEventControl;
EmberEventControl CheckMCReadyEventControl;
EmberEventControl SendIeeeResponseEventControl;

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
void NwkJoinEventFunction(void
                          ); // Event function forward declaration
void DeviceResetEventFunction (void);
void UartSendEventFunction(void);
void UartGetEventFunction(void);
void SendDeviceStatusEventFunction(void);
void CheckConnectionFromHcEventFunction(void);
void CheckMCReadyEventFunction(void);
void SendIeeeResponseEventFunction(void);

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

/**
 * @func   NwkJoinEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void NwkJoinEventFunction(void) {
    EmberNetworkStatus NetworkStatus;

    NetworkStatus = emberAfNetworkState();
    if (NetworkStatus == EMBER_NO_NETWORK) {
        
        if ((NwkJoinEventData.TimesMax == 0xFF)
                || (NwkJoinEventData.TimesCnt < NwkJoinEventData.TimesMax)) {
            emberSetTxPowerMode(RADIO_POWER);
            emberAfStartSearchForJoinableNetwork();
            NwkJoinEventData.TimesCnt++;
            emberEventControlSetInactive(NwkJoinEventControl);
            emberEventControlSetDelayMS(NwkJoinEventControl,
                               5000 + ((int8u)halCommonGetRandom() << 5)); // 5s + random 8s
        }
    }
    else if (NetworkStatus == EMBER_JOINED_NETWORK) {
        //if the first join to network, device must be read network infomation
        GetHcActiveEndPoint();
        emberEventControlSetInactive(NwkJoinEventControl);
        // neu vao mang, gui trang thai theo chu ki 4 phut 1 lan   
        emberEventControlSetInactive(SendDeviceStatusEventControl);
        emberEventControlSetDelayQS(SendDeviceStatusEventControl,
                                 ((int8u) halCommonGetRandom() << 2));
    }
}

/**
 * @func   DeviceResetEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void DeviceResetEventFunction (void){
    halReboot();
}
/**
 * @func   UartSendEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void UartSendEventFunction(void) { 
    UartSendCommand();
    emberEventControlSetInactive(UartSendEventControl);
    emberEventControlSetDelayMS(UartSendEventControl,100); //100ms
}
/**
 * @func   UartGetCommandEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void UartGetEventFunction(void) { 
    UartGetCommand();
    emberEventControlSetInactive(UartGetEventControl);
    emberEventControlSetDelayMS(UartGetEventControl,100); //100ms
}

/**
 * @func   UartGetCommandEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void SendIeeeResponseEventFunction(void) { 

    emberEventControlSetInactive(SendIeeeResponseEventControl);
    
  /// Response: <transaction sequence number: 1>
  ///           <status:1> <EUI64:8> <node ID:2> 
  ///           <ID count:1> <start index:1> <child ID:2>*

    uint8_t contents[ZDO_MESSAGE_OVERHEAD + 15];
    uint8_t *payload = contents + ZDO_MESSAGE_OVERHEAD;
    uint8_t Mac[8];
    uint16_t Nwk;
    
    emberAfGetEui64(Mac);
    Nwk = emberAfGetNodeId();
    payload[0] = EMBER_SUCCESS;
    memcpy(&payload[1], Mac, sizeof(Mac));
    payload[9] = LO_UINT16(Nwk);
    payload[10] = HI_UINT16(Nwk);
    payload[11] = 0;
    payload[12] = 0;
    payload[13] = 0;
    payload[14] = 0;
    emberSendZigDevRequest(0x0000,
                                   NETWORK_ADDRESS_RESPONSE,
                                   EMBER_AF_DEFAULT_APS_OPTIONS,
                                   contents,
                                   sizeof (contents));
}



/**
 * @func   ControlStateDeviceFromHCCallback
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
     
void ControlStateDeviceFromHCCallback(void){
    emberEventControlSetInactive(SendDeviceStatusEventControl);
    emberEventControlSetDelayMS(SendDeviceStatusEventControl,halCommonGetRandom()<<1); // random2 phut
}

     /**
 * @func   SendDeviceStatusEventFunction
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */

int8u ButtonSendCnt =0;
void SendDeviceStatusEventFunction(void) { 
    emberEventControlSetInactive(SendDeviceStatusEventControl);
    emberEventControlSetDelayMinutes(SendDeviceStatusEventControl, 15);
#ifdef SWITCH_TYPE
    ButtonSendCnt++;
    if(ButtonSendCnt == NUMBER_BUTTON){
        ButtonSendCnt = 0;
    }
    int8u CurrentState;
    int8u Endpoint;
    Endpoint = 2*ButtonSendCnt+1;
    emberAfReadServerAttribute(Endpoint,
                                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                                    &CurrentState, sizeof(CurrentState));
    SendGlobalServerToClientReadAttributeResponse(Endpoint,
            ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
            (int8u*) &CurrentState, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
#endif
    #ifdef LEVEL_TYPE
    ButtonSendCnt++;
    if(ButtonSendCnt == NUMBER_LEVEL){
        ButtonSendCnt = 0;
    }
    int8u CurrentOnOffState;
    int8u CurrentLevelState;
    int8u Endpoint;
    Endpoint = 2*ButtonSendCnt+1;
    emberAfReadServerAttribute(Endpoint,
                                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                                    &CurrentOnOffState, sizeof(CurrentOnOffState));
    SendGlobalServerToClientReadAttributeResponse(Endpoint,
            ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
            (int8u*) &CurrentOnOffState, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
    
    emberAfReadServerAttribute(Endpoint,
                                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                                    &CurrentLevelState, sizeof(CurrentLevelState));
    SendGlobalServerToClientReadAttributeResponse(Endpoint,
            ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
            (int8u*) &CurrentLevelState, ZCL_INT8U_ATTRIBUTE_TYPE);
#endif
}
int8u CheckConnectionCnt = 0;
int8u CheckConnectionErrorCnt = 0;
int8u CheckInStartUpFlag = 0;
void CheckConnectionFromHcEventFunction(void) {
    // neu thoi gian khong nhan duoc ban tin MTORR tu HC lon hon 10 phut
    // reset thiet bi, khong xoa bat ki thong tin gi
    GetHcActiveEndPoint();
    CheckConnectionErrorCnt ++;
    if(CheckInStartUpFlag == 0){
        // neu luc moi khoi dong, kiem tra 5s 1 lan
        emberEventControlSetInactive(CheckConnectionFromHcEventControl);
        emberEventControlSetDelayMS(CheckConnectionFromHcEventControl,5000);
        CheckConnectionCnt++;
        if(CheckConnectionCnt == 3){
            CheckConnectionCnt = 0;
            CheckInStartUpFlag = 1;
            
            if(CheckConnectionErrorCnt == 3){
                // neu khi khoi dong qua trinh check bi loi
                // cho nhay den, sau do van cho chay tiep
                UartSendSpecialLedControl(0xFF, _84_cmd_BlinkBlue, 3 , _84_cmd_RefreshLed);
            }
            else{
                // neu khi khoi dong qua trinh check khong bi loi
                // cho nhay den, sau do van cho chay tiep
               UartSendSpecialLedControl(0xFF, _84_cmd_BlinkPink, 3 , _84_cmd_RefreshLed); 
            }
            CheckConnectionErrorCnt = 0;
        }
    }else{
        // neu sau qua trinh khoi dong check bi loi
        if(CheckConnectionErrorCnt == 3){
        // cho khoi dong lai thiet bi nhung khong xoa gi
            emberEventControlSetInactive(DeviceResetEventControl);
            emberEventControlSetDelayMS(DeviceResetEventControl,1000);    
        }
        // neu sau khi khoi dong xong, kiem tra 10 phut 1 lan
        emberEventControlSetInactive(CheckConnectionFromHcEventControl);
        emberEventControlSetDelayMinutes(CheckConnectionFromHcEventControl,10); 
        // gui thong tin trang thai 15p 1 lan
        emberEventControlSetInactive(SendDeviceStatusEventControl);
        emberEventControlSetDelayMS(SendDeviceStatusEventControl,halCommonGetRandom()<<1); // random2 phut
    }  
}
void CheckConnectionFromHcOkCallback(void){
    // neu check ok
    CheckConnectionErrorCnt -- ;
}

void CheckMCReadyEventFunction(void){
    // gui kiem tra thong tin MC
    UartSendGetListTotalDevice();
    // set event active delay 0.5s cho toi khi co tra loi
    emberEventControlSetInactive(CheckMCReadyEventControl);
    emberEventControlSetDelayMS(CheckMCReadyEventControl,500);
}
    
    
    
    
    
    
