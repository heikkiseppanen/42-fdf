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
MLX_AR := $(MLX_DIR)/libmlx.a
else
MLX_DIR := /usr/local/include
MLX_LINK := -lmlx -framework OpenGL -framework AppKit
MLX_AR := /usr/local/lib/libmlx.a
endif

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
ifeq ($ARCH, Linux)
	make clean -C $(MLX_DIR)
endif

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all so clean fclean re
