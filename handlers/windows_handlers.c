/*
** windows_handlers.c for wolf3d in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  1 19:52:04 2017 Bonaldi Jordan
** Last update Sun Jan 15 21:37:49 2017 root
*/

# include "project.h"

void    init_window(t_wolf *wf)
{
  if (!(wf->sprite = sfSprite_create()) ||
      !(wf->texture = sfTexture_create(wf->fb->width, wf->fb->height)))
    return;
  sfSprite_setTexture(wf->sprite, wf->texture, sfTrue);
  wf->mode = set_mode(wf->fb->width, wf->fb->height, 32);
  if (!(wf->wd = sfRenderWindow_create(wf->mode, "Wolf3D",
				   sfResize | sfClose, NULL)))
    return;
  display_window(wf);
}

void		display_window(t_wolf *wf)
{
  sfEvent	event;

  draw_all(wf);
  while (sfRenderWindow_isOpen(wf->wd))
    {
      sfTexture_updateFromPixels(wf->texture,
				 wf->fb->pixels, wf->fb->width, wf->fb->height, 0, 0);
      key_event(wf, event);
      draw_all(wf);
      sfRenderWindow_clear(wf->wd, sfBlack);
      sfRenderWindow_drawSprite(wf->wd, wf->sprite, NULL);
      sfRenderWindow_display(wf->wd);
    }
  sfRenderWindow_destroy(wf->wd);
}
