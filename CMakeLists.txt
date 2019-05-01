cmake_minimum_required(VERSION 3.10)
project(CoolSteal)

set(CMAKE_CXX_STANDARD 11)

add_executable(CoolSteal main.cpp models/Program.h models/Program.cpp models/PlagiasmResult.cpp models/PlagiasmResult.h models/Token.cpp models/Token.h models/TokenType.h models/DBCommand.cpp models/DBCommand.h methods/CheckLibary.h lexUtils/LexerInterface.h Normalizator/NormalizatorInterface.h CoolStealServerApp.cpp CoolStealServerApp.h Router.cpp Router.h PlagiasmChecker.cpp PlagiasmChecker.h)

# set the POCO paths and libs
set(POCO_PREFIX      "/home/anton/Programs/CoolSteal/poco-1.7.5") # the directory containing "include" and "lib"
#set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib/Linux/x86_64")
set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoNet.a"
        "${POCO_LIB_DIR}/libPocoUtild.a"
        "${POCO_LIB_DIR}/libPocoJSONd.a"
        "${POCO_LIB_DIR}/libPocoXMLd.a"
        "${POCO_LIB_DIR}/libPocoFoundationd.a"
        "pthread")

# set the include path for the app
#target_include_directories(PocoTestProject PRIVATE "${POCO_INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(CoolSteal "${POCO_LIBS}")