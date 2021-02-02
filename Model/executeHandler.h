#ifndef  __EXECUTEHANDLER_H__
#define  __EXECUTEHANDLER_H__
#include <iostream>
#include <map>
//#include "Load.h"
//#include "IexecuteHandler.h"


class ExecuteHandler{
public:
    std::string runExecuteHandler(IExecuteHandler * command, std::vector<std::string> params, Collection * collection);

};

inline std::string ExecuteHandler::runExecuteHandler(IExecuteHandler * command, std::vector<std::string> params, Collection * collection)
{

    return command->execute(params, collection);
}

#endif //__EXECUTEHANDLER_H__