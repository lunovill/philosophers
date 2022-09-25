 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
SRC_FILES = chk_all\
				ft_chktbl\
				ft_error\
				ft_init\
				ft_logs\
				ft_sleep\
				lst_add\
				lst_init\
				lst_new\
				lst_rmv\
				main\
				philosophers\
				tbl_free\
				time\
				utils\

SRCS = $(addsuffix .c, $(SRC_FILES))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLFLAGS = -pthread
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CLFLAGS) $(CIFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME).h
	$(CC) $(CFLAGS) $(CLFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
