#include "MainBST.h"

#include "mainAVL.h"
#include "InsertNode.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>
#include <time.h>
#include <cstdlib>


InsertNode insertNode;

int inOrderTraversalTest() {
	timespec tmsp;
	unsigned long long nanoSec;
	unsigned long long milliSec;
	clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);
	insertNode.print();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);
		nanoSec = (unsigned long long) (tmsp.tv_sec * 1000000000)
				+ (unsigned long long) tmsp.tv_nsec;
		milliSec = nanoSec / 1000000;

		cout << "Inorder traversal completed in " << milliSec << " milli seconds"
				<< endl;
		cout << endl;
		return 0;
}

int deleteTest() {
	timespec tmsp;
	unsigned long long nanoSec;
	unsigned long long milliSec;
	clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);
	insertNode.deleteAll();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);
		nanoSec = (unsigned long long) (tmsp.tv_sec * 1000000000)
				+ (unsigned long long) tmsp.tv_nsec;
		milliSec = nanoSec / 1000000;

		cout << "Deleting elements in " << milliSec << " milli seconds"
				<< endl;
		cout << endl;
		return 0;
}

int insertTest() {
	timespec tmsp;
	long insertSIZE;
	cout << "How many elements you want to insert" << endl;
	cin >> insertSIZE;
	int insertSTART = 1;
	int insertEND = insertSIZE;
	bool mybool = true;
	int option;
	unsigned long long nanoSec;
	unsigned long long milliSec;

	clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);

	for (int i = insertSTART; i <= insertEND;i++) {
		tmsp.tv_sec = 0;
		tmsp.tv_nsec = 0;
			insertNode.insertNode(i);

	}
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tmsp);
	nanoSec = (unsigned long long) (tmsp.tv_sec * 1000000000)
			+ (unsigned long long) tmsp.tv_nsec;
	milliSec = nanoSec / 1000000;

	cout <<insertSIZE<< " insert operations " << milliSec << " milli seconds"
			<< endl;
	cout << endl;
	while(mybool){
		cout << "Choose an Option:" << endl;
		cout << "Enter 1 for InorderTraversal to display the elements" << endl;
		cout << "Enter 2 for deleting all the elements" << endl;
		cout << "Enter 3 for Exit" << endl;
		cin >> option;

		switch (option) {
		case 1:
			cout << "You entered one." << endl;
			inOrderTraversalTest();
			break;
		case 2:
			cout << "You entered two." << endl;
			deleteTest();
			break;
		case 3:
			mybool = false;
			break;
		default:
			break;
		}

	}
	return 0;
}



int avlTreeOperations() {
	long key;
	long size; // insertion elements size
	long element;
	bool mybool = true;
	int option = -1;
	mainAVL dictionary;

	while(mybool != false){
		cout << "Choose an Option:" << endl;
		cout << "1: Insert" << endl;
		cout << "2: Delete" << endl;
		cout << "3: Display" << endl;
		cout << "0: Exit Program" << endl;
		cout <<  "Enter option" << endl;
		cin >> option;


			if (option == 1) {
				cout << "How many elements you want to enter" << endl;
				cin >> size;

				for(int i = 0; i < size; i++) {
					cout << "enter " << i << " value " << endl;
					cin >> key;
					insertNode.insertNode(key);
				}

		} else if (option == 2) {
				cout << "Enter the element that you would like to remove." << endl;
				cin >> element;
				insertNode.deleteNode(element);
				insertNode.print();
				}
		else if (option == 3) {
					insertNode.print();

			}
		else {
			mybool = false;
		}
		}

	return 0;
}
int randomTest() {
	bool mybool = true;
	int option;
	mainAVL dictionary;
	while(mybool){
		cout << "Choose an Option:" << endl;
		cout << "1: Insert" << endl;
		cout << "2: Delete" << endl;
		cout << "3: InorderTraversal" << endl;
		cout << "4: Exit Program" << endl;
		cout <<  "Enter option" << endl;
		cin >> option;

		switch (option) {
		case 1:
			cout << "You entered one." << endl;
			insertTest();
			break;
		case 2:
			cout << "You entered two." << endl;
			deleteTest();
			break;
		case 3:
			cout << "You entered Three." << endl;
			inOrderTraversalTest();
			break;
		case 4:
			mybool = false;
			break;
		default:
			break;
		}
	}

	return 0;
}
int main() {
	bool mybool = true;
	int num;


	cout << "Enter 1 to test with manual data" << endl;
	cout << "Enter 2 to test with Random data" << endl << endl;

	while (mybool) {
		cout << "Enter your option, 1 Manual -- 2 Random -- Other number to exit" <<endl;
		cin >> num;
		switch (num) {
			case 1:
				cout << "You entered one." << endl;
				avlTreeOperations();
				break;
			case 2:
				cout << "You entered two." << endl;
				randomTest();
				break;
			default:
				cout << "You did not enter a number 1 or 2. Exiting from program" << endl;
				mybool = false;
				break;
			}
	}

	return 0;
}
