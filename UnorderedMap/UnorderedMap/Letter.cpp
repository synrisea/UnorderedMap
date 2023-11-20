#include <iostream>
#include <unordered_map>
#include <string>

bool stringComposing(std::string randomLetter, std::string paper)
{
	std::unordered_map<char, int> randomLetterFreqs;
	std::unordered_map<char, int> paperFreqs;


	for (const char& c : randomLetter)
	{
		randomLetterFreqs[tolower(c)]++;
	}

	for (const char& c : paper)
	{
		paperFreqs[tolower(c)]++;
	}


	for (const auto& [symbol, freq] : randomLetterFreqs)
	{
		if (paperFreqs[symbol] < freq)
		{
			return false;
		}
	}

	return true;
}


int main()
{
	std::string randomLetter;
	std::string paper;

	std::cout << "Enter the blackmailer's letter : ";
	std::cin >> randomLetter;

	std::cout << "Enter the text of the newspaper from which the letters are cut : ";
	std::cin >> paper;

	std::cout << "\n\n";

	std::cout << "randomLetter = \"" << randomLetter << "\", paper = \"" << paper << "\" - ";

	if (stringComposing(randomLetter, paper)) 
	{
		std::cout << "TRUE\n";
	}
	else 
	{
		std::cout << "FALSE\n";
	}
}
