#include <raylib.h>
#include <stdint.h>
#include <math.h>

#define COLS 10
#define ROWS 10
#define TILESIZE 40

#define screenWidth 900
#define screenHeight 600

#define PLAYER_FOV 90
#define DEG 0.0174533

// Map Grid
 int map[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


void renderMap2D(){
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
        Color color = WHITE;
      if(map[row][col] == 1) {
        color = BLACK;
      }
      DrawRectangle(col * TILESIZE, row * TILESIZE, TILESIZE - 1, TILESIZE - 1, color);
    }
  }
}


Vector2 playerPosition = {(float) TILESIZE / 2 * 10, (float) TILESIZE / 2 * 10};
double playerAngle;
Vector2 directionV;

void renderPlayer2D() {
  double endPosX = playerPosition.x + directionV.x * 50;
  double endPosY = playerPosition.y + directionV.y * 50;

  DrawCircleV(playerPosition, 6, RED);
  DrawLine(playerPosition.x, playerPosition.y, endPosX, endPosY, RED);
}

void updatePlayer2D(){
  

  if (IsKeyDown(KEY_D)){
    // turn clockwise, increse angle
    playerAngle += 2*DEG;
    // reset angle once too big
    if (playerAngle > 2*PI) playerAngle -= 2*PI;
    directionV.x = cos(playerAngle);
    directionV.y = sin(playerAngle);
  }
  if (IsKeyDown(KEY_A)){
    // turn anti-clockwise, decrese angle
    playerAngle -= 2*DEG;
    // reset angle once too big
    if (playerAngle > 2*PI) playerAngle += 2*PI;
    directionV.x = cos(playerAngle);
    directionV.y = sin(playerAngle);
  }
  if (IsKeyDown(KEY_W)){
    playerPosition.x += directionV.x;
    playerPosition.y += directionV.y;
  }
  if (IsKeyDown(KEY_S)){
    playerPosition.x -= directionV.x;
    playerPosition.y -= directionV.y;
  }

}




int main(void) {
  InitWindow(TILESIZE * 10, TILESIZE * 10, "Raycaster");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    // Rendering
    BeginDrawing();
    renderMap2D();
    updatePlayer2D();
    renderPlayer2D();
    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
