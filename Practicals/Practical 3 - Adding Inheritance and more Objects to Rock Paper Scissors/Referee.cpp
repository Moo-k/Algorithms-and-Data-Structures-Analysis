#include "Referee.h"

Referee::Referee(){
}

char Referee::refGame(Player *player1, Player *player2){
    char player1Move = player1->makeMove();
    char player2Move = player2->makeMove();
    switch (player1Move){
        case 'R':
            switch (player2Move){
                case 'R':
                    return 'T';
                case 'P':
                    return 'L';
                case 'S':
                    return 'W';
                default:
                    return 'E';
            }
        case 'P':
            switch (player2Move){
                case 'R':
                    return 'W';
                case 'P':
                    return 'T';
                case 'S':
                    return 'L';
                default:
                    return 'E';
            }
        case 'S':
            switch (player2Move){
                case 'R':
                    return 'L';
                case 'P':
                    return 'W';
                case 'S':
                    return 'T';
                default:
                    return 'E';
            }
        default:
            return 'E';
    }
}