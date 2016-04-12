/**
 * \file WorldChangeMessage.hpp
 * \brief WorldChangeMessage class definition
 */
#ifndef _WORLDCHANGEMESSAGE_
#define _WORLDCHANGEMESSAGE_

#include <iostream>
#include "Message.hpp"

using namespace std;

/**
 * \class WorldChangeMessage
 * \brief Message class for sending world updates to clients
 */
class WorldChangeMessage : Message {
	private:
		string data;
	public:
		WorldChangeMessage(string _data);
};

#endif
