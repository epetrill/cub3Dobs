# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epetrill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 20:38:23 by epetrill          #+#    #+#              #
#    Updated: 2020/02/25 12:53:34 by epetrill         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= cub
PRF		= printf
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
OBJDIR	= objs
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR)
SRCS	= $(addprefix $(SRCDIR)/, cub.c get_next_line.c get_next_line_utils.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
HDRS	= $(addprefix $(INCDIR)/, cub.h get_next_line.h)

all				:	printf $(NAME)

$(PRF)		:
		make -C $(PRF)

$(PRF)/libftprintf.a:	printf

$(NAME)			:	$(PRF)/libftprintf.a $(OBJDIR) $(OBJS)
		cp $(PRF)/libftprintf.a libftprintf.a
		$(CC) -g -o $@ $(OBJS) libftprintf.a
		rm libftprintf.a

$(OBJDIR)		:
		mkdir -p $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HDRS)
		$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean			:
		make clean -C $(PRF)
		/bin/rm -rf $(OBJDIR)

fclean			:	clean
		make fclean -C $(PRF)
		/bin/rm -f $(NAME)

re				:	fclean all


.PHONY			: libft
