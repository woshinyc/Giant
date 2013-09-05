#include "HTTPHelper.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

HTTPHelper::HTTPHelper(void)
{

}


HTTPHelper::~HTTPHelper(void)
{
}

static HTTPHelper *s_HTTPHelper = NULL;
HTTPHelper *HTTPHelper::shared()
{
	if (!s_HTTPHelper)
	{
		s_HTTPHelper = new HTTPHelper();
		CCHttpClient::getInstance()->setTimeoutForRead(120);
	}
	return s_HTTPHelper;
}

bool HTTPHelper::post(string url, CCObject *pTarget, SEL_CallFuncND pSelector,const char *requestData)
{
	CCHttpRequest *request = new CCHttpRequest();
	request ->setUrl(url.c_str());
	request->setRequestType(CCHttpRequest::kHttpPost);
	request->setResponseCallback(pTarget,pSelector);
	if (requestData)
	{
		request->setRequestData(requestData,strlen(requestData));
	}
    CCHttpClient::getInstance()->send(request);
	request->release();
	return true;
}
bool HTTPHelper::get(string url,CCObject *pTarget,SEL_CallFuncND pSelector,const char *requestData)
{
	CCHttpRequest *request = new CCHttpRequest();
	request->setUrl(url.c_str());
	request->setRequestType(CCHttpRequest::kHttpGet);
request->setResponseCallback(pTarget,pSelector);
if (requestData)
{
	request->setRequestData(requestData,strlen(requestData));
}
CCHttpClient::getInstance()->send(request);
request->release();
return true;

}

CCString *HTTPHelper::JsonFromResponse(void *data)
{
  CCHttpResponse *response = (CCHttpResponse *)data;
  if (!response)
  {
	  return NULL;
  }
  if (!response->isSucceed())
  {
//	  switch (response->getResponseCode())
//	  {
//	  case  SESSIONID_EXPIRED:
//		  {
//			  
//
//		  }
//		    break;
//	  case  NO_NETWORK:
//		  {
//
//
//		  }
//	  case  BAD_SERVER:
//		  {
//
//
//		  }
//		    break;
//	  case  BAD_REQUEST:
//		  {
//
//
//		  }
//		   break;
//	  default:
//		  {
//
//		  }
//		  break;
//	  }
	  return NULL;
  }
  std::vector<char> *buffer = response->getResponseData();
  std::string json ;
  for (unsigned int i =0;i <buffer->size();i++)
  {
	  json +=(*buffer)[i];
  }

  return CCStringMake(json.c_str());
}

