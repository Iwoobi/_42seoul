#include <sstream>
#include <iostream>
#include <limits>
#include "convert.hpp"
int	main(int argc, char **argv)
{
	std::stringstream	buf;
	double				double_buf = 0;
	std::string			buf2;
	char				char_buf = 0;
	int					int_buf = 0;
	float				float_buf = 0;
	int					flag = 0;

	if (argc != 2)
		return (-1);
	int i = 0;
	while (argv[1][i] != '\0')
	{
		i++;
		if (i == INTMAX)
			return (-1);
	}
	if (i == 1)
	{
		if (argv[1][0] == '.')
			flag = -1;
		if (argv[1][0] >= '0' && argv[1][0] <= '9')
		{
			buf << argv[1];
			buf >> double_buf;
			flag = 3;
		}
		else
		{
			char_buf = argv[1][0];
			flag = 1;
		}
	}
	else if (i > 2)
	{
		if ((argv[1][i - 1] == 'f' && argv[1][i - 2] != 'n') || (argv[1][i - 1] == 'f' && argv[1][i - 2] == 'n' && argv[1][i - 3] == 'a'))
		{
			if (argv[1][i - 2] == '.' || argv[1][0] == '.')
				flag = -1;
			buf2.resize(i - 1);
			i = i - 2;
			while (i >= 0)
			{
				buf2[i] = argv[1][i];
				i--;
			}
			buf << buf2;
			buf >> float_buf;
			flag = 2;
			if (buf.fail() || !buf.eof())
				flag = -1;
		}
	}
	if (flag == 0)
	{
		if (argv[1][0] == '.' || argv[1][i - 1] == '.')
			flag = -1;
		buf << argv[1];
		buf >> double_buf;
		if (buf.fail() || !buf.eof())
		{
			if (double_buf != std::numeric_limits<double>::infinity() && double_buf != -std::numeric_limits<double>::infinity())
				flag = -1;
		}
	}
	if (flag == 1)
	{
		int_buf = static_cast<int>(char_buf);
		double_buf = static_cast<double>(char_buf);
		float_buf = static_cast<float>(char_buf);
	}
	else if (flag == 2)
	{
		int_buf = static_cast<int>(float_buf);
		double_buf = static_cast<double>(float_buf);
		char_buf = static_cast<char>(float_buf);
	}
	else if (flag != -1)
	{
		int_buf = static_cast<int>(double_buf);
		char_buf = static_cast<char>(double_buf);
		float_buf = static_cast<float>(double_buf);
	}
	else if (flag == -1)
	{
		std::cout << "char: impossible" << "\n"
		<< "int: " << "impossible" << "\n"
		<< "float: " << "impossible" << "\n"
		<< "double: " << "impossible" << std::endl;
		return (1);
	}
	flag = 0;
	if (double_buf >= 31 && double_buf < 127)
		std::cout << "char: '" << char_buf << "'\n";
	else if (float_buf != float_buf)
		std::cout << "char: impossible\n";
	else if(double_buf >= -128 && double_buf <= 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: overflow\n";
	if (double_buf - int_buf != 0)
	{
		if (double_buf > INTMAX || double_buf < INTMIN)
			std::cout << "int: overflow\n";
		else if (float_buf != float_buf )
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << int_buf << "\n";
		if (float_buf != float_buf)
			std::cout << "float: " << float_buf << "f\n";
		else 
			std::cout << "float: " << float_buf << "f\n";
		if (double_buf != double_buf)
			std::cout << "double: " << double_buf << "\n";
		else
			std::cout << "double: " << double_buf << std::endl;
	}
	else
	{
		if (double_buf > INT_MAX || double_buf < INT_MIN)
			std::cout << "int: overflow\n";
		else if (float_buf != float_buf )
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << int_buf << "\n";
		if (float_buf != float_buf)
			std::cout << "float: " << float_buf << "f\n";
		else 
			std::cout << "float: " << float_buf << ".0f\n";
		if (double_buf != double_buf)
			std::cout << "double: " << double_buf << "\n";
		else
			std::cout << "double: " << double_buf << ".0" <<std::endl;
	}
	
	

}
