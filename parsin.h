#ifndef PARSIN_H

# define PARSIN_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define BMP "screenshot.bmp"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_w;
	int		tex_h;
}	t_tex;

typedef struct s_sprt
{
	double	x;
	double	y;
	int		dist;
}	t_sprt;

typedef struct s_sprite
{
	int		count;
	double	**buff;
	double	y;
	int		texture;
	t_sprt	*buf;
}	t_sprite;

typedef struct s_res
{
	int	x;
	int	y;
	int	keys;
}	t_res;

typedef struct s_NO
{
	char	*pt;		
}	t_NO;

typedef struct s_WE
{
	char	*pt;		
}	t_WE;

typedef struct s_SO
{
	char	*pt;		
}	t_SO;

typedef struct s_EA
{
	char	*pt;		
}	t_EA;

typedef struct s_F
{
	int	r;
	int	g;
	int	b;
}	t_F;

typedef struct s_C
{
	int	r;
	int	g;
	int	b;	
}	t_C;

typedef struct s_S
{
	char	*s;		
}	t_S;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}	t_win;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_plr
{
	double		x;
	double		y;
	double		dirX;
	double		dirY;
	double		end;
	double		planeX;
	double		planeY;
	int			fl;
}	t_plr;

typedef struct s_newc
{
	double			psX;
	double			psY;
	double			drX;
	double			drY;
	double			plneX;
	double			plneY;
	unsigned int	color;
	double			Zbuff[2560];
	int				numSprts;
	double			spOr[1000];
	double			sprtDist[1000];

}	t_newc;

typedef struct s_nr
{
	double	camX;
	double	rayDX;
	double	rayDY;
	int		mX;
	int		mY;
	double	sideDX;
	double	sideDY;
	double	deltaDX;
	double	deltaDY;
	double	pWalDst;
	int		stpX;
	int		stpY;
	int		hit;
	int		side;
	int		lnHgt;
	int		drStrt;
	int		drEnd;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	int		g;
	double	texPos;
	int		y;
}	t_nr;

typedef struct s_sps
{
	double	spX;
	double	spY;
	double	inD;
	double	tfX;
	double	tfY;
	int		ssx;
	int		vms;
	int		sH;
	int		dsY;
	int		deY;
	int		spW;
	int		dsX;
	int		deX;
}	t_sps;

typedef struct s_all
{
	t_sps		sps;
	t_nr		nr;
	t_newc		newc;
	t_win		win;
	t_plr		plr;
	char		**map;
	char		**only_m;
	t_res		res;
	t_F			F;
	t_point		point;
	t_NO		NO;
	t_WE		WE;
	t_EA		EA;
	t_SO		SO;
	t_C			C;
	t_S			S;
	int			save;
	t_img		img;
	t_tex		tex[6];
	t_sprt		sprt[5];
	t_sprite	sprite;

}	t_all;

void			move_forward(t_all *all);
void			move_right(t_all *all);
void			move_left(t_all *all);
void			move_back(t_all *all);
void			rotate_l(t_all *all);
void			bubbleSort(double *num, double *s, int size);
int				ft_close(t_all *all, int win);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
unsigned int	get_color(t_all *all, int x, int y, int i);
void			ft_clean_window(t_all *all, int f, int c);
int				newcub(t_all *all, int f, int c, int x);
int				rgb_to_int_f(t_all *all);
int				rgb_to_int_c(t_all *all);
void			print_map(t_all *all);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
int				pars_map(char **map, t_all *all, int i);
void			parse_sprite(t_all *all, int i, int j);
void			do_map(char **map, t_all *all, int j);
int				parse_player(t_all *all, int i, size_t j);
void			valid_map(t_all *all, int i, int j);
void			errors(int flag);
void			errors1(int flag);
void			errors2(int flag);
void			parse_r(char *map, t_all *all, int j);
void			parse_f(char *map, t_all *all, int j);
void			parsNo(char **map, t_all *all, int i);
void			parsWe(char **map, t_all *all, int i);
void			parsEa(char **map, t_all *all, int i);
void			parsSo(char **map, t_all *all, int i);
void			parsS(char **map, t_all *all, int i);
void			we_pos(t_all *all);
void			ea_pos(t_all *all);
void			so_pos(t_all *all);
void			no_pos(t_all *all);
void			check_view(t_all *all, int i, int j);
int				create_bmp(t_all *all);
void			initcub(t_all *all);
void			initrays(t_all *all, int x);
void			calcstep(t_all *all);
void			makestep(t_all *all);
void			calcdnheight(t_all *all);
void			textone(t_all *all);
void			textother(t_all *all);
void			textonwall(t_all *all);
void			startsprt(t_all *all, int x);
void			sortsprite(t_all *all);
int				key_press(int key, t_all *all);
void			textinit0(t_all *all);
void			textinit1(t_all *all);
void			checktext(t_all *all);
int				skip_space(char *str, int i);
void			keysinit(t_all *all);
void			checkcolorfa(t_all *all);
void			checkcolorca(t_all *all);
void			checkcolorf(t_all *all);
void			checkcolorc(t_all *all);

#endif