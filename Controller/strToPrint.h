//
// Created by chevi on 8/20/20.
//

#ifndef DNA_ANALIZER_STRTOPRINT_H
#define DNA_ANALIZER_STRTOPRINT_H
#ifndef DNA_ANALYZER_STR_TO_PRINT_H
#define DNA_ANALYZER_STR_TO_PRINT_H
#include <string>
#include <vector>
#include "Model/dnaMetaData.h"

class strToPrint{
public:
    std::string getString(DnaMetaData * &m);
    std::string getString(size_t &m);
    std::string getString(std::vector<size_t> &m);
    std::string getString(std::string &str);
};


#endif //DNA_ANALYZER_STR_TO_PRINT_H
#endif //DNA_ANALIZER_STRTOPRINT_H
