//
// Created by chevi on 9/14/20.
//

#include "findAll.h"
#include "Model/seqdna.h"


std::vector<size_t> findAllSubs(const DnaSequence & originSeq, const DnaSequence & sub)
{
    DnaSequence originalSeq(originSeq);
    DnaSequence subSeq(sub);
    std::vector<size_t> allSubSeq = originSeq.findallsubSeq(sub);
    return allSubSeq;
}

std::string FindAll::execute(std::vector<std::string> params, Collection *collection)
{
    IGet * get = (IGet*)collection;
    std::vector<size_t> res;

    if(params[1].at(0) == '@')
    {
        if(params[2].at(0) == '@')
        {
            res = findAllSubs(get->getDNAByName(params[1].erase(0, 1)), get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = findAllSubs(get->getDNAByName(params[1].erase(0, 1)),
                                get->getDNAById(stoull(params[2].erase(0, 1))));
        }
        else
        {
            res = findAllSubs(get->getDNAByName(params[1].erase(0, 1)), params[2]);

        }
    }

    else if(params[1].at(0) == '#')
    {
        if(params[2].at(0) == '@')
        {
            res = findAllSubs(get->getDNAById(stoull(params[1].erase(0, 1))),
                                get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = findAllSubs(get->getDNAById(stoull(params[1].erase(0, 1))),
                                get->getDNAById(stoull(params[2].erase(0, 1))));
        }

        else
        {
            res = findAllSubs(get->getDNAById(stoull(params[1].erase(0, 1))), params[2]);
        }
    }

    else
    {
        res = findAllSubs(params[1], params[2]);
    }


    strToPrint str;

    return str.getString(res);
}

