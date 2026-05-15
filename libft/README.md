*This activity has been created as part of the 42 curriculum by mde-nas.*

## Description

Libft is a custom C library reimplementing a selection of standard libc functions, along with additional string utilities and linked list manipulation functions. The goal is to understand how these functions work internally and build a reusable foundation for future 42 projects.

The library is compiled as a static archive ('libft.a') and covers:

**Part 1 — Libc functions**
'ft_isalpha' 'ft_isdigit' 'ft_isalnum' 'ft_isascii' 'ft_isprint' 'ft_strlen' 'ft_memset' 'ft_bzero' 'ft_memcpy' 'ft_memmove' 'ft_strlcpy' 'ft_strlcat' 'ft_toupper' 'ft_tolower' 'ft_strchr' 'ft_strrchr' 'ft_strncmp' 'ft_memchr' 'ft_memcmp' 'ft_strnstr' 'ft_atoi' 'ft_calloc' 'ft_strdup'

**Part 2 — Additional functions**
'ft_substr' 'ft_strjoin' 'ft_strtrim' 'ft_split' 'ft_itoa' 'ft_strmapi' 'ft_striteri' 'ft_putchar_fd' 'ft_putstr_fd' 'ft_putendl_fd' 'ft_putnbr_fd'

**Part 3 — Linked list**
'ft_lstnew' 'ft_lstadd_front' 'ft_lstsize' 'ft_lstlast' 'ft_lstadd_back' 'ft_lstdelone' 'ft_lstclear' 'ft_lstiter' 'ft_lstmap'

## Instructions

bash commands
make        # compile → libft.a /
make clean  # remove object files /
make fclean # remove object files and libft.a /
make re     # rebuild from scratch /

## Resources

A lot of friends and exercices made during the piscine

**AI usage**: Claude was used to translate this README. All C files were written manually.
