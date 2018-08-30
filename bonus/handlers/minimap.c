/*
** minimap.c for wolf in /home/Neferett/wolf3d
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Thu Jan 12 23:44:49 2017 root
** Last update Sun Jan 15 17:55:19 2017 Bonaldi Jordan
*/

# include "project.h"

int		get_coef_x(t_wolf *wf, int minimap)
{
  if (!wf->minimap || wf->minimap == 2)
    return (minimap ? 170 : 40);
  if (wf->minimap == 1 || wf->minimap == 3)
    return (minimap ? 1720 : 1590);
  return (10);
}

int		get_coef_y(t_wolf *wf, int minimap)
{
  if (!wf->minimap || wf->minimap == 1)
    return (minimap ? 170 : 90);
  if (wf->minimap == 2 || wf->minimap == 3)
    return (minimap ? 920 : 840);
  return (10);
}

void            draw_cage(t_my_framebuffer *fb, int x, int y, sfColor c)
{
  int           j;
  int           i;

  i = y - 1;
  while (++i < y + 30)
    {
      j = x - 1;
      while (++j < x + 30)
	my_put_pixel(fb, j, i, c);
    }
}

void		draw_line_int(t_wolf *wf, int line)
{
  int		x;
  int		y;
  int		i;

  i = wf->size.y;
  y =  wf->size.y + get_coef_y(wf, 0);
  while (--i > 0)
    {
      x = wf->size.x + line * 30 + get_coef_x(wf, 0);
      if (wf->map[i][line] == 2)
	draw_cage(wf->fb, (x += 30), y, wf->s4);
      else if (wf->map[i][line] == 1)
	draw_cage(wf->fb, (x += 30), y, wf->s5);
      else if (!wf->map[i][line])
	draw_cage(wf->fb, (x += 30), y, wf->s2);
      else if (wf->map[i][line] == 3)
	draw_cage(wf->fb, (x += 30), y, sfGreen);
      y += 30;
    }
}

void            minimap(t_wolf *wf)
{
  int		j;
  int		i;

  i = 0;
  draw_circle(wf);
  j = wf->map[(int)wf->player.x][(int)wf->player.y];
  wf->map[(int)wf->player.x][(int)wf->player.y] = 2;
  while (++i < wf->size.y - 1)
    draw_line_int(wf, i);
  wf->map[(int)wf->player.x][(int)wf->player.y] = j;
}
