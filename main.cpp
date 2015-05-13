#include <iostream>
#include "GCPtr.h"
using namespace std;

int main(){
	int *p1 = new int(1000);
	int *p2 = new int(2000);
	int *p3 = new int[5]{3000,4000,5000,6000,7000};
	cout << *p3;
	GCPtr<int> p(p1);
	GCPtr<int> pp(p1);
	GCPtr<int> ppp(p2);
	GCPtr<int> pppp(p3, 5);
	GCPtr<int> ppppp(p3, 5);
	GCPtr<int>::showList();
	
	return 0;
}