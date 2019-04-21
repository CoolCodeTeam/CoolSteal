cmake_minimum_required(VERSION 3.10)
project(CoolStealNight)

set(CMAKE_CXX_STANDARD 11)

add_executable(CoolStealNight main.cpp models/Program.h models/Program.cpp models/PlagiasmResult.cpp models/PlagiasmResult.h models/Token.cpp models/Token.h models/TokenType.h models/DBCommand.cpp models/DBCommand.h methods/CheckLibary.h lexUtils/LexerInterface.h Normalizator/NormalizatorInterface.h)