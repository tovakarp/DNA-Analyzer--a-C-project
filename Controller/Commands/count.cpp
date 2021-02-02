//
// Created by chevi on 9/14/20.
//

#include "count.h"
#include "Model/seqdna.h"

std::vector<size_t> findallsubs(const std::string seq, const std::string subseq)
{
    DnaSequence originSeq(seq);
    DnaSequence subSeq(subseq);

    std::vector<size_t> allsebseq;
    size_t j = 0, len = subSeq.getLength();
    
    for (size_t i = 0; i < originSeq.getLength() - len  ; i++)
    {
        if (originSeq[i] == originSeq[0])
        {
            for (j = 0; j < subSeq.getLength(); j++)
            {
                if (originSeq[i + j] != subseq[j])
                    break;
            }

            if (j == subSeq.getLength())
            {
                allsebseq.push_back(i);
            }
        }
    }
    return allsebseq;

}

size_t count(const std::string seq, const std::string subseq)
{
    return findallsubs(seq, subseq).size();
}

std::string Count::execute(std::vector<std::string> params, Collection *collection)
{
    IGet * get = (IGet*)collection;
    size_t res;

    if(params[1].at(0) == '@')
    {
        if(params[2].at(0) == '@')
        {
            res = count(get->getDNAByName(params[1].erase(0, 1)), get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = count(get->getDNAByName(params[1].erase(0, 1)), get->getDNAById(stoull(params[2].erase(0, 1))));
        }
        else
        {
            res = count(get->getDNAByName(params[1].erase(0, 1)), params[2]);

        }
    }

    else if(params[1].at(0) == '#')
    {
        if(params[2].at(0) == '@')
        {
            res = count(get->getDNAById(stoull(params[1].erase(0, 1))), get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = count(get->getDNAById(stoull(params[1].erase(0, 1))), get->getDNAById(stoull(params[2].erase(0, 1))));
        }

        else
        {
            res = count(get->getDNAById(stoull(params[1].erase(0, 1))), params[2]);
        }
    }

    else
    {
        res = count(params[1], params[2]);
    }


    strToPrint str;

    return str.getString(res);
}
