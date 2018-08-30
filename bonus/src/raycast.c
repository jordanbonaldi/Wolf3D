/*
** raycast.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Fri Jan  6 14:22:38 2017 Bonaldi Jordan
** Last update Fri Jan  6 16:35:00 2017 Bonaldi Jordan
*/

# include "project.h"

float		raycast(sfVector2f pos, float dir, int **map, sfVector2i size)
{
  sfVector2f	p;
  float		d;

  d = 0;
  p = move_forward(pos, dir, 0);
  while (p.x > -1 && p.x < size.x && p.y > -1 &&
	 p.y < size.y && map[(int)p.y][(int)p.x] != 1)
    {
      d += 0.001;
      p = move_forward(pos, dir, d);
    }
  return (d - 0.001);
}
