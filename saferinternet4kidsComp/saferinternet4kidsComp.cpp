#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string encryptedMessage = "nhi loa mv abv ahj loa als vA }y3ow1j{zkpr4pz";
	vector<char> reversedMessage;
	for(int i = encryptedMessage.length() - 1; i >= 0; i--)
	{
		reversedMessage.push_back(encryptedMessage[i]);
	}

	for(int i = 0; i < reversedMessage.size() - 1; i++)
	{
		if(reversedMessage[i] - 0 >= 97 && reversedMessage[i] - 0 <= 126 && reversedMessage[i] - 0 != 123 && reversedMessage[i] - 0 != 125) //123 and 125 are {, } in ascii
			cout << static_cast<char>(reversedMessage[i] - 7);
		else
			cout << reversedMessage[i];
	}
	//don't care what the rest are. Only want the flag
}
