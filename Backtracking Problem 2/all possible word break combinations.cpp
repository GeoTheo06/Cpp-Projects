/*Given a string s and a dictionary of words wordDict, find all possible word break combinations of s.
Example:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[  "cats and dog",  "cat sand dog"]
*/

#include <iostream>
#include <vector>

using namespace std;

void findPossibilities(string s, vector<string> wordDict, string solution, vector<string> combination, int index)
{
	// If there are words in the combination, concatenate them into a string
	if (combination.size() > 0)
	{
		for (int i = 0; i < combination.size(); i++)
		{
			solution += combination[i];
		}
		// Check if the concatenated string matches the original string
		for (int i = 0; i < solution.length(); i++)
		{
			if (solution[i] != s[i])
				return;
		}
	}
	// If the concatenated string matches the original string, print the combination and return
	if (solution == s)
	{
		for (int i = 0; i < combination.size(); i++)
		{
			cout << combination[i] << " ";
		}
		cout << endl;
		return;
	}
	// If we have tried all the words in the dictionary, return
	if (index >= wordDict.size())
	{
		return;
	}
	// Try adding the current word to the combination
	combination.push_back(wordDict[index]);
	findPossibilities(s, wordDict, "", combination, index + 1);
	// Backtrack by removing the current word from the combination and trying the next word
	combination.pop_back();
	findPossibilities(s, wordDict, "", combination, index + 1);
}

int main()
{
	string s;
	cout << "type the string without spaces: ";
	cin >> s;
	string solution;
	vector<string> wordDict;
	vector<string> combination;
	string input;
	cout << "type the words in the dictionary (example: cat , cats, and, sand, dog) | Type stop to stop:" << endl;
	do
	{
		cin >> input;
		if (input != "stop")
			wordDict.push_back(input);
	} while (input != "stop");
	cout << "Output:" << endl;
	findPossibilities(s, wordDict, solution, combination, 0);
}