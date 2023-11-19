#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <cstdlib>

class RPN {
	public:
		RPN();
		RPN( const RPN& other );
		RPN& operator=(const RPN& other);
		~RPN();

		int calc(const std::string& expression);
};

#endif