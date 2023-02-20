/* USER: theodoridis_geo35pdp
LANG: C++
TASK: coupon */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream in("roadfix.in");
	ofstream out("roadfix.out");
	int prosfores, erwthmata;

	in >> prosfores >> erwthmata;
	int *arxikoXiliometroProsforas = new int[prosfores - 1];
	int *mhkosProsforas = new int[prosfores - 1];
	int *kostosProsforas = new int[prosfores - 1];

	for (int i = 0; i < prosfores; i++)
	{
		in >> arxikoXiliometroProsforas[i] >> mhkosProsforas[i] >> kostosProsforas[i];
	}

	int *arxikoXiliometroErwthmatos = new int[erwthmata - 1];
	int *mhkosErwthmatos = new int[erwthmata - 1];
	for (int i = 0; i < erwthmata; i++)
	{
		in >> arxikoXiliometroErwthmatos[i] >> mhkosErwthmatos[i];
	}

	for (int i = 0; i < prosfores; i++)
	{
		cout << arxikoXiliometroProsforas[i] << " " << mhkosProsforas[i] << " " << kostosProsforas[i] << endl;
	}

	for (int i = 0; i < erwthmata; i++)
	{
		cout << arxikoXiliometroErwthmatos[i] << " " << mhkosErwthmatos[i] << endl;
	}
	return (0);
}