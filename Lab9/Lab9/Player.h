#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROCK = 1, PAPER = 2, SCISSORS = 3;

class Player
{
    
public:
    
    Player();
    Player(string player_name);
    
    string getName() const;
    
    int getWins() const;
    int addWins();
    
    int getLosses() const;
    int addLosses();
    
    int getDraws() const;
    int addDraws();
    
    int getRPSThrow();
    
    double getWinRecord();
    
    string toString();
    
private:
    
    string name;
    int wins=0;
    int losses=0;
    int draws=0;
    
};