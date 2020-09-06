## Description
Cmpe Airlines is an airline company that aims to provide highest quality services for their customers.

Cmpe Airlines' planes have 2 lines of seats named as Line A and Line B. The lines have different sizes: the size of the first line (A) is N and the size of the second line (B) is M. This design allows everyone to have a window seat.


Every person is assigned a ticket and when the person enters the plane he/she goes to the seat on his/her ticket. 

* The seat number may exceed the size of the lines, so people sits to the place according to modulo of that line's size. Let's say the seat number is X, if the seat is in the first line (A column) he/she sits X % N, if the seat is in the second line (B column) he/she sits X % M. 


If the seat is full, he/she causes the sitting person move, and he/she sits there. The displaced person needs to find a new place, there are 3 different types of people who make a different move when they need to find a new place:

* The **first type of person** goes the other seat line and sits other seat in modulo of that line's size. (For example, if at first he/she sits X % N in the Line A, than he/she goes to X%M in the Line B).
* The **second type of person** moves to one back seat. If he/she was on final seat, he/she goes to the first seat of the **other line!**
* The **third type of person** moves to the seat back at the first time, to the seat that is 4 behind the original seat at the second time, to the seat that is 9 behind the original seat at third time, and so on... (For example if he/she sits originally at A4 and got moved 4 times, he/she sits in the seats: `A4 -> A5 -> A8 -> A13 -> A20`). If the seat number exceeds the line size he/she goes the head of the other line and continues to go back. (For example N=10 and a person sits in 8 and needs to go 7 seats back. He has to go seat 5 in the Line B, if that line does not have seat 5, eg. for M=3, he/she changes line again, and needs to sit the second seat in the Line A). 

**NOTE:** When a person goes to the new place always he/she sits that place and cause to move previous person.

## Input
The input is formatted as follows:

- First row is the sizes of the Line A and Line B, and the number of queries: *N* *M* *Q*
- The next Q rows have queries, each query describing a new person coming into plane. Formatted as two properties seperated by space:
    - First, is the **type of the incoming person**
    - Second, is the **ticket information**, described as line name (A or B) with seat number.
    - Example: `3 A12` means type 3 person coming to the Line A, seat 12.

**NOTE:** The seat number can be greater than N and M, Lets say seat number is X, when a person occured in this situation he/she goes the seat number X % N if it is in the Line A, X % M if it is in the Line B (seat number 0 equals to N).

## Output

An output consisting of **exactly** N+M rows, describing the state of the seats on the plane.
* First N rows is for **Line A**, contains the real ticket of information of the people if seat is full, and "0" if seat is empty. 
* Next M rows is for **Line B**, contains the real ticket of information of the people if seat is full, and "0" if seat is empty. 

The output is printed to a file.

## Limits
* N, M <= 1000
* Q <= N + M
* X_i (The ticket seat number) <= 100000
