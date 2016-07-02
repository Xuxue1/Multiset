//
//  Multiset.h
//  CS32_HW01
//
//  Created by Boyi Wang on 7/1/16.
//
//

#ifndef __CS32_HW01__Multiset__
#define __CS32_HW01__Multiset__

#include <stdio.h>
#include<list>
#include<string>
using namespace std;

class Items_array
{	
public :
	string value;
	int times;
	Items_array(string s);
	bool isMatch(string s);
	int add(string s);
};

typedef list<Items_array>::iterator LIST_STAR;
//创建一个list容器的实例LISTCHAR   
typedef list<Items_array>::iterator LIST_END;

class Multiset
{
public:
	list<Items_array> iteams_arrays;
//Create an items array.
    
Multiset();    // Create an empty multiset.

bool empty();  // Return true if the multiset is empty, otherwise false.

int size();
// Return the number of items in the multiset.  For example, the size
// of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.

int uniqueSize();
// Return the number of distinct items in the multiset.  For example,
// the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
// "turmeric" is 2.

bool insert(const std::string& value);


int erase(const std::string& value);
// Remove one instance of value from the multiset if present.
// Return the number of instances removed, which will be 1 or 0.


int eraseAll(const std::string& value);
// Remove all instances of value from the multiset if present.
// Return the number of instances removed.

bool contains(const std::string& value);
// Return true if the value is in the multiset, otherwise false.

int count(const std::string& value);
	// Return the number of instances of value in the multiset.

int get(int i, std::string& value);
// If 0 <= i < uniqueSize(), copy into value an item in the
// multiset and return the number of instances of that item in
// the multiset.  Otherwise, leave value unchanged and return 0.
// (See below for details about this function.)

bool getLeastFrequentValue(std::string &value);
// If there exists a single item that has the least number of instances in the multiset, 
// then copy into value that item in the multiset and return true.
// However, if there exist more than 1 item that have the least number of instances in the multiset,
// then do not copy into value any item in the multiset and return false. In other words, value should remain unchanged.
// If there's no item in the multiset, return false.


bool getSmallestValue(std::string &value);
// If there exists a value that is the smallest value among all the values in the multiset, 
// then copy into value that item in the multiset and return true
// Otherwise, return false.
// For both unsigned long and string data type, the lower value can be found by using less than operator (<).
// For example, 10 is smaller than 20, so 10 < 20 is true.
// "ABCDE" is smaller than "XYZ", so "ABCDE" < "XYZ" is true.


bool getSecondSmallestValue(std::string &value);
// Similar to getSmallestValue(), but this time you need to find the second smallest value.
// If there exists a value that is the 2nd smallest value among all the values in the multiset,
// then copy into value that item in the multiset and return true.
// Otherwise, return false.
// Please note that you cannot use any sorting algorithm to sort the multiset.

bool replace(std::string original, std::string new_value);
// Replace the item that has the value equal to original by the new value new_value.
// For example, replace("ABCDE","XYZ") will search the multiset for the item "ABCDE" and replace all occurrences of "ABCDE" as "XYZ".
// If the replacement is successful, then return true.
// If there is no item to be replaced, then return false.

int countIf(char op, std::string value);
// Count the number of items that the item is greater than, less than, or equal to value.
// For example: 
// countIf('>',100) returns the number of items in multiset in which the item is greater than 100.
// countIf('=',"ABC") returns the number of items in multiset in which the item is equal to "ABC".
// countIf('<',50) returns the number of items in multiset in which the item is less than 50.
// If op is a character other than '>','=', and '<', then return -1.

void swap(Multiset& other);
// Exchange the contents of this multiset with the other one.

void copyIntoOtherMultiset(Multiset &other);
// Insert all the items into the multiset in other.

};



#endif /* defined(__CS32_HW01__Multiset__) */
