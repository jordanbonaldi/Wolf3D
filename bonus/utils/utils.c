/*
** utils.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 22:19:08 2017 Bonaldi Jordan
** Last update Fri Jan  6 11:49:51 2017 Bonaldi Jordan
*/

# include "project.h"

sfVideoMode     set_mode(int w, int h, int bpp)
{
  sfVideoMode   mode;

  mode.width = w;
  mode.height = h;
  mode.bitsPerPixel = bpp;
  return (mode);
}

sfColor		set_color(int r, int g, int b)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  return (color);
}

float		to_rad(float angle)
{
  return (angle * (M_PI / 180));
}

sfVector2i      set_vector(int x, int y)
{
  sfVector2i    vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

sfVector2f      set_fvector(float x, float y)
{
  sfVector2f    vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}
