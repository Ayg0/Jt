#include "JTest.h"

_testStruct tests;

void isEqualInt(int expected, int resulted, int lineNb){
	tests.TestsRan++;
	fprintf(stderr, "Line: %03d Test No %03d: ", lineNb, tests.TestsRan);
	if (expected == resulted)
		fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n"), tests.OKTests++;
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %d, resulted %d\n", expected, resulted), tests.KOTests++;
}

void isEqualFloat(float expected, float resulted, int lineNb){
	tests.TestsRan++;
	fprintf(stderr, "Line: %03d Test No %03d: ", lineNb, tests.TestsRan);
	if (expected == resulted)
		fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n"), tests.OKTests++;
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %.3f, resulted %.3f\n", expected, resulted), tests.KOTests++;
}

void isEqualStr(const char *expected, const char *resulted, int lineNb){
	tests.TestsRan++;
	fprintf(stderr, "Line: %03d Test No %03d: ", lineNb, tests.TestsRan);
	if (!strcmp(expected, resulted))
		fprintf(stderr, SUCC_COLOR "PASSED" DEFF_COLOR "\n"), tests.OKTests++;
	else
		fprintf(stderr, FAIL_COLOR "FAILED" DEFF_COLOR" => Expected %s, resulted %s\n", expected, resulted), tests.KOTests++;
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