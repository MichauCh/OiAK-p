#include "natural.cpp"

class smNum
{
	bool sign; //false +, true -
	natural module; //modul reprezentowany przez liczbe naturalna

/* Konstruktor bezargumentowy */
	smNum()
        : sign(false),
          module(){ }
/* Konstruktor sam modul */
	smNum(const std::vector<int> a){
		sign = false;
		while (a.size() > 1 && a.back() == 0)
		module(a);
	}
/* Konstruktor sam modul */
	smNum(bool si, const std::vector<int> a){
		sign = si;
		while (a.size() > 1 && a.back() == 0)
		module(a);
	}
/* Konstruktor kopiujacy */
	smNum(const smNum &b)
        : sign(b.sign),
          module(b.module){ }

/* Konstruktor kopiujacy */
	smNum(const natural &n)
        : sign(false),
          module(n){ }

/* Konstruktor z konwersja z typu long long */
	smNum::smNum(long long value)
	{
		if (value < 0) {
			sign = true;
			module(0);
		} else {
			sign = false;
		}

		while (value) {
			module.push_back((uint32_t)(value));
		}
	}
	smNum(){
		sign = false;
		module.push_back()
	}

	std::string toString_decimal(){
		std::string value = std::to_string(module);
		if(sign==0){
			std::string str("+ ");
			return str  + value;
		}
		else{
			std::string str("- ");
			return str  + value;
		}
	}
};
	/* operacje arytmetyczne */
    /* dodawanie */
	smNum add(smNum x, smNum y){
		smNum s;
		if(x.sign == y.sign){ //znaki zgodne
			s.sign = x.sign;
			s.module.add(x.module,y.module);
		}
		else{ //znaki niezgodne
			if(x.module >= y.module){
				s.sign = x.sign;
				s.module.subtract(x.module,y.module);
			}
			else
			{	
				s.sign = y.sign;
				s.module.subtract(y.module,x.module);
			}
		}
		return s;
	}
	/* odejmowanie */
	smNum sub(smNum x, smNum y){
		smNum r;
		if(x.sign == y.sign){ //znaki zgodne
			if(x.module_val >= y.module_val){
				r.sign = x.sign;
				r.module.subtract(x.module,y.module);
			}
			else
			{	
				r.sign = !(x.sign);
				r.module.subtract(y.module,x.module);
			}
		}
		else{ //znaki niezgodne
			r.sign = x.sign;
			if(x.sign == 0){
				r.module_val = x.module_val + y.module_val; //co tu nie gra
			}
			else
			{	
				r.module_val = x.module_val + y.module_val;
			}
		}
		return r;

	}
smNum mul(smNum x, smNum y){
	smNum m;
	if(x.sign==y.sign)
		m.sign = 0;
	else
		m.sign = 1;

	m.module.multiply(x,y);;
	return m;
}
smNum div(smNum x, smNum y){
	smNum q;
	if(x.sign==y.sign)
		q.sign = 0;
	else
		q.sign = 1;

	q.module.divide(x.module,y.module);
	return q;
}

int main()
{

	smNum a,b,c;
	a.sign = 1;
	b.sign = 0;
	c.sign = 1;

	smNum s1;

	s1 = add(a,b);


	std::cout<<"---------------dodawanie---------------\n";
	std::cout<<"w 10 to "<< s1.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< s2.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< s3.toString_decimal()<<"\n";
	std::cout<<"---------------odejmowanie-------------\n";
	std::cout<<"w 10 to "<< r1.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< r2.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< r3.toString_decimal()<<"\n";
	std::cout<<"---------------mnozenie----------------\n";
	std::cout<<"w 10 to "<< m1.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< m2.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< m3.toString_decimal()<<"\n";
	std::cout<<"---------------dzielenie---------------\n";
	std::cout<<"w 10 to "<< q1.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< q2.toString_decimal()<<"\n";
	std::cout<<"w 10 to "<< q3.toString_decimal()<<"\n";

	return 0;
}