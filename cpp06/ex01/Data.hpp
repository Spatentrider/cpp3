#ifndef DATA_HPP
# define DATA_HPP

class Data 
{
	private:
		int _value;

	public:
		Data();
		Data( int value );
		Data( const Data& other );
		~Data();
		Data& operator=( const Data& other );

		int getValue() const;
};

#endif