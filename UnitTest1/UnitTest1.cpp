#include "pch.h"
#include "CppUnitTest.h"
#include "../2.1/Product.h"
#include "../2.1/Product.cpp"
#include "../2.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Product p(200, 2.5);
			Assert::AreEqual(200.0 * 2.5 * 10, p.power(), L"Parameterized constructor failed.");
		}
	};
}
