#include <iostream>
#include <bitset>
#include <string.h>

struct smNum
{
	bool sign;
	std::bitset<7> module_repr;
	unsigned long module_val;

	smNum(){
		sign = false;
		module_repr.reset();
		module_val = module_repr.to_ulong();
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
		//dodawanie modulow
		s.module_val = x.module_val + y.module_val;
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

	a.module_repr[0] = 1; a.module_repr[5] = 1;
	a.module_val = a.module_repr.to_ulong();

	b.module_repr.set();
	b.module_val = b.module_repr.to_ulong();

	std::bitset<7>c_val("1110111");
	c.module_repr = c_val;
	c.module_val = c.module_repr.to_ulong();

	smNum s1, s2, s3, r1, r2, r3, m1, m2, m3, q1, q2, q3;

	s1 = add(a,b);
	s2 = add(a,c);
	s3 = add(b,c);

	r1 = sub(a,b);
	r2 = sub(a,c);
	r3 = sub(b,c);

	m1 = mul(a,b);
	m2 = mul(a,c);
	m3 = mul(b,c);

	q1 = div(a,b);
	q2 = div(a,c);
	q3 = div(b,c);

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