#ifndef LMM_PLOT_H
#define LMM_PLOT_H

#include "raylib.h"

namespace lmm
{
    namespace plot
    {
        class Plot
        {
            public:
                Plot(int width, int height) : screenWidth(width), screenHeight(height) {}
                void plot(int x, int y);
                void y_label(char* label);
                void x_label(char* label);
                void plot_label(char* label);
                // void plot_legend();
                void draw_plot();
                
            private:
                int screenWidth;
                int screenHeight;

                // Plot parameters
                int x_label;
                int y_label;
                int plot_label;
                int plot_legend;
                int plot_legend_text;

        };
    }
}

#endif // LMM_PLOT_H