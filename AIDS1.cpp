#include <iostream>
#include <stdio.h>

using namespace std;
int** liczby;
int* rozmiarliczby;
int n;
const int ROZMIAR = 2500;

void wprowadzanie()
{
	for (int i = 0; i < n; i++)
	{
		char wejscie[ROZMIAR];
		cin >> wejscie;
		int k = 0;
		while (wejscie[k] != '\0')
		{
			k++;
		}
		if (wejscie[0] == '-')
			rozmiarliczby[i] = k;
		else
			rozmiarliczby[i] = k + 1;
		int* liczba = new int[rozmiarliczby[i]];
		for (int  j = 0; j < k; j++)
		{
			if (wejscie[0] == '-')
			{
				liczba[0] = 1;
				if(j+1<k)
					liczba[j + 1] = (wejscie[j + 1] - '0');
			}
			else
			{
				liczba[0] = 0;
				liczba[j + 1] = (wejscie[j] - '0');
			}	
		}
		liczby[i] = liczba;
	}
}
void wypisywanie()
{
	for (int i = 0; i < n; i++)
	{
		int* liczba = liczby[i];
		if (liczba[0] == 1)
			cout << '-';
		for (int j = 1; j < rozmiarliczby[i]; j++)
		{
			cout << liczba[j];
		}
			
		cout << endl;
	}
}

void najwieksza()
{
	int najwiekszyrozmiarliczby = rozmiarliczby[0];
	int* najwiekszaliczba = liczby[0];
	for (int i = 1; i < n; i++)
	{
		int* liczbasprawdzana = liczby[i];
		if (najwiekszaliczba[0]==1 && liczbasprawdzana[0]==0)
		{
			najwiekszaliczba = liczbasprawdzana;
			najwiekszyrozmiarliczby = rozmiarliczby[i];
		}
		else if ((rozmiarliczby[i] > najwiekszyrozmiarliczby) && (najwiekszaliczba[0]==0) && (liczbasprawdzana[0]==0))
		{
			najwiekszyrozmiarliczby = rozmiarliczby[i];
			najwiekszaliczba = liczby[i];
		}
		else if ((rozmiarliczby[i] < najwiekszyrozmiarliczby) && (najwiekszaliczba[0] == 1) && (liczbasprawdzana[0] == 1))
		{
			najwiekszyrozmiarliczby = rozmiarliczby[i];
			najwiekszaliczba = liczby[i];
		}
		else if (rozmiarliczby[i] == najwiekszyrozmiarliczby && (najwiekszaliczba[0] == 1) && (liczbasprawdzana[0] == 1))
		{
			for (int j = 1; j < rozmiarliczby[i]; j++)
			{
				if (liczbasprawdzana[j] < najwiekszaliczba[j])
				{
					najwiekszaliczba = liczbasprawdzana;
					break;
				}
				if (liczbasprawdzana[j] > najwiekszaliczba[j])
				{
					break;
				}
			}
		}
		else if (rozmiarliczby[i] == najwiekszyrozmiarliczby && (najwiekszaliczba[0] == 0) && (liczbasprawdzana[0] == 0))
		{
			for (int j = 1; j < rozmiarliczby[i]; j++)
			{
				if (liczbasprawdzana[j] > najwiekszaliczba[j])
				{
					najwiekszaliczba = liczbasprawdzana;
					break;
				}
				if (liczbasprawdzana[j] < najwiekszaliczba[j])
				{
					break;
				}
			}
		}
	}
	int* liczba = najwiekszaliczba;
	if (liczba[0] == 1)
		cout << '-';
	for (int j = 1; j < najwiekszyrozmiarliczby; j++)
		cout << liczba[j];
	cout << endl;
}

void najmniejsza()
{
	int najmniejszyrozmiarliczby = rozmiarliczby[0];
	int* najmniejszaliczba = liczby[0];
	for (int i = 1; i < n; i++)
	{
		int* liczbasprawdzana = liczby[i];
		if (najmniejszaliczba[0] == 0 && liczbasprawdzana[0] == 1)
		{
			najmniejszaliczba = liczbasprawdzana;
			najmniejszyrozmiarliczby = rozmiarliczby[i];
		}
		else if ((rozmiarliczby[i] < najmniejszyrozmiarliczby) && (najmniejszaliczba[0] == 0) && (liczbasprawdzana[0] == 0))
		{
			najmniejszyrozmiarliczby = rozmiarliczby[i];
			najmniejszaliczba = liczby[i];
		}
		else if ((rozmiarliczby[i] > najmniejszyrozmiarliczby) && (najmniejszaliczba[0] == 1) && (liczbasprawdzana[0] == 1))
		{
			najmniejszyrozmiarliczby = rozmiarliczby[i];
			najmniejszaliczba = liczby[i];
		}
		else if (rozmiarliczby[i] == najmniejszyrozmiarliczby && (najmniejszaliczba[0] == 0) && (liczbasprawdzana[0] == 0))
		{
			for (int j = 1; j < rozmiarliczby[i]; j++)
			{
				if (liczbasprawdzana[j] < najmniejszaliczba[j])
				{
					najmniejszaliczba = liczbasprawdzana;
					break;
				}
				if (liczbasprawdzana[j] > najmniejszaliczba[j])
					break;
			}
		}
		else if (rozmiarliczby[i] == najmniejszyrozmiarliczby && (najmniejszaliczba[0] == 1) && (liczbasprawdzana[0] == 1))
		{
			for (int j = 1; j < rozmiarliczby[i]; j++)
			{
				if (liczbasprawdzana[j] > najmniejszaliczba[j])
				{
					najmniejszaliczba = liczbasprawdzana;
					break;
				}
				if (liczbasprawdzana[j] < najmniejszaliczba[j])
					break;
			}
		}
	}
	int* liczba = najmniejszaliczba;
	if (liczba[0] == 1)
		cout << '-';
	for (int j = 1; j < najmniejszyrozmiarliczby; j++)
		cout << liczba[j];
	cout << endl;
}

void odejmowanie(int miejscezapisu, int indeks1, int indeks2)
{
	int dlugoscwyniku = 0;
	int* liczba1 = liczby[indeks1];
	int* liczba2 = liczby[indeks2];
	if (rozmiarliczby[indeks1] >= rozmiarliczby[indeks2])
		dlugoscwyniku = rozmiarliczby[indeks1];
	else
		dlugoscwyniku = rozmiarliczby[indeks2];
	int* wynik = new int[dlugoscwyniku];
	for (int i = 0; i < dlugoscwyniku; i++)
		wynik[i] = 0;
	int d = dlugoscwyniku-1, j = rozmiarliczby[indeks1] - 1, i = rozmiarliczby[indeks2] - 1;
	while (1)
	{
		if (i > 0 && j > 0)
		{
			if ((rozmiarliczby[indeks1] == rozmiarliczby[indeks2]) && liczba1[0] == 1 && liczba2[0] == 0 && (liczba1[1] > liczba2[1]))
				wynik[0] = 1;
			if ((rozmiarliczby[indeks1] == rozmiarliczby[indeks2]) && (liczba2[1] > liczba1[1]) && liczba1[0] == 0 && liczba2[0] == 1)
			{
				wynik[d] = liczba2[i] - liczba1[j];
				wynik[0] = 1;
			}
			else
				wynik[d] = liczba1[j] - liczba2[i];
			i--;
			j--;
			d--;
		}
		else if (i > 0 && j <= 0)
		{
			wynik[d] = liczba2[i];
			i--;
			d--;
		}
		else if (i <= 0 && j > 0)
		{
			wynik[d] = liczba1[j];
			j--;
			d--;
		}
		else
			break;
	}
	for (int i = dlugoscwyniku; i > 0; i--)
	{
		if (wynik[i] > 9)
		{
			wynik[i] = wynik[i] % 10;
			wynik[i - 1] += 1;
		}
	}
	liczby[miejscezapisu] = wynik;
	rozmiarliczby[miejscezapisu] = dlugoscwyniku;
}

void dodawanie(int miejscezapisu, int indeks1, int indeks2,bool znak)
{
	int dlugoscwyniku = 0;
	int* liczba1 = liczby[indeks1];
	int* liczba2 = liczby[indeks2];
	if (rozmiarliczby[indeks1] >= rozmiarliczby[indeks2])
		dlugoscwyniku = rozmiarliczby[indeks1];
	else
		dlugoscwyniku = rozmiarliczby[indeks2];
	int* wynik = new int[dlugoscwyniku + 1];
	for (int i = 0; i < dlugoscwyniku; i++)
		wynik[i] = 0;
	int d = dlugoscwyniku, j = rozmiarliczby[indeks1] - 1, i = rozmiarliczby[indeks2] - 1;
	while (1)
	{
		if (i > 0 && j > 0)
		{
			wynik[d] = liczba1[j] + liczba2[i];
			i--;
			j--;
			d--;
		}
		else if (i > 0 && j <= 0)
		{
			wynik[d] = liczba2[i];
			i--;
			d--;
		}
		else if (i <= 0 && j > 0)
		{
			wynik[d] = liczba1[j];
			j--;
			d--;
		}
		else
			break;
	}
	for (int i = dlugoscwyniku; i > 0; i--)
	{
		if (wynik[i] > 9)
		{
			wynik[i] = wynik[i] % 10;
			wynik[i - 1] += 1;
		}
	}
	if (wynik[1] == 0)
	{
		for (int i = 2; i < dlugoscwyniku + 1; i++)
		{
			wynik[i - 1] = wynik[i];
		}
		dlugoscwyniku--;
	}
	if (znak == 1)
		wynik[0] = 1;
	liczby[miejscezapisu] = wynik;
	rozmiarliczby[miejscezapisu] = dlugoscwyniku + 1;
}

void dzialanie(int miejscezapisu)
{
	int indeks1, indeks2,dlugoscwyniku=0;
	char rownosc, znak;
	cin >> rownosc >> indeks1 >> znak >> indeks2;	
	int* liczba1 = liczby[indeks1];
	int* liczba2 = liczby[indeks2];
	if (liczba1[0] == 0 && liczba2[0] == 0)
		dodawanie(miejscezapisu,indeks1,indeks2,0);
	else if (liczba1[0] == 1 && liczba2[0] == 1)
		dodawanie(miejscezapisu, indeks1, indeks2,1);
	else if (liczba1[0] == 0 && liczba2[0] == 1)
		odejmowanie(miejscezapisu, indeks1, indeks2);
	else
		odejmowanie(miejscezapisu, indeks1, indeks2);
}

void operacje(bool* koniec)
{
		char wyrazenie[1000] = {};
		cin >> wyrazenie;
		if (wyrazenie[0] == '?')
		wypisywanie();
		else if (wyrazenie[0] == 'q')
		*koniec = true;
		else if (wyrazenie[0] == 'm' && wyrazenie[1] == 'a')
			najwieksza();
		else if (wyrazenie[0] == 'm' && wyrazenie[1] == 'i')
			najmniejsza();
		else
		{
			int miejscezapisu = 0;
			sscanf_s(wyrazenie, "%d", &miejscezapisu);
			dzialanie(miejscezapisu);
		}	
}

int main()
{
	cin >> n;
	liczby = new int*[n];
	rozmiarliczby = new int [n];
	bool koniec = false;
	wprowadzanie();
	while (koniec != true)
		operacje(&koniec);
	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Dexbugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
