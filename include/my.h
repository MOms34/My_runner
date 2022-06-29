/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <signal.h>

#ifndef __RUNNER_H__
#define __RUNNER_H__


typedef struct window_s {
    int move;
    float gravity;
    int move2;
    int i;
    int count;
    float second;
    sfRenderWindow *window;
    sfEvent event;
    sfTime time;
    sfTime time2;
    sfClock *clock;
    sfClock *clock2;
    sfTexture *texture;
    sfText *text;
    char *str;
    char *str2;
    sfMusic *music_game;
    sfFont *font_text;
    sfTexture *gameover_texture;
    sfTexture *win_texture;
    sfTexture *sol_texture;
    sfTexture *sol_texture1;
    sfTexture *sol_texture2;
    sfTexture *fondb_texture;
    sfTexture *fondb_texture1;
    sfTexture *fondm_texture;
    sfTexture *fondm_texture1;
    sfTexture *stone_texture;
    sfTexture *stone_texture1;
    sfTexture *stone_texture2;
    sfSprite *sprite;
    sfSprite *win;
    sfSprite *gameover;
    sfSprite *fire;
    sfSprite *sol;
    sfSprite *sol1;
    sfSprite *sol2;
    sfSprite *fond_back;
    sfSprite *fond_back1;
    sfSprite *fond_mid;
    sfSprite *fond_mid1;
    sfSprite *stone;
    sfSprite *stone1;
    sfSprite *stone2;
    sfVector2f ps_gameover;
    sfVector2f ps_stone;
    sfVector2f ps_stone1;
    sfVector2f ps_stone2;
    sfVector2f ps_sprite;
    sfVector2f ps_sol;
    sfVector2f ps_sol1;
    sfVector2f ps_sol2;
    sfVector2f ps_fond_back;
    sfVector2f ps_fond_back1;
    sfVector2f ps_fond_mid;
    sfVector2f ps_fond_mid1;
    sfVector2f origin;
    sfIntRect rect1;
} window_t;

typedef struct OKLM OKLM;
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(int number, char const *base);

#endif
