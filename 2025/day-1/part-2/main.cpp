#include <any>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// right == +
// left == -
//
// currently "num" is being calculated correctly, determining whether zero gets passed
// is not being calculated correctly

int main() {
	std::fstream inputFile("./testinput.txt", std::ios::in);
	if(inputFile.is_open()) {
		std::cout << "file open\n";
	}

	int password = 0;
	int num = 50;
	int lastNum = num;

	std::string op;
	while (std::getline(inputFile, op)) {
		char dir = op[0];
		op.erase(0, 1);

		int amount = std::stoi(op);

		std::cout << "untouched: "<< num << '\n';

		password += amount / 100;
		
		amount %= 100;

		std::cout << dir << " : " << amount << '\n';

		if(dir == 'L') {
			amount = -amount;
		}

		num += amount;

		if (num == 0) {
			password++;
		}

		if(num > 99) {
			num = num % 100;
			std::cout << "wrapped" << '\n';
			password++;
		} else if(num < 0) {
			num = num + 100;
			if(lastNum != 0) {
				std::cout << "wrapped" << '\n';
				password++;
			} else {
				std::cout << "wrapped, no zero added" << '\n';
			}
		}

		std::cout << "after adjustment: "<< num << '\n';

		std::cout << "zeros: " << password << '\n';
		std::cout << "------------" << '\n';

		lastNum = num;
	}

	inputFile.close();
	std::cout << "total zeros: " <<  password << "\n";
	return 0;
}


