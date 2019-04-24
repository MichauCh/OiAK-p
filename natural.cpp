#include <iostream>
#include <vector>

class natural{
private:
	std::vector<uint32_t> module;
    
public:
    /* Konstruktor bezargumentowy */
    natural(){
    }
    /* Konstruktor kopiujacy */
	natural(const  std::vector<uint32_t> &a){
        this->module = a;
    }
	/* Konstruktor kopiujacy */
	natural(const natural &a) : module(a.module) {}
	/* operator przypisania */
	void operator=(const natural &x) {
		this->module = x.module;
	}
    /* operator porownania */
    bool operator ==(const natural &x) const {
        if (module.size() != x.module.size())
            return false;
        else {
            // porownywanie kolejnych elementow
            for (int i = 0; i < x.module.size(); i++)
                if (module[i] != x.module[i])
                    return false;
            return true;
        }
    }
    /* operator inkrementacji */
    void operator ++() {
        int i=0;
        bool cIn = true;
        for (; i < module.size() && cIn; i++) {
            module[i]++;
            cIn = (module[i] == 0);
        }
        if (cIn) {
            module.push_back(1);
        }
    }
    /* operator dekrementacji */
    void operator --() {
        if (module.size()==0)
            std::cout<<"Niezainicjalizowana liczba";
        int i=0;
        bool bIn = true;
        for (; bIn; i++) {
            bIn = (module[i] == 0);
            module[i]--;
        }
    }
    /* wypisywanie wartosci */
    void print() { 
    for (int i=0; i<module.size(); i++) 
       std::cout << module[i] << " ";
    std::cout<<"\n";
    }
    /* operacje arytmetyczne */
    /* dodawanie */
    void add(const natural &x, const natural &y) {
        bool cIn, cOut; //przeniesienia na konkretnych pozycjach
        uint32_t temp; //przechowywanie sumy
        int i; //indeksowanie

        const natural *shorterArg, *longerArg; //zmienne na krotszy i dluzszy argument
        if (x.module.size() >= y.module.size()) { //rownej dlugosci lub x dluzszy od y
            longerArg = &x;
            shorterArg = &y;
        } else { //y dluzszy od x
            longerArg = &y;
            shorterArg = &x;
        }
        // dla kazdego elementu w zasiegu krotszego argumentu
        for (i = 0, cIn = false; i < shorterArg->module.size(); i++) {
            temp = longerArg->module[i] + shorterArg->module[i];
            cOut = (temp < longerArg->module[i]); //sprawdzenie czy uint sie "nie przekrecil"
            if (cIn) {
                temp++;
                cOut |= (temp == 0); // cOut | temp
            }
            this->module.push_back(temp); // zapisanie wyniku
            cIn = cOut; // przeniesienie w nastepnej iteracji
        }
        //w zasiegu dluzszego argumentu z przeniesieniem
        for (; i < longerArg->module.size() && cIn; i++) {
            temp = longerArg->module[i] + 1;
            cIn = (temp == 0); //max val + 1 = 0
            this->module.push_back(temp);
        }
        //w zasiegu dluzszego argumentu bez przeniesienia
        for (; i < longerArg->module.size(); i++)
            this->module.push_back(longerArg->module[i]); //przepisywanie
        //Dodatkowy element w przypadku nadmiaru
        if (cIn)
            this->module.push_back(1);
    }
    /* odejmowanie */
    void subtract(const natural &x, const natural &y) {
        bool bIn, bOut; //pozyczki na konkretnych pozycjach
        uint32_t temp; //przechowywanie roznicy
        int i; //indeksowanie

        for (i = 0, bIn = false; i < y.module.size(); i++) {
            temp = x.module[i] - y.module[i];
            bOut = (temp > x.module[i]); //sprawdzenie czy uint sie "nie przekrecil"
            if (bIn) {
                bOut |= (temp == 0); // bOut | temp
                temp--;
            }
            this->module.push_back(temp); // zapisanie wyniku
            bIn = bOut; // pozyczka w nastepnej iteracji
        }
        // dalsze pozyczki
        for (; i < x.module.size() && bIn; i++) {
            bIn = (x.module[i] == 0);
            this->module.push_back(x.module[i] - 1);
        }
        if (bIn) {
            this->module.clear();
            std::cout<<"Wynik odejmowania ujemny\n";
        } 
        else //dalsze przepisywanie odjemnej, bez zmian
            for (; i < x.module.size(); i++)
                this->module.push_back(x.module[i]);
    }
	natural multiply(const natural &a, const natural &b){};
};

int main()
{
    std::vector<uint32_t> vect;
    std::vector<uint32_t> beka;
    vect.push_back(1266); 
    vect.push_back(20);
    beka.push_back(1267); 
	natural a(vect);
    natural b(beka);
    natural c;
    c.subtract(a,b);

    a.print();
    b.print();
	c.print();
    if(a == b){
        std::cout<<"rowne \n";
    }

	return 0;
}