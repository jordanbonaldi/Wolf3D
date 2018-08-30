/*
** player_handler.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Jan  5 20:10:36 2017 Bonaldi Jordan
** Last update Fri Jan  6 13:56:42 2017 Bonaldi Jordan
*/

# include "project.h"

Boolean		check_pos(t_wolf *wolf, sfVector2f player)
{
  return (player.x > -1 && player.y > -1 &&
	  player.x < wolf->size.x && player.y < wolf->size.y &&
	  wolf->map[(int)player.x][(int)player.y] != wolf->wall);
}
