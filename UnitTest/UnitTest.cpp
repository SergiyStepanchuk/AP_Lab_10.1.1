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
			int count = 0;
			FILE* fp;
			if ((fp = fopen("r.txt", "r")) != NULL) {
				count = count_strs(fp);
				fclose(fp);
			}
			Assert::AreEqual(count, 2);
		}
	};
}
