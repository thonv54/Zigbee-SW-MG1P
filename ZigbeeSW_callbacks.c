//

// This callback file is created for your convenience. You may add application
// code to this file. If you regenerate this file over a previous version, the
// previous version will be overwritten and any code you have added will be
// lost.

#include "Device.h"
#include "app/framework/include/af.h"
#include "AppEvent.h"
#include "Uart_Receiver.h"
#include "Uart_Transmitter.h"
#include "app/framework/plugin/reporting/reporting.h"
#include "ZigbeeUtility.h"
#include "halDelay.h"


/** @brief Main Init
 *
 * This function is called from the application's main function. It gives the
 * application a chance to do any initialization required at system startup. Any
 * code that you would normally put into the top of the application's main()
 * routine should be put into this function. This is called before the clusters,
 * plugins, and the network are initialized so some functionality is not yet
 * available.
 Note: No callback in the Application Framework is
 * associated with resource cleanup. If you are implementing your application on
 * a Unix host where resource cleanup is a consideration, we expect that you
 * will use the standard Posix system calls, including the use of atexit() and
 * handlers for signals such as SIGTERM, SIGINT, SIGCHLD, SIGPIPE and so on. If
 * you use the signal() function to register your signal handler, please mind
 * the returned value which may be an Application Framework function. If the
 * return value is non-null, please make sure that you call the returned
 * function from your handler to avoid negating the resource cleanup of the
 * Application Framework itself.
 *
 */
void emberAfMainInitCallback(void) {
    //always send and check MC ready after reset
    emberSerialInit(MC_SERIAL, MC_BAUD_RATE, PARITY_NONE, 1);
    emberEventControlSetActive(UartSendEventControl);
    emberEventControlSetActive(UartGetEventControl);
    emberEventControlSetActive(CheckMCReadyEventControl);
}

/** @brief Main Tick
 *
 * Whenever main application tick is called, this callback will be called at the
 * end of the main tick execution.
 *
 */
void emberAfMainTickCallback(void) {

}

/** @brief Stack Status
 *
 * This function is called by the application framework from the stack status
 * handler.  This callbacks provides applications an opportunity to be notified
 * of changes to the stack status and take appropriate action.  The return code
 * from this callback is ignored by the framework.  The framework will always
 * process the stack status after the callback returns.
 *
 * @param status   Ver.: always
 */
int8u StatusCallbackReadyState = 0;
#define Inrunning 1
bool emberAfStackStatusCallback(EmberStatus status)
{

// neu callback nay xay ra khong phai khi khoi dong
    if(StatusCallbackReadyState == Inrunning){
        if(status == EMBER_NETWORK_DOWN){
            UartSendBlinkLed(0xFFFF, 2);
            emberEventControlSetInactive(DeviceResetEventControl);
            emberEventControlSetDelayMS(DeviceResetEventControl,1000);
        }
        else if(status == EMBER_NETWORK_UP){
           UartSendBlinkLed(0xFFFF, 3);
           // gui ngay thong tin model cua thiet bi, du sao thi HC cung hoi nen khong can gui cung duoc
            SendBasicReadModelAttributeResponse();
        }
    }
    return false;
}



void McReadyCallback(void){
    EmberNetworkStatus NetworkStatus;
    UartSendBlinkLed(0x0F, 2);
    //trang thai khoi dong da xong
    StatusCallbackReadyState = Inrunning;
    NetworkStatus = emberAfNetworkState();
    if (NetworkStatus == EMBER_JOINED_NETWORK) {
        // neu da o trong mang, kiem tra ket noi toi HC
        emberEventControlSetInactive(CheckConnectionFromHcEventControl);
        emberEventControlSetDelayMS(CheckConnectionFromHcEventControl,
                                    30 + halCommonGetRandom()>>1); // 30s + random 30s
    }
    else {
        UartSendSpecialLedControl(0xFF, _84_cmd_BlinkRed, 3 , _84_cmd_RefreshLed);
        NwkJoinEventData.TimesMax = 0xFF;
        NwkJoinEventData.TimesCnt = 0;
        emberEventControlSetInactive(NwkJoinEventControl);
        emberEventControlSetDelayMS(NwkJoinEventControl,
                                   ((int8u) halCommonGetRandom() << 5)); // 5s + random 8s
    }
}
#if 1

void emberAfOnOffClusterServerCommandParseCallBack(int8u HandledStatus, EmberAfClusterCommand *cmd){
//  User Controller Command
    if (HandledStatus == EMBER_ZCL_STATUS_SUCCESS) {
        int8u CurrentState;
        emberAfReadServerAttribute(cmd->apsFrame->destinationEndpoint,
                                    ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID,
                                    &CurrentState, sizeof(CurrentState));
    // nhan lenh dieu khien tu HC
    ControlStateDeviceFromHCCallback();
#ifdef SWITCH_TYPE

        UartSendSwitchControlNumber((((cmd->apsFrame->destinationEndpoint) >> 1) + 1),
                            CurrentState);
#endif // end
#ifdef LEVEL_TYPE
        int8u level;
        if(CurrentState == 1){
            level = 255;
        }
        else{
            level = 0;
        }

        emberAfWriteServerAttribute(cmd->apsFrame->destinationEndpoint,
                    ZCL_LEVEL_CONTROL_CLUSTER_ID,
                    ZCL_CURRENT_LEVEL_ATTRIBUTE_ID,
                    &level,
                    sizeof (level));
        int8u DeviceNo =   ((cmd->apsFrame->destinationEndpoint >> 1)+1);
        UartSendLevel(DeviceNo,level);
#endif
    }
}

#endif
