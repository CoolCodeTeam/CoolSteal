#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>
#include <gtest/gtest.h>
#include "CoolStealServerApp.h"
#include "DataBase/DBManager.h"

using namespace db::postgres;

int StartDataBase();

int main(int argc, char **argv) {
  DBManager db;

//  cout << db.getNewId() << endl;
//
//  Program p;
//  p.setLang("CPP");
//  p.setShingleSet(set<string>{"lol"});
//  p.setOwnerId(1);
//  p.setId(1);
//  p.setName("lol");
//  p.setTokenSet("lol");
//  p.setNormalizeCode("lol");
//  p.setSourseCode("ll");
//
//  db.addProgram(p);
//
//  cout << db.getNewId() << endl;

  cout << db.getProgram(1);



  CoolStealServerApp app;
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return app.run(argc, argv);


}