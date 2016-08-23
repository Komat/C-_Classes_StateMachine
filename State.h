/**
 * @description
 * @fileName State.h
 * @author komat
 * @date 8/21/16
 * @version 0.0.0
 */

#ifndef C_GAMEFRAMEMOCK_STATE_H
#define C_GAMEFRAMEMOCK_STATE_H

#include "classes/core/PubSub/PubSub.h"


typedef enum _TOPIC {
    STAY_STATE,
    CHANGE_STATE,
    ENTER_STATE,
    EXIT_STATE,
    STATE_TOPIC_LEN
} STATE_TOPIC;


typedef std::function<void(const std::string &topic, const std::string & str)> StateHandler;



class State : public PubSub<StateHandler> {
private:
    const std::string id;
    bool isCurrent;

public:

    State(const std::string &id);

    const std::string getId() const;

    bool isIsCurrent() const;

    void setIsCurrent(bool isCurrent);

    void onEnter();

    void onStay();

    void onExit();

    void (*superOnEnter)();

    void (*superOnStay)();

    void (*superOnExit)();


    void once(const std::string &topic, StateHandler subscriber);


    const static std::string TOPIC[];



};


#endif //C_GAMEFRAMEMOCK_STATE_H
