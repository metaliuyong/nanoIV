#include "plot.h"

#include <iostream>

#include "qcustomplot.h"


Plot::Plot()
{
    iv_activeforwardstyle_.setShape(QCPScatterStyle::ssCircle);
    iv_activeforwardstyle_.setPen(QPen(QColor(233, 188, 27)));
    iv_activeforwardstyle_.setBrush(QColor(233, 188, 27));
    iv_activeforwardstyle_.setSize(7);


    iv_inactiveforwardstyle_.setShape(QCPScatterStyle::ssCircle);
    iv_inactiveforwardstyle_.setPen(QPen(QColor(31, 218, 154)));
    iv_inactiveforwardstyle_.setBrush(QColor(31, 218, 154));
    iv_inactiveforwardstyle_.setSize(7);

    iv_averageactiveforwardstyle_.setShape(QCPScatterStyle::ssCircle);
    iv_averageactiveforwardstyle_.setPen(QPen(QColor(212, 63, 63)));
    iv_averageactiveforwardstyle_.setBrush(QColor(212, 63, 63));
    iv_averageactiveforwardstyle_.setSize(7);


    iv_averageinactiveforwardstyle_.setShape(QCPScatterStyle::ssCircle);
    iv_averageinactiveforwardstyle_.setPen(QPen(QColor(0, 172, 233)));
    iv_averageinactiveforwardstyle_.setBrush(QColor(0, 172, 233));
    iv_averageinactiveforwardstyle_.setSize(7);

    iv_activereversestyle_.setShape(QCPScatterStyle::ssSquare);
    iv_activereversestyle_.setPen(QPen(QColor(233, 188, 27)));
    iv_activereversestyle_.setBrush(Qt::white);
    iv_activereversestyle_.setSize(7);


    iv_inactivereversestyle_.setShape(QCPScatterStyle::ssSquare);
    iv_inactivereversestyle_.setPen(QPen(QColor(31, 218, 154)));
    iv_inactivereversestyle_.setBrush(Qt::white);
    iv_inactivereversestyle_.setSize(7);

    iv_averageactivereversestyle_.setShape(QCPScatterStyle::ssSquare);
    iv_averageactivereversestyle_.setPen(QPen(QColor(212, 63, 63)));
    iv_averageactivereversestyle_.setBrush(Qt::white);
    iv_averageactivereversestyle_.setSize(7);


    iv_averageinactivereversestyle_.setShape(QCPScatterStyle::ssSquare);
    iv_averageinactivereversestyle_.setPen(QPen(QColor(0, 172, 233)));
    iv_averageinactivereversestyle_.setBrush(Qt::white);
    iv_averageinactivereversestyle_.setSize(7);

    autoscalex_ = true;
    autoscaley_ = true;

    zoomoutmultiplier_ = 1.2;
    zoominmultiplier_ = 0.75;


}

void Plot::SetPlotWidget(QCustomPlot* plotwidget)
{
    plotwidget_ = plotwidget;
    plotwidget_->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    return;
}




QCustomPlot* Plot::plotwidget()
{
    return plotwidget_;
}


void Plot::UpdatePlot(int graphnumber, QVector<double> x, QVector<double> y)
{
    static int currentgraphnumber = -1;
    if(currentgraphnumber != graphnumber)
    {
        for(int i = 0; i < plotwidget_->graphCount(); i++)
        {
            if(i == graphnumber)
            {

            }
            else
            {
                plotwidget_->graph(i)->setScatterStyle(iv_inactiveforwardstyle_);

            }
        }
    }
    currentgraphnumber = graphnumber;

    plotwidget_->setVisible(true);
    plotwidget_->graph(graphnumber)->setData(x, y);

    if(autoscalex_ == true)
    {
        plotwidget_->xAxis->rescale(false);
    }

    if(autoscaley_ == true)
    {
        plotwidget_->yAxis->rescale(false);
    }

    plotwidget_->replot();
    return;

}

void Plot::UpdatePlot(QCPGraph* graph, QVector<double> x, QVector<double> y)
{
    graph->setData(x, y);
    if(autoscalex_ == true)
    {
        plotwidget_->xAxis->rescale(false);
    }

    if(autoscaley_ == true)
    {
        plotwidget_->yAxis->rescale(false);
    }

    plotwidget_->replot();
    return;
}

void Plot::Set_PlotStyle_ActiveForward(QCPGraph* graph)
{
    graph->setScatterStyle(iv_activeforwardstyle_);
    graph->setPen(QPen(QColor(233, 188, 27)));

    return;
}

void Plot::Set_PlotStyle_InactiveForward(QCPGraph* graph)
{
    graph->setScatterStyle(iv_inactiveforwardstyle_);
    graph->setPen(QPen(QColor(31, 218, 154)));


    return;
}

void Plot::Set_PlotStyle_AverageActiveForward(QCPGraph* graph)
{
    graph->setScatterStyle(iv_averageactiveforwardstyle_);
    graph->setPen(QPen(QColor(212, 63, 63)));

    return;
}

void Plot::Set_PlotStyle_AverageInactiveForward(QCPGraph* graph)
{
    graph->setScatterStyle(iv_averageinactiveforwardstyle_);

    graph->setPen(QPen(QColor(0, 172, 233)));
    return;
}

void Plot::Set_PlotStyle_ActiveReverse(QCPGraph* graph)
{
    graph->setScatterStyle(iv_activereversestyle_);
    graph->setPen(QPen(QColor(233, 188, 27)));

    return;
}

void Plot::Set_PlotStyle_InactiveReverse(QCPGraph* graph)
{
    graph->setScatterStyle(iv_inactivereversestyle_);

    graph->setPen(QPen(QColor(31, 218, 154)));
    return;
}

void Plot::Set_PlotStyle_AverageActiveReverse(QCPGraph* graph)
{
    graph->setScatterStyle(iv_averageactivereversestyle_);
    graph->setPen(QPen(QColor(212, 63, 63)));

    return;
}

void Plot::Set_PlotStyle_AverageInactiveReverse(QCPGraph* graph)
{
    graph->setScatterStyle(iv_averageinactivereversestyle_);

    graph->setPen(QPen(QColor(0, 172, 233)));
    return;
}


void Plot::UpdateAveragePlot(QCPGraph* graph, QVector<double>x, QVector<double> y)
{
    graph->setData(x, y);
    if(autoscalex_ == true)
    {
        plotwidget_->xAxis->rescale(false);
    }

    if(autoscaley_ == true)
    {
        plotwidget_->yAxis->rescale(false);
    }

    plotwidget_->replot();
    return;
}

QCPGraph* Plot::AddGraph()
{
    QCPGraph* graph = plotwidget_->addGraph();


    return graph;
}

void Plot::DeleteGraph(int graphnumber)
{
    plotwidget_->removeGraph(graphnumber);
    plotwidget_->replot();
    return;
}

void Plot::DeleteGraph(QCPGraph* graph)
{
    plotwidget_->removeGraph(graph);
    plotwidget_->replot();
    return;
}

void Plot::ShowGraph(int graphindex, bool show)
{
    if(graphindex > plotwidget_->graphCount())
    {
        return;
    }
    else
    {
        plotwidget_->graph(graphindex)->setVisible(show);
        plotwidget_->replot();
    }



    return;
}

void Plot::ShowGraph(QCPGraph* graph, bool show)
{
    if(graph == NULL)
    {
        return;
    }
    else
    {
        graph->setVisible(show);
        plotwidget_->replot();
    }

    return;
}


void Plot::SetXAxisText(QString text)
{
    plotwidget_->xAxis->setLabel(text);

    return;
}

void Plot::SetYAxisText(QString text)
{
    plotwidget_->yAxis->setLabel(text);
    return;
}

void Plot::SetAutoscaleX(bool autoscalex)
{
    autoscalex_ = autoscalex;
    return;
}

void Plot::SetAutoscaleY(bool autoscaley)
{
    autoscaley_ = autoscaley;
    return;
}

void Plot::ZoomOutX()
{
    float oldxrangelower = plotwidget_->xAxis->range().lower;
    float oldxrangeupper = plotwidget_->xAxis->range().upper;


    float newxrangelower = oldxrangelower * zoomoutmultiplier_;
    float newxrangeupper = oldxrangeupper * zoomoutmultiplier_;

    const QCPRange newxrange(newxrangelower, newxrangeupper);

    plotwidget_->xAxis->setRange(newxrange);
    plotwidget_->replot();
    return;
}

void Plot::ZoomInX()
{
    float oldxrangelower = plotwidget_->xAxis->range().lower;
    float oldxrangeupper = plotwidget_->xAxis->range().upper;


    float newxrangelower = oldxrangelower * zoominmultiplier_;
    float newxrangeupper = oldxrangeupper * zoominmultiplier_;

    const QCPRange newxrange(newxrangelower, newxrangeupper);

    plotwidget_->xAxis->setRange(newxrange);
    plotwidget_->replot();

    return;
}

void Plot::ZoomOutY()
{
    float oldyrangelower = plotwidget_->yAxis->range().lower;
    float oldyrangeupper = plotwidget_->yAxis->range().upper;


    float newyrangelower = oldyrangelower * zoomoutmultiplier_;
    float newyrangeupper = oldyrangeupper * zoomoutmultiplier_;

    const QCPRange newyrange(newyrangelower, newyrangeupper);

    plotwidget_->yAxis->setRange(newyrange);
    plotwidget_->replot();
    return;
}

void Plot::ZoomInY()
{
    float oldyrangelower = plotwidget_->yAxis->range().lower;
    float oldyrangeupper = plotwidget_->yAxis->range().upper;


    float newyrangelower = oldyrangelower * zoominmultiplier_;
    float newyrangeupper = oldyrangeupper * zoominmultiplier_;

    const QCPRange newyrange(newyrangelower, newyrangeupper);

    plotwidget_->yAxis->setRange(newyrange);
    plotwidget_->replot();
    return;
}

