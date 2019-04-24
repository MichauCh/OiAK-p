#include <iostream>
#include <vector>
#include <string.h>
#include <cstdint>

class natural{
	std::vector<uint32_t> module;

	/* Konstruktor kopiujacy */
	natural(const natural &a) : module(a.module) {}
	/* operator przypisania */
	void operator=(const natural &x) {
		NumberlikeArray<Blk>::operator =(x);
	}
};

struct smNum
{
	bool sign;
	std::vector<uint32_t> module;

/* Konstruktor bezargumentowy */
	smNum(){
		sign = false;
		std::cout<<"Empty number \n";
	}
/* Konstruktor sam modul */
	smNum(vector<int> a){
		sign = false;
		while (a.size() > 1 && a.back() == 0)
		module.push_back();
	}
/* Konstruktor kopiujacy */
	smNum(const smNum &b)
        : sign(b.sign),
          module(b.module){ }

/* Konstruktor z konwersja z typu long long */
	smNum::smNum(long long value)
	{
		if (value < 0) {
			sign = true;
			module.push_back(0);
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
		std::string value = std::to_string(module_val);
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

smNum add(smNum x, smNum y){
	smNum s;
	if(x.sign == y.sign){ //znaki zgodne
		s.sign = x.sign;
		//int lenght = maxVal(x.module.size(),y.module.size())
		//dodawanie modulow
		//for(int i=0; i<lenght; i++)
		//s.module[i]=x.module[i]+y.module[i]
	}
	else{ //znaki niezgodne
		if(x.module_val >= y.module_val){
			s.sign = x.sign;
			s.module_val = x.module_val - y.module_val;
		}
		else
		{	
			s.sign = y.sign;
			s.module_val = y.module_val - x.module_val;
		}
	}
	return s;
}
smNum sub(smNum x, smNum y){
	smNum r;
	if(x.sign == y.sign){ //znaki zgodne
		if(x.module_val >= y.module_val){
			r.sign = x.sign;
			r.module_val = x.module_val - y.module_val;
		}
		else
		{	
			r.sign = !(x.sign);
			r.module_val = y.module_val - x.module_val;
		}
	}
	else{ //znaki niezgodne
		r.sign = x.sign;
		if(x.sign == 0){
			r.module_val = x.module_val + y.module_val;
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

	m.module_val = x.module_val * y.module_val;
	return m;
}
smNum div(smNum x, smNum y){
	smNum q;
	if(x.sign==y.sign)
		q.sign = 0;
	else
		q.sign = 1;

	q.module_val = x.module_val / y.module_val;
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