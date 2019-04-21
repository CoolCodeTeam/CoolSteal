//
// Created by anton on 19.04.19.
//

#ifndef COOLSTEALNIGHT_DBCOMMAND_H
#define COOLSTEALNIGHT_DBCOMMAND_H


#include <string>

class DBCommand {
public:
    DBCommand(const std::string &Command);

    DBCommand();

    const std::string &getCommand() const;

    void setCommand(const std::string &Command);

private:
    std::string Command;

};


#endif //COOLSTEALNIGHT_DBCOMMAND_H
