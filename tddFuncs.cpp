#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <sstream>

using namespace std;

string exec(const char *cmd)
{
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
    {
        throw runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }
    return result;
}

void assertImgMatch(string answer,
                    string key,
                    string message,
                    double threshold = 0)
{
    string res = exec("./CompareImg a.JPG b.JPG");
    double diff = stod(res);

    ostringstream ea;
    if (diff <= threshold)
    {
        ea << "| PASSED: " << message << endl;
    }
    else
    {
        ea << "|   FAILED: " << message << endl;
    }
    cout << ea.str();
}

int main(int argc, char **argv)
{
    assertImgMatch("a.JPG", "b.JPG", "ImgTest1", 10);
}
