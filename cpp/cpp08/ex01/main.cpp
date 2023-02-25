#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addmanyNumber(5, 2);
// 	std::vector<int> j = (sp.getdata());
// 	for (std::vector<int>::iterator i = j.begin() ; i != j.end(); i++)
// 	{
// 		std::cout << *i << " ";
// 	}
// 	std::cout << "\n";
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

	
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}