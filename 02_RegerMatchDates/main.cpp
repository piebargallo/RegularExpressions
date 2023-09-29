#include <iostream>
#include <string>
#include <regex>
#include <format>

int main()
{
	std::regex r{ "(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])" };
	while (true) {
		std::cout << "Enter a date (year/month/day) (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q") {
			break;
		}

		if (std::smatch m; regex_match(str, m, r)) {
			int year{ stoi(m[1]) };
			int month{ stoi(m[2]) };
			int day{ stoi(m[3]) };
			std::cout << std::format("  Valid date: Year={}, month={}, day={}", year, month, day) << std::endl;
		}
		else {
			std::cout << "  Invalid date!" << std::endl;
		}
	}

	return 0;
}