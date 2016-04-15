#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "sqliteInterface.hpp"
#include "AuthenticationUser.hpp"

using namespace std;

AuthenticationUser::AuthenticationUser(string dbN,string userN,string userP){
	dbName=dbN;
	userName=userN;
	userPassword=userP;
}

AuthenticationUser::~AuthenticationUser(){

}

vector<string>split(string str,char delimiter);

string AuthenticationUser::checkUser() {
    SQLiteAccess sqla=SQLiteAccess(dbName);
    string result= sqla.sqlGetRequest("Select id from user where nickname = '"+userName+"' and password = '"+userPassword+"'");
    vector<string>results=split(result,'\n');
    result=split(results[1],'|')[0];
    
    if(result.length()<=0){
        result="-1";
    }
    
    return result;
}

vector<string>split(string str,char delimiter) {
    vector<string>retour;
    retour.push_back("");
    
    for(unsigned int i=0; i<str.length(); i++){
        if(str[i]!=delimiter) 
            retour[retour.size()-1]=retour[retour.size()-1]+str[i];		
        else
            retour.push_back("");
    }
    
    return retour;
}
