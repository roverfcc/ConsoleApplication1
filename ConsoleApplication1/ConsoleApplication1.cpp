// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

#include <string>
#include<cstring>

using namespace std;

string longestCommonSubstring(const string& string1, const string& str2)
{

	if (string1.empty() || str2.empty())
	{
		return 0;
	}

	int *curr = new int[str2.size()];
	int *prev = new int[str2.size()];
	int *swap = nullptr;
	int maxSubstr = 0;
	int lastSubsBegin = 0;
	string sequenceBuilder;

	for (int i = 0; i<string1.size(); ++i)
	{
		for (int j = 0; j<str2.size(); ++j)
		{
			if (string1[i] != str2[j])
			{
				curr[j] = 0;
			}
			else
			{
				if (i == 0 || j == 0)
				{
					curr[j] = 1;
				}
				else
				{
					curr[j] = 1 + prev[j - 1];
				}

				if (maxSubstr < curr[j])
				{
					maxSubstr = curr[j];

					int thisSubsBegin = i - curr[j] + 1;
					if (lastSubsBegin == thisSubsBegin)
					{
						sequenceBuilder += string1[i];
					}
					else
					{
						lastSubsBegin = thisSubsBegin;
						sequenceBuilder = "";
						sequenceBuilder += string1.substr(lastSubsBegin, (i + 1) - lastSubsBegin);
					}
				}
			}
		}
		swap = curr;
		curr = prev;
		prev = swap;
	}

	delete[] curr;
	delete[] prev;

	return sequenceBuilder;
}

int main()
{
	string str1 = "the quick sfbrown fox jumps over the lazy dog";
	string str2 = "ghdsgf fjsdfg ghdsfbrown fox jumpshfsdjfg 457877fsdfhb$%";

	//string str1 = "Now is the time for all good men to come to the aid of their country.";
	//string str2 = "They are good men to come to the aid of their people.";

	//string value;
	string value = longestCommonSubstring(str1, str2);

	cout << "value: " + value + "\n";
	//cin.get();
	//cin.get();
	return 0;


}
	


//cin.get();