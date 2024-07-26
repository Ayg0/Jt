#include "JTest.h"

_testStruct tests;

void	printTestInfo(int lineNb, char *fileName){
	static char *file = NULL;

	if (!file || strcmp(file, fileName)){
		free(file);
		file = strdup(fileName);
		fprintf(stderr, "===============> Entering %s\n", file);
	}
	fprintf(stderr, "Test #%03d Line #%03d: ", tests.TestsRan, lineNb);
}

void	displaySuccess(){
	fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n");
	tests.OKTests++;
}

void	displayFail(){
	tests.KOTests++;
	fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR);
}

void jStart(){
	fprintf(stderr, "========================== JTEST START ==========================\n");
}

void jEnd(){
	fprintf(stderr, "\n%d Tests Ran, %d PASSED, and %d Failed, %.2f\%\n", 
	tests.TestsRan,
	tests.OKTests,
	tests.KOTests,
	(float)(tests.OKTests * 100) / tests.TestsRan);
	fprintf(stderr, "=========================== JTEST END ===========================\n");
}

void isEqualInt(int expected, int resulted, int lineNb, char *fileName){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
	if (expected == resulted)
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, " => Expected %d, resulted %d\n", expected, resulted);
	}
}

void isEqualFloat(float expected, float resulted, int lineNb, char *fileName){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
	if (expected == resulted)
		displaySuccess();
	else{
		displayFail();
		fprintf(stderr, " => Expected %.3f, resulted %.3f\n", expected, resulted);
	}
}

void isEqualStr(const char *expected, const char *resulted, int lineNb, char *fileName){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
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

void	isDataEqual(void *expected, void *resulted, int lineNb, char *fileName, int (*cmp)(void *, void *), void (*print)(void *)){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
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
