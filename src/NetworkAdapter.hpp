/**
 * \file NetworkAdapter.hpp
 * \brief NetworkAdapter class definition
 */
#ifndef _NETWORKADAPTER_
#define _NETWORKADAPTER_

#include <iostream>
#include <vector>
#include "message/Message.hpp"
#include "message/WorldChangeMessage.hpp"
#include "WorldChangesListener.hpp"
#include "AuthenticationModule.hpp"


class WorldChangesListener;

using namespace std;

/**
 * \class NetworkAdapter
 * \brief Link with the network block
 */
class NetworkAdapter {
	private:
		AuthenticationModule auth;
		WorldChangesListener* worldChangesListener;
	public:
		NetworkAdapter(WorldChangesListener* _worldChangesListener);
};

#endif
