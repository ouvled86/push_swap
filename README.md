<div align="center">

# 🔄 push_swap

**Sorting integers with a limited set of stack operations in the fewest moves possible**

[![42 School](https://img.shields.io/badge/42-School_Project-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norm-OK-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)

> *An algorithmic challenge: sort a stack of integers using two stacks and a restricted instruction set, optimized for the minimum number of operations.*

</div>

---

## ✨ Features

| Feature | Description |
|---|---|
| 🧠 **Turk Algorithm** | Cost-optimized sorting strategy that finds the cheapest move at each step |
| 📊 **Dual Stack** | Uses two stacks (A and B) with push, swap, and rotate operations |
| ⚡ **Optimized Cases** | Dedicated algorithms for 2 and 3 elements |
| ✅ **Checker (Bonus)** | Verifies sorting correctness by replaying operations |
| 🔧 **Custom libft** | Built on a personal C library with ft_printf & get_next_line |

---

## 🧠 The Turk Algorithm

The sorting strategy uses a **cost-based optimization** approach:

```
┌─────────────┐     ┌─────────────┐
│   Stack A   │     │   Stack B   │
│ ┌─────────┐ │     │ ┌─────────┐ │
│ │    5    │ │ ──► │ │         │ │  1. Push elements from A to B
│ │    3    │ │     │ │         │ │     (keeping 3 in A)
│ │    1    │ │     │ │         │ │
│ │    4    │ │     │ │         │ │  2. Sort the remaining 3 in A
│ │    2    │ │     │ │         │ │
│ └─────────┘ │     │ └─────────┘ │  3. Push back from B to A
└─────────────┘     └─────────────┘     using cost optimization
```

### How it works:

1. **Index & Position** — Each node gets a position index relative to the median
2. **Target Finding** — For each element, find its optimal target in the other stack
3. **Cost Calculation** — Compute the total cost to move an element and its target to the top (considering both `ra`/`rb` and `rra`/`rrb` combinations)
4. **Cheapest Selection** — Execute the move with the lowest total cost
5. **Final Rotation** — Rotate A to place the minimum value at the top

---

## 📋 Operations Reference

| Operation | Description |
|:---------:|---|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of B onto A |
| `pb` | Push the top of A onto B |
| `ra` | Rotate A — shift all elements up by 1 |
| `rb` | Rotate B — shift all elements up by 1 |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A — shift all elements down by 1 |
| `rrb` | Reverse rotate B — shift all elements down by 1 |
| `rrr` | `rra` and `rrb` simultaneously |

---

## 🏗️ Build & Run

### Compile

```bash
git clone https://github.com/ouvled86/push_swap.git
cd push_swap
make
```

### Usage

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l

# Verify with the checker (bonus)
make bonus
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

### Error Handling

The program handles:
- Non-integer arguments
- Duplicate values
- Integer overflow/underflow
- Empty input

---

## 📁 Project Structure

```
push_swap/
├── Makefile
├── mandatory/
│   ├── includes/
│   │   └── push_swap.h          # Main header with structs & prototypes
│   ├── libft/                   # Custom C library (libft + ft_printf + GNL)
│   └── srcs/
│       ├── main.c               # Entry point & argument handling
│       ├── parssing.c           # Input parsing & validation
│       ├── init_stack.c         # Stack initialization
│       ├── sort_stack.c         # Main sorting algorithm
│       ├── sort_three.c         # Optimized sort for 3 elements
│       ├── set_target.c         # Target node assignment
│       ├── set_cheapest.c       # Cheapest move selection
│       ├── set_index.c          # Position indexing
│       ├── calc_cost.c          # Move cost calculation
│       ├── push.c               # pa, pb operations
│       ├── swap.c               # sa, sb, ss operations
│       ├── rotate.c             # ra, rb, rr operations
│       ├── reverse_rotate.c     # rra, rrb, rrr operations
│       └── utils.c              # Utility functions
└── bonus/
    ├── includes/
    │   └── push_swap_bonus.h
    ├── libft/
    └── srcs/
        ├── checker.c            # Operation reader & validator
        └── ...                  # Bonus operation implementations
```

---

## 📝 Makefile Targets

| Command | Description |
|---|---|
| `make` | Compile push_swap |
| `make bonus` | Compile the checker program |
| `make clean` | Remove object files |
| `make fclean` | Remove objects + binaries |
| `make re` | Full recompile |

---

<div align="center">

Made with 🧠 at **[1337 School](https://1337.ma)** (42 Network)

</div>
