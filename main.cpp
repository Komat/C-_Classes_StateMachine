#include <iostream>
#include "State.h"
#include "StateMachine.h"


//int sleep(unsigned long x) {
//    clock_t c1 = clock(), c2;
//
//    do {
//        if ((c2 = clock()) == (clock_t) -1)
//            return 0;
//    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
//
//    return 1;
//
//}
//
//
//
///**
// * 購読開始
// */
//void state_exit_handler(const std::string &topic) {
//    std::cout << "HANDLER >> " << topic << std::endl;
//}
//
//
//
///**
// * 購読開始
// */
//void state_stay_handler(const std::string &topic) {
//    std::cout << "HANDLER >> " << topic << std::endl;
//}
//
//
//
///**
// * 購読開始
// */
//void state_enter_handler(const std::string &topic) {
//    std::cout << "HANDLER >> " << topic << std::endl;
//}
//





int main() {

    StateMachine stateMachine;

    State Intro("INTRO");
    State Main("MAIN");

    stateMachine.add(Intro);
    stateMachine.add(Main);

//    stateMachine.once(State::TOPIC[ENTER_STATE], state_enter_handler);
//    stateMachine.once(State::TOPIC[STAY_STATE], state_stay_handler);
//    stateMachine.once(State::TOPIC[EXIT_STATE], state_exit_handler);
//
    stateMachine.go(Main.getId());

//    stateMachine.subscribe(State::TOPIC::ENTER);

//    std::cout << State::TOPIC << std::endl;

    return 0;
}
