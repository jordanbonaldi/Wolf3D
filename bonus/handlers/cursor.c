/*
** cursor.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Fri Jan 13 23:52:07 2017 root
** Last update Sun Jan 15 17:44:38 2017 root
*/

# include "project.h"

void	draw_cursor2(t_wolf *wf)
{
  int	i;

  i = -1;
  while (++i < 4)
    my_draw_line(wf->fb, set_vector((wf->fb->width / 2) + 6,
				    (wf->fb->height / 2) + i),
  		 set_vector((wf->fb->width / 2) + 26,
			    (wf->fb->height / 2) + i), sfBlack);
  i = -1;
  while (++i < 4)
    my_draw_line(wf->fb, set_vector((wf->fb->width / 2) + i,
				    (wf->fb->height / 2) + 6),
		 set_vector((wf->fb->width / 2) + i,
			    (wf->fb->height / 2) + 26), sfBlack);
}

void	draw_cursor(t_wolf *wf)
{
  int	i;

  i = -1;
  while (++i < 4)
    my_draw_line(wf->fb, set_vector((wf->fb->width / 2) + i,
				    (wf->fb->height / 2) - 4),
		 set_vector((wf->fb->width / 2) + i,
			    (wf->fb->height / 2) - 25), sfBlack);
  i = -1;
  while (++i < 4)
    my_draw_line(wf->fb, set_vector((wf->fb->width / 2) - 2,
				    (wf->fb->height / 2) + i),
		 set_vector((wf->fb->width / 2) - 23,
			    (wf->fb->height / 2) + i), sfBlack);
  draw_cursor2(wf);
}
