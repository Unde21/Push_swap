NAME = push_swap

SRCS := srcs/main.c \
    srcs/print.c \
    srcs/parsing/check_arg_valid.c \
    srcs/exec/init_stack.c \
	srcs/exec/operations.c

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MMD -MP 

RM := rm -rf

SRC_DIR := srcs/
SRCB_DIR := srcs_bonus/
OBJ_DIR := .objs/
OBJB_DIR := .objs_bonus/
LIBFT_DIR := ./libft

INCS := -I.

LIBFT := $(LIBFT_DIR)libft.a
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJSB := $(patsubst $(SRCB_DIR)%.c, $(OBJB_DIR)%.o, $(SRCSB))

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(INCS) ./libft/libft.a -o $@
	@echo "$(BLUE)$(BOLD)$(NAME) made successfully!$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS)-c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@

$(OBJB_DIR):
	@mkdir -p $@

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

bonus: .bonus

.bonus: $(LIBFT) $(OBJSB)
	$(RM) $(NAME) 
	@$(RM) $(OBJ_DIR)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJSB)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(END)"
	@echo "$(BLUE)$(BOLD)$(NAME) made with bonuses$(END)"
	@touch .bonus

FORCE :

clean:
	@$(RM) $(OBJ_DIR) $(OBJB_DIR) .bonus
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

re: fclean all

.PHONY: all clean fclean re bonus libft FORCE
