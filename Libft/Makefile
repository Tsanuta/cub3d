# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: olidon <olidon@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/10 14:51:46 by olidon       #+#   ##    ##    #+#        #
#    Updated: 2020/02/04 10:44:17 by olidon      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c \
get_next_line.c \
get_next_line_utils.c \
ft_atoi_base.c \
ft_atou_base.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strrncmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_itoa_base.c \
ft_utoa_base.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

SRCSBNUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

INCL = libft.h

OBJS = $(SRCS:.c=.o)

OBJSBNUS = $(SRCSBNUS:.c=.o)

FLAGS += -Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c $(INCL)
			gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus:		$(OBJSBNUS) $(OBJS)
			ar rc $(NAME) $(OBJS) $(OBJSBNUS)

clean:
			rm -f $(OBJS) $(OBJSBNUS)

fclean: 	clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re