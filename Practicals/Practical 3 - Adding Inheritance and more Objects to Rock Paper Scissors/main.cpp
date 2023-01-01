#include "Tournament.h"
#include "Human.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "PaperDoll.h"
#include "RandomComputer.h"
#include "Toolbox.h"
#include <array>
#include <string>
#include <iostream>

int main(void){
    Player *player1 = new Avalanche();
    Player *player2 = new Bureaucrat();
    Player *player3 = new Bureaucrat();
    Player *player4 = new Toolbox();
    Player *player5 = new Toolbox();
    Player *player6 = new Crescendo();
    Player *player7 = new FistfullODollars();
    Player *player8 = new Crescendo();

    std::array<Player *,8> competitors = {player1,player2,player3,player4,player5,player6,player7,player8};

    Tournament t1;

    std::cout << "Winner: " << t1.run(competitors)->getName() << std::endl;

    return 0;
}