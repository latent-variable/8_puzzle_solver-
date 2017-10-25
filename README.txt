Project: 1	 CS 205. Introduction to Artificial Intelligence
Due Date: Friday November 3rd
The Eight Puzzle 

For this project I want you to write a program that solves the eight-puzzle. You will solve it using 

1)	Uniform Cost Search 
2)	A* with the Misplaced Tile heuristic.
3)	A* with the Manhattan Distance heuristic.

You may use any language, but the variable and function names for main “driver” program should approximately match the peusdocode in the book. If you have a good reason to ignore this directive, let me know in advance.


The general search algorithm.

I expect the code to be meaningfully commented, nicely indented etc. This is not a software engineering class, but if I cannot clearly review and understand your code. I will strongly lean towards a lower grade.

The code should be kept general as possible. In other words, your code should require only a modicum of effort to change to solve the 15-puzzle, or the 25-puzzle etc. 

You can hardcode an initial state for testing purposes. But I want to be able to enter an arbitrary initial state. So sometime along the lines of the interface on the next page would be nice.
 
You may use some predefined utility routines, for example sorting routines or queue manipulation functions. However, I expect all the major code to be original. You must document any book, webpage, person or other resources you consult in doing this project (see the first day’s handout).  

You may consult colleagues at a high level, discussing ways to implement the tree data structure for example. But you may not share code.  At most, you might illustrate something to a colleague with pseudocode.

You will hand in 
1)	A coversheet.
2)	A printout of your code. 
(just the first and last page, don’t kill trees)
A trace of the Manhattan distance A* on the following problem. (just the first and last page, don’t kill trees)
3)	A two to five-page report which summaries your findings. You might want to compare the algorithms on several random puzzles, summarize the results with graphs and make comments on the utility of the different heuristics etc. The only meaningful comparisons for the algorithms are time (number of nodes expanded) and space (the maximum size of the queue).

You must keep the evolving versions of your code, so that, if necessary you can demonstrate to the course staff how you went about solving this problem (in other words, we may ask you to prove that you did the work, rather than copy it from somewhere).
In addition, I will randomly select ten students to demonstrate their program to me, in my office.

You can use a simple text line interface or a more sophisticated GUI (but don’t waste time making it pretty unless you are sure it works and you have lots free time). However your program should generate a trace like the one below, so that it can be tested. 
