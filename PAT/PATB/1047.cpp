#include <string>
#include <sstream>
#include <iostream> 
using namespace std;

int main()
{
    std::stringstream stream;
    std::string result;
    int i = 1000;
    stream << i; //��int������
    stream >> result; //��stream�г�ȡǰ������intֵ
    std::cout << result << std::endl; // print the string "1000"
} 
