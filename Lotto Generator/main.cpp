#include <iostream>
#include <random>
#include <ctime>
#include <map>
const int NUM_BALLS = 49;

int main(int argc, char** argv)
{
	std::map<int, int> ballFreqs;
	for (int i = 1; i < NUM_BALLS + 1; i++)
	{
		ballFreqs[i] = 0;
	}

	int ballPick = 0;
	std::mt19937 randEngine(time(nullptr));
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
	while (counter < 6)
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