#include "CoroutineBase.h"

CoroutineBase::CoroutineBase() : state_(DEAD)
{

}

CoroutineBase::~CoroutineBase()
{
}

int CoroutineBase::GetState()
{
	return state_;
}
