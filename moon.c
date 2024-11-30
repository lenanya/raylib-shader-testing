#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define WIDTH 600
#define HEIGHT 600
#define SQ(v) v*v

uint8_t R(float xn, float yn, uint8_t frame) {
    float val = ((xn - 0.5) * (xn - 0.5) + (yn - 0.5) * (yn - 0.5));
    if (val <= 0.1) {
        return  SQ(xn) * 255;
    }
    return 0;
}

uint8_t G(float xn, float yn, uint8_t frame) {
    return R(xn, yn, frame);
}

uint8_t B(float xn, float yn, uint8_t frame) {
    return R(xn, yn, frame);
}

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Moon");
    SetTargetFPS(60);
    uint8_t frame = 0;
    int dir = 1;
    while(!WindowShouldClose()) {
        frame += dir;
        if (frame == 255) {
            dir = -1;
        }
        if (frame == 0) {
            dir = 1;
        }
        BeginDrawing();
        ClearBackground((Color){0, 0, 0, 0});
        for (size_t y = 0; y < HEIGHT; ++y) {
            for (size_t x = 0; x < WIDTH; ++x) {
                float xn = (float)x / WIDTH;
                float yn = (float)y / HEIGHT;
                uint8_t a = 255;
                uint8_t r = R(xn, yn, frame); 
                uint8_t g = G(xn, yn, frame); 
                uint8_t b = B(xn, yn, frame);
                DrawPixelV((Vector2){x, y}, (Color){r, g, b, a});                
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}