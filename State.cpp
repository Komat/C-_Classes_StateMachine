/**
 * @description
 * @fileName State.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "State.h"


State::State(const char *id) {
    this->id = id;
    isCurrent = false;
}

void State::onEnter() {
    isCurrent = true;
    publish(State::TOPIC[CHANGE_STATE], NULL);
    publish(State::TOPIC[ENTER_STATE], NULL);
}

void State::onStay() {
    if (!isCurrent) {
        isCurrent = true;
    }
    publish(State::TOPIC[STAY_STATE], NULL);
}

void State::onExit() {
    isCurrent = false;
    publish(State::TOPIC[CHANGE_STATE], NULL);
    publish(State::TOPIC[EXIT_STATE], NULL);
}

void * State::getId() const {
    return (void *) id;
}

bool State::isIsCurrent() const {
    return isCurrent;
}

void State::setIsCurrent(bool isCurrent) {
    State::isCurrent = isCurrent;
}

void State::once(const std::string &topic, std::function<void(std::string _topic)> subscriber) {
    subscriber(topic);
//    subscribeOnce(topic, subscriber);
}




const std::string State::TOPIC[] = {
        "stay_state",
        "change_state",
        "enter_state",
        "exit_state"
};


