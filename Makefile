NAME = so_long
CFILESLG = get_next_line/get_next_line.c\
		 get_next_line/get_next_line_utils.c\
		 libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_substr.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_itoa.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_putchar_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_split.c\
		libft/ft_strchr.c\
		libft/ft_strdup.c\
		libft/ft_striteri.c\
		libft/ft_strjoin.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strlen.c\
		libft/ft_strmapi.c\
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\

CFILES = main.c\
		path.c\
		check_map.c\
		check_wall.c\
		stockwen.c\
		moves1.c\
		moves1h.c\
		moves2.c\
		${CFILESLG} \

NAMEB = so_long_b
CFILESB = bonus/path_B.c\
		bonus/check_map_B.c\
		bonus/check.c\
		bonus/check_wall_B.c\
		bonus/stockwen_B.c\
		bonus/moves1_B.c\
		bonus/move1_Bh.c\
		bonus/move_ch.c\
		bonus/enm.c\
		bonus/main_B.c\
		bonus/moves2_B.c\
		${CFILESLG} \

OBJ = ${CFILES:.c=.o}

OBJB = ${CFILESB:.c=.o}

FLAGS = -Wall -Werror -Wextra 
CC = cc
LI = ar -rc

all : ${NAME}

bonus : ${NAMEB}

${NAME} : ${OBJ}
	cc   $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(CFILES) -o $(NAME) 

${NAMEB} : ${OBJB}
	cc   $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(CFILESB) -o $(NAMEB)
clean :
	${RM} ${OBJ} ${OBJB}
fclean : clean 
	${RM} ${NAME} ${NAMEB}
re : fclean all bonus