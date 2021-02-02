//
// Created by chevi on 8/20/20.
//

#ifndef DNA_ANALIZER_SAVE_H
#define DNA_ANALIZER_SAVE_H

#include <sstream>      // std::stringstream
#include "Model/IexecuteHandler.h"
#include "Model/dnaMetaData.h"
#include "Model/Iappend.h"
#include "Model/collection.h"
#include "Controller/writer.h"

class Save: public IExecuteHandler {
public:
    Save();
    ~Save();
    /*virtual*/ std::string execute(std::vector<std::string> params, Collection *collection);

private:
    Writer * m_write;
};

inline Save::Save(): m_write(new Writer){}

inline Save::~Save()
{
    delete m_write;
}


#endif //DNA_ANALIZER_SAVE_H
