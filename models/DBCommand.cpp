//
// Created by anton on 19.04.19.
//

#include "DBCommand.h"

DBCommand::DBCommand(const std::string &Command) : Command(Command) {}

DBCommand::DBCommand() {}

const std::string &DBCommand::getCommand() const {
    return Command;
}

void DBCommand::setCommand(const std::string &Command) {
    DBCommand::Command = Command;
}
