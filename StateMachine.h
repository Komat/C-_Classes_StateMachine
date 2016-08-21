/**
 * @description
 * @fileName StateMachine.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#ifndef C_GAMEFRAMEMOCK_STATEMACHINE_H
#define C_GAMEFRAMEMOCK_STATEMACHINE_H

#include <iostream>
#include "State.h"

class StateMachine: public PubSub {
private:
    std::map<const std::string, State> _stateList;
    std::string currentId;
    void oneceHandler(std::string topic, void * topicOption);
public:
    StateMachine();
    bool hasState(const std::string);
    void add(State);
    void go(const std::string);
    void exit(const std::string);
    void once(const std::string &topic, topicFunctionPtr subscriber);
    State & getCurrentState();
};

#endif //C_GAMEFRAMEMOCK_STATEMACHINE_H
