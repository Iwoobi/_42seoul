/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:43:50 by youhan            #+#    #+#             */
/*   Updated: 2022/09/07 20:15:32 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(-1);
}

void	check_filename(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	if (argv[i] != 't')
		print_error("check file name");
	i--;
	if (argv[i] != 'r')
		print_error("check file name");
	i--;
	if (argv[i] != '.')
		print_error("check file name");
}

int	opne_data(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		print_error("check file name");
	return (fd);
}

int	div_str(char *str, char *div)
{
	if (*str == '\0')
		return (-1);
	if (str == NULL || div == NULL)
		return (-1);
	while (*div != '\0')
	{
		if (*div != *str)
			return (-1);
		div++;
		str++;
		if (*str == '\0')
			return (-1); 
	}
	return (1);
}

void	push_a(char *str, t_mlx *mlx)
{
	
}

void	push_c(char *str, t_mlx *mlx)
{
	
}

void	push_a(char *str, t_mlx *mlx)
{
	
}

void	push_a(char *str, t_mlx *mlx)
{
	
}

void	check_obj(char *str, t_mlx *mlx)
{
	if (div_str(str, "A"))
		push_a(str, mlx);
	else if (div_str(str, "C"))
		push_c(str, mlx);
	else if (div_str(str, "L"))
		push_l(str, mlx);
	else if (div_str(str, "sp"))
		push_sp(str, mlx);
	else if (div_str(str, "pl"))
		push_pl(str, mlx);
	else if (div_str(str, "cy"))
		push_cy(str, mlx);
	else if (*str != '\0')
		print_error("check data");
}

void	 check_push_data(char *str, t_mlx *mlx)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	check_obj(str, mlx);
}

void	push_data(int fd, t_mlx *mlx)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		check_push_data(str, mlx);
		free(str);
		str = get_next_line(fd);
	}
}

void	check_input(char *argv, t_mlx *mlx)
{
	check_filename(argv);
	push_data(opne_data(argv), mlx);
}
int	main(int argc, char **argv)
{
	t_mlx	mlx;
	if (argc != 2)
		exit(0);
	check_input(argv[1], &mlx);
}