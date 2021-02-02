//
// Created by chevi on 8/19/20.
//
#include "dnaMetaData.h"
size_t DnaMetaData::s_id = 0;
size_t DnaMetaData::s_name = 0;

DnaMetaData::DnaMetaData(std::string dnaSeq, std::string name): m_dnaSeq(new DnaSequence(dnaSeq)) ,m_name(name), m_id(s_id)
{
    if(m_name == "")
    {
        m_name = "sequence" + std::to_string(s_name);
        ++s_name ;
    }
    ++s_id;
}

std::string DnaMetaData::getName()
{
    return m_name;
}

size_t DnaMetaData::getId()
{
    return m_id;
}

std::string DnaMetaData::getSequence()
{
    //TODO try not to create a temporary object
    DnaSequence & a = (DnaSequence&)m_dnaSeq;
    return a.getSeq();

}
