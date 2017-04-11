#ifndef WINDOW_H
#define WINDOW_H

#include <qwt/qwt_thermo.h>
#include <qwt/qwt_knob.h>
#include <qwt/qwt_slider.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include <QBoxLayout>
#include <QSpinBox>

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window(); // default constructor - called when a Window is declared without arguments

	void timerEvent( QTimerEvent * );

public slots:
	void setGain(double gain);
	void setBins(int bins);
// internal variables for the window class
private:
  // graphical elements from the Qwt library - http://qwt.sourceforge.net/annotated.html
	QwtKnob      knob;
	QwtThermo    thermo;
	QwtPlot      plot,plot2;
	QwtPlotCurve amp_curve, spec_curve;
	QSpinBox     spinner;

	// layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
	QVBoxLayout  vLayout, vPlots;  // vertical layout
	QHBoxLayout  hLayout;  // horizontal layout

	static const int plotDataSize = 128;

	// data arrays for the plot
	double xData[plotDataSize];
	double yData[plotDataSize];

	double gain;
	int bins, pbins;
	int count;
};

#endif // WINDOW_H
