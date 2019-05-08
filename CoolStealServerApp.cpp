#include <iostream>
#include <string>
#include <rapidjson/stringbuffer.h>
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
#define COMPARE "/Compare"
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
      //TODO: Обработка исключений
      istream &stream = req.stream();
      streamsize len = req.getContentLength();

      char *buffer = new char[len]();
      stream.read(buffer, len );

      cerr << "Json: " << buffer << endl;
      rapidjson::Document doc;
      try{
        doc.Parse(buffer);
      }catch (Exception e){
        cerr<<"mem";
      }

      if (req.getURI().find(SEND_PROGRAM) != std::string::npos) {


        Program programmFromReq;
        programmFromReq = programmFromReq.fromJSON(doc);
        cerr << "Send program to check :" << programmFromReq << endl;
        PlagiasmResult result = router.checkProgram(programmFromReq);
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType(APP_JSON);
        ostream &out = resp.send();
        out << getStringFromJson(result.toJSON());
        out.flush();
      } else if(req.getURI().find(COMPARE) != std::string::npos){
        Program firstProgramFromReq;
        Program secondProgramFromReq;
        const rapidjson::Value& a = doc["programs"];
        assert(a.IsArray());
        firstProgramFromReq = firstProgramFromReq.fromJSON(a[0]);
        secondProgramFromReq = secondProgramFromReq.fromJSON(a[1]);
        cerr << "Send programs to check :" << firstProgramFromReq << endl;
        cerr <<  secondProgramFromReq << endl;
        PlagiasmResult result = router.comparePrograms(firstProgramFromReq,secondProgramFromReq);
        cerr<<"result :"<<getStringFromJson(result.toJSON())<<endl;
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType(APP_JSON);
        ostream &out = resp.send();
        out << getStringFromJson(result.toJSON());
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
  std::string getStringFromJson(rapidjson::Document doc);
};

std::string PlagiasmHandler::getStringFromJson(rapidjson::Document doc) {
  rapidjson::StringBuffer buffer;
  rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
  doc.Accept(writer);

// Output {"project":"rapidjson","stars":11}
  std::string s(buffer.GetString(), buffer.GetSize());
  return s;
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

  HTTPServer s(new TodoRequestHandlerFactory, ServerSocket(8001), pParams);

  s.start();
  cerr << "Server started" << endl;

  waitForTerminationRequest();  // wait for CTRL-C or kill

  cerr << "Shutting down..." << endl;
  s.stop();


  return Application::EXIT_OK;
}