#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"
#include "lmm_functions.h"

namespace lmm
{
    class Graph {
        public:
        
            Graph(int width, int height) : screenWidth(width), screenHeight(height) {}
            void Draw(std::pair<Func, Color> funcs[], int numFuncs, int minX, int maxX, int minY, int maxY);
            void drawFunc(int screenWidth, int screenHeight, std::pair<Func, Color> funcs[], int numFuncs, int minX, int maxX, int minY, int maxY, float xRange, float yRange);
            void drawPoints(int numSets, Vector2 points[][2]);

        private:
            int screenWidth;
            int screenHeight;
    };

}
#endif // GRAPH_H
