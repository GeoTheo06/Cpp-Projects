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
	vector<int> olesOiPithanesProsforesMetaThnPrwth;
	vector<vector<int>> chain;

	// logic
	for (int i = 0; i < erwthmata; i++)
	{


//*******// KANTO ME RECURSION (backtrack) gia na vreis olous tous pithanous syndiasmous. Meta, des poios einai o pio fthinos //





		// // vriskw oles tis prosfores twn opoiwn to mhkos periexei to arxiko xiliometro tou erwthmatos kai apothikevw ton arithmo ths prosforas sto prosforesPrinToArxikoXiliometroErwthmatos
		// for (int k = 0; k < prosfores; k++)
		// {
		// 	if (arxikoXiliometroProsforas[k] <= arxikoXiliometroErwthmatos[i] && telikoXiliometroProsforas[k] >= arxikoXiliometroErwthmatos[i])
		// 	{
		// 		prosforesPrinToArxikoXiliometroErwthmatos.push_back(k);
		// 	}
		// 	else if (arxikoXiliometroProsforas[k] > telikoXiliometroErwthmatos[i])
		// 	{
		// 		olesOiPithanesProsforesMetaThnPrwth.push_back(k);
		// 	}
		// }
		// chain.push_back(prosforesPrinToArxikoXiliometroErwthmatos);

		// // prosfores prin to arxiko xiliometro erwthmatos counter
		// // int ptaxeCounter = 0;
		// // edw tha vrw olous tous syndyasmous pou mporoun na ginoun ksekinontas apo tis prosfores pou periexontai sto prosforesPrinToArxikoXiliometroErwthmatos
		// for (int k = 0; k < prosforesPrinToArxikoXiliometroErwthmatos.size(); k++)
		// {
		// 	for (int l = 0; l < olesOiPithanesProsforesMetaThnPrwth.size(); l++)
		// 	{
		// 		if (arxikoXiliometroProsforas[olesOiPithanesProsforesMetaThnPrwth[l]] <= telikoXiliometroProsforas[prosforesPrinToArxikoXiliometroErwthmatos[k]] && telikoXiliometroProsforas[olesOiPithanesProsforesMetaThnPrwth[l]] > telikoXiliometroProsforas[prosforesPrinToArxikoXiliometroErwthmatos[k]])
		// 		{
		// 			chain.push_back(prosforesPrinToArxikoXiliometroErwthmatos)
		// 		}
		// 	}
		// }
		// prosforesPrinToArxikoXiliometroErwthmatos.clear();
		// olesOiPithanesProsforesMetaThnPrwth.clear();
	}

	delete[] arxikoXiliometroProsforas, mhkosProsforas, kostosProsforas, telikoXiliometroProsforas, arxikoXiliometroErwthmatos, mhkosErwthmatos;
	// Print
	return (0);
}