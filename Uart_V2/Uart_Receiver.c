#include "app/framework/include/af.h"

#include "Uart_CommonHeader.h"
#include "Uart_CmdExec.h"

#include "Uart_Receiver.h"

int8u UartRxDataStep = 0;
int8u UartRxPacketLength;
int8u UartRxPacketCheckXor = 0;
int8u UartRxCommandData[256] = { 0 };
int8u UartRxCurrentLength = 0;



void UartProcess(int8u *PacketCommand , int8u Length) {
    int8u UartPacketID = PacketCommand[0];

    switch (UartPacketID) {
        case ListTotalDevice:
            MC_ListTotalDevice(PacketCommand);
        break;
        case UpdateStatusOfDevice:
            MC_UpdateStatusOfDevice(PacketCommand , Length);
        break;
        case TouchButtonHold:
            MC_TouchButtonHold(PacketCommand);
        break;
        case McUartError:
            MC_McUartError(PacketCommand);
        break;
    default:
        break;
    }
}

void UartGetCommand(void) {
    int16u NumberOfByteReCeiver;
    int8u ReadSerialData[128];
    int8u ReadStatus;

    NumberOfByteReCeiver = emberSerialReadAvailable(MC_SERIAL);
    if (NumberOfByteReCeiver > 0) {
        ReadStatus = emberSerialReadData(MC_SERIAL,
                        ReadSerialData,
                        NumberOfByteReCeiver,
                        NULL);

////          emberSerialWriteData(1,&ReadSerialData,NumberOfByteReCeiver) ;
////          COM_Printf(1,"hello %d",10);
        if (ReadStatus == EMBER_SUCCESS) {
            for(int8u i = 0; i<NumberOfByteReCeiver; i++){
                switch (UartRxDataStep) {
                case 0:
                    if (ReadSerialData[i] == 0x4C) {
                        UartRxDataStep = 1;
                    }
                    else {
                        UartRxDataStep = 0;
                    }
                    break;
                case 1:
                    if (ReadSerialData[i] == 0x4D) {
                        UartRxDataStep = 2;
                    }
                    else {
                        UartRxDataStep = 0;
                    }
                    break;
                case 2:
                    UartRxPacketLength = ReadSerialData[i];
                    if (UartRxPacketLength > 40) {
                        UartRxDataStep = 0;
                    }
                    else {
                        UartRxDataStep = 3;
                    }
                    break;
                case 3:
                    if (UartRxCurrentLength < UartRxPacketLength - 1) {
                        UartRxCommandData[UartRxCurrentLength] = ReadSerialData[i];
                        UartRxCurrentLength++;
                    }
                    else {
                        int8u PacketCheckXor;
                        int8u CheckXor = 0;
                        PacketCheckXor = ReadSerialData[i];
                        {
                            for (int8u j = 0;j < UartRxPacketLength - 1; j++) {
                                CheckXor = CheckXor ^ UartRxCommandData[j];
                            }
                        }
                        if (PacketCheckXor == CheckXor) {
                            UartProcess(UartRxCommandData, UartRxPacketLength);
                        }
                        else{// neu loi check xor
                            if(UartRxCommandData[0] == 0x01){// truong hop dac biet do code MC loi phan ban tin 0x01
                                UartProcess(UartRxCommandData, UartRxPacketLength);
                            }
                        }
                        UartRxCurrentLength = 0;
                        UartRxDataStep = 0;
                    }
                    break;
                default:
                    break;

                }
            }
        }
    }
}