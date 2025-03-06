# Push Swap

A C program that sorts a stack of numbers using two stacks and a limited set of operations, implementing an optimized sorting algorithm.

## Overview

Push Swap is a sorting algorithm that uses two stacks (A and B) and a predefined set of operations to sort numbers. The goal is to sort stack A in ascending order using the minimum number of operations possible.

## Features

- Efficient sorting algorithm using two stacks
- Dynamic chunk-based sorting strategy
- Optimized rotation operations
- Memory leak-free implementation
- Comprehensive error handling

## Installation

```bash
git clone <repository-url>
cd push_swap
make
```

## Usage

```bash
./push_swap [numbers]
```

Example:
```bash
./push_swap 5 2 9 1 8
```

## Available Operations

- `pa`: Push top element from stack B to stack A
- `pb`: Push top element from stack A to stack B
- `sa`: Swap top two elements of stack A
- `sb`: Swap top two elements of stack B
- `ss`: `sa` and `sb` simultaneously
- `ra`: Rotate stack A (first element becomes last)
- `rb`: Rotate stack B
- `rr`: `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack A (last element becomes first)
- `rrb`: Reverse rotate stack B
- `rrr`: `rra` and `rrb` simultaneously

## Algorithm

The sorting process consists of several steps:

1. **Initial Push to B**: Numbers are pushed to stack B in chunks, with partial sorting during the push process
2. **Rotation Optimization**: For each number being pushed back to A:
   - Calculate costs for different rotation combinations
   - Choose the most efficient rotation strategy
   - Execute the optimal sequence of moves

## Performance

| Input Size | Average Operations | Maximum Operations | Target |
|---|---|---|---|
| 100 | ~600 | 646 | ≤ 700 |
| 500 | ~4,052 | 4,330 | ≤ 5,500 |


## Time Complexity

The Push Swap algorithm achieves a time complexity of O(n log n), which is characteristic of efficient sorting algorithms. This is supported by the observed scaling of operations with input size:

For 100 elements, the average is approximately 600 operations.
For 500 elements, the average rises to around 4,052 operations.

The operation count aligns with the model operations ≈ n⋅log2(n), confirming the O(n log n) complexity with optimizations that reduce constant factors.


## Testing

[Tester for Mac](https://github.com/Aresga/Push_swap-Tester/blob/main/testmac.sh)  
[Tester for Linux](https://github.com/Aresga/Push_swap-Tester/blob/main/testlinux.sh)  

You must have checker_linux Or checker_mac in the same directory a long with push_swap executable ! 


## Project Structure

```
.
├── includes/
│   └── push_swap.h    # Main header file
├── libft/             # Custom C library
├── srcs/
│   ├── algorithm/     # Sorting algorithm implementation
│   ├── checker/       # Input validation
│   ├── error/         # Error handling
│   ├── list/          # Linked list operations
│   ├── operations/    # Stack operations
│   └── main.c         # Entry point
```

## Contributing

Feel free to submit issues and enhancement requests.

## License

UNLICENCED

## Author

Abderrahman Gaga- agaga@student.hive.fi
