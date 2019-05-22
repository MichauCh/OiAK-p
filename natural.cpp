#include "natural.h"

	/* Konstruktor bezargumentowy */
	natural::natural() {}
	/* Konstruktor kopiujacy, z uinta */
	natural::natural(const uint32_t a) {
		this->value.push_back(a);
	}
	/* Konstruktor kopiujacy, z vectora */
	natural::natural(const std::vector<uint32_t> &a) {
		this->value = a;
	}
	/* Konstruktor kopiujacy, z natural */
	natural::natural(const natural &a) : value(a.value) {}

	/* getter do wartosci */
	std::vector<uint32_t> natural::getValue() const{
		return this->value;
	}
	/* setter do wartosci */
	void natural::setValue(const std::vector<uint32_t> &a) {
		this->value = a;
	}
	/* Funkcja, ktora dodaje uinta32 do wartosci */
	void natural::push_back(const uint32_t a) {
		this->value.push_back(a);
	}
	/* Funkcja, ktora usuwa element o najwyzszej wadze */
	void natural::pop_back() {
		this->value.pop_back();
	}
	/* liczba elementow */
	unsigned natural::size() const{
		return this->value.size();
	}
	/* liczba bitow, potrzebnych do zapisania liczby */
	unsigned natural::bitSize() const{
		return 32 * this->value.size();
	}
	/* operator przypisania */
	void natural::operator=(const natural &x) {
		value = x.getValue();
	}
	/* operator porownania */
	bool natural::operator==(const natural &x) const {
		if (value.size() != x.value.size())
			return false;
		else {
			// porownywanie kolejnych elementow
			for (unsigned i = 0; i < x.value.size(); i++)
				if (value[i] != x.value[i])
					return false;
			return true;
		}
	}
	/* operator porownania do pojedynczej liczby */
	bool natural::operator==(const unsigned &x) const {
		if (value.size() > 1)
			return false;
		else {
			if(value[0] == x)
				return true;
			else
				return false;			
		}
	}
	/* operator inkrementacji */
	void natural::operator++() {
		unsigned i = 0;
		bool cIn = true;
		for (; i < this->value.size() && cIn; i++) {
			this->value[i]++;
			cIn = (this->value[i] == 0);
		}
		if (cIn) {
			this->value.push_back(1);
		}
	}
	/* operator dekrementacji */
	void natural::operator--() {
		if (this->isZero())
			throw std::runtime_error("Dekrementacja 0 niedozwolona\n");
		int i = 0;
		bool bIn = true;
		for (; bIn; i++) {
			bIn = (this->value[i] == 0);
			this->value[i]--;
		}
	}

	/* operator porownania, wiekszy */
	bool natural::operator >(const natural &x) const {
		if (this->value.size() > x.value.size())
			return true;
		else if (this->value.size() < x.value.size())
			return false;
		else { //argumenty tej samej dlugosci
			// porownywanie kolejnych elementow od lewej (tych o wyzszej wadze)
			for (int i = this->value.size() - 1; i >= 0; i--)
				if (this->value[i] > x.value[i])
					return true;
			return false;
		}
	}
	/* operator porownania, mniejszy */
	bool natural::operator <(const natural &x) const {
		if (this->value.size() < x.value.size())
			return true;
		else if (this->value.size() > x.value.size())
			return false;
		else { //argumenty tej samej dlugosci
			// porownywanie kolejnych elementow od lewej (tych o wyzszej wadze)
			for (int i = this->value.size() - 1; i >= 0; i--)
				if (this->value[i] < x.value[i])
					return true;
			return false;
		}
	}
	/* operator porownania, wiekszy/rowny */
	bool natural::operator >=(const natural &x) const{
		unsigned int counter = 0; //licznik rownych elementow
		if (this->value.size() > x.value.size())
			return true;
		else if (this->value.size() < x.value.size())
			return false;
		else { //argumenty tej samej dlugosci
			// sprawdzenie czy jest wiekszy
			for (unsigned int i = this->value.size() - 1; i >= 0; i--) {
				if (this->value[i] > x.value[i])
					return true;
				else if (this->value[i] == x.value[i]) //sprawdzenie czy rowne
					counter++;
			}
			if (counter == this->value.size()) //wszystkie elementy sa rowne
				return true;
			else
				return false;
		}
	}
	/* operator porownania, mniejszy/rowny */
	bool natural::operator <=(const natural &x) const {
		unsigned int counter = 0; //licznik rownych elementow
		if (this->value.size() < x.value.size())
			return true;
		else if (this->value.size() > x.value.size())
			return false;
		else { //argumenty tej samej dlugosci
			// sprawdzenie czy jest mniejszy
			for (unsigned int i = this->value.size() - 1; i >= 0; i--) {
				if (this->value[i] < x.value[i])
					return true;
				else if (this->value[i] == x.value[i]) //sprawdzenie czy rowne
					counter++;
			}
			if (counter == this->value.size()) //wszystkie elementy sa rowne
				return true;
			else
				return false;
		}
	}

	/* wypisywanie wartosci */
	void natural::print() const{
		for (int i = value.size() - 1; i >= 0; i--)
			std::cout << value[i] << " ";
		std::cout << "\n";
	}
	/* usuwanie wiodacego zera */
	void natural::eraseLeadingZeroIfExists() {
		if ((this->value.size() - 1) == 0) //jesli elementem o najwyzszej wadze jest 0
			this->value.pop_back(); //trzeba je usunac, zaburza wykonanie porownania
	}

	bool natural::isZero() const{
		if(this->value.size() == 0)
			return true;
		if(this->value.size() == 1 && value[0] == 0)
			return true;
		for(unsigned i = 0; i < this->value.size()-1; i++){
			if(this->value[i] != 0)
				return false;
		}
		return true;	
	}
	/* operacje arytmetyczne */
	/* dodawanie */
	void natural::add(const natural &x, const natural &y) {
		bool cIn, cOut; //przeniesienia na konkretnych pozycjach
		uint32_t temp; //przechowywanie sumy
		unsigned i = 0; //indeksowanie

		const natural *shorterArg, *longerArg; //zmienne na krotszy i dluzszy argument
		if (x.value.size() >= y.value.size()) { //rownej dlugosci lub x dluzszy od y
			longerArg = &x;
			shorterArg = &y;
		}
		else { //y dluzszy od x
			longerArg = &y;
			shorterArg = &x;
		}
		// dla kazdego elementu w zasiegu krotszego argumentu
		for (cIn = false; i < shorterArg->value.size(); i++) {
			temp = longerArg->value[i] + shorterArg->value[i];
			cOut = (temp < longerArg->value[i]); //sprawdzenie czy uint sie "nie przekrecil"
			if (cIn) {
				temp++;
				cOut |= (temp == 0); // cOut | temp
			}
			this->value.push_back(temp); // zapisanie wyniku
			cIn = cOut; // przeniesienie w nastepnej iteracji
		}
		//w zasiegu dluzszego argumentu z przeniesieniem
		for (; i < longerArg->value.size() && cIn; i++) {
			temp = longerArg->value[i] + 1;
			cIn = (temp == 0); //max val + 1 = 0
			this->value.push_back(temp);
		}
		//w zasiegu dluzszego argumentu bez przeniesienia
		for (; i < longerArg->value.size(); i++)
			this->value.push_back(longerArg->value[i]); //przepisywanie
		//Dodatkowy element w przypadku nadmiaru
		if (cIn)
			this->value.push_back(1);
	}
	/* odejmowanie */
	void natural::subtract(const natural &x, const natural &y) {
		bool bIn, bOut; //pozyczki na konkretnych pozycjach
		uint32_t temp; //przechowywanie roznicy
		unsigned i = 0; //indeksowanie

		for (bIn = false; i < y.value.size(); i++) {
			temp = x.value[i] - y.value[i];
			bOut = (temp > x.value[i]); //sprawdzenie czy uint sie "nie przekrecil"
			if (bIn) {
				bOut |= (temp == 0); // bOut | temp
				temp--;
			}
			this->value.push_back(temp); // zapisanie wyniku
			bIn = bOut; // pozyczka w nastepnej iteracji
		}
		// dalsze pozyczki
		for (; i < x.value.size() && bIn; i++) {
			bIn = (x.value[i] == 0);
			this->value.push_back(x.value[i] - 1);
		}
		if (bIn) {
			this->value.clear();
			throw std::runtime_error("Wynik odejmowania ujemny");
		}
		else //dalsze przepisywanie odjemnej, bez zmian
			for (; i < x.value.size(); i++)
				this->value.push_back(x.value[i]);
	}
	/* mnozenie */
	void natural::multiply(const natural &x, const natural &y) {
		int cIn = 0;
		int cOut = 0;
		uint32_t temp = 0;
		std::vector<uint32_t> tempMod;
		natural tempVec;
		natural tempNat;
		int longerArg = 0;
		if (x.value.size() >= y.value.size())
			longerArg = x.value.size();
		else longerArg = y.value.size();

		unsigned long long longtemp;
		for (unsigned i = 0; i < x.value.size(); i++) {
			for (unsigned k = 0; k < i; k++) {
				tempVec.value.insert(tempVec.value.begin(), 0);
			}
			for (unsigned j = 0; j < y.value.size(); j++) {
				longtemp = x.value[i] * y.value[j] + cIn;
				temp = longtemp;
				tempVec.value.insert(tempVec.value.begin() + i + j, temp);
				if (temp == longtemp) {
					cIn = 0;
				}
				else {
					cIn = longtemp / 4294967295;
				}
				temp = 0;

			}
			tempMod = this->value;
			tempNat.value = tempMod;
			this->value.clear();
			this->add(tempNat, tempVec);
			tempVec.value.clear();
			tempMod.clear();
		}
	}

	// prymitywny algorytm dzielenia
	void natural::divide(const natural &x, const natural &y) {
		if(y.isZero())
			throw std::runtime_error("Dzielenie przez 0\n");
		natural divident(x); //kopia do dzialan dzielnej
		natural quotient(0); //przechowywanie ilorazu, quotient
		natural temp;

		while (divident.operator>(y)) { //powinno byc >= ale samo > to mniej operacji
			temp.subtract(divident, y);
			divident.value = temp.value; //kopiowanie wartosci
			divident.print();
			temp.value.clear(); //zwalnianie pamieci z temp
			quotient.operator++();
			divident.eraseLeadingZeroIfExists();
		}
		if (divident.operator==(y)) { //ostatnie porownanie
			temp.subtract(divident, y);
			divident.value = temp.value; //kopiowanie wartosci
			temp.value.clear(); //zwalnianie pamieci z temp
			quotient.operator++();
		}
		this->value = quotient.value;
		temp.value.clear(); //zwalnianie pamieci z temp
		divident.value.clear();
	}