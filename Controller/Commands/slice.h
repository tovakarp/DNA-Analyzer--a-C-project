//
// Created by chevi on 9/14/20.
//

#ifndef DNA_ANALIZER_SLICE_H
#define DNA_ANALIZER_SLICE_H

#include "Model/IexecuteHandler.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class Slice: public IExecuteHandler {
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
    std::string slice(std::string dnaSeq, size_t start , size_t end);
};

#endif //DNA_ANALIZER_SLICE_H
