/*
** utils_menu2.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Sun Jan 15 13:49:03 2017 root
** Last update Sun Jan 15 15:41:02 2017 root
*/

# include "project.h"

void		draw_text(t_wolf *wf)
{
  sfRenderWindow_drawText(wf->wd, wf->t1, NULL);
  sfRenderWindow_drawText(wf->wd, wf->t2, NULL);
  if (!wf->lang)
    sfRenderWindow_drawText(wf->wd, wf->t3, NULL);
  if (wf->settings || wf->controls)
    {
      sfRenderWindow_drawText(wf->wd, wf->t4, NULL);
      sfRenderWindow_drawText(wf->wd, wf->t5, NULL);
      sfRenderWindow_drawText(wf->wd, wf->t6, NULL);
    }
  else if (wf->position)
    sfRenderWindow_drawText(wf->wd, wf->t5, NULL);
}

Boolean		reset_pixel(t_wolf *wf)
{
  int		i;

  i = -1;
  while (++i < wf->fb->width * wf->fb->height * 4)
    wf->fb->pixels[i] = 0;
  return (true);
}
