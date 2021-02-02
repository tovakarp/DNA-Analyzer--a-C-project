//
// Created by chevi on 8/20/20.
//
#include "new.h"


std::string New::execute(std::vector<std::string> params, Collection * collection)
{
    IAppend * append = (IAppend*)collection;
    DnaMetaData * dmd;
    strToPrint str;

    if(params.capacity() > 2)
    {
        dmd = append->appendDNA(DnaMetaData(params[1], params[2].erase(0, 1)));

    }

    else
    {
        dmd = append->appendDNA(DnaMetaData(params[1]));
    }

    std::cout << "I'm in New" << std::endl;

    return str.getString(dmd);
}
