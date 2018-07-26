#include <iostream>
#include <unistd.h>
#include "sys/time.h"

#include "UCoroutine.h"
#include "WCoroutine.h"
#include "RpcCoroObj.h"
#include "RpcObjMgr.h"

using namespace std;

int main(int argc, char** argv)
{
    CoroutineBase *co1 = new WCoroutine();
    // CoroutineBase *co1 = new UCoroutine();
    RpcBaseObj *obj1 = new RpcCoroObj(co1);

    RpcObjMgr::Instance()->Insert(obj1);

    // co1->CreateCoroutine(GetMainCoro(), obj1);
    co1->CreateCoroutine(nullptr, obj1);
	co1->Resume();

	struct timeval start, end;
	gettimeofday(&start, nullptr);
	std::cout << "start " << start.tv_sec << "." << start.tv_usec << std::endl;

	int i = 0;
	while (++i<cnt)
	{
		co1->Resume();
	}


	gettimeofday(&end, nullptr);
	std::cout << "end " << end.tv_sec << "." << end.tv_usec << std::endl;

	std::cout << "duration: " << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << std::endl;
    return 0;
}

