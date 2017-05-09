


#include "app/framework/include/af.h"
#include "halDelay.h"






void CommonSetLed(int8u LedNumber){

	switch (LedNumber){
		case 1: halSetLed(BOARDLED0);
			break;
		case 2: halSetLed(BOARDLED1);
			break;
		case 3: halSetLed(BOARDLED2);
			break;
		default:
			break;
	}
}

void CommonClearLed(int8u LedNumber){

	switch (LedNumber){
		case 1: halClearLed(BOARDLED0);
			break;
		case 2: halClearLed(BOARDLED1);
			break;
		case 3: halClearLed(BOARDLED2);
			break;
		default:
			break;
	}
}

void CommonToggleLed(int8u LedNumber){

	switch (LedNumber){
		case 1: halToggleLed(BOARDLED0);
			break;
		case 2: halToggleLed(BOARDLED1);
			break;
		case 3: halToggleLed(BOARDLED2);
			break;
		default:
			break;
	}
}
void CommonLedRefresh(void){
	EmberAfStatus readStatus;
	int8u LedStatus;
	int8u i;
	for(i=1;i<4;i++){
		readStatus = emberAfReadServerAttribute(i,
			ZCL_ON_OFF_CLUSTER_ID, ZCL_ON_OFF_ATTRIBUTE_ID, &LedStatus, sizeof(LedStatus));
		if(readStatus == EMBER_ZCL_STATUS_SUCCESS){
			if(LedStatus == 1){
				CommonSetLed(i);
			}
			else{
				CommonClearLed(i);
			}
		}
	}
}