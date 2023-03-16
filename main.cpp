#include "parser.hpp"
#include "checkinput.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	/*if(!checkArgs(argc)){
		return -1;
	}
	if(!checkPath(argv[1])){
		return -1;
	}*/
	
	Parser file;
	file.parse(argv[1], '\t');
	file.output(stoi(argv[2]), stoi(argv[3]));
	return 1;
};
