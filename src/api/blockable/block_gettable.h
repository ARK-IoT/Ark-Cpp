

#ifndef BLOCK_GETTABLE_H
#define BLOCK_GETTABLE_H

#include "api/blockable/block_respondable.h"
#include "models/fees.h"
#include "models/block.h"
#include "api/paths.h"
#include "utilities/connector.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
namespace Block
{
/*************************************************
*  PROTECTED: ARK::API::Block::Gettable
**************************************************/
class Gettable
{
protected:
  /*************************************************
  * ARK::API::Block::Gettable::block
  *	api/blocks/get?id=_blockID
  **************************************************/
  ARK::Block block(
		ARK::Utilities::Network::Connector &netConnector,
		const char *const blockId
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************/
  /*************************************************
  *	BROKEN: fix for large callbacks
  *	blocks callback is ~63,712 bytes
  **************************************************/
  /*************************************************/
	/*************************************************
  *	/api/blocks
  **************************************************/
  // String blocks(ARK::Utilities::Network::Connector _netConnector) {
  /*************************************************/
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::epoch
  *	/api/blocks/getEpoch
  *
  *	@brief:	blockEpoch example: 2017-03-21T13:00:00.000Z
  **************************************************/
  void epoch(
			ARK::Utilities::Network::Connector &netConnector,
      char bufer[]
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::height 
  *	/api/blocks/getHeight
  **************************************************/
  ARK::API::Block::Respondable::Height height(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::nethash
  *	/api/blocks/getNethash 
  **************************************************/
  Hash nethash(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::fee 
  *	/api/blocks/getFee
  **************************************************/
  Balance fee(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::fees
  *	/api/blocks/getFees 
  **************************************************/
  ARK::Fees fees(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::milestone
  *	/api/blocks/getMilestone
  **************************************************/
  const char *milestone(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::reward
  *	/api/blocks/getReward
  **************************************************/
  Balance reward(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
  * ARK::API::Block::Gettable::supply
  *	/api/blocks/getSupply
  **************************************************/
  Balance supply(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

  /**************************************************************************************************/

  /*************************************************
   *  ARK::API::Block::Gettable::status 
   *	api/blocks/getStatus
  **************************************************/
  ARK::API::Block::Respondable::Status status(
			ARK::Utilities::Network::Connector &netConnector
	);
  /*************************************************/

};
/*************************************************/

};
};
};

#endif

/**************************************************************************************************/
/*************************************************/
/*************************************************
*   BROKEN: fix for large callbacks
*   blocks callback is ~63,712 bytes
**************************************************/
/*************************************************/
/*************************************************
* ARK::API::Block::Gettable::blocks
*   /api/blocks
**************************************************/
// String blocks(ARK::Utilities::Network::Connector _netConnector) {
//   String uri = ARK::API::Paths::Block::blocks_s;
//   String callback = _netConnector.cb(uri);
//   if (callback.indexOf("false") >= 0) { return callback; };
//   return ARK::API::Block::Gettable::blocksfromJSON(callback);
// };

// /*
// {
//   "success":true,
//   "blocks":[
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     },
//     ...
//     {
//       "id":"_blockID",
//       "version":_version,
//       "timestamp":_timestamp,
//       "height":_height,
//       "previousBlock":"_previousBlock",
//       "numberOfTransactions":_numberOfTransactions,
//       "totalAmount":_totalAmount,
//       "totalFee":_totalFee,
//       "reward":_reward,
//       "payloadLength":_payloadLength,
//       "payloadHash":"_payloadHash",
//       "generatorPublicKey":"_generatorPubkey",
//       "generatorId":"_generatorId",
//       "blockSignature":"_blockSig",
//       "confirmations":_confirmations,
//       "totalForged":"_totalForged"
//     }
//   ],
//   "count":2313747
// }
// */
/*************************************************
*
*
**************************************************/
// String blocksfromJSON(String jsonStr) {
//   ARK::Utilities::JSONString jString(jsonStr);
//   // ARK::Block block = {
//   //   jString.valueFor("id").toInt(),
//   //   jString.valueFor("version").toFloat(),
//   //   jString.valueFor("timestamp").toInt(),
//   //   jString.valueFor("height").toInt(),
//   //   jString.valueFor("previousBlock").toInt(),
//   //   jString.valueFor("numberOfTransactions").toInt(),
//   //   jString.valueFor("totalAmount").toFloat(),
//   //   jString.valueFor("totalFee").toFloat(),
//   //   jString.valueFor("reward").toInt(),
//   //   jString.valueFor("payloadLength").toInt(),
//   //   jString.valueFor("payloadHash"),
//   //   jString.valueFor("generatorPublicKey"),
//   //   jString.valueFor("generatorId"),
//   //   jString.valueFor("blockSignature"),
//   //   jString.valueFor("confirmations").toInt(),
//   //   jString.valueFor("totalForged").toInt()
//   // };
//   return "";//block.description();
// };
/*************************************************/
/*************************************************/
/**************************************************************************************************/
