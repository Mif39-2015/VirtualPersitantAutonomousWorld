/**
 * \file Message.hpp
 * \brief Message class definition. Also defines message IDs
 */
#ifndef _MESSAGE_
#define _MESSAGE_

// *** Message IDs definition
//  * Recieved from client (starts from 0)


//  * Sent to client (starts from 1000)
#define WORLDCHANGEMESSAGE_ID 1000


#include <iostream>

/**
 * \class Message
 * \brief Abstract super-class for all messages sent and recieved over the network
 */
class Message {
	private:
		short messageId;
	protected:
		Message(short _messageId);
};

#endif
