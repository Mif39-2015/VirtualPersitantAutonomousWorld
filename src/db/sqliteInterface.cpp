#include <stdio.h>
#include <sqlite3.h> 
#include <string>
#include "sqliteInterface.hpp"

/*constructeur*/
SQLiteAccess::SQLiteAccess(std::string nameBase){
	char *zErrMsg = 0;
	int rc;
	
	rc = sqlite3_open(nameBase.c_str(), &db);

	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}else{
		fprintf(stderr, "Opened database successfully\n");
	}
}

/*destructeur*/
SQLiteAccess::~SQLiteAccess(){
	sqlite3_close(db);
}

/*execution du code sql pour la base donnée en paramètre*/
int SQLiteAccess::sqlRequest(std::string sqlStatement){
	char *zErrMsg = 0;
	const char* data = "Callback function called";
	int rc = sqlite3_exec(db, sqlStatement.c_str(), callback, (void*)data, &zErrMsg);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}
	return rc;
}

/*fonction affichage de la réponse de la requete (fonction de débug)*/
static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}