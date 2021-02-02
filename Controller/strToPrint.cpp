//
// Created by chevi on 8/20/20.
//
#include "strToPrint.h"


std::string strToPrint::getString(DnaMetaData * &m)
{
    std::string s = "[" + std::to_string(m->getId()) + "] " + m->getName() + ": " + m->getSequence();
    return s;
}


std::string strToPrint::getString(size_t &m)
{
    return std::to_string(m);
}

std::string strToPrint::getString(std::vector<size_t> &m)
{
    std::string s = "[ ";
    for (int i = 0; i < m.size(); ++i)
    {
        s += std::to_string(m[i]) + " ";
    }
    return s + "]";
}
