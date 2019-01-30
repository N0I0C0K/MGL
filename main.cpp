#include"head.h"

int main(int argc, char** argv)
{
	VM* vm = new VM();
	string codestr;
	while (true)
	{
		cin >> codestr;
		vm->interpret(codestr);
	}
	return 0;
}