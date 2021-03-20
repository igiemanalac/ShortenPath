#include <iostream>
#include "ShortenPath.cpp"
using namespace std;

int main(void)
{
    string testPath = "/foo/bar/../test/only";
    cout << testPath.substr(0, testPath.find("\/.."));

    return 0;
}