# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    manda.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 12:47:41 by mykle             #+#    #+#              #
#    Updated: 2024/12/11 13:35:56 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
define TITLE

┌────────────────────────────────────┐
│░█▀█░█░█░█▀▀░█░█░░░░░█▀▀░█░█░█▀█░█▀█│
│░█▀▀░█░█░▀▀█░█▀█░░░░░▀▀█░█▄█░█▀█░█▀▀│
│░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░░│
└────────────────────────────────────┘
	             MANDA
endef
export TITLE
text-style 		= $(shell tput $1)$2$(shell tput sgr0)
PRINT_TITLE		:= $(shell $(info $(call text-style,setaf 6, $(TITLE))))

SOURCES		:=	main.c\
				stack.c\
				stack_moves.c\
				stack_moves_extra.c\
				sorting.c\
