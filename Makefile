# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2024/12/13 14:57:38 by mrouves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include sources/manda.mk
include sources/bonus.mk
NAME 			:= push_swap
NAME_BONUS		:= checker

DIR_HEADERS		:= headers
DIR_SOURCES		:= sources
DIR_OBJS		:= .objs
DIR_LIB			:= lib

DIR_LIBFT		:= $(DIR_LIB)/libft
LIBFT_INCLUDES	:= $(DIR_LIBFT)/headers
LIBFT			:= $(DIR_LIBFT)/libft.a

OBJS			:= $(addprefix $(DIR_OBJS)/, $(SOURCES:%.c=%.o))
OBJS_BONUS		:= $(addprefix $(DIR_OBJS)/, $(SOURCES_BONUS:%.c=%.o))

CC				:= clang
CFLAGS			:= -Wall -Wextra -Werror -g
IFLAGS			:= -I $(DIR_HEADERS) -I $(LIBFT_INCLUDES)
DIR_DUP			= mkdir -p $(@D)

BOLD		= \033[1m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
define run_and_test
printf "%b" "$(COM_STRING) $(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_STRING) $(BOLD)$@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_STRING) $(BOLD)$@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_STRING) $(BOLD)$(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef


all: $(NAME) $(OBJS)

bonus: $(NAME_BONUS) $(OBJS_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	@printf "$(BOLD)$@$(NO_COLOR) compiled $(OK_COLOR)successfully$(NO_COLOR)\n"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	@printf "$(BOLD)$@$(NO_COLOR) compiled $(OK_COLOR)successfully$(NO_COLOR)\n"

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT) --no-print-directory -j

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(call run_and_test,$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@)

clean:
	@rm -rf $(DIR_OBJS)
	@printf "Cleaned $(BOLD)$(DIR_OBJS)$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@printf "Cleaned $(BOLD)$(NAME)$(NO_COLOR)\n"
	@printf "Cleaned $(BOLD)$(NAME_BONUS)$(NO_COLOR)\n"
	@$(MAKE) -C $(DIR_LIBFT) --no-print-directory fclean

re: fclean all

.PHONY: clean fclean re bonus all
