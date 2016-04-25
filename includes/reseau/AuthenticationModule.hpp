/**
 * \file AuthenticationModule.hpp
 * \brief AuthenticationModule class definition
 */
#ifndef _AUTHENTICATIONMODULE_
#define _AUTHENTICATIONMODULE_

#include <iostream>
#include <vector>

//~ #include "../db/sqliteInterface.hpp"

using namespace std;

/**
 * \class AuthenticationModule
 * \brief Performs authentication operations
 * Authenticate, register account, etc
 */
class AuthenticationModule {
	private:
		SQLiteAccess dbAccess;
		vector<string> split(string str,char delimiter);
	public:
		AuthenticationModule();
		int registerClient(string username, string password); // Add new client and returns his id
		int removeClient(string username); // Remove client from username
		int removeClient(int id); // Remove client from id
		int authClient(string username, string password); // Returns true if client username/password match, false otherwise
};

#endif
