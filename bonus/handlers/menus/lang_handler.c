/*
** controls_handlers.c for wolf in /home/Neferett/wolf3d/bonus
** 
** Made by root
** Login   <root@epitech.net>
** 
** Started on  Sun Jan 15 00:40:29 2017 root
** Last update Sun Jan 15 17:49:14 2017 Bonaldi Jordan
*/

# include "project.h"

static char	*get_string(t_wolf *wf)
{
  return (my_strcat(my_strcat(get_int("Lang_Type") ?
			      get_conf("Lang_EN_LangMenu"):
			      get_conf("Lang_FR_LangMenu"), "\t->\t"), wf->language));
}

void		init_string_lang(t_wolf *wf)
{
  sfText_setString(wf->t1, get_string(wf));
  sfText_setString(wf->t2, get_int("Lang_Type") ? get_conf("Lang_EN_Back"):
                   get_conf("Lang_FR_Back"));
}

void		handle_lang(t_wolf *wf, sfEvent event)
{
  if (event.type == sfEvtTextEntered &&
      (event.text.unicode == 'e' || event.text.unicode == 'f'))
    {
      set_conf("Lang_Type", my_strcatc("\0",
				       event.text.unicode == 'e' ? '1' : '0'));
      wf->language = !get_int("Lang_Type") ? "Francais" : "English";
    }
}
