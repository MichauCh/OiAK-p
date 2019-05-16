#include "natural.h"

class smNum
{
	bool sign; //false +, true -
	natural module; //modul reprezentowany przez liczbe naturalna
public:
	/* Konstruktor bezargumentowy */
	smNum();
	/* Konstruktor kopiujacy, z uinta */
	smNum(const uint32_t a);
	/* Konstruktor sam modul */
	smNum(const std::vector<uint32_t> &a);
	/* Konstruktor znak, modul (vector) */
	smNum(bool si, const std::vector<uint32_t> &a);
	/* Konstruktor kopiujacy */
	smNum(const smNum &b);
	/* Konstruktor kopiujacy, znak + natural */
	smNum(const bool si, const natural &n);
	/* Konstruktor kopiujacy */
	smNum(const natural &n);
	/* Konstruktor z konwersja z typu long long */
	smNum(long long value);

	void print();

	/* operator przypisania */
	void operator=(const smNum &x);
	/* operator porownania */
	bool operator==(const smNum &x);
	/* operator inkrementacji */
	void operator ++();
	/* operator dekrementacji */
	void operator --();
	/* operator porownania, wiekszy */
	bool operator >(const smNum &x);
	/* operator porownania, mniejszy */
	bool operator <(const smNum &x);
	/* operator porownania, wiekszy/rowny */
	bool operator >=(const smNum &x);
	/* operator porownania, mniejszy/rowny */
	bool operator <=(const smNum &x);
	/* operatory arytmetyczne */
	smNum operator+(const smNum x);
	smNum operator-(const smNum x);
	smNum operator*(const smNum x);
	smNum operator/(const smNum x);

	/* operacje arytmetyczne */
	//dodawanie
	void add(smNum x, smNum y);
	//odejmowanie
	void sub(smNum x, smNum y);
	//mnozenie
	void mul(smNum x, smNum y);
	//prymitywny algorytm dzielenia
	void div(smNum x, smNum y);
};