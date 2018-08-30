/*
** drawer.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Tue Jan  3 16:08:44 2017 Bonaldi Jordan
** Last update Tue Jan 10 15:46:19 2017 Bonaldi Jordan
*/

# include "project.h"

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
}

void	drawer(t_wolf *wolf)
{
  int   x;

  x = -1;
  while (++x <= wolf->fb->width / 2)
    my_draw_line(wolf->fb, set_vector(0, x), set_vector(1920, x), sfBlue);
  x = (wolf->fb->height / 2) - 1;
  while (++x <= wolf->fb->height)
    my_draw_line(wolf->fb, set_vector(0, x), set_vector(1920, x), sfWhite);
}

void		wall(t_wolf *wolf, double dis, int x)
{
  int		c = (dis * 200)/wolf->fb->width + 55;
  my_draw_line(wolf->fb, set_vector(x, wolf->fb->height / 2),
	       set_vector(x, (wolf->fb->height / 2)
			  + (wolf->fb->height / (2 * dis))), set_color(c, c, c));
  my_draw_line(wolf->fb, set_vector(x, (wolf->fb->height / 2) -
				    wolf->fb->height / (2 * dis)),
	       set_vector(x, (wolf->fb->height / 2)), set_color(c, c, c));
}
