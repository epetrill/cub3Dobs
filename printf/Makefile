# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epetrill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 20:38:23 by epetrill          #+#    #+#              #
#    Updated: 2020/02/16 13:54:53 by epetrill         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
OBJDIR	= objs
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)
SRCS	= $(addprefix $(SRCDIR)/, ft_printf.c ft_distrib.c ft_affich.c ft_printfutils.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
HDRS	= $(INCDIR)/ft_printf.h

all				:	libft $(NAME)

libft			:
		make -C $(LIBFT)

$(LIBFT)/libft.a:	libft

$(NAME)			:	$(LIBFT)/libft.a $(OBJDIR) $(OBJS)
		cp $(LIBFT)/libft.a $(NAME)
		ar rcus $@ $(OBJS)

$(OBJDIR)		:
		mkdir -p $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HDRS)
		$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean			:
		make clean -C $(LIBFT)
		/bin/rm -rf $(OBJDIR)

fclean			:	clean
		make fclean -C $(LIBFT)
		/bin/rm -f $(NAME)

re				:	fclean all


.PHONY			: libft
