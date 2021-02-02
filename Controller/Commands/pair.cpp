//
// Created by chevi on 9/14/20.
//

#include "pair.h"
#include "Model/seqdna.h"

std::string getPairedSeq(const std::string & str)
{
    DnaSequence temp(str);
    DnaSequence::Nucleotide * seq = temp.pairing();
    size_t len = temp.getLength();
    std::string result = "";

    for( size_t i = 0; i < len; i++)
    {
        result += seq[i];
    }

    return result;
}

/*virtual*/ std::string Pair::execute(std::vector<std::string> params, Collection *collection)
{
    IGet * get = (IGet*)collection;
    IAppend * append = (IAppend*)collection;
    DnaMetaData * dmd;
    std::string seq;

    if(params[1].at(0) == '@')
    {
        seq = getPairedSeq(get->getDNAByName(params[1].erase(0, 1)));
    }

    else
    {
        seq = getPairedSeq(get->getDNAById(stoull(params[1].erase(0, 1))));
    }

    if(params.size() > 2)
    {
        if(params[3].at(1) == '@')
        {
            dmd = append->appendDNA(DnaMetaData(seq));
        }

        else
        {
            dmd = append->appendDNA(DnaMetaData(seq, params[3].erase(0, 1)));
        }
        //TODO throw exception ...

        strToPrint str;

        return str.getString(dmd);

    }
    return seq;

}


