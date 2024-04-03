#include <iostream>
#include <map>
#include <string>

int main()
{
	{
		std::map<std::string, std::map<int, std::string>> Test;
		std::map<int, std::string> SubTest;
		SubTest.insert(std::make_pair(16, "CBuffer1"));
		SubTest.insert(std::make_pair(32, "CBuffer2"));
		Test.insert(std::make_pair("ColorTest", SubTest));
	}

	std::map<int, std::map<int, int>> Test;
	std::map<int, int> SubTest;
	SubTest.insert(std::make_pair(16, 16));
	SubTest.insert(std::make_pair(32, 32));

	Test.insert(std::make_pair(1, SubTest));
	Test.insert(std::make_pair(2, SubTest));

	for (std::pair<int, std::map<int, int>> TestResult1 : Test)
	{
		std::cout << TestResult1.first << std::endl;
		std::map<int, int> TestResult = TestResult1.second;
		for (std::pair<int, int> FianlResult : TestResult)
		{
			std::cout << FianlResult.first << " " << FianlResult.second << std::endl;
		}
	}


}

