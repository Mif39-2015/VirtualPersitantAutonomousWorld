#include <stdio.h>
#include <sqlite3.h> 
#include <string> 

using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName);
sqlite3* connectDB(string nameBase);
void sqlRequest(string sqlStatement,sqlite3*db);	

sqlite3* disconnectDB(sqlite3* db);
