/*
** main_menu.c for wolf in /home/Neferett/wolf3d/bonus
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 13:23:22 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:17:42 2017 root
*/

# include "project.h"

static void	init_pos(t_wolf *wf)
{
  sfText_setPosition(wf->t1, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("PMN_EN_X") :
					  get_int("PMN_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("PMN_EN_Y") :
					 get_int("PMN_FR_Y")));
  sfText_setPosition(wf->t2, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("PCL_EN_X") :
					  get_int("PCL_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("PCL_EN_Y") :
					 get_int("PCL_FR_Y")));
  sfText_setPosition(wf->t3, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("MBack_EN_X") :
					  get_int("MBack_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("MBack_EN_Y") :
					 get_int("MBack_FR_Y")));
  sfText_setPosition(wf->t5, get_right_pos());
}

static void	init_controls(t_wolf *wf)
{
  init_Color(wf);
  init_font(wf, 1);
  init_size(wf, 90);
  init_string_mp(wf);
  init_pos(wf);
  sfRenderWindow_setMouseCursorVisible(wf->wd, true);
  sfRenderWindow_setTitle(wf->wd, (get_int("Lang_Type") ?
                                   get_conf("Lang_mt_EN") :
                                   get_conf("Lang_mt_FR")));
}

static int		get_pos(int buttonx, int buttony)
{
  static	int pos;

  if (buttonx > 73 && buttonx < 1032 && buttony > 338 && buttony < 418)
    return (pos = 0);
  else if (buttonx > 77 && buttonx < 737 && buttony > 530 && buttony < 608)
    return (pos = 1);
  else if (buttonx > 800 && buttonx < 1075 && buttony > 815 && buttony < 900)
    return (pos = 2);
  return (pos);
}
void            handle_position_event(t_wolf *wf)
{
  sfEvent       event;

  init_controls(wf);
  if (!wf->sel)
    draw_circle(wf);
  else if (wf->sel == 1 && reset_pixel(wf))
    sfText_setString(wf->t5, get_int("Lang_Type") ?
		     my_strcat(my_strcat(get_conf("Lang_EN_Current_Lvl"), ": "),
			       get_conf("WCurrentLevel")) :
		     my_strcat(my_strcat(get_conf("Lang_FR_Current_Lvl"), ": "),
			       get_conf("WCurrentLevel")));
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      handle_close_event(wf, event);
      if (!wf->position)
	break;
      if (event.type == sfEvtMouseMoved)
	wf->sel = get_pos(event.mouseMove.x, event.mouseMove.y);
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
	!wf->sel ? 1 : wf->sel--;
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
	wf->sel == 2 ? 1 : wf->sel++;
      handle_position(wf, event);
    }
}
