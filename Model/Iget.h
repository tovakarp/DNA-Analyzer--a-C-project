//
// Created by chevi on 8/20/20.
//

#ifndef DNA_ANALIZER_IGET_H
#define DNA_ANALIZER_IGET_H
#include <iostream>


class IGet{
public:
    virtual std::string getDNAByName(std::string name) = 0;
    virtual std::string getDNAById(size_t id) = 0;
};

#endif //DNA_ANALIZER_IGET_H
