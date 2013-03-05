#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;


//using namespace std;
struct shipContainer
	{
	string carrier;
	string battleship;
	string submarine;
	string destroyer;
	string patrolBoat;
	};

void Menu();
void InputShips();
void PlayGame();
void Shoot();
void RandShips();
void SaveLog();
void Spyplane();
void AnnoyPlayer();
void Secretary();
void Config();
//cmd.exe linewidth: 80 chars
void SaveLoad();
void MachineCommander();
shipContainer ReadConfig();
void StringSplitter(stringstream &, string &, string &);

int main()
{
	shipContainer ships;
	srand(time(0));
	ships = ReadConfig();
	if(!ships.battleship.empty() && !ships.carrier.empty() && !ships.destroyer.empty() && !ships.patrolBoat.empty() && !ships.submarine.empty())
	{
		cout <<"Ships succesfully loaded from config file." <<endl;
	}
	else
	{
		cout <<"Ships were not loaded succesfully from config file. Please input them manually." <<endl;
	}


	system("PAUSE");
	return 0;
}
shipContainer ReadConfig()
{
	shipContainer ships;
	string configLine;
	string substr;
	ifstream configFile("config.ini");
	if(configFile)
		cout <<"File found" <<endl;
	else
		cout <<"File not found" <<endl;
	while(configFile.good())
	{
		getline(configFile, configLine);
		if(configLine[0] == '#')
		{
			continue;
		}

		else
		{
			stringstream stream(configLine);
			while (getline(stream, substr, ','))
			{
				if(substr == "carrier")
				{
					StringSplitter(stream, substr, ships.carrier);
				}
				if(substr == "battleship")
				{
					StringSplitter(stream, substr, ships.battleship);
				}
				if(substr == "submarine")
				{
					StringSplitter(stream, substr, ships.submarine);
				}
				if(substr == "destroyer")
				{
					StringSplitter(stream, substr, ships.destroyer);
				}
				if(substr == "patrolBoat")
				{
					StringSplitter(stream, substr, ships.patrolBoat);
				}	
			}
		}
	}

	return ships;
}
void StringSplitter(stringstream &stream, string &splitted, string &ship)
{
	for(int i=0; getline(stream, splitted, ','); i++)
	{				
		ship.append(splitted);
	}
}