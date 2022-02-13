//
// Created by stefa on 12/28/2021.
//

#ifndef MAIN_CPP_ZONA3_H
#define MAIN_CPP_ZONA3_H
#include "base.h"

class zona3: public base {
private:
    double populatie;
    double varste[4];
    vector<intrebare> intrebari;
public:
    zona3();
    ~zona3();
    double getPopulatie();
    void afisare(ofstream&);
    void citire(ifstream&);
    void getIntrebari(ifstream&,int);
};



#endif //MAIN_CPP_ZONA3_H
