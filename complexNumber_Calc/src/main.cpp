#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "Statystyka.hh"
using namespace std;



int main(int argc, char **argv)
{
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;




  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz, poprawna;
  stat x{0,0};
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
  {
    cout << "Podaj wynik operacji: " << WyrZ_PytanieTestowe;
    cout << "Twoja odpowiedz: ";
    cin >> odpowiedz;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(10000,'\n');
    }

    cout<<endl;
    poprawna=Oblicz(WyrZ_PytanieTestowe);
    if(odpowiedz.re == poprawna.re && odpowiedz.im==poprawna.im)
      {
      cout<<" :) Odpowiedz: "<<odpowiedz<< " jest poprawna"<<endl;
      x.dobra ++;
      }
      else
      { 
      cout <<" :( Odpowiedz: " <<odpowiedz<<" jest bledna"<<endl;
      cout <<"Odpowiedzia poprawna jest: "<<poprawna <<endl;
      x.zla ++;
      }
  }

  cout << endl;
  cout << "Koniec testu" << endl;
  Wyswietl(x);


