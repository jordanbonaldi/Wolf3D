/*
** drawer.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Tue Jan  3 16:08:44 2017 Bonaldi Jordan
** Last update Fri Jan 13 23:56:28 2017 Bonaldi Jordan
*/

# include "project.h"

sfColor		sky_color()
{
  return (set_color(get_int("ColorSky.R"),
		    get_int("ColorSky.G"),
		    get_int("ColorSky.B")));
}

sfColor		gr_color()
{
  return (set_color(get_int("ColorGround.R"),
		    get_int("ColorGround.G"),
		    get_int("ColorGround.B")));
}

void	draw_all(t_wolf *wolf)
{
  int	i;

  i = -1;
 drawer(wolf);
 while (++i < wolf->fb->width)
    {
      wolf->distance = my_raycast(wolf, (float)i);
      wall(wolf, wolf->distance, i);
    }
 minimap(wolf);
 draw_cursor(wolf);
}

void		drawer(t_wolf *wolf)
{
  int   x;

  x = -1;
  while (++x <= wolf->fb->width / 2)
    my_draw_line(wolf->fb, set_vector(0, x), set_vector(1920, x), wolf->s1);
  x = (wolf->fb->height / 2) - 1;
  while (++x <= wolf->fb->height)
    my_draw_line(wolf->fb, set_vector(0, x), set_vector(1920, x), wolf->s2);
}

void		wall(t_wolf *wolf, double dis, int x)
{
  my_draw_line(wolf->fb, set_vector(x, wolf->fb->height / 2),
	       set_vector(x, (wolf->fb->height / 2)
			  + (wolf->fb->height / (2 * dis))), wolf->s3);
  my_draw_line(wolf->fb, set_vector(x, (wolf->fb->height / 2) -
				    wolf->fb->height / (2 * dis)),
	       set_vector(x, (wolf->fb->height / 2)), wolf->s3);
}
