#include "lmm_graph.h"

namespace lmm {

void createGraphWindow(const GraphDataList& dataList) {
    // Create a QApplication instance
    int argc = 0;
    char** argv = nullptr;
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("Graph Window");

    // Set the fixed size of the window
    window.setFixedSize(800, 600);

    // Create a chart and add it to the main window
    QChart* chart = new QChart();
    chart->legend()->hide();  // Hide the legend
    window.setCentralWidget(new QChartView(chart, &window));

    // Create a value axis for the x-axis
    QValueAxis* xAxis = new QValueAxis();
    chart->addAxis(xAxis, Qt::AlignBottom);

    // Create a line series for the x-axis
    QLineSeries* xAxisSeries = new QLineSeries();
    xAxisSeries->append(QPointF(0, 0));
    xAxisSeries->append(QPointF(4, 0));
    chart->addSeries(xAxisSeries);
    xAxisSeries->attachAxis(xAxis);

    // Create a value axis for the y-axis
    QValueAxis* yAxis = new QValueAxis();
    chart->addAxis(yAxis, Qt::AlignLeft);

    // Create a line series for the y-axis
    QLineSeries* yAxisSeries = new QLineSeries();
    yAxisSeries->append(QPointF(0, 0));
    yAxisSeries->append(QPointF(0, 20));
    chart->addSeries(yAxisSeries);
    yAxisSeries->attachAxis(yAxis);

    // Iterate over the dataList
    for (const auto& dataPair : dataList) {
        const std::variant<Vec, Func, DataPoints>& dataVariant = dataPair.first;
        const QColor& color = dataPair.second;

        if (std::holds_alternative<Vec>(dataVariant)) {
            const Vec& vecData = std::get<Vec>(dataVariant);

            // Create a line series for the Vec data
            QLineSeries* series = new QLineSeries();
            series->setColor(color);

            // Add data points to the series
            for (int i = 0; i < vecData.size(); ++i) {
                series->append(QPointF(i, vecData[i]));

                // Add arrowhead at the end of the vector
                if (i == vecData.size() - 1) {
                    double arrowSize = 0.2; // Adjust arrow size as needed
                    double angle = atan2(vecData[i], i) + M_PI;
                    series->append(QPointF(i - arrowSize * cos(angle - M_PI / 6), vecData[i] - arrowSize * sin(angle - M_PI / 6))); // Add arrowhead point
                    series->append(QPointF(i, vecData[i])); // Add data point again
                    series->append(QPointF(i - arrowSize * cos(angle + M_PI / 6), vecData[i] - arrowSize * sin(angle + M_PI / 6))); // Add another arrowhead point
                }
            }

            // Add the series to the chart
            chart->addSeries(series);
            series->attachAxis(xAxis);
            series->attachAxis(yAxis);
        } else if (std::holds_alternative<Func>(dataVariant)) {
            const Func& funcData = std::get<Func>(dataVariant);

            // Create a line series for the function data
            QLineSeries* series = new QLineSeries();
            series->setColor(color);

            // Add data points to the series by evaluating the function
            for (int i = 0; i <= 100; ++i) {
                double x = i / 10.0;
                double y = funcData(x);
                series->append(QPointF(x, y));
            }

            // Add the series to the chart
            chart->addSeries(series);
            series->attachAxis(xAxis);
            series->attachAxis(yAxis);
        } else if (std::holds_alternative<DataPoints>(dataVariant)) {
            const DataPoints& pointsData = std::get<DataPoints>(dataVariant);

            // Create a scatter series for the DataPoints
            QScatterSeries* series = new QScatterSeries();
            series->setColor(color);
            series->setMarkerSize(10); // Adjust marker size as desired

            // Add the DataPoints to the series
            for (const QPointF& point : pointsData) {
                series->append(point);
            }

            // Add the series to the chart
            chart->addSeries(series);
            series->attachAxis(xAxis);
            series->attachAxis(yAxis);
        }
    }

    // Set the ranges of the axes
    yAxis->setRange(0, 20);
    xAxis->setRange(0, 4);

    // Show the grid lines
    xAxis->setGridLineVisible(true);
    yAxis->setGridLineVisible(true);

    // Display the main window
    window.show();

    // Run the application event loop
    app.exec();
}

} // namespace lmm
