/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:06:43 by youhan            #+#    #+#             */
/*   Updated: 2022/08/25 18:32:59 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define _USE_MATH_DEFINES
# define PRESS 2
# define CLOSED 17
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_SPA 49

# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_list	*data;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_line
{
	int			w;
	int			h;
	int			d;
	int			x;
	int			y;
}	t_line;
/*데이터*/
typedef struct s_tri
{
	double			a[3];
	double			b[3];
	double			c[3];
	double			n[3];
	unsigned char	rgb[3];
	struct s_tri	*next;
}	t_tri;

typedef struct s_plane
{
	double			x[3];
	double			vecter[3];
	unsigned char	rgb[3];
	struct s_plane	*next;
}	t_plane;

typedef struct s_sphere
{
	double			c[3];
	double			r;
	unsigned char	rgb[3];
	struct s_plane	*next;
}	t_sphere;

typedef struct s_quad
{
	double			c[3];
	double			l;
	double			n[3];
	unsigned char	rgb[3];
	struct s_plane	*next;
}	t_quad;

typedef struct s_cylinder
{
	double			c[3];
	double			h;
	double			r;
	double			n[3];
	unsigned char	rgb[3];
	struct s_plane	*next;
}	t_cylinder;

typedef struct s_data
{
	t_sphere	*sp;
	t_plane		*pl;
	t_quad		*sq;
	t_cylinder	*cy;
	t_tri		*tr;	
}	t_data;

/*데이터*/

#endif