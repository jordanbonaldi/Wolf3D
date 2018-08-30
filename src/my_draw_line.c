/*
** my_draw_line.c for wolf in /home/Neferett/wolf3d/src
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Tue Jan 24 22:32:50 2017 Bonaldi Jordan
** Last update Tue Jan 24 22:43:48 2017 root
*/

#include "project.h"

void                    vertical(t_my_framebuffer *framebuffer,
				    sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   i;
  int                   xinc;
  int                   yinc;
  int                   cumul;
  int                   x;
  int                   y;

  if ((!(x = from.x) ? 1 : 1) && (!(y = from.y) ? 1 : 1) &&
      (!(dx = to.x - from.x) ? 1 : 1) && (!(dy = to.y - from.y) ? 1 : 1) &&
      (xinc = (dx > 0) ? 1 : -1) && (yinc = (dy > 0) ? 1 : -1) &&
      (!(dx = abs(dx)) ? 1 : 1) && (!(dy = abs(dy)) ? 1 : 1)) {}
  my_put_pixel(framebuffer, x, y, color);
  if ((cumul = dy / 2) && !(i = 0)) {}
  while (++i <= dy)
    {
      y += yinc;
      cumul += dx;
      (cumul >= dy) ? cumul -= dy, x += xinc : 0;
      my_put_pixel(framebuffer, x, y, color);
    }
}
void                    horizontal(t_my_framebuffer *framebuffer,
				    sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   i;
  int                   xinc;
  int                   yinc;
  int                   cumul;
  int                   x;
  int                   y;

  if ((!(x = from.x) ? 1 : 1) && (!(y = from.y) ? 1 : 1) &&
      (!(dx = to.x - from.x) ? 1 : 1) && (!(dy = to.y - from.y) ? 1 : 1) &&
      (xinc = (dx > 0) ? 1 : -1) && (yinc = (dy > 0) ? 1 : -1) &&
      (!(dx = abs(dx)) ? 1 : 1) && (!(dy = abs(dy)) ? 1 : 1)) {}
  my_put_pixel(framebuffer, x, y, color);
  if ((cumul = dx / 2) && !(i = 0)) {}
  while (++i <= dx)
    {
      x += xinc;
      cumul += dy;
      (cumul >= dx) ? cumul -= dx, y += yinc : 0;
      my_put_pixel(framebuffer, x, y, color);
    }
}

void                    my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to, sfColor color)
{
  int                   dx;
  int                   dy;
  int                   x;
  int                   y;

  if ((!(x = from.x) ? 1 : 1) &&  (!(y = from.y) ? 1 : 1) &&
      (!(dx = to.x - from.x) ? 1 : 1) && (!(dy = to.y - from.y) ? 1 : 1) &&
      (!(dx = abs(dx)) ? 1 : 1) && (!(dy = abs(dy)) ? 1 : 1)) {}
  my_put_pixel(framebuffer, x, y, color);
  if (dx > dy)
    horizontal(framebuffer, from, to, color);
  else
    vertical(framebuffer, from, to, color);
}
