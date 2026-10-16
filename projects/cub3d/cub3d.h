/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:29:22 by aielo             #+#    #+#             */
/*   Updated: 2026/03/02 14:19:09 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>

# define WND_NAME "cub3d"
# define WIDTH 800
# define HEIGHT 600
# define IMG_PXL 6
# define MINI_W 300
# define MINI_H 300

# define TEX_SIZE 64

# define FRAME_RATE_MS 33.33 // 16.67 - 33.33 - 50
# define SPEED 0.05

# define ERR_WRONG_INPUT "wrong input: ./cub3d <path/to/map.cub>"
# define ERR_WRONG_MAP "map file cannot be opened"
# define ERR_NO_VALIDATE "text cannot be validated"
# define ERR_PARSE_TEX "parsing texture error"
# define ERR_PARSE_COLOR "parsing color error"
# define ERR_PLAYER "parsing player error"
# define ERR_FLOOD "not all floor tiles are enclosed"
# define ERR_MALLOC "could not allocate memory"
# define ERR_MLX_START "could not start mlx"
# define ERR_MLX_IMG "could not create mlx image"

# define MAP_PLAYER_COLOR 0x27D3F5
# define MAP_WALL_COLOR 0xFF0000
# define MAP_FLOOR_COLOR 0xF54927
# define MAP_BG_COLOR 0x29402A
# define MAP_TRANSPARENT 0xFFFFF00

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**cc;
	char	**cf;
}	t_config;

typedef struct s_valid
{
	int	no;
	int	so;
	int	ea;
	int	we;
	int	cc;
	int	cf;
}	t_valid;

typedef enum e_tline
{
	NO_LINE,
	SO_LINE,
	EA_LINE,
	WE_LINE,
	CC_LINE,
	CF_LINE,
	MAP_LINE,
}	t_tline;

typedef struct s_ulines
{
	char			*line;
	t_tline			type;
	struct s_ulines	*next;
	int				pad;
	int				max;
}	t_ulines;

typedef struct s_rect
{
	int	x;
	int	y;
	int	size;
	int	color;
}	t_rect;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player;
	t_config	id;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_ray		ray;
	t_img		frame;
	t_img		minimap;
}	t_data;

#endif
