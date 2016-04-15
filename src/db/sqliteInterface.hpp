#include <iostream>
#include <cstdio>
#include <sqlite3.h> 
#include <string> 
#include <vector> 
#include <map> 
using std::vector;
using std::map;

class SQLiteAccess{
	private:
		sqlite3 * db;
		std::string tableName;

	public:
		SQLiteAccess(std::string nameBase);
		~SQLiteAccess();

		std::string sqlGetRequest(std::string sql);
		int sqlRequest(std::string sqlStatement);
		int sqlAddUser(std::string username, std::string password, std::string addmail);
		void sqlSetTableUp();
};

int callback(void *data, int argc, char **argv, char **azColName);
