#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <vector>

/*
	* finish wrting the splitIDs function, use strtok to 
	* split the string into pieces, i think 2 while loops are needed
*/
std::vector<char*> allID;

void splitIDs(char* fullID) {

}


int main() {
	FILE* input = fopen("input.txt", "r");
	if(input == NULL) {
		std::cout << "FILE DID NOT OPEN OH NOEEE\n";
		return 1;
	}

	char fullID[1024];
	if(std::fgets(fullID, sizeof(fullID), input) == NULL) {
		std::cout << "failed to read input ruh roh\n";
	}

	splitIDs(fullID);

	return 0;
}
