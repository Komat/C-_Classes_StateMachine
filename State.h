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



class State : public PubSub {
private:
    const char *id;
    bool isCurrent;

public:

    State(const char *id);

    void * getId() const;

    bool isIsCurrent() const;

    void setIsCurrent(bool isCurrent);

    void onEnter();

    void onStay();

    void onExit();

    void (*superOnEnter)();

    void (*superOnStay)();

    void (*superOnExit)();


    void once(const std::string &topic, std::function<void(std::string topicType)> subscriber);


    const static std::string TOPIC[];



};


#endif //C_GAMEFRAMEMOCK_STATE_H
