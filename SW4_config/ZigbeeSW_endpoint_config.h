// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef __AF_ENDPOINT_CONFIG__
#define __AF_ENDPOINT_CONFIG__


// Fixed number of defined endpoints
#define FIXED_ENDPOINT_COUNT (8)


// Generated defaults
#if BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
8,'L','u','m','i',' ','R','&','D',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* 0,Default value: Basic,manufacturer name */, \
6,'L','M','-','S','Z','4',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* 33,Default value: Basic,model identifier */, \
  }
#else // ! BIGENDIAN_CPU
#define GENERATED_DEFAULTS { \
8,'L','u','m','i',' ','R','&','D',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* 0,Default value: Basic,manufacturer name */, \
6,'L','M','-','S','Z','4',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* 33,Default value: Basic,model identifier */, \
  }
#endif // BIGENDIAN_CPU


// MinMax defaults
#define GENERATED_MIN_MAX_DEFAULTS { \
    { \
      (uint8_t*)0x02, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)1, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)1, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)1, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)0x0000, \
      (uint8_t*)0x0000, \
      (uint8_t*)0xFFFF \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0x80 \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0xFF \
    }, \
    { \
      (uint8_t*)0x0000, \
      (uint8_t*)0x0000, \
      (uint8_t*)0xFFF7 \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0x01 \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0x80 \
    }, \
    { \
      (uint8_t*)0x00, \
      (uint8_t*)0x00, \
      (uint8_t*)0x01 \
    }, \
  }


// Generated attributes
#define GENERATED_ATTRIBUTES { \
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(minMaxDefaults[0]) } }, /* 0 / Basic / ZCL version*/\
    { 0x0001, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_TOKENIZE|ATTRIBUTE_MASK_MIN_MAX|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(minMaxDefaults[1]) } }, /* 1 / Basic / application version*/\
    { 0x0002, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_TOKENIZE|ATTRIBUTE_MASK_MIN_MAX|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(minMaxDefaults[2]) } }, /* 2 / Basic / stack version*/\
    { 0x0003, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_TOKENIZE|ATTRIBUTE_MASK_MIN_MAX|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(minMaxDefaults[3]) } }, /* 3 / Basic / hardware version*/\
    { 0x0004, ZCL_CHAR_STRING_ATTRIBUTE_TYPE, 33, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(generatedDefaults[0]) } }, /* 4 / Basic / manufacturer name*/\
    { 0x0005, ZCL_CHAR_STRING_ATTRIBUTE_TYPE, 33, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(generatedDefaults[33]) } }, /* 5 / Basic / model identifier*/\
    { 0x0007, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX|ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)&(minMaxDefaults[4]) } }, /* 6 / Basic / power source*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 7 / Basic / cluster revision*/\
    { 0x0000, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_WRITABLE|ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[5]) } }, /* 8 / Identify / identify time*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 9 / Identify / cluster revision*/\
    { 0x0000, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[6]) } }, /* 10 / Groups / name support*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 11 / Groups / cluster revision*/\
    { 0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[7]) } }, /* 12 / Scenes / scene count*/\
    { 0x0001, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[8]) } }, /* 13 / Scenes / current scene*/\
    { 0x0002, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[9]) } }, /* 14 / Scenes / current group*/\
    { 0x0003, ZCL_BOOLEAN_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[10]) } }, /* 15 / Scenes / scene valid*/\
    { 0x0004, ZCL_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[11]) } }, /* 16 / Scenes / name support*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 17 / Scenes / cluster revision*/\
    { 0x0000, ZCL_BOOLEAN_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_MIN_MAX), { (uint8_t*)&(minMaxDefaults[12]) } }, /* 18 / On/off / on/off*/\
    { 0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 19 / On/off / cluster revision*/\
    { 0x0000, ZCL_IEEE_ADDRESS_ATTRIBUTE_TYPE, 8, (ATTRIBUTE_MASK_CLIENT), { NULL } }, /* 20 / Over the Air Bootloading / OTA Upgrade Server ID*/\
    { 0x0001, ZCL_INT32U_ATTRIBUTE_TYPE, 4, (ATTRIBUTE_MASK_CLIENT), { NULL } }, /* 21 / Over the Air Bootloading / Offset (address) into the file*/\
    { 0x0006, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_CLIENT), { (uint8_t*)0x00 } }, /* 22 / Over the Air Bootloading / OTA Upgrade Status*/\
  }


// Cluster function static arrays
#define GENERATED_FUNCTION_ARRAYS \
PGM EmberAfGenericClusterFunction emberAfFuncArrayIdentifyClusterServer[] = { (EmberAfGenericClusterFunction)emberAfIdentifyClusterServerInitCallback,(EmberAfGenericClusterFunction)emberAfIdentifyClusterServerAttributeChangedCallback}; \
PGM EmberAfGenericClusterFunction emberAfFuncArrayGroupsClusterServer[] = { (EmberAfGenericClusterFunction)emberAfGroupsClusterServerInitCallback}; \
PGM EmberAfGenericClusterFunction emberAfFuncArrayScenesClusterServer[] = { (EmberAfGenericClusterFunction)emberAfScenesClusterServerInitCallback}; \
PGM EmberAfGenericClusterFunction emberAfFuncArrayOtaBootloadClusterClient[] = { (EmberAfGenericClusterFunction)emberAfOtaBootloadClusterClientInitCallback,(EmberAfGenericClusterFunction)emberAfOtaBootloadClusterClientDefaultResponseCallback}; \


// Clusters defitions
#define GENERATED_CLUSTERS { \
    { 0x0000, (EmberAfAttributeMetadata*)&(generatedAttributes[0]), 8, 0, (CLUSTER_MASK_SERVER), NULL,  },    \
    { 0x0003, (EmberAfAttributeMetadata*)&(generatedAttributes[8]), 2, 4, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION| CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION), emberAfFuncArrayIdentifyClusterServer, },    \
    { 0x0004, (EmberAfAttributeMetadata*)&(generatedAttributes[10]), 2, 3, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayGroupsClusterServer, },    \
    { 0x0005, (EmberAfAttributeMetadata*)&(generatedAttributes[12]), 6, 8, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION), emberAfFuncArrayScenesClusterServer, },    \
    { 0x0006, (EmberAfAttributeMetadata*)&(generatedAttributes[18]), 2, 3, (CLUSTER_MASK_SERVER), NULL,  },    \
    { 0x0019, (EmberAfAttributeMetadata*)&(generatedAttributes[20]), 3, 13, (CLUSTER_MASK_CLIENT| CLUSTER_MASK_INIT_FUNCTION| CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION), emberAfFuncArrayOtaBootloadClusterClient, },    \
    { 0x0000, (EmberAfAttributeMetadata*)&(generatedAttributes[0]), 8, 0, (CLUSTER_MASK_SERVER), NULL,  },    \
    { 0x0003, (EmberAfAttributeMetadata*)&(generatedAttributes[8]), 0, 0, (CLUSTER_MASK_CLIENT), NULL,  },    \
    { 0x0003, (EmberAfAttributeMetadata*)&(generatedAttributes[8]), 2, 4, (CLUSTER_MASK_SERVER| CLUSTER_MASK_INIT_FUNCTION| CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION), emberAfFuncArrayIdentifyClusterServer, },    \
    { 0x0006, (EmberAfAttributeMetadata*)&(generatedAttributes[18]), 0, 0, (CLUSTER_MASK_CLIENT), NULL,  },    \
  }


// Endpoint types
#define GENERATED_ENDPOINT_TYPES {        \
    { (EmberAfCluster*)&(generatedClusters[0]), 6, 31 }, \
    { (EmberAfCluster*)&(generatedClusters[6]), 4, 4 }, \
  }


// Networks
#define EM_AF_GENERATED_NETWORK_TYPES { \
  EM_AF_NETWORK_TYPE_ZIGBEE_PRO, /* Primary */ \
}
#define EM_AF_GENERATED_ZIGBEE_PRO_NETWORKS { \
  { \
    /* Primary */ \
    ZA_ROUTER, \
    EMBER_AF_SECURITY_PROFILE_HA, \
  }, \
}
#define EM_AF_GENERATED_NETWORK_STRINGS  \
  "Primary (pro)", \


// Cluster manufacturer codes
#define GENERATED_CLUSTER_MANUFACTURER_CODES {      \
{0x00, 0x00} \
  }
#define GENERATED_CLUSTER_MANUFACTURER_CODE_COUNT (0)

// Attribute manufacturer codes
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODES {      \
{0x00, 0x00} \
  }
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODE_COUNT (0)


// Largest attribute size is needed for various buffers
#define ATTRIBUTE_LARGEST (33)
// Total size of singleton attributes
#define ATTRIBUTE_SINGLETONS_SIZE (73)

// Total size of attribute storage
#define ATTRIBUTE_MAX_SIZE 140

// Array of endpoints that are supported
#define FIXED_ENDPOINT_ARRAY { 1, 2, 3, 4, 5, 6, 7, 8 }

// Array of profile ids
#define FIXED_PROFILE_IDS { 260, 260, 260, 260, 260, 260, 260, 260 }

// Array of profile ids
#define FIXED_DEVICE_IDS { 256, 259, 256, 259, 256, 259, 256, 259 }

// Array of profile ids
#define FIXED_DEVICE_VERSIONS { 0, 0, 0, 0, 0, 0, 0, 0 }

// Array of endpoint types supported on each endpoint
#define FIXED_ENDPOINT_TYPES { 0, 1, 0, 1, 0, 1, 0, 1 }

// Array of networks supported on each endpoint
#define FIXED_NETWORKS { 0, 0, 0, 0, 0, 0, 0, 0 }


// Code used to configure the cluster event mechanism
#define EMBER_AF_GENERATED_EVENT_CODE \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl1; \
  EmberEventControl emberAfOtaBootloadClusterClientTickCallbackControl1; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl2; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl3; \
  EmberEventControl emberAfOtaBootloadClusterClientTickCallbackControl3; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl4; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl5; \
  EmberEventControl emberAfOtaBootloadClusterClientTickCallbackControl5; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl6; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl7; \
  EmberEventControl emberAfOtaBootloadClusterClientTickCallbackControl7; \
  EmberEventControl emberAfIdentifyClusterServerTickCallbackControl8; \
  extern EmberEventControl emberAfPluginEzmodeCommissioningStateEventControl; \
  extern void emberAfPluginEzmodeCommissioningStateEventHandler(void); \
  extern EmberEventControl emberAfPluginFormAndJoinCleanupEventControl; \
  extern void emberAfPluginFormAndJoinCleanupEventHandler(void); \
  extern EmberEventControl emberAfPluginIdentifyFeedbackProvideFeedbackEventControl; \
  extern void emberAfPluginIdentifyFeedbackProvideFeedbackEventHandler(void); \
  extern EmberEventControl emberAfPluginNetworkFindTickEventControl; \
  extern void emberAfPluginNetworkFindTickEventHandler(void); \
  extern EmberEventControl emberAfPluginOtaStorageSimpleEepromPageEraseEventControl; \
  extern void emberAfPluginOtaStorageSimpleEepromPageEraseEventHandler(void); \
  extern EmberEventControl emberAfPluginReportingTickEventControl; \
  extern void emberAfPluginReportingTickEventHandler(void); \
  extern EmberEventControl NwkJoinEventControl; \
  extern void NwkJoinEventFunction(void); \
  extern EmberEventControl DeviceResetEventControl; \
  extern void DeviceResetEventFunction(void); \
  extern EmberEventControl UartSendEventControl; \
  extern void UartSendEventFunction(void); \
  extern EmberEventControl UartGetEventControl; \
  extern void UartGetEventFunction(void); \
  extern EmberEventControl SendDeviceStatusEventControl; \
  extern void SendDeviceStatusEventFunction(void); \
  extern EmberEventControl CheckConnectionFromHcEventControl; \
  extern void CheckConnectionFromHcEventFunction(void); \
  extern EmberEventControl CheckMCReadyEventControl; \
  extern void CheckMCReadyEventFunction(void); \
  extern EmberEventControl SendIeeeResponseEventControl; \
  extern void SendIeeeResponseEventFunction(void); \
  static void clusterTickWrapper(EmberEventControl *control, EmberAfTickFunction callback, uint8_t endpoint) \
  { \
    emberAfPushEndpointNetworkIndex(endpoint); \
    emberEventControlSetInactive(*control); \
    (*callback)(endpoint); \
    emberAfPopNetworkIndex(); \
  } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction1(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl1, emberAfIdentifyClusterServerTickCallback, 1); } \
  void emberAfOtaBootloadClusterClientTickCallbackWrapperFunction1(void) { clusterTickWrapper(&emberAfOtaBootloadClusterClientTickCallbackControl1, emberAfOtaBootloadClusterClientTickCallback, 1); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction2(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl2, emberAfIdentifyClusterServerTickCallback, 2); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction3(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl3, emberAfIdentifyClusterServerTickCallback, 3); } \
  void emberAfOtaBootloadClusterClientTickCallbackWrapperFunction3(void) { clusterTickWrapper(&emberAfOtaBootloadClusterClientTickCallbackControl3, emberAfOtaBootloadClusterClientTickCallback, 3); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction4(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl4, emberAfIdentifyClusterServerTickCallback, 4); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction5(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl5, emberAfIdentifyClusterServerTickCallback, 5); } \
  void emberAfOtaBootloadClusterClientTickCallbackWrapperFunction5(void) { clusterTickWrapper(&emberAfOtaBootloadClusterClientTickCallbackControl5, emberAfOtaBootloadClusterClientTickCallback, 5); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction6(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl6, emberAfIdentifyClusterServerTickCallback, 6); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction7(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl7, emberAfIdentifyClusterServerTickCallback, 7); } \
  void emberAfOtaBootloadClusterClientTickCallbackWrapperFunction7(void) { clusterTickWrapper(&emberAfOtaBootloadClusterClientTickCallbackControl7, emberAfOtaBootloadClusterClientTickCallback, 7); } \
  void emberAfIdentifyClusterServerTickCallbackWrapperFunction8(void) { clusterTickWrapper(&emberAfIdentifyClusterServerTickCallbackControl8, emberAfIdentifyClusterServerTickCallback, 8); } \


// EmberEventData structs used to populate the EmberEventData table
#define EMBER_AF_GENERATED_EVENTS   \
  { &emberAfIdentifyClusterServerTickCallbackControl1, emberAfIdentifyClusterServerTickCallbackWrapperFunction1 }, \
  { &emberAfOtaBootloadClusterClientTickCallbackControl1, emberAfOtaBootloadClusterClientTickCallbackWrapperFunction1 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl2, emberAfIdentifyClusterServerTickCallbackWrapperFunction2 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl3, emberAfIdentifyClusterServerTickCallbackWrapperFunction3 }, \
  { &emberAfOtaBootloadClusterClientTickCallbackControl3, emberAfOtaBootloadClusterClientTickCallbackWrapperFunction3 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl4, emberAfIdentifyClusterServerTickCallbackWrapperFunction4 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl5, emberAfIdentifyClusterServerTickCallbackWrapperFunction5 }, \
  { &emberAfOtaBootloadClusterClientTickCallbackControl5, emberAfOtaBootloadClusterClientTickCallbackWrapperFunction5 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl6, emberAfIdentifyClusterServerTickCallbackWrapperFunction6 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl7, emberAfIdentifyClusterServerTickCallbackWrapperFunction7 }, \
  { &emberAfOtaBootloadClusterClientTickCallbackControl7, emberAfOtaBootloadClusterClientTickCallbackWrapperFunction7 }, \
  { &emberAfIdentifyClusterServerTickCallbackControl8, emberAfIdentifyClusterServerTickCallbackWrapperFunction8 }, \
  { &emberAfPluginEzmodeCommissioningStateEventControl, emberAfPluginEzmodeCommissioningStateEventHandler }, \
  { &emberAfPluginFormAndJoinCleanupEventControl, emberAfPluginFormAndJoinCleanupEventHandler }, \
  { &emberAfPluginIdentifyFeedbackProvideFeedbackEventControl, emberAfPluginIdentifyFeedbackProvideFeedbackEventHandler }, \
  { &emberAfPluginNetworkFindTickEventControl, emberAfPluginNetworkFindTickEventHandler }, \
  { &emberAfPluginOtaStorageSimpleEepromPageEraseEventControl, emberAfPluginOtaStorageSimpleEepromPageEraseEventHandler }, \
  { &emberAfPluginReportingTickEventControl, emberAfPluginReportingTickEventHandler }, \
  { &NwkJoinEventControl, NwkJoinEventFunction }, \
  { &DeviceResetEventControl, DeviceResetEventFunction }, \
  { &UartSendEventControl, UartSendEventFunction }, \
  { &UartGetEventControl, UartGetEventFunction }, \
  { &SendDeviceStatusEventControl, SendDeviceStatusEventFunction }, \
  { &CheckConnectionFromHcEventControl, CheckConnectionFromHcEventFunction }, \
  { &CheckMCReadyEventControl, CheckMCReadyEventFunction }, \
  { &SendIeeeResponseEventControl, SendIeeeResponseEventFunction }, \


#define EMBER_AF_GENERATED_EVENT_STRINGS   \
  "Identify Cluster Server EP 1",  \
  "Over the Air Bootloading Cluster Client EP 1",  \
  "Identify Cluster Server EP 2",  \
  "Identify Cluster Server EP 3",  \
  "Over the Air Bootloading Cluster Client EP 3",  \
  "Identify Cluster Server EP 4",  \
  "Identify Cluster Server EP 5",  \
  "Over the Air Bootloading Cluster Client EP 5",  \
  "Identify Cluster Server EP 6",  \
  "Identify Cluster Server EP 7",  \
  "Over the Air Bootloading Cluster Client EP 7",  \
  "Identify Cluster Server EP 8",  \
  "EZ-Mode Commissioning Plugin State",  \
  "Form and Join Library Plugin Cleanup",  \
  "Identify Feedback Plugin ProvideFeedback",  \
  "Network Find Plugin Tick",  \
  "OTA Simple Storage EEPROM Driver Plugin PageErase",  \
  "Reporting Plugin Tick",  \
  "NwkJoin Custom",  \
  "DeviceReset Custom",  \
  "UartSend Custom",  \
  "UartGet Custom",  \
  "SendDeviceStatus Custom",  \
  "CheckConnectionFromHc Custom",  \
  "CheckMCReady Custom",  \
  "SendIeeeResponse Custom",  \


// The length of the event context table used to track and retrieve cluster events
#define EMBER_AF_EVENT_CONTEXT_LENGTH 12

// EmberAfEventContext structs used to populate the EmberAfEventContext table
#define EMBER_AF_GENERATED_EVENT_CONTEXT { 0x1, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl1}, \
{ 0x1, 0x19, true, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfOtaBootloadClusterClientTickCallbackControl1}, \
{ 0x2, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl2}, \
{ 0x3, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl3}, \
{ 0x3, 0x19, true, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfOtaBootloadClusterClientTickCallbackControl3}, \
{ 0x4, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl4}, \
{ 0x5, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl5}, \
{ 0x5, 0x19, true, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfOtaBootloadClusterClientTickCallbackControl5}, \
{ 0x6, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl6}, \
{ 0x7, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl7}, \
{ 0x7, 0x19, true, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfOtaBootloadClusterClientTickCallbackControl7}, \
{ 0x8, 0x3, false, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP, &emberAfIdentifyClusterServerTickCallbackControl8}


#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_DECLARATIONS \
  void emberAfPluginEepromInitCallback(void); \
  void emberAfPluginNetworkFindInitCallback(void); \
  void emberAfPluginReportingInitCallback(void); \


#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_CALLS \
  emberAfPluginEepromInitCallback(); \
  emberAfPluginNetworkFindInitCallback(); \
  emberAfPluginReportingInitCallback(); \


#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_DECLARATIONS \
  void emberAfPluginNetworkFindStackStatusCallback(EmberStatus status); \
  void emberAfPluginOnOffStackStatusCallback(EmberStatus status); \
  void emberAfPluginOtaClientStackStatusCallback(EmberStatus status); \


#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_CALLS \
  emberAfPluginNetworkFindStackStatusCallback(status); \
  emberAfPluginOnOffStackStatusCallback(status); \
  emberAfPluginOtaClientStackStatusCallback(status); \


// Generated data for the command discovery
#define GENERATED_COMMANDS { \
    { 0x0003, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Identify / Identify */ \
    { 0x0003, 0x00, COMMAND_MASK_OUTGOING_SERVER | COMMAND_MASK_INCOMING_CLIENT }, /* Identify / IdentifyQueryResponse */ \
    { 0x0003, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* Identify / IdentifyQuery */ \
    { 0x0004, 0x00, COMMAND_MASK_OUTGOING_SERVER }, /* Groups / AddGroupResponse */ \
    { 0x0004, 0x00, COMMAND_MASK_INCOMING_SERVER }, /* Groups / AddGroup */ \
    { 0x0004, 0x01, COMMAND_MASK_OUTGOING_SERVER }, /* Groups / ViewGroupResponse */ \
    { 0x0004, 0x01, COMMAND_MASK_INCOMING_SERVER }, /* Groups / ViewGroup */ \
    { 0x0004, 0x02, COMMAND_MASK_OUTGOING_SERVER }, /* Groups / GetGroupMembershipResponse */ \
    { 0x0004, 0x02, COMMAND_MASK_INCOMING_SERVER }, /* Groups / GetGroupMembership */ \
    { 0x0004, 0x03, COMMAND_MASK_OUTGOING_SERVER }, /* Groups / RemoveGroupResponse */ \
    { 0x0004, 0x03, COMMAND_MASK_INCOMING_SERVER }, /* Groups / RemoveGroup */ \
    { 0x0004, 0x04, COMMAND_MASK_INCOMING_SERVER }, /* Groups / RemoveAllGroups */ \
    { 0x0004, 0x05, COMMAND_MASK_INCOMING_SERVER }, /* Groups / AddGroupIfIdentifying */ \
    { 0x0005, 0x00, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / AddSceneResponse */ \
    { 0x0005, 0x00, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / AddScene */ \
    { 0x0005, 0x01, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / ViewSceneResponse */ \
    { 0x0005, 0x01, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / ViewScene */ \
    { 0x0005, 0x02, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / RemoveSceneResponse */ \
    { 0x0005, 0x02, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / RemoveScene */ \
    { 0x0005, 0x03, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / RemoveAllScenesResponse */ \
    { 0x0005, 0x03, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / RemoveAllScenes */ \
    { 0x0005, 0x04, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / StoreSceneResponse */ \
    { 0x0005, 0x04, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / StoreScene */ \
    { 0x0005, 0x05, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / RecallScene */ \
    { 0x0005, 0x06, COMMAND_MASK_OUTGOING_SERVER }, /* Scenes / GetSceneMembershipResponse */ \
    { 0x0005, 0x06, COMMAND_MASK_INCOMING_SERVER }, /* Scenes / GetSceneMembership */ \
    { 0x0006, 0x00, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / Off */ \
    { 0x0006, 0x01, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / On */ \
    { 0x0006, 0x02, COMMAND_MASK_OUTGOING_CLIENT | COMMAND_MASK_INCOMING_SERVER }, /* On/off / Toggle */ \
    { 0x0019, 0x01, COMMAND_MASK_OUTGOING_CLIENT }, /* Over the Air Bootloading / QueryNextImageRequest */ \
    { 0x0019, 0x03, COMMAND_MASK_OUTGOING_CLIENT }, /* Over the Air Bootloading / ImageBlockRequest */ \
    { 0x0019, 0x06, COMMAND_MASK_OUTGOING_CLIENT }, /* Over the Air Bootloading / UpgradeEndRequest */ \
  }
#define EMBER_AF_GENERATED_COMMAND_COUNT (32)
#endif // __AF_ENDPOINT_CONFIG__
