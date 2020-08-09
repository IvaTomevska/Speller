#ifndef MYSEARCH_H
#define MYSEARCH_H

#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<array>


using namespace std;

void searchForWord(string &, vector <string> &);
vector <string> searchForPrefix(string &, vector <string> &, int*, int);
bool comp(string & , string & );
int binarySearch(string &, vector <string> &, int , int, int* );
void searchq(string &, vector <string> &, int);

#endif
