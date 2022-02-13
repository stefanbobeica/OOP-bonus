//
// Created by stefa on 12/28/2021.
//

#ifndef MAIN_CPP_ZONA2_H
#define MAIN_CPP_ZONA2_H
#include "base.h"
using namespace  std;
class zona2:public base {
private:
    double populatie;
    double functie[10];
    vector<intrebare> intrebari;
public:
    zona2();
    ~zona2();
    double getPopulatie();
    void afisare(ofstream&);
    void citire(ifstream&);
    void getIntrebari(ifstream&,int);
};



#endif //MAIN_CPP_ZONA2_H
