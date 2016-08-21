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


enum _TOPIC {
    STAY,
    CHANGE,
    ENTER,
    EXIT,
    STATE_TOPIC_LEN
};

class State : public PubSub {
private:
    const char *id;
    bool isCurrent;
public:
    State(const char *id);

    const char *getId() const;

    bool isIsCurrent() const;

    void setIsCurrent(bool isCurrent);

    void onEnter();

    void onStay();

    void onExit();

    void (*superOnEnter)();

    void (*superOnStay)();

    void (*superOnExit)();

    static _TOPIC TOPIC;

};


#endif //C_GAMEFRAMEMOCK_STATE_H
