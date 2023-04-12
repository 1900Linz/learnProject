#include <iostream>
#include <boost\algorithm\string.hpp>

class expression {
public:
	virtual bool interpret(std::string) = 0;
};

//
class terminalExp : public expression {
public:
	terminalExp(std::string str) {
		data = str;
	}

	bool interpret(std::string context) {
		if (boost::contains(context,data))
		{
			return true;
		}
		return false;
	}

private:
	std::string data;
};

class orExp :public expression {
public:
	orExp(expression* e1, expression* e2)
		: exp1(e1)
		, exp2(e2)
	{

	}

	bool interpret(std::string context) {
		return exp1->interpret(context) || exp2->interpret(context);
	}

private:
	expression* exp1;
	expression* exp2;
};

class andExp :public expression {
public:
	andExp(expression* e1, expression* e2)
		: exp1(e1)
		, exp2(e2)
	{

	}

	bool interpret(std::string context) {
		return exp1->interpret(context) && exp2->interpret(context);
	}

private:
	expression* exp1;
	expression* exp2;
};



