
#ifndef SIMULATOR_DATA_H
#define SIMULATOR_DATA_H

#include <map>
#include <mutex>
#include <string>
#include <vector>
#include "Expression.h"
#include "Lexer.h"
#include "CommandExpression.h"

using namespace std;

class Data {
    Lexer lexer;
    map<string, Expression *> simulator_data;
    map<string, string> binds;
    map<string, double> symbol_table;
    vector<string> paths;
    map<string, double> path_values;
    vector<pair<string, double>> new_plane_data;
    vector<pair<string, double>> path_value;
    mutable mutex m;

public:
    void setNewPlaneData(string var, double val);
    void setSimulatorData(string cmd, Expression* ce);
    void setBinds(string var_name, string path);
    string getBind(string var);
    void setSymbolTable(string symbol, double value);
    const map<string, double> &getSymbolTable() const;
    void initializePaths();
    vector<string> getPaths();
    void initializePathValues();
    void setPathValues(string values);
    double getValue(string var);
    map<string,string>& getBinds();
    auto get_and_clear() {
        lock_guard<mutex> g(m);
        auto output = new_plane_data;
        new_plane_data.clear();
        return output;
    }
    void update_path_value(int index, double value);
};

#endif //SIMULATOR_DATA_H