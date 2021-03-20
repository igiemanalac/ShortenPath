#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string shortenPath(string path);
vector<string> tokenize(string path, string delimiter = "/");
string joinTokens(vector<string> tokens);
vector<string> removeEmptyAndSingleDot(vector<string> tokens);
vector<string> removeParentDirSymbols(vector<string> tokens, 
bool startsWithSlash);