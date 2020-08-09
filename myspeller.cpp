#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>

#include "mysearch.h"

using namespace std;


int main(int argc, char** argv)
{
	//declaring variables
	vector <string> dictionaryArray;
	string word;
	string begin;

	//creating and opening dictionary file for reading
	ifstream dictionaryFile;
	dictionaryFile.open(argv[2]); 
	
	//check if the dictionary file is succesfully open 
	if (!dictionaryFile)
	{
		cerr<<"Failed to open the file"<<endl;
		exit(1);
	}

	//crating array of the words
	while(dictionaryFile>>word)
		dictionaryArray.push_back(word);

	//main while loop
	while(1)
	{
		cout<<"Search or type exit to exit the program"<<endl;
		cin>>begin;
		if(begin=="exit")
			break;//the program stops when the user writes exit
		else
		{
			//we call the function that searches based on prefix
			//if the user inpus '*'
			if (begin.find('*')<begin.size())
			{
				int b=1;
				searchForPrefix(begin,dictionaryArray, &b, atoi(argv[4]));
			}
			//we call the function that searches a query
			//if the user inputs '?'
			else if (begin.find('?')<begin.size())
				searchq(begin,dictionaryArray, atoi(argv[4]));
			//we call the function that searches for aword
			//if the user doesn't input '?' or '*'
			else
				searchForWord(begin,dictionaryArray);
		}
	}

	dictionaryFile.close();//closing the text file
	return 0;

}

