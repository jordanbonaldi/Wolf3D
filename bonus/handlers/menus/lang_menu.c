/*
** main_menu.c for wolf in /home/Neferett/wolf3d/bonus
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 13:23:22 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:18:42 2017 root
*/

# include "project.h"

static void	init_pos(t_wolf *wf)
{
  sfText_setPosition(wf->t1, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("PL_EN_X") :
					  get_int("PL_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("PL_EN_Y") :
					 get_int("PL_FR_Y")));
  sfText_setPosition(wf->t2, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("MBack_EN_X") :
					  get_int("MBack_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("MBack_EN_Y") :
					 get_int("MBack_FR_Y")));
}

static void	init_controls(t_wolf *wf)
{
  init_Color(wf);
  init_font(wf, 1);
  init_size(wf, 90);
  init_string_lang(wf);
  init_pos(wf);
  sfRenderWindow_setMouseCursorVisible(wf->wd, true);
  sfRenderWindow_setTitle(wf->wd, (get_int("Lang_Type") ?
                                   get_conf("Lang_Lang_EN") :
                                   get_conf("Lang_Lang_FR")));
}

static int		get_pos(int buttonx, int buttony)
{
  static	int pos;

  if (buttonx > 86 && buttonx < 898 && buttony > 338 && buttony < 427)
    return (pos = 0);
  else if (buttonx > 800 && buttonx < 1075 && buttony > 815 && buttony < 900)
    return (pos = 1);
  return (pos);
}
void            handle_lang_event(t_wolf *wf)
{
  sfEvent       event;

  init_controls(wf);
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      handle_close_event(wf, event);
      if (!wf->lang)
	break;
      if (event.type == sfEvtMouseMoved)
	wf->sel = get_pos(event.mouseMove.x, event.mouseMove.y);
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
	!wf->sel ? 1 : wf->sel--;
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
	wf->sel == 1 ? 1 : wf->sel++;
      handle_lang(wf, event);
    }
}
