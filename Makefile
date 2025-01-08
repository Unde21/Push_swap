NAME = push_swap.a

SRCS := srcs/main.c \
    srcs/print.c \
    srcs/parsing/check_arg_valid.c \
    srcs/exec/init_lst.c

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MD -MP -MF

RM := rm -rf
AR := ar -rcs

SRC_DIR := srcs/
OBJ_DIR := .objs/
DEP_DIR := .deps/
LIBFT_DIR := libft/

INCS := -I. -I$(LIBFT_DIR)

OBJS := $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS := $(SRCS:%.c=$(DEP_DIR)%.d)

LIBFT := $(LIBFT_DIR)libft.a

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)$*)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ -MMD -MF $(DEP_DIR)$*.d

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean: 
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

re: fclean all

.PHONY: all clean fclean re libft FORCE
