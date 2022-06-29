/*
** EPITECH PROJECT, 2021
** runer
** File description:
** runer
*/

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#define WIDTH 1920
#define HEIGHT 1000
#define SAUT 50



int main (void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "My runer", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 12);
    if (window != NULL)
    {
        sfSprite* sprite = sfSprite_create();
        sfSprite* perso = sfSprite_create();
        sfSprite* sol = sfSprite_create();
        sfSprite* sol1 = sfSprite_create();
        sfSprite* sol2 = sfSprite_create();
        sfSprite* fond_back = sfSprite_create();
        sfSprite* fond_mid = sfSprite_create();
        sfIntRect rect;
        rect.top = 0;
        rect.left = 0;
        rect.width = 242;
        rect.height = 301;
        if (sprite != NULL) {
            sfTexture* texture = sfTexture_create(WIDTH, HEIGHT);
            sfTexture* perso_texture = sfTexture_createFromFile("dd.png", NULL);
            sfTexture* sol_texture = sfTexture_createFromFile("sol.png", NULL);
            sfTexture* sol_texture1 = sfTexture_createFromFile("sol.png", NULL);
            sfTexture* sol_texture2 = sfTexture_createFromFile("sol.png", NULL);
            sfTexture* fondb_texture = sfTexture_createFromFile("back.png", NULL);
            sfTexture* fondm_texture = sfTexture_createFromFile("midback.png", NULL);
            if (texture != NULL) {
                if (perso_texture != NULL){
                sfSprite_setTexture(sprite, texture, sfTrue);
                sfSprite_setTexture(perso, perso_texture, sfTrue);
                sfSprite_setTexture(fond_back, fondb_texture, sfTrue);
                sfSprite_setTexture(sol, sol_texture, sfTrue);
                sfSprite_setTexture(sol1, sol_texture1, sfTrue);
                sfSprite_setTexture(sol2, sol_texture2, sfTrue);
                sfSprite_setTexture(fond_mid, fondm_texture, sfTrue);
                sfColor* pixels = malloc(sizeof(sfColor) * (WIDTH * HEIGHT));
                    if (pixels != NULL) {
                            int px = 100, py = 100, ps = 50, move;
                            float vs = 2, vx = vs; int vy = 0;
                            int la = 200, lo = 600, gravity = -20;
                            sfVector2f moove;
                            sfVector2f sol_moove ;
                            sfVector2f sol_moove1;
                            sfVector2f sol_moove2;
                            sfVector2f mid_moove ;
                            sfVector2f mid_moove1;
                            sfVector2i anim(x, y);
                        while (sfRenderWindow_isOpen(window)) {
                            sfEvent event;
                    /* Process events */
                            while (sfRenderWindow_pollEvent(window, &event)) {
                            /* Close window : exit */
                                if (event.type == sfEvtClosed)
                                    sfRenderWindow_close(window);

                                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                                    sfRenderWindow_close(window);
                                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
                                    vx = 0 - vs;
                                    vy = 0;
                                    sfSprite_setPosition(perso, moove);
                                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
                                        vx = 0 + vs;
                                        vy = 0;

                                if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
                                    py -= SAUT;
                                    px += 20 * vx;
                                       lo = lo +  gravity;

                                     // rotation around the origin
                                    if (lo < 900)
                                        sfSprite_rotate(perso, 0);

                                    // if no key is pressed the sprite doesn't move
                                    if (lo > 610) {
                                        gravity = 0;
                                       lo = 900;
                                    }

                                if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace )
                                    //  = sfSprite_getPosition(sprite);
                                    py += SAUT;
                                     lo = lo - gravity;
                            }
                            sfSprite_setPosition(sol, sol_moove);
                            sfSprite_setPosition(sol1, sol_moove1);
                            sfSprite_setPosition(sol2, sol_moove2);
                            sfSprite_setPosition(perso, moove);
                            sfSprite_setPosition(fond_mid, mid_moove);
                            sfSprite_setPosition(fond_back, mid_moove1);
                             (move * 0.5) + 5 - 1920;
                            move -= 6;
                            if (move < -1920) {
                                sol_moove.x = (move * 2) + (1*5) + 5760;
                            }
                            if (move < -3840)
                                move = 0;
                            if (rect.left == 1210)
                                rect.left -= 1210;
                             else
                                rect.left += 242;

                            /* Clear the screen */
                            sfRenderWindow_clear(window, sfBlack);
                            sfSprite_setTextureRect(perso, rect);
                            // sfSprite_setTextureRect(fond_back, back);
                            sfTexture_updateFromPixels(texture, (sfUint8*) pixels, WIDTH, HEIGHT, 0, 0);
                            sfRenderWindow_drawSprite(window, fond_back, NULL);
                            // sfRenderWindow_drawSprite(window, fond_mid, NULL);
                            sfRenderWindow_drawSprite(window, fond_mid, NULL);
                            sfRenderWindow_drawSprite(window, perso, NULL);
                            sfRenderWindow_drawSprite(window, sol, NULL);
                            sfRenderWindow_drawSprite(window, sol1, NULL);
                            sfRenderWindow_drawSprite(window, sol2, NULL);
                            sfRenderWindow_display(window);
                        }
                        free(pixels);
                    }
                sfText_destroy(texture);
                sfText_destroy(perso_texture);
                sfText_destroy(sol_texture);
                sfText_destroy(sol_texture1);
                sfText_destroy(sol_texture2);
                sfText_destroy(fondb_texture);
                sfText_destroy(fondm_texture);
                    }
            }
            sfSprite_destroy(sprite);
        }    sfRenderWindow_destroy(window);
    }
    return 0;
}