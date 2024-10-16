#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class UnitTestHelper
{
public:
	template<typename T>
	string VerifyVectorResult(vector<T> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator) + " ";
		}
		result.pop_back();
		return result;
	}

	template<typename T1, typename T2>
	string VerifyVectorResult(vector<pair<T1,T2>> vector)
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