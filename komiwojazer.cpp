#include "komiwojazer.h"



komiwojazer::komiwojazer(vector<vector <int>> &tab, int mias)
{
	miasta = mias;
	komi = tab;
	droga = 9999999;
}
void komiwojazer::przegladZupelny()
{
	int x = 0;
	int temp1 = 0, temp2 = 0;

	vector <int> test;
	for (int i = 0; i < komi.size(); i++)
	{
		test.push_back(i);
	}
	do {
		temp1 = 0;

		for (int i = 0; i < test.size(); i++)
		{
			if (i < test.size() - 1)
			{
				temp1 += komi[test[i]][test[i + 1]];
			}
			else
			{
				temp1 += komi[test[i]][test[0]];
			}
		}

		if (temp1 < droga)
		{
			show.clear();
			droga = temp1;
			temp2 = x;
			for (int i = 0; i < test.size(); i++)
			{
				show.push_back(test[i]);		
			}
		}
		x++;
	} while (std::next_permutation(test.begin()+1, test.end()));

}
void komiwojazer::zachlanny()
{
	vector <int> show2;
	droga = 0;
	int temp = 9999,temp1=0,n =0;

	show.clear();
	vector <int> check;
	for (int i = 0; i < miasta; i++)
	{
		check.push_back(0);
	}
	check[0] = 1;
	show.push_back(0);
	for (int i = 0; i < komi.size()-1; i++)
	{
		temp = 9999;
		for (int j = 0; j < komi[n].size(); j++)
		{
			if (komi[n][j] < temp && check[j]==0)
			{
				temp = komi[n][j];
				temp1 = j;
			}
		}
		check[temp1] = 1;
		n = temp1;
		show.push_back(n);
		show2.push_back(temp);	
		droga += show2[i];

	}
	show2.push_back(komi[n][0]);
	droga += show2.at(show2.size() - 1);
}
void komiwojazer::podzialuIOgraniczen()
{
	//----------------------------------------------------
	cout << endl;
	for (int i = 0; i < komi.size(); i++)
	{
		for (int j = 0; j < komi.size(); j++)
		{
			cout << komi[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	//----------------------------------------------------X

	vector <int> wierszMin;		// wartości minimalne dla wierszy
	vector <int> kolumnaMin;	// wartości minimalne dla kolumn
	vector <int> wynik;			// droga komiwojazera
	vector <vector <int>> temp;	// tymczasowa macierz, na której przeprowadzane są obliczenia
	int D = 0;					// wartość dolnego ograniczenia
	int maxW = 0;				// wartość maksymalna z minimów wierszy
	int maxK = 0;				// wartość maksymalna z minimów kolumn
	int max = 0;				// wartość maksymalna z minimów wierszy i kolumn
	int kolumna = 0;			// numer kolumny do skrócenia
	int wiersz = 0;				// numer wiersza do skrócenia
	

	for (int i = 0; i < komi.size(); i++)
	{
		wierszMin.push_back(9999);
		kolumnaMin.push_back(9999);
	}
	temp = komi;
	for (int x = 2; x < komi.size(); x++)
	{
		
		if (x != 2)
		{
			//for (int w = 0; w < komi.size()-(x-1); w++)
			//{
			//	temp[w].erase(temp[w].begin()+kolumna);
			//}
			temp.erase(temp.begin() + wiersz);
			//temp.resize(komi.size() - (x - 2));//
			wierszMin.resize(komi.size() - (x - 2));
			//wierszMin.erase(wierszMin.end());
			//kolumnaMin.erase(wierszMin.end());
			kolumnaMin.resize(komi.size() - (x - 2));
		}
		
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[i][j] < wierszMin[i])
				{
					wierszMin[i] = temp[i][j];
				}
			}
		}

		//----------------------------------------------------
		cout << endl;
		for (int i = 0; i < wierszMin.size(); i++)
		{
			cout << wierszMin[i] << "  ";
		}
		cout << endl;
		//----------------------------------------------------X

		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[i][j] != 999)
				{
					temp[i][j] -= wierszMin[i];
				}
			}
		}
		//----------------------------------------------------
		cout << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				cout << temp[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
		//----------------------------------------------------X
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[i][j] < kolumnaMin[j])
				{
					kolumnaMin[j] = temp[i][j];
				}
			}
		}
		//----------------------------------------------------
		cout << endl;
		for (int i = 0; i < kolumnaMin.size(); i++)
		{
			cout << kolumnaMin[i] << "  ";
		}
		cout << endl;
		//----------------------------------------------------X
		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[i][j] != 999)
				{
					temp[i][j] -= kolumnaMin[j];
				}
			}
		}

		for (int i = 0; i < wierszMin.size(); i++)
		{
			D += kolumnaMin[i] + wierszMin[i];
			kolumnaMin[i] = 9999;
			wierszMin[i] = 9999;
		}
		int wf = 1;
		int kf[4] = { 1, 1, 1, 1 };

		for (int i = 0; i < temp.size(); i++)
		{
			for (int j = 0; j < temp.size(); j++)
			{
				if (temp[i][j] == 0)
				{
					if (wf == 1)
					{
						wf = 0;
					}
					else
					{
						if (temp[i][j] < wierszMin[i])
						{
							wierszMin[i] = temp[i][j];
						}
					}
				}
				else
				{
					if (temp[i][j] < wierszMin[i])
					{
						wierszMin[i] = temp[i][j];
					}
				}
				/////////////////////////////////////

				if (temp[i][j] == 0)
				{
					if (kf[j] == 1)
					{
						kf[j] = 0;
					}
					else
					{
						if (temp[i][j] < kolumnaMin[j])
						{
							kolumnaMin[j] = temp[i][j];
						}
					}
				}
				else
				{
					if (temp[i][j] < kolumnaMin[j])
					{
						kolumnaMin[j] = temp[i][j];
					}
				}
			}
			wf = 1;
		}



		//----------------------------------------------------
		cout << endl;
		for (int i = 0; i < kolumnaMin.size(); i++)
		{
			cout << kolumnaMin[i] << "  ";
		}
		cout << endl;
		//----------------------------------------------------X

		//----------------------------------------------------
		cout << endl;
		for (int i = 0; i < wierszMin.size(); i++)
		{
			cout << wierszMin[i] << "  ";
		}
		cout << endl;
		//----------------------------------------------------X

		for (int i = 0; i < wierszMin.size(); i++)
		{
			if (wierszMin[i] > maxW)
			{
				maxW = wierszMin[i];
				wiersz = i;
				wierszMin[i] = 999;
			}
			if (kolumnaMin[i] > maxK)
			{
				maxK = kolumnaMin[i];
				kolumna = i;
				kolumnaMin[i] = 999;
			}
		}
		if (maxK > maxW)
		{
			D += maxK;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i][kolumna] == 0)
				{
					wiersz = i;
					break;
				}
			}
			wynik.push_back(wiersz);
			wynik.push_back(kolumna);
		}
		else
		{
			D += maxW;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[wiersz][i] == 0)
				{
					kolumna = i;
					break;
				}
			}
			wynik.push_back(wiersz);
			wynik.push_back(kolumna);
		}
		komi[kolumna][wiersz] = 999;
		if (temp.size() > (kolumna || wiersz))
		{
			temp[kolumna][wiersz] = 999;
		}
	}

	temp.erase(temp.begin() + kolumna);

	//----------------------------------------------------
	cout << endl << "end" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp.size(); j++)
		{
			cout << temp[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	//----------------------------------------------------X
	
	//----------------------------------------------------
	cout << endl << "end" << endl;
	for (int i = 0; i < komi.size(); i++)
	{
		for (int j = 0; j < komi.size(); j++)
		{
			cout << komi[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	//----------------------------------------------------X

	cout << endl << "Wynik!"<< endl;
	for (int j = 0; j < wynik.size(); j++)
	{
		cout << wynik[j] << "  ";
	}
	cout << endl;
}
void komiwojazer::showPodzialu()
{

}
void komiwojazer::showZ()
{
	cout << "\n\nLiczba miast: " << miasta << "\n\n";

	for (int i = 0; i < komi.size(); i++)
	{
		for (int j = 0; j < komi[i].size(); j++)
		{
			cout << komi[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\nDlugosc trasy: " << droga << "  ";

	cout << show[0] << "-";
	for (int i = 0; i < show.size(); i++)
	{
		if (i < show.size() - 1)
		{
			cout << show[i + 1] << "-";
		}
		else
		{
			cout << show[0] << endl;
		}
	}
}
void komiwojazer::showZach()
{
	cout << "\n\nLiczba miast: " << miasta << "\n\n";

	for (int i = 0; i < komi.size(); i++)
	{
		for (int j = 0; j < komi[i].size(); j++)
		{
			cout << komi[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\nDlugosc trasy: " << droga << "  ";

	cout << show[0] << "-";
	for (int i = 0; i < show.size(); i++)
	{
		if (i < show.size() - 1)
		{
			cout << show[i + 1] << "-";
		}
		else
		{
			cout << show[0] << endl;
		}
	}
}
