#include "arithmetic_expression.h"

const std::map<char, Operation> opsMap = {
	{'+', Operation::ADD_SUBSTRACT},
	{'-', Operation::ADD_SUBSTRACT},
	{'*', Operation::MULTIPLY_DIVIDE},
	{'/', Operation::MULTIPLY_DIVIDE}
};

ArithmeticExpression::ArithmeticExpression(std::string value) :
	_expression(value)
{}

void ArithmeticExpression::AddOperation(const std::string& command)
{
	auto it = opsMap.find(command[0]);

	if (it == opsMap.end())
	{
		return;
	}

	if (it->second > _currentOp)
	{
		_expression = '(' + _expression + ')';
	}
	
	_expression += ' ' + command;
	_currentOp = it->second;
}

std::string ArithmeticExpression::GetExpression()
{
	return _expression;
}