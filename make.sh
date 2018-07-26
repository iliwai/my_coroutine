#!/bin/bash

g++ -g --std=c++11 -I./libco -I./co RpcCoroObj.cpp RpcBaseObj.cpp ./co/CoroutineBase.cpp ./co/UCoroutine.cpp ./co/WCoroutine.cpp RpcObjMgr.cpp main.cpp ./libco/lib/libcolib.a -lpthread -o main
