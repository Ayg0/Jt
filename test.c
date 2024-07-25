#include "JTest.h"

_testStruct tests;

void isEqualInt(int expected, int resulted, int lineNb){
	tests.TestsRan++;
	fprintf(stderr, "Line: %d Test No %d: ", lineNb, tests.TestsRan);
	if (expected == resulted)
		fprintf(stderr, "PASSED\n"), tests.OKTests++;
	else
		fprintf(stderr, "FAILED Expected %d, resulted %d\n", expected, resulted), tests.KOTests++;
}

void isEqualStr(const char *expected, const char *resulted, int lineNb){
	tests.TestsRan++;
	fprintf(stderr, "Line: %d Test No %d: ", lineNb, tests.TestsRan);
	if (!strcmp(expected, resulted))
		fprintf(stderr, "PASSED\n"), tests.OKTests++;
	else
		fprintf(stderr, "FAILED Expected %s, resulted %s\n", expected, resulted), tests.KOTests++;
}

# define ASSERT_INT_EQU(EXPECTED, RESULT) isEqualInt(EXPECTED, RESULT, __LINE__)
# define ASSERT_STR_EQU(EXPECTED, RESULT) isEqualStr(EXPECTED, RESULT, __LINE__)

# define JTEST_START() fprintf(stderr, "==========================\n")
# define JTEST_END() fprintf(stderr, "\n%d Tests Ran, %d PASSED, and %d Failed, %.2f\%\n", tests.TestsRan, tests.OKTests, tests.KOTests, (float)(tests.OKTests * 100) / tests.TestsRan)

int	main(){
	JTEST_START();
	ASSERT_INT_EQU(3, printf("Hi\n"));
	ASSERT_INT_EQU(7, 7);
	ASSERT_INT_EQU(7, 7);
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hey", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	JTEST_END();
}