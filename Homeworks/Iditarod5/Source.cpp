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
	double baseX = us.node(0)->x() / 1000, baseY = us.node(9983)->y() / 1000;

	for (auto n = 0; n < us.size(); n++) {
		dots = "<svg:circle cx=\"";


		X = us.node(n)->x() / 1000 - baseX;
		X = 34 + n;
		Y = us.node(n)->y() / 1000 - baseY;
		Y = 640 - n;

		dots += std::to_string(X);
		dots += "\" cy=\"";
		dots += std::to_string(Y);
		dots += "\" r=\"";

		/*if (n / 10000 > 1)
			dots += "11";
		else if (n / 1000 > 1)
			dots += "10";
		else if (n / 100 > 1)
			dots += '8';
		else if (n / 10 > 1)
			dots += '7';
		else
			dots += '6';*/
		dots += '2';

		dots += "\" fill=\"black\"/>";

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