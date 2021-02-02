//
// Created by chevi on 9/16/20.
//

#ifndef DNA_ANALYZER_REVERSE_H
#define DNA_ANALYZER_REVERSE_H

#include "Model/Idecorator.h"
#include "Model/IexecuteHandler.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/writer.h"
#include "Controller/strToPrint.h"

class Reverse : public IExecuteHandler , public IDecorator{

    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
};
#endif //DNA_ANALYZER_REVERSE_H
