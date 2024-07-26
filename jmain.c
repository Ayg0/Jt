#include "JTest.h"

_testStruct jTestData;

void	printTestInfo(int lineNb){
	static int currentTest;
	fprintf(stderr, "Test #%03d Line #%03d: ", currentTest, lineNb);
	currentTest++;
}

void	displaySuccess(){
	fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n");
	jTestData.OKTests++;
}

void	displayFail(){
	jTestData.KOTests++;
	fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR);
}

void jStart(){
	fprintf(stderr, "========================== JTEST START ==========================\n");
}

void jEnd(){
	int		totalTests = jTestData.OKTests + jTestData.KOTests;
	float	successPercentage;

	if (totalTests != 0)
		successPercentage = (float)(jTestData.OKTests * 100) / totalTests;
	else
		successPercentage = 0;
	fprintf(stderr, "\nTESTS RAN:    %d\nPASSED:       %d\nFailed:       %d\nSUCCESS RATE: %.2f%%\n", 
	totalTests,
	jTestData.OKTests,
	jTestData.KOTests,
	successPercentage);
	fprintf(stderr, "=========================== JTEST END ===========================\n");
}

void isEqualInt(int expected, int resulted, int lineNb){
	printTestInfo(lineNb);
	if (expected == resulted)
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, " => Expected %d, resulted %d\n", expected, resulted);
	}
}

void isEqualFloat(float expected, float resulted, int lineNb){
	printTestInfo(lineNb);
	if (expected == resulted)
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, " => Expected %.3f, resulted %.3f\n", expected, resulted);
	}
}

void isEqualStr(const char *expected, const char *resulted, int lineNb){
	printTestInfo(lineNb);
	if (!strcmp(expected, resulted))
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, " => Expected %s, resulted %s\n", expected, resulted);
	}
}

void	printData(void *data, void (*print)(void *)){
	if (print)
		print(data);
	else
		fprintf(stderr, "AYO Can't print this\n");
}

void	isDataEqual(void *expected, void *resulted, int lineNb, int (*cmp)(void *, void *), void (*print)(void *)){
	printTestInfo(lineNb);
	if (cmp(expected, resulted))
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, "\n--- EXPECTED ---\n");
		printData(expected, print);
		fprintf(stderr, "--- Resulted ---\n");
		printData(resulted, print);
		fprintf(stderr, "----------------\n");
	}
}


void	registerTest(testFunction test){
	if (jTestData.testsNb >= MAX_TESTS){
		fprintf(stderr, "Are you Sure about Running more than %d TestGroups ?!?\nif Yes: You can change it from the JTest.h\n", MAX_TESTS);
		exit(1);
	}
	jTestData.tests[jTestData.testsNb].func = test;
	jTestData.tests[jTestData.testsNb].test = NULL;
	jTestData.testsNb++;
}

void	runTest(){
	for (int i = 0; i < jTestData.testsNb; i++)
		jTestData.tests[i].func();
}