#include "Referee.h"

Referee::Referee(){

}

char Referee::refGame(HumanPlayer player1, ComputerPlayer player2){
    char hmove = '\0';
    char cmove = '\0';
    hmove = player1.makeMove();
    cmove = player2.makeMove();
    switch (hmove){
        case 'R':
            switch (cmove){
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
            switch (cmove){
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
            switch (cmove){
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