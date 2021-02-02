#include "dup.h"

std::string Dup::execute(std::vector<std::string> params, Collection * collection)
{
    IAppend * append = (IAppend*)collection;
    IGet * get = (IGet*)collection;
    DnaMetaData * dmd;
    strToPrint str;

    if(params.size() > 2)
    {
        if(params[1].at(0) == '@') {
              dmd = append->appendDNA(DnaMetaData(get->getDNAByName(params[1].erase(0, 1)), params[2].erase(0, 1)));
        }
        else
        {
            dmd = append->appendDNA(DnaMetaData(get->getDNAById(stoull(params[1].erase(0, 1))), params[2].erase(0, 1)));
        }
    }

    else
    {
        if(params[1].at(0) == '@')
        {
            dmd = append->appendDNA(DnaMetaData(get->getDNAByName(params[1].erase(0, 1)), dmd->getName() + "_1"));
        }
        else
        {
            dmd = append->appendDNA(DnaMetaData(get->getDNAById(stoull(params[1].erase(0, 1))), dmd->getName() + "_1"));
        }

    }

    return str.getString(dmd);
}