//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms
#define WIN32

#include "tspsolver.hpp"
#include <fstream>
#include <sstream>

#include <FL/Fl_Window.H>

void solve(const std::string& str, const int s) {
	CityList defList;
	defList.load(str);

	//SVG element storing vector
	std::vector<std::string> svg;
	int dataB = 0, dataE = 0;
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

	//Input to vector
	std::ifstream inf("graph.svg");
	if (!inf) {			//Error check
		std::cout << "File error";
		return;
	}
	std::string line;
	while (std::getline(inf, line)) {	//Get each line and push_back with newline
		svg.push_back(line + "\n");
		if (line == "      <!-- FROM HERE THE DATA-->")
			dataE = svg.size();
		if (line == "    </svg:svg>")
			dataB = svg.size();
	}
	inf.close();

	line = "";
	//Save data after city data
	for (auto i = dataB - 1; i < svg.size(); i++)
		line += svg[i];

	svg.resize(dataE);

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

	//After data is inserted push back the saved elements that is not part of data
	std::istringstream iss(line);
	line = "";
	while (std::getline(iss, line, '\n'))
		svg.push_back(line + "\n");

	//Output
	std::ofstream outf("graph.svg");
	for (auto v : svg)
		outf.write(v.c_str(), v.size());
	outf.close();
}

int main(void) {

	solve("usa13509.tsp", 1);

	return 0;
}