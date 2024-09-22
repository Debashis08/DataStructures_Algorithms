#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename T>
class UnitTestHelper
{
public:
	string VerifyVectorResult(vector<T> vector)
	{
		string result = "";
		for (auto iterator : vector)
		{
			result += to_string(iterator) + " ";
		}
		result.pop_back();
		return result;
	}
};
