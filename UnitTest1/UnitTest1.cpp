#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.4/lab10.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConvertPriceToUAH_WithValidInput_ReturnsCorrectConversion)
		{
			double priceInDollars = 100; 
			double exchangeRate = 27.5; 
			double expectedPriceInUAH = 2750; 

			double result = convertPriceToUAH(priceInDollars, exchangeRate);
			Assert::AreEqual(expectedPriceInUAH, result);
		}

		TEST_METHOD(ConvertPriceToUAH_WithZeroExchangeRate_ReturnsZero)
		{
			double priceInDollars = 100; 
			double exchangeRate = 0; 
			double expectedPriceInUAH = 0; 

			double result = convertPriceToUAH(priceInDollars, exchangeRate);
			Assert::AreEqual(expectedPriceInUAH, result);
		}

		TEST_METHOD(ConvertPriceToUAH_WithNegativePrice_ReturnsNegativeConversion)
		{
			double priceInDollars = -100; 
			double exchangeRate = 27.5; 
			double expectedPriceInUAH = -2750; 

			double result = convertPriceToUAH(priceInDollars, exchangeRate);
			Assert::AreEqual(expectedPriceInUAH, result);
		}
	};
}