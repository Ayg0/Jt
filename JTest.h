#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct testStruct{
	int TestsRan;
	int OKTests;
	int KOTests;
} _testStruct;

#ifdef USE_COLORS
	# define DEFF_COLOR "\033[0m"
	# define SUCC_COLOR "\033[1;37;42m"
	# define FAIL_COLOR "\033[1;37;41m"
#else
	# define DEFF_COLOR "|"
	# define SUCC_COLOR "|"
	# define FAIL_COLOR "|"
#endif

# define ASSERT_INT_EQU(EXPECTED, RESULT) isEqualInt(EXPECTED, RESULT, __LINE__, __FILE__)
# define ASSERT_FLOAT_EQU(EXPECTED, RESULT) isEqualFloat(EXPECTED, RESULT, __LINE__, __FILE__)
# define ASSERT_STR_EQU(EXPECTED, RESULT) isEqualStr(EXPECTED, RESULT, __LINE__, __FILE__)
# define ASSERT_DATA_EQU(EXPECTED, RESULT, CMP_FUNC, PRINT_FUNC) isDataEqual(EXPECTED, RESULT, __LINE__, __FILE__, CMP_FUNC, PRINT_FUNC)

# define JTEST_START() jStart()
# define JTEST_END() jEnd()

void	jEnd();
void	jStart();
void	isEqualInt(int expected, int resulted, int lineNb, char *fileName);
void	isEqualFloat(float expected, float resulted, int lineNb, char *fileName);
void	isEqualStr(const char *expected, const char *resulted, int lineNb, char *fileName);
void	isDataEqual(void *expected, void *resulted, int lineNb, char *fileName, int (*cmp)(void *, void *), void (*print)(void *));
