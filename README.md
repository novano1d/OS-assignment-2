# Assignment 2
By Matthew Moore

## Enviroment
I wrote this code in C++ using Visual Studio Code and compiled it using Clang.

## Execution
To prepare the program for execution, it must first be compiled. This can be done by running the command `clang++ bankers.cpp -o bankers` in the terminal. After compilation, a single output file named `bankers` will be generated, which can be executed by typing `./bankers` in the terminal.

## Data Table
The dated provided to us:
| Process | Allocation | Max | Available |
| --- | --- | --- | --- |
| P0 | 0 1 0 | 7 5 3 | 3 3 2 |
| P1 | 2 0 0 | 3 2 2 | |
| P2 | 3 0 2 | 9 0 2 | |
| P3 | 2 1 1 | 2 2 2 | |
| P4 | 0 0 2 | 4 3 3 | |

In my input.txt, I converted the table to a format using spaces as seperating characters.
The input.txt file is shown below:
```
0 1 0 7 5 3 3 3 2
2 0 0 3 2 2
3 0 2 9 0 2
2 1 1 2 2 2
0 0 2 4 3 3
```

## Output
```code
Allocated: 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
Max: 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
Available: 3 3 2
The system is in safe state. Safe sequence is: 1 3 4 0 2
```

## Explaination
To fulfill the project's requirements, I utilized for loops and the extraction operator in C++ to read input from a file. The program consists of a single function (other than main), called checkSafe, which is an implementation of Banker's Algorithm in C++.

The checkSafe function first generates a need table by subtracting the allocation table from the max table using a loop. It then initializes a finish table to keep track of which processes have finished. Next, a copy of the available resources table is created, and the function enters a while loop.

During each iteration of the while loop, the function checks if the current process has already finished. If not, it verifies that all the resources needed for the current process are available. If the available resources are sufficient for the process and we have reached the end of the resource counter, a safe sequence is obtained. Otherwise, the program exits the loop, indicating that no safe sequence exists.

## Problems and Lessons Learned
While writing the code for this assignment, I did not encounter significant difficulties as there are numerous helpful resources available online to aid in implementing the Banker's algorithm in C++. However, I faced challenges in designing a method to read data from a table stored in a text file, which consumed a majority of my time during the project development phase.

During the coding process, I gained a valuable lesson in using for-loops and while-loops in C++. I made errors in flipping some variables in 2D arrays, leading to several issues that took considerable debugging time to fix. Despite these challenges, I eventually developed a functioning program. However, I spent more time than necessary on debugging, which could have been avoided with proper attention to detail during the initial coding phase.