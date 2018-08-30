/*
** player_handler.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Jan  5 20:10:36 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:28:33 2017 Bonaldi Jordan
*/

# include "project.h"

void		teleport_pos(t_wolf *wf, sfVector2f player)
{
  if (wf->map[(int)player.x][(int)player.y] == 3)
    {
      set_conf("WCurrentLevel", get_int("WCurrentLevel") == 5 ? "1"
	       : my_itoa(get_int("WCurrentLevel") + 1));
      wf->filename = get_int("WCurrentLevel") == 1 ? "MAPS/map.w3" :
	get_int("WCurrentLevel") == 2 ? "MAPS/map2.w3" :
	get_int("WCurrentLevel") == 3 ? "MAPS/map3.w3" :
	get_int("WCurrentLevel") == 4 ? "MAPS/map4.w3" : "MAPS/map5.w3";
      file_manager(wf);
      set_conf("Player_Angle", "250");
      if (get_int("WCurrentLevel") == 1)
	{
	  set_conf("Player_Pos_X", "1");
	  set_conf("Player_Pos_Y", "1");
	}
      else
	{
	  set_conf("Player_Pos_X", get_int("WCurrentLevel") == 4
		   || get_int("WCurrentLevel") == 5 ? "4" : "5");
	  set_conf("Player_Pos_Y", "4");
	}
      wf->player = set_fvector(get_int("Player_Pos_X") + 0.5,
			       get_int("Player_Pos_Y") + 0.5);
    }
}

Boolean		check_pos(t_wolf *wolf, sfVector2f player)
{
  return (player.x > -1 && player.y > -1 &&
	  player.x < wolf->size.x && player.y < wolf->size.y &&
	  wolf->map[(int)player.x][(int)player.y] != wolf->wall);
}
