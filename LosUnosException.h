#pragma once
#include<exception>
using namespace std;
class LosUnosException:public exception {
	public:
	const char * what() const throw ()
	{
		return "Los unos!";
	}
};
