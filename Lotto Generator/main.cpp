#include <iostream>
#include <random>
#include <ctime>
#include <map>
static int NUM_BALLS = 0;
static int NUM_BALLS_TO_DRAW = 0;

int main(int argc, char** argv)
{
	std::cout << "Please select a Lotto format (enter the number and press return)" << std::endl<<std::endl;
	std::cout << "1. National Lottery. 49 Balls, 6 Drawn" << std::endl;
	std::cout << "2. Custom" << std::endl;
	int in = 0;
	std::cin >> in;
	if (in == 1)
	{
		NUM_BALLS_TO_DRAW = 6;
		NUM_BALLS = 49;
	}
	else if (in == 2)
	{
		std::cout << "How many balls do you want to draw?" << std::endl;
		std::cin >> NUM_BALLS_TO_DRAW;
		std::cout << "How many balls do you want to be in the hat?" << std::endl;
		std::cin >> NUM_BALLS;
	}

	

	std::map<int, int> ballFreqs;
	for (int i = 1; i < NUM_BALLS + 1; i++)
	{
		ballFreqs[i] = 0;
	}

	int ballPick = 0;
	std::mt19937 randEngine((unsigned int)time(nullptr));
	std::uniform_int_distribution<int> randRoll(1, NUM_BALLS);

	int counter = 0;
	while (counter < 10000)
	{
		ballPick = randRoll(randEngine);
		ballFreqs[ballPick]++;
		counter++;
	}
	
	int mostFreq = 0;
	int ball = 0;
	
	counter = 0;

	std::cout << "This Weeks Balls Are Going To Be: " << std::endl << std::endl;;
	while (counter < NUM_BALLS_TO_DRAW)
	{
		for (auto& it = ballFreqs.begin(); it != ballFreqs.end(); it++)
		{
			if (it->second > mostFreq)
			{
				ball = it->first;
				mostFreq = it->second;
			}
			
		}
		std::cout << ball << "  ";
		ballFreqs.erase(ball);
		mostFreq = 0;
		ball = 0;	
		counter++;		
	}
	std::cout << std::endl;
	char tmp;
	std::cin >> tmp;
	return 0;
}