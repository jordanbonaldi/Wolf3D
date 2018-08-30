/*
** windows_handlers.c for wolf3d in /home/Neferett/wolf3d
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  1 19:52:04 2017 Bonaldi Jordan
** Last update Sun Jan 15 16:38:20 2017 root
*/

# include "project.h"

sfVector2f	get_right_pos()
{
  if (!get_int("CurrentLevelPos"))
    return (set_fvector(0, 10));
  if (get_int("CurrentLevelPos") == 1)
    return (set_fvector(1460, 10));
  if (get_int("CurrentLevelPos") == 2)
    return (set_fvector(10, 1020));
  if (get_int("CurrentLevelPos") == 3)
    return (set_fvector(1460, 1020));
  return (set_fvector(0, 10));
}

void    init_window(t_wolf *wf)
{
  if (!(wf->sprite = sfSprite_create()) ||
      !(wf->texture = sfTexture_create(wf->fb->width, wf->fb->height)))
    my_exit(84, 22, "winows_handler.c", "Texture and sprite");
  sfSprite_setTexture(wf->sprite, wf->texture, sfTrue);
  wf->mode = set_mode(wf->fb->width, wf->fb->height, 32);
  if (!(wf->wd = sfRenderWindow_create(wf->mode, "Wolf3D",
				   sfResize | sfClose, NULL)))
    my_exit(84, 27, "windows_handler.c", "Window create");
  display_window(wf);
}

void		game_screen(t_wolf *wf, sfEvent	event)
{
  sfRenderWindow_setMouseCursorVisible(wf->wd, false);
  draw_all(wf);
  sfTexture_updateFromPixels(wf->texture,
			     wf->fb->pixels, wf->fb->width, wf->fb->height, 0, 0);
  key_event(wf, event);
  sfRenderWindow_clear(wf->wd, sfBlack);
  sfRenderWindow_drawSprite(wf->wd, wf->sprite, NULL);
  sfText_setString(wf->t1, get_int("Lang_Type") ?
  		   my_strcat(my_strcat(get_conf("Lang_EN_Current_Lvl"), ": "),
  			     get_conf("WCurrentLevel")) :
  		   my_strcat(my_strcat(get_conf("Lang_FR_Current_Lvl"), ": "),
  			     get_conf("WCurrentLevel")));
  sfText_setFont(wf->t1, wf->font2);
  sfText_setCharacterSize(wf->t1, get_int("Size_Current_Level"));
  sfText_setColor(wf->t1, sfRed);
  sfText_setPosition(wf->t1, get_right_pos());
  sfRenderWindow_drawText(wf->wd, wf->t1, NULL);
  sfRenderWindow_display(wf->wd);
}

void		menu_screen(t_wolf *wf)
{
  sfText_setString(wf->t5, "\0");
  if (wf->settings)
    handle_settings_event(wf);
  else if (wf->controls)
    handle_controls_event(wf);
  else if (wf->position)
    handle_position_event(wf);
  else if (wf->lang)
    handle_lang_event(wf);
  else
    handle_menu_event(wf);
  sfRenderWindow_clear(wf->wd, sfBlack);
  if (!wf->position && reset_pixel(wf)) {}
  sfTexture_updateFromPixels(wf->texture,
			     wf->fb->pixels, wf->fb->width, wf->fb->height, 0, 0);
  draw_text(wf);
  sfRenderWindow_drawSprite(wf->wd, wf->sprite, NULL);
  sfRenderWindow_display(wf->wd);
  init_sfcolor(wf);
}

void		display_window(t_wolf *wf)
{
  sfEvent	event;

  while (sfRenderWindow_isOpen(wf->wd))
    {
      if (wf->game)
	{
	  sfRenderWindow_setTitle(wf->wd, wf->title_game);
	  game_screen(wf, event);
	}
      else
	menu_screen(wf);
    }
  sfRenderWindow_destroy(wf->wd);
}

