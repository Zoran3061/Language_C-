#pragma once
#include<exception>
using namespace std;
class IDiliIndexVecPostojiException:public exception {
	public:
	const char * what() const throw ()
	{
		return "Uneti ID ili index vec postoji!";
	}
};
