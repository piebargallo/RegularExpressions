#include <iostream>
#include <string>
#include <regex>
#include <format>

int main()
{
	std::regex reg{ "[\\w]+" };
	while (true) {
		std::cout << "Enter a string to split (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q") {
			break;
		}

		const std::sregex_iterator end;
		for (std::sregex_iterator iter{ cbegin(str), cend(str), reg }; iter != end; ++iter) {
			std::cout << format("\"{}\"", (*iter)[0].str()) << std::endl;
		}
	}

	return 0;
}