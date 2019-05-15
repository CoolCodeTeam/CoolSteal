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

  CoolStealServerApp app;
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return app.run(argc, argv);

}