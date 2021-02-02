//
// Created by chevi on 8/20/20.
//
#include <fstream>
#include "load.h"

//Load::Load(): {}

std::string Load::execute(std::vector<std::string> params, Collection * collection)
{
    IAppend * append = (IAppend*)collection;
    DnaMetaData * dmd;
    std::string dnaSeq = "";

    dnaSeq = readFromFile(params[1]);
    params[1] = dnaSeq;

    if(params.size() > 2)
    {
        dmd = append->appendDNA(DnaMetaData(dnaSeq, params[2].erase(0, 1)));
    }

    else
    {
        dmd = append->appendDNA(DnaMetaData(dnaSeq));
    }

    strToPrint str;


    return str.getString(dmd);

}

std::string Load::readFromFile(std::string fileName)
{
    std::string seq="";
    std::string line;
    std::string path = "/home/chevi/Desktop/DNA_Analizer/src/" + fileName;
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            seq.append(line);
        }
        myfile.close();
    }
    else
    {
        throw std::invalid_argument(fileName+": no such file or directory\n");
    }
    return seq;
}