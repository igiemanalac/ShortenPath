#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string shortenPath(string path) {
  // Write your code here.
  return "";
}

vector<string> tokenize(string path, string delimiter = "/")
{
  vector<string> tokens;
  size_t startPos = 0;
  size_t endPos = path.find(delimiter);
  while(endPos != string::npos)
  {
    tokens.push_back(path.substr(startPos, endPos - startPos));
    startPos = endPos + delimiter.size();
    endPos = path.find(delimiter, startPos);
  }
  tokens.push_back(path.substr(startPos, endPos - startPos));
  return tokens;
}

void removeEmptyAndSingleDot(vector<string> *tokens)
{
  remove(tokens->begin(), tokens->end(), "");
  remove(tokens->begin(), tokens->end(), ".");
}

string removeParentDirSymbols(string path)
{
    size_t parentDirSymbolPos = path.find("\/..");
	while(parentDirSymbolPos != string::npos)
	{
        if(parentDirSymbolPos != 0)
        {
		    string tmp = path.substr(0, parentDirSymbolPos);
            size_t parentDir = tmp.rfind("/");
            tmp = tmp.substr(0, parentDir);
        }
	}
}