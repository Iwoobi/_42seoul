/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:16:20 by youhan            #+#    #+#             */
/*   Updated: 2022/09/19 22:17:43 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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