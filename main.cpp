#include <iostream> 
#include <algorithm>

#define MAXCOUNT		52

//black jack

using namespace std;

int Pocket[MAXCOUNT]; // 0 + 1 ~ 51 + 1
int PlayerScore = 0;
int ComputerScore = 0;
int PickCards[4];


void Init()
{
	for (int i = 0; i < MAXCOUNT; ++i)
	{
		Pocket[i] = i + 1;
	}
}

void Shuffle()
{
	srand((unsigned int)time(nullptr));

	//shuffle, 알고리즘, algorithm
	for (int i = 0; i < 10000; ++i)
	{
		int First = rand() % MAXCOUNT;
		int Second = rand() % MAXCOUNT;
		int Temp = Pocket[First];
		Pocket[First] = Pocket[Second];
		Pocket[Second] = Temp;
	}
}

void ChooseCard()
{
	for (int i = 0; i < 4; ++i)
	{
		PickCards[i] = Pocket[i];
	}
}

void Draw()
{
	for (int i = 0; i < 4; ++i)
	{
		int CardType = PickCards[i] / 13;

		//cout << CardsType[CardType] << endl;
		if (CardType == 0)
		{
			//Spade
			cout << "♠ ";
		}
		else if (CardType == 1)
		{
			//Clover
			cout << "♣ ";
		}
		else if (CardType == 2)
		{
			//Heart
			cout << "♥ ";
		}
		else //(CardType == 3)
		{
			//Diamond
			cout << "◆ ";
		}

		int CardNumber = (Pocket[i] % 13) + 1;
		if (CardNumber == 11)
		{
			//J
			cout << "J " << endl;
		}
		else if (CardNumber == 12)
		{
			//Q
			cout << "Q " << endl;
		}
		else if (CardNumber == 13)
		{
			//K
			cout << "K " << endl;
		}
		else
		{
			//숫자
			cout << CardNumber << endl;
		}

		if (i < 2)
		{
			//Com
			if (CardNumber > 10) // 11, 12, 13. J Q K
			{
				ComputerScore += 10;
			}
			else
			{
				ComputerScore += CardNumber;
			}
		}
		else
		{
			//Player
			if (CardNumber > 10) // 11, 12, 13. J Q K
			{
				PlayerScore += 10;
			}
			else
			{
				PlayerScore += CardNumber;
			}
		}
	}
}

void Process()
{
	if (ComputerScore > 21)
	{
		cout << ComputerScore << " : " << PlayerScore << endl;
		cout << "Player Win" << endl;
	}
	else if (PlayerScore > 21)
	{
		cout << ComputerScore << " : " << PlayerScore << endl;
		cout << "Computer Win" << endl;
	}
	else if (ComputerScore > PlayerScore)
	{
		cout << ComputerScore << " : " << PlayerScore << endl;
		cout << "Computer Win" << endl;
	}
	else
	{
		cout << ComputerScore << " : " << PlayerScore << endl;
		cout << "Player Win" << endl;
	}
}

int main()
{
	Init();

	for (int i = 0; i < 10; i++)
	{
		Shuffle();
	}

	ChooseCard();

	Draw();

	Process();

	return 0;
}

