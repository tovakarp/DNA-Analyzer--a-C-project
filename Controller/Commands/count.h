//
// Created by chevi on 9/14/20.
//

#ifndef DNA_ANALIZER_COUNT_H
#define DNA_ANALIZER_COUNT_H

#include "Model/IexecuteHandler.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class Count: public IExecuteHandler {
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
};
#endif //DNA_ANALIZER_COUNT_H
