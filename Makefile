CC	= gcc
FLAGS = -Wall -Wextra -Werror
RM	= rm -f

CLIENT = client
SERVER = server

SRCS_C = client.c tools.c
SRCS_S = server.c tools.c
OBJSC = $(SRCS_C:.c=.o)
OBJSS = $(SRCS_S:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	@$(CC) $(SRCS_C) $(FLAGS) -o $(CLIENT)

$(SERVER) :
	@$(CC) $(SRCS_S) $(FLAGS) -o $(SERVER)

clean:
	@$(RM) $(OBJS_C)
	@$(RM) $(OBJS_S)
	@echo "clean"

fclean: clean
	 	@$(RM) $(CLIENT)
	 	@$(RM) $(SERVER)

re: fclean all

so:	re
	@$(RM) $(OBJS_C)
	@$(RM) $(OBJS_S)
	@echo "Ouais"

.PHONY:		all clean fclean re so
