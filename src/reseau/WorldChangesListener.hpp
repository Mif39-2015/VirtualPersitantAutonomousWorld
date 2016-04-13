/**
 * \file WorldChangesListener.hpp
 * \brief WorldChangesListener class definition
 */
#ifndef _WORLDCHANGESLISTENER_
#define _WORLDCHANGESLISTENER_

#include <iostream>
#include "UdpBroadcaster.hpp"
#include "NetworkAdapter.hpp"

class NetworkAdapter;

/**
 * \class WorldChangesListener
 * \brief Object listening to the world for changes
 */
class WorldChangesListener {
	private:
		UdpBroadcaster changesBroadcaster;
		NetworkAdapter* netAdapter;
	public:
		WorldChangesListener();
		void notify(void* changes); // Called by the world simulation module when a change needs to be broadcasted to clients
};

#endif
