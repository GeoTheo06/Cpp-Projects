/* USER: theodoridis_geo35pdp
LANG: C++
TASK: roadfix */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream in("roadfix.in");
	ofstream out("roadfix.out");
	int prosfores, erwthmata;

	in >> prosfores >> erwthmata;

	// pairnw times
	int *arxikoXiliometroProsforas = new int[prosfores - 1];
	int *mhkosProsforas = new int[prosfores - 1];
	int *kostosProsforas = new int[prosfores - 1];

	int *telikoXiliometroProsforas = new int[prosfores - 1];

	for (int i = 0; i < prosfores; i++)
	{
		in >> arxikoXiliometroProsforas[i] >> mhkosProsforas[i] >> kostosProsforas[i];
		telikoXiliometroProsforas[i] = arxikoXiliometroProsforas[i] + mhkosProsforas[i];
	}

	int *arxikoXiliometroErwthmatos = new int[erwthmata - 1];
	int *mhkosErwthmatos = new int[erwthmata - 1];

	int *telikoXiliometroErwthmatos = new int[erwthmata - 1];

	for (int i = 0; i < erwthmata; i++)
	{
		in >> arxikoXiliometroErwthmatos[i] >> mhkosErwthmatos[i];
		telikoXiliometroErwthmatos[i] = arxikoXiliometroErwthmatos[i] + mhkosErwthmatos[i];
	}

	// tha metraei oles tis prosfores pou to mhkos tous periexei to arxiko xiliometro tou erwthmatos
	vector<int> prosforesPrinToArxikoXiliometroErwthmatos;

	// logic
	for (int i = 0; i < erwthmata; i++)
	{
		// vriskw oles tis prosfores twn opoiwn to mhkos periexei to arxiko xiliometro tou erwthmatos kai apothikevw ton arithmo ths prosforas sto prosforesPrinToArxikoXiliometroErwthmatos
		for (int k = 0; k < prosfores; k++)
		{
			if (arxikoXiliometroProsforas[k] <= arxikoXiliometroErwthmatos[i] && telikoXiliometroProsforas[k] >= arxikoXiliometroErwthmatos[i])
				prosforesPrinToArxikoXiliometroErwthmatos.push_back(k);
		}

		// continue from here (here goes the rest of the logic)
	}

	delete[] arxikoXiliometroProsforas, mhkosProsforas, kostosProsforas, telikoXiliometroProsforas, arxikoXiliometroErwthmatos, mhkosErwthmatos;
	// Print
	return (0);
}