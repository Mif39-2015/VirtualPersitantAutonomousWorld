/**
 * \file UdpBroadcaster.hpp
 * \brief UdpBroadcaster class definition
 */
#ifndef _UDPBROADCASTER_
#define _UDPBROADCASTER_

#include <iostream>
#include <vector>
#include "message/WorldChangeMessage.hpp"

using namespace std;

/**
 * \class UdpBroadcaster
 * \brief Broadcasts world changes via UDP to suscribed clients
 */
class UdpBroadcaster {
	private:
		vector<string> subscribers; // UDP subscribers. Will recieve world changes messages
	public:
		UdpBroadcaster();
		void broadcastWorldChangeToSubscribers(WorldChangeMessage message);
		void addSubscriber(string clientIpAddress);
		void removeSubscriber(string clientIpAddress);
};

#endif

