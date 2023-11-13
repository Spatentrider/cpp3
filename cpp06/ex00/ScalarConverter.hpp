#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>

extern std::string special[6];

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		static void char_converter( const std::string& input );
		static void number_converter( const std::string& input );

	public:
		~ScalarConverter();
		ScalarConverter& operator=( const ScalarConverter& other );

		static void convert( const std::string& input );

};


#endif
