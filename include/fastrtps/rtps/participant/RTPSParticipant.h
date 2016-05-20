/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file RTPSParticipant.h
 */


#ifndef RTPSParticipant_H_
#define RTPSParticipant_H_

#include <cstdlib>
#include <memory>
#include "../filters/FlowFilter.h"
#include "../../fastrtps_dll.h"
#include "../common/Guid.h"

namespace eprosima {
namespace fastrtps{

class TopicAttributes;
class WriterQos;
class ReaderQos;

namespace rtps {

class RTPSParticipantImpl;
class RTPSWriter;
class RTPSReader;


/**
 * @brief Class RTPSParticipant, contains the public API for a RTPSParticipant.
 * @ingroup RTPS_MODULE
 */
class RTPS_DllAPI RTPSParticipant
{
	friend class RTPSParticipantImpl;
	friend class RTPSDomain;
private:
	/**
	 * Constructor. Requires a pointer to the implementation.
	* @param pimpl Implementation.
	*/
	RTPSParticipant(RTPSParticipantImpl* pimpl);
	virtual ~ RTPSParticipant();
public:
	//!Get the GUID_t of the RTPSParticipant.
	const GUID_t& getGuid() const ;
	//!Force the announcement of the RTPSParticipant state.
	void announceRTPSParticipantState();
//	//!Method to loose the next change (ONLY FOR TEST). //TODO remove this method because is only for testing
//	void loose_next_change();
	//!Stop the RTPSParticipant announcement period. //TODO remove this method because is only for testing
	void stopRTPSParticipantAnnouncement();
	//!Reset the RTPSParticipant announcement period. //TODO remove this method because is only for testing
	void resetRTPSParticipantAnnouncement();
	/**
	 * Indicate the Participant that you have discovered a new Remote Writer.
	 * This method can be used by the user to implements its own Static Endpoint
	 * Discovery Protocol
	 * @param pguid GUID_t of the discovered Writer.
	 * @param userDefinedId ID of the discovered Writer.
	 * @return True if correctly added.
	 */
	bool newRemoteWriterDiscovered(const GUID_t& pguid, int16_t userDefinedId);
	/**
	 * Indicate the Participant that you have discovered a new Remote Reader.
	 * This method can be used by the user to implements its own Static Endpoint
	 * Discovery Protocol
	 * @param pguid GUID_t of the discovered Reader.
	 * @param userDefinedId ID of the discovered Reader.
	 * @return True if correctly added.
	 */
	bool newRemoteReaderDiscovered(const GUID_t& pguid, int16_t userDefinedId);
	/**
	 * Get the Participant ID.
	 * @return Participant ID.
	 */
	uint32_t getRTPSParticipantID() const;
	/**
	 * Register a RTPSWriter in the builtin Protocols.
	 * @param Writer Pointer to the RTPSWriter.
	 * @param topicAtt Topic Attributes where you want to register it.
	 * @param wqos WriterQos.
	 * @return True if correctly registered.
	 */
	bool registerWriter(RTPSWriter* Writer,TopicAttributes& topicAtt,WriterQos& wqos);
	/**
	 * Register a RTPSReader in the builtin Protocols.
	 * @param Reader Pointer to the RTPSReader.
	 * @param topicAtt Topic Attributes where you want to register it.
	 * @param rqos ReaderQos.
	 * @return True if correctly registered.
	 */
	bool registerReader(RTPSReader* Reader,TopicAttributes& topicAtt,ReaderQos& rqos);
	/**
	 * Update writer QOS
	 * @param Writer to update
	 * @param wqos New writer QoS
	 * @return true on success
	 */
	bool updateWriter(RTPSWriter* Writer,WriterQos& wqos);
	/**
	 * Update reader QOS
	 * @param Reader to update
	 * @param rqos New reader QoS
	 * @return true on success
	 */
	bool updateReader(RTPSReader* Reader,ReaderQos& rqos);

   void add_flow_filter(std::unique_ptr<FlowFilter> filter);

private:
	//!Pointer to the implementation.
	RTPSParticipantImpl* mp_impl;
};

}
} /* namespace rtps */
} /* namespace eprosima */

#endif /* RTPSParticipant_H_ */





