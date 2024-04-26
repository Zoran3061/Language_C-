#include <iostream>
#include "osoba.h"
void Osoba::setIme(string ime){
	this->ime=ime;
}
void Osoba::setPrezime(string prezime){
	this->prezime=prezime;
}
void Osoba::setPassword(string password){
	this->password=password;
}
void Osoba::setDatumR(string datumR){
	this->datumR=datumR;
}
string Osoba::getIme(){
	return ime;
}
string Osoba::getPrezime(){
	return prezime;
}
string Osoba::getPassword(){
	return password;
}
string Osoba::getDatumR(){
	return datumR;
}
void Student::setIndex(int index){
	this->index=index;
}
void Student::setProsek(float prosek){
	this->prosek=prosek;
}
int Student::getIndex(){
	return index;
}
float Student::getProsek(){
	return prosek;
}
Student::Student(){	
}
Student::Student(int index, string ime, string prezime, string password, string datumR, float prosek){
	this->index=index;
	this->ime=ime;
	this->prezime=prezime;
	this->password=password;
	this->datumR=datumR;
	this->prosek=prosek;
}
void Student::info(){
	cout << "Index: " << index << " \tIme: " << ime << " \tPrezime: " << prezime << " \tDatum rodjenja: " << datumR << " \tProsek: " << prosek << endl;
}

bool Student::operator ==(const Student& s){
	if(index == s.index)
	{
		return true;
	}
	return false;
}
