#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
using namespace std;
// Base class
class Osoba{
	protected:
		string ime;
		string prezime;
		string password;
		string datumR;
	public:
		void setIme(string ime);
		void setPrezime(string prezime);
		void setPassword(string password);
		void setDatumR(string datumR);
		string getIme();
		string getPrezime();
		string getPassword();
		string getDatumR();
		virtual void info()=0;
};
class Student: public Osoba{
	private:
		int index;
		float prosek;
	public:
		void setIndex(int index);
		void setProsek(float prosek);
		int getIndex();
		float getProsek();
		Student();
		Student(int index, string ime, string prezime, string password, string datumR, float prosek);
		void info();
		bool operator ==(const Student& s);
};
#endif
