#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Владелец\source\repos\ConsoleApplication3ipzlaba\ConsoleApplication3ipzlaba\ConsoleApplication3ipzlaba.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_tests)
    {
    public:
        TEST_METHOD(check_RightInput1) {
            float a = 1;
            float b = 20;
            float h = 1;
            float n = 3;

            try
            {
                checkValidInput();
                checkValidParams(a, b, n, h);
                Assert::IsTrue(true);
            }
            catch (const std::exception&)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(check_RightInput2) {
            float a = -10;
            float b = 10;
            float h = 0.2;
            float n = 5;

            try
            {
                checkValidInput();
                checkValidParams(a, b, n, h);
                Assert::IsTrue(true);
            }
            catch (const std::exception&)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(check_WrongInput1) {
            float a = 5;
            float b = -3;
            float h = 1;
            float n = 7;

            try
            {
                checkValidInput();
                checkValidParams(a, b, n, h);
                Assert::IsTrue(true);
            }
            catch (const std::exception&)
            {
                Assert::Fail();
            }
        }
        TEST_METHOD(check_WrongInput2) {
            float a = -3;
            float b = 10;
            float h = -5;
            float n = 4;

            try
            {
                checkValidInput();
                checkValidParams(a, b, n, h);
                Assert::IsTrue(true);
            }
            catch (const std::exception&)
            {
                Assert::Fail();
            }
        }
    };
}
