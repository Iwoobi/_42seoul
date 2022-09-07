/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:06:43 by youhan            #+#    #+#             */
/*   Updated: 2022/09/07 20:08:34 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;
/*데이터*/

typedef struct s_plane
{
	double			x[3];
	double			n[3];
	unsigned char	rgb[3];
	struct s_plane	*next;
}	t_plane;

typedef struct s_sphere
{
	double			c[3];
	double			r;
	unsigned char	rgb[3];
	struct s_sphere	*next;
}	t_sphere;


typedef struct s_cylinder
{
	double				c[3];
	double				h;
	double				r;
	double				n[3];
	unsigned char		rgb[3];
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_data
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_data	data;
}	t_mlx;

/*데이터*/
int	ft_strlen(char *str);

#endif