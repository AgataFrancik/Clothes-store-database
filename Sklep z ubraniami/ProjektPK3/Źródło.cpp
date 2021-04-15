#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <vld.h>
#include "KlasyUbrania.h"
using namespace std;

int main()
{
	int wybor;
	Ubranie* wskaznik;
	cout << "Witamy w bazie danych sklepu odzie¿owego New Age Janina!"<<endl;
	cout << "Co chcesz zrobiæ?" << endl;
	cout << "=============================================" << endl;
	cout << "1. Pokaz wszystkie towary" << endl;
	cout << "2. Wyszukaj towar po typie" << endl;
	cout << "3. Wprowadz nowy towar do sysytemu" << endl;
	cin >> wybor;
	switch (wybor)
	{
		case 1:
		{
			int ilosc,ilosc1,ilosc2;
			cout << "SPODNIE:" << endl;
			fstream plik;
			plik.open("SpodnieIlosc.txt",ios::in);
			if (plik.good())
			{
				plik >> ilosc;
				Spodnie* ktab = new Spodnie[ilosc];
				for (int i = 0; i < ilosc; i++)
				{
					ktab[i].wczytaj();
					cout << "Spodnie nr " << i + 1 << endl;
					ktab[i].wypisz();
					ktab[i+1].getNr(i+2);
				}
                delete[] ktab;
				plik.close();
			}
			else
			{
				cout << "Blad otwierania pliku!";
				plik.close();
				exit(1);
			}
			cout << "BLUZKI:" << endl;
			fstream plik2;
			plik2.open("BluzkiIlosc.txt", ios::in);
			if (plik2.good())
			{
				string Sciezka;
				cout << "Podaj sciezke do pliku" << endl;
				cin >> Sciezka;
				plik2 >> ilosc2;
                Bluzki* ktab = new Bluzki[ilosc];
				for (int i = 0; i < ilosc2; i++)
				{
					ktab[i].laduj(Sciezka);
					cout << "Bluzka nr " << i + 1 << endl;
					ktab[i].wypisz();
					ktab[i+1].getNr(i+2);
				}
                delete[] ktab;
				plik2.close();
			}
			else
			{
				cout << "Blad otwierania pliku!";
				plik2.close();
				exit(1);
			}
			cout << "CZAPKI:" << endl;
			fstream plik1;
			plik1.open("CzapkiIlosc.txt", ios::in);
			if (plik1.good())
			{
				string Sciezka;
				cout << "Podaj sciezke do pliku" << endl;
				cin >> Sciezka;
				plik1 >> ilosc1;
				Czapki* ktab = new Czapki[ilosc1];
				for (int i = 0; i < ilosc1; i++)
				{
					ktab[i] = Czapki(Sciezka,i+1);
					cout << "Czapka nr " << i + 1 << endl;
					ktab[i].wypisz();
					ktab[i+1].getNr(i+2);
				}
                delete[] ktab;
				plik1.close();
			}
			else
			{
				cout << "Blad otwierania pliku!";
				plik1.close();
				exit(1);
			}
			break;
		}
		case 2:
		{
			int wybor2;
			int ilosc;
			cout << "Jaki typ ubrania chcesz wyszukac?" << endl;
			cout << "=============================================" << endl;
			cout << "1. Spodnie" << endl;
			cout << "2. Bluzki" << endl;
			cout << "3. Czapki" << endl;
			cin >> wybor2;
			switch (wybor2)
			{
				case 1:
				{
					fstream plik;
					plik.open("SpodnieIlosc.txt", ios::in);
					if (plik.good())
					{
						Spodnie s("c", "c", "c", "c", 1, 1, 1);
						Ubranie* wskaznik = &s;
						plik >> ilosc;
						Spodnie* ktab = new Spodnie[ilosc];
						string parametr;
						cout << " Napisz o jaki parametr Ci chodzi ";
						cin >> parametr;
						int parametr1;
						if (parametr == "kolor")
						{
							parametr1 = 1;
						}
						if (parametr == "opis")
						{
							parametr1 = 2;
						}
						if (parametr == "p³eæ")
						{
							parametr1 = 3;
						}
						if (parametr == "rozmiar")
						{
							parametr1 = 4;
						}
						if (parametr == "id_produktu")
						{
							parametr1 = 5;
						}
						if (parametr == "typ")
						{
							parametr1 = 6;
						}
						if (parametr == "szerokosc_nogawki")
						{
							parametr1 = 7;
						}
						string szukana;
						int lszuk;
						switch (parametr1)
						{
							case 1:
							{
								string szukana;
							cout << "Jakiego koloru szukasz? ";
							cin >> szukana;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].szukaj(szukana))
								{
									cout << "Spodnie nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
							}
						case 2:
						{
							string szukana;
							cout << "Jakiego opisu produktu szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 3:
						{
							string szukana;
							cout << "Dla jakiej p³ci to ma byæ produkt? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 4:
						{
							cout << "Jakiego rozmiaru szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].lszukaj(lszuk,parametr))
								{
									cout << "Spodnie nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 5:
						{
							cout << "Produktu o jakim id szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].lszukaj(lszuk, parametr))
								{
									cout << "Spodnie nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 6:
						{
							string szukana;
							cout << "Jakiego typu produktu szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].wczytaj();
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						default:
						{
							cout << "Takiego parametru nie ma!";
							exit(1);
						}
                        delete[] ktab;
						plik.close();
						}
						break;
					}
				} // jak wybrales spodnie to tu sie konczy switch
				case 2:
				{
					fstream plik;
					plik.open("BluzkiIlosc.txt", ios::in);
					if (plik.good())
					{
						Bluzki b;
						Ubranie* wskaznik = &b;
						plik >> ilosc;
						Bluzki* ktab = new Bluzki[ilosc];
						string parametr;
						string Sciezka;
						cout << "Podaj sciezke do pliku" << endl;
						cin >> Sciezka;
						cout << " Napisz o jaki parametr Ci chodzi ";
						cin >> parametr;
						int parametr1;
						if (parametr == "kolor")
						{
							parametr1 = 1;
						}
						if (parametr == "opis")
						{
							parametr1 = 2;
						}
						if (parametr == "p³eæ")
						{
							parametr1 = 3;
						}
						if (parametr == "rozmiar")
						{
							parametr1 = 4;
						}
						if (parametr == "id_produktu")
						{
							parametr1 = 5;
						}
						if (parametr == "nadruk")
						{
							parametr1 = 6;
						}
						string szukana;
						int lszuk;
						switch (parametr1)
						{
						case 1:
						{
							cout << "Jakiego koloru szukasz? ";
							cin >> szukana;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].szukaj(szukana))
								{
									cout << "Bluzka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 2:
						{
							cout << "Jakiego opisu produktu szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 3:
						{
							
							cout << "Dla jakiej p³ci to ma byæ produkt? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 4:
						{
							cout << "Jakiego rozmiaru szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].lszukaj(lszuk, parametr))
								{
									cout << "Bluzka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 5:
						{
							cout << "Produktu o jakim id szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].lszukaj(lszuk, parametr))
								{
									cout << "Bluzka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 6:
						{
							string szukana;
							cout << "Jakiego nadruku na produkcie szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i].laduj(Sciezka);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						default:
						{
							cout << "Takiego parametru nie ma!";
							exit(1);
						}
                        delete[] ktab;
						plik.close();
						}
						break;
					}
					break;
				}
				case 3:
				{
					fstream plik;
					plik.open("CzapkiIlosc.txt", ios::in);
					if (plik.good())
					{
						Czapki c;
						Ubranie* wskaznik = &c;
						plik >> ilosc;
						Czapki* ktab = new Czapki[ilosc];
						string parametr;
						string Sciezka;
						cout << "Podaj sciezke do pliku" << endl;
						cin >> Sciezka;
						cout << " Napisz o jaki parametr Ci chodzi ";
						cin >> parametr;
						int parametr1;
						if (parametr == "kolor")
						{
							parametr1 = 1;
						}
						if (parametr == "opis")
						{
							parametr1 = 2;
						}
						if (parametr == "p³eæ")
						{
							parametr1 = 3;
						}
						if (parametr == "rozmiar")
						{
							parametr1 = 4;
						}
						if (parametr == "id_produktu")
						{
							parametr1 = 5;
						}
						if (parametr == "model")
						{
							parametr1 = 6;
						}
						if (parametr == "daszek")
						{
							parametr1 = 7;
						}
						string szukana;
						int lszuk;
						switch (parametr1)
						{
						case 1:
						{
							cout << "Jakiego koloru szukasz? ";
							cin >> szukana;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].szukaj(szukana))
								{
									cout << "Czapka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 2:
						{
							cout << "Jakiego opisu produktu szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 3:
						{

							cout << "Dla jakiej p³ci to ma byæ produkt? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 4:
						{
							cout << "Jakiego rozmiaru szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].lszukaj(lszuk, parametr))
								{
									cout << "Bluzka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 5:
						{
							cout << "Produktu o jakim id szukasz? ";
							cin >> lszuk;
							int l = 1;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].lszukaj(lszuk, parametr))
								{
									cout << "Czapka nr: " << l << endl;
									l++;
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 6:
						{
							string szukana;
							cout << "Jakiego modelu szukasz? ";
							cin >> szukana;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].szukaj(szukana))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						case 7:
						{
							bool czyDaszek;
							cout << "Czapka ma miec daszek? ";
							cin >> czyDaszek;
							for (int i = 0; i < ilosc; i++)
							{
								ktab[i] = Czapki(Sciezka,i+1);
								if (ktab[i].cdaszek(czyDaszek))
								{
									wskaznik = &ktab[i];
									wskaznik->wypisz();
								}
								ktab[i + 1].getNr(i + 2);
							}
                            delete[] ktab;
							break;
						}
						default:
						{
							cout << "Takiego parametru nie ma!";
							exit(1);
						}
                        delete[] ktab;
						plik.close();
						}
						break;
					}
					break;
				}
				defalut:
				{
					cout << "Rodzaju ubran o takim numerze nie ma. Sprobuj jeszcze raz, moze wpisales cyfre slownie? ";
					break;
				}

			}
			break;
		}
		case 3:
		{
			int wybor2;
			string kolor2;
			string opis2;
			string plec2;
			int rozmiar2;
			int id_produktu2;
			cout << "Jaki towar chcesz wprowadzic?" << endl;
			cout << "1. Spodnie" << endl;
			cout << "2. Bluzki" << endl;
			cout << "3. Czapki" << endl;
			cin >> wybor2;
			switch (wybor2)
			{
				case 1:
				{
					int nrUbrania2;
					string typ2;
					int szerokosc_nogawki2;
					cout << "Jaki jest kolor?"<< endl;
					cin >> kolor2;
					cout << endl << "Podaj krotki opis" << endl;
					cin.ignore();
					getline(cin,opis2);
					cout << endl << " Dla jakiej jest to plci?" << endl;
					cin >> plec2;
					cout << endl<< "Jaki jest rozmiar?" << endl;
					cin >> rozmiar2;
					cout << endl << "Jakie jest id produktu?" << endl;
					cin >> id_produktu2;
					cout << endl << "Jaki jest typ tych spodni?" << endl;
					cin >> typ2;
					cout << endl << "Jaka jest szerokosc nogawki spodni?" << endl;
					cin >> szerokosc_nogawki2;
					Spodnie s(kolor2, opis2, plec2, typ2, rozmiar2, id_produktu2, szerokosc_nogawki2);
					wskaznik = &s;
					wskaznik->zapisz();
					fstream plik3;
					plik3.open("SpodnieIlosc.txt",ios::in);
                    int zmienna;
					if (plik3.good())
					{
						plik3 >> zmienna;
						zmienna++;
						plik3.close();
					}
					else
					{
						cout << "Blad otwierania pliku!";
						plik3.close();
						exit(1);
					}
                    plik3.open("SpodnieIlosc.txt", ios::out);
                    plik3 << zmienna;
					break;
				}
				case 2:
				{
					string nadruk2;
					cout << "Jaki jest kolor?";
					cin >> kolor2;
					cout << "Podaj krotki opis";
					cin.ignore();
					getline(cin, opis2);
					cout << " Dla jakiej jest to plci?";
					cin >> plec2;
					cout << "Jaki jest rozmiar?";
					cin >> rozmiar2;
					cout << "Jakie jest id produktu?";
					cin >> id_produktu2;
					cout << "Jaki jest nadruk na bluzce? Jesli nie ma, wpisz Brak";
					cin >> nadruk2;
					char* nadrukk;
					nadrukk = new char[nadruk2.length() + 1];
					strcpy(nadrukk, nadruk2.c_str());
					Bluzki b(kolor2, opis2, plec2, nadrukk, rozmiar2, id_produktu2);
					wskaznik = &b;
					wskaznik->zapisz();
					fstream plik3;
					plik3.open("BluzkiIlosc.txt", ios::in);
						int zmienna;
						plik3 >> zmienna;
						zmienna++;
						plik3.close();
					plik3.open("BluzkiIlosc.txt", ios::out);
					plik3 << zmienna;
					plik3.close();
					break;
				}
				case 3:
				{
					bool daszek2;
					string model2;
					int nrUbrania2;
					cout << "Jaki jest kolor?";
					cin >> kolor2;
					cout << "Podaj krotki opis";
					cin.ignore();
					getline(cin,opis2);
					cout << " Dla jakiej jest to plci?";
					cin >> plec2;
					cout << "Jaki jest rozmiar?";
					cin >> rozmiar2;
					cout << "Jakie jest id produktu?";
					cin >> id_produktu2;
					cout << "Jaki jest model czapki?";
					cin >> model2;
					cout << "Czy produkt ma daszek? Tak-1, nie-0";
					cin >> daszek2;
					Czapki c(kolor2, opis2, plec2, rozmiar2, id_produktu2, model2, daszek2);
					wskaznik = &c;
					wskaznik->zapisz();
					fstream plik3;
					plik3.open("CzapkiIlosc.txt", ios::in);
					int zmienna;
					if (plik3.good())
					{
						plik3 >> zmienna;
						zmienna++;
						plik3.close();
					}
					else
					{
						cout << "Blad otwierania pliku!";
						plik3.close();
						exit(1);
					}
					plik3.open("CzapkiIlosc.txt", ios::out);
					plik3 << zmienna;
					plik3.close();
					break;
				}
			}
			break;
		}
		default:
		{
			cout << "Nie ma opcji o takim numerze. Moze numer wpisales/as slownie?";
			break;
		}
	}
	return 0;
}