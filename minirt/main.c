/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:43:50 by youhan            #+#    #+#             */
/*   Updated: 2022/09/08 20:18:52 by youhan           ###   ########.fr       */
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

void	push_x_y_z(double *data, char **str)
{
	int	i;
	int	count;

	i = 0;
	while (i < 3)
	{
		count = 0;
		data[i] = ft_char_double(*str, &count);
		*str += count;
		if (**str != ',' && i != 2)
			print_error("check data");
		(*str)++;
		i++;
	}
}

void	push_rgb(unsigned char *rgb, char **str)
{
	int	i;
	int	count;

	i = 0;
	while (i < 3)
	{
		count = 0;
		rgb[i] = ft_char_double(*str, &count);
		*str += count;
		if (**str != ',' && i != 2)
			print_error("check data");
		(*str)++;
		i++;
	}
}

void	push_a(char *str, t_mlx *mlx)
{
	int			count;
	t_alight	*save;

	save = mlx->data.al;
	count = 0;
	str++;
	while (mlx->data.count_al > count)
	{
		if (mlx->data.count_al - count == 1)
		{
			mlx->data.al->next = (t_alight *)malloc(sizeof(t_alight) * 1);
			if (mlx->data.al->next == NULL)
				print_error("malloc error");
		}
		mlx->data.al = mlx->data.al->next;
		count++;
	}
	count = 0;
	mlx->data.count_al += 1;
	mlx->data.al->ratio = ft_char_double(str, &count);
	mlx->data.al->next = NULL;
	str += count;
	push_rgb(&(mlx->data.al->rgb[0]), &str);
	mlx->data.al = save;
}

void	push_c(char *str, t_mlx *mlx)
{
	int		count;
	t_cam	*save;

	save = mlx->data.cam;
	count = 0;
	str++;
	while (mlx->data.count_cam > count)
	{
		if (mlx->data.count_cam - count == 1)
		{
			mlx->data.cam->next = (t_cam *)malloc(sizeof(t_cam) * 1);
			if (mlx->data.cam->next == NULL)
				print_error("malloc error");
		}
		mlx->data.cam = mlx->data.cam->next;
		count++;
	}
	count = 0;
	mlx->data.count_cam += 1;
	push_x_y_z(&(mlx->data.cam->x[0]), &str);
	push_x_y_z(&(mlx->data.cam->n[0]), &str);
	mlx->data.cam->fov = ft_char_double(str, &count);
	str += count;
	mlx->data.cam = save;
}

void	check_obj(char *str, t_mlx *mlx)
{
	if (div_str(str, "A") == 1)
	{
		push_a(str, mlx);
	}
	else if (div_str(str, "C") == 1)
	{
		push_c(str, mlx);
	}
	// else if (div_str(str, "L"))
	// 	push_l(str, mlx);
	// else if (div_str(str, "sp"))
	// 	push_sp(str, mlx);
	// else if (div_str(str, "pl"))
	// 	push_pl(str, mlx);
	// else if (div_str(str, "cy"))
	// 	push_cy(str, mlx);
	else if (*str != '\0')
	{
		printf("%s\n",str);
		print_error("check data");
	}
}

void	check_push_data(char *str, t_mlx *mlx)
{
	check_obj(str, mlx);
}

void	push_data(int fd, t_mlx *mlx)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s",str);
		if (!(*str == '\n' && ft_strlen(str) == 1))
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

void	init_mlx_data(t_mlx *mlx)
{
	mlx->data.count_l = 0;
	mlx->data.count_al = 0;
	mlx->data.count_cam = 0;
	mlx->data.count_sp = 0;
	mlx->data.count_pl = 0;
	mlx->data.count_cy = 0;
	mlx->data.al = (t_alight *)malloc(sizeof(t_alight) * 1);
	mlx->data.cam = (t_cam *)malloc(sizeof(t_cam) * 1);
}

void	test_c(t_mlx mlx)
{
	int i;
	printf("\ntest cam\n");
	while (mlx.data.cam != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("x[i] : %f\n",mlx.data.cam->x[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("n[i] : %f\n",mlx.data.cam->n[i]);
			i++;
		}
		printf("FOV : %f\n", mlx.data.cam->fov);
		mlx.data.cam = mlx.data.cam->next;
	}
}

void	test_a(t_mlx mlx)
{
	int i;
	
	printf("\ntest A\n");
	while (mlx.data.al != NULL)
	{
		printf("ratio : %f\n",mlx.data.al->ratio);
		i = 0;
		while (i < 3)
		{
			printf("rgb[i] : %d\n",mlx.data.al->rgb[i]);
			i++;
		}
		mlx.data.al = mlx.data.al->next;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int i = 0;
	if (argc != 2)
		exit(0);
	init_mlx_data(&mlx);
	check_input(argv[1], &mlx);
	test_a(mlx);
	test_c(mlx);
		test_a(mlx);
	test_c(mlx);

}