#include <string>
#include <sstream>
#include <iostream> 
using namespace std;

int main()
{
    std::stringstream stream;
    std::string result;
    int i = 1000;
    stream << i; //将int输入流
    stream >> result; //从stream中抽取前面插入的int值
    std::cout << result << std::endl; // print the string "1000"
} 
