/*
** main_menu.c for wolf in /home/Neferett/wolf3d/bonus
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 13:23:22 2017 Bonaldi Jordan
** Last update Sun Jan 15 17:16:45 2017 root
*/

# include "project.h"

static void	init_pos2(t_wolf *wf)
{
  sfText_setPosition(wf->t4, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("KeyD_EN_X") :
					  get_int("KeyD_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("KeyD_EN_Y") :
					 get_int("KeyD_FR_Y")));
  sfText_setPosition(wf->t5, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("C_Back_EN_X") :
					  get_int("C_Back_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("C_Back_EN_Y") :
					 get_int("C_Back_FR_Y")));
}

static void	init_pos(t_wolf *wf)
{
  sfText_setPosition(wf->t1, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("KeyZ_EN_X") :
					  get_int("KeyZ_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("KeyZ_EN_Y") :
					 get_int("KeyZ_FR_Y")));
  sfText_setPosition(wf->t2, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("KeyS_EN_X") :
					  get_int("KeyS_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("KeyS_EN_Y") :
					 get_int("KeyS_FR_Y")));
  sfText_setPosition(wf->t3, set_fvector((wf->fb->width / 2) -
					 (get_int("Lang_Type") ?
					  get_int("KeyQ_EN_X") :
					  get_int("KeyQ_FR_X") / 2),
					 (wf->fb->height / 2) -
					 get_int("Lang_Type") ?
					 get_int("KeyQ_EN_Y") :
					 get_int("KeyQ_FR_Y")));
  init_pos2(wf);
}

static void	init_controls(t_wolf *wf)
{
  init_Color(wf);
  init_font(wf, 1);
  init_size(wf, 90);
  init_string(wf);
  init_pos(wf);
  sfRenderWindow_setMouseCursorVisible(wf->wd, true);
  sfRenderWindow_setTitle(wf->wd, (get_int("Lang_Type") ?
				   get_conf("Lang_Controls_EN") :
				   get_conf("Lang_Controls_FR")));
}

static int		get_pos(int buttonx, int buttony)
{
  static	int pos;

  if (buttonx > 70 && buttonx < 818 && buttony > 56 && buttony < 131)
    return (pos = 0);
  else if (buttonx > 75 && buttonx < 938 && buttony > 238 && buttony < 318)
    return (pos = 1);
  else if (buttonx > 76 && buttonx < 609 && buttony > 430 && buttony < 516)
    return (pos = 2);
  else if (buttonx > 76 && buttonx < 609 && buttony > 620 && buttony < 707)
    return (pos = 3);
  else if (buttonx > 800 && buttonx < 1071 && buttony > 857 && buttony < 954)
    return (pos = 4);
  return (pos);
}
void            handle_controls_event(t_wolf *wf)
{
  sfEvent       event;

  init_controls(wf);
  while (sfRenderWindow_pollEvent(wf->wd, &event))
    {
      handle_close_event(wf, event);
      if (!wf->controls)
	break;
      if (event.type == sfEvtMouseMoved)
	wf->sel = get_pos(event.mouseMove.x, event.mouseMove.y);
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
	!wf->sel ? 1 : wf->sel--;
      else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
	wf->sel == 4 ? 1 : wf->sel++;
      handle_key_create(wf, event);
    }
}
