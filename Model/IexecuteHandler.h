//
// Created by chevi on 8/18/20.
//

#ifndef __IEXECUTEHANDLER_H__
#define __IEXECUTEHANDLER_H__

#include <iostream>
#include <vector>
#include "collection.h"

typedef class Params;

class IExecuteHandler{
public:
    virtual std::string execute(std::vector<std::string> params, Collection * collection) = 0;


};

#endif //__IEXECUTEHANDLER_H__