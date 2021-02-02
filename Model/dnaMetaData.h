//
// Created by chevi on 8/19/20.
//

#ifndef DNAANALIZER_DNAMETADATA_H
#define DNAANALIZER_DNAMETADATA_H

#include <iostream>
//#include <bits/shared_ptr.h>
#include "seqdna.h"
#include "IdnaSeq.h"
//#include <memory>
//#include <tr1/unordered_map>
//#include <tr1/memory>


class DnaMetaData{

public:
    DnaMetaData(std::string dnaSeq, std::string name="");

    std::string getName();

    size_t getId();

    std::string getSequence();

private:

    /*std::shared_ptr<*/IDnaSequence * m_dnaSeq;

    std::string m_name;

    size_t m_id;

    static size_t s_id;

    static size_t s_name;
};



#endif //DNAANALIZER_DNAMETADATA_H
