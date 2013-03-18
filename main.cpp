#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;


//using namespace std;
struct configContainer
{
string carrier;
string battleship;
string submarine;
string destroyer;
string patrolBoat;
int fieldsize;
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
vector< vector<char> > ConstructGamefield(configContainer&);
configContainer ReadConfig();
void StringSplitter(stringstream &, string &, string &);

int main()
{
	vector<vector<char>> gamefield;
	configContainer initial_config;

	srand(time(0));
	initial_config = ReadConfig();
	if(!initial_config.battleship.empty() && !initial_config.carrier.empty() && !initial_config.destroyer.empty() && !initial_config.patrolBoat.empty() && !initial_config.submarine.empty())
	{
		cout <<"Ships succesfully loaded from config file." <<endl;
	}
	else
	{
		cout <<"Ships were not loaded succesfully from config file. Please input them manually." <<endl;
	}

	gamefield = ConstructGamefield(initial_config);
	cout <<initial_config.battleship <<endl;
	system("PAUSE");
	return 0;
}
configContainer ReadConfig()
{
	configContainer ships;
	string configLine;
	string substr;
	ifstream configFile("config.ini");

	//TEMP HACK
	ships.fieldsize = 10;
	//END TEMP HACK

	if(configFile)
		cout <<"File found" <<endl;
	else
		cout <<"File not found" <<endl;
	while(configFile.good()) //read until bad bit or EOF
	{
		getline(configFile, configLine);
		if(configLine[0] == '#')
		{
			continue;
		}

		else
		{
			stringstream stream(configLine); //deposit line to a stringstream
			while (getline(stream, substr, ',')) //split to substrings with delimiter ','
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
vector< vector<char> > ConstructGamefield(configContainer &configinfo)
{
	//TO-DO - error checking

	vector< vector<char> > constructed_game_field(configinfo.fieldsize);
	for(int i=0; i<configinfo.fieldsize; i++)
	{
			
	}

	return constructed_game_field;
}