#include <iostream>
#include "State.h"
#include "StateMachine.h"

int main() {

    StateMachine stateMachine;

    State Intro("INTRO");
    State Main("MAIN");

    stateMachine.add(Intro);
    stateMachine.add(Main);


    stateMachine.go(Main.getId());

//    stateMachine.subscribe(State::TOPIC::ENTER);

//    std::cout << State::TOPIC << std::endl;

    return 0;
}