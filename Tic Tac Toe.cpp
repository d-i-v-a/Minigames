#include <iostream>
using namespace std;

//declare 3x3 grid 
char arr[3][3]={'.','.','.','.','.','.','.','.','.'};

void display()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

bool win(char m)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == m && arr[i][1] == m && arr[i][2] == m)
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (arr[0][j] == m && arr[1][j] == m && arr[2][j] == m)
            return true;
    }

    // Check diagonals
    if (arr[0][0] == m && arr[1][1] == m && arr[2][2] == m)
        return true;

    if (arr[0][2] == m && arr[1][1] == m && arr[2][0] == m)
        return true;

    return false;
}

void playgame()
{
    char player='X';
    int m, n;
    bool gameover=false;
    
    while (!gameover)
    {
        int i=-1, j=-1;
        cout << "Player " << player<<" ";
        cout<<"Enter row coordinate: ";
        cin>>i;
        cout<<"Enter column coordinate: ";
        cin>>j;
        
        if (i < 0 || i >= 3 || j < 0 || j >= 3 || arr[i][j] != '.')
        {
            cout << "Invalid move! Try again." << endl;
            display();
            continue;
        }
            arr[i][j]=player;
            display();
        
        if (win(player))
        {
            cout << "Player " << player << " wins!" << endl;
            gameover = true;
        }
        else if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }

        // Check for a draw
        bool isdraw = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == '.')
                {
                    isdraw = false;
                    break;
                }
            }
            if (!isdraw)
                break;
        }

        if (isdraw)
        {
            cout << "It's a draw!" << endl;
            display();
            gameover = true;
        }
    }
}

int main()
{
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playgame();
    
    return 0;
}




