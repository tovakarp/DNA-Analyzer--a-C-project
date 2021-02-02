
#include <iostream>
#include "Model/seqdna.h"
#include "Controller/controller.h"
#include "View/cli.h"


int main()
{
    std::fstream  myfile;
    myfile.open("dna.txt", std::ios::out | std::ios::in );
    string line;
    if (myfile.is_open()) {
        while ( getline (myfile,line) ){
            DnaSequence DNA(line);
        }
        myfile.close();
    }

    std::string a = "ATAGC";
    std::string b = "ACGA";
    std::string c = "";

    try{
        DnaSequence d1(a);
        //DnaSequence d(b);

    }
    catch(std::invalid_argument & e){
        std::cout << e.what() << std::endl;
    }
    catch(std::bad_alloc & e){
        std::cout << e.what() << std::endl;

    }

    Controller c1;
    c1.run();

    return 0;
}
