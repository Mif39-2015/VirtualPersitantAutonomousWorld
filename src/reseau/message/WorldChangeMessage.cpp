/**
 * \file WorldChangeMessage.cpp
 * \brief Implementation for WorldChangeMessage.hpp
 */
#include "WorldChangeMessage.hpp"


WorldChangeMessage::WorldChangeMessage(string _data)
: Message(WORLDCHANGEMESSAGE_ID), data(_data)
{
	
}
