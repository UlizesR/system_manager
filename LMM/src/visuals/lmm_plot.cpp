#include "lmm_plot.h"

void DrawLineStrip(Vector2* points, int numPoints, Color color, int thickness)
{
    for (int i = 0; i < numPoints - 1; i++)
    {
        DrawLineEx(points[i], points[i+1], thickness, color);
    }
}

void drawPlotData(bool border = false)
{
    if (border) DrawRectangleLinesEx({ 120, 90, 100, 100 }, 2, BLACK);
    DrawLineEx({ 120, 90 }, { 120, 510 }, 2, BLACK);
    DrawLineEx({ 120, 510 }, { 680, 510 }, 2, BLACK);
}

namespace lmm
{
    namespace plot
    {
        void Plot::plot(int x, int y)
        {

        }

        void Plot::y_label(char* label)
        {

        }

        void Plot::x_label(char* label)
        {

        }

        void Plot::plot_label(char* label)
        {

        }

        void Plot::draw_plot()
        {
            SetConfigFlags(FLAG_MSAA_4X_HINT); // Enable anti-aliasing
            InitWindow(screenWidth, screenHeight, "Plot Window");
            SetTargetFPS(60);

            while(!WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawLineEx((Vector2){0,0}, (Vector2){80, 60}, 4, BLACK);
                EndDrawing();
            }
        }

        // void Plot::plot_legend()
        // {

        // }

    }
} // namespace lmm
