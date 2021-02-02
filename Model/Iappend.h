//
// Created by chevi on 8/19/20.
//

#ifndef DNAANALIZER_ICOLLECTION_H
#define DNAANALIZER_ICOLLECTION_H

class IAppend{
public:
    virtual DnaMetaData * appendDNA(DnaMetaData newSeq) = 0;
};


#endif //DNAANALIZER_ICOLLECTION_H
