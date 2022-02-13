//
// Created by stefa on 12/28/2021.
//

#ifndef MAIN_CPP_BASE_H
#define MAIN_CPP_BASE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "intrebare.h"
#include <iomanip>
#include <cmath>
#include <math.h>
using namespace  std;

class base {
public:
virtual void citire(ifstream&)=0;
virtual void afisare(ofstream&)=0;
virtual void getIntrebari(ifstream&,int)=0;
~base();
};


#endif //MAIN_CPP_BASE_H
