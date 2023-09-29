#include <iostream>
#include <string>
#include <regex>
#include <format>

int main()
{
	std::regex r{ "//\\s*(.+)$" };
	while (true) {
		std::cout << "Enter a string with optional code comments (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q") {
			break;
		}

		if (std::smatch m; regex_search(str, m, r)) {
			std::cout << std::format("  Found comment '{}'", m[1].str()) << std::endl;
		}
		else {
			std::cout << "  No comment found!" << std::endl;
		}
	}

	return 0;
}

