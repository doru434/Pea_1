#include "fileReader.h"


fileReader::fileReader()
{
	cout << "Podaj nazwe pliku dla problemu komiwojazera" << endl;
	cin >> fileName;
	file_read_graph(fileName);
}
bool fileReader::file_read_line(ifstream &file, int tab[], int size)
{
	string s;
	getline(file, s);

	if (file.fail() || s.empty())
		return(false);

	istringstream in_ss(s);

	for (int i = 0; i < size; i++)
	{
		in_ss >> tab[i];
		if (in_ss.fail())
			return(false);
	}
	return(true);
}

void fileReader::file_read_graph(string file_name)
{
	ifstream file;
	int tab[4];
	vector <int> vec;
	file.open(file_name.c_str());

	if (file.is_open())
	{
		if (file_read_line(file, tab, 1))
		{
			miasta = tab[0];				//miasta
			int *tab = new int[miasta];
			for (int i = 0; i < miasta; i++)
			{
				tablica.push_back(vec);
				if (file_read_line(file, tab, miasta))
				{
					for (int j = 0; j < miasta; j++)
					{
						tablica[i].push_back(tab[j]);
					}
				}
				else
				{
					cout << "File error - READ EDGE" << endl;
					break;
				}
			}
		}
		else
			cout << "File error - READ INFO" << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

