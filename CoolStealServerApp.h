//
// Created by anton on 26.04.19.
//

#pragma once

#include <Poco/Mutex.h>
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/Path.h"
#include "Poco/ScopedLock.h"
#include "Poco/StringTokenizer.h"
#include "Poco/URI.h"
#include "Poco/JSON/JSON.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Util/ServerApplication.h"
#include "Router.h"

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class CoolStealServerApp : public ServerApplication {
 public:


 protected:
  int main(const vector<string> &);

 private:


};