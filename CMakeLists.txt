cmake_minimum_required(VERSION 3.10)
project(CoolSteal)

set(CMAKE_CXX_STANDARD 11)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(CoolSteal main.cpp models/Program.h models/Program.cpp models/PlagiasmResult.cpp models/PlagiasmResult.h models/Token.cpp models/Token.h models/TokenType.h models/DBCommand.cpp models/DBCommand.h methods/CheckLibaryInterface.h lexUtils/LexerInterface.h Normalizator/NormalizatorInterface.h CoolStealServerApp.cpp CoolStealServerApp.h Router.cpp Router.h PlagiasmChecker.cpp PlagiasmChecker.h methods/Checker.h methods/ShingleChecker.cpp methods/ShingleChecker.h methods/CheckLibary.cpp methods/CheckLibary.h methods/LevenstainChecker.cpp methods/LevenstainChecker.h lexUtils/LexerCpp.cpp lexUtils/LexerCpp.h lexUtils/TokenSet.h lexUtils/CKeyWords.cpp lexUtils/CKeyWords.h lexUtils/OperatorSet.cpp lexUtils/OperatorSet.h lexUtils/VariableSet.cpp lexUtils/VariableSet.h lexUtils/lexer_check.cpp Normalizator/Normalizator.cpp Normalizator/Normalizator.h Normalizator/NormalizeAlgorhitm.h Normalizator/CppNormaizeAlgorithm.cpp Normalizator/CppNormaizeAlgorithm.h tests/LevenstainTests.cpp tests/shingleTests.cpp tests/lexerTests.cpp tests/normalizerTests.cpp DataBase/DBManager.cpp DataBase/DBManager.h)

# set the POCO paths and libs
set(POCO_PREFIX      "${PROJECT_SOURCE_DIR}/POCO") # the directory containing "include" and "libs"
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(LIB_DIR     "${PROJECT_SOURCE_DIR}/libs")
set(POCO_LIBS        "${LIB_DIR}/libPocoNet.a"
        "${LIB_DIR}/libPocoUtild.a"
        "${LIB_DIR}/libPocoJSONd.a"
        "${LIB_DIR}/libPocoXMLd.a"
        "${LIB_DIR}/libPocoFoundationd.a"
        "pthread")

# set the include path for the app
include_directories(CoolSteal  "${INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(CoolSteal "${POCO_LIBS}")
target_link_libraries(CoolSteal ${GTEST_LIBRARIES} pthread)