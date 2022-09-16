/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:43:50 by youhan            #+#    #+#             */
/*   Updated: 2022/09/16 13:49:31 by youhan           ###   ########.fr       */
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
		if (i != 2)
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
		rgb[i] = (unsigned char)ft_char_double(*str, &count);
		*str += count;
		if (**str != ',' && i != 2)
			print_error("check , data");
		if (i != 2)
			(*str)++;
		i++;
	}
}

void	null_check(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str != '\0')
		print_error("check input data");
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
			mlx->data.al->next->next = NULL;
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
	null_check(str);
	mlx->data.al = save;
}

void	push_c(char *str, t_mlx *mlx)
{
	int		count;
	t_cam	*save;

	save = mlx->data.cam;
	count = 0;
	str += 2;
	while (mlx->data.count_cam > count)
	{
		if (mlx->data.count_cam - count == 1)
		{
			mlx->data.cam->next = (t_cam *)malloc(sizeof(t_cam) * 1);
			if (mlx->data.cam->next == NULL)
				print_error("malloc error");
			mlx->data.cam->next->next = NULL;
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
	null_check(str);
	mlx->data.cam = save;
}

void	push_l(char *str, t_mlx *mlx)
{
	int		count;
	t_light	*save;

	save = mlx->data.l;
	count = 0;
	str++;
	while (mlx->data.count_l > count)
	{
		if (mlx->data.count_l - count == 1)
		{
			mlx->data.l->next = (t_light *)malloc(sizeof(t_light) * 1);
			if (mlx->data.l->next == NULL)
				print_error("malloc error");
			mlx->data.l->next->next = NULL;
		}
		mlx->data.l = mlx->data.l->next;
		count++;
	}
	count = 0;
	mlx->data.count_l += 1;
	push_x_y_z(&(mlx->data.l->x[0]), &str);
	mlx->data.l->ratio = ft_char_double(str, &count);
	str += count;
	push_rgb(&(mlx->data.l->rgb[0]), &str);
	null_check(str);
	mlx->data.l = save;
}

void	push_sp(char *str, t_mlx *mlx)
{
	int			count;
	t_sphere	*save;

	save = mlx->data.sp;
	count = 0;
	str += 2;
	while (mlx->data.count_sp > count)
	{
		if (mlx->data.count_sp - count == 1)
		{
			mlx->data.sp->next = (t_sphere *)malloc(sizeof(t_sphere) * 1);
			if (mlx->data.sp->next == NULL)
				print_error("malloc error");
			mlx->data.sp->next->next = NULL;
		}
		mlx->data.sp = mlx->data.sp->next;
		count++;
	}
	count = 0;
	mlx->data.count_sp += 1;
	push_x_y_z(&(mlx->data.sp->c[0]), &str);
	mlx->data.sp->r = ft_char_double(str, &count);
	str += count;
	push_rgb(&(mlx->data.sp->rgb[0]), &str);
	null_check(str);
	mlx->data.sp = save;
}

void	push_pl(char *str, t_mlx *mlx)
{
	int		count;
	t_plane	*save;

	save = mlx->data.pl;
	count = 0;
	str += 2;
	while (mlx->data.count_pl > count)
	{
		if (mlx->data.count_pl - count == 1)
		{
			mlx->data.pl->next = (t_plane *)malloc(sizeof(t_plane) * 1);
			if (mlx->data.pl->next == NULL)
				print_error("malloc error");
			mlx->data.pl->next->next = NULL;
		}
		mlx->data.pl = mlx->data.pl->next;
		count++;
	}
	count = 0;
	mlx->data.count_pl += 1;
	push_x_y_z(&(mlx->data.pl->x[0]), &str);
	push_x_y_z(&(mlx->data.pl->n[0]), &str);
	push_rgb(&(mlx->data.pl->rgb[0]), &str);
	null_check(str);
	mlx->data.pl = save;
}

void	push_cy(char *str, t_mlx *mlx)
{
	int		count;
	t_cylinder	*save;

	save = mlx->data.cy;
	count = 0;
	str += 2;
	while (mlx->data.count_cy > count)
	{
		if (mlx->data.count_cy - count == 1)
		{
			mlx->data.cy->next = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
			if (mlx->data.cy->next == NULL)
				print_error("malloc error");
			mlx->data.cy->next->next = NULL;
		}
		mlx->data.cy = mlx->data.cy->next;
		count++;
	}
	count = 0;
	mlx->data.count_cy += 1;
	push_x_y_z(&(mlx->data.cy->c[0]), &str);
	push_x_y_z(&(mlx->data.cy->n[0]), &str);
	mlx->data.cy->r = ft_char_double(str, &count);
	str += count;
	count = 0;
	mlx->data.cy->h = ft_char_double(str, &count);
	str += count;
	push_rgb(&(mlx->data.cy->rgb[0]), &str);
	null_check(str);
	mlx->data.cy = save;
}

void	check_obj(char *str, t_mlx *mlx)
{
	if (div_str(str, "A") == 1)
		push_a(str, mlx);
	else if (div_str(str, "C") == 1)
		push_c(str, mlx);
	else if (div_str(str, "L") == 1)
		push_l(str, mlx);
	else if (div_str(str, "sp") == 1)
		push_sp(str, mlx);
	else if (div_str(str, "pl") == 1)
		push_pl(str, mlx);
	else if (div_str(str, "cy") == 1)
		push_cy(str, mlx);
	else if (*str != '\0')
	{
		printf("here\n");
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
	mlx->data.l = (t_light *)malloc(sizeof(t_light) * 1);
	mlx->data.pl = (t_plane *)malloc(sizeof(t_plane) * 1);
	mlx->data.cy = (t_cylinder *)malloc(sizeof(t_cylinder) * 1);
	mlx->data.sp = (t_sphere *)malloc(sizeof(t_sphere) * 1);
	if (mlx->data.al == NULL || mlx->data.cam == NULL || mlx->data.l == NULL)
		print_error("malloc error");
	if (mlx->data.pl == NULL || mlx->data.cy == NULL || mlx->data.sp == NULL)
		print_error("malloc error");
	mlx->data.al->next = NULL;
	mlx->data.l->next = NULL;
	mlx->data.cam->next = NULL;
	mlx->data.pl->next = NULL;
	mlx->data.cy->next = NULL;
	mlx->data.sp->next = NULL;
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
			printf("x[%d] : %f\n",i,mlx.data.cam->x[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("n[%d] : %f\n",i,mlx.data.cam->n[i]);
			i++;
		}
		printf("FOV : %f\n", mlx.data.cam->fov);
		mlx.data.cam = mlx.data.cam->next;
	}
}


void	test_l(t_mlx mlx)
{
	int i;
	printf("\ntest light\n");
	while (mlx.data.l != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("x[%d] : %f\n",i,mlx.data.l->x[i]);
			i++;
		}
		printf("ratio : %f\n", mlx.data.l->ratio);
		i = 0;
		while (i < 3)
		{
			printf("rgb[i] : %d\n",mlx.data.l->rgb[i]);
			i++;
		}
		mlx.data.l = mlx.data.l->next;
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
			printf("rgb[%d] : %d\n",i,mlx.data.al->rgb[i]);
			i++;
		}
		mlx.data.al = mlx.data.al->next;
	}
}

void	test_pl(t_mlx mlx)
{
	int i;
	
	printf("\ntest pl\n");
	while (mlx.data.pl != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("x[%d] : %f\n",i,mlx.data.pl->x[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("n[%d] : %f\n",i,mlx.data.pl->n[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("rgb[%d] : %d\n",i,mlx.data.pl->rgb[i]);
			i++;
		}
		mlx.data.pl = mlx.data.pl->next;
	}
}

void	test_sp(t_mlx mlx)
{
	int i;
	
	printf("\ntest sp\n");
	while (mlx.data.sp != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("c[%d] : %f\n",i,mlx.data.sp->c[i]);
			i++;
		}
		printf("r : %f\n", mlx.data.sp->r);
		i = 0;
		while (i < 3)
		{
			printf("rgb[%d] : %d\n",i,mlx.data.sp->rgb[i]);
			i++;
		}
		mlx.data.sp = mlx.data.sp->next;
	}
}

void	test_cy(t_mlx mlx)
{
	int i;
	
	printf("\ntest cy\n");
	while (mlx.data.cy != NULL)
	{
		i = 0;
		while (i < 3)
		{
			printf("x[%d] : %f\n",i,mlx.data.cy->c[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("n[%d] : %f\n",i,mlx.data.cy->n[i]);
			i++;
		}
		printf("r : %f\n", mlx.data.cy->r);
		printf("h : %f\n", mlx.data.cy->h);
		i = 0;
		while (i < 3)
		{
			printf("rgb[%d] : %d\n",i,mlx.data.cy->rgb[i]);
			i++;
		}
		mlx.data.cy = mlx.data.cy->next;
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
	test_l(mlx);
	test_cy(mlx);
	test_pl(mlx);
	test_sp(mlx);

}