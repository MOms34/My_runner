/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/

#include "include/my.h"


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
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <sys/types.h>

#define WIDTH 1920
#define HEIGHT 1080

int first (char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int count = 0;
    char c = '\0';
    int i = 0;

    while (read(fd, &c, 1)) {
      count++;
    }
    return count;
}
char *my_first(char *filepath)
{
  int fd = open(filepath, O_RDONLY);
  char c = '\0';
  int i = 0;
  int count = first(filepath);
  char *buffer = malloc(sizeof(char) * count + 1);

    while (read(fd, &c, 1)) {
      buffer[i] = c;
      i++;
    }
    buffer[i] = '\0';
    return buffer;
}
window_t my_moove(window_t win, char *buffer)
{
  int i = 0;
    sfSprite_setPosition(win.sprite, win.ps_sprite);
    sfSprite_setPosition(win.sol, win.ps_sol);
    sfSprite_setPosition(win.sol1, win.ps_sol1);
    sfSprite_setPosition(win.sol2, win.ps_sol2);
    sfSprite_setPosition(win.fond_mid, win.ps_fond_mid);
    sfSprite_setPosition(win.fond_mid1, win.ps_fond_mid1);
    sfSprite_setPosition(win.fond_back, win.ps_fond_back);
    sfSprite_setPosition(win.fond_back1, win.ps_fond_back1);
    // sfSprite_setPosition(win.fire, win.ps_fire);
    win.ps_fond_back.x = (win.move *1) + 5 - 1920;
    win.ps_fond_back1.x = (win.move *1) + 5 + 1918;
    win.ps_fond_mid.x = (win.move2 * 4) + 5 - 1920;
    win.ps_fond_mid1.x = (win.move2 * 3) + 5 + 1918;
    // win.ps_fire.x += (win.move);

    win.move -= 6;
    win.move2 -= 6;
      if (win.move < -3840)
        win.move = 0;
        if (win.move2 < -1920)
        win.move2 = 0;
  // while (buffer[i] != '\0' ) {
  //   if (buffer[i] == '1') {
  //     win.ps_fire.y = 794;
  //     win.ps_fire.x = 300 * i + win.move;
  //   }
  //   i++;
  // }
     return (win);
}
window_t set_mypos(window_t win)
{
    // init of the gravity and the move value
    win.move = 0;
    win.gravity = 0;

    // init of the placement of the features (the background is by default in place here)
    //ground
    win.ps_sol.y = 950;
    win.ps_sol1.y = 950;
    win.ps_sol2.y = 950;
    win.ps_fond_mid.y = 410;
    win.ps_fond_mid1.y = 410;
    win.ps_fire.y = 794;


    // character
    win.ps_sprite.y = 700;
    win.ps_sprite.x = 150;
    return (win);
}
void draw_everything(window_t win)
{

    sfRenderWindow_drawSprite(win.window, win.fond_back, NULL);
    sfRenderWindow_drawSprite(win.window, win.fond_back1, NULL);
    sfRenderWindow_drawSprite(win.window, win.fond_mid, NULL);
    sfRenderWindow_drawSprite(win.window, win.fond_mid1, NULL);
      sfRenderWindow_drawSprite(win.window, win.fire, NULL);
    sfRenderWindow_drawSprite(win.window, win.sol, NULL);
    sfRenderWindow_drawSprite(win.window, win.sol1, NULL);
    sfRenderWindow_drawSprite(win.window, win.sol2, NULL);
    // sfRenderWindow_drawSprite(win.window, win.fire, NULL);
    sfRenderWindow_drawSprite(win.window, win.sprite, NULL);
}

window_t all_sprite(window_t win, char* buffer)
{
  int i = 0;
    win.origin.x = 50;
    win.origin.y = 50;
    win.rect1.top = 0;
        win.rect1.left = 0;
        win.rect1.width = 242;
        win.rect1.height = 301;
  win.sprite = sfSprite_create();
  win.sol = sfSprite_create();
  win.sol1 = sfSprite_create();
  win.sol2 = sfSprite_create();
  win.fond_back = sfSprite_create();
  win.fond_back1 = sfSprite_create();
  win.fond_mid = sfSprite_create();
  win.fond_mid1 = sfSprite_create();
  win.texture = sfTexture_createFromFile("dd.png", NULL);
  win.sol_texture = sfTexture_createFromFile("sol.png", NULL);
  win.sol_texture1 = sfTexture_createFromFile("sol.png", NULL);
  win.sol_texture2 = sfTexture_createFromFile("sol.png", NULL);
  win.fondb_texture = sfTexture_createFromFile("back.png", NULL);
  win.fondb_texture1 = sfTexture_createFromFile("back.png", NULL);
  win.fondm_texture = sfTexture_createFromFile("midback.png", NULL);
  win.fondm_texture1 = sfTexture_createFromFile("midback.png", NULL);
  sfSprite_setTexture(win.sprite, win.texture, sfTrue);
  sfSprite_setTexture(win.fond_back, win.fondb_texture, sfTrue);
  sfSprite_setTexture(win.fond_back1, win.fondb_texture1, sfTrue);
  sfSprite_setTexture(win.sol, win.sol_texture, sfTrue);
  sfSprite_setTexture(win.sol1, win.sol_texture1, sfTrue);
  sfSprite_setTexture(win.sol2, win.sol_texture2, sfTrue);
  sfSprite_setTexture(win.fond_mid, win.fondm_texture, sfTrue);
  sfSprite_setTexture(win.fond_mid1, win.fondm_texture1, sfTrue);
  win.fire = sfSprite_create();
  win.fire_texture = sfTexture_createFromFile("stone.png", NULL);
  sfSprite_setTexture(win.fire, win.fire_texture, sfTrue);
  // win.fire = sfSprite_create();
  // win.fire_texture = sfTexture_createFromFile("stone.png", NULL);
  // sfSprite_setTexture(win.fire, win.fire_texture, sfTrue);
  // while (buffer[i] != '\0' ) {
  //   if (buffer[i] == '1') {
  //     win.fire = sfSprite_create();
  //     win.fire_texture = sfTexture_createFromFile("feu.png", NULL);
  //     sfSprite_setTexture(win.fire, win.fire_texture, sfTrue);
  //     sfSprite_setPosition(win.fire, win.ps_fire);
  //     win.ps_fire.y = 410;
  //     win.ps_fire.x = 200 * i;
  //   }
  //   i++;
  // }
  win = set_mypos(win);


      //  win.second = win.time.microseconds / 1000000.0;
      //         if (win.second > 0.5) {
      //           sfClock_getElapsedTime(win.clock);
      //            if (win.rect1.left == 1210)
      //                           win.rect1.left -= 1210;
      //             else
      //               win.rect1.left += 242;
      //             sfClock_restart(win.clock);
      //         }
   return (win);

}

window_t stone (window_t win, int i)
{
  win.fire = sfSprite_create();
  win.fire_texture = sfTexture_createFromFile("stone.png", NULL);
  sfSprite_setTexture(win.fire, win.fire_texture, sfTrue);
  // sfSprite_setPosition(win.fire, win.ps_fire);
  // win.ps_fire.y = 794;
  // printf("i = %d\n", i);
  // win.ps_fire.x = 150 + (3 *i);
      // printf("ps =%d\n", ps_fire.x);

  // sfRenderWindow_drawSprite(win.window, win.fire, NULL);
  return win;
}
void my_run(char *buffer)
{
  int count = 0;
    window_t win;
    sfVideoMode mode = {1920, 1080, 32};
    int i = 0;
    sfClock *clock = sfClock_create();
    sfTime time;
    win = all_sprite(win, buffer);
  //                while (buffer[i] != '\0' ) {
  //   if (buffer[i] == '1') {
  //     win = stone(win, i);
  //   }
  //   i++;
  // }
    win.window = sfRenderWindow_create(mode, "runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win.window, 60);
    sfSprite_setOrigin(win.sprite, win.origin);
    while (sfRenderWindow_isOpen(win.window)) {
      time = sfClock_getElapsedTime(clock);
      sfRenderWindow_clear(win.window, sfBlack);
              close_window(win.window);
                              while (buffer[i] != '\0' ) {
    if (buffer[i] == '1') {
       sfSprite_setPosition(win.fire, win.ps_fire);
       win.ps_fire.x += 150 + (3 * i);
       draw_everything(win);
    }
    i++;
  }
              draw_everything(win);
              win = my_moove(win, buffer);
              sfSprite_setTextureRect(win.sprite, win.rect1);
                if (time.microseconds > 50000 ) {
                 if (win.rect1.left == 968)
                                win.rect1.left -= 968;
                  else
                    win.rect1.left += 242;
                  sfClock_restart(clock);
                }
              sfRenderWindow_display(win.window);
//gimp
//dafont police
    }
    sfRenderWindow_destroy(win.window);

}
int main(int ac, char **argv)
{
  char *filepath = argv[1];
  int fd = open(filepath, O_RDONLY);
  char *buffer = my_first(filepath);
  my_run(buffer);
  return (0);
}