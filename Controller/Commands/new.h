//
// Created by chevi on 8/19/20.
//

#ifndef DNAANALIZER_NEW_H
#define DNAANALIZER_NEW_H

#include <exception>
#include "Model/IexecuteHandler.h"
#include "Model/dnaMetaData.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/strToPrint.h"
#include "Model/Inew.h"

class New: public IExecuteHandler /*, public INew*/{
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
};

#endif //DNAANALIZER_NEW_H
