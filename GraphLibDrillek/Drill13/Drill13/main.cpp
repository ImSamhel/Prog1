#include <Simple_window.h>

int main() {
	Simple_window win {Point{10,10},900,1000,"Drill13"}; // 800x1000 a drillben, de a next button szeretete fontosabb

	int x_size = 800; // get the size of our window
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	Lines grid;

	for (int x = x_grid; x <= x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,y_size }); 

	for (int y = y_grid; y <= y_size; y += y_grid)
		grid.add(Point{ 0,y }, Point{ x_size,y });

	win.attach(grid);

	Graph_lib::Vector_ref<Graph_lib::Rectangle> rectangles;

	for (int i = 0; i < (x_size/x_grid); i++) {
		int x = i * x_grid;
		Point point1{ x,x };
		Point point2{x+100,x+100};
		rectangles.push_back(new Graph_lib::Rectangle{ point1,point2 });
		rectangles[rectangles.size() - 1].set_fill_color(Color::red);
		rectangles[rectangles.size() - 1].set_color(Color::red);
		win.attach(rectangles[rectangles.size() - 1]);
	}

	Image ceci1{ Point{0,600},"cecike1.jpg" };
	Image ceci2{ Point{0,400},"cecike1.jpg" };
	Image ceci3{ Point{200,600},"cecike1.jpg" };
		
	win.attach(ceci1);
	win.attach(ceci2);
	win.attach(ceci3);

	Point pennyPoint{ 0,0 };
	Image pennymarket{ pennyPoint,"pennymarket.jpg" };
	win.attach(pennymarket);
	
	while (win.wait_for_button()) {
		if (pennyPoint.x < 700) {
			pennyPoint.x += 100;
			pennymarket.move(100, 0);
		}
		else if(pennyPoint.y == 700 && pennyPoint.x == 700) {
			pennyPoint.y -= 700;
			pennyPoint.x -= 700;
			pennymarket.move(-700, -700);
		} else {
			pennyPoint.x -= 700;
			pennyPoint.y += 100;
			pennymarket.move(-700, 100);
		}
	}
	
	for (int i = 0; i < rectangles.size(); i++)
		delete& rectangles[i];
		
	return 0;
}