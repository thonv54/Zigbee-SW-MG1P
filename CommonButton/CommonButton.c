//-----------------------------Khai bao thu vien---------------------//

#include "app/framework/include/af.h"
#include "app/util/zigbee-framework/zigbee-device-common.h"

#include "halDelay.h"
#include "CommonLed.h"
#include "Uart_Transmitter.h"
#include "AppEvent.h"
#include "CommonButton.h"


int16u ReleaseLongHoldTime = 0;
int8u ButtonLongHoldFlag;

#define     beButtonPress2Time  CallButtonShortHold
#define     beButtonPress3Time  CallButtonLongHold
#define     beButtonPress       CallButtonPress
#define     beButtonRealease    CallButtonRelease

void CallButtonLongHold(int8u ButtonNumber) {
    EmberNetworkStatus NetworkStatus;
    NetworkStatus = emberAfNetworkState();

    UartSendPinkLed(0x0F);
    ReleaseLongHoldTime = (int16u) halCommonGetInt32uMillisecondTick();
    ButtonLongHoldFlag = 1;

}
void CallButtonShortHold(int8u ButtonNumber) {
//      Creat Simple Bind Request ButtonNumber is the Endpoint Bind
//      Send Pink State to Led
//      When Bind done clear Led by func ZDO response Bind Success call back.
//      emberAfSendEndDeviceBind(ButtonNumber);
//      UartSendSpecialLedNumber(ButtonNumber, PinkState);
}
void CallButtonRelease(int8u ButtonNumber) {
    if (ButtonLongHoldFlag == 1) {
        if (CommonGetDurationTime(ReleaseLongHoldTime) < 1000) {
            //neu thiet bi trong mang - xoa mang
            int8u NetworkStatus = emberAfNetworkState();
            if(NetworkStatus == EMBER_JOINED_NETWORK){
                //send leave response
                int8u contents[ZDO_MESSAGE_OVERHEAD + 1];
                contents[0] = 0x00;

               (void)emberSendZigDevRequest(0x0000,
                                LEAVE_RESPONSE,
                                EMBER_AF_DEFAULT_APS_OPTIONS,
                                contents,
                                sizeof(contents));  
                // leave
                emberLeaveNetwork();
                emberClearBindingTable();
            }
            // neu thiet bi khong trong mang - reset luon
            else{            
                UartSendBlinkLed(0xFFFF, 2);
                emberEventControlSetInactive(DeviceResetEventControl);
                emberEventControlSetDelayMS(DeviceResetEventControl,1000);
            }
        }
        else {
            UartSendRefreshAllLed();
        }
    }
    ButtonLongHoldFlag = 0;
}

