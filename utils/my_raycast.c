/*
** raycast.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:29:54 2017 Bonaldi Jordan
** Last update Tue Jan 10 15:55:02 2017 Bonaldi Jordan
*/

# include "project.h"

float		my_raycast(t_wolf *wolf, int i)
{
  float		distance;
  int		x;
  int		y;

  wolf->xray.x = 0.5 * cos(to_rad(wolf->angle)) -
    ((wolf->fb->width / 2 - (double)i) / wolf->fb->width)
    * sin(to_rad(wolf->angle));
  wolf->xray.y = 0.5 * sin(to_rad(wolf->angle))
    + ((wolf->fb->width / 2 - (double)i) / wolf->fb->width)
    * cos(to_rad(wolf->angle));
  distance = 1;
  x = wolf->player.x + wolf->xray.x;
  y = wolf->player.y + wolf->xray.y;
  while (check_pos(wolf, set_fvector((float)x, (float)y)))
    {
      distance += 0.005;
      x = wolf->player.x + distance * wolf->xray.x;
      y = wolf->player.y + distance * wolf->xray.y;
    }
  return (distance);
}
