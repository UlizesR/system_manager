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

    void Graph::Draw(std::pair<Func, Color> funcs[], int numFuncs, int minX, int maxX, int minY, int maxY) {
    // Initialize the window and the drawing buffer
    SetConfigFlags(FLAG_MSAA_4X_HINT); // Enable anti-aliasing
    InitWindow(screenWidth, screenHeight, "Graph Window");
    SetTargetFPS(60);

    // Compute the range of values to be displayed
    float xRange = static_cast<float>(maxX - minX);
    float yRange = static_cast<float>(maxY - minY);

    // Compute the interval between grid lines
    float xInterval = xRange / 100.0f; // 10 grid lines along x-axis
    float yInterval = yRange / 100.0f; // 10 grid lines along y-axis

    // Main game loop
    while (!WindowShouldClose())
    {
        // Clear the drawing buffer
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the grid lines
        for (int i = minX; i <= maxX; i += xInterval) {
            if (i == 0) continue; // skip the y-axis line
            DrawLine((i - minX) * screenWidth / xRange, 0, (i - minX) * screenWidth / xRange, screenHeight, LIGHTGRAY);
            if (i % 5 == 0) 
            {            
                DrawText(TextFormat("%d", i), (i - minX) * screenWidth / xRange, (screenHeight / 2) + 2.5, 10, BLACK); // Draw the x-axis label
                DrawLine((i - minX) * screenWidth / xRange, 0, (i - minX) * screenWidth / xRange, screenHeight, DARKGRAY);
            }        
        }

        for (int i = minY; i <= maxY; i += yInterval) {
            if (i == 0) continue; // skip the x-axis line
            DrawLine(0, ((i - minY) * screenHeight / yRange), screenWidth, ((i - minY) * screenHeight / yRange), LIGHTGRAY);
            if (i % 5 == 0) 
            {
                DrawText(TextFormat("%d", -1 * i), (screenWidth / 2) + 2.5,  ((i - minY) * screenHeight / yRange), 10, BLACK); // Draw the y-axis label
                DrawLine(0, ((i - minY) * screenHeight / yRange), screenWidth, ((i - minY) * screenHeight / yRange), DARKGRAY);
            }
        }


        DrawLineEx((Vector2){0, static_cast<float>(screenHeight / 2)}, (Vector2){static_cast<float>(screenWidth), static_cast<float>(screenHeight / 2)}, 1, BLACK);
        DrawLineEx((Vector2){static_cast<float>(screenWidth / 2), 0}, (Vector2){static_cast<float>(screenWidth / 2), static_cast<float>(screenHeight)}, 1, BLACK);

        // Draw each function
        for (int j = 0; j < numFuncs; j++) {
            const float xScale = screenWidth / xRange;
            const float yScale = screenHeight / yRange;
            const int numPoints = screenWidth;
            Vector2 points[numPoints];
            for (int i = 0; i < numPoints; ++i) {
                const float x = static_cast<float>(i) / xScale + minX;
                const float y = funcs[j].first(x);
                points[i] = {(x - minX) * xScale, screenHeight - ((y - minY) * yScale)};
            }
            for (int i = 0; i < numPoints - 1; ++i) {
                DrawLineEx(points[i], points[i + 1], 2.0, funcs[j].second);
            }
        }

        EndDrawing();
    }
    CloseWindow();
}


}
