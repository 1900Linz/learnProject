#include "iterattor.h"
#include <iostream>

int main() {
	entityIterattor* demo = new entityIterattor(new entityItem);
	for (; !(demo->IsDone()); demo->Next()) {
		std::cout << demo->CurrentItem() << std::endl;
	}

	delete demo;
	
}