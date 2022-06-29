#include "include/my.h"
#define GRAVITY     9.81
#define JUMP_HEIGHT 30
#define FRICTION    0.95

int first (char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int count = 0;
    char c = '\0';

    while (read(fd, &c, 1)) {
      count++;
    }
    return count;
}
char *my_first(char *filepath, window_t *game)
{
  int fd = open(filepath, O_RDONLY);
  char c = '\0';
  int i = 0;
  int count = first(filepath);
  char *buffer = malloc(sizeof(char) * count + 1);
  int z = 0;

    while (read(fd, &c, 1)) {
        if (c == '1')
            z++;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    game->count = z;
    printf("count = %d\n", game->count);

    return buffer;
}
char *my_malloc(unsigned int size)
{
	char *mymalloc = malloc(size);

	for (unsigned int i = 0; i < size; i = i + 1)
		mymalloc[i] = '\0';
	return (mymalloc);
}

char *my_itoa(int num)
{
	int i = 0;
	int z;
	int m = 0;
	int n = num;
	char *result;

	while (n != 0) {
		m = m + 1;
		n /= 10;
	}
	result = my_malloc(m + 1);
	for (; i < m; i = i + 1) {
		z = num % 10;
		num = num / 10;
		result[m - (i + 1)] = z + '0';
	}
	result[m] = '\0';
	return (result);
}
void init_perso(window_t *game)
{
    game->sprite = sfSprite_create();
    game->texture = sfTexture_createFromFile("dd.png", NULL);
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    game->ps_sprite.x = 150;
    game->ps_sprite.y = 650;
    sfSprite_setPosition(game->sprite, game->ps_sprite);
    game->rect1.top = 0;
    game->rect1.left = 0;
    game->rect1.width = 242;
    game->rect1.height = 301;
    // sfSprite_setTextureRect(game->sprite, game->rect1);
}
void init_sol(window_t *game)
{
    game->sol = sfSprite_create();
    game->sol_texture = sfTexture_createFromFile("sol.png", NULL);
    sfSprite_setTexture(game->sol, game->sol_texture, sfTrue);
    game->ps_sol.x = 0,
    game->ps_sol.y = 950;
    sfSprite_setPosition(game->sol, game->ps_sol);
    game->sol1 = sfSprite_create();
    game->sol_texture1 = sfTexture_createFromFile("sol.png", NULL);
    sfSprite_setTexture(game->sol1, game->sol_texture1, sfTrue);
    game->ps_sol1.x = 1920,
    game->ps_sol1.y = 950;
    sfSprite_setPosition(game->sol1, game->ps_sol1);
}
void init_stone(window_t *game)
{
    game->stone = sfSprite_create();
    game->stone_texture = sfTexture_createFromFile("stone.png", NULL);
    sfSprite_setTexture(game->stone, game->stone_texture, sfTrue);
    game->ps_stone.y = 793;
    game->ps_stone.x = 3400;
    sfSprite_setPosition(game->stone, game->ps_stone);
}
void init_stone1(window_t *game)
{
    game->stone1 = sfSprite_create();
    game->stone_texture1 = sfTexture_createFromFile("stone.png", NULL);
    sfSprite_setTexture(game->stone1, game->stone_texture1, sfTrue);
    game->ps_stone1.y = 793;
    game->ps_stone1.x = 4500;
    sfSprite_setPosition(game->stone1, game->ps_stone1);
}
void init_stone2(window_t *game)
{
    game->stone2 = sfSprite_create();
    game->stone_texture2 = sfTexture_createFromFile("stone.png", NULL);
    sfSprite_setTexture(game->stone2, game->stone_texture2, sfTrue);
    game->ps_stone2.y = 793;
    game->ps_stone2.x = 5500;
    sfSprite_setPosition(game->stone2, game->ps_stone2);
}
void init_back(window_t *game)
{
    game->fond_back = sfSprite_create();
    game->fondb_texture = sfTexture_createFromFile("back.png", NULL);
    sfSprite_setTexture(game->fond_back, game->fondb_texture, sfTrue);
    game->ps_fond_back.x = 0;
    game->ps_fond_back.y = 0;

}
void init_mid(window_t *game)
{
    game->fond_mid = sfSprite_create();
    game->fondm_texture = sfTexture_createFromFile("midback.png", NULL);
    sfSprite_setTexture(game->fond_mid, game->fondm_texture, sfTrue);
    game->ps_fond_mid.x = 0;
    game->ps_fond_mid.y = 600;
    game->str = malloc(sizeof(char) * 100);
    game->str = "SCORE:0";
    game->text = sfText_create();
    game->font_text = sfFont_createFromFile("choco.ttf");
    sfText_setCharacterSize(game->text, 30);
    sfText_setString(game->text, game->str);
    sfText_setFont(game->text, game->font_text);
    sfText_setColor(game->text, sfWhite);
    sfText_setPosition(game->text, ((sfVector2f){960, 10}));
}
void init_gamer(window_t *game)
{
    game->gameover = sfSprite_create();
    game->gameover_texture = sfTexture_createFromFile("gameover.png", NULL);
    sfSprite_setTexture(game->gameover, game->gameover_texture, sfTrue);
}
void init_win(window_t *game)
{
    game->win = sfSprite_create();
    game->win_texture = sfTexture_createFromFile("win33.jpg", NULL);
    sfSprite_setTexture(game->win, game->win_texture, sfTrue);
}
void init(window_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    game->window = sfRenderWindow_create(mode, "runner", sfResize | sfClose, NULL);
    game->music_game = sfMusic_createFromFile("jefe.ogg");
    sfMusic_play(game->music_game);
    sfMusic_setLoop(game->music_game, sfTrue);
    init_gamer(game);
    init_back(game);
    init_mid(game);
    init_stone(game);
    init_stone1(game);
    init_stone2(game);
    init_sol(game);
    init_perso(game);
    init_win(game);
}
void draw_all(window_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->fond_back, NULL);
    sfRenderWindow_drawSprite(game->window, game->fond_mid, NULL);
    sfRenderWindow_drawSprite(game->window, game->stone, NULL);
    sfRenderWindow_drawSprite(game->window, game->stone1, NULL);
    sfRenderWindow_drawSprite(game->window, game->stone2, NULL);
    sfRenderWindow_drawSprite(game->window, game->sol1, NULL);
    sfRenderWindow_drawSprite(game->window, game->sol, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
}
void my_perso_anim (window_t *game)
{
    sfSprite_setTextureRect(game->sprite, game->rect1);
    if (game->time.microseconds > 50000 ) {
        if (game->rect1.left == 968)
            game->rect1.left -= 968;
        else
            game->rect1.left += 242;
        sfClock_restart(game->clock);
    }
}
void move_sprite(window_t *game)
{
    sfSprite_move(game->fond_back, (sfVector2f){-0.5, 0});
    if (sfSprite_getPosition(game->fond_back).x < -1920)
        sfSprite_setPosition(game->fond_back, game->ps_fond_back);
    sfSprite_move(game->fond_mid, (sfVector2f){-1, 0});
    if (sfSprite_getPosition(game->fond_mid).x < -2400)
        sfSprite_setPosition(game->fond_mid, (sfVector2f){2200, 410});
    sfSprite_move(game->sol, (sfVector2f){-1.5, 0});
    if (sfSprite_getPosition(game->sol).x < -1920)
        sfSprite_setPosition(game->sol, game->ps_sol);
    sfSprite_move(game->sol1, (sfVector2f){-1.5, 0});
    if (sfSprite_getPosition(game->sol1).x < 0)
        sfSprite_setPosition(game->sol1, game->ps_sol1);

}
void move_stone(window_t *game)
{
    sfSprite_move(game->stone, (sfVector2f){-1.5, 0});
    if (sfSprite_getPosition(game->stone).x < -1920 && game->i <= game->count -1)
        sfSprite_setPosition(game->stone, game->ps_stone);
    sfSprite_move(game->stone1, (sfVector2f){-1.5, 0});
    if (sfSprite_getPosition(game->stone1).x < -1920 && game->i < game->count - 2)
        sfSprite_setPosition(game->stone1, game->ps_stone1);
    sfSprite_move(game->stone2, (sfVector2f){-1.5, 0});
    if (sfSprite_getPosition(game->stone2).x < -1920 && game->i < game->count -3)
        sfSprite_setPosition(game->stone2, game->ps_stone2);
}
void jump(window_t *game)
{
    if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeySpace && game->ps_sprite.y > 620) {
        game->gravity = -2.5;
        game->ps_sprite.y += game->gravity;
        sfSprite_setPosition(game->sprite, game->ps_sprite);
    }

}
int colision_m (window_t *game)
{
    if ((sfSprite_getPosition(game->sprite).x) < (sfSprite_getPosition(game->stone).x + 100)){
        if ((sfSprite_getPosition(game->sprite).x + 220) > sfSprite_getPosition(game->stone).x) {
            if ((sfSprite_getPosition(game->sprite).y) < (sfSprite_getPosition(game->stone).y + 179)) {
                if ((280 + sfSprite_getPosition(game->sprite).y) > (sfSprite_getPosition(game->stone).y)) {
                    return (-1);
                }
            }
        }
    }
    return(0);
}
int colision_1 (window_t *game)
{

    if ((sfSprite_getPosition(game->sprite).x) < (sfSprite_getPosition(game->stone1).x + 100)){
        if ((sfSprite_getPosition(game->sprite).x + 220) > sfSprite_getPosition(game->stone1).x) {
            if ((sfSprite_getPosition(game->sprite).y) < (sfSprite_getPosition(game->stone1).y + 179)) {
                if ((280 + sfSprite_getPosition(game->sprite).y) > (sfSprite_getPosition(game->stone1).y)) {
                    return (-1);
                }
            }
        }
    }
    return(0);
}
int colision_2 (window_t *game)
{

    if ((sfSprite_getPosition(game->sprite).x) < (sfSprite_getPosition(game->stone2).x + 100)){
        if ((sfSprite_getPosition(game->sprite).x + 220) > sfSprite_getPosition(game->stone2).x) {
            if ((sfSprite_getPosition(game->sprite).y) < (sfSprite_getPosition(game->stone2).y + 179)) {
                if ((280 + sfSprite_getPosition(game->sprite).y) > (sfSprite_getPosition(game->stone2).y)) {
                    return (-1);
                }
            }
        }
    }
    return(0);
}
int my_coli(window_t *game)
{
    int a = colision_m(game);
    int b = colision_1(game);
    int c = colision_2(game);

    if (a < 0 || b < 0 || c < 0) {
        // sfRenderWindow_close(game->window);
        return (-1);
    }
    return (0);
}
void put_score_text(window_t *game)
{
    game->str = "SCORE:";
    game->text = sfText_create();
    game->font_text = sfFont_createFromFile("choco.ttf");
    sfText_setCharacterSize(game->text, 30);
    sfText_setString(game->text, game->str);
    sfText_setFont(game->text, game->font_text);
    sfText_setColor(game->text, sfWhite);
    sfText_setPosition(game->text, ((sfVector2f){960, 10}));
    sfRenderWindow_drawText(game->window, game->text, NULL);
}
int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int start_len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[start_len + i] = src[i];
        i++;
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}
char *end (int d)
{
    char *la = "Score:0";
    char *ma = my_itoa(d);
    char *ja;
    int i = 0;
    int a = 0;
    ja = malloc(sizeof(char) * my_strlen(la) + my_strlen(ma) + 1);


      while (la[i] != '\0') {
        ja[i] = la[i];
        i++;
    }
    while (ma[a] != '\0') {
        ja[i] = ma[a];
        i++;
        a++;
    }
    printf("ja = %s\n", la);
    my_strcat(ja, "\0");
    printf("ja = %s\n", ja);
    return ja;

}
void loop_game(window_t *game)
{
    char *str2;
    int d;
    game->clock = sfClock_create();
    game->clock2 = sfClock_create();
    while (sfRenderWindow_isOpen(game->window)) {
        if ((sfSprite_getPosition(game->stone).x) == 145 || (sfSprite_getPosition(game->stone1).x) == 144 || (sfSprite_getPosition(game->stone2).x) == 145) {
            game->i += 1;
            d = game->i;
            str2 = end(d);
            game->str = str2;
            sfText_setString(game->text, game->str);
        }
        if (game-> i == game->count) {
            if (sfSprite_getPosition(game->sprite).x != 1400) {
                if (sfSprite_getPosition(game->sprite).x + 1 == 1400) {
                    while (sfRenderWindow_isOpen(game->window)) {
                        sfRenderWindow_clear(game->window, sfBlack);
                        sfRenderWindow_drawSprite(game->window, game->win, NULL);
                        sfRenderWindow_display(game->window);
                    }
                }
                sfSprite_move(game->sprite, (sfVector2f){0.5, 0});
            }
        }
        if (my_coli(game) == -1)
            while (sfRenderWindow_isOpen(game->window)) {
                sfRenderWindow_clear(game->window, sfBlack);
                sfRenderWindow_drawSprite(game->window, game->gameover, NULL);
                sfRenderWindow_display(game->window);
            }
        if (game->ps_sprite.y < 650) {
            game->ps_sprite.y += game->gravity;
            game->gravity += 0.01;
            sfSprite_setPosition(game->sprite, game->ps_sprite);
        }else {
         while (sfRenderWindow_pollEvent(game->window, &game->event))
               jump(game);
        }
        game->time = sfClock_getElapsedTime(game->clock);
        game->time2 = sfClock_getElapsedTime(game->clock2);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_all(game);
        my_perso_anim(game);
        move_sprite(game);
        move_stone(game);
        // put_score_text(game);
        sfRenderWindow_display(game->window);
    }
}
int main (int argc, char **argv)
{
    window_t *game = malloc(sizeof(window_t));

    if (argc > 2 && argv[2] !=  NULL)
        return 84;
    init(game);
    loop_game(game);
}