/*
** struct_handlers.c for wolf3d in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 19:59:16 2017 Bonaldi Jordan
** Last update Sun Jan 15 16:38:02 2017 root
*/

# include "project.h"

static void	pixels_init(t_wolf *wolf)
{
  int		i;

  i = -1;
  if (!(wolf->fb->pixels = malloc(wolf->fb->width * wolf->fb->height *
				  4 * sizeof(wolf->fb))))
    my_exit(84, 19, "struct_handlers.c", "pixels malloc");
  while (++i < wolf->fb->width * wolf->fb->height * 4)
    wolf->fb->pixels[i] = 0;
}

void		init_text(t_wolf	*wf)
{
  if (!(wf->t1 = sfText_create()) || !(wf->t2 = sfText_create()) ||
      !(wf->t3 = sfText_create()) || !(wf->t4 = sfText_create()) ||
      !(wf->t5 = sfText_create()) || !(wf->t6 = sfText_create()) ||
      !(wf->t7 = sfText_create()))
    my_exit(84, 29, "struct_handlers.c", "text create");
  wf->title_menu = get_int("Lang_Type") ? get_conf("Title_EN_Main") :
    get_conf("Title_FR_Main");
  wf->title_game = get_int("Lang_Type") ? get_conf("Title_EN_Game") :
    get_conf("Title_FR_Game");
}

void		init_key(t_wolf *wf)
{
  wf->key_z = get_int("Forward");
  wf->key_s = get_int("BackWard");
  wf->key_q = get_int("Move_Left");
  wf->key_d = get_int("Move_Right");
  wf->key_l = get_int("Head_Right");
  wf->key_r = get_int("Head_Left");
}

void		other_init(t_wolf *wolf)
{
  wolf->game = false;
  wolf->kz = get_conf("WKeyZ");
  wolf->ks = get_conf("WKeyS");
  wolf->kq = get_conf("WKeyQ");
  wolf->kd = get_conf("WKeyD");
  wolf->mpp = get_conf("WMiniMap");
  wolf->clp = get_conf("CurrentLevelPos");
  wolf->settings = false;
  wolf->language = !get_int("Lang_Type") ? "Francais" : "English";
  wolf->lang = false;
  wolf->controls = false;
  wolf->position = false;
  wolf->angle = get_int("Player_Angle");
  wolf->distance = 0.25;
  wolf->minimap = get_int("WMiniMap");
  wolf->filename = get_int("WCurrentLevel") == 1 ? "MAPS/map.w3" :
    get_int("WCurrentLevel") == 2 ? "MAPS/map2.w3" :
    get_int("WCurrentLevel") == 3 ? "MAPS/map3.w3" :
    get_int("WCurrentLevel") == 4 ? "MAPS/map4.w3" : "MAPS/map5.w3";
  wolf->format = get_conf("Format");
  wolf->fb->width = get_int("Windows.x");
  wolf->fb->height = get_int("Windows.y");
  wolf->sel = 0;
}

t_wolf		*initialiser()
{
  t_wolf	*wolf;

  if (!(wolf = malloc(sizeof(*wolf))) ||
      !(wolf->font = sfFont_createFromFile("Font/Sweet.ttf")) ||
      !(wolf->font2 = sfFont_createFromFile("Font/Sweet1.ttf")) ||
      !(wolf->fb = malloc(sizeof(*wolf->fb))) || !(wolf->buf = malloc(4096)))
    my_exit(84, 39, "struct_handlers.c", "malloc");
  wolf->wall = *get_conf("WallType") - 48;
  wolf->vo = *get_conf("Void") - 48;
  wolf->player = set_fvector(get_int("Player_Pos_X") + 0.5,
			     get_int("Player_Pos_Y") + 0.5);
  other_init(wolf);
  init_key(wolf);
  file_manager(wolf);
  init_text(wolf);
  pixels_init(wolf);
  return (wolf);
}
