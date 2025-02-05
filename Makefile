NAME = push_swap
CHECKER_BONUS = checker

SRCS := srcs/main.c \
    srcs/parsing/print.c \
    srcs/parsing/check_arg_valid.c \
    srcs/exec/stack_functions/init_stack.c \
	srcs/exec/operations/swap.c \
	srcs/exec/operations/push.c \
	srcs/exec/operations/rotate.c \
	srcs/exec/operations/reverse_rotate.c \
	srcs/exec/sort_index/first_sort.c \
	srcs/exec/sort_index/first_sort_utils.c \
	srcs/exec/sort_index/check_is_sort.c \
	srcs/exec/stack_functions/lst_functions.c \
	srcs/exec/sandglass_sort/sandglass_algo.c \
	srcs/exec/sandglass_sort/small_sort.c \
	srcs/exec/sandglass_sort/small_sort_utils.c \

SRCSB := checker_bonus/checker.c \
	srcs/parsing/print.c \
    srcs/parsing/check_arg_valid.c \
    srcs/exec/stack_functions/init_stack.c \
	srcs/exec/operations/swap.c \
	srcs/exec/operations/push.c \
	srcs/exec/operations/rotate.c \
	srcs/exec/operations/reverse_rotate.c \
	srcs/exec/sort_index/check_is_sort.c \
	srcs/exec/stack_functions/lst_functions.c \

HEADER := includes/push_swap.h \
		libft/libft.h

HEADERB := includes/push_swap.h \
		includes/checker.h \
		libft/libft.h

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MMD -MP

RM := rm -rf

SRC_DIR := srcs/
SRCB_DIR := checker_bonus/
OBJ_DIR := .objs/
OBJB_DIR := .objs_bonus/
DEPS := $(OBJS:.o=.d)
DEPSB := $(OBJSB:.o=.d)
INCS := -I./includes -I./libft

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJSB := $(patsubst $(SRCB_DIR)%.c,$(OBJB_DIR)%.o,$(SRCSB))

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
YELLOW := \033[0;33m
END := \033[0m

CHECKMARK := "✔️"
WARNING := "⚠️"
FIRE := "🔥"
OK := "✅"
CLEAN := "🧹"
DONE := "🏁"

-include $(DEPS)
-include $(DEPSB)

all: $(NAME)

$(NAME): libft/libft.a $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(INCS) ./libft/libft.a  -o $@
	@echo "$(CYAN)$(BOLD)$(FIRE)$(NAME) made successfully!$(OK)$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c $(HEADERB)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@ $<

libft/libft.a : FORCE
	@$(MAKE) -C libft

bonus: $(CHECKER_BONUS)

$(CHECKER_BONUS): libft/libft.a $(OBJSB) Makefile $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJSB) $(INCS) ./libft/libft.a  -o $@
	@echo "$(MAGENTA)$(BOLD)$(FIRE)$(CHECKER_BONUS) made successfully!$(OK)$(END)"

FORCE :

clean:
	@$(RM) $(OBJ_DIR) $(OBJB_DIR)
	@$(MAKE) -C libft clean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Objects cleaned$(CLEAN)$(END)"

fclean: clean
	@$(RM) $(NAME) $(CHECKER_BONUS)
	@$(MAKE) -C libft fclean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Everything cleaned $(DONE)$(END)"

re: fclean all

.PHONY: all clean fclean re bonus libft FORCE
