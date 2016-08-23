#include <iostream>
#include "StateMachine.h"


int sleep(unsigned long x) {
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t) -1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;

}


/**
 * 購読開始
 */
void state_exit_handler(const std::string &topic, const std::string &str) {
    std::cout << "HANDLER >> " << topic << " ===> " << str << std::endl;
}


/**
 * 購読開始
 */
void state_stay_handler(const std::string &topic, const std::string &str) {
    std::cout << "HANDLER >> " << topic << " ===> " << str << std::endl;
}


/**
 * 購読開始
 */
void state_enter_handler(const std::string &topic, const std::string &str) {
    std::cout << "HANDLER >> " << topic << " ===> " << str << std::endl;
}


int main() {

    StateMachine stateMachine;

    State Intro("INTRO");
    State Main("MAIN");

    stateMachine.add(Intro);
    stateMachine.add(Main);

//    stateMachine.once(State::TOPIC[ENTER_STATE], state_enter_handler);
//    stateMachine.once(State::TOPIC[STAY_STATE], state_stay_handler);
//    stateMachine.once(State::TOPIC[EXIT_STATE], state_exit_handler);

    // TODO(20160823): 何か once なのに2回目もハンドリングしてしまうっぽい
    stateMachine.once(State::TOPIC[ENTER_STATE], [&](const std::string &topic, const std::string &str) {
        std::cout << "@ONCEState::TOPIC[ENTER_STATE]->HANDLER() >> " << str << std::endl;
        stateMachine.go(Main.getId());
    });

    stateMachine.go(Intro.getId());



    return 0;
}
