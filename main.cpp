//
//  main.cpp
//  CS32_HW01
//
//  Created by Boyi Wang on 7/1/16.
//
//

#include "main.h"
#include"Multiset.h"
#include<iostream>

using namespace std;
int main(void)
{
	Multiset ms;
	ms.insert("fennel");
	ms.insert("fennel");
	ms.insert("fenugreek");
	ms.insert("fennel");
	for (int k = 0; k < ms.uniqueSize(); k++)
	{
		string x;
		int n = ms.get(k, x);
		cout << x << " occurs " << n << " times." << endl;
	}
}
