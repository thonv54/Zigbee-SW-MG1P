
#ifndef __ZIGBEEUTILITY_H__
#define __ZIGBEEUTILITY_H__



//---------------------------Define-------------------------//
#define	EmberOnOffAttributeResponseLength	5


//---------------------------Enum----------------------------//

typedef enum {
   OnOffType			= 1,
   LevelType			= 2,
   LevelWithOnOffType 	= 3,
}BindCommandType_enum;
//---------------------------Struct--------------------------//
typedef struct {
  /** The AttributeID of on-off cluster */
  int16u AttributeID;
  /** The Status  */
  int8u Status;
  /** The DataType. */
  int8u DataType;
  /** Value. */
  int8u Value[32];

} EmberReadAttributeResponse_str;


typedef struct {
  /** The AttributeID of on-off cluster */
  int16u AttributeID;
  /** The DataType. */
  int8u DataType;
  /** Value. */
  int8u Value[32];

} EmberReportAttributeResponse_str;


//----------------------------Protocol-----------------------//
void SendViaBindingTable(int8u endpoint,
                           EmberAfClusterId clusterId,
                           EmberAfAttributeId attributeId,
                           int8u* value,
                           int8u dataType);

#if 0
void SendGlobalServerToClientReadAttributeResponse(int8u Endpoint, 
						   EmberAfClusterId clusterId,
						   EmberAfAttributeId attributeId,
						   int8u* value,
						   int8u dataType);
#else
#define SendGlobalServerToClientReadAttributeResponse  SendGlobalServerToClientReportAttributeResponse
void SendGlobalServerToClientReportAttributeResponse(int8u Endpoint, 
						   EmberAfClusterId clusterId,
						   EmberAfAttributeId attributeId,
						   int8u* value,
						   int8u dataType);

#endif
void GetHcActiveEndPoint(void);
void SendBasicReadModelAttributeResponse(void);









#endif