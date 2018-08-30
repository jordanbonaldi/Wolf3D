/*
** move_forward.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:09:52 2017 Bonaldi Jordan
** Last update Mon Jan  9 16:47:27 2017 Bonaldi Jordan
*/

# include "project.h"

sfVector2f		move_right(sfVector2f pos, float direction, float distance)
{
  sfVector2f		vector;

  vector.x = pos.x + distance * cos((direction * (M_PI / 180)) - M_PI / 2);
  vector.y = pos.y + distance * sin((direction * (M_PI / 180)) - M_PI / 2);
  return (vector);
}
