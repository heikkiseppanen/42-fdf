# Meta

NAME := fdf

SRCDIR := ./src
OBJDIR := ./obj

SRC :=\
main.c \
int2.c \
window.c \
input.c \

OBJ := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

ARCH := $(shell uname)

# MiniLibX

ifeq ($(ARCH), Linux)
MLX_DIR := ./third-party/minilibx-linux
MLX_LINK := -L$(MLX_DIR) -lmlx -lXext -lX11
else
MLX_DIR := ./third-party/minilibx-macos
MLX_LINK := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
MLX_AR := $(MLX_DIR)/libmlx.a

# Compilation and linking

CC := cc
INCLUDE := -I$(MLX_DIR) -I$(SRCDIR)
CFLAGS := -g -Wall -Werror -Wextra $(INCLUDE)

# Rules

all: $(NAME)

$(NAME): $(MLX_AR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLX_LINK)

$(MLX_AR):
	$(MAKE) -C $(MLX_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c  
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) -c $(CFLAGS) -o $@ $<
	$(CC) -MM $(CFLAGS) $< > $@.d

# Include dependency info
#-include $(OBJDIR)/$(OBJ:.o=.o.d)

clean:
	/bin/rm -rf $(OBJDIR)
	make clean -C $(MLX_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all so clean fclean re
