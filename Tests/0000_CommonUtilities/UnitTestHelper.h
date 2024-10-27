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

	template<typename T>
	string VerifyVectorResult(vector<pair<T,T>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator.first) + "(" + to_string(iterator.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}
	
	template<typename T>
	string VerifyVectorResult(vector<pair<T, pair<T, T>>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator.first) + "(" + to_string(iterator.second.first) + "," + to_string(iterator.second.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}

	template<typename T>
	string VerifyVectorResult(vector<vector<T>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += "[";
			for (auto& it : iterator)
			{
				result += to_string(it) + " ";
			}
			result += "]";
		}
		return result;
	}
};