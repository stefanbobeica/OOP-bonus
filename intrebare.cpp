//
// Created by stefa on 12/28/2021.
//

#include "intrebare.h"

intrebare::intrebare():question("N/A"),varsta_necesara_intrebare(0) {

    for(int i=0; i<5;i++)
        Da[i]=0;

    for(int i=0; i<5;i++)
        Nu[i]=0;
}

intrebare::~intrebare() {
//
}

string intrebare::getQuestion() {
    return question;
}

double* intrebare::getDa() {
    return Da;
}

double *intrebare::getNu() {
    return Nu;
}
