# Push Swap

## Overview

The `push_swap` project is a sorting algorithm challenge that involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack with the minimum number of moves.

## Operations

The allowed operations are:

- `sa`: Swap the first two elements at the top of stack `a`.
- `sb`: Swap the first two elements at the top of stack `b`.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Push the top element of stack `b` onto stack `a`.
- `pb`: Push the top element of stack `a` onto stack `b`.
- `ra`: Rotate stack `a` upwards (the first element becomes the last one).
- `rb`: Rotate stack `b` upwards (the first element becomes the last one).
- `rr`: `ra` and `rb` at the same time.
- `rra`: Reverse rotate stack `a` (the last element becomes the first one).
- `rrb`: Reverse rotate stack `b` (the last element becomes the first one).
- `rrr`: `rra` and `rrb` at the same time.

## Usage

To compile the project, run:

```sh
make
```

To execute the program, use:

```sh
./push_swap [list of integers]
```

Example:
```sh
./push_swap 3 2 5 1 4
```

You can use `wc -l` to see how many operations did the program used.

```sh
./push_swap 3 2 5 1 4 | wc -l
```

## Testing

You can test the program using the provided checker program to verify the correctness of the sorting operations.

```sh
./push_swap [list of integers] | ./checker_OS [list of integers]
```

Example:

```sh
./push_swap 3 2 5 1 4 | ./checker_OS 3 2 5 1 4
```
