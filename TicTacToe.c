#include <stdio.h>

int WinnerState(void);
void CurrentPlayer(void);
void PrintWinner(void);
void PrintDraw(void);
void PrintBoard(void);
void PrintFinalBoard(void);
void MarkBoard(int In);

int CounterForDisplay = 0;
int CounterForFunction = 0;
int TurnCounter = 0;
int TurnLimit = 9;

char Mark[2] = {'O', 'X'};
int MarkNumber = 0;
int Input = 0;

char Board[9] = {
	'1', '2', '3',
	'4', '5', '6',
	'7', '8', '9'
	};

char FinalBoard[9] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	' ', ' ', ' '
	};

int main(void) {
	printf("Tic Tac Toe\n");
	for(TurnCounter = 0; TurnCounter < TurnLimit; TurnCounter++) {
		CounterForFunction = (TurnCounter % 2);
		CounterForDisplay = (CounterForFunction + 1);
		if(WinnerState() > 0) {
			PrintWinner();
			PrintFinalBoard();
			return 0;
			}
		printf("Turn %i\n", (TurnCounter + 1));
		PrintBoard();
		CurrentPlayer();
		}
	PrintDraw();
	PrintFinalBoard();
	return 0;
	} // End of Main

int WinnerState(void) {
	int Check = 0;
		// Player1 Horizontal
		if(Board[0] == 'O' && Board[1] == 'O' && Board[2] == 'O') {
			FinalBoard[0] = '+';
			FinalBoard[1] = '+';
			FinalBoard[2] = '+';
			Check = 1;
			}
		else if(Board[3] == 'O' && Board[4] == 'O' && Board[5] == 'O') {
			FinalBoard[3] = '+';
			FinalBoard[4] = '+';
			FinalBoard[5] = '+';
			Check =  1;
			}
		else if(Board[6] == 'O' && Board[7] == 'O' && Board[8] == 'O') {
			FinalBoard[6] = '+';
			FinalBoard[7] = '+';
			FinalBoard[8] = '+';
			Check =  1;
			}

		// Player1 Vertical
		else if(Board[0] == 'O' && Board[3] == 'O' && Board[6] == 'O') {
			FinalBoard[0] = '+';
			FinalBoard[3] = '+';
			FinalBoard[6] = '+';
			Check =  1;
			}
		else if(Board[1] == 'O' && Board[4] == 'O' && Board[7] == 'O') {
			FinalBoard[1] = '+';
			FinalBoard[4] = '+';
			FinalBoard[7] = '+';
			Check =  1;
			}
		else if(Board[2] == 'O' && Board[5] == 'O' && Board[8] == 'O') {
			FinalBoard[2] = '+';
			FinalBoard[5] = '+';
			FinalBoard[8] = '+';
			Check =  1;
			}

		//Player1 Diagonal
		else if(Board[0] == 'O' && Board[4] == 'O' && Board[8] == 'O') {
			FinalBoard[0] = '+';
			FinalBoard[4] = '+';
			FinalBoard[8] = '+';
			Check =  1;
			}
		else if(Board[2] == 'O' && Board[4] == 'O' && Board[6] == 'O') {
			FinalBoard[2] = '+';
			FinalBoard[4] = '+';
			FinalBoard[6] = '+';
			Check =  1;
			}

		// Player2 Horizontal
		else if(Board[0] == 'X' && Board[1] == 'X' && Board[2] == 'X') {
			FinalBoard[0] = '+';
			FinalBoard[1] = '+';
			FinalBoard[2] = '+';
			Check =  2;
			}
		else if(Board[3] == 'X' && Board[4] == 'X' && Board[5] == 'X') {
			FinalBoard[3] = '+';
			FinalBoard[4] = '+';
			FinalBoard[5] = '+';
			Check =  2;
			}
		else if(Board[6] == 'X' && Board[7] == 'X' && Board[8] == 'X') {
			FinalBoard[6] = '+';
			FinalBoard[7] = '+';
			FinalBoard[8] = '+';
			Check =  2;
			}

		// Player2 Vertical
		else if(Board[0] == 'X' && Board[3] == 'X' && Board[6] == 'X') {
			FinalBoard[0] = '+';
			FinalBoard[3] = '+';
			FinalBoard[6] = '+';
			Check =  2;
			}
		else if(Board[1] == 'X' && Board[4] == 'X' && Board[7] == 'X') {
			FinalBoard[1] = '+';
			FinalBoard[4] = '+';
			FinalBoard[7] = '+';
			Check =  2;
			}
		else if(Board[2] == 'X' && Board[5] == 'X' && Board[8] == 'X') {
			FinalBoard[2] = '+';
			FinalBoard[5] = '+';
			FinalBoard[8] = '+';
			Check =  2;
			}

		// Player2 Diagonal
		else if(Board[0] == 'X' && Board[4] == 'X' && Board[8] == 'X') {
			FinalBoard[0] = '+';
			FinalBoard[4] = '+';
			FinalBoard[8] = '+';
			Check =  2;
			}
		else if(Board[2] == 'X' && Board[4] == 'X' && Board[6] == 'X') {
			FinalBoard[2] = '+';
			FinalBoard[4] = '+';
			FinalBoard[6] = '+';
			Check =  2;
			}
	if(Check > 0) {
		return Check;
		} else {
		return 0;
		}
	} // End of CheckForWinner

void CurrentPlayer(void) {
	fflush(stdin);
	printf("\nPlayer%i: ", CounterForDisplay);
	scanf("%i", &Input);
	if(Input >= 1 && Input <= 9 ) {
		MarkNumber = CounterForFunction;
		MarkBoard(Input);
		} else {
		fflush(stdin);
		printf("\nInvalid Input\n");
		TurnCounter--;
		}
	} // End of CurrentPlayer

void PrintWinner(void) {
	if(CounterForFunction == 0) {
		printf("\nPlayer2 Won!\n");
		}
	else if(CounterForFunction == 1) {
		printf("\nPlayer1 Won!\n");
		}
	PrintBoard();
	} // End of PrintWinner

void PrintDraw(void) {
	printf("\nIts a draw!\n");
	PrintBoard();
	} // End of PrintDraw

void PrintBoard(void) {
	printf("\n");
	printf("  %c | %c | %c\n", Board[0], Board[1], Board[2]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", Board[3], Board[4], Board[5]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", Board[6], Board[7], Board[8]);
	} // End of PrintBoard

void PrintFinalBoard(void) {
	printf("\n");
	printf("  %c | %c | %c\n", FinalBoard[0], FinalBoard[1], FinalBoard[2]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", FinalBoard[3], FinalBoard[4], FinalBoard[5]);
	printf(" --- --- ---\n");
	printf("  %c | %c | %c\n", FinalBoard[6], FinalBoard[7], FinalBoard[8]);
	} // End of PrintFinalBoard

void MarkBoard(int In) {
	if(Board[In - 1] == 'X' || Board[In - 1] == 'O') {
		printf("\nInvalid Move\n");
		TurnCounter--;
		}
	else {
		Board[In - 1] = Mark[MarkNumber];
		}
	Input = 0;
	} // End of MarkBoard