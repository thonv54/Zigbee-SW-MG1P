// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// This is a set of generated functions that parse the
// the incomming message, and call appropriate command handler.



#include PLATFORM_HEADER
#ifdef EZSP_HOST
// Includes needed for ember related functions for the EZSP host
#include "stack/include/error.h"
#include "stack/include/ember-types.h"
#include "app/util/ezsp/ezsp-protocol.h"
#include "app/util/ezsp/ezsp.h"
#include "app/util/ezsp/ezsp-utils.h"
#include "app/util/ezsp/serial-interface.h"
#else
// Includes needed for ember related functions for the EM250
#include "stack/include/ember.h"
#endif // EZSP_HOST

#include "app/framework/util/util.h"
#include "af-structs.h"
#include "call-command-handler.h"
#include "command-id.h"
#include "callback.h"

static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
  if (wasHandled) {
    return EMBER_ZCL_STATUS_SUCCESS;
  } else if (mfgSpecific) {
    return EMBER_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND;
  } else if (clusterExists) {
    return EMBER_ZCL_STATUS_UNSUP_CLUSTER_COMMAND;
  } else {
    return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
  }
}

// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand *cmd)
{
  if (cmd->direction == ZCL_DIRECTION_SERVER_TO_CLIENT
      && emberAfContainsClient(cmd->apsFrame->destinationEndpoint,
                               cmd->apsFrame->clusterId)) {
    switch (cmd->apsFrame->clusterId) {
    case ZCL_IDENTIFY_CLUSTER_ID:
      return emberAfIdentifyClusterClientCommandParse(cmd);
    }
  } else if (cmd->direction == ZCL_DIRECTION_CLIENT_TO_SERVER
             && emberAfContainsServer(cmd->apsFrame->destinationEndpoint,
                                      cmd->apsFrame->clusterId)) {
    switch (cmd->apsFrame->clusterId) {
    case ZCL_IDENTIFY_CLUSTER_ID:
      return emberAfIdentifyClusterServerCommandParse(cmd);
    case ZCL_GROUPS_CLUSTER_ID:
      return emberAfGroupsClusterServerCommandParse(cmd);
    case ZCL_SCENES_CLUSTER_ID:
      return emberAfScenesClusterServerCommandParse(cmd);
    case ZCL_ON_OFF_CLUSTER_ID:
      return emberAfOnOffClusterServerCommandParse(cmd);
    }
  }
  return status(false, false, cmd->mfgSpecific);
}

// Cluster: Identify, client
EmberAfStatus emberAfIdentifyClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_IDENTIFY_QUERY_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t timeout;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        timeout = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIdentifyClusterIdentifyQueryResponseCallback(timeout);
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Identify, server
EmberAfStatus emberAfIdentifyClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_IDENTIFY_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t identifyTime;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        identifyTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIdentifyClusterIdentifyCallback(identifyTime);
        break;
      }
    case ZCL_IDENTIFY_QUERY_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfIdentifyClusterIdentifyQueryCallback();
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Groups, server
EmberAfStatus emberAfGroupsClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_ADD_GROUP_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t* groupName;  // Ver.: always
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfGroupsClusterAddGroupCallback(groupId,
                                                          groupName);
        break;
      }
    case ZCL_VIEW_GROUP_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfGroupsClusterViewGroupCallback(groupId);
        break;
      }
    case ZCL_GET_GROUP_MEMBERSHIP_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t groupCount;  // Ver.: always
        uint8_t* groupList;  // Ver.: always
        // Command is fixed length: 1
        if (cmd->bufLen < payloadOffset + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupCount = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1;
        groupList = cmd->buffer + payloadOffset;
        wasHandled = emberAfGroupsClusterGetGroupMembershipCallback(groupCount,
                                                                    groupList);
        break;
      }
    case ZCL_REMOVE_GROUP_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfGroupsClusterRemoveGroupCallback(groupId);
        break;
      }
    case ZCL_REMOVE_ALL_GROUPS_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfGroupsClusterRemoveAllGroupsCallback();
        break;
      }
    case ZCL_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t* groupName;  // Ver.: always
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfGroupsClusterAddGroupIfIdentifyingCallback(groupId,
                                                                       groupName);
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Scenes, server
EmberAfStatus emberAfScenesClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_ADD_SCENE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t sceneId;  // Ver.: always
        uint16_t transitionTime;  // Ver.: always
        uint8_t* sceneName;  // Ver.: always
        uint8_t* extensionFieldSets;  // Ver.: always
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        if (cmd->bufLen < payloadOffset + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1;
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        transitionTime = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        sceneName = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += emberAfStringLength(cmd->buffer + payloadOffset) + 1;
        extensionFieldSets = cmd->buffer + payloadOffset;
        wasHandled = emberAfScenesClusterAddSceneCallback(groupId,
                                                          sceneId,
                                                          transitionTime,
                                                          sceneName,
                                                          extensionFieldSets);
        break;
      }
    case ZCL_VIEW_SCENE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t sceneId;  // Ver.: always
        // Command is fixed length: 3
        if (cmd->bufLen < payloadOffset + 3) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterViewSceneCallback(groupId,
                                                           sceneId);
        break;
      }
    case ZCL_REMOVE_SCENE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t sceneId;  // Ver.: always
        // Command is fixed length: 3
        if (cmd->bufLen < payloadOffset + 3) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterRemoveSceneCallback(groupId,
                                                             sceneId);
        break;
      }
    case ZCL_REMOVE_ALL_SCENES_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterRemoveAllScenesCallback(groupId);
        break;
      }
    case ZCL_STORE_SCENE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t sceneId;  // Ver.: always
        // Command is fixed length: 3
        if (cmd->bufLen < payloadOffset + 3) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterStoreSceneCallback(groupId,
                                                            sceneId);
        break;
      }
    case ZCL_RECALL_SCENE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        uint8_t sceneId;  // Ver.: always
        // Command is fixed length: 3
        if (cmd->bufLen < payloadOffset + 3) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2;
        sceneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterRecallSceneCallback(groupId,
                                                             sceneId);
        break;
      }
    case ZCL_GET_SCENE_MEMBERSHIP_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t groupId;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2) return EMBER_ZCL_STATUS_MALFORMED_COMMAND;
        groupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfScenesClusterGetSceneMembershipCallback(groupId);
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: On/off, server
EmberAfStatus emberAfOnOffClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_OFF_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfOnOffClusterOffCallback();
        break;
      }
    case ZCL_ON_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfOnOffClusterOnCallback();
        break;
      }
    case ZCL_TOGGLE_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfOnOffClusterToggleCallback();
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}
