cmake_minimum_required(VERSION 3.10)
project(CoolSteal)

set(CMAKE_CXX_STANDARD 11)

add_executable(CoolSteal main.cpp models/Program.h models/Program.cpp models/PlagiasmResult.cpp models/PlagiasmResult.h models/Token.cpp models/Token.h models/TokenType.h models/DBCommand.cpp models/DBCommand.h methods/CheckLibaryInterface.h lexUtils/LexerInterface.h Normalizator/NormalizatorInterface.h methods/PlagiasmCheckerInterface.h methods/ShingleChecker.cpp methods/ShingleChecker.h)