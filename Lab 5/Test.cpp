#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "SLLSet.h"
#include <iostream>




void testSLLSet() {



        //test constructor 1
        SLLSet listObj1 = SLLSet();
        string expectedSet = "";
        int expectedSize = 0;
        ASSERT_EQUAL(expectedSize,listObj1.getSize());
        ASSERT_EQUAL(expectedSet,listObj1.toString());
	}


void testSLLSetIntArray() {

        int arr[] = {1, 2, 3, 7, 8}; // this list

        SLLSet listObj2 = SLLSet(arr,5);
        string expectedSet = "1, 2, 3, 7, 8";
        int expectedSize = 5;
        ASSERT_EQUAL(expectedSize,listObj2.getSize());
        ASSERT_EQUAL(expectedSet,listObj2.toString());
	}

void testSLLSetZero() {
        int arr[0];

        SLLSet listObj2 = SLLSet(arr,0);
        string expectedSet = "";
        int expectedSize = 0;
        ASSERT_EQUAL(expectedSize,listObj2.getSize());
        ASSERT_EQUAL(expectedSet,listObj2.toString());
	}


void testCopy() {

        int arr[] = {1, 2, 3, 7, 8}; // this list
        SLLSet listObj2 =  SLLSet(arr,5);
		SLLSet copied = listObj2.copy();
        copied.add(100);
        string expectedObj2 = "1, 2, 3, 7, 8";
        string expectedCopied = "1, 2, 3, 7, 8, 100";
        int expectedObj2Size = 5;
        int expectedCopiedSize = 6;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());

        ASSERT_EQUAL(expectedCopiedSize,copied.getSize());
        ASSERT_EQUAL(expectedCopied,copied.toString());


	}

void testCopy2() {

        int arr[0]; // this list
        SLLSet listObj2 =  SLLSet(arr,0);
		SLLSet copied = listObj2.copy();
        copied.add(5);
        string expectedObj2 = "";
        string expectedCopied = "5";
        int expectedObj2Size = 0;
        int expectedCopiedSize = 1;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());

        ASSERT_EQUAL(expectedCopiedSize,copied.getSize());
        ASSERT_EQUAL(expectedCopied,copied.toString());


	}


void testIsInTrue() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int in = 2;

        bool expected = true;

        ASSERT_EQUAL(expected,listObj2.isIn(in));


	}

void testIsIn1() {

    int arr[] = {1}; // this list
    SLLSet listObj2 =  SLLSet(arr,1);

        int in = 1;

        bool expected = true;

        ASSERT_EQUAL(expected,listObj2.isIn(in));
	}


void testIsInFalse() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int notin = 0; // test isIn
        bool expected = false;

        ASSERT_EQUAL(expected,listObj2.isIn(notin));

	}



void testAdd1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int notadd = 3;


        string expectedObj2 = "1, 2, 3, 7, 8";
        int expectedObj2Size = 5;

        listObj2.add(notadd);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testAdd2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int addmiddle = 4;


        string expectedObj2 = "1, 2, 3, 4, 7, 8";
        int expectedObj2Size = 6;

        listObj2.add(addmiddle);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}


void testAdd3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int addlast = 9;


        string expectedObj2 = "1, 2, 3, 7, 8, 9";
        int expectedObj2Size = 6;

        listObj2.add(addlast);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int addfirst = 0;  // test add

        string expectedObj2 = "0, 1, 2, 3, 7, 8";
        int expectedObj2Size = 6;

        listObj2.add(addfirst);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testAdd5() {

    int arr[] = {}; // this list
    SLLSet listObj2 =  SLLSet(arr,0);

        int notadd = 1;


        string expectedObj2 = "1";
        int expectedObj2Size = 1;

        listObj2.add(notadd);
        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int notremove = 10;

        //test remove

        listObj2.remove(notremove);

        string expectedObj2 = "1, 2, 3, 7, 8";
        int expectedObj2Size = 5;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());




	}


void testRemove2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int removemiddle = 3;


        //test remove

        listObj2.remove(removemiddle);

        string expectedObj2 = "1, 2, 7, 8";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());



	}

void testRemove3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int removelast = 8;


        //test remove

        listObj2.remove(removelast);

        string expectedObj2 = "1, 2, 3, 7";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        int removefirst = 1;  // test remove

        //test remove

        listObj2.remove(removefirst);

        string expectedObj2 = "2, 3, 7, 8";
        int expectedObj2Size = 4;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}

void testRemove5() {

    int arr[0]; // this list
    SLLSet listObj2 =  SLLSet(arr,0);

        int removefirst = 1;  // test remove

        //test remove

        listObj2.remove(removefirst);

        string expectedObj2 = "";
        int expectedObj2Size = 0;

        ASSERT_EQUAL(expectedObj2Size,listObj2.getSize());
        ASSERT_EQUAL(expectedObj2,listObj2.toString());


	}


void testUnion1() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);




        SLLSet listObj3 = SLLSet();
        SLLSet listObj4 = listObj2.setUnion(listObj3);


        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj4.getSize());
        ASSERT_EQUAL(expected,listObj4.toString());




	}


void testUnion2() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
    int uni1[] = {0, 2, 3, 8, 10, 20};


        SLLSet listObj5 = SLLSet(uni1,6);
        SLLSet listObj6 = listObj2.setUnion(listObj5);

        string expected = "0, 1, 2, 3, 7, 8, 10, 20";
        int expectedSize = 8;

        ASSERT_EQUAL(expectedSize,listObj6.getSize());
        ASSERT_EQUAL(expected,listObj6.toString());



	}

void testUnion3() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
        int uni2[] = {0, 2, 3}; // for testing union
        SLLSet listObj7 = SLLSet(uni2,3);
        SLLSet listObj8 = listObj2.setUnion(listObj7);

        string expected = "0, 1, 2, 3, 7, 8";
        int expectedSize = 6;

        ASSERT_EQUAL(expectedSize,listObj8.getSize());
        ASSERT_EQUAL(expected,listObj8.toString());

	}

void testUnion4() {
        // test union
    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        SLLSet listObj3 = SLLSet();
        SLLSet listObj9 = listObj3.setUnion(listObj2);

        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj9.getSize());
        ASSERT_EQUAL(expected,listObj9.toString());


	}

void testUnion5() {
    int arr[0]; // this list
    SLLSet listObj2 =  SLLSet(arr,0);


    	int uni2[] = {5, 6, 7, 567, 5677888}; // for testing union
        SLLSet listObj3 = SLLSet(uni2,5);
        SLLSet listObj9 = listObj3.setUnion(listObj2);

        string expected = "5, 6, 7, 567, 5677888";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj9.getSize());
        ASSERT_EQUAL(expected,listObj9.toString());

	}


void testIntersection1() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        SLLSet listObj9 = SLLSet();
        SLLSet listObj10 = listObj2.intersection(listObj9);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj10.getSize());
        ASSERT_EQUAL(expected,listObj10.toString());



	}

void testIntersection2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

    int arr2[] = {0,2,7}; // this list
    SLLSet listObj11 =  SLLSet(arr2,3);


        SLLSet listObj12 = listObj2.intersection(listObj11);

        string expected = "2, 7";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj12.getSize());
        ASSERT_EQUAL(expected,listObj12.toString());




	}

void testIntersection3() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


        int inter2[] = {1, 3, 5, 6, 8, 10};




        SLLSet listObj13 = SLLSet(inter2,6);
        SLLSet listObj14 = listObj2.intersection(listObj13);

        string expected = "1, 3, 8";
        int expectedSize = 3;

        ASSERT_EQUAL(expectedSize,listObj14.getSize());
        ASSERT_EQUAL(expected,listObj14.toString());






	}

void testIntersection4() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);


    int inter3[] = {0, 10, 100}; //test intersection

    SLLSet listObj15 = SLLSet(inter3,3);
    SLLSet listObj16 = listObj2.intersection(listObj15);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj16.getSize());
        ASSERT_EQUAL(expected,listObj16.toString());

	}

void testIntersection5() {

    int arr[0]; // this list //main
    SLLSet listObj2 =  SLLSet(arr,0);

    int arr2[] = {1,2,3}; // this list //s
    SLLSet listObj11 =  SLLSet(arr2,3);


        SLLSet listObj12 = listObj2.intersection(listObj11);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj12.getSize());
        ASSERT_EQUAL(expected,listObj12.toString());

	}

void testDifference1() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);

        SLLSet listObj17 = SLLSet();
        SLLSet listObj18 = listObj2.difference(listObj17);

        string expected = "1, 2, 3, 7, 8";
        int expectedSize = 5;

        ASSERT_EQUAL(expectedSize,listObj18.getSize());
        ASSERT_EQUAL(expected,listObj18.toString());


	}

void testDifference2() {

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);



        int diff1[] = {1, 2, 3, 5, 7, 8, 9};
        SLLSet listObj19 = SLLSet(diff1,7);
        SLLSet listObj20 = listObj2.difference(listObj19);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj20.getSize());
        ASSERT_EQUAL(expected,listObj20.toString());




	}


void testDifference3() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);




    int diff2[] = {1, 2, 3}; // test difference
    // test difference
    SLLSet listObj21 = SLLSet(diff2,3);
    SLLSet listObj22 = listObj2.difference(listObj21);

        string expected = "7, 8";
        int expectedSize = 2;

        ASSERT_EQUAL(expectedSize,listObj22.getSize());
        ASSERT_EQUAL(expected,listObj22.toString());





	}


void testDifference4() {

	      // parameters inpt here

    int arr[] = {1, 2, 3, 7, 8}; // this list
    SLLSet listObj2 =  SLLSet(arr,5);
        SLLSet listObj17 = SLLSet();
        SLLSet listObj1000 = listObj17.difference(listObj2);

        string expected = "";
        int expectedSize = 0;

        ASSERT_EQUAL(expectedSize,listObj1000.getSize());
        ASSERT_EQUAL(expected,listObj1000.toString());

	}

void testDifference5() {

	      // parameters inpt here

    int arr[] = {1, 2, 3}; // this list
    SLLSet listObj2 =  SLLSet(arr,3);

    int arr42[] = {1, 2, 3};
	SLLSet listObj17 = SLLSet(arr42,3);
	SLLSet listObj1000 = listObj17.difference(listObj2);

	string expected = "";
	int expectedSize = 0;

	ASSERT_EQUAL(expectedSize,listObj1000.getSize());
	ASSERT_EQUAL(expected,listObj1000.toString());

	}


void testUnionSLLSetArray() {

        int arr1[] = {0, 1, 2};
        int arr2[] = {1, 2, 3, 4};
        int arr3[] = {0, 1};
        int arr4[] = {6, 7};
        SLLSet listObj100 = SLLSet(arr1,3);
        SLLSet listObj99 = SLLSet(arr2,4);
        SLLSet listObj98 = SLLSet(arr3,2);
        SLLSet listObj97 = SLLSet(arr4,2);
        SLLSet listObj96 = SLLSet();
        SLLSet Array[] = {listObj100, listObj99, listObj98, listObj97, listObj96}; // test static SLLSet union(sArray)

		 SLLSet listObj23 = SLLSet::setUnion(Array,5);

		 string expected = "0, 1, 2, 3, 4, 6, 7";
		 int expectedSize = 7;

		 ASSERT_EQUAL(expectedSize,listObj23.getSize());
		 ASSERT_EQUAL(expected,listObj23.toString());


	}

void testUnionSLLSetArray2() {

        SLLSet listObj100 = SLLSet();
        SLLSet listObj99 = SLLSet();
        SLLSet listObj98 = SLLSet();
        SLLSet listObj97 = SLLSet();
        SLLSet listObj96 = SLLSet();
        SLLSet Array[] = {listObj100, listObj99, listObj98, listObj97, listObj96}; // test static SLLSet union(sArray)

		 SLLSet listObj23 = SLLSet::setUnion(Array,5);

		 string expected = "";
		 int expectedSize = 0;

		 ASSERT_EQUAL(expectedSize,listObj23.getSize());
		 ASSERT_EQUAL(expected,listObj23.toString());


	}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };


	//TODO add your test here

    s.push_back(CUTE(testSLLSet));
    s.push_back(CUTE(testSLLSetIntArray));
    s.push_back(CUTE(testSLLSetZero));
    s.push_back(CUTE(testCopy));
    s.push_back(CUTE(testCopy2));
    s.push_back(CUTE(testIsInTrue));
    s.push_back(CUTE(testIsInFalse));
    s.push_back(CUTE(testIsIn1));
    s.push_back(CUTE(testAdd1));
    s.push_back(CUTE(testAdd2));
    s.push_back(CUTE(testAdd3));
    s.push_back(CUTE(testAdd4));
    s.push_back(CUTE(testAdd5));
    s.push_back(CUTE(testRemove1));
    s.push_back(CUTE(testRemove2));
    s.push_back(CUTE(testRemove3));
    s.push_back(CUTE(testRemove4));
    s.push_back(CUTE(testRemove5));
    s.push_back(CUTE(testUnion1));
    s.push_back(CUTE(testUnion2));
    s.push_back(CUTE(testUnion3));
    s.push_back(CUTE(testUnion4));
    s.push_back(CUTE(testUnion5));
    s.push_back(CUTE(testIntersection1));
    s.push_back(CUTE(testIntersection2));
    s.push_back(CUTE(testIntersection3));
    s.push_back(CUTE(testIntersection4));
    s.push_back(CUTE(testIntersection5));
    s.push_back(CUTE(testDifference1));
    s.push_back(CUTE(testDifference2));
    s.push_back(CUTE(testDifference3));
    s.push_back(CUTE(testDifference4));
    s.push_back(CUTE(testDifference5));
    s.push_back(CUTE(testUnionSLLSetArray));
    s.push_back(CUTE(testUnionSLLSetArray2));





	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
