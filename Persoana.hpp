#pragma once
#include <cstring>
#include <ball.hpp>

class Persoana:public Ball {
private:
    char* nume;       
    int scor;         
    int nivel;        
    int victorii;
    int infrangeri;     

public:
    Persoana(const char* numeInitial = "Guest", int scorInitial = 0, int nivelInitial = 1, int victoriiInitiale = 0, int infrangeriInitiale = 0);
    ~Persoana();
    Persoana(const Persoana& other);//concop
    Persoana& operator=(const Persoana& other);
    const char* getNume() const;
    int getScor() const;
    int getNivel() const;
    int getVictorii() const;
    int getInfrangeri() const;
    void setNume(const char* numeNou);
    void setScor(int scorNou);
    void setNivel(int nivelNou);
    void setVictorii(int victoriiNoi);
    void setInfrangeri(int infrangeriNoi);
    void adaugaInfrangere();
    void adaugaScor(int puncte);
    void adaugaVictorie();
    void salveazaInFisier(const char* numeFisier);
    bool incarcaDinFisier(const char* numeFisier,const char* numeNou);
};