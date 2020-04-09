# Intermediate Programming in C++

Here are the programs from CMPSC122 at Penn State

## Bob's "Down in Front" Aggravation Metric problem

Nothing bothers Bob more than when taller people stand up in front and block his view at sporting events. It bothers him so much, that he has developed a measure for the displeasure that a crowd feels because of this phenomenon. Most days, he calls his measure the Index of Identifiable Inversions. Although when his view is blocked by this phenomenon, he calls it the "Down In Front" Aggravation Metric.

The measure works as follows. In a line of standing people, the measure is equal to the number of people who are blocking others' views. Person A is blocking B's view, if:

* A is taller than B

* A is standing in front of B

* There is no one of equal height or taller than A in line between A and B

Assuming that everyone is standing, the line below has a "Down in Front" Aggravation Measure of 5. Bob's view is blocked by Alice, Chuck's view is blocked by Alice, Dave's view is blocked by both Chuck and Alice, and Eve's view is blocked by Alice.

### Input

Alice Bob 5'10" 5'8"

Chuck Dave Eve 5'8" 5'6" 5'8"

The input consists of an initial line with an integer n, 0 ≤ n < 10,000 on a line by itself representing the number of people standing in line. The rest of the lines give the line configuration, starting at the front of the line and going in order, in the following format:

      Name Feet Inches

### Where

* Name is a person's first name (an alphabetic string containing no spaces).

* Feet is a integer from 0 to 8, inclusive, that indicates the feet portion of a person's height.

* Inches is an integer between 0 and 11 inclusive that represents the inches portion of a person's height.

### Output

The output of the program should be a single integer representing the Index of Indentifiable Inversions of the configuration.

Sample Input:

5

Alice 5 10

Bob 5 8

Chuck 5 8

Dave 5 6

Eve 5 8

Sample Output:

5

----------------------------------------------

Here is the algorithm for this problem: 

```C++
if(n > 0 && n <= 10000){
    while(i < n - 1){
        for(int j = i + 1; j < n; j++){
            //larger but not last spot comparison
            if (*list[i] > *list[j] && j != n - 1){
                count++;
            }
            //last spot comparison
            else if(*list[i] > *list[j] && j == n - 1){
                count++;
                j = i + 1;
                i++;
            }
            //next first comparison slot
            else{
                j = i + 1;
                i++;
            }
        }
    }
}
```
