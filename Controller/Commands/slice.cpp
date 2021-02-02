//
// Created by chevi on 9/14/20.
//
#include "slice.h"



std::string Slice::execute(std::vector<std::string> params, Collection *collection)
{
    IAppend * append = (IAppend*)collection;
    IGet * get = (IGet*)collection;
    DnaMetaData * dmd;
    std::string dnaSeq = "";

    if(params.size() == 4)
    {
        if(params[1].at(0) == '@')
        {
            dnaSeq = get->getDNAByName(params[1].erase(0, 1));
        }

        else
        {
            dnaSeq = get->getDNAById(stoull(params[1].erase(0, 1)));
        }
        dnaSeq = slice(dnaSeq, stoull(params[2]), stoull(params[3]));
        return dnaSeq;
    }

    else if(params.size() > 4)
    {
        if(params[5].at(0) == '@')
        {
            dmd = append->appendDNA(DnaMetaData(slice(get->getDNAByName(params[1].erase(0, 1)),stoull(params[2]), stoull(params[3])), params[5].erase(0, 1)));
        }

        else
        {
            dmd = append->appendDNA(DnaMetaData(get->getDNAById(stoull(params[1].erase(0, 1))), "default name"));
        }
    }

    strToPrint str;

    return str.getString(dmd);
}


/*slice*/
std::string Slice::slice(std::string dnaSeq, size_t start , size_t end)
{
    string mySlicedString = "";

    for (size_t i = start ; i < end ; i++)
    {

        mySlicedString += dnaSeq[i];
    }

    return mySlicedString;
}


