#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

// right == +
// left == -

int main() {
	std::fstream inputFile("./input.txt", std::ios::in);
	if(inputFile.is_open()) {
		std::cout << "file open\n";
	}

	std::string op;
	int password = 0;
	int num = 50;
	while (std::getline(inputFile, op)) {
		char dir = op[0];
		op.erase(0, 1);
		int amount = std::stoi(op) % 100;

		std::cout << dir << " : " << amount << '\n';

		switch (dir) {
			case 'L':
				num -= amount;
				break;
			case 'R':
				num += amount;
				break;
		}

//		std::cout << num << '\n';

		if(num > 99) {
			num = num % 100;
		} else if(num < 0) {
			num = num + 100;
		}

		std::cout << num << '\n';

		if (num == 0) {
			password++;
		}
	}

	inputFile.close();
	std::cout << "total zeros: " <<  password << "\n\n";
	return 0;
}


