#include "checkinput.hpp"

bool checkArgs(int argc) {
	if(argc == 4) {
		return true;
	} else {
		return false;
	}
}

bool checkPath(std::string path) {
	std::fstream file(path);
	if(file) {
		return true;
	} else {
		return false;
	}
}

