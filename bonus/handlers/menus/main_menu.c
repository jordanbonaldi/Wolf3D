/*
** main_menu.c for wolf in /home/Neferett/wolf3d/bonus
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 13:23:22 2017 Bonaldi Jordan
** Last update Sun Jan 15 00:59:34 2017 root
*/

# include "project.h"

void	init_pos(t_wolf *wf)
{
  sfText_setPosition(wf->t1, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Single_EN_X") :
					  get_int("Single_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Single_EN_Y") :
					 get_int("Single_FR_Y")));
  sfText_setPosition(wf->t2, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Set_EN_X") :
					  get_int("Set_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Set_EN_Y") :
					 get_int("Set_FR_Y")));
  sfText_setPosition(wf->t3, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Q_EN_X") :
					  get_int("Q_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Q_EN_Y") :
					 get_int("Q_FR_Y")));
}

void	init_menu(t_wolf *wf)
{
  init_font(wf, 0);
  init_size(wf, 150);
  init_Color(wf);
  sfText_setString(wf->t1, get_int("Lang_Type") ? get_conf("Lang_EN_Single"):
		   get_conf("Lang_FR_Single"));
  sfText_setString(wf->t2, get_int("Lang_Type") ? get_conf("Lang_EN_Settings"):
		   get_conf("Lang_FR_Settings"));
  sfText_setString(wf->t3, get_int("Lang_Type") ? get_conf("Lang_EN_Quit"):
		   get_conf("Lang_FR_Quit"));
  init_pos(wf);
  sfRenderWindow_setMouseCursorVisible(wf->wd, true);
  sfRenderWindow_setTitle(wf->wd, wf->title_menu);
}

Boolean		get_pos(int buttonx, int buttony)
{
  static	int pos;

  if (buttonx > 812 && buttonx < 1100 && buttony > 145 && buttony < 316)
    return (pos = 0);
  else if (buttonx > 790 && buttonx < 1130 && buttony > 340 && buttony < 600)
    return (pos = 1);
  else if (buttonx > 814 && buttonx < 1058 && buttony > 758 && buttony < 904)
    return (pos = 2);
  return (pos);
}
void            handle_menu_event(t_wolf *wf)
{
  sfEvent       event;

  init_menu(wf);
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      if (event.type == sfEvtMouseMoved)
	wf->sel = get_pos(event.mouseMove.x, event.mouseMove.y);
      handle_close_event(wf, event);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
	!wf->sel ? 1 : wf->sel--;
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
	wf->sel == 2 ? 1 : wf->sel++;
      if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) ||
	  (event.type == sfEvtMouseButtonPressed &&
	   event.mouseButton.button == sfMouseLeft))
	{
	  if (!wf->sel && (wf->game = true)) {}
	  else if (wf->sel == 1 && !(wf->sel = 0) && (wf->settings =  true)) {}
	}
    }
}
