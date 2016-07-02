//
//  Multiset.cpp
//  CS32_HW01
//
//  Created by Boyi Wang on 7/1/16.
//
//

#include "Multiset.h"
#include<iostream>
#include<list>
using namespace std;


Items_array::Items_array(string string){
	value = string;
	times = 1;
}

bool Items_array::isMatch(string string){
	if (value.compare(string) == 0) return true;
	return false;
}

int Items_array::add(string string){
	if (isMatch(string)){
		times += 1;
	}
	return times;
}




Multiset::Multiset(){
	iteams_arrays = list<Items_array>();
}


bool Multiset::empty(){
	int size=iteams_arrays.size();
	return size == 0;
}


int Multiset::size(){
	int size = 0;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		size+=it->times;
	}
	return size;
}

int Multiset::uniqueSize(){
	int size = 0;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		size += 1;
	}
	return size;
}

bool Multiset::insert(const std::string& value){
	bool insert = false;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->isMatch(value)){
			it->add(value);
			insert = true;
		}
	}
	if (!insert){
		iteams_arrays.push_front(Items_array(value));
	}
	return true;
}



int Multiset::erase(const std::string& value){
	bool isDelet = false;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->isMatch(value)){
			(it->times) -= 1;
			if (it->times == 0)
				iteams_arrays.erase(it);
			isDelet = true;
		}
	}
	if (isDelet){
		return 1;
	}
	return 0;
}

int Multiset::eraseAll(const std::string& value){
	int deleteNum = 0;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->isMatch(value)){
			deleteNum = it->times;
		}
		iteams_arrays.erase(it);
	}
	return deleteNum;
}

bool Multiset::contains(const std::string& value){
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->isMatch(value)){
			return true;
		}
	}
}



int Multiset::count(const std::string& value){
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->isMatch(value)){
			return it->times;
		}
	}
	return 0;
}


int Multiset::get(int i, std::string& value){
	int num = 0;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (num == i){ 
			value = it->value; 
			return it->times;
		}
		num += 1;
	}
	return 0;
}


bool Multiset::getLeastFrequentValue(std::string &value){
	if (iteams_arrays.size()==0) return false;
	int num=0;//最小的那个出现的次数
	int times=(iteams_arrays.begin())->times; //最小的那个
	string rs = (iteams_arrays.begin())->value;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->times == times){//如果与最小相等
			num += 1;
		}else if (it->times < times){//如果比最小还小
			times = it->times;
			num = 1;
			rs = it->value;
		}
	}
	if (num == 1){
		value = rs;
		return true;
	}
	else{
		return false;
	}
}

bool Multiset::getSmallestValue(std::string &value){
	if (iteams_arrays.size() == 0) return false;
	string small = (iteams_arrays.begin())->value;
	int num = 0;
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if ((it->value.compare(small)) == 0){
			num += 1;
		}
		else if ((it->value.compare(small)) < 0){
			small = it->value;
			num = 1;
		}
	}
	if (num == 1){
		value = small;
		return true;
	}
	else{
		return false;
	}
}


bool Multiset::getSecondSmallestValue(std::string &value){
	string svalue;
	if (getSmallestValue(svalue)){
		Multiset set;
		this->copyIntoOtherMultiset(set);
		set.erase(svalue);
		return set.getSmallestValue(value);
	}
	return false;
}

bool Multiset::replace(std::string original, std::string new_value){
	for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
		if (it->value.compare(original) == 0){
			it->value = new_value;
			return true;
		}
	}
	return false;
}

int Multiset::countIf(char op, std::string value){
	
	int num = 0;

	
		switch (op)
		{
		case '>':{
					 for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
						 if (it->value.compare(value) > 0){
							 num += 1;
						 }
					 }
					 return num;
		}

		case '<':{
					 for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
						 if (it->value.compare(value) < 0){
							 num += 1;
						 }
					 }
					 return num;
		}
		case '=':{
					 for (LIST_STAR it = iteams_arrays.begin(); it != iteams_arrays.end(); it++){
						 if (it->value.compare(value) == 0){
							 num += 1;
						 }
					 }
					 return num;
		}

		default:
			return -1;
	}

}

void Multiset::copyIntoOtherMultiset(Multiset &other){
	int size = uniqueSize();
	string value;
	for (int i = 0; i < size; i++){
		int num=get(i, value);
		for (int j = 0; j <= num; j++){
			other.insert(value);
		}
	}
}


void Multiset::swap(Multiset& other){
	list<Items_array> tarray = iteams_arrays;
	iteams_arrays = other.iteams_arrays;
	other.iteams_arrays = tarray;
}

