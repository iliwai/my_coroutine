#ifndef __UCOROUTINE_H__
#define __UCOROUTINE_H__

// using ucontext

#include "CoroutineBase.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <ucontext.h>
#include <string.h>

#ifdef __cplusplus
}
#endif

void ULogicFun(void*);

class UCoroutine : public CoroutineBase
{
public:
    static const int StackSize = 128 * 1024;

    UCoroutine();
    virtual ~UCoroutine();

    ucontext_t* GetContext() { return &context_;}

    // create and run coroutine
    virtual int CreateCoroutine(CoroutineBase* father, RpcBaseObj *obj);
    virtual void Resume();
    virtual void Yield();

private:
    UCoroutine*  father_;
    ucontext_t      context_;
};

UCoroutine* GetMainCoro();

#endif
