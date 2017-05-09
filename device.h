#ifndef __DEVICE_H__
#define __DEVICE_H__


#define ROUTE
#define RADIO_POWER  10

//#define RADIO_POWER     3

#ifdef  SWITCH_1_BUTTON_V1
#define UART_CMD_V1
#define SWITCH_1_BUTTON
	#ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 1
    #define NumberOfOnOffEndpoint   1
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_2_BUTTON_V1
#define SWITCH_2_BUTTON
#define UART_CMD_V1
	#ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 2
    #define NumberOfOnOffEndpoint   2
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_3_BUTTON_V1
#define SWITCH_3_BUTTON
#define UART_CMD_V1
	#ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 3
    #define NumberOfOnOffEndpoint   3
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_4_BUTTON_V1
#define SWITCH_4_BUTTON
#define UART_CMD_V1
  #ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 4
    #define NumberOfOnOffEndpoint   4
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_1_BUTTON_V2
#define SWITCH_1_BUTTON
#define UART_CMD_V2
	#ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 1
    #define NumberOfOnOffEndpoint   1
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_2_BUTTON_V2
#define SWITCH_2_BUTTON
#define UART_CMD_V2
	#ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 2
    #define NumberOfOnOffEndpoint   2
    #define SWITCH_TYPE
	#endif
#endif

#ifdef  SWITCH_3_BUTTON_V2
#define SWITCH_3_BUTTON
#define UART_CMD_V2
    #ifndef NUMBER_BUTTON
        #define NUMBER_BUTTON 	 3
        #define NumberOfOnOffEndpoint   3
        #define SWITCH_TYPE
    #endif
#endif

#ifdef  SWITCH_4_BUTTON_V2
#define SWITCH_4_BUTTON
#define UART_CMD_V2
  #ifndef NUMBER_BUTTON
    #define NUMBER_BUTTON 	 4
    #define NumberOfOnOffEndpoint   4
    #define SWITCH_TYPE
	#endif
#endif

#ifdef DIMMER
    #define LEVEL_TYPE
    #define SINGER_LEVEL_TYPE
    #define NUMBER_LEVEL  1
#endif

#ifdef CURTAIN
    #define LEVEL_TYPE
    #define SINGER_LEVEL_TYPE
    #define NUMBER_LEVEL  1
#endif

#ifdef FAN
    #define LEVEL_TYPE
    #define SINGER_LEVEL_TYPE
    #define NUMBER_LEVEL  1
#endif

#ifdef DUAL_CURTAIN
    #define LEVEL_TYPE
    #define DUAL_LEVEL_TYPE
    #define NUMBER_LEVEL  2
#endif

#ifdef DUAL_DIMMER
    #define LEVEL_TYPE
    #define DUAL_LEVEL_TYPE
    #define NUMBER_LEVEL  2
#endif


#define Button1InClusterEndpoint 1
#define Button1OutClusterEndpoint 2
#define Button2InClusterEndpoint 3
#define Button2OutClusterEndpoint 4
#define Button3InClusterEndpoint 5
#define Button3OutClusterEndpoint 6
#define Button4InClusterEndpoint 7
#define Button4OutClusterEndpoint 8
#define DimmerInClusterEndpoint	1
#define DimmerOutClusterEndpoint 2

#define Lumivietnam   	12,'L','u','m','i',' ','V','i','e','t','n','a','m',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LumiRD     		8,'L','u','m','i',' ','R','&','D',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_DZ1     		6,'L','M','-','D','Z','1',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_DZ2      	6,'L','M','-','D','Z','2',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_SZ1       	6,'L','M','-','S','Z','1',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_SZ2       	6,'L','M','-','S','Z','2',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_SZ3       	6,'L','M','-','S','Z','3',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_SZ4       	6,'L','M','-','S','Z','4',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_BZ1			  6,'L','M','-','B','Z','1',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_FZ1			  6,'L','M','-','F','Z','1',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define LM_BZ2        6,'L','M','-','B','Z','2',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0


#define LM_DZ1_M     	"LM_DZ1"	
#define LM_DZ2_M      "LM_DZ2"	
#define LM_SZ1_M      "LM_SZ1" 	
#define LM_SZ2_M      "LM_SZ2" 	
#define LM_SZ3_M      "LM_SZ3" 	
#define LM_SZ4_M      "LM_SZ4"	
#define LM_BZ1_M			"LM_BZ1"  
#define LM_FZ1_M			"LM_FZ1"  
#define LM_BZ2_M      "LM_BZ2"

#define ModelLength 7

#ifdef DIMMER
    #define ManufacturerName   LumiRD
    #define ModelId	LM_DZ1
    #define ModelId_M  LM_DZ1_M
#endif

#ifdef CURTAIN
    #define ManufacturerName   LumiRD
    #define ModelId	LM_BZ1
    #define ModelId_M  LM_BZ1_M
#endif

#ifdef DUAL_CURTAIN
    #define ManufacturerName   LumiRD
    #define ModelId	LM_BZ2
    #define ModelId_M  LM_BZ2_M
#endif

#ifdef FAN
    #define ManufacturerName   LumiRD
    #define ModelId	LM_FZ1
    #define ModelId_M  LM_FZ1_M
#endif

#ifdef DUAL_DIMMER
    #define ManufacturerName   LumiRD
    #define ModelId	LM_DZ2
    #define ModelId_M  LM_DZ2_M
#endif


#ifdef SWITCH_1_BUTTON
		#define ManufacturerName   LumiRD
		#define ModelId				LM_SZ1
    #define ModelId_M  LM_SZ1_M
#endif
#ifdef SWITCH_2_BUTTON
		#define ManufacturerName   LumiRD
		#define ModelId				LM_SZ2
    #define ModelId_M  LM_SZ2_M
#endif
#ifdef SWITCH_3_BUTTON
		#define ManufacturerName   LumiRD
		#define ModelId				LM_SZ3
    #define ModelId_M  LM_SZ3_M
#endif
#ifdef SWITCH_4_BUTTON
		#define ManufacturerName   LumiRD
		#define ModelId				LM_SZ4
    #define ModelId_M  LM_SZ4_M
#endif

#define LedLightOptionEndpoint		15

#define HcDefaultEP_Zipato		0x0C
#define HcDefaultEP_Smarthing		0x01
#define HcDefaultEP_Lumi		0x01

#ifdef Zipato
#define HcDefaultEP	0x0C
#endif
#ifdef SmartThing
#define  HcDefaultEP 0x01
#endif
#ifndef  HcDefaultEP
#define	HcDefaultEP	0x01
#endif

#ifndef ConfigToolEpt
#define ConfigToolEpt  50
#endif

#endif