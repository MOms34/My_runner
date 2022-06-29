/*
** EPITECH PROJECT, 2022
** hunter_mohamed
** File description:
** main
*/

#include "include/my.h"

void loop_game(window_t *game);

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}

void my_event(window_t *game, sfVector2i mouse, sfVector2f sprite)
{
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->my_window);
	if (game->alea == 10) {
		sfMusic_destroy(game->song);
		sfRenderWindow_close(game->my_window);
	}
	if (game->event.type == sfEvtMouseButtonPressed &&
        (game->event.mouseButton.button == sfMouseLeft &&
        mouse.x >= sprite.x && mouse.x <= sprite.x + 200 &&
        mouse.y >= sprite.y && mouse.y <= sprite.y + 120)) {
            game->alea++;
			sfSprite_setPosition(game->player, (sfVector2f){-10, 500});
		}
}

void loop_game(window_t *game)
{
	while(sfRenderWindow_isOpen(game->my_window)) {
		sfVector2i mouse = sfMouse_getPositionRenderWindow(game->my_window);
    	sfVector2f sprite = sfSprite_getPosition(game->player);
		while (sfRenderWindow_pollEvent(game->my_window, &game->event))
            my_event(game, mouse, sprite);
		sfRenderWindow_clear(game->my_window, sfBlack);
        sfRenderWindow_drawSprite(game->my_window, game->background, NULL);
		if (sfSprite_getPosition(game->player).x >= 1930)
			sfSprite_setPosition(game->player, (sfVector2f){-10, 500});
		sfSprite_move(game->player, (sfVector2f){0.5, 0});
        sfRenderWindow_drawSprite(game->my_window, game->player, NULL);
        sfRenderWindow_display(game->my_window);
	}
}

void init_struct(window_t *game)
{
	sfVideoMode mode = {1920, 1080, 32};
    game->my_window = sfRenderWindow_create(mode, "My Runner", sfFullscreen | \
    sfClose, NULL);
    game->background = sfSprite_create();
    game->player = sfSprite_create();
    game->back = sfTexture_createFromFile("12.jpg", NULL);
    game->obj = sfTexture_createFromFile("th.png", NULL);
    game->song = sfMusic_createFromFile("leto-tes-parents-feat-ninho-clip-officiel.ogg");
    sfSprite_setTexture(game->background, game->back, sfTrue);
    sfSprite_setTexture(game->player, game->obj, sfTrue);
	sfSprite_setPosition(game->player, (sfVector2f){-10, 500});
    game->alea = 0;
    sfMusic_play(game->song);
    sfMusic_setLoop(game->song, sfTrue);
	loop_game(game);
}

int main(int argc, char **argv)
{
	window_t *game = malloc(sizeof(window_t));

	if (argc != 1 && argv[1][0] == '-' && argv[1][1] == 'h') {
		my_putstr("Is my_game\n");
		return 0;
	}
	init_struct(game);
	return 0;
}
