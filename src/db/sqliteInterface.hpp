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
};

static int callback(void *data, int argc, char **argv, char **azColName);