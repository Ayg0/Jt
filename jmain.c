#include "JTest.h"

_testStruct tests;

void	printTestInfo(int lineNb, char *fileName){
	static char *file = NULL;

	if (!file || strcmp(file, fileName)){
		file = strdup(fileName);
		fprintf(stderr, "===============> Entering %s\n", file);
	}
	fprintf(stderr, "Test #%03d Line #%03d: ", tests.TestsRan, lineNb);
}

void	displaySuccess(){
	fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n");
	tests.OKTests++;
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
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %d, resulted %d\n", expected, resulted), tests.KOTests++;
}

void isEqualFloat(float expected, float resulted, int lineNb, char *fileName){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
	if (expected == resulted)
		displaySuccess();
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %.3f, resulted %.3f\n", expected, resulted), tests.KOTests++;
}

void isEqualStr(const char *expected, const char *resulted, int lineNb, char *fileName){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
	if (!strcmp(expected, resulted))
		displaySuccess();
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %s, resulted %s\n", expected, resulted), tests.KOTests++;
}

void	isDataEqual(void *expected, void *resulted, int lineNb, char *fileName, int (*cmp)(void *, void *), void (*print)(void *)){
	tests.TestsRan++;
	printTestInfo(lineNb, fileName);
	if (cmp(expected, resulted))
		displaySuccess();
	else{
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR "\n");
		fprintf(stderr, "--- EXPECTED ---\n");
		print(expected);
		fprintf(stderr, "--- Resulted ---\n");
		print(resulted);
		fprintf(stderr, "----------------\n");
		tests.KOTests++;
	}
}
