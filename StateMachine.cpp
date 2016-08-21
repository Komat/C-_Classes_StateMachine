/**
 * @description
 * @fileName StateMachine.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "StateMachine.h"

StateMachine::StateMachine() {
    currentId = "";
}


bool StateMachine::hasState(const std::string state_id) {
    return _stateList.count(state_id) != 0;
}

void StateMachine::add(State state) {
    _stateList.insert(std::make_pair(state.getId(), state));
}


void StateMachine::oneceHandler(std::string topic, void * topicOption) {
    publish(topic, topicOption);
}


void StateMachine::go(const std::string state_id) {
    if (hasState(state_id)) {

        std::map<const std::string, State>::iterator state = _stateList.find(state_id);

//        state->second.once(State::TOPIC[ENTER_STATE], (topicFunctionPtr) oneceHandler);
        state->second.onEnter();
//        publish(State::TOPIC[ENTER_STATE]);
        currentId = state->second.getId();

//        if (it->second != currentId) {
//            if (currentId) currentId->stateExit();
//            currentId = it->second;
//            currentId->stateEnter();
//        }
//        std::cout << "TRUE::" << state_id << std::endl;
//        std::cout << "TRUE" << _stateList.find(state_id) << std::endl;
//        subscribe(State::TOPIC::ENTER);
//        currentId = _stateList[state_id];
    }
}

void StateMachine::exit(const std::string) {

}

void StateMachine::once(const std::string &topic, topicFunctionPtr subscriber) {
    subscribeOnce(topic, subscriber);
}

State &StateMachine::getCurrentState() {
    std::map<const std::string, State>::iterator state = _stateList.find(currentId);
    return state->second;
}
