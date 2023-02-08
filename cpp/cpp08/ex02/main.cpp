#include "MutantStack.hpp"

int main()
{
    MutantStack<int> a;

    for (int i = 0; i < 10; i++)
    {
        a.push(i);
    }
    for (MutantStack<int>::iterator i = a.begin(); i != a.end(); i++)
    {
        std::cout << *i << " ";
    }

    
}