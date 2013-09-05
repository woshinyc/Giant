//
//  SqlHelper.cpp
//  sangocard
//
//  Created by Zhang Xu on 12-12-3.
//
//

#include "SqlHelper.h"
using namespace std;


static SqlHelper *s_SQLite= NULL;

SqlHelper* SqlHelper::sharedSQHelper(void)
{
    if (!s_SQLite)
    {
        s_SQLite = new SqlHelper();
    }
    return s_SQLite;
}


int SqlHelper::ExcyteQuery(const char* sql)
{
    return 0;
}


bool SqlHelper::getDBWithName(const char *dbName)
{
    std::string sqlstr=dbName;
    sqlstr=sqlstr+".db";
    int result;
    result = sqlite3_open(sqlstr.c_str(), &pDB);
    if (result !=SQLITE_OK) {
        CCLOG("打开数据库失败，错误码:%d",result);
        return false;
    }
    return true;
}
bool SqlHelper::createTableWithSQLString(const char *sqlString)
{

    return runSqlStringAndErrLog(sqlString, "创建表失败");
    
}

bool SqlHelper::insertDataWithSQLString(const char *sqlString)
{

    return runSqlStringAndErrLog(sqlString, "插入记录失败");
}


 bool SqlHelper::updateDataWithSQLString(const char *sqlString)
{

    return runSqlStringAndErrLog(sqlString, "更新记录失败");

}
void SqlHelper::close()
{

sqlite3_close(pDB); 
}

bool SqlHelper::runSqlStringAndErrLog(const char *sqlString,const char *log)
{
    int result;
    char * errMsg = NULL;
    result=sqlite3_exec(pDB, sqlString, NULL, NULL, &errMsg);
    if (result !=SQLITE_OK) {
       // CCLOG("%s 错误码:%d,错误原因:%s\n",log,result,errMsg);
    }
    return true;
}


int isExisted( void * para, int n_column, char ** column_value, char ** column_name )
{
    
    
    bool *isExisted_=(bool*)para;
    *isExisted_=(**column_value)!='0';
    return 0;

}



int loadRecordCount( void * para, int n_column, char ** column_value, char ** column_name )
{
    int *count=(int*)para;
    *count=n_column;
    return 0;
}



int loadRecord( void * para, int n_column, char ** column_value, char ** column_name )
{
        printf("ID=%s,name=%s",column_value[0],column_value[1]);
        return 0;
}



bool SqlHelper::isTable(const char *sqlString)
{
    
  
   bool isExisted_;
    char * errMsg = NULL;
    sqlite3_exec(pDB, sqlString, isExisted, &isExisted_, &errMsg );

    return isExisted_;
    
}
bool SqlHelper::isData(const char *sqlString)
{
    
    
   bool isExisted_;
  char * errMsg = NULL;
  sqlite3_exec( pDB, sqlString , isExisted, &isExisted_, &errMsg );
 return isExisted_;
}
int SqlHelper::getCount(const char *sqlString)
{
    int count ;
    char * errMsg = NULL;
    sqlite3_exec(pDB, sqlString, isExisted, &count, &errMsg );

    return count;
}

void SqlHelper::logData(const char *sqlString)
{
    
    
   char * errMsg = NULL;
   sqlite3_exec( pDB, sqlString , loadRecord, NULL, &errMsg );
    

}



