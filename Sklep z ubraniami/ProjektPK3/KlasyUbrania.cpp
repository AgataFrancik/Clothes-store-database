#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include "KlasyUbrania.h"
using namespace std;

Ubranie::Ubranie() :kolor("bialy"), opis("brak opisu"), p³eæ("brak"), id_produktu(0), nrUbrania(1),rozmiar (0)
{

}
Spodnie::Spodnie(string k, string o, string p,string t,int s, int r, int i)
{
		if (s<=0) cout << "Blad! Szerokosc nogawki nie moze wynosic zero badz byc ujemna!";
		else
		{
			kolor = k; opis = o; p³eæ = p; id_produktu = i; typ = t; szerokosc_nogawki = s; rozmiar = r;
		}
}
Spodnie::Spodnie(): typ("brak"), szerokosc_nogawki(0)
{
}
Czapki::Czapki() : daszek(false), model("brak")
{
}
Bluzki::Bluzki():nadruk(new char[12])
{
	strcpy(nadruk, "bez_nadruku");
}
Bluzki::~Bluzki()
{
	delete[] nadruk;
}
Bluzki::Bluzki(string k, string o, string p, const char* n, int r, int i)
{
	kolor = k; opis = o; p³eæ = p; rozmiar = r; id_produktu = i;
	nadruk = new char[strlen(n+1)];
	strcpy(nadruk, n);
}
Czapki::Czapki(string k, string o, string p, int r, int i, string m, bool d)
{
	kolor = k; opis = o; p³eæ = p; rozmiar = r; id_produktu = i; model = m; daszek = d;
}
void Spodnie::zapisz()
{
	fstream plik;
	plik.open("Spodnie.txt", ios::app);
	plik << this->kolor << endl;
	plik << this->opis << endl;
	plik << this->p³eæ << endl;
	plik << this->rozmiar << endl;
	plik << this->id_produktu << endl;
	plik << this->typ << endl;
	plik << this->szerokosc_nogawki;
	plik.close();
}
void Spodnie:: wczytaj()
{
	fstream plik;
	plik.open("Spodnie.txt", ios::in);
    if (plik.good())
    {
        string linia;
        int nrLinii = (nrUbrania - 1) * 7 + 1;
        int licznik = 1;
        while (getline(plik, linia))
        {
            if (licznik == nrLinii)
            {
                kolor = linia;
            }
            if (licznik == nrLinii + 1)
            {
                opis = linia;
            }
            if (licznik == nrLinii + 2)
            {
                p³eæ = linia;
            }
            if (licznik == nrLinii + 3)
            {
                stringstream geek(linia);
                geek >> rozmiar;
            }
            if (licznik == nrLinii + 4)
            {
                stringstream geek(linia);
                geek >> id_produktu;
            }
            if (licznik == nrLinii + 5)
            {
                typ = linia;
            }
            if (licznik == nrLinii + 6)
            {
                stringstream geek(linia);
                geek >> szerokosc_nogawki;
            }
            licznik++;
        }
    }
    else
    {
        cout << "Blad otwierania pliku!";
        exit(1);
    }
	plik.close();
}
void Spodnie::wypisz() const
{
	cout <<"Kolor: "<< kolor << " .Opis: " << opis << " .Dla plci: " << p³eæ << " .Rozmier: " << rozmiar << " .Id produktu: " << id_produktu << " .Typ: " << typ << " .Szerokosc nogawki: " << szerokosc_nogawki << endl ;
}
int Spodnie::getNr(int i)
{
	return nrUbrania = i;
}
int Czapki::getNr(int i)
{
	return nrUbrania = i;
}
int Bluzki::getNr(int i)
{
	return nrUbrania = i;
}
void Bluzki::zapisz()
{
	fstream plik;
	plik.open("Bluzki.txt", ios::app);
    if (plik.good())
    {
        plik << this->kolor << endl;
        plik << this->opis << endl;
        plik << this->p³eæ << endl;
        plik << this->rozmiar << endl;
        plik << this->id_produktu << endl;
        plik << this->nadruk;
    }
    else {
        cout << "Blad otwierania pliku!";
        exit(1);
    }
	plik.close();
}
void Bluzki::laduj(string const& Sciezka)
{
	fstream plik;
	plik.open(Sciezka.c_str(), std::ios::in | std::ios::out);
	if (plik.good())
	{
		string linia;
		string nadrukk;
		int nrLinii = (nrUbrania - 1) * 6 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				kolor = linia;
			}
			if (licznik == nrLinii + 1)
			{
				opis = linia;
			}
			if (licznik == nrLinii + 2)
			{
				p³eæ = linia;
			}
			if (licznik == nrLinii + 3)
			{
				stringstream geek(linia);
				geek >> rozmiar;
			}
			if (licznik == nrLinii + 4)
			{
				stringstream geek(linia);
				geek >> id_produktu;
			}
			if (licznik == nrLinii + 5)
			{
                delete[] nadruk;
				nadrukk = linia;
				nadruk = new char[nadrukk.length() + 1];
				strcpy(nadruk, nadrukk.c_str());
			}
			licznik++;
		}
		plik.close();
	}
	else cout << "Nie da sie otworzyc pliku!";
}
void Bluzki::wypisz() const
{
	cout << kolor << " " << opis << " " << p³eæ << " " << rozmiar << " " << id_produktu << " " << nadruk<<  endl;
}
void Czapki::zapisz()
{
	fstream plik;
	plik.open("Czapki.txt", ios::app);
    if (plik.good())
    {
        plik << this->kolor << endl;
        plik << this->opis << endl;
        plik << this->p³eæ << endl;
        plik << this->rozmiar << endl;
        plik << this->id_produktu << endl;
        plik << this->model << endl;
        plik << this->daszek<<endl;
    }
    else
    {
        cout << "Blad otwierania pliku!";
        exit(1);
    }
	plik.close();
}
void Czapki::wypisz() const
{
	cout << kolor << " " << opis << " " << p³eæ << " " << rozmiar << " " << id_produktu << " " << model << " " << daszek << endl;
}
Czapki::Czapki(string const& Sciezka, int i)
{
	fstream plik;
	plik.open(Sciezka.c_str(), std::ios::in | std::ios::out);
	if (plik.good())
	{
		string linia;
		int nrLinii = (i - 1) * 7 + 1;
		int licznik = 1;
		while (getline(plik, linia))
		{
			if (licznik == nrLinii)
			{
				kolor = linia;
			}
			if (licznik == nrLinii + 1)
			{
				opis = linia;
			}
			if (licznik == nrLinii + 2)
			{
				p³eæ = linia;
			}
			if (licznik == nrLinii + 3)
			{
				stringstream geek(linia);
				geek >> rozmiar;
			}
			if (licznik == nrLinii + 4)
			{
				stringstream geek(linia);
				geek >> id_produktu;
			}
			if (licznik == nrLinii + 5)
			{
				model = linia;
			}
			if (licznik == nrLinii + 6)
			{
				istringstream(linia) >> daszek;
			}
			licznik++;
		}
		plik.close();
	}
	else cout << "Nie da sie otworzyc pliku!";
}
bool Spodnie::szukaj(string szukana)
{
	if (szukana == this->kolor||szukana==this->opis|| szukana == this->p³eæ|| szukana == this->typ)
		return 1;
	else
		return 0;
}
bool Bluzki::szukaj(string szukana)
{
	if (szukana == this->kolor || szukana == this->opis || szukana == this->p³eæ || szukana == this->nadruk)
		return 1;
	else
		return 0;
}
bool Czapki::szukaj(string szukana)
{
	if (szukana == this->kolor || szukana == this->opis || szukana == this->p³eæ)
		return 1;
	else
		return 0;
}
bool Spodnie::lszukaj(int szukana, string parametr)
{
	if (parametr == "rozmiar")
	{
		if (szukana == this->rozmiar)
		{
			return 1;
		}
		else
			return 0;
	}
	if (parametr == "id_produktu")
	{
		if (szukana == this->id_produktu)
		{
			return 1;
		}
		else
			return 0;
	}
	if (parametr == "szerokosc_nogawki")
	{

		if (szukana == this->szerokosc_nogawki)
		{
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
bool Bluzki::lszukaj(int szukana, string parametr)
{
	if (parametr == "rozmiar")
	{
		if (szukana == this->rozmiar)
		{
			return 1;
		}
		else
			return 0;
	}
	if (parametr == "id_produktu")
	{
		if (szukana == this->id_produktu)
		{
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
bool Czapki::lszukaj(int szukana, string parametr)
{
	if (parametr == "rozmiar")
	{
		if (szukana == this->rozmiar)
		{
			return 1;
		}
		else
			return 0;
	}
	if (parametr == "id_produktu")
	{
		if (szukana == this->id_produktu)
		{
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
bool Czapki::cdaszek(bool czyDaszek)
{
	if (czyDaszek == true && this->daszek == true || czyDaszek == false && this->daszek == false)
	{
		return 1;
	}
	return 0;
}
void Bluzki::wczytaj()
{

}
void Czapki::wczytaj()
{

}