#include <iostream>
#include <string>
#include "rapidjson/stringbuffer.h"
#include <rapidjson/writer.h>
#include "models/Program.h"
#include "models/PlagiasmResult.h"

#include "CoolStealServerApp.h"

#define GET "GET"
#define POST "POST"
#define APP_JSON "application/json"
#define SEND_METRIC "/SendMetric"
#define GET_METRIC "/GetMetric"
#define SEND_PROGRAM "/SendProgram"
#define SEND_Metric "/SendMetric"

class PlagiasmHandler : public HTTPRequestHandler {
 public:
  void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp) {
    URI uri(req.getURI());
    string method = req.getMethod();

    cerr << "URI: " << uri.toString() << endl;
    cerr << "Method: " << req.getMethod() << endl;
    cerr << "Content type: " << req.getContentType() << endl;


    if (!method.compare(POST)) {
      istream &stream = req.stream();
      int len = req.getContentLength();

      char *buffer = new char[len];
      stream.read(buffer, len);
      cerr << "Json: " << buffer << endl;
      rapidjson::Document doc;
      doc.Parse(buffer);
      if (req.getURI().find(SEND_PROGRAM) != std::string::npos) {

        Program programmFromReq;
        programmFromReq = programmFromReq.fromJSON(doc);
        cerr << "Send program to check :" << programmFromReq << endl;
        PlagiasmResult result = router.checkProgram(programmFromReq);
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType(APP_JSON);
        ostream &out = resp.send();
        out<<getStringFromJson(result.toJSON());
        out.flush();

      } else {
        PlagiasmResult metricFromReq;
        metricFromReq = metricFromReq.fromJson(doc);
        cerr << "SendMetric :" << metricFromReq << endl;
      }

    } else if (!method.compare(GET)) {
      if (req.getURI().find(GET_METRIC) != std::string::npos) {
        cerr << "GetMetric";
        //TODO: Узнать зачем это
      } else {
        cerr << "GetNewId";
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType(APP_JSON);
        ostream &out = resp.send();
        out<<router.getNewId();
        out.flush();
      }
    }

  }
 private:
  Router router;
  const char* getStringFromJson(rapidjson::Document doc);
};

const char *PlagiasmHandler::getStringFromJson(rapidjson::Document doc) {
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  doc.Accept(writer);

// Output {"project":"rapidjson","stars":11}
  return buffer.GetString();
}

#include <iostream>
#include <fstream>
#include <map>

class TodoRequestHandlerFactory : public HTTPRequestHandlerFactory {
 public:
  virtual HTTPRequestHandler *createRequestHandler(const HTTPServerRequest &request) {
    return new PlagiasmHandler;
  }
};

int CoolStealServerApp::main(const vector<string> &) {
  HTTPServerParams *pParams = new HTTPServerParams;

  pParams->setMaxQueued(100);
  pParams->setMaxThreads(16);

  HTTPServer s(new TodoRequestHandlerFactory, ServerSocket(8000), pParams);

  s.start();
  cerr << "Server started" << endl;

  waitForTerminationRequest();  // wait for CTRL-C or kill

  cerr << "Shutting down..." << endl;
  s.stop();


  return Application::EXIT_OK;
}