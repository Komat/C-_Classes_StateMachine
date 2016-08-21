/**
 * @description
 * @fileName StateMachine.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#include "StateMachine.h"

//StateMachine::StateMachine() {
//    currentState = NULL;
//}


bool StateMachine::hasState(const std::string state_id) {
    return _stateList.count(state_id) != 0;
}

void StateMachine::add(State state) {
    _stateList.insert(std::make_pair(state.getId(), state));
}


void StateMachine::go(const std::string state_id) {
    if (hasState(state_id)) {

        std::map<const std::string, State>::iterator it = _stateList.find(state_id);

//        it->second.subscribe(State::TOPIC)
        it->second.onEnter();
//        if (it->second != currentState) {
//            if (currentState) currentState->stateExit();
//            currentState = it->second;
//            currentState->stateEnter();
//        }
//        std::cout << "TRUE::" << state_id << std::endl;
//        std::cout << "TRUE" << _stateList.find(state_id) << std::endl;
//        subscribe(State::TOPIC::ENTER);
//        currentState = _stateList[state_id];
    }
}

void StateMachine::exit(const std::string) {

}
