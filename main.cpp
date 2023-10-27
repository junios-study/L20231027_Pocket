#include <iostream> 

#define MAXCOUNT		52

using namespace std;

int main()
{
	int Pocket[MAXCOUNT]; // 0 + 1 ~ 51 + 1

	for (int i = 0; i < MAXCOUNT; ++i)
	{
		Pocket[i] = i + 1;
	}

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 10000; ++i)
	{
		int First = rand() % MAXCOUNT;
		int Second = rand() % MAXCOUNT;
		int Temp = Pocket[First];
		Pocket[First] = Pocket[Second];
		Pocket[Second] = Temp;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << Pocket[i] << endl;
	}

	return 0;
}

