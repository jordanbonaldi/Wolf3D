/*
** my_put_pixel.c for wolf in /home/Neferett/wolf3d/src
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 22:07:18 2017 Bonaldi Jordan
** Last update Mon Jan  2 10:22:37 2017 Bonaldi Jordan
*/

# include "project.h"

void	my_put_pixel(t_my_framebuffer *fb, int x, int y, sfColor color)
{
  if (x >= 0 && y >= 0 && x < fb->width && y < fb->height)
    {
      fb->pixels[((fb->width * y) + x) * 4] = color.r;
      fb->pixels[((fb->width * y) + x) * 4 + 1] = color.g;
      fb->pixels[((fb->width * y) + x) * 4 + 2] = color.b;
      fb->pixels[((fb->width * y) + x) * 4 + 3] = color.a;
    }
}
