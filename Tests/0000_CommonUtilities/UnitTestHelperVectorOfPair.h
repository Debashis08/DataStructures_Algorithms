#pragma once

#include<iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;

template<typename T1, typename T2>
class UnitTestHelperVectorOfPair
{
public:
	string VerifyVectorOfPair(vector<pair<T1,T2>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += string(1, iterator.first) + "(" + to_string(iterator.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}
};