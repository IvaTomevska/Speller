#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<array>

#include "mysearch.h"

using namespace std;

//searchForWord function is called when the user just searches for a word
void searchForWord(string &searchWord, vector <string> &array)
{
	int mid, left=0;
	int right=array.size();
	int ctr=0;
	int *x=&ctr;//we have a pointer because we get the number of comparisons from a seperate function
	bool isTrue=false;
	//we call a seperate function for binary search through the vector array
	mid=binarySearch(searchWord, array, left, right, x);

	if (mid==-1)
		cout<<"Word not found."<<endl;	
	else
		cout<<"Word found.\n"<<ctr<<" comparisons carried out."<<endl;

	
}

//searchForPrefix function is called when the user just searches for a prefix indicated with '*'
//it returns a vector of the results because we use this function to find the resilts for the query search
vector <string> searchForPrefix(string &searchPrefix, vector <string> &array, int* a, int b)
{
	int ctr=0, mid;
	bool temp=false;
	int left=0;
	int right=array.size();
	vector <string> results;
	string prefix=searchPrefix.substr(0,searchPrefix.find('*'));//substracting '*'
	string temstr;
	//we use a binary search algorithm to look through the dictionary
	//we dont use the same binary search function as for wordSearch
	//because we need a temporary string that will hold the characters before '*'
	while(left<=right)
	{	
		mid=(left+right)/2;
		temstr=array[mid].substr(0,prefix.length());
		if (temstr>prefix)
			right=mid-1;
		else if (temstr<prefix)
			left=mid+1;
		else if (temstr==prefix)
		{
			if (temp==false)
			{
				temp=true;
				break;
			}
		}
		if (temp==false)
			ctr++;	
	}

	//we use a while loop to find the firt occurence of the prefix
	while(1)
	{
		if(!comp(prefix,array[mid]))//we call comp for string comparison
		{
			mid++;
			break;
		}
		mid--;
	}
	if (*a==0)
		*a+=ctr;//we use a pointer to retirn the number of comparisons to the searchq function

	//after we find the first occurence we append the words with the prefix in order
	while(1)
	{
		if(!comp(prefix,array[mid]))
			break;
		results.push_back(array[mid]);
		mid++;
	}

	
	if(*a==1)//we have a mark here because we don't want this to execute if this function
			//is called by the searchqfunction
	{
		cout<<results.size()<<" matches found"<<endl;
		for (int i=0;i<b;i++)
			cout<<results[i]<<endl;
		if(results.empty())
			cout<<"Such prefix not found."<<endl;
		cout<<ctr<<" comparisons up-to the first match."<<endl;
	}
	return results;
}

//searchq function is called when the user just searches for a query indicated with '?'
void searchq(string &query, vector <string> &array, int b)
{
	int qM = 0 ;
	int ctr=0;
	int *a=&ctr;//we use a pointer because we get the number of searches from another function
	vector <string> results, tempresults;

	string prefix=query.substr(0,query.find('?'));//making a prefix until '?' to pass to the searchForPrefix function
	tempresults=searchForPrefix(prefix,array, a, 0);
	string sufix=query.substr(query.find('?')+1);//making a sufix from '?' until the end of the user's input
	string tempstr;
	//checking which of the resilus that mathch the prefix, also match the sufix
	for (int i=0;i<tempresults.size();i++)
	{
		tempstr=tempresults[i].substr(query.find('?')+1);
		if (tempstr==sufix)
		{
			results.push_back(tempresults[i]);
			ctr+=1;
		}

	}
	
	cout<<results.size()<<" matches found"<<endl;
	//printing the results
	if (results.size()<=b)//b is the number given in the comand prompt
	{
		for (int i=0;i<results.size();i++)
			cout<<results[i]<<endl;
	}
	else
	{
		for (int i=0;i<b;i++)
			cout<<results[i]<<endl;
	}


	cout<<ctr<<" comparisons made."<<endl;
}

//recursive function for binary searching
int binarySearch(string &searchWord, vector <string> &array, int left,int right, int* ctr)

{
	if (right>=left)
	{
		int mid=(left+right)/2;
		(*ctr)++;
		if (array[mid]==searchWord)
			return mid;

		else if (array[mid]>searchWord)
			binarySearch(searchWord, array, left, mid-1, ctr);

		else
			binarySearch(searchWord, array, mid+1, right, ctr);
	}
	else
		return -1;
}

//string comparison function
bool comp(string & prefix, string & word)
{
	int len=prefix.length();
	for (int i=0; i<len; i++)
	{
		if (prefix[i]!=word[i])
			return 0;
	}
	return 1;
}

