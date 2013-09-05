//
//  SqlHelper.h
//  sangocard
//
//  Created by Zhang Xu on 12-12-3.
//
//

#ifndef __sangocard__SqlHelper__
#define __sangocard__SqlHelper__

#include "cocos2d.h"
#include "sqlite3.h"


class SqlHelper : public cocos2d::CCNode
{
public:
    static SqlHelper* sharedSQHelper(void);
    
    int ExcyteQuery(const char* sql);
    
    
    
    sqlite3 *pDB ;//数据库指针
//    char * errMsg ;//错误信息

    
bool getDBWithName(const char *dbName);
    bool createTableWithSQLString(const char *sqlString);
    bool insertDataWithSQLString(const char *sqlString);
    bool updateDataWithSQLString(const char *sqlString);
    void close();
  bool runSqlStringAndErrLog(const char *sqlString,const char *log);
   bool isTable(const char *sqlString);//表是否存在;
bool isData(const char *sqlString);
int getCount(const char *sqlString);  //获取纪录条数
void logData(const char *sqlString);   //打印一条数据


};

#endif /* defined(__sangcard__SqlHelper__) */
