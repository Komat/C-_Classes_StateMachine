/**
 * @description
 * @fileName State.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "State.h"



/**
 *
 */
std::string TOPIC_LIST[] = {
        "stay_state",
        "change_state",
        "enter_state",
        "exit_state"
};


State::State(const char *id) {
    this->id = id;
    isCurrent = false;
}

void State::onEnter() {
    isCurrent = true;
    publish(TOPIC_LIST[CHANGE], NULL);
    publish(TOPIC_LIST[ENTER], NULL);
}

void State::onStay() {
    if (!isCurrent) {
        isCurrent = true;
    }
    publish(TOPIC_LIST[STAY], NULL);
}

void State::onExit() {
    isCurrent = false;
    publish(TOPIC_LIST[CHANGE], NULL);
    publish(TOPIC_LIST[EXIT], NULL);
}

const char *State::getId() const {
    return id;
}

bool State::isIsCurrent() const {
    return isCurrent;
}

void State::setIsCurrent(bool isCurrent) {
    State::isCurrent = isCurrent;
}
