/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:12:10 by youhan            #+#    #+#             */
/*   Updated: 2022/11/22 19:18:33 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

void	ft_replace(std::string &buf, size_t found, size_t len, std::string replace)
{
	std::string	tmp;
	int			i = 0;

	tmp.resize(found);
	for (i = 0; i < found; i++)
		tmp[i] = buf[i];
	tmp[i] = '\0';
	tmp += replace;
	tmp.resize(buf.length() - len + replace.length());
	int j = 0;
	while (i + j + len < buf.length())
	{
		tmp[i + j + replace.length()] = buf[len + i + j];
		j++;
	}
	buf = tmp;
}
void	find_word(std::string buf, std::ofstream &out, std::string word, std::string replace)
{
	static	int	i = 0;
	int			progress = 0;

	if (i != 0)
		out << std::endl;
	std::size_t	found = buf.find(word);
	while (found != -1)
	{
		progress = found + replace.length();
		ft_replace(buf, found, word.length(), replace);
		found = buf.find(word, progress);
	}
	out << buf;
	i = 1;
}
int	main(int argc, char **argv)
{
	std::ifstream		read_f;
	std::ofstream		write_f;
	std::stringstream	tmp;
	std::string			string_file;


	if (argc != 4)
		return (0);


	tmp << argv[1];
	tmp >> string_file;
	read_f.open(argv[1]);


	if (!read_f.is_open())
	{
		std::cout << "check file name" << std::endl;
		return (0);
	}

	
	write_f.open(string_file + ".replace");
	if (!write_f.is_open())
	{
		std::cout << "write file not exist" << std::endl;
		return (0);
	}

	std::string	buf;
	while (std::getline(read_f, buf))
	{
		find_word(buf, write_f, argv[2], argv[3]);
	}

	// system("leaks a.out");
}