//
// Created by chevi on 8/18/20.
//

#ifndef __MAPCOMMAND_H__
#define __MAPCOMMAND_H__

#include <map>
#include <vector>
#include "Controller/Commands/load.h"
#include "Controller/Commands/new.h"
#include "Controller/Commands/save.h"
#include "Controller/Commands/dup.h"
#include "Controller/Commands/slice.h"
#include "Controller/Commands/pair.h"
#include "Controller/Commands/find.h"
#include "Controller/Commands/count.h"
#include "Controller/Commands/findAll.h"

class MapCommand
{
public:
    MapCommand();
    IExecuteHandler * getCommandMap(std::string command);

private:
    std::map<std::string, IExecuteHandler *> m_commands;
};

inline MapCommand::MapCommand()
{
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("load",new Load()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("new",new New()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("save",new Save()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("dup",new Dup()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("slice",new Slice()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("pair",new Pair()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("find",new Find()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("count",new Count()));
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("findAll",new FindAll()));

}

inline IExecuteHandler * MapCommand::getCommandMap(std::string command)
{
    return m_commands[command];
}


#endif //__MAPCOMMAND_H__
