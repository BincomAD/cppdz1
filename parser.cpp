#include "parser.hpp"

void Parser::parse(string path, char delim) {
	ifstream file(path);

	string str;
	while (getline(file, str)) {
		string word;
		vector<string> out;
		for (size_t i = 0; i < str.size(); i++) {
        		if (str[i] != delim) {
            			word += str[i];
        		} else {
            			out.push_back(word);
            			word.clear();
        		}
    	}
    	out.push_back(word);
    	nameAndYear.push_back(out);
    	count++;
		out.clear();
	}
}

void Parser::output(int min, int max) {
	for(int i = 0; i < count; ++i) {
		if((nameAndYear[i][4] != "\\N") && stoi(nameAndYear[i][4]) <= max && stoi(nameAndYear[i][4]) >= min) {
			std::cout << nameAndYear[i][2] << endl;
		}
	}
}
