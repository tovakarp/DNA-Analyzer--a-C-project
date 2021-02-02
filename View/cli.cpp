//
// Created by chevi on 8/20/20.
//
#include "cli.h"

std::string CLI::read()
{
    std::cout << "> cmd >>> ";
    std::string command;
    getline(std::cin, command);

    return command;
}

std::vector<std::string> CLI::parse(std::string & s)
{
    std::vector<std::string> vec;

    std::string word;
    std::stringstream iss( s );
    while ( iss >> word )
        vec.push_back(word);

    return vec;
}

void CLI::write(std::string action_result)
{
    // action_result is ready print
    std::cout << action_result << std::endl;
}

