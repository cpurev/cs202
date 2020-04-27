//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms
#define WIN32

#include "tspsolver.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Native_File_Chooser.H>

void solve(const std::string& str, const int s) {
	if (str.size() == 0)
		return;
	std::string dir;
	std::transform(str.begin(), str.end(), std::back_inserter(dir), 
		[](unsigned char c) -> unsigned char {if (c == '\\') return '/'; return c; });

	CityList defList;
	defList.load(dir);

	//SVG element storing vector
	std::vector<std::string> svg;
	TspSolver ts;

	//The solved path container
	CityList us;
	us = defList;

	//Algorithm solve
	switch (s) {
	case 2:
		ts.solveGreedy(us); break;
	case 1:
		ts.solveRandomly(us); break;
	case 0:
		ts.solveMyWay(us); break;
	default:
		return;
	}

	//Push back header
	svg.push_back("<html xmlns=\"http://www.w3.org/1999/xhtml\" xmlns:svg = \"http://www.w3.org/2000/svg\" >\n");
	svg.push_back("<body>\n");
	svg.push_back("<svg:svg width=\"2250px\" height=\"2500px\">\n");
	svg.push_back("<!-- FROM HERE THE DATA-->\n");

	std::string dots = "";
	double X = 0, Y = 0;

	//This could be solved dynamically 
	//By adding min max functions and finding them
	//In this case I manually searched the min and max in data 
	double minX = defList.getMinX(), minY = defList.getMinY();
	double maxX = defList.getMaxX(), maxY = defList.getMaxY();

	//Line value
	double previousX = 0, previousY = 0;
	double startX = 0, startY = 0;

	//Loop for each city in list
	for (auto n = 0; n < defList.size(); n++) {
		previousX = X;
		previousY = Y;
		//Create a dot
		dots = "<svg:circle cx=\"";

		//Scaling values
		X = 1280 - 1080 * (us.node(n)->x() - minX) / (maxX - minX);
		Y = 2260 - 2250 * (us.node(n)->y() - minY) / (maxY - minY);

		//This is where X goes on graph
		dots += std::to_string(Y);

		//This is where Y goes on graph
		dots += "\" cy=\"";
		dots += std::to_string(X);

		//This is the circle radius
		dots += "\" r=\"";
		dots += '1';

		//Set circle color
		dots += "\" fill=\"#0078ff\"/>";

		//Push back the element/city
		svg.push_back(dots + "\n");

		//Draw a line to previous dot
		//First dots previous dot is the last dot in list
		//which is X/Y not calculated yet.
		if (n == 0) {
			startX = X; startY = Y;
			continue;
		}
		dots = "<svg:line x1=\""; dots += std::to_string(previousY);
		dots += "\" y1=\""; dots += std::to_string(previousX);
		dots += "\" x2=\""; dots += std::to_string(Y);
		dots += "\" y2=\""; dots += std::to_string(X);

		dots += "\" style=\"stroke:rgb(189,0,255);stroke-width:1\" />";

		//Push back the path
		svg.push_back(dots + "\n");

	}

	//Connect the last city with starting city
	dots = "<svg:line x1=\""; dots += std::to_string(Y);
	dots += "\" y1=\""; dots += std::to_string(X);
	dots += "\" x2=\""; dots += std::to_string(startY);
	dots += "\" y2=\""; dots += std::to_string(startX);

	dots += "\" style=\"stroke:rgb(189,0,255);stroke-width:1\" />";

	//Push back the path
	svg.push_back(dots + "\n");

	//Push back tail
	svg.push_back("</svg:svg>\n");
	svg.push_back("</body>\n");
	svg.push_back("</html>\n");

	//Output
	std::ofstream outf("tspsolved.svg");
	for (auto v : svg)
		outf.write(v.c_str(), v.size());
	outf.close();
}

void browseCallback(Fl_Widget* w, void* data) {
	Fl_Input* input = (Fl_Input*)data;

	Fl_Native_File_Chooser fnfc;
	fnfc.title("Choose TSPLIB file to solve");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("TSP\t*.tsp\n");
	fnfc.directory("/var/tmp");           // default directory to use
	// Show native chooser
	switch (fnfc.show()) {
	case -1: printf("ERROR: %s\n", fnfc.errmsg());    break;  // ERROR
	case  1: printf("CANCEL\n");                      break;  // CANCEL
	default: printf("PICKED: %s\n", fnfc.filename()); break;  // FILE CHOSEN
	}

	input->value(fnfc.filename());
}

void greedy(Fl_Widget* w, void* data) {
	Fl_Input* input = (Fl_Input*)data;

	solve(input->value(), 2);
}
void random(Fl_Widget* w, void* data) {
	Fl_Input* input = (Fl_Input*)data;

	solve(input->value(), 1);
}
void myway(Fl_Widget* w, void* data) {
	Fl_Input* input = (Fl_Input*)data;

	solve(input->value(), 0);
}

int main(int argc, char** argv) {
	Fl_Window* window = new Fl_Window(300, 215, "TSPLIB Path Solve into SVG file");
	window->begin();
	
	Fl_Button* browsef = new Fl_Button(5, 10, 90, 25, "Browse File");
	Fl_Input* inputf = new Fl_Input(105, 10, 185, 25);
	browsef->callback(browseCallback, inputf);

	Fl_Button* buttonSG = new Fl_Button(5, 45, 90, 25, "Greedy");
	Fl_Button* buttonSR = new Fl_Button(105, 45, 90, 25, "Random");
	Fl_Button* buttonSM = new Fl_Button(205, 45, 90, 25, "MyWay");
	buttonSG->callback(greedy, inputf);
	buttonSR->callback(random, inputf);
	buttonSM->callback(myway, inputf);

	Fl_Output* distance = new Fl_Output(70, 80, 200, 25, "Distance:");

	//Instructions prompt
	Fl_Text_Buffer* buff = new Fl_Text_Buffer();
	Fl_Text_Display* instructions = new Fl_Text_Display(5, 130, 290, 75, "Instructions");
	instructions->buffer(buff);
	buff->text("Choose a TSPLIB file and then choose one\nof the 3 algorithms to solve. It will show the\ntotal distance travalled and will output\nSVG file that will open in browser.");

	window->end();
	window->resizable();
	window->show(argc, argv);
	return (Fl::run());
}