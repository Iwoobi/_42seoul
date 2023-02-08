#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:

		Array()
		{
			this->array = NULL;
			this->_size = 0;
		}
		Array(unsigned int n)
		{
			
			this->array = new T[n];
			this->_size = n;
		}
		Array( Array const & src )
		{
			if (src.size() != 0)
			{
				this->array = new T[src.size()];
				for (std::size_t i = 0; i < src.size(); i++)
					this->array[i] = src[i];
			}
			else
				this->array = NULL;
			this->_size = src.size();
		}
		~Array()
		{
			if (this->size() != 0)
				delete[] this->array;
			this->array = NULL;
			this->_size = 0;
		}
		std::size_t	size() const
		{
			return (this->_size);
		}
		T&		operator[]( std::size_t i)
		{
			if (this->_size < i + 1)
				throw error();
			return (this->array[i]);
		}
		const T&		operator[]( std::size_t i) const
		{
			if (this->_size < i + 1)
				throw error();
			return (this->array[i]);
		}
		Array &		operator=( Array const & rhs )
		{
			if ( this != &rhs )
			{
				if (this->size() != 0)
				{
					delete[] this->array;
				}
				if (rhs.size() == 0)
				{
					this->array = NULL;
					this->_size = 0;
					return (*this);
				}
				this->array = new T[rhs.size()];
				this->_size = rhs.size();
				for (std::size_t i = 0; i < rhs.size(); i++)
				{
					this->array[i] = rhs[i];
				}
			}
			return (*this);
		}
		class error : public std::exception 
		{
   			public:
      			const char* what(void) const throw()
				{
        			return ("out of range!");
      			}
		};

	private:
		std::size_t _size;
		T *array;
		

};


#endif /* *********************************************************** ARRAY_H */