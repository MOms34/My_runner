/*
** EPITECH PROJECT, 2022
** Makedossier
** File description:
** my
*/

#ifndef MY_H_
	#define MY_H_
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
	#include <signal.h>
	#include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct window_s
{
    sfRenderWindow *my_window;
    sfSprite *background;
    sfSprite *player;
    sfTexture *back;
    sfTexture *obj;
    sfEvent event;
    sfMusic *song;
    int alea;
} window_t;

#endif /* !MY_H_ */
