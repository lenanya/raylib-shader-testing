#include <raylib.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

#define WIDTH 600
#define HEIGHT 600

uint8_t R(float xn, float yn, uint8_t frame) {
    float val = ((xn-0.5) * (xn-0.5)) + ((yn-0.5) * (yn-0.5));
    if (val <= 0.15) {
        //return yn * 255;
        //return (yn / xn / xn / yn / xn + xn / yn * xn) * sin(yn) / sin(xn) * frame;
        return (xn / yn / yn / xn / yn + yn / xn * yn ) * sin(xn) / sin(yn) * frame / sin(xn) * 0.1 + 1;   
    }
    if (val > 0.1 && val <= 0.105) {
        return xn * frame;
    }
    return xn * frame;
}

uint8_t G(float xn, float yn, uint8_t frame) {
    float val = ((xn-0.5) * (xn-0.5)) + ((yn-0.5) * (yn-0.5));
    if (val <= 0.15) {
        return (xn * yn * yn + xn * yn - yn * xn) * xn / yn * frame * 1.5;
    }
    if (val > 0.1 && val <= 0.105) {
        return yn * frame;
    }
    return (xn * yn) * frame;
}

uint8_t B(float xn, float yn, uint8_t frame) {
    float val = ((xn-0.5) * (xn-0.5)) + ((yn-0.5) * (yn-0.5));
    if (val <= 0.15) {
        return (xn / yn / yn / xn / yn + yn / xn * yn ) * cos(xn) / cos(yn) * frame / yn * 0.1;
    }
    if (val > 0.1 && val <= 0.105) {
        return xn * yn * frame;
    }
    return yn * frame;
}

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Shaders");
    SetTargetFPS(60);
    uint8_t frame = 145;
    int dir = 1;
    while(!WindowShouldClose()) {
        frame += dir;
        if (frame == 255) {
            dir = -1;
        }
        if (frame == 145) {
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