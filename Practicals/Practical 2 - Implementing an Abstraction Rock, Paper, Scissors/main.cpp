#include <iostream>
using namespace std;
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main(void){
    HumanPlayer player1;
    ComputerPlayer player2;

    Referee ref1;

    char result;
    result = ref1.refGame(player1,player2);

    cout << result << endl;
    return 0;
}