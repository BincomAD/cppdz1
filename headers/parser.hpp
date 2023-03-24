#ifndef PARSER_HPP
#define PARSER_HPP
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Parser
{
private:
	int count = 0;
	vector<vector<string>> nameAndYear;
public:
	void parse(string path, char delim);
	void output(int min, int max);
};

#endif
