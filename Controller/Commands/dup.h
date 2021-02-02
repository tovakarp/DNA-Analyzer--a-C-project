//
// Created by chevi on 9/13/20.
//

#ifndef DNA_ANALYZER_DUP_H
#define DNA_ANALYZER_DUP_H

#include "Model/IexecuteHandler.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class Dup: public IExecuteHandler {
public:
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);

};


#endif //DNA_ANALYZER_DUP_H
