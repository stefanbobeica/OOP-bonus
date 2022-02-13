//
// Created by stefa on 12/28/2021.
//

#include "zona2.h"
using namespace std;

double zona2::getPopulatie() {
    return populatie;
}

zona2::zona2():populatie(0) {
for(int i=0; i<10; i++)
    functie[i]=0;
}
zona2::~zona2(){
    //
}

void zona2::citire(ifstream &input) {
    input>>populatie;
    for(int i=0 ; i<10 ; i++)
        input>>functie[9-i];
}

void zona2::getIntrebari(ifstream &input, int nrIntrebari) {
    intrebare aux;
    for(int i=0; i<nrIntrebari;i++){
        string trash;
        getline(input, trash);
        getline(input,aux.question);
        input>>trash;
        for(int j=0;j<5;j++){
            input>>aux.Da[j];
        }
        input>>trash;
        for(int j=0;j<5;j++){
            input>>aux.Nu[j];
        }
        intrebari.push_back(aux);
        input.clear();
    }
}

void zona2::afisare(ofstream &out) {
    out<<"Zona 2"<<endl;

    for(int i=0; i<intrebari.size();i++){
        double acceptat=0;
        double respins=0;
        double votanti=0;
        out<<intrebari[i].question<<endl;
        for(int j=0;j<5;j++) {
            votanti=votanti+intrebari[i].Da[j];
            acceptat = acceptat + intrebari[i].Da[j] * (10-j);
        }
        for(int j=0;j<5;j++) {
            votanti=votanti+intrebari[i].Nu[j];
            respins = respins + intrebari[i].Nu[j] * (10-j);
        }
        if(acceptat>respins)
            out<<"Acceptat "<<fixed<<setprecision(0)<<acceptat<<"-"<<fixed<<setprecision(0)<<respins<<endl;
        if(respins>acceptat)
            out<<"Respins "<<fixed<<setprecision(0)<<acceptat<<"-"<<fixed<<setprecision(0)<<respins<<endl;
        if(respins==acceptat)
            out<<"Egalitate "<<fixed<<setprecision(0)<<acceptat<<"-"<<fixed<<setprecision(0)<<respins<<endl;
        double PrezentaVot;
        double populatie_eligibila=0;
        for(int j=0; j<6;j++)
            populatie_eligibila=populatie_eligibila+functie[10-j];
        PrezentaVot=(votanti*100)/populatie_eligibila;

        PrezentaVot=floor(100*PrezentaVot)/100;
        out<<"Prezenta vot: "<<fixed<<setprecision(2)<<PrezentaVot<<"%"<<endl;
    }

}
