#ifndef _GAME__H
#define _GAME__H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "defs.h"

using namespace std;

struct Plane {
    int x, y;
    int dx = 0, dy = 0;
    int speed = PLANE_SPEED;
    SDL_Texture* texture;

    void move();
    void render(SDL_Renderer* renderer);

};

struct Enemy {
    int x,y ;
    int speed = ENEMY_SPEED;
    SDL_Texture* texture;

    void render(SDL_Renderer* renderer);
    void move();

};

void spawnEnemy(Enemy& enemy, SDL_Renderer* renderer, SDL_Texture* enemyTexture);
void updateEnemy(Enemy& enemy, SDL_Renderer* renderer, Plane& plane, bool& quit, int& score);


#endif // _GAME__H
