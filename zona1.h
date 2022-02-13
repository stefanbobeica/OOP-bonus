//
// Created by stefa on 12/28/2021.
//

#ifndef MAIN_CPP_ZONA1_H
#define MAIN_CPP_ZONA1_H
#include "base.h"

using namespace std;
class zona1: public base{
private:
    double populatie;
    double obligatii[5];
    static const double ponderi[5];
    vector<intrebare> intrebari;
public:
    zona1();
    ~zona1();
    double getPopulatie();
    void afisare(ofstream&);
    void citire(ifstream&);
    void getIntrebari(ifstream&,int);
};


#endif //MAIN_CPP_ZONA1_H
