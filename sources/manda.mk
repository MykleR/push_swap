# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    manda.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 12:47:41 by mykle             #+#    #+#              #
#    Updated: 2024/12/13 15:01:31 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
define TITLE

┌────────────────────────────────────┐
│░█▀█░█░█░█▀▀░█░█░░░░░█▀▀░█░█░█▀█░█▀█│
│░█▀▀░█░█░▀▀█░█▀█░░░░░▀▀█░█▄█░█▀█░█▀▀│
│░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░░│
└────────────────────────────────────┘

endef
export TITLE
text-style 		= $(shell tput $1)$2$(shell tput sgr0)
PRINT_TITLE		:= $(shell $(info $(call text-style,setaf 6, $(TITLE))))

SOURCES		:=	manda/main.c\
				stack/stack.c\
				stack/stack_parse.c\
				instructions/instructions.c\
				instructions/instructions_2.c\
				manda/sorting.c\
				manda/moves.c\
				manda/costs.c\
