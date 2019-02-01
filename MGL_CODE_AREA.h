#pragma once
#include<iostream>
#include<string>
#include<map>

using namespace std;

class Code
{
public:
	Code(string name,string code, string precode = "");
	map<string, double> Lcount_pack;
	map<string, string> Lstr_pack;
	string name;
	string bytecode;
	string bytePrecode;
private:

};