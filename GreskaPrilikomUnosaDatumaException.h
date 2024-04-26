#pragma once
#include<exception>
using namespace std;
class GreskaPrilikomUnosaDatumaException:public exception {
	public:
	const char * what() const throw ()
	{
		return "Neispravan datum!";
	}
};
