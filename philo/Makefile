 #=============================================================================#
#								SOURCES											#
 #=============================================================================#

SRCS_DIR = sources
SRC_FILES = chk_all\
				ft_error\
				ft_init\
				ft_logs\
				lst_add\
				lst_init\
				lst_new\
				lst_rmv\
				lst_print\
				main\
				philosophers\
				tbl_free\
				time\
				utils\

SRCS = $(addsuffix .c, $(SRC_FILES))

SRC_FILES_BONUS = $(addsuffix _bonus, $(SRC_FILES))
SRCS_BONUS = $(addsuffix .c, $(SRC_FILES_BONUS))

 #=============================================================================#
#									OBJETS										#
 #=============================================================================#

OBJS_DIR = objets
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

 #=============================================================================#
#									LIBRARY										#
 #=============================================================================#

 #=============================================================================#
#									COMPILATION									#
 #=============================================================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g
CDFLAGS = -MMD -MP
CIFLAGS = -Iincludes

 #=============================================================================#
#									MAKEFILE									#
 #=============================================================================#

NAME = philo
NAME_BONUS = philo_bonus

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_DIR) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(CIFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(OBJS_BONUS) : $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c ./includes/$(NAME_BONUS).h
	$(CC) $(CFLAGS) $(CDFLAGS) $(CIFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY: all bonus clean fclean re
