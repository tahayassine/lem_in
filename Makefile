NAME 		= 	lem-in

SRCDIR		= 	src/

INCDIR		=	header/

SRCBASE		=	check        connector2   ft_atoll     ft_strsearch\
				anthill_s_e  debeug       ft_isnum     init           print\
				connector    free_struct  ft_parse     main           pushback\

INCBASE		=	lemin.h

SRC			= 	$(addprefix $(SRCDIR), $(SRCBASE))

INC			= 	$(addprefix $(INCDIR), $(INCBASE))

FLAGS 		= 	-Wall -Wextra -Werror

LIB 		= 	libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c $(FLAGS) $(addsuffix .c, $(SRC)) $(INC) -I $(INCDIR) -I libft
	gcc -o $(NAME) $(addsuffix .o, $(SRCBASE)) $(LIB)

clean:
	make -C libft/ clean
	rm -f $(addsuffix .o, $(SRCBASE))
	rm -f $(addsuffix .gch, $(INC))
	rm -f $(addprefix $(SRCDIR), $(addprefix ._, $(addsuffix .c, $(SRCBASE))))

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
