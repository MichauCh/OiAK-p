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
	/* Destruktor */
	~smNum();

	/* getter do znaku */
	bool getSign() const;
	/* setter do znaku */
	void setSign(const bool si);
	/* getter do wartosci */
	std::vector<uint32_t> getModule() const;
	/* getter do wartosci */
	natural getNatural() const;
	/* setter do wartosci */
	void setModule(const std::vector<uint32_t> &a);
	/* setter do wartosci */
	void setNatural(const natural &a);
	/* liczba elementow */
	unsigned size() const;
	/* liczba bitow, potrzebnych do zapisania liczby */
	unsigned bitSize() const;
	void print() const;

	/* operator przypisania */
	void operator=(const smNum &x);
	/* operator porownania */
	bool operator==(const smNum &x) const;
	/* operator porownania do liczby */
	bool operator==(const int &x) const;
	/* operator inkrementacji */
	void operator ++();
	/* operator dekrementacji */
	void operator --();
	/* operator porownania, wiekszy */
	bool operator >(const smNum &x) const;
	/* operator porownania, mniejszy */
	bool operator <(const smNum &x) const;
	/* operator porownania, wiekszy/rowny */
	bool operator >=(const smNum &x) const;
	/* operator porownania, mniejszy/rowny */
	bool operator <=(const smNum &x) const;
	/* operatory arytmetyczne */
	smNum operator+(const smNum &x);
	smNum operator-(const smNum &x);
	smNum operator*(const smNum &x);
	smNum operator/(const smNum &x);

	/* operacje arytmetyczne */
	//dodawanie
	void add(const smNum &x, const smNum &y);
	//odejmowanie
	void sub(const smNum &x, const smNum &y);
	//mnozenie
	void mul(const smNum &x, const smNum &y);
	//prymitywny algorytm dzielenia
	void div(const smNum &x, const smNum &y);
};