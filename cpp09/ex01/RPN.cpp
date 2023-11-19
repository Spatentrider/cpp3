#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	return;
}

RPN& RPN::operator=(const RPN& other) {
	return *this;
}

RPN::~RPN() {}

int RPN::calc(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> stack;

	while (iss >> token) {
		if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression");

			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/") {
				if (b == 0)
					throw std::runtime_error("Division by zero");
				stack.push(a / b);
			}
		} else {
			int i = 0;
			if (token[i] == '-')
				i++;
			while (token[i]) {
				if (!isdigit(token[i]) && token[0] != '-')
					throw std::runtime_error("Only digit");
				i++;
			}
			int num = std::atoi(token.c_str());
			if (num > 9 || num < -9)
				throw std::runtime_error("Numbers must be less than 10 || greater than -10");
			stack.push(num);
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return stack.top();
}