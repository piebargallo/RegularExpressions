#include <iostream>
#include <string>
#include <regex>
#include <format>

int main()
{
	std::regex reg{ R"(\s*[,;]\s*)" };
	while (true) {
		std::cout << "Enter a string to split on ',' and ';' (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q") {
			break;
		}

		const std::sregex_token_iterator end;
		for (std::sregex_token_iterator iter{ cbegin(str), cend(str), reg, -1 };
			iter != end; ++iter) {
			std::cout << format("\"{}\"", iter->str()) << std::endl;
		}
	}

	return 0;
}