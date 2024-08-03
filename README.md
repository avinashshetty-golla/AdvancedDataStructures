													AdvancedDataStructures 8380 Persistence BST with AVL Project Work
													-----------------------------------------------------------------

Configuration:
-----------------------
IDE: Eclipse 2024 IDE.
Compiler: mingw64 C++ compiler.

STEPS TO RUN THE PROGRAM
------------------------

1. Import Project to Eclipse IDE:
		Open Eclipse IDE.
		Go to "File" > "Import".
		Choose "Existing Projects into Workspace" under the "General" category.
		Click "Next".
		Select the root directory of your project.
		Click "Finish" to import the project.
2. Clean the Project:
		In the Package Explorer pane, right-click on the project.
		Select "Clean Project".
		This will remove any existing build artifacts and prepare the project for a fresh build.
3. Build the Project:
		After cleaning the project, right-click on the project again.
		Select "Build Project".
		This will compile the source code and generate the executable file.
4. Run as C++ Application:
		Once the project is built successfully, right-click on the project.
		Choose "Run As" > "C/C++ Application".
		Select the appropriate executable file to run.
		Click "OK" to run the application.
5. Post-Execution Options:
		After successful execution, the program should display certain options.
			Enter 1 to test with manual data
			Enter 2 to test with Random data
			Enter your option, 1 Manual -- 2 Random -- Other number to exit.
			
		Follow the on-screen instructions or menu to interact with the program as intended.
		
NOTE : 
	Manual Data Entry: You manually input the value for each node.
	Random Data Entry: You specify the size of elements, and the nodes are automatically inserted based on the given size. 
	For example, if you enter a size of 100, then 100 elements will be inserted automatically.

Manual Data Entry:
1. Lets choose option 1 to test manual data entry
	Now, you get below prompt :
	
	You entered one.
	Choose an Option:
	1: Insert
	2: Delete
	3: Display
	0: Exit Program
	Enter option

2. Let's choose 1 to insert elements.
	Now you get prompt like below :
	How many elements you want to enter

3. For example, if I want to insert 3 elements, enter option as 3

4. It will ask to " enter 0 value - means first value" after entering 0 value, it will ask for "enter 1 value" and "enter 2 value"

5. After entering 3 values, it will again ask for below options :
	Choose an Option:
	1: Insert
	2: Delete
	3: Display
	0: Exit Program
	Enter option

6. Lets say, I want to display the tree with nodes of Left Height and Right Height, I will select "Option 3 : Display"
	It will give output like below :
	InOderTraversal
	2 (LH: 0, RH: 0)
	4 (LH: 1, RH: 1)
	6 (LH: 0, RH: 0)

7. Again it will ask below options :
	Choose an Option:
	1: Insert
	2: Delete
	3: Display
	0: Exit Program
	Enter option

8. Let's say I want to delete an element, now i choose "2 : Delete" and you get below prompt :
	"Enter the element that you would like to remove"
	I entered 6 and you can see below prompt after deleting the element :
	
	InOderTraversal
	2 (LH: 0, RH: 0)
	4 (LH: 1, RH: 0)

9. After showing the above result, it will again ask for below options to choose :
	Choose an Option:
	1: Insert
	2: Delete
	3: Display
	0: Exit Program
	Enter option

10. Choose 0 to exit.

------------------------------------------------------------------------
Random Data Entry:

1. Enter your option, 1 Manual -- 2 Random -- Other number to exit
Lets choose option 2 :

2. You can see below prompt :

	You entered two.
	Choose an Option:
	1: Insert
	2: Delete
	3: InorderTraversal
	4: Exit Program
	Enter option

3. I entered "1: Insert"
	It will ask "How many elements you want to insert"

4. I entered "5000" and you can see below message :
	5000 insert operations 0 milli seconds and you can also see below prompt :

	Choose an Option:
	Enter 1 for InorderTraversal to display the elements
	Enter 2 for deleting all the elements
	Enter 3 for Exit

5. I choosed "1 : InOderTraversal to display elements" and you can see similar output like below :
	1200 (LH: 4, RH: 4)
	1201 (LH: 0, RH: 0)
	1202 (LH: 1, RH: 1)
	1203 (LH: 0, RH: 0)
	1204 (LH: 2, RH: 2)
	1205 (LH: 0, RH: 0)
	1206 (LH: 1, RH: 1)
	1207 (LH: 0, RH: 0)
	1208 (LH: 3, RH: 3)
	1209 (LH: 0, RH: 0)
	1210 (LH: 1, RH: 1)
	1211 (LH: 0, RH: 0)
	1212 (LH: 2, RH: 2)
	1213 (LH: 0, RH: 0)
	1214 (LH: 1, RH: 1)
	1215 (LH: 0, RH: 0)
	1216 (LH: 6, RH: 6)
	1217 (LH: 0, RH: 0)
	1218 (LH: 1, RH: 1)
	1219 (LH: 0, RH: 0)
	1220 (LH: 2, RH: 2)
	1221 (LH: 0, RH: 0)
	.......
	..........
	Inorder traversal completed in 0 milli seconds
	
	Choose an Option:
	Enter 1 for InorderTraversal to display the elements
	Enter 2 for deleting all the elements
	Enter 3 for Exit

6. Now I choosed "2 : Deleting all elements" and we can see below prompt :
	You entered two.
	Deleting all the elements in the tree

	Deleting elements in 0 milli seconds

	Choose an Option:
	Enter 1 for InorderTraversal to display the elements
	Enter 2 for deleting all the elements
	Enter 3 for Exit

7. Now I choosed "3 for Exit" and You can see below options 
	Choose an Option:
	1: Insert
	2: Delete
	3: InorderTraversal
	4: Exit Program
	Enter option

8. Now I choosed "4 : Exit Program" and it will show below message 
	Enter your option, 1 Manual -- 2 Random -- Other number to exit

9. I enterd number other than 1 or 2 and program got EXIT.


																	PERFORMANCE TESTING RESULTS
																	---------------------------
In a balanced binary search tree, the time complexity of insertion is usually O(log n), where n is the number of nodes in the tree.
Therefore, the time complexity of inserting 1 lakh records into a balanced BST is approximately O(log n), where n is the number of records. And in this case, with 1 lakh records and 15 milliseconds of insertion time, it's approximately O(log n), where log is base 2 and n is around 100,000.

RANDOM INSERTION FOR 1LAKH RECORDS
-----------------------------------
Enter 1 to test with manual data
Enter 2 to test with Random data

Enter your option, 1 Manual -- 2 Random -- Other number to exit
2
You entered two.
Choose an Option:
1: Insert
2: Delete
3: InorderTraversal
4: Exit Program
Enter option
1
You entered one.
How many elements you want to insert
100000
100000 insert operations 15 milli seconds

Choose an Option:
Enter 1 for InorderTraversal to display the elements
Enter 2 for deleting all the elements
Enter 3 for Exit

..............
..............
..............
95526 (LH: 1, RH: 1)
95527 (LH: 0, RH: 0)
95528 (LH: 3, RH: 3)
95529 (LH: 0, RH: 0)
95530 (LH: 1, RH: 1)
95531 (LH: 0, RH: 0)
95532 (LH: 2, RH: 2)
..............
..............
..............
95533 (LH: 0, RH: 0)
95534 (LH: 1, RH: 1)
95535 (LH: 0, RH: 0)
95536 (LH: 4, RH: 4)
95537 (LH: 0, RH: 0)
95538 (LH: 1, RH: 1)
95539 (LH: 0, RH: 0)
95540 (LH: 2, RH: 2)
95541 (LH: 0, RH: 0)
99990 (LH: 1, RH: 1)
99991 (LH: 0, RH: 0)
99992 (LH: 3, RH: 4)
99993 (LH: 0, RH: 0)
99996 (LH: 2, RH: 3)
99997 (LH: 0, RH: 0)
99998 (LH: 1, RH: 2)
99999 (LH: 0, RH: 1)
100000 (LH: 0, RH: 0)

Inorder traversal completed in 78 milli seconds

Choose an Option:
Enter 1 for InorderTraversal to display the elements
Enter 2 for deleting all the elements
Enter 3 for Exit

2
You entered two.
Deleting all the elements in the tree

Deleting elements in 93 milli seconds


RANDOM INSERTION FOR 10LAKHS RECORDS
-----------------------------------

the time complexity of inserting 10 lakh records into a balanced BST is approximately O(log n), where log is base 2 and n is around 1,000,000. With 156 milliseconds of insertion time for 10 lakh records, the time complexity aligns with the expected O(log n) behavior.

Enter 1 to test with manual data
Enter 2 to test with Random data

Enter your option, 1 Manual -- 2 Random -- Other number to exit
2
You entered two.
Choose an Option:
1: Insert
2: Delete
3: InorderTraversal
4: Exit Program
Enter option
1
You entered one.
How many elements you want to insert
1000000
1000000 insert operations 156 milli seconds

Choose an Option:
Enter 1 for InorderTraversal to display the elements
Enter 2 for deleting all the elements
Enter 3 for Exit
2
You entered two.
Deleting all the elements in the tree

Deleting elements in 171 milli seconds

SUMMARY
-------
Based on the above tests scenario it demonstrates the runtime performance of the tree that we expect when input size is scaled up and the time complexity aligns with 
the expected O(log n) behavior.
