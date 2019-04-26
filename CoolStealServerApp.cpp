#include <iostream>
#include <string>
#include "models/Program.h"

#include "CoolStealServerApp.h"

#define GET "GET"
#define POST "POST"
#define APP_JSON "application/json"
#define SEND_METRIC "/SendMetric"
#define GET_METRIC "/GetMetric"
#define SEND_PROGRAM "/SendProgram"
#define SEND_Metric "/SendMetric"

class CTodoHandler : public HTTPRequestHandler {
 public:
  void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp) {
    URI uri(req.getURI());
    string method = req.getMethod();

    cerr << "URI: " << uri.toString() << endl;
    cerr << "Method: " << req.getMethod() << endl;

    StringTokenizer tokenizer(uri.getPath(), "/", StringTokenizer::TOK_TRIM);
    HTMLForm form(req, req.stream());
    cerr << "Content type: " << req.getContentType() << endl;
    //        std::string json = "{ \"test\" : \"mem\" }";


    if (!method.compare(POST)) {
      std::string jsonTest = "{ \"id\": 0, \"sourseCode\": \"string\",\"lang\": \"string\" }";
      istream &stream = req.stream();
      /// getline(stream,jsonTest);
//            int len = req.getContentLength();
//
//            char* buffer = new char[len];
//            stream.getline(buffer,len);

//            Poco::Dynamic:: Var result = parser.parse(jsonTest);
//            JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
//            cerr<<"Content type: "<<object->get("test").convert<std::string>()<<endl;
//            cerr<<"Content type: "<<object<<endl;
      cerr << "Json: " << jsonTest << endl;
      //std::string json = result.toString();



      if (req.getURI().find(SEND_PROGRAM) != std::string::npos) {

        Program programmFromReq;
        rapidjson::Document doc;
        doc.Parse(jsonTest.c_str());
        programmFromReq = programmFromReq.fromJSON(doc);
        // TODO: SEND PROGRAM TO ROUTER
        cerr << "Send program to check";
      } else {
        // TODO: JSON PARSER
        cerr << "SendMetric";
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
        //TODO: out<<router.getNewId<<endl;

        out.flush();
      }
    }

  }
};

#include <iostream>
#include <fstream>
#include <map>

class TodoRequestHandlerFactory : public HTTPRequestHandlerFactory {
 public:
  virtual HTTPRequestHandler *createRequestHandler(const HTTPServerRequest &request) {
    return new CTodoHandler;
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