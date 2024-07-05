CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = libft/libft.a

SRCS = moves.c push_swap.c moves2.c utils.c utils2.c utils3.c solve.c case.c exit.c parser.c

HEADERS = push_swap.h

OBJS = $(SRCS:.c=.o)

TARGET = push_swap
 
SUBDIRS =  libft

$(TARGET): $(OBJS)
	$(MAKE) -C libft;\
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: clean_subdirs
	rm -f $(OBJS)

fclean: fclean_subdirs clean
	rm -f $(TARGET)

clean_subdirs:
	for dir in $(SUBDIRS); do\
			$(MAKE) -C $$dir clean;\
			done

fclean_subdirs:
	for dir in $(SUBDIRS); do\
			$(MAKE) -C $$dir fclean;\
			done

re: fclean all

all: $(TARGET)

.PHONY: all clean fclean re clean_subdirs fclean_subdirs
