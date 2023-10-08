#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Osoba
{
protected:
    string ime_prezime;
    string jmbg, adresa;
    int br_godina;
    char spol;
public:
    void postavi_ime_prezime(string i_p)
    {
        ime_prezime = i_p;
    }
    void postavi_jmbg(string jmb)
    {
        jmbg = jmb;
    }
    void postavi_adresa(string adr)
    {
        adresa = adr;
    }
    void postavi_godine(int god)
    {
        br_godina = god;
    }
    void postavi_spol(char sp)
    {
        spol = sp;
    }
    string daj_ime_prezime() const
    {
        return ime_prezime;
    }
    string daj_jmbg() const
    {
        return jmbg;
    }
    string daj_adresu() const
    {
        return adresa;
    }
    int daj_godine() const
    {
        return br_godina;
    }
    char daj_spol() const
    {
        return spol;
    }
    void ispisi()
    {
        cout << "Ime i prezime: " << daj_ime_prezime() << endl;
        cout << "JMBG: " << daj_jmbg() << endl;
        cout << "Adresa: " << daj_adresu() << endl;
        cout << "Godine: " << daj_godine() << endl;
        cout << "Spol: " << daj_spol() << endl;
    }
};

class Radnik : public Osoba
{
    string zanimanje;
    int plata;
    int staz;
public:
    void postavi_zanimanje(string z)
    {
        zanimanje = z;
    }
    void postavi_platu(int p)
    {
        plata = p;
    }
    void postavi_staz(int s)
    {
        staz = s;
    }
    string daj_zanimanje() const
    {
        return zanimanje;
    }
    int daj_platu() const
    {
        return plata;
    }
    int daj_staz() const
    {
        return staz;
    }
    int Penzija()
    {
        int penzija_staz, penzija_starost, minimum;
        penzija_staz = 40-staz;
        penzija_starost = 65-br_godina;
        minimum = penzija_staz;
        if(penzija_starost<minimum)
            penzija_starost = minimum;
        return minimum;
    }
    void ispis()
    {
        cout << endl;
        cout << "Ime i prezime radnika: " << daj_ime_prezime() << endl;
        cout << "Godina do penzije: " << Penzija() << endl;
    }
};

class Ucenik : public Osoba
{
    vector<int> ocjene;
public:
    void dodaj_ocjenu(int ocj)
    {
        ocjene.push_back(ocj);
    }
    float prosjek()
    {
        float prosjek;
        int s=0;
        for(int i=0; i<14; i++)
            s += ocjene[i];
        prosjek = s/14;
        return prosjek;
    }
    void ispis()
    {
        cout << endl;
        cout << "Ime i prezime: " << daj_ime_prezime() << endl;
        cout << "Prosjek: " << prosjek() << endl;
    }
};

int random_number()
    {
        srand(time(0));                    // srand - postavlja seed komandi rand, bez postavljenog seeda, random broj ce uvijek biti isti
        int random_num = rand()%5;         // time(0) - osigurava da seed uvijek bude u potpunosti random, biblioteka: ctime
        return random_num;                 // svaka cifra se tvori random od 0 do 5, cemu sluzi %10-4
    }

int main()
{
    Osoba x;
    Radnik y;
    Ucenik z;

    x.postavi_ime_prezime("Ismail Mujanovic");
    x.postavi_jmbg("____");
    x.postavi_adresa("Olovska 17");
    x.postavi_godine(17);
    x.postavi_spol('M');
    x.ispisi();

    y.postavi_ime_prezime("Mirza");
    y.postavi_godine(40);
    y.postavi_zanimanje("Programer");
    y.postavi_platu(2000);
    y.postavi_staz(20);
    y.ispis();

    z.postavi_ime_prezime("Ismail Mujanovic");
    for(int i=0; i<14; i++)
    {
        z.dodaj_ocjenu(random_number());
    }
    z.ispis();
    return 0;
}
