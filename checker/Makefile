NAME = checker

SRCS := srcs/main.c \


CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MMD -MP 

RM := rm -rf

SRC_DIR := srcs/
OBJ_DIR := .objs/
LIBFT_DIR := .././libft

INCS := -I.

LIBFT := $(LIBFT_DIR)libft.a
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
END := \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(INCS) ../.libft/libft.a -o $@
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

FORCE :

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)$(BOLD)Objects cleaned$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)$(BOLD)Everything cleaned$(END)"

re: fclean all

.PHONY: all clean fclean re libft FORCE
