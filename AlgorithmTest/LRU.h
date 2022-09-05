// #pragma once
// Array Challenge
// Have the function ArrayChallenge(strArr) take the array of characters stored in strArr, which will contain characters ranging from A to Z in some arbitrary order, and determine what elements still remain in a virtual cache that can hold up to 5 elements with an LRU cache algorithm implemented.For example : if strArr is["A", "B", "C", "D", "A", "E", "D", "Z"], then the following steps are taken :
// 
// (1) A does not exist in the cache, so access it and store it in the cache.
// (2) B does not exist in the cache, so access it and store it in the cache as well.So far the cache contains : ["A", "B"].
// (3) Same goes for C, so the cache is now : ["A", "B", "C"].
// (4) Same goes for D, so the cache is now : ["A", "B", "C", "D"].
// (5) Now A is accessed again, but it exists in the cache already so it is brought to the front : ["B", "C", "D", "A"].
// (6) E does not exist in the cache, so access it and store it in the cache : ["B", "C", "D", "A", "E"].
// (7) D is accessed again so it is brought to the front : ["B", "C", "A", "E", "D"].
// (8) Z does not exist in the cache so add it to the front and remove the least recently used element : ["C", "A", "E", "D", "Z"].
// 
// Now the caching steps have been completed and your program should return the order of the cache with the elements joined into a string, separated by a hyphen.Therefore, for the example above your program should return C - A - E - D - Z.
// 

#include <string>
#include <unordered_map>
#include <list>
#include <stack>


using namespace  std;



void put(string str, list<string>& listTmp, unordered_map<string, list<string>::iterator>& mapTmp, int size)
{
	auto it = mapTmp.find(str);
	if (it == mapTmp.end())
	{
		if(mapTmp.size() >= size)
		{
			auto it_list = listTmp.back();
			listTmp.pop_back();
			mapTmp.erase(it_list);
		}
		//
		listTmp.push_front(str);
		mapTmp[str] = listTmp.begin();
	}
	else
	{
		listTmp.erase(mapTmp[str]);
		listTmp.push_front(str);
		mapTmp[str] = listTmp.begin();
	}
}


string ArrayChallenge(string strArr[], int arrLength) {
	
	list<string> listTmp;
	unordered_map<string, list<string>::iterator> mapTmp;

	for (auto i = 0; i < arrLength; ++i)
	{
		put(strArr[i], listTmp, mapTmp, 5);
	}
	
	int i = 0;
	string res; 
	for (auto it = listTmp.rbegin(); it != listTmp.rend(); ++it)
	{
		if (res.length() == 0)
			res += *it;
		else
		{
			res += "->";
			res += *it;
		}
	}
	
	// code goes here  
	return res;

}

