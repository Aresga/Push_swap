Collecting workspace information

Here's a 

README.md

 for your Push Swap project:

```markdown
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

Input Size | Average Operations	| Maximum Operations | Target
100					~600				646				≤ 700
500					~4,052				4,330			≤ 5,500


- Time complexity of O(nlogn)



## Testing

The project includes test scripts in the 

Tester

 directory:
```bash
./Tester/testmac.sh  # For testing on macOS
./Tester/checkleaks.sh  # For checking memory leaks
```

## Project Structure

```
.
├── includes/
│   └── push_swap.h    # Main header file
├── libft/             # Custom C library
├── srcs/
│   ├── algorithm/     # Sorting algorithm implementation
│   ├── checker/       # Input validation
│   ├── error/        # Error handling
│   ├── list/         # Linked list operations
│   ├── operations/   # Stack operations
│   └── main.c        # Entry point
└── Tester/           # Testing scripts
```

## Contributing

Feel free to submit issues and enhancement requests.

## License

This project is licensed under the terms described in the project license files.

## Author

Abderrahman Gaga- agaga@student.hive.fi
```