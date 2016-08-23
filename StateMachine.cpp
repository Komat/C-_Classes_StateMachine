/**
 * @description
 * @fileName StateMachine.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "StateMachine.h"
#include <iostream>

StateMachine::StateMachine() {
    currentId = "";
}


bool StateMachine::hasState(const std::string state_id) {
    return _stateList.count(state_id) != 0;
}

void StateMachine::add(State state) {
    _stateList.insert(std::make_pair(state.getId(), state));
}


void StateMachine::onceHandler(std::string topic, const std::string state_id) {

    if (topic == State::TOPIC[ENTER_STATE]) {
        currentId = state_id;
    } else if (topic == State::TOPIC[EXIT_STATE]) {

        std::map<const std::string, State>::iterator state = _stateList.find(state_id);

        auto once = std::bind(&StateMachine::onceHandler, this, State::TOPIC[ENTER_STATE], state->second.getId());

        state->second.once(State::TOPIC[ENTER_STATE], once);
        state->second.onEnter();

    }

    publish(topic, state_id);

}


void StateMachine::go(const std::string state_id) {

    if (hasState(state_id)) {

        std::map<const std::string, State>::iterator state = _stateList.find(state_id);

        if (!currentId.empty()) {

            if (state->second.getId() != currentId) {

                std::map<const std::string, State>::iterator currentState = _stateList.find(currentId);

                auto once = std::bind(&StateMachine::onceHandler, this, State::TOPIC[EXIT_STATE], state->second.getId());

                currentState->second.once(State::TOPIC[EXIT_STATE], once);
                currentState->second.onExit();

            } else {
                state->second.onStay();
                publish(State::TOPIC[STAY_STATE], state->second.getId());
            }

        } else {

            auto once = std::bind(&StateMachine::onceHandler, this, State::TOPIC[ENTER_STATE], state->second.getId());

            state->second.once(State::TOPIC[ENTER_STATE], once);
            state->second.onEnter();

        }

    }
}

void StateMachine::exit(const std::string) {

}

void StateMachine::once(const std::string &topic, StateHandler subscriber) {
    subscribeOnce(topic, subscriber);
    // TODO(20160823): 何か once なのに2回目もハンドリングしてしまうっぽい用テスト
    publish(topic, "DUMMY");
}

State &StateMachine::getCurrentState() {
    std::map<const std::string, State>::iterator state = _stateList.find(currentId);
    return state->second;
}
