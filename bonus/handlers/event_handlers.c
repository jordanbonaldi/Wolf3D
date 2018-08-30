/*
** event_handlers.c for wolf in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  9 16:55:11 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:59:04 2017 Bonaldi Jordan
*/

# include "project.h"

void		angle_move_event(t_wolf *wf, sfEvent event)
{
  if (event.type == sfEvtMouseMoved)
    wf->angle += event.mouseMove.x > 960 ? -get_int("AngleMouseEvt") :
      get_int("AngleMouseEvt");
  if (event.type == sfEvtKeyPressed && event.key.code == wf->key_l)
    wf->angle += get_int("AngleArrow");
  if (event.type == sfEvtKeyPressed && event.key.code == wf->key_r)
    wf->angle -= get_int("AngleArrow");
}

void		close_event(t_wolf *wf, sfEvent event)
{
  char		*str;

  if (!(str = malloc(12)))
    exit(84);
  if (event.type == sfEvtClosed ||
      (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
    {
      set_conf("Player_Angle", my_itoa((int)wf->angle));
      set_conf_char("Player_Pos_X", (int)wf->player.x + 48);
      set_conf_char("Player_Pos_Y", (int)wf->player.y + 48);
      wf->game = false;
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(wf->wd);
    }
}

void		key_event(t_wolf *wf, sfEvent event)
{
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      angle_move_event(wf, event);
      close_event(wf, event);
      if (event.type == sfEvtKeyPressed && event.key.code == wf->key_z &&
	  check_pos(wf, move_forward(wf->player, wf->angle, 0.25)))
	wf->player = move_forward(wf->player, wf->angle, 0.25);
      else if (event.type == sfEvtKeyPressed && event.key.code == wf->key_s &&
	       check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
	wf->player = move_backward(wf->player, wf->angle, 0.25);
      else if (event.type == sfEvtKeyPressed && event.key.code == wf->key_q
	       && check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
	wf->player = move_left(wf->player, wf->angle, 0.25);
      else if (event.type == sfEvtKeyPressed && event.key.code == wf->key_d &&
	       check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
	wf->player = move_right(wf->player, wf->angle, 0.25);
    }
  teleport_pos(wf, wf->player);
}
