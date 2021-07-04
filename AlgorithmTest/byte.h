#pragma once
#include <map>
#include <vector>
#include <iostream>



bool IsDependy(std::vector<std::pair<char, char> >& listVal, std::map<char, int> mapPath, char chTmp) {

	for (auto i = 1; i < listVal.size(); ++i)
	{
		auto stInfo = listVal[i];
		if (stInfo.first != chTmp)
			continue;
		auto it = mapPath.find(stInfo.second);
		if (it != mapPath.end())
			return true;

		mapPath[stInfo.second] = 0;
		if (IsDependy(listVal, mapPath, stInfo.second))
			return true;

		auto it_ = mapPath.find(stInfo.second);
		mapPath.erase(it_);
	}

	return false;
}

bool IsSearch(std::vector<std::pair<char, char> >&listval)
{
	if (listval.size() == 0)
		return false;

	std::map<char, int> mapPath;
	char chTmp = 0;

	auto stinfo = listval[0];
	mapPath[stinfo.first] = 0;
	mapPath[stinfo.second] = 0;
	return IsDependy(listval, mapPath, stinfo.second);
}

