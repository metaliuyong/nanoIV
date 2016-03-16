#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"

class Plot: public QObject
{
    Q_OBJECT
public:
    Plot();

    double xmin, xmax, ymin, ymax;

    void SetPlotWidget(QCustomPlot* plotwidget);
    QCustomPlot* plotwidget();

    void InitializeParameters();

    QCPGraph* AddGraph();

    void DeleteGraph(int graphnumber);

    void DeleteGraph(QCPGraph* graph);

    void ShowGraph(int graphindex, bool show);

    void ShowGraph(QCPGraph* graph, bool show);

    void SetXAxisText(QString text);

    void SetYAxisText(QString text);

    void SetAutoscaleX(bool autoscalex);
    void SetAutoscaleY(bool autoscaley);

    void ZoomOutX();

    void ZoomInX();

    void ZoomOutY();

    void ZoomInY();





public slots:
    void UpdatePlot(QCPGraph* graph, QVector<double> x, QVector<double> y);
    void UpdatePlot(int graphnumber, QVector<double> x, QVector<double> y);
    void UpdateAveragePlot(QCPGraph* graph, QVector<double> x, QVector<double> y);

    void Set_PlotStyle_ActiveForward(QCPGraph* graph);
    void Set_PlotStyle_InactiveForward(QCPGraph* graph);
    void Set_PlotStyle_AverageActiveForward(QCPGraph* graph);
    void Set_PlotStyle_AverageInactiveForward(QCPGraph* graph);

    void Set_PlotStyle_ActiveReverse(QCPGraph* graph);
    void Set_PlotStyle_InactiveReverse(QCPGraph* graph);
    void Set_PlotStyle_AverageActiveReverse(QCPGraph* graph);
    void Set_PlotStyle_AverageInactiveReverse(QCPGraph* graph);



private:
    QCustomPlot* plotwidget_;

    QCPScatterStyle iv_activeforwardstyle_, iv_inactiveforwardstyle_,  iv_averageactiveforwardstyle_, iv_averageinactiveforwardstyle_;
    QCPScatterStyle iv_activereversestyle_, iv_inactivereversestyle_,  iv_averageactivereversestyle_, iv_averageinactivereversestyle_;


    QCPScatterStyle currentsample_style_;

    bool autoscalex_;
    bool autoscaley_;

    float zoomoutmultiplier_, zoominmultiplier_;


};

#endif // PLOT_H
