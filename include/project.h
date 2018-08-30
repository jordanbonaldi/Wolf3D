/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Jan 15 21:31:54 2017 root
*/

#ifndef H_CHECK
# define H_CHECK

# include <sys/stat.h>
# include <fcntl.h>
# include <SFML/Graphics.h>
# include <math.h>
# include "lib.h"

# define ABS(x)	((x < 0) ? -x : x)

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_wolf
{
  t_my_framebuffer	*fb;
  sfVector2f		xray;
  int			stop;
  int			wall;
  float			angle;
  int			vo;
  sfVector2f		player;
  int			fd;
  float			distance;
  int			read;
  int			**map;
  sfVector2f		pos;
  float			dir;
  sfVector2i		size;
  char			*format;
  char			*buf;
  char			*filename;
  sfVideoMode		mode;
  sfRenderWindow	*wd;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_wolf;

t_wolf		*initialiser(char **, char *, int, int);
Boolean		file_manager(t_wolf *);
int		**convert_map(t_wolf *);
void		init_window(t_wolf *);
void		display_window(t_wolf *);
void		key_event(t_wolf *, sfEvent);
sfVector2i	set_vector(int, int);
sfVector2f	set_fvector(float, float);
sfColor		set_color(int, int, int);
sfVideoMode	set_mode(int, int, int);
void		my_draw_line(t_my_framebuffer *, sfVector2i, sfVector2i, sfColor);
void		my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector2f	move_forward(sfVector2f, float, float);
sfVector2f	move_left(sfVector2f, float, float);
sfVector2f	move_right(sfVector2f, float, float);
sfVector2f	move_backward(sfVector2f, float, float);
float		raycast(sfVector2f, float, int **, sfVector2i);
float		my_raycast(t_wolf *, int);
float		to_rad(float);
void		draw_all(t_wolf *);
void		wall(t_wolf *, double, int);
void		drawer(t_wolf *);
void		calcul(t_wolf *);
Boolean		check_pos(t_wolf *, sfVector2f);

#endif
