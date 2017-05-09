#include "app/framework/include/af.h"
#include "app/util/zigbee-framework/zigbee-device-common.h"

#include "Uart_Transmitter.h"
#include "halDelay.h"
#include "callback.h"
#include "AppEvent.h"
#include "device.h"

#include "ZigbeeUtility.h"

int8u HcDefaultEPt = HcDefaultEP;

//-------------------------------------Fuction---------------------------------//
/** @brief Pre ZDO Message Received
 *
 * This function passes the application an incoming ZDO message and gives the
 * appictation the opportunity to handle it. By default, this callback returns
 * FALSE indicating that the incoming ZDO message has not been handled and
 * should be handled by the Application Framework.
 *
 * @param emberNodeId   Ver.: always
 * @param apsFrame   Ver.: always
 * @param message   Ver.: always
 * @param length   Ver.: always
 */
boolean emberAfPreZDOMessageReceivedCallback(EmberNodeId emberNodeId,
                                        EmberApsFrame* apsFrame, int8u* message, int16u length) {
    if (apsFrame->clusterId == ACTIVE_ENDPOINTS_RESPONSE) {

        int8u Status;
        int8u FirstEndpointID;
        Status = message[1];
        if(Status == EMBER_SUCCESS){
            FirstEndpointID = message[5];
            HcDefaultEPt = FirstEndpointID;
            CheckConnectionFromHcOkCallback();
        }
        return FALSE;
    }
    else if (apsFrame->clusterId == SIMPLE_DESCRIPTOR_RESPONSE) {
        return FALSE;
    }
    else if (apsFrame->clusterId == LEAVE_REQUEST) {
        return FALSE;
    }
    return FALSE;
}

void SendGlobalServerToClientReadAttributeResponse(int8u Endpoint,
        EmberAfClusterId clusterId, EmberAfAttributeId attributeId,
        int8u* value, int8u dataType) {
    EmberAttributeResponse_str AttributeResponse;
    unsigned int AttributeResponseLength;
    AttributeResponse.AttributeID = attributeId;  // on-off
    AttributeResponse.Status = 0x00;   // success
    AttributeResponse.DataType = dataType; //bool
    memcpy(AttributeResponse.Value, value, emberAfGetDataSize(dataType));
    AttributeResponseLength = sizeof(AttributeResponse.AttributeID)
            + sizeof(AttributeResponse.Status)
            + sizeof(AttributeResponse.DataType) + emberAfGetDataSize(dataType);

    emberAfFillCommandGlobalServerToClientReadAttributesResponse(clusterId,
            &AttributeResponse, AttributeResponseLength);
    emberAfSetCommandEndpoints(Endpoint, HcDefaultEPt);
    emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);
}

void SendViaBindingTable(int8u endpoint, EmberAfClusterId clusterId,
        EmberAfAttributeId attributeId, int8u* value, int8u dataType) {

    int8u i;
    EmberBindingTableEntry result;
    EmberStatus bindStatus;
    int16u NormalTransitionTime = 0xFFFF;

    for (i = 0; i < EMBER_BINDING_TABLE_SIZE; i++) {
        bindStatus = emberGetBinding(i, &result);
        if (bindStatus == EMBER_SUCCESS) {
            if (result.type > EMBER_MULTICAST_BINDING) {
                result.type = 4;  // last entry in the string list above
            }
            if (result.type != EMBER_UNUSED_BINDING) {
                if (result.local == endpoint) {
                    if (clusterId == ZCL_ON_OFF_CLUSTER_ID) {
                        if (attributeId == ZCL_ON_OFF_ATTRIBUTE_ID) {
                            if (value[0] == 1) {
                                emberAfFillCommandOnOffClusterOn();
                            }
                            else {
                                emberAfFillCommandOnOffClusterOff();
                            }
                        }
                    }
                    else if (clusterId == ZCL_LEVEL_CONTROL_CLUSTER_ID) {
                        if (attributeId == ZCL_CURRENT_LEVEL_ATTRIBUTE_ID) {
                            emberAfFillCommandLevelControlClusterMoveToLevel(
                                    value[0], NormalTransitionTime);
                        }
                    }
                    emberAfSendCommandUnicast(EMBER_OUTGOING_VIA_BINDING, i); // Send Bind
                }
            }
        }
    }
}

void GetHcActiveEndPoint(void) {
    emberActiveEndpointsRequest(0x000, EMBER_AF_DEFAULT_APS_OPTIONS | 0x0040);
}

void SendBasicReadModelAttributeResponse(void){
        EmberAttributeResponse_str AttributeResponse;
    unsigned int AttributeResponseLength;
    uint8_t value[64] = {ModelId};
    AttributeResponse.AttributeID = ZCL_MODEL_IDENTIFIER_ATTRIBUTE_ID;  // on-off
    AttributeResponse.Status = 0x00;   // success
    AttributeResponse.DataType = ZCL_CHAR_STRING_ATTRIBUTE_TYPE; //bool
    memcpy(AttributeResponse.Value, value, ModelLength);
    AttributeResponseLength = sizeof(AttributeResponse.AttributeID)
            + sizeof(AttributeResponse.Status)
            + sizeof(AttributeResponse.DataType) + ModelLength;

    emberAfFillCommandGlobalServerToClientReadAttributesResponse(ZCL_BASIC_CLUSTER_ID,
            &AttributeResponse, AttributeResponseLength);
    emberAfSetCommandEndpoints(1, HcDefaultEPt);
    emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);
}

/** @brief On/off Cluster Server Attribute Changed
 *
 * Server Attribute Changed
 *
 * @param endpoint Endpoint that is being initialized  Ver.: always
 * @param attributeId Attribute that changed  Ver.: always
 */
#define OnOffAttributeLengthMax		4

/*
 void TestSendCustomCmd(void){
 
 emberAfFillExternalBuffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                             | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER\
                             | ZCL_DISABLE_DEFAULT_RESPONSE_MASK), \
                            ZCL_BASIC_CLUSTER_ID, \
                            0x05, \
                            "uu", \
                            0x22, \
                            0x33 \
                            );
 emberAfSetCommandEndpoints(1,HcDefaultEPt);
 emberAfSendCommandUnicast(EMBER_OUTGOING_DIRECT, 0x0000);
 
 }
 */

void emberAfOnOffClusterServerAttributeChangedCallback(int8u endpoint,
        EmberAfAttributeId attributeId) {

}

void emberAfLevelControlClusterServerAttributeChangedCallback(int8u endpoint,
        EmberAfAttributeId attributeId) {

}

//void emberAfLmDevOptServerAttributeChangedCallback(uint8_t endpoint,
//		EmberAfAttributeId attributeId) {
//	if (endpoint == ConfigToolEpt) {
//		switch (attributeId) {
//		case ZCL_REMAIN_STATE_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_LED_INDICATE_R_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_LED_INDICATE_G_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_LED_INDICATE_B_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_GLASS_TYPE_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_LOCKED_DEVICE_ATTRIBUTE_ID:
//
//			break;
//
//		case ZCL_OUTPUT_PAIR_ATTRIBUTE_ID:
//
//			break;
//
//		default:
//
//			break;
//		}
//	}
//}













