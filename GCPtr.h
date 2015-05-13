#pragma once
#include "MemInfo.h"
#include <list>
#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif
using namespace std;
template<class T>
class GCPtr
{
public:
	static  list<MemInfo<T>> gclist;
	typename list<MemInfo<T>>::iterator it;
	MemInfo<T> temp;
public:
	static void showList(){
#ifndef DEBUG
		cout << "ARE¡¡YOU OK";
#endif
#ifdef DEBUG
		int index = 0;
		 list<MemInfo<T>>::iterator it = gclist.begin();
		for (; it != gclist.end(); ++it){
			if (!it->isArray)
				cout <<"list  "<<index++<<": "<<it->pMem<<"||Val: "<<*(it->pMem)<<"||refCount: "<<it->refCount<<endl;
			else
				cout <<"list  " << index++ << ": " << it->pMem << "||Val: " << *(it->pMem) << "||size:"<<it->size<<"||refCount: " << it->refCount << endl;
		}
#endif
		
}
	GCPtr(T*p=nullptr,int size=0){
		it = find(p);
		if (it != gclist.end()){
			it->refCount++;
			return;
		}
		if (size == 0)
			temp = MemInfo<T>(p);
		else
			temp = MemInfo<T>(p, size);
		gclist.push_back(temp);
		it = gclist.end();
		it--;
	}
	virtual ~GCPtr(){
		it->refCount--;
		if (it->refCount <= 0)
			gclist.erase(it);
	}
public:
	typename list<MemInfo<T>>::iterator find(T *p){
		list<MemInfo<T>>::iterator it = gclist.begin();
		for (; it != gclist.end(); ++it){
			if (it->pMem == p)
				return it;
		}
		return gclist.end();
	}

};

template <class T>
list<MemInfo<T>> GCPtr<T>::gclist = list<MemInfo<T>>();