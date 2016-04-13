#include <cstdio>
#include <sqlite3.h> 
#include <string> 

class SQLiteAccess{
	private:
		sqlite3 * db;

	public:
		SQLiteAccess(std::string nameBase);
		~SQLiteAccess();

		int sqlRequest(std::string sqlStatement);
		int sqlAddUser(std::string username, std::string password, std::string addmail);
};

static int callback(void *data, int argc, char **argv, char **azColName);