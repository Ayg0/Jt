#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct testStruct{
	int TestsRan;
	int OKTests;
	int KOTests;
} _testStruct;

# define SUCC_COLOR "\033[1;37;42m"
# define FAIL_COLOR "\033[1;37;41m"
# define DEFF_COLOR "\033[0m"


# define ASSERT_INT_EQU(EXPECTED, RESULT) isEqualInt(EXPECTED, RESULT, __LINE__)
# define ASSERT_FLOAT_EQU(EXPECTED, RESULT) isEqualFloat(EXPECTED, RESULT, __LINE__)
# define ASSERT_STR_EQU(EXPECTED, RESULT) isEqualStr(EXPECTED, RESULT, __LINE__)

# define JTEST_START() jStart()
# define JTEST_END() jEnd()

void	jEnd();
void	jStart();
void	isEqualInt(int expected, int resulted, int lineNb);
void	isEqualFloat(float expected, float resulted, int lineNb);
void	isEqualStr(const char *expected, const char *resulted, int lineNb);

