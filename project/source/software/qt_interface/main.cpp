#include <window.h>

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// create the window
	Window window;
	window.show();

	// call the window.timerEvent function every 40 ms
	window.startTimer(9);

	// execute the application
	return app.exec();
}
