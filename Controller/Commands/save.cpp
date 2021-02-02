//
// Created by chevi on 8/20/20.
//

#include "save.h"

inline std::string Save::execute(std::vector<std::string> params, Collection *collection)
{
    IGet * get = (IGet*)collection;
    DnaMetaData * dmd;
    std::string seq;

    if(params[1].at(0) == '@')
    {
        seq = get->getDNAByName(params[1].erase(0, 1));
    }

    else
    {
        seq = get->getDNAById(stoull(params[1].erase(0, 1)));
    }

    if(seq == "")
    {
        throw std::invalid_argument("Invalid Command");
    }
    if(params.size() < 3)
    {
        params[2] = dmd->getName();
    }
    m_write->writeToFile(seq, params[2]);

    return "sequence was saved successfully";
}