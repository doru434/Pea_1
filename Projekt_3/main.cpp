#include "fileReader.h"

int main()
{
	cout << "				Zadanie projektowe nr 3" << endl;
	cout << "	Implementacja i analiza efektywnosci algorytmow optymalnych o pseudowielomianowej zlozonosci \n		  obliczeniowej dla wybranych problemow kombinatorycznych  " << endl;
	bool check;
	int wybor = 0, wybor2 = 0, wybor3 = 0;

	while (wybor != 1 && wybor != 2 && wybor != 3 && wybor != 5)
	{
		cout << "Co chcesz testowac?\n";
		cout << "(2)Problem komiwojazera\n(3)Wyjscie\n(else)Ponowny wybor\n";
		cin >> wybor;

		switch (wybor)
		{
		case 2:
		{
			fileReader reader;
			komiwojazer wojazer(reader.tablica, reader.miasta);
			while (wybor2 != 3)
			{
				wybor = 0, wybor2 = 0, wybor3 = 0;
				cout << "\nCo chcesz testowac?\n";
				cout << "(1)Przeglad zupelny\n(2)Algorytm zachlanny\n(3)podzialuIOgraniczen\n(4)Wyjście\n(else)Ponowny wybor\n";
				cin >> wybor2;

				switch (wybor2)
				{
				case 1:
					wojazer.przegladZupelny();
					wojazer.showZ();
					break;
				case 2:
					wojazer.zachlanny();
					wojazer.showZach();
					break;
				case 3:
					wojazer.podzialuIOgraniczen();
					break;
				case 4:
					break;
				default:
					break;
				}
			}
			break;
		}
		case 5:
			break;
		default:
			break;
		}
	}
	system("Pause");
	return 0;
}

