#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"


using namespace std;


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture("background.jpg"));

    Plane plane = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    plane.texture = graphics.loadTexture("vietjetplane.png");


    SDL_Texture* enemyTexture = graphics.loadTexture("virus.png");
    Enemy enemy;


    srand(time(0));
    spawnEnemy(enemy, graphics.renderer, enemyTexture);

    int score=0;

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e )) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        plane.move();
        background.scroll(1);

        graphics.render(background);
        plane.render(graphics.renderer);

        updateEnemy(enemy, graphics.renderer, plane, quit, score);
        enemy.render(graphics.renderer);

        graphics.presentScene();
        SDL_Delay(16);
    }

SDL_DestroyTexture( plane.texture );
SDL_DestroyTexture(enemyTexture);
SDL_DestroyTexture( background.texture );
graphics.quit();
return 0;
}





