#include "GameManager.h"
#include <iostream>
using namespace std;
#include <string>

void GameManager::Drawman(int tries)
{
	cout<<endl<<endl;
	cout<<"  ________"<<endl;
	cout<<"  |  |"<<endl;
	cout<<"  |";if (tries>=1) cout<<"  O   "<<endl;
	cout<<"  |";if (tries>=3) cout<<" /|\\   "<<endl;
	cout<<"  |";if (tries>=5) cout<<" / \\   "<<endl;
	cout<<"  |"<<endl;
	cout<<"__|__"<<endl;
}

GameManager::GameManager(): MAX_TRIES(5)
{
    words[0] = "computer";
	words[1] = "pakistan";
	words[2] = "oriented";
	words[3] = "antartica";
	words[4] = "amazon";
	words[5] = "africa";
	words[6] = "purple";
	words[7] = "nihari";
	words[8] = "parrot";
	words[9] = "petrol";
    player_name = "default";

   
}

void GameManager::showTitle()
{
    cout<<"\t\t\t HANGMAN :: THE GAME "<<endl;
    cout<<"\t\t\t Menu OF The Game : "<<endl;
}

void GameManager::showRules()
{
    // welcome the user
    cout<<endl;
    cout<<"\t\t\t HOW TO PLAY"<<endl;
    cout<<"\t\t\t-------------"<<endl;
	cout<<"Welcome to hangman."<<endl;
    cout<<"You have to guess a country Name."<<endl;
	cout<<"Each letter is represented by a star."<<endl;
	cout<<"You have to type only one letter in one try."<<endl;
	cout<< "You have "<<MAX_TRIES<<" tries to try and guess the word."<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Press any key to continue."<<endl;
    cin.ignore();
    cin.get();
}

void GameManager::startGame()
{
    int num_of_wrong_guesses = 0;  // Initialize the current score to 100.
    //choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];

    string unknown = string(word.length(), '*');

    // Loop until the guesses are used up
    system("cls");
	while (num_of_wrong_guesses < MAX_TRIES)
	{
        cout<<endl;
		cout<<unknown<<endl;
		cout<<"Guess a letter: ";
        char letter;
		cin>>letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
        cout<<endl;
		if (letterFill(letter, unknown) == 0)
		{
			
			cout<<"Whoops! That letter isn't in there!"<<endl;
			
			num_of_wrong_guesses++;
            Drawman(num_of_wrong_guesses);
		}
		else
		{
			cout<<"You found a letter! Isn't that exciting!"<<endl;
		}
		// Tell user how many guesses has left.
		cout<<"You have "<<MAX_TRIES - num_of_wrong_guesses;
		cout<<" guesses left."<<endl;
		// Check if user guessed the word.
		if (word == unknown)
		{
			cout<<word<<endl;
			cout<<"Woohoo! You got it!"<<endl;
			cout<<"You are FREE !!"<<endl;
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{	cout<<"\nSorry, you lose...you've been hanged."<<endl;
		cout<<"The word was : "<<word<<endl;
       
     }
}
int GameManager::letterFill(char guess, string &guessword)
{
	int i;
	int matches = 0;
	int len = word.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == word[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

void GameManager::getPlayerName()
{
    cout<<"Please enter your name: ";
    cin>>player_name;
}

