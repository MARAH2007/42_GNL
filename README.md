*This project has been created as part of the 42 curriculum by mnazzal.*

# get_next_line
## Description

The **get_next_line** project consists of implementing a function that reads a file descriptor one line at a time.

The function returns a line ending with `\n` when a newline is present. When there is nothing left to read, it returns `NULL`.

This project introduces file descriptors, the `read()` function, static variables, dynamic memory allocation, and memory management in C.

## Instructions

### Compilation

Compile the project using the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

To test the project, compile it with your own `main.c`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

### Execution

Run the generated executable:

```bash
./a.out
```

### Testing Different Buffer Sizes

You can change `BUFFER_SIZE` to test different reading sizes.

For example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
./a.out
```

You should test the function with:
- Empty files.
- Files containing multiple lines.
- Lines ending with `\n`.
- A final line without a newline.
- Different buffer sizes, such as `1`, `42`, and `9999`.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Files

- `get_next_line.c` — Contains the main `get_next_line()` function and reading logic.
- `get_next_line_utils.c` — Contains helper functions for string manipulation and saving data.
- `get_next_line.h` — Contains the required headers, macros, and function prototypes.

## Allowed Functions

The mandatory part allows the following external functions:

- `read()`
- `malloc()`
- `free()`

## Concepts Learned

- File descriptors.
- Reading files using `read()`.
- Static variables and persistent storage.
- Dynamic memory allocation.
- String manipulation.
- Memory management.
- Handling different buffer sizes and end-of-file conditions.

## Resources

- [42 School](https://42.fr/)
- [read() — Linux manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() — Linux manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [free() — Linux manual](https://man7.org/linux/man-pages/man3/free.3.html)

## AI Usage

AI tools were used as learning and debugging assistants to help understand C programming concepts, memory management, static variables, file reading, and project requirements. The author is responsible for reviewing and understanding the submitted implementation.

## License

This project is part of the 42 curriculum and is intended for educational purposes.

