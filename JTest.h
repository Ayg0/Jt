#pragma once

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_TESTS 100

typedef void (*testFunction)();
typedef struct test
{
	testFunction	func;
	int				Ignored;
} _test;

typedef struct testStruct{
	int		testsNb;
	_test	tests[MAX_TESTS];
	int		OKTests;
	int		KOTests;
	int		IgnoredTests;
} _testStruct;
	
# define TEST_START(base)\
	void base(); \
    __attribute__((constructor)) void register_##base() { \
        registerTest(base); \
    }\
	void base(){\
		displayGroup(__COUNTER__, __func__);\
		Jsetup();\

# define TEST_END Jcleanup();\
}

# define IGNORE_ME return ;\

#ifdef USE_COLORS
	# define DEFF_COLOR "\033[0m"
	# define SUCC_COLOR "\033[1;37;42m"
	# define FAIL_COLOR "\033[1;37;41m"
	# define BLUE_BOLD_COLOR "\033[1;34m"
#else
	# define DEFF_COLOR "|"
	# define SUCC_COLOR "|"
	# define FAIL_COLOR "|"
	# define BLUE_BOLD_COLOR "|"
#endif

# define ASSERT_INT_EQU(EXPECTED, RESULT) isEqualInt(EXPECTED, RESULT, __LINE__)
# define ASSERT_STR_EQU(EXPECTED, RESULT) isEqualStr(EXPECTED, RESULT, __LINE__)
# define ASSERT_FLOAT_EQU(EXPECTED, RESULT) isEqualFloat(EXPECTED, RESULT, __LINE__)
# define ASSERT_DATA_EQU(EXPECTED, RESULT, CMP_FUNC, PRINT_FUNC) isDataEqual(EXPECTED, RESULT, __LINE__, CMP_FUNC, PRINT_FUNC)

# define JTEST_START() jStart()
# define JTEST_END() jEnd()
void	jEnd();
void	jStart();

void	Jsetup();
void	Jcleanup();

void	runTests();
void	registerTest(testFunction test);

void	isEqualInt(int expected, int resulted, int lineNb);
void	isEqualFloat(float expected, float resulted, int lineNb);
void	isEqualStr(const char *expected, const char *resulted, int lineNb);
void	isDataEqual(void *expected, void *resulted, int lineNb, int (*cmp)(void *, void *), void (*print)(void *));

void	displayGroup(int count, const char *testGroup);