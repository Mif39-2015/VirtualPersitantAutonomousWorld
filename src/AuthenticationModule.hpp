/**
 * \file AuthenticationModule.hpp
 * \brief AuthenticationModule class definition
 */
#ifndef _AUTHENTICATIONMODULE_
#define _AUTHENTICATIONMODULE_

#include <iostream>
#include <vector>
#include "message/WorldChangeMessage.hpp"

using namespace std;

/**
 * \class AuthenticationModule
 * \brief Performs authentication operations
 * Authenticate, register account, etc
 */
class AuthenticationModule {
	public:
		AuthenticationModule();
		int registerClient(string username, string password); // Add new client
		bool removeClient(string username, string password); // Remove client
		bool authClient(string username, string password); // Returns true if client username/password match, false otherwise
};

#endif
