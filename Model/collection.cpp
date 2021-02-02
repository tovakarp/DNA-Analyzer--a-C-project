//
// Created by chevi on 8/20/20.
//
#include "collection.h"

bool Collection::checkIfNameExist(const std::string & name) {
    return m_DNAByName.find(name) != m_DNAByName.end();
}

bool Collection::checkIfIdExist(size_t id) {
    return m_DNAById.find(id) != m_DNAById.end();
}

DnaMetaData * Collection::appendDNA(DnaMetaData newSeq) {
    DnaMetaData *dmd = new DnaMetaData(newSeq);
    m_collection.push_back(dmd);

    return dmd;
}

std::string Collection::getDNAByName(std::string name)
{
    for(int i = 0; i < m_collection.size(); ++i)
    {
        if(m_collection[i]->getName() == name)
        {
            return m_collection[i]->getSequence();
        }
    }
    return "";
}

std::string binarySearch(std::vector<DnaMetaData *> vec, size_t l, size_t r, size_t x)
{
    size_t mid;
    if (r >= l) {
        mid = l + (r - l) / 2;

        if (vec[mid]->getId() == x)
            return vec[mid]->getSequence();

        if (vec[mid]->getId() > x)
            return binarySearch(vec, l, mid - 1, x);

        return binarySearch(vec, mid + 1, r, x);
    }

    return "";
}

inline std::string Collection::getDNAById(size_t id)
{
    return binarySearch(m_collection, 0, m_collection.capacity(), id);
}


