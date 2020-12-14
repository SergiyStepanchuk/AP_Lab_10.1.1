#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Program/main.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(met_count_strs)
		{
			ifstream stream("r.txt");
			int count = 0;
			if (stream.is_open()) {
				count = count_strs(stream);
				stream.close();
			}
			Assert::AreEqual(count, 2);
		}
	};
}
