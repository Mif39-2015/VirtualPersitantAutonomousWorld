#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "db/sqliteInterface.hpp"

using std::vector;
using std::map;

/*constructeur*/
SQLiteAccess::SQLiteAccess(std::string nameBase){
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open(nameBase.c_str(), &db);
	tableName="user";

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

int SQLiteAccess::sqlAddUser(std::string username, std::string password, std::string addmail){
	std::string adduser = "INSERT into user values((Select (max(id)+1) from user),'"+username+"','"+password+"','"+addmail+"',1);";
	return sqlRequest(adduser);
}
int SQLiteAccess::sqlDelUser(std::string username){
	std::string deluser = "delete from user where nickname = '"+username+"';";
	return sqlRequest(deluser);
}
int SQLiteAccess::sqlDelUser(int id){
	std::string deluser = "delete from user where id = "+id+';';
	return sqlRequest(deluser);
}

void SQLiteAccess::sqlSetTableUp(){

	int existsTableUser=sqlRequest("Select * from "+tableName);

	if(existsTableUser==1){
		std::cout<<"=Création de la table "<<tableName<<"="<<std::endl;	
		sqlRequest("CREATE TABLE "+tableName+"(id integer primary key autoincrement ,Nickname text unique, password TEXT, email_address TEXT unique,privileges integer check(privileges <=1 and privileges >=0) );");
		if(!(sqlRequest("Insert into "+tableName+" values (0,'root','root','',0);"))){
			sqlRequest("DROP TABLE "+tableName+";");
		}else{
			if(!(sqlRequest("Insert into "+tableName+" values (1,'noob','noob','merys.piegay@gmail.com',1);"))){
				sqlRequest("DROP TABLE "+tableName+";");

			}
		}
	}else{
		std::cout<<"=Table "+tableName+" existante="<<std::endl;	
	}

}
std::string SQLiteAccess::sqlGetRequest(std::string sql){
	char *zErrMsg = 0;
	int nrows;
	int ncols;
	char** result=NULL;
	std::string a;
	std::string retour="";
	int rc = sqlite3_get_table(db, sql.c_str(), &result, &nrows, &ncols, &zErrMsg);
	int k=0;
	for(int i=0;i<=nrows;i++){
		for(int j=0;j<ncols;j++){
		//	std::cout<<result[k]<<"|";
			retour = retour+(result[k]?result[k]:"NULL")+"|";

			k++;
		}
		retour = retour+"\n";
		//std::cout<<std::endl;
	}

	sqlite3_free_table(result);

	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Operation done successfully\n");
	}
	return retour;
}

/*fonction affichage de la réponse de la requete (fonction de débug)*/
int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}


