LEM-IN_NAME = lem-in

LIBRARY = libft/libft.a

LEM_C = additional find_ways fix_norme get_input launch_ants \
		main parse_input select_connections get_data

LEM-IN_DIR = ./

OBJ_LEM-IN = $(addprefix $(LEM-IN_DIR),$(addsuffix .o,$(LEM_C)))


FLAGS = -Wall -Wextra -Werror

all: lib lem-in 

lib:
	@make -C ./libft

lem-in: $(OBJ_LEM-IN)
	gcc -o $(LEM-IN_NAME) $(FLAGS) $(OBJ_LEM-IN) $(LIBRARY) 

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@find . -name "*.o" -type f -delete

fclean: clean
	@rm -f $(LEM-IN_NAME) $(LIBRARY)

re: fclean all
