# Libft

## Table of Contents
- [Introduction](#introduction)
- [Contents](#contents)
- [Compilation](#compilation)
- [Usage](#usage)
- [Testing](#testing)
- [Example Usage](#example-usage)

## Introduction
**Libft** is my personal implementation of some of the Standard C Library functions, along with additional utilities that I found necessary during my studies at 42. This project is intended to help me get a deeper understanding of data structures and basic algorithms by recreating fundamental C functions.

## Contents
Libft is organized into several functional categories, each containing specific types of operations and utilities:

- **btree**: *(No specific functions listed yet)*
- **ctype**: Functions related to character classification and conversion (e.g., `ft_isalpha`, `ft_toupper`).
- **deque**: Functions for handling double-ended queues (e.g., `deque_push_right`, `deque_pop_left`).
- **garbage_collector**: Functions for memory management and custom allocation (e.g., `ft_malloc`).
- **hashtable**: Functions for creating and managing hash tables.
- **list**: Functions for linked list manipulation and operations (e.g., `ft_lstnew`, `ft_lstadd_front`).
- **math**: *(No specific functions listed yet)*
- **stdio**: Functions related to input/output operations, including a custom `printf` implementation.
- **stdlib**: Standard library functions such as memory and string manipulation (e.g., `ft_memset`, `ft_strdup`).
- **string**: Functions that deal with string operations and manipulations (e.g., `ft_strtrim`, `ft_strjoin`).

This organization helps in navigating the library and understanding the available functionalities that enhance standard C capabilities or provide additional useful tools.

### Function Categories

| Category           | Functions                                                 |
|--------------------|-----------------------------------------------------------|
| **btree**          | *(No specific files listed)*                              |
| **ctype**          | `ft_isalnum.c`, `ft_isalpha.c`, `ft_isascii.c`, `ft_isdigit.c`, `ft_isprint.c`, `ft_isspace.c`, `ft_tolower.c`, `ft_toupper.c` |
| **deque**          | `deque_init.c`, `deque_iter.c`, `deque_node_init.c`, `deque_pop_left.c`, `deque_pop_right.c`, `deque_print.c`, `deque_push_node_left.c`, `deque_push_node_right.c`, `deque_rotate.c`, `deque_sort.c`, `deque_swap.c`, `deque_to_arr.c` |
| **garbage_collector** | `ft_malloc.c`                                            |
| **hashtable**      | `hash.c`, `hashtable.c`                                   |
| **list**           | `ft_lstadd_back.c`, `ft_lstadd_front.c`, `ft_lstclear.c`, `ft_lstdelone.c`, `ft_lstiter.c`, `ft_lstlast.c`, `ft_lstmap.c`, `ft_lstnew.c`, `ft_lstsize.c` |
| **math**           | *(No specific files listed)*                              |
| **stdio**          | `ft_printf`, `ft_putchar_fd.c`, `ft_putendl_fd.c`, `ft_putnbr_base.c`, `ft_putnbr_fd.c`, `ft_putstr_fd.c`, `get_next_line.c`, `get_next_line_utils.c` |
| **stdio/ft_printf** | `ft_printf.c`, `print_c.c`, `print_i_d.c`, `print_number.c`, `print_p.c`, `print_s.c`, `print_u.c`, `print_utils.c`, `print_x.c` |
| **stdlib**         | `free_matrix.c`, `ft_atoi.c`, `ft_atoll.c`, `ft_bzero.c`, `ft_calloc.c`, `ft_memchr.c`, `ft_memcmp.c`, `ft_memcpy.c`, `ft_memmove.c`, `ft_memset.c` |
| **string**         | `ft_split.c`, `ft_strchr.c`, `ft_strdup.c`, `ft_striteri.c`, `ft_strjoin.c`, `ft_strlcat.c`, `ft_strlcpy.c`, `ft_strlen.c`, `ft_strmapi.c`, `ft_strncmp.c`, `ft_strndup.c`, `ft_strnstr.c`, `ft_strrchr.c`, `ft_strtrim.c`, `ft_substr.c` |

## Compilation
`libft.a` is the library file compiled from the source. To compile it, clone the repo and run make:

```bash
git clone https://github.com/your-username/libft.git
cd libft
make
```

This will compile all the functions into a single library file `libft.a`.

## Usage
To use `libft` in your project:

1. Include it in your C file:
   ```c
   #include "libft.h"
   ```
2. When compiling your project, link against `libft`:
   ```bash
   gcc -L. -lft your_c_file.c
   ```

## Testing
For testing the library, you can use the [Francinette](https://github.com/xicodomingues/francinette.git) or any other tester available.

## Example Usage
Here is an example of using some of the libft functions:
```c
#include "libft.h"

int main()
{
    ft_putstr("Hello, 42!");
    return (0);
}
```

This will print `Hello, 42!` using the `ft_putstr` function defined in libft.
