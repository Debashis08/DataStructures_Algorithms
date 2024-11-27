#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class UnitTestHelper
{
public:
	template<typename T>
	string SerializeVectorToString(vector<T> vector)
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
	string SerializeVectorToString(vector<pair<T,T>> vector)
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
	string SerializeVectorToString(vector<pair<T, pair<T, T>>> vector)
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
	string SerializeVectorToString(vector<vector<T>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += "[";
			for (auto& it : iterator)
			{
				result += to_string(it) + " ";
			}
			if (!result.empty())
			{
				result.pop_back();
			}
			result += "]";
		}
		return result;
	}


	// This helper method is used to sort the vector of vectors of a particular typename.
	// Each inner vector is sorted first.
	// Then each of them are sorted by their first element, in increasing order.
	template<typename T>
	vector<vector<T>> SortVectorOfVectors(vector<vector<T>> data)
	{
		// Step 1: Sorting each inner vectors.
		for (auto& innerVector : data)
		{
			sort(innerVector.begin(), innerVector.end());
		}

		// Step 2: Sorting all the vectors by their first element, in increasing order.
		sort(data.begin(), data.end(), [](const vector<T>& a, const vector<T>& b)
			{
				// Checking if both inner vectors are empty to prevent out-of-bounds access.
				if (a.empty() && b.empty())
					return false;

				// Considering empty vector as less than non-empty vector.
				if (a.empty())
					return true;

				// Considering non-empty vector as greater than empty vector.
				if (b.empty())
					return false;

				// Comparing the first elements of each vector.
				return (a[0] < b[0]);
			});

		return data;
	}

	template<typename T>
	vector<T> NormalizeCycle(vector<T> data)
	{
		if (data.empty())
		{
			return {};
		}
		auto minimumElementIterator = min_element(data.begin(), data.end());
		long long startIndex = distance(data.begin(), minimumElementIterator);
		vector<T> normalizedCycle;
		normalizedCycle.insert(normalizedCycle.end(), data.begin() + startIndex, data.end());
		normalizedCycle.insert(normalizedCycle.end(), data.begin(), data.begin() + startIndex);
		return normalizedCycle;
	}
};