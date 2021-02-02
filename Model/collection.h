#ifndef  __COLLECTION_H__
#define  __COLLECTION_H__

#include <iostream>
#include <map>
#include "seqdna.h"
#include "dnaMetaData.h"
#include "Iappend.h"
#include "Iget.h"


class Collection : public IAppend, public IGet{

public:
    DnaMetaData * appendDNA(DnaMetaData newSeq);
    std::string getDNAByName(std::string name);
    std::string getDNAById(size_t id);
    DnaMetaData & getDNAMDByName(std::string name);
    DnaMetaData & getDNAMDByID(std::string name);
private:
    std::vector<DnaMetaData *> m_collection;
    std::map<size_t ,DnaMetaData*> m_DNAById;
    std::map<std::string, DnaMetaData*> m_DNAByName;

    bool checkIfNameExist(const std::string & name);
    bool checkIfIdExist(size_t id);
};


#endif //__COLLECTION_H__