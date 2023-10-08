/*
//Zadatak 1.

#include <iostream>
#include <string>

using namespace std;


struct TPerson
{
    string name;
    string surname;
    int age;
    string phoneNumber;
    string address;
    char gender;
    long long int ID;
};

void unos(TPerson &person)
{
    cout << "Name = ? ";
    getline(cin, person.name);

    cout << "Surname = ? ";
    getline(cin, person.surname);

    cout << "Age = ? ";
    cin >> person.age;
    cin.ignore();

    cout << "Phone Number = ? ";
    getline(cin, person.phoneNumber);

    cout << "Address = ? ";
    getline(cin, person.address);

    cout << "Gender = ? ";
    cin >> person.gender;

    cout << "ID = ? ";
    cin >> person.ID;
}


void ispis(TPerson &person)
{
    cout << endl;
    cout << "Name is " << person.name << " " << person.surname << endl;
    cout << "Phone Number is " << person.phoneNumber << endl;
    cout << "Address is " << person.address << endl;
    cout << "Age is " << person.age << endl;
    cout << "Gender is " << person.gender << endl;
    cout << "ID is " << person.ID << endl;
}

int main()
{
    TPerson person;
    unos(person);
    ispis(person);

    return 0;
}
*/

//**********************************************************************************************************************************************************

/*
//Zadatak 2. i 3.

#include <iostream>
#include <string>
using namespace std;

class Bankovni_racun
{
private:
  string broj_racuna;
  double stanje_na_racunu;
  double kamatna_stopa;

public:
    Bankovni_racun (string b, double s, double k)
  {
    broj_racuna = b;
    stanje_na_racunu = s;
    kamatna_stopa = k;
  }
  Bankovni_racun (string b, double s)
  {
    broj_racuna = b;
    stanje_na_racunu = s;
    kamatna_stopa = 0.02;
  }
  Bankovni_racun (string b)
  {
    broj_racuna = b;
    stanje_na_racunu = 0;
    kamatna_stopa = 0.02;
  }


  double Izracunaj_kamatu ();
  double Daj_Stanje() const;
  string Daj_Broj_Racuna() const;
  void Uplata (double);
  bool Isplata (double);
};


double Bankovni_racun::Izracunaj_kamatu()
{
  double kamata;
  kamata = kamatna_stopa * stanje_na_racunu;
  return kamata;
}

double Bankovni_racun::Daj_Stanje () const
{
  return stanje_na_racunu;
}

string Bankovni_racun::Daj_Broj_Racuna () const
{
  return broj_racuna;
}

void Bankovni_racun::Uplata (double x)
{
  stanje_na_racunu += x;
}

bool Bankovni_racun::Isplata (double x)
{
  if (stanje_na_racunu >= x)
    {
      stanje_na_racunu -= x;
      cout << "moguca" << endl;
    }
  else
    {
      cout << "nemoguca" << endl;
      cout << "Razlog: nedovoljan iznos na racunu" << endl;
    }
}

int main ()
{
  double u, i;
  Bankovni_racun korisnik("123-000-000", 7500, 0.2);

  cout << "Kamata: " << korisnik.Izracunaj_kamatu() << endl;
  cout << "Trenutno stanje racuna: " << korisnik.Daj_Stanje() << endl;
  cout << "Broj racuna: " << korisnik.Daj_Broj_Racuna() << endl;

  cout << "Unesite sumu novca koju zelite uplatiti na racun: " << endl;
  cin >> u;
  korisnik.Uplata(u);

  cout << "Trenutno stanje racuna: " << korisnik.Daj_Stanje() << endl;
  cout << "Unesite sumu novca koju zelite podici sa racuna: " << endl;
  cin >> i;

  cout << "Isplata: ";
  cout << korisnik.Isplata(i);
  cout << endl << "Trenutno stanje racuna: " << korisnik.Daj_Stanje() << endl << endl;

//----------------------------------------------------------------------------------------------------------------------------

  Bankovni_racun korisnik_2("124-000-000", 1000);

  cout << "Kamata: " << korisnik_2.Izracunaj_kamatu() << endl;
  cout << "trenutno stanje racuna: " << korisnik_2.Daj_Stanje() << endl;
  cout << "Broj racuna: " << korisnik_2.Daj_Broj_Racuna() << endl<<endl;

//----------------------------------------------------------------------------------------------------------------------------

  Bankovni_racun korisnik_3("125-000-000");

  cout << "Kamata: " << korisnik_3.Izracunaj_kamatu() << endl;
  cout << "trenutno stanje racuna: " << korisnik_3.Daj_Stanje() << endl;
  cout << "Broj racuna: " << korisnik_3.Daj_Broj_Racuna() << endl;

  return 0;
}
*/

//**********************************************************************************************************************************************************

/*
//Zadatak 4.

#include <iostream>
using namespace std;
class myClass
{
private:
  int a, b;
public:
  void set(int x)
  {
    a = b = x; //varijabli a se pridruzuje sadrzaj varijable b, varijabli b sadrzaj varijable x
    //KONACNI REZULTAT: sadrzaj sve tri varijable je isti i jednak je sadrzaju varijable x

  }
  void set(int x, int y)
  {
    a = x; //varijabli a se pridruzuje sadrzaj varijable x
    b = y; //varijabli b se pridruzuje sadrzaj varijable y
  }
  void print ()
  {
    cout << a << " " << b << endl;
  }

};

int
main ()
{
  myClass x;
  x.set(5); // funkcija kao parametar prima vrijednost x
  x.print(); //a,b,x imaju istu vrijednost, u ovom slucaju 5,  funkcija vrsi ispis a i b (ODNOSNO 5 5)
  x.set(3,9); // funkcija kao parametre prima vrijednost x, koji e pridruzuje varijabli a ,i vrijednost y,koja se pridruzuje varijabli b
  x.print(); //  funkcija vrsi ispis a i b (ODNOSNO 3 9)
  return 0;
}
*/

//**********************************************************************************************************************************************************

/*
//Zadatak 5.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Tacka
{
private:
  double x, y;

public:
  void setX(double);
  void setY(double);
  void Output() const;
  double distance();
  friend Tacka Najudaljenija_tacka(vector <Tacka> vektor)
  {
    double dmax = 0;
    int m = 0;
    for (int i = 0; i<vektor.size(); i++)
      {
        if (vektor[i].distance() > dmax)
          {
            dmax = vektor[i].distance();
            m = i;
          }
      }
    return vektor[m];
  }

};

void Tacka::setX(double a)
{
  x = a;
}

void Tacka::setY(double a)
{
  y = a;
}

void Tacka::Output() const
{
  cout << "(" << x << ", " << y << ")" << endl;
}

double Tacka::distance()
{
  return sqrt(x*x + y*y);
}

int main()
{
  vector <Tacka> v1;
  int velicina_vektora;
  Tacka MAX;

  cout << "Unesite broj tacaka" << endl;
  cin >> velicina_vektora;

  for(int i=0; i<velicina_vektora; i++)
    {
      Tacka t;
      double x1, y1;
      cout << "Unesite kordinatu x " << i + 1 << ". tacke:" << endl;
      cin >> x1;
      t.setX(x1);
      cout << "Unesite kordinatu y " << i + 1 << ". tacke:" << endl;
      cin >> y1;
      t.setY(y1);
      v1.push_back(t);
    }

  MAX = Najudaljenija_tacka(v1);
  MAX.Output();

  return 0;
}
*/
