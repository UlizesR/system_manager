#include "lmm_graph.h"

namespace lmm
{

    void DrawLineStrip(Vector2* points, int numPoints, Color color, int thickness)
    {
        for (int i = 0; i < numPoints - 1; i++)
        {
            DrawLineEx(points[i], points[i+1], thickness, color);
        }
    }

    void Graph::Draw(std::pair<Func, Color> funcs[], int numFuncs) {
        // Initialize the window and the drawing buffer
        SetConfigFlags(FLAG_MSAA_4X_HINT); // Enable anti-aliasing
        InitWindow(screenWidth, screenHeight, "Graph Window");
        SetTargetFPS(60);

        // Main game loop
        while (!WindowShouldClose())
        {
            // Clear the drawing buffer
            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw the grid lines
            const int xInterval = 10;
            const int yInterval = 10;
            for (int i = 0; i < screenWidth; i += xInterval) {
                DrawLine(i, 0, i, screenHeight, LIGHTGRAY);
                if (i % 50 == 0 && i != 0) {
                    DrawText(TextFormat("%i", i - (screenWidth / 2)), (float)i+2.5, (screenHeight / 2) + 2.5, 10, BLACK); // Draw the x-axis label
                }
            }
            for (int i = 0; i < screenHeight; i += yInterval) {
                DrawLine(0, i, screenWidth, i, LIGHTGRAY);
                if (i % 50 == 0 && i != 0) {
                    DrawText(TextFormat("%i", (screenHeight / 2) - i), (screenWidth / 2) + 2.5, i, 10, BLACK); // Draw the y-axis label
                }
            }

            DrawLineEx((Vector2){0, static_cast<float>(screenHeight / 2)}, (Vector2){static_cast<float>(screenWidth), static_cast<float>(screenHeight / 2)}, 2, BLACK);
            DrawLineEx((Vector2){static_cast<float>(screenWidth / 2), 0}, (Vector2){static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight)}, 2, BLACK);

            // Draw each function
            for (int j = 0; j < numFuncs; j++) {
                const float xScale = 0.1f;
                const float yScale = 50.0f;
                const int xOrigin = screenWidth / 2;
                const int yOrigin = screenHeight / 2;
                const int numPoints = screenWidth;
                Vector2 points[numPoints];
                for (int i = 0; i < numPoints; ++i) {
                    const float x = (i - xOrigin) * xScale;
                    const float y = funcs[j].first(x) * yScale;
                    points[i] = (Vector2){static_cast<float>(i), yOrigin - y};
                }
                DrawLineStrip(points, numPoints, funcs[j].second, 2); // twice as thick
            }

            // End drawing and swap buffers
            EndDrawing();
        }

        // Close the window and clean up resources
        CloseWindow();
    }
}
