#include <iostream>
#include <gtest/gtest.h>
#include "CoolStealServerApp.h"

int main(int argc, char** argv) {
     CoolStealServerApp app;
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return app.run(argc, argv);
    return 0;
}