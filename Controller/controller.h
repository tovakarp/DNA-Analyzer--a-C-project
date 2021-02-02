#ifndef  __CONTROLLER_H__
#define  __CONTROLLER_H__

#include <iostream>
#include <stdlib.h>
#include "View/cli.h"
#include "Model/mapCommand.h"
#include "Model/executeHandler.h"
class Controller{
public:
    Controller();
    ~Controller();
    void run();

private:
    Collection * m_collection;
    CLI * m_cli;
    ExecuteHandler * m_executeHandler;
    MapCommand mpc;

};

inline Controller::Controller()
{
    m_collection = new Collection;
}

inline Controller::~Controller()
{
    delete m_collection;
}

inline void Controller::run()
{
    while(true)
    {
        std::string cmd = m_cli->read();
        if(cmd == "quit")
        {
            exit(0);
        }
        std::vector<std::string> commandVec = m_cli->parse(cmd);
        IExecuteHandler * command = mpc.getCommandMap(commandVec[0]);
        std::string _ = m_executeHandler->runExecuteHandler(command, commandVec, m_collection);
        m_cli->write(_);
    }

}

#endif //__CONTROLLER_H__