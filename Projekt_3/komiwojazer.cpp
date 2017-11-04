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
