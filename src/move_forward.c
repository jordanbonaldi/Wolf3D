/*
** move_forward.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:09:52 2017 Bonaldi Jordan
** Last update Fri Jan  6 14:05:34 2017 Bonaldi Jordan
*/

# include "project.h"

sfVector2f		move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f		vector;

  vector.x = pos.x + distance * cos(direction * (M_PI / 180));
  vector.y = pos.y + distance * sin(direction * (M_PI / 180));
  return (vector);
}
