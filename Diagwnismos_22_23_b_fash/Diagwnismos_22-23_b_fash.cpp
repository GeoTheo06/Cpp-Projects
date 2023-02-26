/* USER: theodoridis_geo35pdp
LANG: C++
TASK: roadfix */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// prosfores{{20 45 10}, {30 75 20}, {40 80 30}, {60 95 5}, {90 100 15}	}
// prosfores{     0,          1,          2,          3,         4		}
// syndiasmoi{{0, 1, 2, 3, 4}, {0, 1, 3, 4}, {0, 2, 3, 4}} einai relative sto prosfores
// arxikoXiliometro: 20
// telikoXiliometro: 100
void bruteForce(vector<vector<int>> prosfores, int arxikoXiliometro, int telikoXiliometro, vector<vector<int>> syndiasmoi, int index, int syndiasmoiCounter)
{
	if ((index == 0 && prosfores[index][0] <= arxikoXiliometro && prosfores[index][1] >= arxikoXiliometro) || (index != 0 /*<- den eimai sigouros an xreaizetai afto*/ && prosfores[index][0] <= prosfores[syndiasmoi[syndiasmoiCounter].back()][1] && prosfores[index][1] > prosfores[syndiasmoi[syndiasmoiCounter].back()][1]))
	{
		// prosfores[syndiasmoi[syndiasmoiCounter].back()][1])) einai to teliko xiliometro ths teleftaias prosforas tou current syndiasmou. Des apo panw sto comment gia na katalaveis to structure

		syndiasmoi[syndiasmoiCounter].push_back(index);
	}

	if (index >= prosfores.size())
	{
		syndiasmoiCounter++;
		return;
	}
	bruteForce(prosfores, arxikoXiliometro, telikoXiliometro, syndiasmoi, index + 1, syndiasmoiCounter);
}

int main()
{
	ifstream in("roadfix.in");
	ofstream out("roadfix.out");

	// initializations

	int arithmosProsforwn, arithmosErwthmatwn, arxikoXiliometroProsforas, mhkosProsforas, kostosProsforas, arxikoXiliometroErwthmatos, mhkosErwthmatos, telikoXiliometroErwthmatos;
	vector<int> temp, dektosSyndiasmos;
	vector<vector<int>> prosfores, erwthmata, syndiasmoi, prosforesConstant;

	// pairnw times

	in >> arithmosProsforwn >> arithmosErwthmatwn;

	/*	prosfores[Arxiko Xiliometro, Teliko Xiliometro, kostos]:
		20 45 10
		30 75 20
		40 80 30
		60 95 5
		90 100 15
	*/
	for (int i = 0; i < arithmosProsforwn; i++)
	{
		in >> arxikoXiliometroProsforas >> mhkosProsforas >> kostosProsforas;
		temp.push_back(arxikoXiliometroProsforas);
		temp.push_back(arxikoXiliometroProsforas + mhkosProsforas);
		temp.push_back(kostosProsforas);
		prosfores.push_back(temp);
		temp.clear();
	}
	sort(prosfores.begin(), prosfores.end());

	/*	erwthmata[Arxiko Xiliometro, Teliko Xiliometro]:
		20 100
		50 80
		10 40
	*/
	for (int i = 0; i < arithmosErwthmatwn; i++)
	{
		in >> arxikoXiliometroErwthmatos >> mhkosErwthmatos;
		temp.push_back(arxikoXiliometroErwthmatos);
		temp.push_back(arxikoXiliometroErwthmatos + mhkosErwthmatos);
		erwthmata.push_back(temp);
		temp.clear();
	}

	// logic

	prosforesConstant = prosfores;
	for (int i = 0; i < arithmosErwthmatwn; i++)
	{
		prosfores = prosforesConstant;
		// gia na xamhlwsw to complexity vriskw apo twra tis prosfores ektos twn oriwn kai tis eksaleifw apo twra.
		for (int k = 0; k < prosfores.size(); k++)
		{
			if (prosfores[k][1] < erwthmata[i][0] || prosfores[k][0] > erwthmata[i][1])
				prosfores.erase(prosfores.begin() + k);
		}
		bruteForce(prosfores, erwthmata[i][0], erwthmata[i][1], syndiasmoi, 0, 0);
	}

	// Print

	return (0);
}