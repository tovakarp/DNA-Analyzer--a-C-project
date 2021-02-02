//
// Created by chevi on 9/16/20.
//

#ifndef DNA_ANALYZER_IDECORATOR_H
#define DNA_ANALYZER_IDECORATOR_H

#include "IdnaSeq.h"

class IDecorator : IDnaSequence{
public:
    IDecorator(IDnaSequence * IDnaSeq);
private:
    IDnaSequence * m_IDnaSequence;
};

inline IDecorator::IDecorator(IDnaSequence * IDnaSeq) : m_IDnaSequence(IDnaSeq){}

#endif //DNA_ANALYZER_IDECORATOR_H
