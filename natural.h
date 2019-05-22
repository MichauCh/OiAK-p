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
	/* getter do wartosci */
	std::vector<uint32_t> getValue();
	/* setter do wartosci */
	void setValue(const std::vector<uint32_t> &a);

	/* funkcja do dodawania elementow */
	void push_back(const uint32_t a);
	/* funkcja do usuwania elementow */
	void pop_back();
	/* liczba elementow */
	unsigned size() const;
	/* liczba bitow, potrzebnych do zapisania liczby */
	unsigned bitSize() const;

	/* operator przypisania */
	void operator=(const natural &x);
	/* operator porownania */
	bool operator==(const natural &x) const;
	/* operator porownania do pojedynczej liczby */
	bool operator==(const unsigned &x) const;
	/* operator inkrementacji */
	void operator ++();
	/* operator dekrementacji */
	void operator --();
	/* operator porownania, wiekszy */
	bool operator >(const natural &x) const;
	/* operator porownania, mniejszy */
	bool operator <(const natural &x) const;
	/* operator porownania, wiekszy/rowny */
	bool operator >=(const natural &x) const;
	/* operator porownania, mniejszy/rowny */
	bool operator <=(const natural &x) const;
	/* wypisywanie wartosci */
	void print() const;
	/* usuwanie wiodacego zera */
	void eraseLeadingZeroIfExists();
	bool isZero() const;

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

