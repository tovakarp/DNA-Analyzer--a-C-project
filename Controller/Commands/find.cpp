//
// Created by chevi on 9/14/20.
//
#include "find.h"
#include "Model/seqdna.h"

size_t findsubseq(const std::string seq, const std::string subseq) {//TODO take care of some overflow that somtimes occurs
    DnaSequence originSeq(seq);
    DnaSequence subSeq(subseq);

    size_t j = 0, len = subSeq.getLength();

    for (size_t i = 0; i < originSeq.getLength() - len; i++) {
        if (originSeq[i] == originSeq[0]) {
            for (j = 0; j < len; j++) {
                if (originSeq[i + j] != subSeq[j]) {
                    break;
                }
            }
        }
        if (j == len) {
            return i;
        }
    }
    return -1;
}

std::string Find::execute(std::vector<std::string> params, Collection *collection)
{
    IGet * get = (IGet*)collection;
    size_t res;

    if(params[1].at(0) == '@')
    {
        if(params[2].at(0) == '@')
        {
            res = findsubseq(get->getDNAByName(params[1].erase(0, 1)), get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = findsubseq(get->getDNAByName(params[1].erase(0, 1)), get->getDNAById(stoull(params[2].erase(0, 1))));
        }
        else
        {
            res = findsubseq(get->getDNAByName(params[1].erase(0, 1)), params[2]);

        }
    }

    else if(params[1].at(0) == '#')
    {
        if(params[2].at(0) == '@')
        {
            res = findsubseq(get->getDNAById(stoull(params[1].erase(0, 1))), get->getDNAByName(params[2].erase(0, 1)));
        }

        else if(params[2].at(0) == '#')
        {
            res = findsubseq(get->getDNAById(stoull(params[1].erase(0, 1))), get->getDNAById(stoull(params[2].erase(0, 1))));
        }

        else
        {
            res = findsubseq(get->getDNAById(stoull(params[1].erase(0, 1))), params[2]);
        }
    }

    else
    {
        res = findsubseq(params[1], params[2]);
    }


    strToPrint str;

    return str.getString(res);
}