/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchapman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:18:19 by bchapman          #+#    #+#             */
/*   Updated: 2019/04/18 15:50:58 by bchapman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_line
{
	int				pos;
	int				plus;
	int				minus;
	int				pound;
	int				zero;
	int				space;
	int				width;
	int				length;
	int				width_digits;
	va_list			ap;
}					t_line;

int					parse_csp(va_list ap, const char *p);
void				parse_dioux(t_line *line, const char *p);
int					parse_float(va_list ap);
int					ft_putstr(char *str, t_line *line);
int					ft_putchar(char c);
char				*ft_itoa(int n);
char				*ft_itoa_unsigned(unsigned int n);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_lower(int value, int base);
void				ft_print_pointer_memory(const void *addr);
char				*ft_ftoa(double f, char *buf, int precision);
int					ft_atoi(const char *str);
int					ft_strchri(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
#endif
