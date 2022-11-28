# Meta

NAME := libftprintf.a

INCDIR := ./include
SRCDIR := ./src
OBJDIR := ./obj

SRC :=\
ft_printf.c \
ft_put_base.c \
ft_putdec.c \
ft_puthex.c \
ft_putptr.c \
ft_write_str.c \
ft_write_char.c \

OBJ := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# libft

FT_DIR := ./libft/
FT_AR := $(FT_DIR)/libft.a
FT_FLAGS := -I$(FT_DIR) 

# Compilation and linking

CC := cc
CFLAGS := -g -Wall -Werror -Wextra -I$(INCDIR) $(FT_FLAGS)


all: $(NAME)

$(NAME): $(FT_AR) $(OBJ)
	ar rus $(NAME) $(OBJ)

$(FT_AR):
	$(MAKE) -C $(FT_DIR)
	cp $(FT_AR) ./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c  
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) -c $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $@.d

# Include dependency info
-include $(OBJDIR)/$(OBJ:.o=.o.d)

clean:
	/bin/rm -rf $(OBJDIR)
	make clean -C $(FT_DIR)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(FT_DIR)

re: fclean all

.PHONY: all so clean fclean re
