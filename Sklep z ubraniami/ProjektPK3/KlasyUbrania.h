#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class Ubranie
{
	protected:
	string kolor;
	string opis; //krótki opis odzie¿y
	string p³eæ; //czy to odzie¿ mêska czy damska
	int rozmiar; //dostepne rozmiary rozmiarow
	int id_produktu;
	int nrUbrania;//do wczytywania
public:
	Ubranie();
	virtual void zapisz()=0;
	virtual void wczytaj()=0;
	virtual void wypisz() const =0;
};
class Spodnie:public Ubranie
{
	string typ;
	int szerokosc_nogawki;
	public:
	Spodnie(string, string, string, string, int, int, int);
	Spodnie();
	bool szukaj(string);
	bool lszukaj(int, string);
	virtual void zapisz();
	virtual void wczytaj();
	virtual void wypisz() const;
	int getNr(int i);
};
class Bluzki :public Ubranie
{
	char* nadruk;
	public:
	Bluzki(string, string, string, const char*, int, int);
	Bluzki();
	~Bluzki();
	virtual void zapisz();
	virtual void wczytaj();
	bool szukaj(string);
	bool lszukaj(int, string);
	void laduj(string const& Sciezka);
	virtual void wypisz() const;
	int getNr(int i);
};
class Czapki :public Ubranie
{
	bool daszek;
	string model;
	public:
	Czapki(string, string, string, int, int, string, bool);
	Czapki(string const& Sciezka,int);
	Czapki();
	int getNr(int i);
	bool szukaj(string);
	bool lszukaj(int, string);
	bool cdaszek(bool);
	virtual void wczytaj();
	virtual void zapisz();
	virtual void wypisz() const;
};