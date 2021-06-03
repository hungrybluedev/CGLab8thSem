# Assignment 01

## Pseudocode

```
input_str := input('Enter the height : ')
n := input_str.int()

if n < 3 {
  println('Height must be at least 3')
  return
}

for row in 0 .. n {
  if row == 0 || row == n - 1 {
    print('N')
    for col in 1 .. n - 1 {
      print(' ')
    }
    print('N')
  } else {
    print('N')
    for col in 1 .. row {
      print(' ')
    }
    print('N')
    for col in 2 .. n - row {
      print(' ')
    }
    print('N')
  }
  println('')
}
```

## Description

1. First, we obtain the height of the Big N as an input from the user.
2. We ensure that the height is at least 3.
3. We iterate over the rows from 0 (inclusive) to n (exclusive).
4. If we are at the top or bottom row, that is, when value of row is 0 or n - 1, we print an N, followed by an appropriate amount of space, then another N.
5. If we are in one of the middle rows, first we print N, then 'row - 1' spaces, then another N, then 'n - 2 - row' spaces, then a final N.
6. We print a newline to get to the next output row.

## Test Cases

```
Enter the height : 5
N   N
NN  N
N N N
N  NN
N   N

Enter the height : 10
N        N
NN       N
N N      N
N  N     N
N   N    N
N    N   N
N     N  N
N      N N
N       NN
N        N

Enter the height : 15
N             N
NN            N
N N           N
N  N          N
N   N         N
N    N        N
N     N       N
N      N      N
N       N     N
N        N    N
N         N   N
N          N  N
N           N N
N            NN
N             N

Enter the height : 20
N                  N
NN                 N
N N                N
N  N               N
N   N              N
N    N             N
N     N            N
N      N           N
N       N          N
N        N         N
N         N        N
N          N       N
N           N      N
N            N     N
N             N    N
N              N   N
N               N  N
N                N N
N                 NN
N                  N
```
