/**
 * @description
 * @fileName State.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "State.h"


State::State(const std::string &id) : id(id) {
}

void State::onEnter() {
    isCurrent = true;

    std::cout << " [ ON ENTER ] " << this->id << std::endl;

    publish(State::TOPIC[CHANGE_STATE], this->id);
    publish(State::TOPIC[ENTER_STATE], this->id);
}

void State::onStay() {
    if (!isCurrent) {
        isCurrent = true;
    }
    publish(State::TOPIC[STAY_STATE], this->id);
}

void State::onExit() {
    isCurrent = false;
    publish(State::TOPIC[CHANGE_STATE], this->id);
    publish(State::TOPIC[EXIT_STATE], this->id);
}

const std::string State::getId() const {
    return id;
}

bool State::isIsCurrent() const {
    return isCurrent;
}

void State::setIsCurrent(bool isCurrent) {
    State::isCurrent = isCurrent;
}

void State::once(const std::string &topic, StateHandler subscriber) {
  subscribeOnce(topic, subscriber);
}


const std::string State::TOPIC[] = {
        "stay_state",
        "change_state",
        "enter_state",
        "exit_state"
};



