/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:10:50 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/20 15:54:47 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "../utils/getnextline/get_next_line.h"
# include "../utils/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define SCREEN_W 1280
# define SCREEN_H 720

// adarolla

typedef struct s_textures
{
	char			*so;
	char			*no;
	char			*ea;
	char			*we;
	int				floor;
	int				celling;
}					t_textures;

typedef struct s_sprite
{
	double			x;
	double			y;
	int				type;
	int				state;
}					t_sprite;

// mabenois
typedef struct s_ray
{
	double	ray_dir;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	int		map_val;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	len;
	double	fixed_len;
	int		wall_orientation;	// N E S W
	double	texture_x;
}	t_ray;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img_data;

typedef struct s_map
{
	int		*tiles;
	int		size_x;
	int		size_y;
	int		nb_elements;
	int		scale;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	smooth_x;
	double	smooth_y;
	double	dir;
	double	screen_dist;
	double	screen_vec_dir;
	double	screen_vec_len;
	double	fov;
}	t_player;

typedef struct s_render
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_render;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img_data	*frame_img;
	t_img_data	*texture_n;
	t_img_data	*texture_e;
	t_img_data	*texture_s;
	t_img_data	*texture_w;
	int			win_width;
	int			win_height;
	t_map		*level;
	t_player	*player;
	t_render	*render;
	int			init_failed;
	int			ceil;
	int			floor;
}	t_vars;

typedef struct s_game
{
	t_vars			*vars;
	char			**map;
	int				map_width;
	int				map_height;
	double			player_x;
	double			player_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				player_dir;
	t_sprite		*sprites;
	int				num_sprites;
	void			*mlx;
	void			*win;
	t_textures		*textures;
	struct s_game	*next;
}					t_game;

//	ft_images
int				create_trgb(int t, int r, int g, int b);
t_img_data		*ft_new_img(void *mlx, int width, int height);
void			ft_free_img(void *mlx, t_img_data *img);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_img_data *data, int x, int y);
void			ft_clear_img(t_img_data *data, int width,
					int height, int color);
void			ft_image_draw_rec(t_img_data *data, int *i);
void			ft_image_draw_circle(t_img_data *data, int *i);

t_img_data		*ft_alloc_img_data(void);

//	ft_utils.c
float			ft_int_coord_dist(int x1, int y1, int x2, int y2);
double			ft_double_coord_dist(double x1, double y1,
					double x2, double y2);
int				ft_int_error(char *msg, int ret);
void			*ft_error(char *msg);

//	ft_map.c
t_map			*ft_generate_empty_map(int w, int h);
int				ft_map_set_value(t_vars *vars, int x, int y, int val);
int				ft_map_get_value(t_vars *vars, int x, int y);
void			ft_draw_minimap(t_vars *vars);

//	ft_raycast.c
void			ft_raycast(t_vars *vars);

void			ft_draw_ray_hitpoint(t_vars *vars, t_ray *shortest);
void			ft_raycast_vert_ray(t_vars *vars, t_ray *r, double dir);
void			ft_correct_dir(double *dir);
void			ft_raycast_calculate_screen(t_vars *vars, double *screen_x,
					double *screen_y, int i);
int				ft_darken_color(int color, int value);
double			ft_abs(double val);
void			ft_raycast_hori_travel_ray(t_vars *vars, t_ray *r,
					double oriented_down);
double			ft_raycast_hori_ray_first(t_vars *vars, t_ray *r, double dir);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

int				ft_load_textures(t_game *game, t_vars *vars);
t_vars			*ft_init_vars(t_game *game, int width, int height, char *title);
void			ft_destroy_vars(t_vars *vars);

t_map			*ft_convert_map(t_game *game);
t_render		*ft_create_render(int x, int y, int w, int h);

int				my_mouse_hook(int button, int x, int y, void *param);
int				my_key_hook(int keycode, void *param);
int				update_hook(void *param);
int				ft_close_window(void *param);

//	ft_player.c
void			ft_player_move(t_vars *vars, double x, double y);
void			ft_player_rotate(t_vars *vars, double radians);
void			ft_update_player_rotation(t_vars *vars,
					int keycode, double rot_speed);
void			ft_update_player_movement(t_vars *vars,
					int keycode, double player_speed);
void			ft_draw_player(t_vars *vars);
t_player		*ft_create_player(t_vars *vars, double x, double y, double dir);
double			ft_rotate_dir(double dir, double radians);

int				parse_data(char *filename, t_game *game);
int				init_textures(t_game *game);
int				check_path(t_game *game);
int				get_map(t_game *game, int fd, char *first_line);
int				parse_map(t_game *game, int x, int y, int player_count);
int				is_closed_by_walls(char **map);
int				all_data_collected(t_game *game);
int				verify_filename(char *filename);
int				take_rgb_colors(char *line);
int				compare_identifier(char *line, t_game *game, int i, int res);
int				parse_file(t_game *game, char *filename);
int				init_engine(t_game *game);
void			init_player_camera(t_game *game);
int				init_sprites(t_game *game);
void			free_double(char **map);
void			free_textures(t_textures *textures);
void			clean_gnl(int fd);
int				init_engine(t_game *game);

#endif
