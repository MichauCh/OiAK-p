#include <iostream>
#include <vector>

class natural {
private:
	std::vector<uint32_t> value;

public:
	/* Konstruktor bezargumentowy */
	natural();
	/* Konstruktor kopiujacy, z uinta */
	natural(const uint32_t a);
	/* Konstruktor kopiujacy, z vectora */
	natural(const std::vector<uint32_t> &a);
	/* Konstruktor kopiujacy, z natural */
	natural(const natural &a);

	/* funkcja do dodawania elementow */
	void push_back(const uint32_t a);
	/* funkcja do usuwania elementow */
	void pop_back();
	/* liczba elementow */
	unsigned size();


	/* operator przypisania */
	void operator=(const natural &x);
	/* operator porownania */
	bool operator==(const natural &x);
	/* operator inkrementacji */
	void operator ++();
	/* operator dekrementacji */
	void operator --();
	/* operator porownania, wiekszy */
	bool operator >(const natural &x);
	/* operator porownania, mniejszy */
	bool operator <(const natural &x);
	/* operator porownania, wiekszy/rowny */
	bool operator >=(const natural &x);
	/* operator porownania, mniejszy/rowny */
	bool operator <=(const natural &x);
	/* wypisywanie wartosci */
	void print();
	/* usuwanie wiodacego zera */
	void eraseLeadingZeroIfExists();


	/* operacje arytmetyczne */
	/* dodawanie */
	void add(const natural &x, const natural &y);
	/* odejmowanie */
	void subtract(const natural &x, const natural &y);
	/* mnozenie */
	void multiply(const natural &x, const natural &y);
	// prymitywny algorytm dzielenia
	void divide(const natural &x, const natural &y);
};

