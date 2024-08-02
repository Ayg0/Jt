#include "JTest.h"

typedef struct vector{
	int x;
	int y;
} _vector;

/*
	=> Compare Functions should take two arguments representing the address of the elements you want to compare.
	=> The Arguments should be of type void *.
	=> Should return 1 if the elements are equal and 0 if not.
*/
int cmpVector(void *vec1, void *vec2){
	_vector *v1 = vec1, *v2 = vec2;

	return (v1->x == v2->x) && (v1->y == v2->y);
}

/*
	=> Print Functions should take an argument representing the address of the element you want to print.
	=> The Argument should be of type void *.
	=> Should Return void.
*/
void printVector(void *data){
	_vector *vec = data;

	fprintf(stderr, "x = %3d; y = %3d\n", vec->x, vec->y);
}

/*
	=> Jsetup does run before each testGroup.
	=> Provides You with a way init the envirement for your test.
	=> Example: Allocation Memory, Connecting to The DataBase.
*/
void Jsetup(){
    // printf("\033[33mEnv Setup\033[0m\n");
}

/*
	=> Jcleanup does run after each testGroup.
	=> Provides You with a way clean up the envirement after your test.
	=> Example: Freeing Memory, Disconnecting from The DataBase.
*/
void Jcleanup(){
	// printf("\033[33mEnv cleanup\033[0m\n");
}

/*
	=> TEST_START allows you to group tests into a TestGroup.
	=> TEST_START Requires one Mangatory Argument which is the TestGroupName Example: vectorDataTests.
	=> TEST_START can Take an Optional Argument which is IGNORE_TEST, so the TestGroup will be ignored and not to be Run.
*/
TEST_START(vectorDataTests)
	_vector v1 = {.x = 0, .y = 6};
	_vector v2 = {.x = 0, .y = 6};
	ASSERT_DATA_EQU(&v1, &v2, cmpVector, printVector);
	ASSERT_HEX_EQU(6, 55);
	v2.x = 0;
	v2.y = 5;
	ASSERT_DATA_EQU(&v1, &v2, cmpVector, NULL);
TEST_END

TEST_START(sprintfTest, IGNORE_TEST)
	char s[20];
	sprintf(s, "%s", "Hey");
	ASSERT_STR_EQU("Hey", s);
TEST_END

TEST_START(vectorSimpleTests)
	ASSERT_FLOAT_EQU(7.3, 7.3);
	ASSERT_INT32_EQU(7.3, 7.3);
	ASSERT_STR_EQU("Hi", "Hi");
TEST_END

int	main(){
	/*
		JTEST_START init the envirement for JTEST
	*/
	JTEST_START;

	/*
		Use runTest(<TestGroupName>) to run an induvial TestGroup.
	*/
	// runTest(vectorSimpleTests);
	
	/*
		Use runall() to run all TestGroups.
	*/
	runAll();
	
	/*
		JTEST_END clean up the envirement after JTEST
	*/
	JTEST_END;
}
