#include<iostream>

using namespace std;

char turn = 'X';

void display_board(char board[][3])
{
	system("cls");
	cout<< "\n\n   T I C K   C R O S S   G A M E \n\n"<<endl;
	cout<<"\tPlayer1 [X] \n\tplayer2 [O]\n\n";
	
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";
	
}

void player_turn(char board[][3])
{
	int choice;
	int row,col;
	
	if(turn == 'X')
	cout<<"\n\tPlayer1 [X] turn:";
	if(turn == 'O')
	cout<<"\n\tPlayer2 [O] turn:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			row=0; col=0;
			break;
		case 2:
			row=0; col=1;
			break;
		case 3:
			row=0; col=2;
			break;
		case 4:
			row=1; col=0;
			break;
		case 5:
			row=1; col=1;
			break;
		case 6:
			row=1; col=2;
			break;
		case 7:
			row=2; col=0;
			break;
		case 8:
			row=2; col=1;
			break;
		case 9:
			row=2; col=2;
			break;			
			
		default:
		cout<<"Invalid choice"<<endl;
		break;
   }
   
   if(turn == 'X' && board[row][col]!='X' && board[row][col]!='O')
   {
   	board[row][col]='X';
   	turn ='O';
   }
   	
   	else if(turn == 'O' && board[row][col]!='X' && board[row][col]!='O')
   	{
   	 board[row][col]='O';
   	 turn ='X';
	}
	else
	{
		cout<<"Box already filled:\n\n";
		player_turn(board);
		display_board(board);
	}
   
}
bool gameover(char board[][3])
{
	bool draw=false;

	for(int i=0;i<3;i++)
	{
	   if(board[i][0] == board[i][1] && board[i][0] == board[i][2]||board[0][i] == board[1][i] && board[0][i] == board[2][i])
	   {
         return false;
       }
    }
    if(board[0][0]== board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
	return false;
	
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X' && board[i][j]!='O')
			return true;
		}
	}
	draw=true;
	return false;
}
int main()
{
	bool draw=false;
	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

	
	while(gameover(board))
	{
	display_board(board);
	player_turn(board);
	gameover(board);
    }
    
    if(turn == 'X' && draw==false)
    cout<<"\n\n  Player2 [O] wins !! Congratulations \n\n";
    else if(turn == 'O' && draw==false)
    cout<<"\n\n  Player1 [X] wins !! Congratulations \n\n";
    else
    cout<<"\n\n    G a m e   D r a w \n\n";
		
	return 0;
}
