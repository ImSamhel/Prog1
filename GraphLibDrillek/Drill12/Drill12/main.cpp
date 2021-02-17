#include <Simple_window.h>

int main()
{
	try {
		int windowPointX = 300;
		int windowPointY = 300;
		int windowLengthX = 600;
		int windowLengthY = 400;
		string windowLabel = "";
		Point windowPoint{ windowPointX,windowPointY };
		Simple_window window{ windowPoint, windowLengthX, windowLengthY, windowLabel };
		window.set_label("My window");
		
		Image image1{ Point{0,0}, "igen.jpg" };
		image1.move(0, 1);
		window.attach(image1);

		int axisPointX = 20;
		int axisPointY = 350;

		Point axisPoint{ axisPointX,axisPointY };

		int xAxisLength = 500;
		int xAxisNotches = 10;
		string xAxisLabel = "X axis";

		Axis axisX{ Axis::x, axisPoint, xAxisLength, xAxisNotches, xAxisLabel };
		axisX.set_color(Color::white);
		axisX.label.set_color(Color::black);
		axisX.label.set_font_size(25);
		axisX.label.set_font(Font::times_bold);
		window.attach(axisX);

		int yAxisLength = 320;
		int yAxisNotches = 10;
		string yAxisLabel = "Y axis";

		Axis axisY{ Axis::y, axisPoint, yAxisLength, yAxisNotches, yAxisLabel };
		axisY.set_color(Color::white);
		axisY.label.set_color(Color::white);
		axisY.label.set_font_size(25);
		axisY.label.set_font(Font::times_bold);
		window.attach(axisY);

		double sinRange1 = 0;
		double sinRange2 = 50;
		Point sinPoint{ axisPointX,50 };
		int sinPoints = 1000;
		double sinScaleX = 100;
		double sinScaleY = 20;

		Function sine{ sin, sinRange1, sinRange2, sinPoint, sinPoints, sinScaleX, sinScaleY };
		sine.set_color(Color::cyan);
		window.attach(sine);

		Point polyPoint1{ 42,222 };
		Point polyPoint2{ 69,333 };
		Point polyPoint3{ 420,69 };

		Graph_lib::Polygon poly;
		poly.add(polyPoint1);
		poly.add(polyPoint2);
		poly.add(polyPoint3);
		poly.set_color(Color::dark_red);
		poly.set_style(Line_style::solid);
		poly.set_fill_color(Color::red);
		window.attach(poly);

		Point rectPoint{ 150,220 };
		int rectWidth = 150;
		int rectHeight = 40;
		Graph_lib::Rectangle rect{rectPoint,rectWidth,rectHeight};
		rect.set_color(Color::black);
		rect.set_fill_color(Color::dark_magenta);
		window.attach(rect);
		
		Closed_polyline poly_rect;
		poly_rect.add(Point{ 69,69 });
		poly_rect.add(Point{ 69,200 });
		poly_rect.add(Point{ 420,200 });
		poly_rect.add(Point{ 420,69 });
		poly_rect.add(Point{ 200,130 });
		poly_rect.set_color(Graph_lib::Color::dark_green);
		poly_rect.set_fill_color(Color::green);
		window.attach(poly_rect);

		string textString1 = "Why are we using FLTK?";
		Point textPoint1 { 150,165 };
		Text text1{ textPoint1, textString1};
		text1.set_font(Font::times);
		text1.set_font_size(20);
		window.attach(text1);

		Circle myCircle{ Point{100,200},50 };
		myCircle.set_color(Color::dark_magenta);
		myCircle.set_style(Line_style::solid);
		myCircle.set_fill_color(Color::yellow);
		window.attach(myCircle);

		Mark m{ Point{100,200},'x' };
		window.attach(m);

		window.wait_for_button();
	}
	catch (exception& e) {
		return 1;
	} 
}