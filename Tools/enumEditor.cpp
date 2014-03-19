#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string FILEPATH = "../Enums.h";

std::string HEADER =
"#ifndef ENUMS_H\n" 
"#define ENUMS_H\n\n";
 
 std::string FOOTER =
 "\n#endif"
 ;
 

struct EnumType {
	std::string enumName;
	std::vector<std::string> enumValues;
};

std::vector<EnumType*> currentEnums;

void defineNewEnum(){
	EnumType* newEnum = new EnumType;
	std::cout << "Enter new enum name: ";
	std::cin >> newEnum->enumName;
	
	std::string decision = "";
	std::cout << "Would you like to add a new value to enum " << newEnum->enumName << "?: ";
	std::cin >> decision;
	while(decision != "n" && decision != "N"){
		std::cout << "Enter Value: ";
		std::string newValue;
		std::cin >> newValue;
		newEnum->enumValues.push_back(newValue);
		
		std::cout << "Would you like to add a new value to enum " << newEnum->enumName << "? (n|N  y|Y): ";
		std::cin >> decision;
	}
	
	currentEnums.push_back(newEnum);
}

void saveEnums(std::ofstream* outputFile){
	for(unsigned i = 0; i < currentEnums.size(); i++){
	
		*outputFile << "enum " << currentEnums[i]->enumName << "{";
		
		for(unsigned j = 0; j < currentEnums[i]->enumValues.size()-1; j++){
			*outputFile << currentEnums[i]->enumValues[j] << ",";
		}
		if(currentEnums[i]->enumValues.size() > 1){
			*outputFile <<  currentEnums[i]->enumValues[currentEnums[i]->enumValues.size()-1] << "};";
		}
	}
}

void freeMemory(){
	for(unsigned i = 0; i < currentEnums.size(); i++){
		EnumType* tmp = currentEnums[i];
		currentEnums[i] = NULL;
		delete tmp;
	}
}

int main(){
	std::ofstream outputFile;
	outputFile.open(FILEPATH);
	
	outputFile << HEADER;
	
	std::string decision = "";
	std::cout << "Would you like to add a new enum " << "? (n|N  y|Y): ";
	std::cin >> decision;
	while(decision != "n" && decision != "N"){
		defineNewEnum();
		
		std::cout << "Would you like to add a new enum " << "? (n|N  y|Y): ";
		std::cin >> decision;
	}
	
	
	
	saveEnums(&outputFile);
	freeMemory();
	
	outputFile << FOOTER;
	
	outputFile.close();
	
	return 0;

}