#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm> 

#include <cstdlib>
#include <ctime>

using namespace std;


class komiwojazer
{
public:
	int miasta;

	int droga;
	vector <int> show;

	vector<vector <int>> komi;
	komiwojazer(vector<vector <int>> &tab, int mias);
	void przegladZupelny();
	void zachlanny();
	void podzialuIOgraniczen();
	void showPodzialu();
	void showZ();
	void showZach();
};

