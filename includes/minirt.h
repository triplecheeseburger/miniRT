/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:23:09 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/30 15:23:11 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "structures.h"

# define WIN_WIDTH	1200
# define WIN_HEIGHT	800
# define EPSILON 1e-6
/*
 * 	ft_constructor.c
 */
t_vec		make_vec(double x, double y, double z);
t_point		make_point(double x, double y, double z);
t_color		make_color(double x, double y, double z);
t_ray		make_ray(t_point p, t_vec vec);
t_ray		make_view(t_camera *cam, double u, double v);

/*
 * 	utils.c
 */
void		set_face_normal(t_ray *ray, t_rec *rec);
t_point		ray_at(t_ray *ray, double t);
int			get_color(t_color c);
int			color_obj(t_scene *scene, t_objects *ob);
void		check_hit(t_objects *ob, t_ray *ray, t_rec *rec);

/*
 * 	ft_sphere.c
 */
void		hit_sphere(t_sphere *sp, t_ray *ray, t_rec *rec);

/*
 * 	ft_plane.c
 */
void		hit_plane(t_plane *pl, t_ray *ray, t_rec *rec);

/*
 * 	ft_cylinder.c
 */
void		hit_cylinder(t_cylinder *cy, t_ray *ray, t_rec *rec);

/*
 * 	phong_lighting.c
 */
int			lighting(t_scene *scene, t_objects *ob);
t_color		point_light_get(t_scene *scene, t_light *light, t_objects *ob);
t_vec		reflect(t_vec v, t_vec n);
int			in_shadow(t_objects *ob, t_ray *ray, t_rec rec, double light_len);

/*
 * parse.c
 */
void	parse_mini_rt(char *filename, t_data *data);

#endif
