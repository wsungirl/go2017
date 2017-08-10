// CountStringsInFile.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

long long wc(char *fileName)
{
	long long cnt = 0;
	char delimeter = '\n';
	ifstream iS (fileName, ifstream::binary);
	if(iS)
	{
		if(iS.peek() == EOF)
			return cnt;
		cnt = count(std::istreambuf_iterator<char>(iS), istreambuf_iterator<char>(), delimeter);
		iS.unget();
		if(iS.get() != '\n')
			++cnt;
	}
	else
	{
		cout << "Bad file name!" << endl;
		return -1;
	}
	return cnt;
}

int main(int argc, char* argv[])
{
	if(argc != 3 or strcmp(argv[1], "-l"))
	{
		cout << "Usage: " << argv[0] << " -l fileName" << endl;
		return -1;
	}
	long long cnt = wc(argv[2]);
	if(cnt != -1)
		cout << "The number of lines in " << argv[2] << " = " << cnt << endl;
	return 0;
}

