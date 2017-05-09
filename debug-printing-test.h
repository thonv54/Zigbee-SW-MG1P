// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// This is the test header, that enables all printing
// Enclosing macro to prevent multiple inclusion
#ifndef __EMBER_AF_PRINTING_TEST__
#define __EMBER_AF_PRINTING_TEST__


#define EMBER_AF_PRINT_ENABLE
#define EMBER_AF_PRINT_BASIC_CLUSTER 0x0001
#define EMBER_AF_PRINT_POWER_CONFIG_CLUSTER 0x0002
#define EMBER_AF_PRINT_DEVICE_TEMP_CLUSTER 0x0004
#define EMBER_AF_PRINT_IDENTIFY_CLUSTER 0x0008
#define EMBER_AF_PRINT_GROUPS_CLUSTER 0x0010
#define EMBER_AF_PRINT_SCENES_CLUSTER 0x0020
#define EMBER_AF_PRINT_ON_OFF_CLUSTER 0x0040
#define EMBER_AF_PRINT_ON_OFF_SWITCH_CONFIG_CLUSTER 0x0080
#define EMBER_AF_PRINT_LEVEL_CONTROL_CLUSTER 0x0101
#define EMBER_AF_PRINT_ALARM_CLUSTER 0x0102
#define EMBER_AF_PRINT_TIME_CLUSTER 0x0104
#define EMBER_AF_PRINT_RSSI_LOCATION_CLUSTER 0x0108
#define EMBER_AF_PRINT_BINARY_INPUT_BASIC_CLUSTER 0x0110
#define EMBER_AF_PRINT_COMMISSIONING_CLUSTER 0x0120
#define EMBER_AF_PRINT_PARTITION_CLUSTER 0x0140
#define EMBER_AF_PRINT_OTA_BOOTLOAD_CLUSTER 0x0180
#define EMBER_AF_PRINT_POWER_PROFILE_CLUSTER 0x0201
#define EMBER_AF_PRINT_APPLIANCE_CONTROL_CLUSTER 0x0202
#define EMBER_AF_PRINT_POLL_CONTROL_CLUSTER 0x0204
#define EMBER_AF_PRINT_GREEN_POWER_CLUSTER 0x0208
#define EMBER_AF_PRINT_KEEPALIVE_CLUSTER 0x0210
#define EMBER_AF_PRINT_SHADE_CONFIG_CLUSTER 0x0220
#define EMBER_AF_PRINT_DOOR_LOCK_CLUSTER 0x0240
#define EMBER_AF_PRINT_WINDOW_COVERING_CLUSTER 0x0280
#define EMBER_AF_PRINT_PUMP_CONFIG_CONTROL_CLUSTER 0x0301
#define EMBER_AF_PRINT_THERMOSTAT_CLUSTER 0x0302
#define EMBER_AF_PRINT_FAN_CONTROL_CLUSTER 0x0304
#define EMBER_AF_PRINT_DEHUMID_CONTROL_CLUSTER 0x0308
#define EMBER_AF_PRINT_THERMOSTAT_UI_CONFIG_CLUSTER 0x0310
#define EMBER_AF_PRINT_COLOR_CONTROL_CLUSTER 0x0320
#define EMBER_AF_PRINT_BALLAST_CONFIGURATION_CLUSTER 0x0340
#define EMBER_AF_PRINT_ILLUM_MEASUREMENT_CLUSTER 0x0380
#define EMBER_AF_PRINT_ILLUM_LEVEL_SENSING_CLUSTER 0x0401
#define EMBER_AF_PRINT_TEMP_MEASUREMENT_CLUSTER 0x0402
#define EMBER_AF_PRINT_PRESSURE_MEASUREMENT_CLUSTER 0x0404
#define EMBER_AF_PRINT_FLOW_MEASUREMENT_CLUSTER 0x0408
#define EMBER_AF_PRINT_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER 0x0410
#define EMBER_AF_PRINT_OCCUPANCY_SENSING_CLUSTER 0x0420
#define EMBER_AF_PRINT_IAS_ZONE_CLUSTER 0x0440
#define EMBER_AF_PRINT_IAS_ACE_CLUSTER 0x0480
#define EMBER_AF_PRINT_IAS_WD_CLUSTER 0x0501
#define EMBER_AF_PRINT_GENERIC_TUNNEL_CLUSTER 0x0502
#define EMBER_AF_PRINT_BACNET_PROTOCOL_TUNNEL_CLUSTER 0x0504
#define EMBER_AF_PRINT_11073_PROTOCOL_TUNNEL_CLUSTER 0x0508
#define EMBER_AF_PRINT_ISO7816_PROTOCOL_TUNNEL_CLUSTER 0x0510
#define EMBER_AF_PRINT_PRICE_CLUSTER 0x0520
#define EMBER_AF_PRINT_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER 0x0540
#define EMBER_AF_PRINT_SIMPLE_METERING_CLUSTER 0x0580
#define EMBER_AF_PRINT_MESSAGING_CLUSTER 0x0601
#define EMBER_AF_PRINT_TUNNELING_CLUSTER 0x0602
#define EMBER_AF_PRINT_PREPAYMENT_CLUSTER 0x0604
#define EMBER_AF_PRINT_ENERGY_MANAGEMENT_CLUSTER 0x0608
#define EMBER_AF_PRINT_CALENDAR_CLUSTER 0x0610
#define EMBER_AF_PRINT_DEVICE_MANAGEMENT_CLUSTER 0x0620
#define EMBER_AF_PRINT_EVENTS_CLUSTER 0x0640
#define EMBER_AF_PRINT_MDU_PAIRING_CLUSTER 0x0680
#define EMBER_AF_PRINT_KEY_ESTABLISHMENT_CLUSTER 0x0701
#define EMBER_AF_PRINT_INFORMATION_CLUSTER 0x0702
#define EMBER_AF_PRINT_DATA_SHARING_CLUSTER 0x0704
#define EMBER_AF_PRINT_GAMING_CLUSTER 0x0708
#define EMBER_AF_PRINT_DATA_RATE_CONTROL_CLUSTER 0x0710
#define EMBER_AF_PRINT_VOICE_OVER_ZIGBEE_CLUSTER 0x0720
#define EMBER_AF_PRINT_CHATTING_CLUSTER 0x0740
#define EMBER_AF_PRINT_PAYMENT_CLUSTER 0x0780
#define EMBER_AF_PRINT_BILLING_CLUSTER 0x0801
#define EMBER_AF_PRINT_APPLIANCE_IDENTIFICATION_CLUSTER 0x0802
#define EMBER_AF_PRINT_METER_IDENTIFICATION_CLUSTER 0x0804
#define EMBER_AF_PRINT_APPLIANCE_EVENTS_AND_ALERT_CLUSTER 0x0808
#define EMBER_AF_PRINT_APPLIANCE_STATISTICS_CLUSTER 0x0810
#define EMBER_AF_PRINT_ELECTRICAL_MEASUREMENT_CLUSTER 0x0820
#define EMBER_AF_PRINT_DIAGNOSTICS_CLUSTER 0x0840
#define EMBER_AF_PRINT_ZLL_COMMISSIONING_CLUSTER 0x0880
#define EMBER_AF_PRINT_SAMPLE_MFG_SPECIFIC_CLUSTER 0x0901
#define EMBER_AF_PRINT_OTA_CONFIGURATION_CLUSTER 0x0902
#define EMBER_AF_PRINT_MFGLIB_CLUSTER 0x0904
#define EMBER_AF_PRINT_CORE 0x0908
#define EMBER_AF_PRINT_DEBUG 0x0910
#define EMBER_AF_PRINT_APP 0x0920
#define EMBER_AF_PRINT_SECURITY 0x0940
#define EMBER_AF_PRINT_ATTRIBUTES 0x0980
#define EMBER_AF_PRINT_REPORTING 0x0A01
#define EMBER_AF_PRINT_SERVICE_DISCOVERY 0x0A02
#define EMBER_AF_PRINT_REGISTRATION 0x0A04
#define EMBER_AF_PRINT_ZDO 0x0A08
#define EMBER_AF_PRINT_CUSTOM1 0x0A10
#define EMBER_AF_PRINT_CUSTOM2 0x0A20
#define EMBER_AF_PRINT_CUSTOM3 0x0A40


#define EMBER_AF_PRINT_OUTPUT 1


#define EMBER_AF_PRINT_NAMES { \
  "Basic",\
  "Power Configuration",\
  "Device Temperature Configuration",\
  "Identify",\
  "Groups",\
  "Scenes",\
  "On/off",\
  "On/off Switch Configuration",\
  "Level Control",\
  "Alarms",\
  "Time",\
  "RSSI Location",\
  "Binary Input (Basic)",\
  "Commissioning",\
  "Partition",\
  "Over the Air Bootloading",\
  "Power Profile",\
  "Appliance Control",\
  "Poll Control",\
  "Green Power",\
  "Keep-Alive",\
  "Shade Configuration",\
  "Door Lock",\
  "Window Covering",\
  "Pump Configuration and Control",\
  "Thermostat",\
  "Fan Control",\
  "Dehumidification Control",\
  "Thermostat User Interface Configuration",\
  "Color Control",\
  "Ballast Configuration",\
  "Illuminance Measurement",\
  "Illuminance Level Sensing",\
  "Temperature Measurement",\
  "Pressure Measurement",\
  "Flow Measurement",\
  "Relative Humidity Measurement",\
  "Occupancy Sensing",\
  "IAS Zone",\
  "IAS ACE",\
  "IAS WD",\
  "Generic Tunnel",\
  "BACnet Protocol Tunnel",\
  "11073 Protocol Tunnel",\
  "ISO 7816 Protocol Tunnel",\
  "Price",\
  "Demand Response and Load Control",\
  "Simple Metering",\
  "Messaging",\
  "Tunneling",\
  "Prepayment",\
  "Energy Management",\
  "Calendar",\
  "Device Management",\
  "Events",\
  "MDU Pairing",\
  "Key Establishment",\
  "Information",\
  "Data Sharing",\
  "Gaming",\
  "Data Rate Control",\
  "Voice over ZigBee",\
  "Chatting",\
  "Payment",\
  "Billing",\
  "Appliance Identification",\
  "Meter Identification",\
  "Appliance Events and Alert",\
  "Appliance Statistics",\
  "Electrical Measurement",\
  "Diagnostics",\
  "ZLL Commissioning",\
  "Sample Mfg Specific Cluster",\
  "Configuration Cluster",\
  "MFGLIB Cluster",\
  "Core",\
  "Debug",\
  "Application",\
  "Security",\
  "Attributes",\
  "Reporting",\
  "Service discovery",\
  "Registration",\
  "ZDO (ZigBee Device Object)",\
  "Custom messages (1)",\
  "Custom messages (2)",\
  "Custom messages (3)"\
}


#define EMBER_AF_PRINT_NAME_NUMBER 87
#define EMBER_AF_PRINT_BITS { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }


#endif // __EMBER_AF_PRINTING_TEST__
