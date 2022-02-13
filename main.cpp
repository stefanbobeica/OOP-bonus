#include "zona1.h"
#include "zona2.h"
#include "zona3.h"
using namespace std;

int main(){

base ** zone;
zone=new base*[3];
zone[0]=new zona1;
zone[1]=new zona2;
zone[2]=new zona3;
int nrZona;
ifstream input("input.txt");
ofstream output("output.txt");
for(int i=0;i<3;i++){
    input>>nrZona;
    zone[nrZona-1]->citire(input);
}
int nrIntrebari;

for(int i=0; i<3;i++){
    input>>nrIntrebari;
    input>>nrZona;
    zone[nrZona-1]->getIntrebari(input,nrIntrebari);
}
for(int i=0; i<3;i++){
    zone[i]->afisare(output);
}
for(int i=0;i<3;i++)
    delete zone[i];
    delete[] zone;

    input.close();
    output.close();
    return EXIT_SUCCESS;
}
