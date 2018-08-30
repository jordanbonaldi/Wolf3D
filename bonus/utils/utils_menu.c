/*
** utils_menu.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sat Jan 14 22:58:11 2017 Bonaldi Jordan
** Last update Sun Jan 15 18:17:24 2017 Bonaldi Jordan
*/

# include "project.h"

void		init_font(t_wolf *wf, int i)
{
  sfText_setFont(wf->t1, i ? wf->font2 : wf->font);
  sfText_setFont(wf->t2, i ? wf->font2 : wf->font);
  sfText_setFont(wf->t3, i ? wf->font2 : wf->font);
  sfText_setFont(wf->t4, i ? wf->font2 : wf->font);
  if (wf->position)
    sfText_setFont(wf->t5, wf->font2);
  else
    sfText_setFont(wf->t5, i ? wf->font2 : wf->font);
  sfText_setFont(wf->t6, i ? wf->font2 : wf->font);
  sfText_setFont(wf->t7, i ? wf->font2 : wf->font);
}

void		init_Color(t_wolf *wf)
{
  sfText_setColor(wf->t1, !wf->sel ? sfRed : sfWhite);
  sfText_setColor(wf->t2, wf->sel == 1 ? sfRed : sfWhite);
  sfText_setColor(wf->t3, wf->sel == 2 ? sfRed : sfWhite);
  sfText_setColor(wf->t4, wf->sel == 3 ? sfRed : sfWhite);
  if (wf->position)
    sfText_setColor(wf->t5, sfRed);
  else
    sfText_setColor(wf->t5, wf->sel == 4 ? sfRed : sfWhite);
  sfText_setColor(wf->t6, wf->sel == 5 ? sfRed : sfWhite);
  sfText_setColor(wf->t7, wf->sel == 6 ? sfRed : sfWhite);
}

void		init_size(t_wolf *wf, int size)
{
  sfText_setCharacterSize(wf->t1, size);
  sfText_setCharacterSize(wf->t2, size);
  sfText_setCharacterSize(wf->t3, size);
  sfText_setCharacterSize(wf->t4, size);
  if (wf->position)
    sfText_setCharacterSize(wf->t5, get_int("Size_Current_Level"));
  else
    sfText_setCharacterSize(wf->t5, size);
  sfText_setCharacterSize(wf->t6, size);
  sfText_setCharacterSize(wf->t7, size);
}

void		init_sfcolor(t_wolf *wf)
{
  wf->s1 = sky_color();
  wf->s2 = gr_color();
  wf->s3 = set_color(get_int("L1_ColorWall.R"),
		     get_int("L1_ColorWall.G"),
                     get_int("L1_ColorWall.B"));
  wf->s4 = set_color(get_int("MiniMap_Player_Color.R"),
		     get_int("MiniMap_Player_Color.G"),
                     get_int("MiniMap_Player_Color.B"));
  wf->s5 = set_color(get_int("MiniMap_BG_Color.R"),
		     get_int("MiniMap_BG_Color.G"),
                     get_int("MiniMap_BG_Color.B"));
  wf->s6 = set_color(get_int("MiniMap_Circle_Color.R"),
		     get_int("MiniMap_Circle_Color.G"),
                     get_int("MiniMap_Circle_Color.B"));
}

void		handle_close_event(t_wolf *wf, sfEvent event)
{
  if (event.type == sfEvtClosed)
    sfRenderWindow_close(wf->wd);
  if (event.type == sfEvtKeyPressed &&
      ((event.key.code == sfKeyEscape ||
	(event.key.code == sfKeyReturn &&
	 wf->sel == (wf->settings ? 3 : wf->controls
		     ? 4 : wf->lang ? 1 : 2))) ||
       (event.type == sfEvtMouseButtonPressed &&
	event.mouseButton.button == sfMouseLeft &&
	wf->sel == (wf->settings ? 3 : wf->controls ? 4 : wf->lang ? 1 : 2))))
    {
      if (wf->settings && !(wf->settings = false) && !(wf->sel = 0)) {}
      else if (wf->controls && !(wf->controls = false)
	       && (wf->settings = true) && !(wf->sel = 0)) {}
      else if (wf->position && (wf->settings = true)
	       && !(wf->position = false) && !(wf->sel = 0)) {}
      else if (wf->lang && (wf->settings = true) &&
	       !(wf->lang = false) && !(wf->sel = 0)) {}
      else
	sfRenderWindow_close(wf->wd);
    }
}
