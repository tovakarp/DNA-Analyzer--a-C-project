//
// Created by chevi on 8/18/20.
//

#ifndef __LOAD_H__
#define __LOAD_H__

#include <exception>
#include "Model/IexecuteHandler.h"
#include "Model/dnaMetaData.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/strToPrint.h"
//#include "Inew.h"
class Load: public IExecuteHandler /*, public INew*/{
public:
//    Load();
//    ~Load();
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);
    std::string readFromFile(std::string fileName);
//private:
//    INew * m_new;
};



#endif //DNAANALIZER_LOAD_H
