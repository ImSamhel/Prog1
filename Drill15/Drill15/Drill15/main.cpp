#include <Simple_window.h>

double one(double x) {
	return 1;
}

double slope(double x) { 
	return x / 2; 
}

double square(double x) { 
	return x * x; 
}

double sloping_cos(double x) {
	return slope(x) + cos(x);
}

int main() {
	int winx = 600;
	int winy = 600;
	Graph_lib::Point winpt(100,100);

	Simple_window win(winpt, winx, winy, "Function graphs");

	int axisLenght = 400;
	int xAxisX = (winx - axisLenght) / 2; 
	int yAxisY = winy - xAxisX;
	int notches = 20;
	std::string axisLabel = "1 = = 20 pixels";

	Graph_lib::Point origo(winx/2, winy/2);

	Graph_lib::Point xAxisP(xAxisX, origo.x);
	Graph_lib::Point yAxisP(origo.y, yAxisY);

	Graph_lib::Axis xAxis(Graph_lib::Axis::x, xAxisP, axisLenght, notches, axisLabel);
	Graph_lib::Axis yAxis(Graph_lib::Axis::y, yAxisP, axisLenght, notches, axisLabel);

	xAxis.set_color(Graph_lib::Color::red);
	yAxis.set_color(Graph_lib::Color::red);

	int start = -10;
	int end = 11;
	int npoints = 400;
	int xscale = 20;
	int yscale = 20;

	Graph_lib::Function oneF(one, start, end, origo, npoints,xscale,yscale);

	Graph_lib::Function slopeF(slope, start, end, origo, npoints, xscale, yscale);

	std::string slopeLabel = "x/2";
	int slopeLabelX = origo.x - abs(start * xscale);
	int slopeLabelY = (origo.y + abs((slope(start))*yscale)) - yscale;
	Graph_lib::Point slopeLabelPt(slopeLabelX,slopeLabelY);
	Graph_lib::Text slopeText(slopeLabelPt,slopeLabel);

	Graph_lib::Function squareF(square, start, end, origo, npoints, xscale, yscale);

	Graph_lib::Function cosine(cos, start, end, origo, npoints, xscale, yscale);
	cosine.set_color(Graph_lib::Color::blue);

	Graph_lib::Function slopingCos(sloping_cos, start, end, origo, npoints, xscale, yscale);
	slopingCos.set_color(Graph_lib::Color::dark_green);

	win.attach(xAxis);
	win.attach(yAxis);
	win.attach(oneF);
	win.attach(slopeF);
	win.attach(slopeText);
	win.attach(squareF);
	win.attach(cosine);
	win.attach(slopingCos);

	win.wait_for_button();

	return 0;

};