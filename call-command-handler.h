// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef __EMBER_AF_COMMAND_PARSE_HEADER__
#define __EMBER_AF_COMMAND_PARSE_HEADER__


// This is a set of generated prototype for functions that parse the
// the incomming message, and call appropriate command handler.

// Cluster: Identify, client
EmberAfStatus emberAfIdentifyClusterClientCommandParse(EmberAfClusterCommand *cmd);

// Cluster: Identify, server
EmberAfStatus emberAfIdentifyClusterServerCommandParse(EmberAfClusterCommand *cmd);

// Cluster: Groups, server
EmberAfStatus emberAfGroupsClusterServerCommandParse(EmberAfClusterCommand *cmd);

// Cluster: Scenes, server
EmberAfStatus emberAfScenesClusterServerCommandParse(EmberAfClusterCommand *cmd);

// Cluster: On/off, server
EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand *cmd);

#endif // __EMBER_AF_COMMAND_PARSE_HEADER__
