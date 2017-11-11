#include "komiwojazer.h"

class fileReader
{
public:
	string fileName;
	vector<vector<int>> tablica;

	int miasta;

public:
	fileReader();

	bool file_read_line(ifstream &file, int tab[], int size);
	void file_read_graph(string file_name);

};

