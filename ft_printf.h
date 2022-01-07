/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-b <apaula-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:13 by apaula-b          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/07 20:43:56 by apaula-b         ###   ########.fr       */
=======
/*   Updated: 2021/10/05 19:23:09 by apaula-b         ###   ########.fr       */
>>>>>>> caeb45a3947e08953bb40a69a7f075a10b168775
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_counters
{
	int		counter;
	int		length;
}		t_c;


//---------------------------------start_structs------------------------------

void		start_counters(t_c *counters);

//---------------------------------collect_info-------------------------------

void		get_type(const char *data, va_list args, t_c *count);

//---------------------------------type_functions-----------------------------

size_t		ft_isalpha(size_t c);

size_t		ft_isdigit(size_t c);

size_t		ft_isflag(size_t str);

size_t		ft_strlen(char *s);

//---------------------------------char_functions-----------------------------

size_t		print_char(va_list args, t_c *count);

void		ft_putstr(char string, t_c *count);

//---------------------------------text_functions(%s)-------------------------

size_t		print_string(va_list args, t_c *count);

void		print_percent(t_c *count);

//--------------------------------hexa_functions------------------------------

size_t		print_hexa(va_list args, t_c *count, const char *data);

//---------------------------------integer_functions--------------------------

size_t		print_int(va_list args, t_c *count, const char *type);

size_t		print_pointer(va_list args, t_c *count);

int			get_size_int(long int value);

char		*convert_int(va_list args, const char *type);

//---------------------------------conversion_functions-----------------------

int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t count, size_t size);

char		*ft_itoa(int n);

char		*ft_itoa_unsigned(unsigned int n);

char		*ft_utoa(unsigned int integer);

char		*ft_utoa_long(unsigned long integer);

char		*ft_toupper(char *c);

//---------------------------------global_functions---------------------------
int			ft_printf(const char *format, ...);

void		get_data(const char *data, va_list args, t_c *count);

void		print_null(t_c *count);

void		ft_putstr_fd(char *s, t_c *count);

#endif
