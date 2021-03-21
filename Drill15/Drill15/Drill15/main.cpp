#include <Simple_window.h>

int main() {

	Graph_lib::Point winpt(100,100);
	Simple_window win(winpt, 600, 600, "Function graphs");

	Graph_lib::Point xAxisP(100, 300);
	Graph_lib::Point yAxisP(300, 500);
	Graph_lib::Axis xAxis(Graph_lib::Axis::x, xAxisP, 400, 20, "1 = = 20 pixels");
	Graph_lib::Axis yAxis(Graph_lib::Axis::y, yAxisP, 400, 20, "1 = = 20 pixels");
	xAxis.set_color(Graph_lib::Color::red);
	yAxis.set_color(Graph_lib::Color::red);

	win.attach(xAxis);
	win.attach(yAxis);

	win.wait_for_button();

	return 0;

};