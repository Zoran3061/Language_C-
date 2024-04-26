#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "osoba.h"
#include "LosUnosException.h"
#include "IDiliIndexVecPostojiException.h"
#include "GreskaPrilikomUnosaDatumaException.h"

using namespace std;

vector<Student> studenti;
void ucitajStudente(vector<Student>& studenti);
void pocetniEkran();
void studentScreen();
void listajStudente();
void ubaciStudenta();
void obrisiStudenta();
void izmeniStudenta();
void sacuvajStudente();

int main(int argc, char** argv) {
ucitajStudente(studenti);
pocetniEkran();
return 0;
}
void ucitajStudente(vector<Student>& studenti){
studenti.clear();
ifstream infile("studenti.txt");
string line;
Student privremeni;	
while(getline(infile, line))
{
privremeni.setIndex(atoi(line.c_str()));
getline(infile, line);
privremeni.setIme(line);
getline(infile, line);
privremeni.setPrezime(line);
getline(infile, line);
privremeni.setPassword(line);
getline(infile, line);
privremeni.setDatumR(line);
getline(infile, line);
privremeni.setProsek(atof(line.c_str()));
studenti.insert(studenti.end(), privremeni);
}
infile.close();
}
void pocetniEkran(){
int izbor, id, index;
string username, password;
cout <<"\t\t\t\t\t\t Dobrodosli\n\n\n\n1)Elektronski Dnevnik\n2)Izlaz\n\nUnos:";
cin >> izbor;
try {
if (izbor!=1 && izbor!=2)
	throw LosUnosException();
if(izbor==1)
{
	studentScreen();
	}
}
catch (LosUnosException& e)
{
system("cls");
cout << e.what() << endl;
pocetniEkran();
}
}
void listajStudente(){
vector<Student>::iterator studentiIterator;
for(studentiIterator = studenti.begin(); studentiIterator != studenti.end(); studentiIterator++)
{
	(*studentiIterator).info();
}
}
void ubaciStudenta(){
int index, pom=0, dan, mesec, godina;
float prosek;
string ime, prezime, password, datumR, izbor;
ostringstream temp;
vector<Student>::iterator studentiIterator;
cout << "Unesite broj indeksa novog studenta: ";
cin >> index;
try{
for(studentiIterator = studenti.begin(); studentiIterator != studenti.end(); studentiIterator++)
{
if((*studentiIterator).getIndex()==index)
{
	throw IDiliIndexVecPostojiException();
}
}
cout << "Unesite password novog studenta: ";
cin >> password;
cout << "Unesite ime novog studenta: ";
cin >> ime;
cout << "Unesite prezime novog studenta: ";
cin >> prezime;
cout << "Unesite dan rodjenja novog studenta: ";
cin >> dan;
cout << "Unesite mesec rodjenja novog studenta: ";
cin >> mesec;
cout << "Unesite godinu rodjenja novog studenta: ";
cin >> godina;
if(dan<1 || dan>31)
	throw GreskaPrilikomUnosaDatumaException();
if(mesec<1 || mesec>12)
	throw GreskaPrilikomUnosaDatumaException();
if(godina<1900 || godina>2000)
	throw GreskaPrilikomUnosaDatumaException();
temp<<dan;
datumR=temp.str()+".";
temp.str("");
temp<<mesec;
datumR+=temp.str()+".";
temp.str("");
temp<<godina;
datumR+=temp.str();
cout << "Unesite prosek novog studenta: ";
cin >> prosek;
Student privremeni(index, ime, prezime, password, datumR, prosek);
privremeni.info();
studenti.insert(studenti.end(), privremeni);
sacuvajStudente();
cout << "Student uspesno ubacen!" << endl;
system("pause");
studentScreen();
}
catch (GreskaPrilikomUnosaDatumaException& e)
{
	system("cls");
	cout << e.what() << endl;
	ubaciStudenta();
}
catch (IDiliIndexVecPostojiException& e)
{
	system("cls");
	cout << e.what() << endl;
	ubaciStudenta();
}
catch (LosUnosException& e)
{
	system("cls");
	cout << e.what() << endl;
	studentScreen();
}
}
void obrisiStudenta(){
int index, pom=0;
string izbor;
listajStudente();
cout << "\nUnesite broj indeksa koga zelite da obrisete: ";
cin >> index;
try{
for(int i = 0; i < studenti.size(); i++)
{
if(studenti.at(i).getIndex()==index)
{
	studenti.erase(studenti.begin()+i);
	pom++;
}
}
if(pom==0)
throw LosUnosException();
sacuvajStudente();
cout << "Student uspesno obrisan!" << endl;
system("pause");
studentScreen();
}
catch (LosUnosException& e)
{
	system("cls");
	cout << e.what() << endl;
	obrisiStudenta();
}
}
void izmeniStudenta(){
int index, it, pom=0, dan, mesec, godina;
float prosek;
string izbor, ime, prezime, datumR, password;
listajStudente();
ostringstream temp;
cout << "\nUnesite index studenta koga zelite da izmenite: ";
cin >> index;
try{
for(int i = 0; i < studenti.size(); i++)
{
if(studenti.at(i).getIndex()==index)
{
	it=i;
	pom++;
}
}
if(pom!=0){
cout << "Unesite index: ";
cin >> index;
for(int i = 0; i<studenti.size();i++)
{
if(studenti.at(i).getIndex()==index && i!=it)
{
	throw IDiliIndexVecPostojiException();
}
}
cout << "Unesite password: ";
cin >> password;
cout << "Unesite ime: ";
cin >> ime;
cout << "Unesit prezime: ";
cin >> prezime;
cout << "Unesite dan rodjenja: ";
cin >> dan;
cout << "Unesite mesec rodjenja: ";
cin >> mesec;
cout << "Unesite godinu rodjenja: ";
cin >> godina;
if(dan<1 || dan>31)
	throw GreskaPrilikomUnosaDatumaException();
if(mesec<1 || mesec>12)
	throw GreskaPrilikomUnosaDatumaException();
if(godina<1900 || godina>2000)
	throw GreskaPrilikomUnosaDatumaException();
temp<<dan;
datumR=temp.str()+".";
temp.str("");
temp<<mesec;
datumR+=temp.str()+".";
temp.str("");
temp<<godina;
datumR+=temp.str();
cout << "Unesite prosek: ";
cin >> prosek;
Student privremeni(index, ime, prezime, password, datumR, prosek);
privremeni.info();
studenti.erase(studenti.begin()+it);
studenti.insert(studenti.begin() + it, privremeni);
sacuvajStudente();
cout << "Student uspesno promenjen!" << endl;
system("pause");
studentScreen();
}
else{
	throw LosUnosException();
}
}
catch (IDiliIndexVecPostojiException& e)
{
	system("cls");
	cout << e.what() << endl;
	cout << endl << endl;
	izmeniStudenta();
}
catch (LosUnosException& e)
{
	system("cls");
	cout << e.what() << endl;
	izmeniStudenta();
}
}
void sacuvajStudente(){
ofstream myfile;
myfile.open("studenti.txt");
vector<Student>::iterator studentiIterator;
for(studentiIterator = studenti.begin(); studentiIterator != studenti.end(); studentiIterator++)
{
  	myfile << (*studentiIterator).getIndex() << endl;
  	myfile << (*studentiIterator).getIme() << endl;
  	myfile << (*studentiIterator).getPrezime() << endl;
  	myfile << (*studentiIterator).getPassword() << endl;
  	myfile << (*studentiIterator).getDatumR() << endl;
  	myfile << (*studentiIterator).getProsek() << endl;
}
myfile.close();
}
void studentScreen(){
system("cls");
int in, izbor;
string izbor2, npass;
for(int i = 0; i<studenti.size(); i++){
}
cout << "Dobro dosao\n" << endl;
cout << "1)Izlistaj sve Studente\n2)Ubaci novog studenta\n3)Obrisi studenta\n4)Izmeni studenta\n5)Izadji iz dnevnika\n\nUnos:";
cin >> izbor;
try {
if (izbor!=1 && izbor!=2 && izbor!=3 && izbor!=4 && izbor!=5)
throw LosUnosException();
	if(izbor==1)	
{
	listajStudente();
	system("pause");
	studentScreen();
}
if(izbor==2)
{
	ubaciStudenta();
}
if(izbor==3)
{
	obrisiStudenta();
}
if(izbor==4){
	izmeniStudenta();
}
if(izbor==5)
{
	system("cls");
	pocetniEkran();
}
}
catch (LosUnosException& e) {
	cout << e.what() << endl;
}
}
