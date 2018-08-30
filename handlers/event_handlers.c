/*
** event_handlers.c for wolf in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Jan  9 16:55:11 2017 Bonaldi Jordan
** Last update Tue Jan 10 15:43:55 2017 Bonaldi Jordan
*/

# include "project.h"

void		key_event(t_wolf *wf, sfEvent event)
{
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      if (event.type == sfEvtMouseMoved)
  	wf->angle += event.mouseMove.x > 960 ? -1 : 1;
      if (event.type == sfEvtClosed ||
  	  (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
  	sfRenderWindow_close(wf->wd);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ)
  	if (check_pos(wf, move_forward(wf->player, wf->angle, 0.25)))
  	  wf->player = move_forward(wf->player, wf->angle, 0.25);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
  	if (check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
  	  wf->player = move_backward(wf->player, wf->angle, 0.25);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)
  	if (check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
  	  wf->player = move_left(wf->player, wf->angle, 0.25);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD)
  	if (check_pos(wf, move_backward(wf->player, wf->angle, 0.25)))
  	  wf->player = move_right(wf->player, wf->angle, 0.25);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
  	wf->angle += 3;
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
  	wf->angle -= 3;
    }
}
