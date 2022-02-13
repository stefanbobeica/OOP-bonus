//
// Created by stefa on 12/28/2021.
//

#include "zona1.h"
using namespace std;
const double zona1::ponderi[]={1,0.8,0.6,0.4,0.2};

zona1::zona1():populatie(0){

    for(int i=0;i<5;i++)
        obligatii[i]=0;
}

zona1::~zona1() {
//
}

void zona1::afisare(ofstream& out) {
out<<"Zona 1"<<endl;

for(int i=0; i<intrebari.size();i++){
    double acceptat=0;
    double respins=0;
    double votanti=0;
    out<<intrebari[i].question<<endl;
       for(int j=0;j<5;j++) {
           votanti=votanti+intrebari[i].Da[j];
           acceptat = acceptat + intrebari[i].Da[j] * ponderi[j];
       }
        for(int j=0;j<5;j++) {
            votanti=votanti+intrebari[i].Nu[j];
            respins = respins + intrebari[i].Nu[j] * ponderi[j];
        }
        if(acceptat>respins)
          out<<"Acceptat "<<fixed<<setprecision(1)<<acceptat<<"-"<<fixed<<setprecision(1)<<respins<<endl;
        if(respins>acceptat)
          out<<"Respins "<<fixed<<setprecision(1)<<acceptat<<"-"<<fixed<<setprecision(1)<<respins<<endl;
        if(respins==acceptat)
            out<<"Egalitate "<<fixed<<setprecision(1)<<acceptat<<"-"<<fixed<<setprecision(1)<<respins<<endl;
        double PrezentaVot;
    PrezentaVot=(votanti*100)/populatie;
    PrezentaVot=floor(100*PrezentaVot)/100;
    out<<"Prezenta vot: "<<fixed<<setprecision(2)<<PrezentaVot<<"%"<<endl;
 }
}

void zona1::citire(ifstream &input) {
    input>>populatie;
    for(int i=0 ; i<5 ; i++)
        input>>obligatii[4-i];

}

void zona1::getIntrebari(ifstream &input, int nrIntrebari) {
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

double zona1::getPopulatie() {
    return populatie;
}
