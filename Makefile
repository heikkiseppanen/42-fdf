# Meta

NAME := fdf

SRCDIR := ./src
OBJDIR := ./obj

SRC :=\
main.c \
app.c \
float3.c \
float4x4.c \
window.c \
input.c \
rasterizer.c \
mesh.c

OBJ := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
DEP := $(OBJ:%.o=%.d)

ARCH := $(shell uname)

# MiniLibX

ifeq ($(ARCH), Linux)
MLX_DIR := ./third-party/minilibx-linux
MLX_LD := -lXext -lX11 -L$(MLX_DIR) -lmlx 
MLX_AR := $(MLX_DIR)/libmlx.a
else
MLX_DIR := /usr/local/include
MLX_LD := -lmlx -framework OpenGL -framework AppKit
MLX_AR := /usr/local/lib/libmlx.a
endif

# Compilation and linking

CC := cc
INCLUDE := -I$(MLX_DIR) -I$(SRCDIR)
CFLAGS := -g -Wall -Werror -Wextra $(INCLUDE)
LDFLAGS := -lm $(MLX_LD) 

# Rules

all: $(NAME)

$(NAME): $(MLX_AR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(MLX_AR):
	$(MAKE) -C $(MLX_DIR)

# Include dependency info
-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%.c  
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)
ifeq ($ARCH, Linux)
	make clean -C $(MLX_DIR)
endif

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all so clean fclean re
