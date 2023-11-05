#include "ball.hpp"
#include "paddle.hpp"
#include "aipaddle.hpp"

#include "raylib.h"

static int WIDTH = 1280;
static int HEIGHT = 800;

Ball *ball;
Paddle *player;
AiPaddle *ai;

int main()
{
    InitWindow(WIDTH, HEIGHT, "Pong[Raylib]");

    SetTargetFPS(60);

    ball = new Ball(WIDTH/2, HEIGHT/ 2, 7, 7, 20);
    player = new Paddle(WIDTH - 35, HEIGHT/ 2 - 60, 7, 25, 120);
    ai = new AiPaddle(10, HEIGHT/ 2 - 60, 6, 25, 120);

    while (!WindowShouldClose()) {
        BeginDrawing();

        // Update objects
        ball->update();
        player->update();
        ai->update(ball->y());

        // Checking for collisions
        if (CheckCollisionCircleRec({ball->x(), ball->y()}, ball->radius(), {player->x(), player->y(), player->width(), player->height()})) {
            ball->setSpeedX(ball->speedX() * -1);
        }

        if (CheckCollisionCircleRec({ball->x(), ball->y()}, ball->radius(), {ai->x(), ai->y(), ai->width(), ai->height()})) {
            ball->setSpeedX(ball->speedX() * -1);
        }

        // Drawing objects
        ClearBackground(BLACK);
        DrawLine(WIDTH / 2, 0, WIDTH / 2, HEIGHT, WHITE);
        ball->draw();
        player->draw();
        ai->draw();
        DrawText(TextFormat("%i", ball->aiScore()), WIDTH / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", ball->playerScore()), 3 * WIDTH / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
