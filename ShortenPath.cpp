#include "ShortenPath.h"

string shortenPath(string path) {
  // Write your code here.
  bool startsWithSlash = path[0] == '/';
  vector<string> tokens = tokenize(path);
  vector<string> removedEmptyAndSingleDot = 
  removeEmptyAndSingleDot(tokens);
  vector<string> removedParentDirSymbols = 
  removeParentDirSymbols(removedEmptyAndSingleDot, startsWithSlash);

  if(removedParentDirSymbols.size() == 1 && 
  removedParentDirSymbols[0] == "")
  {
    return "/";
  }

  return joinTokens(removedParentDirSymbols);
}

vector<string> tokenize(string path, string delimiter)
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

string joinTokens(vector<string> tokens)
{
  string joinedPath;
  for(int i = 0; i < tokens.size(); i++)
  {
    if(i != 0)
      joinedPath += "/";
    joinedPath += tokens[i];
  }
  return joinedPath;
}

vector<string> removeEmptyAndSingleDot(vector<string> tokens)
{
  vector<string>::iterator pend = remove(tokens.begin(), tokens.end(), ".");
  pend = remove(tokens.begin(), pend, "");
  vector<string> filteredTokens;
  filteredTokens.assign(tokens.begin(), pend);
  return filteredTokens;
}

vector<string> removeParentDirSymbols(vector<string> tokens, 
bool startsWithSlash)
{
  vector<string> dirStack;
  if(startsWithSlash)
    dirStack.push_back("");
  for(string token : tokens)
  {
    if(token == "..")
    {
      if(dirStack.size() == 0 || dirStack[dirStack.size() - 1] == "..")
        dirStack.push_back(token);
      else if (dirStack[dirStack.size() - 1] != "")
        dirStack.pop_back();
    }
    else
    {
      dirStack.push_back(token);
    }
  }
  
  return dirStack;
}