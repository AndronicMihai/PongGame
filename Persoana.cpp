#include "Persoana.hpp"
#include <cstring> 
#include <fstream>
#include <sstream>
using namespace std;


Persoana::Persoana(const char* numeInitial, int scorInitial, int nivelInitial, int victoriiInitiale,int infrangeriInitiale): scor(scorInitial), nivel(nivelInitial), victorii(victoriiInitiale),infrangeri(infrangeriInitiale) 
{
    nume = new char[strlen(numeInitial) + 1];
    strcpy(nume, numeInitial);
}

Persoana::~Persoana() {
    delete[] nume; 
}

Persoana::Persoana(const Persoana& other): scor(other.scor), nivel(other.nivel), victorii(other.victorii),infrangeri(other.infrangeri)
{
    nume = new char[strlen(other.nume) + 1];
    strcpy(nume, other.nume);
}
Persoana& Persoana::operator=(const Persoana& other) {
    if (this != &other) {
        delete[] nume; 
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        scor = other.scor;
        nivel = other.nivel;
        victorii = other.victorii;
        infrangeri = other.infrangeri;
    }
    return *this;
}

const char* Persoana::getNume() const {
    return nume;
}

int Persoana::getScor() const {
    return scor;
}

int Persoana::getNivel() const {
    return nivel;
}

int Persoana::getVictorii() const {
    return victorii;
}
int Persoana::getInfrangeri() const {
    return infrangeri;
}
void Persoana::setNume(const char* numeNou) {
    delete[] nume; 
    nume = new char[strlen(numeNou) + 1];
    strcpy(nume, numeNou);
}

void Persoana::setScor(int scorNou) {
    scor = scorNou;
}

void Persoana::setNivel(int nivelNou) {
    nivel = nivelNou;
}

void Persoana::setVictorii(int victoriiNoi) {
    victorii = victoriiNoi;
}

void Persoana::setInfrangeri(int infrangeriNoi) {
    infrangeri = infrangeriNoi;
}
void Persoana::adaugaScor(int puncte) {
    scor += puncte;
}

void Persoana::adaugaVictorie() {
    victorii++;
}
void Persoana::adaugaInfrangere() {
    infrangeri++;
}
void Persoana::salveazaInFisier(const char* numeFisier)
{
    ifstream fin(numeFisier);
    ostringstream out;
    bool gasit=false;
    string line;
    while(getline(fin,line))
    {
        istringstream iss(line);
        string numeFile;
        iss>>numeFile;
        if(numeFile==nume)
        {
            gasit=true;
            out<<nume<<" "<<victorii<<" "<<infrangeri<<endl;

        }
        else
        {
            out<<line<<endl;
        }
    }
    fin.close();
    if(gasit==false)
    {
        out<<nume<<" "<<victorii<<" "<<infrangeri<<endl;
    }   
    ofstream fout(numeFisier);
    fout<<out.str();
    fout.close();

}
bool Persoana::incarcaDinFisier(const char* numeFisier,const char* numeCautat)
{
    ifstream fin(numeFisier);
    string line;
    while(getline(fin,line))
    {
        istringstream iss(line);
        string numeFile;
        int v,i;
        iss>>numeFile>>v>>i;
        if(numeFile==numeCautat)
        {
            victorii=v;
            infrangeri=i;
            fin.close();
            return true;
        }

    }
    fin.close();
    return false;
}