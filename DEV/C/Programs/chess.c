#include <stdio.h>

enum PieceType{King, Queen, Rook, Bishop, Knight, Pawn};
//             0     1      2     3       4       5
enum Teams{White, Black};
//         0      1

typedef struct ChessPiece{
enum PieceType Type;
enum Teams Team;
int isalive;
}ChessPiece;

typedef struct Board{
ChessPiece NewBoard[8][8];
}Board;

ChessPiece MakePawn(enum Teams TeamType){
ChessPiece NewPawn;
NewPawn.Type = Pawn;
NewPawn.Team = TeamType;
NewPawn.isalive = 1;
return NewPawn;
}
ChessPiece MakeKnight(enum Teams TeamType){
ChessPiece NewKnight;
NewKnight.Type = Knight;
NewKnight.Team = TeamType;
NewKnight.isalive = 1;
return NewKnight;
}
ChessPiece MakeBishop(enum Teams TeamType){
ChessPiece NewBishop;
NewBishop.Type = Bishop;
NewBishop.Team = TeamType;
NewBishop.isalive = 1;
return NewBishop;
}
ChessPiece MakeRook(enum Teams TeamType){
ChessPiece NewRook;
NewRook.Type = Rook;
NewRook.Team = TeamType;
NewRook.isalive = 1;
return NewRook;
}
ChessPiece MakeQueen(enum Teams TeamType){
ChessPiece NewQueen;
NewQueen.Type = Queen;
NewQueen.Team = TeamType;
NewQueen.isalive = 1;
return NewQueen;
}
ChessPiece MakeKing(enum Teams TeamType){
ChessPiece NewKing;
NewKing.Type = King;
NewKing.Team = TeamType;
NewKing.isalive = 1;
return NewKing;
}

int CanMoveFunc(TypePiece)
{
pieces in the way?
is x piece? 
    check against relevant canXmove func 
    
}

int main()
{
ChessPiece Board[8][8];
    for (int i=0;i!=7;++i){
        Board[1][i] = MakePawn(Black);
        Board[6][i] = MakePawn(White);
    }   
    Board[0][1] = MakeKnight(Black);
    Board[0][6] = MakeKnight(Black);
    Board[7][1] = MakeKnight(White);
    Board[7][6] = MakeKnight(White);

    Board[0][0] = MakeRook(Black);
    Board[0][7] = MakeRook(Black);
    Board[7][0] = MakeRook(White);
    Board[7][7] = MakeRook(White);

    Board[0][2] = MakeBishop(Black);
    Board[0][4] = MakeBishop(Black);
    Board[7][2] = MakeBishop(White);
    Board[7][4] = MakeBishop(White);

    Board[0][3] = MakeQueen(Black);
    Board[7][3] = MakeQueen(White);
    Board[0][4] = MakeKing(Black);
    Board[7][4] = MakeKing(White);

}