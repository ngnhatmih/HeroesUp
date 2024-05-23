#ifndef STATE_H
#define STATE_H

class State {
public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual ~State() {};
};

#endif /* STATE_H */ 