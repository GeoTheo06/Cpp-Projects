/* USER: theodoridis_geo35pdp
LANG: C++
TASK: roadfix */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void pithanoiSyndiasmoi(vector<int> &pithanoiSyndiasmoiProsforwn, vector<int> dektosSyndiasmos, int arxikoXiliometroErwthmatos, int telikoXiliometroErwthmatos, vector<int> arxikoXiliometroProsforas, vector<int> telikoXiliometroProsforas, int index)
{
	if (arxikoXiliometroProsforas[index] <= arxikoXiliometroErwthmatos && telikoXiliometroProsforas[index] >= arxikoXiliometroErwthmatos)
	{
		dektosSyndiasmos.push_back(index);
		return;
	}
}

int main()
{
	ifstream in("roadfix.in");
	ofstream out("roadfix.out");
	int prosfores, erwthmata;

	in >> prosfores >> erwthmata;

	// pairnw times
	int *mhkosProsforas = new int[prosfores - 1];
	int *kostosProsforas = new int[prosfores - 1];

	vector<int> arxikoXiliometroProsforas;
	vector<int> telikoXiliometroProsforas;
	int temp1, temp2;
	for (int i = 0; i < prosfores; i++)
	{
		in >> temp1 >> mhkosProsforas[i] >> kostosProsforas[i];
		arxikoXiliometroProsforas.push_back(temp1);
		telikoXiliometroProsforas.push_back(arxikoXiliometroProsforas[i] + mhkosProsforas[i]);
	}

	int *mhkosErwthmatos = new int[erwthmata - 1];
	vector<int> arxikoXiliometroErwthmatos;
	vector<int> telikoXiliometroErwthmatos;
	for (int i = 0; i < erwthmata; i++)
	{
		in >> temp1 >> mhkosErwthmatos[i];
		arxikoXiliometroErwthmatos.push_back(temp1);
		telikoXiliometroErwthmatos.push_back(arxikoXiliometroErwthmatos[i] + mhkosErwthmatos[i]);
	}

	// tha metraei oles tis prosfores pou to mhkos tous periexei to arxiko xiliometro tou erwthmatos
	// vector<int> prosforesPrinToArxikoXiliometroErwthmatos;
	// vector<int> olesOiPithanesProsforesMetaThnPrwth;
	// vector<vector<int>> chain;
	vector<int> pithanoiSyndiasmoiProsforwn;
	vector<int> dektosSyndiasmos;
	// logic
	for (int i = 0; i < erwthmata; i++)
	{
		pithanoiSyndiasmoi(pithanoiSyndiasmoiProsforwn, dektosSyndiasmos, arxikoXiliometroErwthmatos[i], telikoXiliometroErwthmatos[i], arxikoXiliometroProsforas, telikoXiliometroProsforas, 0);

		//*******// KANTO ME RECURSION (backtracking) gia na vreis olous tous pithanous syndiasmous. Meta, des poios einai o pio fthinos //
		// kanto prwta me dfs kai meta dokimase monos sou

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

	delete[] mhkosProsforas, kostosProsforas, mhkosErwthmatos;
	// Print
	return (0);
}