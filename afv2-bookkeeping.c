// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

#include PLATFORM_HEADER
#include CONFIGURATION_HEADER
#include "af.h"

// Init function declarations.
void emberAfMainInitCallback(void);
void emberAfInit(void);

void emAfInit(void)
{
  emberAfMainInitCallback();
  emberAfInit();
}

// Tick function declarations.
void emberAfMainTickCallback(void);
void emberAfTick(void);

void emAfTick(void)
{
  emberAfMainTickCallback();
  emberAfTick();
}

void emAfResetAttributes(uint8_t endpointId)
{
}

// PreCommandReceived function declarations.
bool emberAfPreCommandReceivedCallback(EmberAfClusterCommand* cmd);

bool emAfPreCommandReceived(EmberAfClusterCommand* cmd)
{
  return emberAfPreCommandReceivedCallback(cmd);
}

// PreZDOMessageReceived function declarations.
bool emberAfPreZDOMessageReceivedCallback(EmberNodeId emberNodeId,EmberApsFrame* apsFrame,uint8_t* message,uint16_t length);

bool emAfPreZDOMessageReceived(EmberNodeId emberNodeId,EmberApsFrame* apsFrame,uint8_t* message,uint16_t length)
{
  return emberAfPreZDOMessageReceivedCallback(emberNodeId, apsFrame, message, length);
}
