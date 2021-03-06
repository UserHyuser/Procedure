#include <fstream>
#include "animal_atd.h"

using namespace std;

namespace simple_animals {
	// Signatures of using external functions 
	void In(bird &r, ifstream &ist);
	void In(fish  &t, ifstream &ist);
	void In(beast &b, ifstream &ist);
	int LenghtName(bird &r, char name[20]);
	int LenghtName(fish &t, char name[20]);
	int LenghtName(beast &b, char name[20]);

	// Input parameters of generalized animal from file
	animal* In(ifstream &ifst)
	{
		animal *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new animal;
			sp->k = animal::key::BIRD;
			In(sp->r, ifst);
			ifst >> sp->name;
			ifst >> sp->age;
			return sp;
		case 2:
			sp = new animal;
			sp->k = animal::key::FISH;
			In(sp->t, ifst);
			ifst >> sp->name;
			ifst >> sp->age;
			return sp;
		case 3:
			sp = new animal;
			sp->k = animal::key::BEAST;
			In(sp->b, ifst);
			ifst >> sp->name;
			ifst >> sp->age;
			return sp;
		default:
			return 0;
		}
	}


	int LenghtName(animal &s) {
		int arrayLength = 0;
		for (int i = 0; s.name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}

	// Signatures of using external functions
	void Out(bird &r, char name[20], int age, ofstream &ofst);
	void Out(fish  &t, char name[20], int age, ofstream &ofst);
	void Out(beast &b, char name[20], int age, ofstream &ofst);

	// Output parameters of generalized animal to file
	void Out(animal &s, ofstream &ofst) {
		switch (s.k) {
		case animal::key::BIRD:
			Out(s.r, s.name, s.age, ofst);
			ofst << "Name's lenght: " << LenghtName(s.r, s.name) << endl;
			break;
		case animal::key::FISH:
			Out(s.t, s.name, s.age, ofst);
			ofst << "Name's lenght: " << LenghtName(s.t, s.name) << endl;
			break;
		case animal::key::BEAST:
			Out(s.b, s.name, s.age, ofst);
			ofst << "Name's lenght: " << LenghtName(s.b, s.name) << endl;
			break;
		default:
			ofst << "Incorrect animal!" << endl;
		}
	}
} // end simple_animals namespace

