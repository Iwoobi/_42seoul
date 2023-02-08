#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack()
		{
		}
		MutantStack( MutantStack const & src )
		{
			*this = src;
		}
		~MutantStack()
		{
		}
		MutantStack &		operator=( MutantStack const & rhs )
		{
			*this = rhs;
		}
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		typename MutantStack<T>::stack::container_type::iterator begin()
		{
			return (this->c.begin());
		}
		typename MutantStack<T>::stack::container_type::iterator end()
		{
			return (this->c.end());
		}
		typename MutantStack<T>::stack::container_type::reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		typename MutantStack<T>::stack::container_type::reverse_iterator rend()
		{
			return (this->c.rend());
		}
		typename MutantStack<T>::stack::container_type::const_iterator cbegin()
		{
			return (this->c.cbegin());
		}
		typename MutantStack<T>::stack::container_type::const_iterator cend()
		{
			return (this->c.cend());
		}
		typename MutantStack<T>::stack::container_type::const_reverse_iterator crbegin()
		{
			return (this->c.crbegin());
		}
		typename MutantStack<T>::stack::container_type::const_reverse_iterator crend()
		{
			return (this->c.crend());
		}
	private:

};


#endif /* ***************************************************** MUTANTSTACK_H */