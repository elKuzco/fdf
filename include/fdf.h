/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:22:15 by qlouisia          #+#    #+#             */
/*   Updated: 2019/02/06 12:45:53 by qlouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

typedef	struct		s_lst_cd
{
	int				x;
	int				y;
	int				z;
	unsigned char	rcolor;
	unsigned char	gcolor;
	unsigned char	bcolor;
	double			c_x;
	double			c_y;
	double			c_z;
	struct s_lst_cd	*upon;
	struct s_lst_cd	*next;
}					t_lst_coord;

typedef struct		s_list_fdf
{
	t_bool			color_mode;
	int				column;
	int				line;
	int				max_z;
	int				min_z;
	double			middle;
	int				coef_x;
	int				coef_y;
	int				coef_z;
	int				center_x;
	int				center_y;
	int				x;
	int				y;
	double			rotz;
	double			roty;
	double			rotx;
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	t_lst_coord		*first;
	t_lst_coord		*lst;
	void			*mlx_ptr;
	void			*win_ptr;
	int				w_width;
	int				w_height;

}					t_lst_env;

int					draw_line(t_lst_coord *point1, t_lst_coord *point2,
					t_lst_env **img);
int					create_env(t_lst_env **env);
void				window_size(t_lst_env **env);
int					create_lst(t_lst_coord **first, t_lst_coord **lst);
int					create_window(t_lst_env **env, char *av);
int					create_matrice(int fd, t_lst_env **env);
int					free_map(t_lst_env **env);
int					free_parsing(int *test, char *line);
int					*free_tab(char **str, int size);
int					draw_grid(t_lst_env **env);
void				refresh_image(t_lst_env **env);
void				rotation_axis_z(t_lst_coord *point, double angle, int width,
					int height);
void				rotation_axis_y(t_lst_coord *point, double angle);
void				rotation_axis_x(t_lst_coord *point, double angle);
void				translation(t_lst_coord *point, t_lst_env **env);
void				scale_up(t_lst_coord *point, t_lst_env **env);
void				parallele(t_lst_coord *point, t_lst_env **env);
void				set_color_gradient(t_lst_coord *ptr, t_lst_env **env);
int					choice_color(t_lst_coord *pt1, t_lst_coord *pt2, int coef,
					double ratio);
void				zoom(int keycode, t_lst_env **param);
void				move(int keycode, t_lst_env **param);
void				rotate(int keycode, t_lst_env **param);
void				automatic_view(int keycode, t_lst_env **param);
int					quit_program(t_lst_env **param);
unsigned int		convert_rgb(unsigned int a, unsigned int r, unsigned int g,
					unsigned int b);

#endif
