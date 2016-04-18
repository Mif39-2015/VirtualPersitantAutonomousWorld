/**
 * \file AuthenticationModule.cpp
 * \brief Implementation of AuthenticationModule.hpp
 */
#include "AuthenticationModule.hpp"


AuthenticationModule::AuthenticationModule()/* :
dbAccess(SQLiteAccess("user"))*/
{
}

int AuthenticationModule::registerClient(string username, string password){
	//~ dbAccess.sqlAddUser(username, password, "");
    return 0;
}

bool AuthenticationModule::removeClient(string username){

    return false;
}

bool AuthenticationModule::removeClient(int id){

    return false;
}

bool AuthenticationModule::authClient(string username, string password){
	//~ string result= dbAccess.sqlGetRequest("Select id from user where nickname = '" + username + "' and password = '" + password + "'");
	//~ vector<string>results=split(result,'\n');
	//~ result=split(results[1],'|')[0];
	//~ if(result.length()<=0){
		//~ return false;
	//~ }
    return true;
}

vector<string> AuthenticationModule::split(string str,char delimiter){
	vector<string>retour;
	retour.push_back("");
	for(int i=0;i<str.length();i++){
		if(str[i]!=delimiter) 
			retour[retour.size()-1]=retour[retour.size()-1]+str[i];		
		else
			retour.push_back("");
	}
	return retour;
}
