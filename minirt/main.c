/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:43:50 by youhan            #+#    #+#             */
/*   Updated: 2022/09/21 21:59:37 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	print_rot_data(t_mdata data)
{
	int	i;
	int	j;

	printf("rot_data\n");
	printf("%f  %f   %f\n",data.m[0], data.m[1], data.m[2]);

	i = 0;
	while (i < 3)
	{
		j=0;
		while (j < 3)
		{
			printf("%f ", data.rot[3 * i + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


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

void	close_non_data(t_mlx *mlx)
{
	if (mlx->data.count_al == 0)
	{
		free(mlx->data.al);
		mlx->data.al = NULL;
	}
	if (mlx->data.count_cy == 0)
	{
		free(mlx->data.cy);
		mlx->data.cy = NULL;
	}
	if (mlx->data.count_l == 0)
	{
		free(mlx->data.l);
		mlx->data.l = NULL;
	}
	if (mlx->data.count_pl == 0)
	{
		free(mlx->data.pl);
		mlx->data.pl = NULL;
	}
	if (mlx->data.count_sp == 0)
	{
		free(mlx->data.sp);
		mlx->data.sp = NULL;
	}
}

void	check_cam_error(t_mlx *mlx)
{
	if (mlx->data.count_cam == 0)
		print_error("check cam data");
}

void	check_input(char *argv, t_mlx *mlx)
{
	check_filename(argv);
	push_data(opne_data(argv), mlx);
	test_a(*mlx);
	test_c(*mlx);
	test_l(*mlx);
	test_cy(*mlx);
	test_pl(*mlx);
	test_sp(*mlx);
	printf("\n\n\n\n\n\n\n\n\n");
	close_non_data(mlx);
	check_cam_error(mlx);
}

void	init_mlx_data(t_mlx *mlx)
{

	mlx->size[0] = 1600;
	mlx->size[1] = 900;

	mlx->cam_num = 0;
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

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (-1);
}

int	press_key(int key_code)
{
	if (key_code == 53)
		exit(0);
	return (1);
}

void	cross_product(double *u, double *w, double *result)
{
	result[0] = u[1] * w[2] - u[2] * w[1];
	result[1] = u[2] * w[0] - u[0] * w[2];
	result[2] = u[0] * w[1] - u[1] * w[0];
}

double	vector_size(double *x)
{
	return (sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]));
}

double	*rot_matrix(double *x, double *y, double *z)
{
	static double	result[9];

	result[0] = x[0] / vector_size(x);
	result[1] = y[0] / vector_size(y);
	result[2] = z[0] / vector_size(z);
	result[3] = x[1] / vector_size(x);
	result[4] = y[1] / vector_size(y);
	result[5] = z[1] / vector_size(z);
	result[6] = x[2] / vector_size(x);
	result[7] = y[2] / vector_size(y);
	result[8] = z[2] / vector_size(z);
	printf("\ncross\n%f %f %f\n",result[0], result[1], result[2]);
	printf("%f %f %f\n",result[3], result[4], result[5]);
	printf("%f %f %f\n",result[6], result[7], result[8]);

	return (result);
}

double	*rot_data_push(t_cam cam)
{
	double	*result;
	double	x[3];
	double	y[3];
	double	z[3];

	z[0] = 0;
	z[1] = 0;
	z[2] = 1;
	cross_product(cam.n, z, x);
	cross_product(cam.n, x, y);
	result = rot_matrix(x, y, cam.n);
	return (result);
}

t_mdata	rot_data_init(t_cam	cam)
{
	t_mdata	data;

	data.m[0] = cam.x[0];
	data.m[1] = cam.x[1];
	data.m[2] = cam.x[2];
	data.rot = rot_data_push(cam);
	return (data);
}

t_mdata	data_cam_num_init(t_mlx mlx)
{
	int		i;

	i = 0;
	while (i < mlx.cam_num)
	{
		mlx.data.cam = mlx.data.cam->next;
		i++;
	}
	return (rot_data_init(*(mlx.data.cam)));
}

void	trans_rot_data(double x[3], t_mdata mdata)
{
	double	save[3];

	save[0] = x[0];
	save[1] = x[1];
	save[2] = x[2];
	x[0] = mdata.rot[0] * save[0] + mdata.rot[1] * save[1] + mdata.rot[2] * save[2];
	x[1] = mdata.rot[3] * save[0] + mdata.rot[4] * save[1] + mdata.rot[5] * save[2];
	x[2] = mdata.rot[6] * save[0] + mdata.rot[7] * save[1] + mdata.rot[8] * save[2];
}

void	updata_rot_l(t_data *data, t_mdata mdata)
{
	t_light	*save;

	save = data->l;
	while (data->l != NULL)
	{
		data->l->x[0] -= mdata.m[0];
		data->l->x[1] -= mdata.m[1];
		data->l->x[2] -= mdata.m[2];
		trans_rot_data(data->l->x, mdata); 
		data->l = data->l->next;
	}
	data->l = save;
}

void	updata_rot_sp(t_data *data, t_mdata mdata)
{
	t_sphere	*save;

	save = data->sp;
	while (data->sp != NULL)
	{
		data->sp->c[0] -= mdata.m[0];
		data->sp->c[1] -= mdata.m[1];
		data->sp->c[2] -= mdata.m[2];
		trans_rot_data(data->sp->c, mdata); 
		data->sp = data->sp->next;
	}
	data->sp = save;
}

void	updata_rot_pl(t_data *data, t_mdata mdata)
{
	t_plane	*save;

	save = data->pl;
	while (data->pl != NULL)
	{
		data->pl->x[0] -= mdata.m[0];
		data->pl->x[1] -= mdata.m[1];
		data->pl->x[2] -= mdata.m[2];
		trans_rot_data(data->pl->x, mdata);
		trans_rot_data(data->pl->n, mdata); 
		data->pl = data->pl->next;
	}
	data->pl = save;
}

void	updata_rot_cy(t_data *data, t_mdata mdata)
{
	t_cylinder	*save;

	save = data->cy;
	while (data->cy != NULL)
	{
		data->cy->c[0] -= mdata.m[0];
		data->cy->c[1] -= mdata.m[1];
		data->cy->c[2] -= mdata.m[2];
		trans_rot_data(data->cy->c, mdata);
		trans_rot_data(data->cy->n, mdata); 
		data->cy = data->cy->next;
	}
	data->cy = save;
}


void	updata_rot(t_data *data, t_mdata mdata)
{
	updata_rot_l(data, mdata);
	updata_rot_sp(data, mdata);
	updata_rot_pl(data, mdata);
	updata_rot_cy(data, mdata);
}

void	exec_rot_data(t_mlx *mlx, t_data data, t_mdata mdata)
{
	updata_rot(&data, mdata);
	mlx->data.l = mlx->data.l;
}

int	loop_main(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}



int	main(int argc, char **argv)
{
	t_mlx	mlx;
	if (argc != 2)
		exit(0);
	init_mlx_data(&mlx);
	check_input(argv[1], &mlx);
	t_mdata	rot_data;

	rot_data = data_cam_num_init(mlx);
	print_rot_data(rot_data);
	exec_rot_data(&mlx, mlx.data, rot_data);
	test_a(mlx);
	test_c(mlx);
	test_l(mlx);
	test_cy(mlx);
	test_pl(mlx);
	test_sp(mlx);
	// ft_mlx_init(&mlx);
	// mlx_hook(mlx.win, PRESS, 0, &press_key, &mlx);
	// mlx_hook(mlx.win, CLOSED, 0, &ft_close, &mlx);
	// mlx_loop_hook(mlx.mlx, &loop_main, &mlx);
	// mlx_loop(mlx.mlx);
}