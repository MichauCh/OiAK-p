#include "sm.h"

	/* Konstruktor bezargumentowy */
	smNum::smNum()
		: sign(false),
		module() { }
	/* Konstruktor kopiujacy, z uinta */
	smNum::smNum(const uint32_t a) {
		sign = false;
		this->module.push_back(a);
	}
	/* Konstruktor sam modul */
	smNum::smNum(const std::vector<uint32_t> &a) {
		sign = false;
		module = natural(a);
	}

	/* Konstruktor znak-modul */
	smNum::smNum(bool si, const std::vector<uint32_t> &a) {
		sign = si;
		module = natural(a);
	}

	/* Konstruktor kopiujacy z smNum */
	smNum::smNum(const smNum &b)
		: sign(b.sign),
		module(b.module) { }

	/* Konstruktor kopiujacy znak + natural */
	smNum::smNum(const bool si, const natural &n)
		: sign(si),
		module(n) { }

	/* Konstruktor kopiujacy z natural */
	smNum::smNum(const natural &n)
		: sign(false),
		module(n) { }

	/* Konstruktor z konwersja z typu long long */
	smNum::smNum(long long value)
	{
		if (value < 0) {
			sign = true;
			module = natural(0);
		}
		else {
			sign = false;
		}

		while (value) {
			module.push_back((uint32_t)(value));
		}
	}
	/* getter do znaku */
	bool smNum::getSign() const{
		return this->sign;
	}
	/* setter do znaku */
	void smNum::setSign(const bool si) {
		this->sign = si;
	}
	/* getter do wartosci */
	std::vector<uint32_t> smNum::getModule() const{
		return this->module.getValue();
	}
	/* getter do wartosci */
	natural smNum::getNatural() const{
		return this->module;
	}
	/* setter do wartosci */
	void smNum::setModule(const std::vector<uint32_t> &a) {
		this->module.setValue(a);
	}
	/* setter do wartosci */
	void smNum::setNatural(const natural &a) {
		this->module = a;
	}

	/* wypisywanie wartosci */
	void smNum::print() const{
		if (sign)
			std::cout << "- ";
		else
			std::cout << "+ ";

		module.print();
	}

	/* operator przypisania */
	void smNum::operator=(const smNum &x) {
		this->sign = x.sign;
		this->module = x.module;
	}
	/* operator porownania */
	bool smNum::operator==(const smNum &x) const{
		if (this->sign != x.sign) //jesli znaki sa rozne false
			return false;
		else //porownanie wartosci
			if (this->module == x.module)
				return true;
			else
				return false;
	}

	/* operator inkrementacji */
	void smNum::operator++() {
		if (!sign) //dodatnie
			this->module.operator++();
		else //ujemne
			this->module.operator--();
	}
	/* operator dekrementacji */
	void smNum::operator--() {
		if (!sign) //dodatnie
			this->module.operator--();
		else //ujemne
			this->module.operator++();
	}

	/* operator porownania, wiekszy */
	bool smNum::operator >(const smNum &x) const{
		if (this->sign != x.sign) { //znaki rozne
			if (this->sign == 0 && x.sign == 1) //x jest liczba ujemna
				return true;
			else
				return false; //x dodatnie a liczba ujemna
		}
		else { //znaki zgodne
			if (this->sign == 0) { //obie liczby dodatnie
				if (this->module > x.module)
					return true;
				else
					return false;
			}
			else{ //obie liczby ujemne
				if (this->module < x.module)
					return true;
				else
					return false;
				}
		}
	}
	/* operator porownania, mniejszy */
	bool smNum::operator <(const smNum &x) const{
		if (this->sign != x.sign) { //znaki rozne
			if (this->sign == 0 && x.sign == 1) //x jest liczba ujemna
				return false;
			else
				return true; //x dodatnie a liczba ujemna
		}
		else { //znaki zgodne
			if (this->sign == 0) { //obie liczby dodatnie
				if (this->module < x.module)
					return true;
				else
					return false;
			}
			else { //obie liczby ujemne
				if (this->module > x.module)
					return true;
				else
					return false;
			}
		}
	}
	/* operator porownania, wiekszy/rowny */
	bool smNum::operator >=(const smNum &x) const{
		if (this->sign != x.sign) { //znaki rozne
			if (this->sign == 0 && x.sign == 1) //x jest liczba ujemna
				return true;
			else
				return false; //x dodatnie a liczba ujemna
		}
		else { //znaki zgodne
			if (this->sign == 0) { //obie liczby dodatnie
				if (this->module >= x.module)
					return true;
				else
					return false;
			}
			else { //obie liczby ujemne
				if (this->module <= x.module)
					return true;
				else
					return false;
			}
		}
	}
	/* operator porownania, mniejszy/rowny */
	bool smNum::operator <=(const smNum &x) const{
		if (this->sign != x.sign) { //znaki rozne
			if (this->sign == 0 && x.sign == 1) //x jest liczba ujemna
				return false;
			else
				return true; //x dodatnie a liczba ujemna
		}
		else { //znaki zgodne
			if (this->sign == 0) { //obie liczby dodatnie
				if (this->module <= x.module)
					return true;
				else
					return false;
			}
			else { //obie liczby ujemne
				if (this->module >= x.module)
					return true;
				else
					return false;
			}
		}
	}
	smNum smNum::operator+(const smNum &x) {
		smNum result;
		result.add(*this, x);
		return result;
	}
	smNum smNum::operator-(const smNum &x) {
		smNum result;
		result.sub(*this, x);
		return result;
	}
	smNum smNum::operator*(const smNum &x) {
		smNum result;
		result.mul(*this, x);
		return result;
	}
	smNum smNum::operator/(const smNum &x) {
		smNum result;
		result.div(*this, x);
		return result;
	}
/* operacje arytmetyczne */
// dodawanie
	void smNum::add(const smNum &x, const smNum &y) {
		if (x.sign == y.sign) { //znaki zgodne
			this->sign = x.sign;
			this->module.add(x.module, y.module);
		}
		else { //znaki niezgodne
			if (x.module >= y.module) {
				this->sign = x.sign;
				this->module.subtract(x.module, y.module);
			}
			else
			{
				this->sign = y.sign;
				this->module.subtract(y.module, x.module);
			}
		}
	}
// odejmowanie
	void smNum::sub(const smNum &x, const smNum &y) {
		if (x.sign == y.sign) { //znaki zgodne
			if (x.module >= y.module) {
				this->sign = x.sign;
				this->module.subtract(x.module, y.module);
			}
			else
			{
				this->sign = !(x.sign);
				this->module.subtract(y.module, x.module);
			}
		}
		else { //znaki niezgodne
			this->sign = x.sign;
			if (x.sign == 0) {
				this->module.add(x.module, y.module);
			}
			else
			{
				this->module.add(x.module, y.module);
			}
		}
	}
// mnozenie 
	void smNum::mul(const smNum &x, const smNum &y) {
			if (x.sign == y.sign)
				this->sign = 0;
			else
				this->sign = 1;

			this->module.multiply(x.module, y.module);
	}
// prymitywny algorytm dzielenia
	void smNum::div(const smNum &x, const smNum &y) {
		if (x.sign == y.sign)
			this->sign = 0;
		else
			this->sign = 1;

		this->module.divide(x.module, y.module);
	}