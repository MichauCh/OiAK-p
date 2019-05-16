#include <iostream>
#include <vector>

class natural{
private:
	std::vector<uint32_t> module;
    
public:
    /* Konstruktor bezargumentowy */
    natural(){
    }
    /* Konstruktor kopiujacy, z uinta */
	natural(const  uint32_t a){
        this->module.push_back(a);
    }
    /* Konstruktor kopiujacy, z vectora */
	natural(const  std::vector<uint32_t> &a){
        this->module = a;
    }
	/* Konstruktor kopiujacy, z natural */
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
        for (; i < this->module.size() && cIn; i++) {
            this->module[i]++;
            cIn = (this->module[i] == 0);
        }
        if (cIn) {
            this->module.push_back(1);
        }
    }
    /* operator dekrementacji */
    void operator --() {
        if (this->module.size()==0)
            std::cout<<"Niezainicjalizowana liczba";
        int i=0;
        bool bIn = true;
        for (; bIn; i++) {
            bIn = (this->module[i] == 0);
            this->module[i]--;
        }
    }

    /* operator porownania, wiekszy */
    bool operator >(const natural &x) const {
        if (this->module.size() > x.module.size())
            return true;
        else if(this->module.size() < x.module.size())
            return false;
        else{ //argumenty tej samej dlugosci
            // porownywanie kolejnych elementow od lewej (tych o wyzszej wadze)
            for (int i = this->module.size()-1; i >= 0; i--)
                if (this->module[i] > x.module[i])
                    return true;
            return false;
        }
    }
    /* operator porownania, wiekszy/rowny */
    bool operator >=(const natural &x) const {
        unsigned int counter=0; //licznik rownych elementow
        if (this->module.size() > x.module.size())
            return true;
        else if(this->module.size() < x.module.size())
            return false;
        else{ //argumenty tej samej dlugosci
            // sprawdzenie czy jest wiekszy
            for (unsigned int i = this->module.size()-1; i >= 0; i--){
                if (this->module[i] > x.module[i])
                    return true;
                else if(this->module[i] == x.module[i]) //sprawdzenie czy rowne
                    counter++;
            }
            if(counter == this->module.size()) //wszystkie elementy sa rowne
                return true;
            else
                return false;
        }
    }
    /* wypisywanie wartosci */
    void print() { 
    for (int i=module.size()-1; i>=0; i--) 
       std::cout << module[i] << " ";
    std::cout<<"\n";
    }
    // /* usuwanie wiodacego zera */
    // void eraseLeadingZeroIfExists() {
    //     if(this->module.size()-1 == 0) //jesli elementem o najwyzszej wadze jest 0
    //         this->module.pop_back; //trzeba je usunac, zaburza wykonanie porownania
    // }

    /* operacje arytmetyczne */
    /* dodawanie */
    void add(const natural &x, const natural &y) {
        bool cIn, cOut; //przeniesienia na konkretnych pozycjach
        uint32_t temp; //przechowywanie sumy
        int i=0; //indeksowanie

        const natural *shorterArg, *longerArg; //zmienne na krotszy i dluzszy argument
        if (x.module.size() >= y.module.size()) { //rownej dlugosci lub x dluzszy od y
            longerArg = &x;
            shorterArg = &y;
        } else { //y dluzszy od x
            longerArg = &y;
            shorterArg = &x;
        }
        // dla kazdego elementu w zasiegu krotszego argumentu
        for (cIn = false; i < shorterArg->module.size(); i++) {
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
        int i=0; //indeksowanie

        for (bIn = false; i < y.module.size(); i++) {
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
    /* mnozenie */
    void multiply(const natural &x, const natural &y){
        int cIn = 0;
        int cOut = 0;
        uint32_t temp=0;
        std::vector<uint32_t> tempMod;
        natural tempVec;
        natural tempNat;
        int longerArg = 0;
        if(x.module.size()>=y.module.size())
            longerArg = x.module.size();
        else longerArg = y.module.size();
 
       unsigned long long longtemp;
       for (int i = 0; i<x.module.size(); i++) {
                for(int k = 0; k<i ;k++) {
                    tempVec.module.insert(tempVec.module.begin(), 0);
                    }
            for (int j = 0; j<y.module.size(); j++) {
                longtemp = x.module[i] * y.module[j] + cIn;
                temp = longtemp;
                tempVec.module.insert(tempVec.module.begin()+i+j, temp);
                if (temp == longtemp) {
                    cIn = 0;
                    } else {
                   cIn = longtemp/4294967295;
                    }
                    temp = 0;
 
            }
            tempMod = this->module;
            tempNat.module=tempMod;
            this->module.clear();
            this->add(tempNat, tempVec);
            tempVec.module.clear();
            tempMod.clear();
        }
    }
 
 // prymitywny algorytm dzielenia
    void divide(const natural &x, const natural &y) {
        natural divident(x); //kopia do dzialan dzielnej
        natural quotient(0); //przechowywanie ilorazu, quotient
        natural temp;

        while(divident.operator>(y)){ //powinno byc >= ale samo > to mniej operacji
            temp.subtract(divident, y);
            divident.module = temp.module; //kopiowanie wartosci
            divident.print();
            temp.module.clear(); //zwalnianie pamieci z temp
            quotient.operator++();
            //divident.eraseLeadingZeroIfExists();
        }
        if(divident.operator==(y)){ //ostatnie porownanie
            temp.subtract(divident, y);
            divident.module = temp.module; //kopiowanie wartosci
            temp.module.clear(); //zwalnianie pamieci z temp
            quotient.operator++();
        }
        this->module = quotient.module;
        temp.module.clear(); //zwalnianie pamieci z temp
        divident.module.clear();
    }


};

int main()
{
    std::vector<uint32_t> vect;
    std::vector<uint32_t> vect2;
    vect.push_back(55); 
    vect.push_back(1);
    vect2.push_back(16); 
    vect2.push_back(1);
    natural a(vect);
    natural b(vect2);
    natural c,d;
    //c.divide(a,b);
    d.multiply(a,b);
    d.print();

    if(a >= b)
        std::cout<<"a >= b\n";

	return 0;
}