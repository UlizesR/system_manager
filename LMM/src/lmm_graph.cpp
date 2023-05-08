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

    void drawFunc(int screenWidth, int screenHeight, std::pair<Func, Color> funcs[], int numFuncs, int minX, int maxX, int minY, int maxY, float xRange, float yRange)
    {
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
    }

    void drawPoints(int numSets, Vector2 points[][2])
    {
        // Draw each set of points
        for (int j = 0; j < numSets; j++) {
            DrawLineStrip(points[j], sizeof(points[j])/sizeof(points[j][0]), BLACK, 2.0);
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
        drawFunc(screenWidth, screenHeight, funcs, numFuncs, minX, maxX, minY, maxY, xRange, yRange);
        
        EndDrawing();
    }
    CloseWindow();
}

}

// std::string yLabel = "y-axis";
//             for (int i = 0; i < yLabel.length(); i++) 
//             {
//                 DrawText(TextFormat("%c", yLabel[i]), 70, 270 + (i * 15), 15, BLACK);
//             }

//             float x_pos = 120;
//             float y_pos = 600;
//             DrawLineEx({ x_pos, 140 }, { x_pos, y_pos }, 2, BLACK); // x-axis
//             DrawLineEx({ x_pos, y_pos }, { 720, y_pos }, 2, BLACK); // y-axis

//             // DrawLineEx({ 112, x_pos }, { x_pos, x_pos }, 2, RED);

//             for (int i = 0; i < (450 / yRange) * 10; i += 6) 
//             {
//                 DrawLineEx({ 114, 90 + (float) i * 10}, { x_pos, 90 + (float) i * 10}, 2, BLACK);
//                 DrawText(TextFormat("%d",(int) ((450 / yRange) * 10) - i), 100, 90 + (float) i * 10, 10, BLACK);
//             }
//             for (int i = (600 / xRange) * 10; i > 0; i -= 6) 
//             {
//                 DrawLineEx({ x_pos + (float) i * 10, y_pos }, { x_pos + (float) i * 10, 548 }, 2, BLACK);
//                 DrawText(TextFormat("%d", i), x_pos + (float) i * 10, 550, 10, BLACK);
//             }