#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameManager
{
    private:
        const int MAX_TRIES;
        string word;
        string words[10];
        string player_name;
        int letterFill (char, string&);
        

    public:
        GameManager();
        void getPlayerName();
        void showRules();
        void startGame();
        void showTitle();
        void Drawman (int);
};

#endif