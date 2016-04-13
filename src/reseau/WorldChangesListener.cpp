/**
 * \file WorldChangesListener.cpp
 * \brief Implementation of WorldChangesListener.hpp
 */
#include "WorldChangesListener.hpp"

WorldChangesListener::WorldChangesListener()
: changesBroadcaster(), netAdapter(new NetworkAdapter(this)){
	
}

void WorldChangesListener::notify(void* changes){
	// TODO
}
