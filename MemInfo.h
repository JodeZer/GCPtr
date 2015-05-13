#pragma once
template<class T>
class MemInfo
{
public:
	int refCount=1;//reference count
	T* pMem;//pointer to the Memory
	int size=0;//if array sizeof(array)
	bool isArray = false;//if is array
	explicit MemInfo(T* p = nullptr, int size = 0) :pMem(p), size(size)
	{
		if (size > 0)
			isArray = true;
	}
	MemInfo(const MemInfo<T> &rhs){
		if (&rhs == this)
			return;
		if (!rhs.isArray){
			pMem = new T;
			*pMem = *rhs.pMem;
		}

		else{
			pMem = new T[rhs.size];
			for (int i = 0; i < rhs.size; i++){
				pMem[i] = rhs.pMem[i];
			}
		}
		refCount = rhs.refCount;
		size = rhs.size;
		isArray = rhs.isArray;
	}
	MemInfo<T>& operator=(const MemInfo<T> &rhs){
		if (&rhs == this)
			return *this;
		if (!rhs.isArray){
			pMem = new T;
			*pMem = *rhs.pMem;
		}

		else{
			pMem = new T[rhs.size];
			for (int i = 0; i < rhs.size; i++){
				pMem[i] = rhs.pMem[i];
				cout << pMem[i] << endl;
			}
		}
		refCount = rhs.refCount;
		size = rhs.size;
		isArray = rhs.isArray;
		return *this;
	}
	virtual ~MemInfo(){
		if (!isArray)
			delete pMem;
		else
			delete[]pMem;
		pMem = nullptr;
	}
};

