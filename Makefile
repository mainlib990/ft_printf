NAME		:=	libftprintf.a

CC			?=	cc
CFLAGS		:=	-Wall -Wextra -Werror
AR			?=	ar
ARFLAGS		:=	cr

SRCS		:=	buffer_writer.c					\
				buffer_writer_method_1.c		\
				buffer_writer_method_2.c		\
				buffer_writer_method_3.c		\
				ft_printf.c						\
				printer.c						\
				printer_method.c				\
				scanner.c						\
				scanner_command_1.c				\
				scanner_command_2.c				\
				scanner_command_3.c				\
				scanner_command_4.c				\
				scanner_method.c				\
				styles.c						\
				styles_method_1.c				\
				styles_method_2.c				\
				styles_method_3.c				\
				token_buffer_writer_1.c			\
				token_buffer_writer_2.c			\
				token_buffer_writer_3.c			\
				token_buffer_writer_method.c
OBJS		:=	$(SRCS:.c=.o)

.PHONY: mandatory bonus all clean fclean re

mandatory: $(NAME)($(OBJS)) ;

bonus: $(NAME)($(OBJS)) ;

$(NAME): mandatory ;

all: $(NAME) ;

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all ;
