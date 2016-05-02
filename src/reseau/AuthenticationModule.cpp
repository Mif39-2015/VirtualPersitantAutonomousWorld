/**
 * \file AuthenticationModule.cpp
 * \brief Implementation of AuthenticationModule.hpp
 */
#include "reseau/AuthenticationModule.hpp"
#include "db/sqliteInterface.hpp"

AuthenticationModule::AuthenticationModule() :
dbAccess(SQLiteAccess("user.db"))
{
}

int AuthenticationModule::registerClient(string username, string password, string mail){
	return dbAccess.sqlAddUser(username, password, mail);
}

int AuthenticationModule::removeClient(string username){
	return dbAccess.sqlDelUser(username);
}

int AuthenticationModule::removeClient(int id){
	return dbAccess.sqlDelUser(id);
}

int AuthenticationModule::authClient(string username, string password){
	string result= dbAccess.sqlGetRequest("Select id from user where nickname = '" + username + "' and password = '" + password + "'");
	vector<string>results=split(result,'\n');
	result=split(results[1],'|')[0];
	if(!(result.length()<=0)){
		result = -1;
	}
	return atoi(result.c_str());
}

vector<string> AuthenticationModule::split(string str,char delimiter){
	vector<string>retour;
	retour.push_back("");
	for(unsigned int i=0;i<str.length();i++){
		if(str[i]!=delimiter) 
			retour[retour.size()-1]=retour[retour.size()-1]+str[i];		
		else
			retour.push_back("");
	}
	return retour;
}
