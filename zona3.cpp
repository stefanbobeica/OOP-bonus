//
// Created by stefa on 12/28/2021.
//

#include "zona3.h"

zona3::zona3():populatie(0) {
    for(int i=0; i<4;i++)
        varste[i]=0;
}

zona3::~zona3() {
//nimic alocat dinamic
}

double zona3::getPopulatie() {
    return populatie;
}

void zona3::getIntrebari(ifstream &input, int nrIntrebari) {
    int populatie_eligibila;
    intrebare aux;
    for(int i=0; i<nrIntrebari;i++){
        string trash;
        input>>aux.varsta_necesara_intrebare;
        getline(input, trash);
        getline(input,aux.question);
        input>>trash;//trec peste Da
        input>>aux.Da[0];
        input>>trash;//trec peste nu
        input>>aux.Nu[0];

        intrebari.push_back(aux);
        input.clear();
    }
}

void zona3::citire(ifstream &input) {
    input>>populatie;
    for(int i=0 ; i<4 ; i++)
        input>>varste[i];
}

void zona3::afisare(ofstream &out) {
    out<<"Zona 3"<<endl;
    for(int i=0; i<intrebari.size();i++){
        out<<intrebari[i].question<<endl;
        if(intrebari[i].Da[0]>intrebari[i].Nu[0])
        {
            out<<"Acceptat "<<fixed<<setprecision(0)<<intrebari[i].Da[0]<<"-"<<fixed<<setprecision(0)<<intrebari[i].Nu[0]<<endl;
        }
        if(intrebari[i].Da[0]<intrebari[i].Nu[0]){
            out<<"Respins "<<fixed<<setprecision(0)<<intrebari[i].Da[0]<<"-"<<fixed<<setprecision(0)<<intrebari[i].Nu[0]<<endl;
        }
        if(intrebari[i].Da[0]==intrebari[i].Nu[0]){
            out<<"Egalitate "<<fixed<<setprecision(0)<<intrebari[i].Da[0]<<"-"<<fixed<<setprecision(0)<<intrebari[i].Nu[0]<<endl;
        }
        double votanti=0;
      if(intrebari[i].varsta_necesara_intrebare==0){
          for(int i=0; i<4;i++)
              votanti=votanti+varste[4-i];
      }
      if(intrebari[i].varsta_necesara_intrebare==14){
            for(int i=1; i<4;i++)
                votanti=votanti+varste[i];
        }
      if(intrebari[i].varsta_necesara_intrebare==20){
            for(int i=2; i<4;i++)
                votanti=votanti+varste[i];
        }

      double prezenta_vot;
      prezenta_vot=(intrebari[i].Da[0]+intrebari[i].Nu[0])*100/votanti;
        prezenta_vot=floor(100*prezenta_vot)/100;
        out<<"Prezenta vot: "<<fixed<<setprecision(2)<<prezenta_vot<<"%"<<endl;
    }

}
