#include "container_atd.h"
#include "animal_atd.h"
#include <fstream>

using namespace std;

namespace simple_animals {
	// Container initialization
	void Init(container &c) { c.len = 0; }

	// Container cleaning (free memory)
	void Clear(container &c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	}

	// Signatures of using external functions
	animal *In(ifstream &ifdt);

	// Input container's content from specified source
	void In(container &c, ifstream &ifst) {
		while (!ifst.eof())
		{
			if (c.len > 99)
			{
				break;
			}
			else
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
					c.len++;
			}
		}

	}

	// Signatures of using external functions
	int LenghtName(animal &s);
	void Out(animal &s, ofstream &ofst);
	bool Compare(animal *first, animal *second);

	// Sorting animals by LenghtName
	void Sort(container &c)
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if (Compare(c.cont[i], c.cont[j]))
				{
					animal *tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
				}
			}
		}
	}

	// Output container's content to specified stream
	void Out(container &c, ofstream &ofst)
	{
		ofst << "Container contains " << c.len
			<< " animals." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
		}
		ofst << endl;
	}
} // end simple_animals namespace




