/*
** project.h for project_header in /home/Neferett/bin/IMPORT/include
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 21 01:13:04 2016 Bonaldi Jordan
** Last update Sun Jan 15 17:55:45 2017 root
*/

#ifndef H_CHECK
# define H_CHECK

#ifndef READ_SIZE
# define READ_SIZE 2
#endif

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
  int			minimap;
  t_my_framebuffer	*fb;
  sfVector2f		xray;
  Boolean		game;
  char			*language;
  char			*mpp;
  char			*clp;
  char			*kz;
  char			*ks;
  char			*kq;
  char			*kd;
  Boolean		controls;
  Boolean		lang;
  Boolean		position;
  Boolean		settings;
  char			*title_game;
  char			*title_menu;
  int			key_s;
  int			key_z;
  int			key_q;
  int			key_d;
  int			key_l;
  int			key_r;
  sfText		*t1;
  sfColor		s1;
  sfColor		s2;
  sfColor		s3;
  sfColor		s4;
  sfColor		s5;
  sfColor		s6;
  sfText		*t2;
  sfText		*t3;
  sfText		*t4;
  sfText		*t5;
  sfText		*t6;
  sfText		*t7;
  sfFont		*font;
  sfFont		*font2;
  int			sel;
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

char		*get_conf(char *);
void		set_conf(char *, char *);
t_wolf		*initialiser();
void		file_manager(t_wolf *);
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
void		handle_menu_event(t_wolf *);
char		*get_conf(char *);
void		set_conf(char *, char *);
sfColor		sky_color();
sfColor		gr_color();
int		get_int(char *);
void		minimap(t_wolf *);
void		set_conf_char(char *, char);
char		*convert_nb(int, Boolean);
void		draw_cursor(t_wolf *wf);
void		init_Color(t_wolf *wf);
void		init_size(t_wolf *wf, int);
void		init_font(t_wolf *wf, int);
void		init_sfcolor(t_wolf *wf);
void		handle_settings_event(t_wolf *wf);
void		handle_close_event(t_wolf *wf, sfEvent);
void		init_string(t_wolf *wf);
void		init_string_mp(t_wolf *wf);
void		handle_controls_event(t_wolf *wf);
void		handle_key_create(t_wolf *wf, sfEvent);
char		*my_strcatc(char *, char);
void		handle_position(t_wolf *, sfEvent);
void		handle_position_event(t_wolf *);
void		draw_circle(t_wolf *wf);
sfVector2f	get_right_pos();
Boolean		reset_pixel(t_wolf *wf);
void		draw_text(t_wolf *wf);
void		handle_lang_event(t_wolf *);
void		handle_lang(t_wolf *, sfEvent);
void		init_string_lang(t_wolf *wf);
void		teleport_pos(t_wolf *wf, sfVector2f);
int		get_coef_x(t_wolf *wf, int);
int		get_coef_y(t_wolf *wf, int);

#endif
