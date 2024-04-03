
//   tic tac toe game program in c++

/*
#include<iostream>
#include<conio.h>
using namespace std;
char square [10]={'0','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
int main()
{
    int player =1, i ,choice;
    char mark ;
    do{
        board();
    if (player % 2)
        player =1;
    else
        player =2;
    cout<<"player"<<player <<"enter a number:";
    cin>>choice;
    if(player ==1)
    {
        mark ='X';
    }
    else
        {
        mark ='o';
    }
    if (choice == 1 && square [1] == '1')
        square [1] =mark;
    else if(choice == 2 && square [2] == '2')
        square [2] = mark;
    else if(choice == 3 && square [3] == '3')
        square [3] = mark;
    else if(choice == 4 && square [4] == '4')
        square [4] = mark;
    else if(choice == 5 && square [5] == '5')
        square [5] = mark;
    else if(choice == 6 && square [6] == '6')
        square [6] = mark;
    else if(choice == 7 && square [7] == '7')
        square [7] = mark;
    else if(choice == 8 && square [8] == '8')
        square [8] = mark;
    else if(choice == 9 && square [9] == '9')
        square [9] = mark;
    else
        {
            cout<<"invalid move because you enterd a invalid number";
            player --;
            cin.ignore();
            cin.get();
        }
        i=checkwin();
        player ++;
    }
        while(i== -1);
    board();
    if (i==1)
        cout<<" ==>  \a player "<<--player<<" win ";
    else
        cout<<" ==>  \a Game Drow";
    cin.ignore();
    cin.get();
    return 0;
    getch();
}
void board()
{
    system("cls");
    cout<<"\n==================";
    cout<<"\nTic Tac Toe \n";
    cout<<"\n==================";
    cout<<"Player 1 (x) - Player 2 (0)"<<endl << endl;
    cout<<endl;
    cout<< "     |     |     "<<endl;
    cout<<"  "<< square[1] <<  "  |  "<< square[2] <<"  |  "<< square[3] <<endl;

    cout<< "_____|_____|______"<<endl;
    cout<< "     |     |      "<<endl;

    cout<<"  "<< square[4] <<  "  |  "<< square[5] <<"  |  "<< square[6] <<endl;

    cout<< "_____|_____|______"<<endl;
    cout<< "     |     |      "<<endl;

     cout<<"  "<< square[7] <<  "  |  "<< square[8] <<"  |  "<< square[9] <<endl;

    cout<< "_____|_____|______"<<endl;
}
int checkwin()
{
    if (square [1] == square [2] && square [2] == square [3])
        return 1;
    else if(square [4] == square [5] && square [5] == square [6])
        return 1;
    else if(square [7] == square [8] && square [8] == square [9])
        return 1;
    else if(square [1] == square [4] && square [4] == square [7])
    return 1;
    else if(square [2] == square [5] && square [5] == square [8])
    return 1;
    else if(square [3] == square [6] && square [6] == square [9])
    return 1;
    else if(square [1] == square [5] && square [5] == square [9])
    return 1;
    else if(square [3] == square [5] && square [5] == square [7])
    return 1;
    else if(square [1] != '1' && square [2] != '2' && square [3] != '3'
         && square [4] !='4' && square [5] !='5' && square [6] !='6'
         && square [7] !='7' && square [8] !='8' && square [9] !='9')
    return 0;
    else
    return -1;

    }
*/

#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

// Initialize the game board with empty spaces
void initializeBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the board
void displayBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl
             << "-------------" << endl;
    }
}

// Check if the current player has won
bool checkWin(char player)
{
    for (int i = 0; i < 3; ++i)
    {
        // Check rows and columns
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Check if the game is a draw
bool checkDraw()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
                return false; // If there's an empty space, the game is not a draw
        }
    }
    return true; // If the board is full and no one has won, it's a draw
}

int main()
{
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    initializeBoard();

    cout << "TIC-TAC-TOE GAME" << endl;

    while (!gameWon && !gameDraw)
    {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        int row, col;
        cin >> row >> col;

        // Check if the chosen cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(currentPlayer))
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameWon = true;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameDraw = true;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    cout << "Do you want to play again? (Y/N): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y')
    {
        initializeBoard();
        main(); // Start a new game
    }
    else
    {
        cout << "Thanks for playing! Goodbye!" << endl;
    }

    return 0;
}

/*

This code sets up a basic Tic-Tac-Toe game with a 3x3 game board, alternating between "X" and "O" players, checking for wins and draws, and allowing players to play again if they wish.
*/


