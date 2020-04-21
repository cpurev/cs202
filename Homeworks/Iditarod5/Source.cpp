//Source.cpp
//Chuluunbat Purev
//2020-4-13
//Testing path solving algortihms

#include "tspsolver.hpp"
#include <fstream>
#include <sstream>

int main(void) {

	/*CityList vm;
	vm.load("vm1748.tsp");
	CityList d15;
	d15.load("d15112.tsp");
	CityList d18;
	d18.load("d18512.tsp");
	CityList rl;
	rl.load("rl5934.tsp");*/

	CityList us;
	us.load("usa13509.tsp");
	std::vector<std::string> svg;
	int dataB = 0, dataE = 0;

	//The solved path container
	CityList path;
	path = us;

	//Input to vector
	std::ifstream inf("graph.svg");
	if (!inf) {			//Error check
		std::cout << "File error";
		return 0;
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
	//In this case i manually searched the min and max in data 
	double minX = us.node(0)->x() , minY = us.node(9983)->y() ;
	double maxX = us.node(13508)->x() , maxY = us.node(13508)->y();

	//Loop for each city in list
	for (auto n = 0; n < us.size(); n++) {
		dots = "<svg:circle cx=\"";

		//Scaling values
		X = 1980 - 1920 * (us.node(n)->x() - minX) / (maxX - minX);
		Y = 2080 - 1080 * (us.node(n)->y() - minY) / (maxY - minY);

		//This is where X goes on graph
		dots += std::to_string(Y);

		//This is where Y goes on graph
		dots += "\" cy=\"";
		dots += std::to_string(X);

		//This is the circle radius
		dots += "\" r=\"";
		dots += '1';

		//Set circle color
		dots += "\" fill=\"red\"/>";

		//Push back the element/city
		svg.push_back(dots + "\n");
		//svg.push_back(std::to_string(us.node(n)->id()) + "\n");
	}

	//After data is inserted push back the saved elements that is not part of data
	std::istringstream iss(line);
	line = "";
	while (std::getline(iss, line, '\n'))
		svg.push_back(line + "\n");

	//for (auto v : svg)
	//	std::cout << v << " ";

	//Output
	std::ofstream outf("graph.svg");
	for(auto v : svg)
		outf.write(v.c_str(), v.size());
	outf.close();

	return 0;
}