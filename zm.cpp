#include <iostream>
#include <bitset>
#include <string.h>

struct smNum
{
	bool sign;
	std::bitset<7> module;
};

int main()
{

	smNum a,b,c;
	a.sign = 1;
	b.sign = 0;
	c.sign = 1;

	a.module[0] = 1; a.module[5] = 1;
	b.module.set(); //sets all bits to true
	//std::string str = "1110111";
	std::bitset<7>c_val("1110111");
	c.module = c_val;
	std::cout << "Znak a: " << a.sign << " modul a " << a.module.to_string()<<"\n";
	std::cout << "Znak b: " << b.sign << " modul b " << b.module.to_string()<<"\n";
	std::cout << "Znak c: " << c.sign << " modul c " << c.module.to_string()<<"\n";

	return 0;
}