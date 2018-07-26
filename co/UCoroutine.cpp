#include "UCoroutine.h"
#include <iostream>

void ULogicFun(void* p)
{
    if (!p)
    {
        return;
    }
	RpcBaseObj* obj = static_cast<RpcBaseObj*>(p);
    obj->Run();
}

UCoroutine* GetMainCoro()
{
    static UCoroutine main_coroutine;
    return &main_coroutine;
}

UCoroutine::UCoroutine() : father_(nullptr)
{
	memset(&context_, 0, sizeof(ucontext_t));
}

UCoroutine::~UCoroutine()
{
    char *p = (char*)context_.uc_stack.ss_sp;
    delete p;
    context_.uc_stack.ss_sp = nullptr;
}

int UCoroutine::CreateCoroutine(CoroutineBase* father, RpcBaseObj *obj)
{
    getcontext(&context_);

    father_ = static_cast<UCoroutine*>(father);
    state_ = INIT;


    char* p_stack = new char[UCoroutine::StackSize];
    
    context_.uc_stack.ss_sp = p_stack;
    context_.uc_stack.ss_size = UCoroutine::StackSize;
    context_.uc_link = father_->GetContext();

    makecontext(&context_, (void (*)())ULogicFun, 1, obj);

	return 0;
}

void UCoroutine::Resume()
{
    state_ = RUNNING;
    swapcontext(father_->GetContext(), &context_);
}

void UCoroutine::Yield()
{
    state_ = SUSPEND;
    swapcontext(&context_, father_->GetContext());
}
