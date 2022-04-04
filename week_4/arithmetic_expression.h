#include <string>
#include <map>

enum Operation : int
{
	ADD_SUBSTRACT = 0,
	MULTIPLY_DIVIDE
	
};

class ArithmeticExpression
{
public:
	ArithmeticExpression(std::string value);
	void AddOperation(const std::string& command);
	std::string GetExpression();
private:
	std::string _expression;
	Operation _currentOp = Operation::MULTIPLY_DIVIDE;
};