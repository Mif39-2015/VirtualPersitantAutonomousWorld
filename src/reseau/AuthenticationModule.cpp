/**
 * \file AuthenticationModule.cpp
 * \brief Implementation of AuthenticationModule.hpp
 */
#include "AuthenticationModule.hpp"


AuthenticationModule::AuthenticationModule(){
	
}

int AuthenticationModule::registerClient(string username, string password){

    return 0;
}

bool AuthenticationModule::removeClient(string username, string password){

    return false;
}

bool AuthenticationModule::authClient(string username, string password){

    return true;
}
