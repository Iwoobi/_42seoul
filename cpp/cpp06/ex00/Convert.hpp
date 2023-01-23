#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert
{

	public:

		Convert();
		Convert( Convert const & src );
		~Convert();

		Convert &		operator=( Convert const & rhs );

	private:
		char	res_char;
		double	res_double;
		float	res_float;
		int		res_int;
};


#endif /* ********************************************************* CONVERT_H */