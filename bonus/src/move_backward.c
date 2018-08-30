/*
** move_forward.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:09:52 2017 Bonaldi Jordan
** Last update Tue Jan 10 15:47:31 2017 Bonaldi Jordan
*/

# include "project.h"

sfVector2f		move_backward(sfVector2f pos, float dir, float dis)
{
  sfVector2f		vector;

  vector.x = pos.x - dis * cos(dir * (M_PI / 180));
  vector.y = pos.y - dis * sin(dir * (M_PI / 180));
  return (vector);
}
