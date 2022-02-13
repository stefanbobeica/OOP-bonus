//
// Created by stefa on 12/28/2021.
//

#ifndef MAIN_CPP_INTREBARE_H
#define MAIN_CPP_INTREBARE_H
#include "base.h"
#include <string>
using namespace std;
class intrebare {
public:
    string question;
    int varsta_necesara_intrebare;//pentru cerinta 3
    double Da[5];
    double Nu[5];

    intrebare();
    ~intrebare();
    string getQuestion();
    double* getDa();
    double* getNu();
};


#endif //MAIN_CPP_INTREBARE_H
