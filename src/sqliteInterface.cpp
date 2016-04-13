#include <stdio.h>
#include <sqlite3.h> 
#include <string>
using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
sqlite3* connectDB(string nameBase)
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	
	rc = sqlite3_open(nameBase.c_str(), &db);

	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return NULL;
	}else{
		fprintf(stderr, "Opened database successfully\n");
	}
	return db;
}

void sqlRequest(string sqlStatement,sqlite3*db){
	char *zErrMsg = 0;
	const char* data = "Callback function called";
	int rc = sqlite3_exec(db, sqlStatement.c_str(), callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);

}
sqlite3* disconnectDB(sqlite3 * db)
{
	sqlite3_close(db);

}
