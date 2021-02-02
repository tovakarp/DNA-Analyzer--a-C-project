//
// Created by chevi on 9/14/20.
//

#ifndef DNA_ANALIZER_FINDALL_H
#define DNA_ANALIZER_FINDALL_H

#include "Model/IexecuteHandler.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class FindAll: public IExecuteHandler {
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
    std::vector<size_t> findfindAllSubs(const DnaSequence & seq, const DnaSequence & subSeq);
};

#endif //DNA_ANALIZER_FINDALL_H
