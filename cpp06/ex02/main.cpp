#include <iostream>
#include <cstdlib>
#include <ctime>

class Base 
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate() 
{
	int randomNum = rand() % 3;

	switch (randomNum) 
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void	identify(Base* p) 
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "*A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "*B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "*C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p) 
{
	try 
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "&A" << std::endl;
		return;
	} catch (const std::exception& e) {}

	try 
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "&B" << std::endl;
		return;
	} catch (const std::exception& e) {}

	try 
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "&C" << std::endl;
		return;
	} catch (const std::exception& e) {}

	std::cout << "Unknown" << std::endl;
}


int	main() 
{
	srand(static_cast<unsigned>(time(0)));

	Base* first = generate();
	Base* second = generate();
	Base* third = generate();

	std::cout << "first* = " << std::ends;
	identify(first);
	std::cout << "first& = " << std::ends;
	identify(*first);
	std::cout << "\nsecond* = " << std::ends;
	identify(second);
	std::cout << "second& = " << std::ends;
	identify(*second);
	std::cout << "\nthird* = " << std::ends;
	identify(third);
	std::cout << "third& = " << std::ends;
	identify(*third);

	delete first;
	delete second;
	delete third;
	return 0;
}
