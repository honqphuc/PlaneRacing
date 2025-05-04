#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

#include "game.h"

void Plane::move(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    dx = 0;
    dy = 0;

    if (currentKeyStates[SDL_SCANCODE_W]) dy -= speed;
    if (currentKeyStates[SDL_SCANCODE_S]) dy += speed;
    if (currentKeyStates[SDL_SCANCODE_A]) dx -= speed;
    if (currentKeyStates[SDL_SCANCODE_D]) dx += speed;

    if (x + dx >= 0 && x + dx <= SCREEN_WIDTH - 125) {
        x += dx;
        }
    if (y + dy >= 0 && y + dy <= SCREEN_HEIGHT - 125) {
        y += dy;
        }
}

void Plane::render(SDL_Renderer* renderer) {
    SDL_Rect rect = {x, y, 125, 125};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Enemy::move(){
    y+= speed;
}

void Enemy::render(SDL_Renderer* renderer) {
    SDL_Rect rect = {x, y, 150, 150};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void spawnEnemy(Enemy& enemy, SDL_Renderer* renderer, SDL_Texture* enemyTexture) {
    enemy.x = rand() % (SCREEN_WIDTH - 100);
    enemy.y = -100;
    enemy.texture = enemyTexture;
}


void updateEnemy(Enemy& enemy, SDL_Renderer* renderer, Plane& plane, bool& quit, int& score) {
    enemy.move();
    SDL_Rect planeRect = {plane.x, plane.y, 110, 110};
    SDL_Rect enemyRect = {enemy.x, enemy.y, 110, 110};

    if (enemy.y > SCREEN_HEIGHT) {
        score += 10;
        spawnEnemy(enemy, renderer, enemy.texture);
    }

    if (SDL_HasIntersection(&planeRect, &enemyRect)) {
        quit = true;
        std::string message = std::to_string(score);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game Over!", "mÁy bAY đÃ b! ViruSs hACk ", NULL);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Điểm số", message.c_str(), NULL );
    }
}



