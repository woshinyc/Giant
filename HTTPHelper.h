#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
class HTTPHelper
{

public:
	HTTPHelper(void);
	~HTTPHelper(void);
	static HTTPHelper* shared();
	const char* path;
	bool post(std::string, cocos2d::CCObject*, cocos2d::SEL_CallFuncND, const char* = NULL);
	bool get(std::string, cocos2d::CCObject*, cocos2d::SEL_CallFuncND, const char* = NULL);

	static std::string updateLocalFile(const char *fileName,const char *type = "",const char *pixe = "");
    static cocos2d::CCString* JsonFromResponse(void *);
	int downLoad(const char *,const char *,void*,int (*Callback)());
	int downLoadList(const char*, const char*, char**, int);
};

