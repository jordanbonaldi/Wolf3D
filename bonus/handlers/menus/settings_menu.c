/*
** main_menu.c for wolf in /home/Neferett/wolf3d/bonus
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 13:23:22 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:15:44 2017 root
*/

# include "project.h"

static void	init_pos2(t_wolf *wf)
{
  sfText_setPosition(wf->t3, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Lang_EN_X") :
					  get_int("Lang_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Lang_EN_Y") :
					 get_int("Lang_FR_Y")));
  sfText_setPosition(wf->t4, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Back_EN_X") :
					  get_int("Back_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Back_EN_Y") :
					 get_int("Back_FR_Y")));
}

static void	init_pos(t_wolf *wf)
{
  sfText_setPosition(wf->t1, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Controls_EN_X") :
					  get_int("Controls_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Controls_EN_Y") :
					 get_int("Controls_FR_Y")));
  sfText_setPosition(wf->t2, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("Position_EN_X") :
					  get_int("Position_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("Position_EN_Y") :
					 get_int("Position_FR_Y")));
  init_pos2(wf);
}

static void	init_settings(t_wolf *wf)
{
  init_Color(wf);
  init_font(wf, 0);
  init_size(wf, 150);
  sfText_setString(wf->t1, get_int("Lang_Type") ? get_conf("Lang_EN_Controls"):
                   get_conf("Lang_FR_Controls"));
  sfText_setString(wf->t2, get_int("Lang_Type") ? get_conf("Lang_EN_Position"):
                   get_conf("Lang_FR_Position"));
  sfText_setString(wf->t3, get_int("Lang_Type") ? get_conf("Lang_EN_Lang"):
                   get_conf("Lang_FR_Lang"));
  sfText_setString(wf->t4, get_int("Lang_Type") ? get_conf("Lang_EN_Back"):
                   get_conf("Lang_FR_Back"));
  init_pos(wf);
  sfRenderWindow_setMouseCursorVisible(wf->wd, true);
  sfRenderWindow_setTitle(wf->wd, (get_int("Lang_Type") ?
                                   get_conf("Lang_Settings_EN") :
                                   get_conf("Lang_Settings_FR")));
}

static int		get_pos(int buttonx, int buttony)
{
  static	int pos;

  if (buttonx > 758 && buttonx < 1146 && buttony > 88 && buttony < 195)
    return (pos = 0);
  else if (buttonx > 805 && buttonx < 1114 && buttony > 286 && buttony < 391)
    return (pos = 1);
  else if (buttonx > 493 && buttonx < 1500 && buttony > 465 && buttony < 585)
    return (pos = 2);
  else if (buttonx > 800 && buttonx < 1071 && buttony > 857 && buttony < 954)
    return (pos = 3);
  return (pos);
}
void            handle_settings_event(t_wolf *wf)
{
  sfEvent       event;

  init_settings(wf);
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      handle_close_event(wf, event);
      if (!wf->settings)
	break;
      if (event.type == sfEvtMouseMoved)
	wf->sel = get_pos(event.mouseMove.x, event.mouseMove.y);
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
	!wf->sel ? 1 : wf->sel--;
      if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
	wf->sel == 3 ? 1 : wf->sel++;
      if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) ||
	  (event.type == sfEvtMouseButtonPressed &&
	   event.mouseButton.button == sfMouseLeft))
	{
	  if (!wf->sel && (wf->controls = true) && !(wf->settings = false)) {}
	  if (wf->sel == 1 && (wf->position = true) && !(wf->sel = 0)
	      && !(wf->settings = false)) {}
	  if (wf->sel == 2 && (wf->lang = true) && !(wf->sel = 0)
	      && !(wf->settings = false)) {}
	}
    }
}
