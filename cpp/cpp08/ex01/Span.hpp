#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
class Span
{

	public:

		Span();
		Span(unsigned int n);
		Span( Span const & src );
		~Span();
		int	getn() const;
		int getfilln() const;
		std::vector<int> getdata() const;
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		Span &		operator=( Span const & rhs );
		class error : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class differror : public std::exception
		{
			public:
			const char* what() const throw();
		};


	private:
		unsigned int n;
		unsigned int fill_n;
		std::vector<int> _data;

};

// std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */