#ifndef  __CLI_H__
#define  __CLI_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class CLI{

public:
    std::string read();
    std::vector<std::string> parse(std::string & s);
    void write(std::string action_result);
};





#endif //__CLI_H__