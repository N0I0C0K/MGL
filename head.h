#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
#include<math.h>

using namespace std;

enum Instruction
{
	INST_PRINT_STR = 0x0111,
	INST_ADD = 0x0101,
	INST_RIDE = 0x0102,
	INST_MINUS = 0x0103,
	INST_DIVIDE = 0x0104,
	INST_MOD = 0x0105,
	INST_INT_LITERAL_4 = 0x0004,
	INST_INT_LITERAL_8 = 0x0008,
	INST_INT_LITERAL_2 = 0x0002,
	INST_DOUBLE_LITERAL_2 = 0x0012,
	INST_DOUBLE_LITERAL_4 = 0x0014,
	INST_DOUBLE_LITERAL_8 = 0x0018,
	INST_STR_LITERAL = 0x0031,
	INST_LT = 0x0081,
	INST_GT = 0x0082,
	INST_OR = 0x0083,
	INST_AND = 0x0084,
	INST_JZ = 0x0091,
	INST_RJZ = 0x0092,
	INST_JNZ =	0x0093,
	INST_RJNZ = 0x0094
};

struct Value
{
	union
	{
		//int hero_index;
		//int int_value;
		const char* char_value;
		double double_value;
	};
};

class VM
{
public:
	void push_double(double value)
	{
		assert(stackSize_ < MAX_STACK);
		cout << "+++push count" << value << endl;
		stack_[stackSize_++].double_value = value;
		return;
	}
	void push_str(string value)
	{
		assert(stackSize_ < MAX_STACK);
		cout << "+++push str:" << value << endl;
		stack_[stackSize_++].char_value = value.c_str();
		return;
	}
	Value pop()
	{
		assert(stackSize_ > 0);
		cout << "---pop value" << endl;
		return stack_[--stackSize_];
	}
	void interpret(string &bytecode);
private:
	static const int MAX_STACK = 128;
	int stackSize_ = 0;
	Value stack_[MAX_STACK];
};

