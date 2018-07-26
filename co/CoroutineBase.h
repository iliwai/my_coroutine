#ifndef __COROUTINE_BASE__
#define __COROUTINE_BASE__

#include "../RpcBaseObj.h"

// typedef void (*LogicFun)(RpcBaseObj *obj);
// LogicFun CoroLogicFun;

// void LogicFun(void*);

class CoroutineBase
{
public:
    enum {
        INIT = 0,
        SUSPEND,
        RUNNING,
        DEAD,
    };

    CoroutineBase();
    virtual ~CoroutineBase();

    // virtual interface
    virtual int CreateCoroutine(CoroutineBase* father, RpcBaseObj *obj) = 0;
    virtual void Resume() = 0;
    virtual void Yield() = 0;

	int GetState();

protected:
    int		state_;
};

#endif
