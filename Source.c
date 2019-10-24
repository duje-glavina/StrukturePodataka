/*2.Definirati strukturu osoba (ime, prezime, godina rođenja) i napisati program koji:
a)dinamički dodaje novi element na početak liste,
b)ispisuje listu,
c)dinamički dodaje novi element na kraj liste,
d)pronalazi element u listi (po prezimenu),
e)briše određeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/


#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME 40

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Struktura
struct osoba;
typedef struct osoba* Posoba;
struct osoba
{
	char ime[MAX_NAME];
	char prezime[MAX_NAME];
	int godina_rodjenja;
	Posoba Next;

};

//Funkcije

int unos(Posoba);
int ispis_liste(Posoba);
int izbornik();
int unos_na_kraj(Posoba);
Posoba trazi_prezime_prethodni(Posoba);
Posoba trazi_prezime(Posoba);
int brisi_prezime(Posoba);

int main()
{
	struct osoba Head;
	int x = 0,y=0;
	Posoba p1 = NULL;
	
	Head.Next = NULL;

	while (x!= 6)
	{
		x = izbornik();
		if (1 == x)
		{
			y = unos(&Head);
			if (y != 1) {
				printf("Greska tokom unosa!\n");
				y = 0;
			}
		}
		else if (2 == x)
		{
			y = ispis_liste(Head.Next);
			if (y != 1) {
				printf("Greska kod ispisa liste\n");
				y = 0;
			}
		}

		else if (3 == x)
		{
			y = unos_na_kraj(&Head);
			if (y != 1) {
				printf("Greska kod unosa na kraj liste\n");
				y = 0;
			}
		}
		else if (4 == x)
		{
			p1=trazi_prezime(Head.Next);
			if (p1 != NULL)
				printf("Trazena osoba je: %s %s %d \n", p1->ime, p1->prezime, p1->godina_rodjenja);
			else
				printf("Trazena osoba nije pronadjena\n");
			
		}
		else if (5 == x)
		{
			y = brisi_prezime(&Head);
			if (y != 1)
			{
				printf("Greska tokom brisanja\n");
				y = 0;
			}
		}
	}

	

	getchar();
	getchar();
	return 0;
}


//Unos elementa liste
int unos(Posoba P)
{
	Posoba q;
	q = (Posoba)malloc(sizeof(struct osoba));
	if (NULL==q)
	{
		printf("Greska prilikom alokacije memorije");
		return -1;
	}
	else
	{
		printf("Unesite ime prezime i godinu rodjenja osobe\n");
		scanf(" %s %s %d", q->ime, q->prezime, &q->godina_rodjenja);

		q->Next = P->Next;
		P->Next = q;
		return 1;
	}

}
//Ispis liste od poslanog clana
int ispis_liste(Posoba P)
{
	printf("Ispis Liste:\n");
	if (NULL==P)
	{

		printf("Prazna lista");
		return -1;
	}
	else
	{
		while (P != NULL)
		{

			printf("Ime: %s   Prezime: %s   Godina Rodjenja %d \n", P->ime, P->prezime, P->godina_rodjenja);
			P = P->Next;
			
		}
		return 1;

	}
}


//Funkcija izborinka
int izbornik()
{
	printf("\n Izbornik:\n");
	char c = '0';
	printf("Dodavanje novog clana na pocetak: 1\n");
	printf("Ispis liste:                      2\n");
	printf("Dodavanje na kraj liste:          3\n");
	printf("Pronalazi element liste(prezime)  4\n");
	printf("Briše element liste               5\n");
	printf("Exit                              6\n");
	scanf(" %c", &c);
	switch (c)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	default:
		printf("Nepodrzan odabir\n");
		return -1;
		
	}

}

//Unos Na Kraj liste
int unos_na_kraj(Posoba P)
{
	while (P->Next!=NULL)
	{
		P = P->Next;
	}
	unos(P);
	return 1;
}


//Trazenje prezimena prethodnog
Posoba trazi_prezime_prethodni(Posoba P)
{
	char prezime[MAX_NAME];
	printf("\nUpisite trazeno prezime\n");
	scanf(" %s", prezime, MAX_NAME);
	while ((P->Next != NULL) && (strcmp(P->Next->prezime, prezime) != 0))
	{
		P = P->Next;

	}
	if (NULL == P->Next)
		P = NULL;
}


//Trazenje prezimena 
Posoba trazi_prezime(Posoba P)
{
	Posoba temp = NULL;
	temp = trazi_prezime_prethodni(P);
	if (NULL == temp)
		return temp;
	else
	{
		temp = temp->Next;
		return temp;
	}
}

//Brisanje pleba po prezimenu

int brisi_prezime(Posoba P)
{
	Posoba temp_njega=NULL;
	Posoba temp_prethodnika=NULL;
	char prezime[MAX_NAME];

	printf("Unesite prezime osobe koju zelite izbrisati:\n");
	temp_prethodnika = trazi_prezime_prethodni(P->Next);
	temp_njega = temp_prethodnika->Next;

	temp_prethodnika->Next = temp_njega->Next;
	free(temp_njega);


	return 1;
}