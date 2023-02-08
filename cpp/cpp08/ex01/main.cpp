#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);

std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}