NAME = push_swap.a

SRCS :=

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

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
DEPS := $(SRCS:$(SRC_DIR)%.c=$(DEP_DIR)%.d)

LIBFT := $(LIBFT_DIR)libft.a

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m

-include $(DEPS)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"

.PHONY: all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)$*)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) $(DEP_DIR)$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: libft

FORCE:

.PHONY: FORCE

clean: 
	@$(RM) $(OBJS_DIR) $(DEPS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

.PHONY: clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

.PHONY: fclean

re: fclean all

.PHONY: re
