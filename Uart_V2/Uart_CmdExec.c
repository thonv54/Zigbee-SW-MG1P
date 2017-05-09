

#include "app/framework/include/af.h"
#include "device.h"
#include "halDelay.h"
#include "ZigbeeUtility.h"
#include "CommonLed.h"
#include "CommonButton.h"
#include "Uart_Transmitter.h"
#include "AppEvent.h"
#include "Uart_CmdExec.h"

#define NumberOfSwitch          4






/**
 * @func   MC_ListTotalDevice
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void MC_ListTotalDevice(int8u *data){
    // khong can kiem tra list device, coi nhu day la ban tin kiem tra ket noi giua mc va zigbee
    // inactive event kiem tra
    emberEventControlSetInactive(CheckMCReadyEventControl);
    // goi callback nhay led - tao mang
    McReadyCallback();
}

/**
 * @func   MC_UpdateStatusOfDevice
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void MC_UpdateStatusOfDevice(int8u *data, int8u length){
    us_DeviceControl_Str DeviceControlVal;
    int8u RelayState;
    int8u DimmerLevel;
    int8u CurtainLevel;
    int8u FanLevel;
    int8u OnOffValue;
    *data ++;

    DeviceControlVal.DeviceNo = 2*(*data++) - 1;
    DeviceControlVal.DeviceType = *data++;
    DeviceControlVal.DeviceData[0] = *data++;
    DeviceControlVal.DeviceData[1] = *data++;
    
    switch(DeviceControlVal.DeviceType){
        case SwitchTypeDevice:
            RelayState = DeviceControlVal.DeviceData[0];
            switch (RelayState){
            case RelayOn:
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo, ZCL_ON_OFF_CLUSTER_ID,
                    ZCL_ON_OFF_ATTRIBUTE_ID, &RelayState, sizeof(RelayState));
                break;
            case RelayOff:
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo, ZCL_ON_OFF_CLUSTER_ID,
                        ZCL_ON_OFF_ATTRIBUTE_ID, &RelayState, sizeof(RelayState));
                break;
            default:
                break;
            }
//                        //      Send to Bind Device
//            SendViaBindingTable(DeviceControlVal.DeviceNo, ZCL_ON_OFF_CLUSTER_ID,
//                    ZCL_ON_OFF_ATTRIBUTE_ID, (int8u*) &RelayState,
//                    ZCL_BOOLEAN_ATTRIBUTE_TYPE);

//      Send On-Off AttributeResponse, Zipato stupid update :D-----------------------------//

            SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                    (int8u*) &RelayState, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
        break;
        case DimmerTypeDevice:
            DimmerLevel = DeviceControlVal.DeviceData[0];
    //      write attribute
            emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                    &DimmerLevel, sizeof(DimmerLevel));
            
            if (DimmerLevel == 0) {
                OnOffValue = 0;
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                        ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                        sizeof(OnOffValue));
            }
            else {
                OnOffValue = 1;
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                        ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                        sizeof(OnOffValue));
            }

            //      Send to Bind Device
//            SendViaBindingTable(DimmerInClusterEndpoint,
//                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
//                    (int8u*) &DimmerLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
            //          Send Level AttributeResponse, Zipato stupid update :D-----------------------------//
            SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                    (int8u*) &DimmerLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
            //      Send On-Off AttributeResponse, Zipato stupid update :D-------------------------------//
            SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                    (int8u*) &OnOffValue, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
        break;
        case FanTypeDevice:
            FanLevel = DeviceControlVal.DeviceData[0];
    //      write attribute
            emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                    &FanLevel, sizeof(FanLevel));
            
            if (FanLevel == 0) {
                OnOffValue = 0;
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                        ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                        sizeof(OnOffValue));
            }
            else {
                OnOffValue = 1;
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                        ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                        sizeof(OnOffValue));
            }

            //      Send to Bind Device
//            SendViaBindingTable(DimmerInClusterEndpoint,
//                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
//                    (int8u*) &DimmerLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
            //          Send Level AttributeResponse, Zipato stupid update :D-----------------------------//
            SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                    (int8u*) &FanLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
            //      Send On-Off AttributeResponse, Zipato stupid update :D-------------------------------//
            SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                    (int8u*) &OnOffValue, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
        break;
        
        case CurtainTypeDevice:
            if(DeviceControlVal.DeviceData[0] == CurtainControlId_Run){
                CurtainLevel = DeviceControlVal.DeviceData[1];
        //      write attribute
                emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                        ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                        &CurtainLevel, sizeof(CurtainLevel));

                if (CurtainLevel == 0) {
                    OnOffValue = 0;
                    emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                            ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                            sizeof(OnOffValue));
                }
                else {
                    OnOffValue = 1;
                    emberAfWriteServerAttribute(DeviceControlVal.DeviceNo,
                            ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &OnOffValue,
                            sizeof(OnOffValue));
                }
                //      Send to Bind Device
    //            SendViaBindingTable(DimmerInClusterEndpoint,
    //                    ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
    //                    (int8u*) &DimmerLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
                //          Send Level AttributeResponse, Zipato stupid update :D-----------------------------//
                SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                        ZCL_LEVEL_CONTROL_CLUSTER_ID, ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                        (int8u*) &CurtainLevel, ZCL_INT8U_ATTRIBUTE_TYPE);
                //      Send On-Off AttributeResponse, Zipato stupid update :D-------------------------------//
                SendGlobalServerToClientReadAttributeResponse(DeviceControlVal.DeviceNo,
                        ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                        (int8u*) &OnOffValue, ZCL_BOOLEAN_ATTRIBUTE_TYPE);
            }
        break;
    default:
        break;
    }
}

/**
 * @func   MC_TouchButtonHold
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */

void MC_TouchButtonHold(int8u *data){
    int8u ButtonId;
    int8u ButtonHoldType;
    *data ++;
    ButtonId = *data++;
    ButtonHoldType = *data++;

    switch (ButtonHoldType) {
    case ButtonUnpress:
        CallButtonRelease(ButtonId);
        break;
    case ButtonShortHold:
        CallButtonShortHold(ButtonId);
        break;
    case ButtonLongHold:
        CallButtonLongHold(ButtonId);
        break;
    case ButtonResetHold:
        break;
    default:
        break;    
    }
}

/**
 * @func   MC_McUartError
 *
 * @brief  
 *
 * @param  None
 *
 * @retval None
 */
void MC_McUartError(int8u *data){
    
}



//-----------------------------***************--------------------------//


