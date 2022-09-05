#pragma once

#include <string>
#include <vector>


using namespace std;
string trim(std::string src)
{
	auto start = src.find_first_not_of(" ");
	auto end = src.find_last_not_of(" ");
	if (start == string::npos && end != string::npos)
		return src.substr(0, end + 1);
	else if(start != string::npos && end == string::npos)
		return src.substr(start);
	else if (start != string::npos && end != string::npos)
		return src.substr(start, end - start + 1);
	else
		return src;

	return src;
}
int splite(string str, vector<string>& vecTmp, char& ch)
{
	int nret = -1;
	ch = 0;
	int pos = 0;
	for (; pos < str.length(); ++pos)
	{
		if (str.at(pos) == '+' || str.at(pos) == '-' || str.at(pos) == '*' || str.at(pos) == '/')
		{
			ch = str.at(pos);
			break;
		}
	}
	//
	if (ch == 0)
		return nret;
	string val1 = str.substr(0, pos - 1);
	vecTmp.push_back(trim(val1));
	if (val1.find("x") != std::string::npos)
		nret = 0;
	auto pos1 = str.find("=");
	if (std::string::npos == pos1)
		return -1;
	string val2 = str.substr(pos + 1, pos1 - pos - 1);
	vecTmp.push_back(trim(val2));
	if (val2.find("x") != std::string::npos)
		nret = 1;
	
	string res = str.substr(pos1 + 1);
	vecTmp.push_back(trim(res));
	if (res.find("x") != std::string::npos)
		nret = 2;
	return nret;
}


std::string add(std::string val1, std::string val2)
{
	int val = atoi(val1.c_str()) + atoi(val2.c_str());
	return to_string(val);
}

std::string sub(std::string val1, std::string val2)
{
	int val = atoi(val1.c_str()) - atoi(val2.c_str());
	return to_string(val);
}

std::string multi(std::string val1, std::string val2)
{
	int val = atoi(val1.c_str()) * atoi(val2.c_str());
	return to_string(val);
}

std::string desp(std::string val1, std::string val2)
{
	int val = atoi(val1.c_str()) / atoi(val2.c_str());
	return to_string(val);
}


std::string match(std::string dst, std::string src)
{
	auto pos = dst.find("x");
	if (pos == string::npos)
		return "";
	
	int left = 0; 
	int right = src.length() - 1;
	for (; left < right && src.at(left) != 'x'; ++left);
	for (; right > left && src.at(right) != 'x'; --right);

	return src.substr(left, right - left + 1);
	
}

string MathChallenge(string str) {

	vector<string> vecTmp;
	char ch;
	int ret = splite(str, vecTmp, ch);
	if(ret < 0)
		return "";
	
	std::string res;
	switch (ch)
	{
	case '+':
		if (ret == 2)
			res = add(vecTmp[0], vecTmp[1]);
		else
			res = sub(vecTmp[2], vecTmp[1 - ret]);
		break;
	case '-':
		if (ret == 1)
			res = add(vecTmp[2], vecTmp[1]);
		else
			res = sub(vecTmp[0], vecTmp[3 - ret]);
		break;
	case '*':
		if (ret == 2)
			res = multi(vecTmp[0], vecTmp[1]);
		else
			res = desp(vecTmp[2], vecTmp[1 - ret]);
		break;
	case '/':
		if (ret == 1)
			res = multi(vecTmp[1], vecTmp[0]);
		else
			res = desp(vecTmp[0], vecTmp[3 - ret]);
		break;
	default:
		break;
	}

	return match(vecTmp[ret], res);
}