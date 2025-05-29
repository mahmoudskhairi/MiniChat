CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME1 = server
NAME2 = client

all: $(NAME1) $(NAME2)

$(NAME1):
	$(CC) $(CPPFLAGS) server.cpp -o $(NAME1)
$(NAME2):
	$(CC) $(CPPFLAGS) client.cpp -o $(NAME2)
clean:
	@ $(RM) $(NAME1) $(NAME2)

fclean: clean

re: fclean all