
#ifndef SIMULATOR_ASSIGN_H
#define SIMULATOR_ASSIGN_H

#include "Command.h"
#include "Data.h"

extern Data data;

class Assign : public Command {
    string var;
    string value;

public:
    Assign(string var, string value);
    virtual double execute();
};

#endif //SIMULATOR_ASSIGN_H
