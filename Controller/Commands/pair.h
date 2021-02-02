//
// Created by chevi on 9/14/20.
//

#ifndef DNA_ANALIZER_PAIR_H
#define DNA_ANALIZER_PAIR_H

#include "Model/IexecuteHandler.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class Pair: public IExecuteHandler {
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
};

#endif //DNA_ANALIZER_PAIR_H
