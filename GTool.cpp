//
//  GTool.cpp
//  Giant
//
//  Created by Mac on 13-9-3.
//
//

#include "GTool.h"
std::string DTool::formartTimeToString(int timeStamp)
{
    std::string str ;
    
    time_t time = timeStamp;
    tm * localnow = localtime(&time);
    
    int mon = localnow->tm_mon;
    int day = localnow->tm_mday;
    int whour = localnow->tm_hour;
    int wminute = localnow->tm_min;
    int wsecond = localnow->tm_sec;
    
    //    int wminute = timeStamp / 60 ;
    //    int wsecond = timeStamp % 60 ;
    
    str = CCString::createWithFormat("%02d点:%02d分",whour,wminute)->getCString() ;
    
    return str ;
}