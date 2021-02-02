//
// Created by chevi on 8/20/20.
//

#ifndef DNA_ANALIZER_WRITER_H
#define DNA_ANALIZER_WRITER_H

#include <iostream>
#include <fstream>


class Writer{
public:
    void writeToFile(std::string action_result, std::string file_name);
};

inline void Writer::writeToFile(std::string action_result, std::string file_name)
{
    // see why file is created in cmake-build-debug
    std::ofstream myfile;
    std::string path = "/home/chevi/Desktop/DNA_Analizer/src/" + file_name + ".rawdna";
    myfile.open (path);
    myfile << action_result;
    myfile.close();
}

#endif //DNA_ANALIZER_WRITER_H
