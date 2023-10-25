#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template < typename T >
void	swap( T& x, T& y ) 
{
	T swap;
	swap = x;
	x = y;
	y = swap;
}

template< typename M >
const M&	max( const M& x, const M& y ) 
{
	if (x > y)
		return x;
	return y;
}

template< typename N >
const N&	min( const N& x, const N& y ) 
{
	if (x < y)
		return x;
	return y;
}

#endif
