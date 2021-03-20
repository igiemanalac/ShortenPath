#include "ShortenPath.h"

int main(void)
{
    string testPath = "/foo/bar/../test/only";
    string testPath2 = "/foo/../test/../test/../foo//bar/./baz";
    string joined = shortenPath(testPath2);
    cout << joined << endl;
    return 0;
}