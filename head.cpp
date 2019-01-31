#include "head.h"


void VM::interpret(string &bytecode)
{

	for (unsigned int i = 0; i < bytecode.size(); i += 4)
	{
		string strcode = bytecode.substr(i, 4);
		int code = stoi(strcode, nullptr, 16);
		switch (code)
		{
		case INST_PRINT_STR:
		{
			cout << "print_start" << endl;
			cout << pop().char_value << endl;
			//this->temp_str.
			//cout << this->temp_str.back() << endl;
		}
			break;
		case INST_ADD:
		{
			double ll = pop().double_value;
			double rr = pop().double_value;
			//log(ll + rr);
			push_double(ll + rr);
		}
			break;
		case INST_RIDE:
		{
			double ll = pop().double_value;
			double rr = pop().double_value;
			push_double(ll*rr);
		}
			break;
		case INST_MINUS:
		{
			double ll = pop().double_value;
			double rr = pop().double_value;
			push_double(ll - rr);
		}
			break;
		case INST_DIVIDE:
		{
			double ll = pop().double_value;
			double rr = pop().double_value;
			push_double(ll / rr);
		}
			break;
		case INST_MOD:
		{
			double ll = pop().double_value;
			double rr = pop().double_value;
			push_double(int(ll)%int(rr));
		}
			break;
		case INST_INT_LITERAL_2:
		{
			int _value;
			string tempstr = bytecode.substr(i += 4, 2);
			i -= 2;
			assert(_value = stoi(tempstr, nullptr, 10));
			this->push_double(double(_value));
		}
			break;
		case INST_INT_LITERAL_4:
		{
			int _value;
			string tempstr = bytecode.substr(i += 4, 4);
			assert(_value = stoi(tempstr, nullptr, 10));
			this->push_double(double(_value));
		}
			break;
		case INST_INT_LITERAL_8:
		{
			int _value;
			string tempstr = bytecode.substr(i += 4, 8);
			i += 4;
			assert(_value = stoi(tempstr, nullptr, 10));
			this->push_double(double(_value));
		}
			break;
		case INST_DOUBLE_LITERAL_2:
		{
			double _value;
			string tempstr = bytecode.substr(i += 4, 2);
			i -= 2;
			assert(_value = stod(tempstr,nullptr));
			this->push_double(_value);
		}
			break;
		case INST_DOUBLE_LITERAL_4:
		{
			double _value;
			string tempstr = bytecode.substr(i += 4, 4);
			assert(_value = stod(tempstr, nullptr));
			this->push_double(_value);
		}
			break;
		case INST_DOUBLE_LITERAL_8:
		{
			double _value;
			string tempstr = bytecode.substr(i += 4, 8);
			i += 4;
			assert(_value = stod(tempstr, nullptr));
			this->push_double(_value);
		}
			break;
		case INST_STR_LITERAL:
		{
			int lengh = int(pop().double_value);
			string tempstr = bytecode.substr((i += 4), lengh);
			cout << "str:" << tempstr << endl;
			i += (lengh - 4);
			if (temp_str.size() > 0)
			{
				//this->temp_str.erase(temp_str.end() - 1);
				this->temp_str.pop_back();
			}
				
			this->temp_str.push_back(tempstr);
			this->push_str(this->temp_str.back());
		}
			break;
		case INST_LOADR:
		{
			Value val = pop();
			int reg = int(pop().double_value);
			assert(reg <= MAX_STACK);
			stack_[reg] = val;
		}
			break;
		case INST_LT:
		{
			Value ll = pop();
			Value rr = pop();
			if (ll.double_value > rr.double_value)
				push_double(1);
			else
				push_double(0);
		}
			break;
		case INST_GT:
		{
			Value ll = pop();
			Value rr = pop();
			if (ll.double_value > rr.double_value)
				push_double(0);
			else
				push_double(1);
		}
			break;
		case INST_AND:
		{
			Value ll = pop();
			Value rr = pop();
			if (int(ll.double_value) == 1 && int(rr.double_value) == 1)
				push_double(1);
			else
				push_double(0);
		}
			break;
		case INST_OR:
		{
			Value ll = pop();
			Value rr = pop();
			if (int(ll.double_value) == 1 || int(rr.double_value) == 1)
				push_double(1);
			else
				push_double(0);
		}
			break;
		case INST_JZ:
		{
			int addr = int(pop().double_value);
			if (pop().double_value == 0)
				i = addr;
		}
			break;
		case INST_RJZ:
		{
			int diff = int(pop().double_value);
			if (pop().double_value == 0)
				i += diff;
		}
			break; 
		case INST_JNZ:
		{
			int addr = int(pop().double_value);
			if (pop().double_value == 1)
				i = addr;
		}
			break;
		case INST_RJNZ:
		{
			int diff = int(pop().double_value);
			if (pop().double_value == 1)
				i += diff;
		}
			break;

		default:
			break;
		}
	}
}

