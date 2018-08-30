/*
** circle.c for wolf in /home/Neferett/wolf3d/bonus/handlers
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan 15 17:45:21 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:47:38 2017 Bonaldi Jordan
*/

# include "project.h"

void            draw_circle(t_wolf *wf)
{
  int		j;
  double	i;
  double	angle;
  int		x;
  int		y;
  double        radius;

  radius = 1;
  j = 0;
  while (++j <= 120)
    {
      radius = (j + 1);
      i = 0;
      while (i < 360.0)
	{
          angle = i * 3.14 / 180;
          x = (int)(get_coef_x(wf, 1) + radius * cos(angle));
          y = (int)(get_coef_y(wf, 1) + radius * sin(angle));
          my_put_pixel(wf->fb, x, y, wf->s5);
          x = (int)(get_coef_x(wf, 1) + (10 + j) * cos(angle));
          y = (int)(get_coef_y(wf, 1) + (10 + j) * sin(angle));
          my_put_pixel(wf->fb, x, y, wf->s6);
          i += 0.10;
        }
    }
}
