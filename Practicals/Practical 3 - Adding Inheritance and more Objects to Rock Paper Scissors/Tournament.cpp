#include "Tournament.h"

Tournament::Tournament(){
}

Player *Tournament::run(std::array<Player *, 8> competitors){
    Referee ref;
    std::array<Player *,4> top4;
    std::array<Player *,2> top2;
    int p1Score = 0;
    int p2Score = 0;
    // round 1
    for (int i = 0; i < 4; i++){
        p1Score = 0;
        p2Score = 0;
        for (int j = 0; j < 5; j++){
            switch (ref.refGame(competitors[2*i],competitors[2*i+1])){
                case 'W':
                    p1Score++;
                    break;
                case 'L':
                    p2Score++;
                    break;
                case 'T':
                    break;
            }
        }
        if (p1Score >= p2Score){
            top4[i] = competitors[2*i];
        }   else{
            top4[i] = competitors[2*i+1];
        }
    }
    for (int i = 0; i < 4; i++){
        top4[i]->resetMoveCount();
    }
    // round 2
    for (int i = 0; i < 2; i++){
        p1Score = 0;
        p2Score = 0;
        for (int j = 0; j < 5; j++){
            switch (ref.refGame(top4[2*i],top4[2*i+1])){
                case 'W':
                    p1Score++;
                    break;
                case 'L':
                    p2Score++;
                    break;
            }
        }
        if (p1Score >= p2Score){
            top2[i] = top4[2*i];
        }   else{
            top2[i] = top4[2*i+1];
        }
    }
    for (int i = 0; i < 2; i++){
        top2[i]->resetMoveCount();
    }
    // round final
    p1Score = 0;
    p2Score = 0;
    for (int j = 0; j < 5; j++){
        switch (ref.refGame(top2[0],top2[1])){
            case 'W':
                p1Score++;
                break;
            case 'L':
                p2Score++;
                break;
        }
    }
    if (p1Score >= p2Score){
        return top2[0];
    }   else{
        return top2[1];
    }
}