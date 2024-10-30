#include "GameManager.cpp"
#include <iostream>
using namespace std;
int main()
{
    GameManager game;

    int choice;
    do
    {
        system("cls");
        game.showTitle();

        cout<<endl;
        cout<<"\t1. Play\n";
        cout<<"\t2. How to play?\n";
        cout<<"\t3. Exit\n";
        cout<<"Enter your choice (1/2/3): ";
        cin>>choice;

        if (choice == 1)
        {
            game.getPlayerName();
            char ch;
            do {
                game.startGame();
                cout<<"Want to play again? (y/n): ";
                cin>>ch;
              
            } while (ch == 'y');
        }
        else if (choice == 2)
        {
            game.showRules();
        }
        else if (choice == 3)
        {
            cout<<"Bye bye"<<endl;
        }
        else
       {
            cout<<"Invalid choice"<<endl;
        }
    } while (choice != 3);
	 

    return 0;
}