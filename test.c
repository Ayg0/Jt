#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct testStruct{
	int TestsRan;
	int OKTests;
	int KOTests;
}_testStruct;

_testStruct tests;

# define CHECK_EQUAL(EXPECTED, RESULT, LINE) tests.TestsRan++;\
												printf("Line: %d Test No %d: ", LINE, tests.TestsRan);\
												if (EXPECTED == RESULT)\
													printf("PASSED\n"), tests.OKTests++;\
												else\
													printf("FAILED Expected %d, resulted %d\n", EXPECTED, RESULT), tests.KOTests++

# define CHECK_STR_EQUAL(EXPECTED, RESULT, LINE) tests.TestsRan++;\
												printf("Line: %d Test No %d: ", LINE, tests.TestsRan);\
												if (!strcmp(EXPECTED, RESULT))\
													printf("PASSED\n"), tests.OKTests++;\
												else\
													printf("FAILED Expected %s, resulted %s\n", EXPECTED, RESULT), tests.KOTests++

# define ASSERT_EQU(EXPECTED, RESULT) CHECK_EQUAL(EXPECTED, RESULT, __LINE__)
# define ASSERT_STR_EQU(EXPECTED, RESULT) CHECK_STR_EQUAL(EXPECTED, RESULT, __LINE__)

int	main(){
	ASSERT_EQU(3, printf("Hi\n"));
	ASSERT_EQU(7, 7);
	ASSERT_EQU(7, 7);
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	printf("%d Tests Ran, %d PASSED, and %d Failed, %.2f\%\n", tests.TestsRan, tests.OKTests, tests.KOTests, (float)(tests.OKTests * 100) / tests.TestsRan);
}