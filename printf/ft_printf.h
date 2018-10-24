/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpyrozho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:19:11 by dpyrozho          #+#    #+#             */
/*   Updated: 2018/01/26 18:20:18 by dpyrozho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>
# include <locale.h>
# define TYPES "%sSpdDioOuUxXcC"
# define FLAGS " -0#+ "
# define NUM_TYPES "hh h l ll j z"

typedef struct						s_argue
{
	unsigned int					width;
	unsigned int					pr;
	char							*flag;
	int								left;
	char							*type;
	char							id;
	int								nul;
	int								hash;
	int								unsi;
	int								dot;
	int								ret;
	int								pmod;
	va_list							g_ap;
	int								hmod;
}									t_argue;

int									ft_printf(const char *format, ...);
void								ft_nulls(void *b, size_t len, char symv);
char								*ft_a_z(int diff, char symv);
char								*ft_revstr(char *str);
char								*ft_itoabase(long long int ch,
	int base, int is_neg);
char								*ft_itoabasepo(unsigned long ch,
	int base, t_argue *s);
char								*ft_itoabaseu(unsigned long long ch,
	t_argue *s, int i);
int									ft_get_spec(char *gets, t_argue *s);
int									ft_get_type(char *gets, t_argue *s);
int									ft_m(char const *s, char c);
int									ft_get_precision(char *gets,
	t_argue *s);
char								*ft_putdnoflag_h(char *str, t_argue *s);
char								*ft_putd1flag_h(char *str, t_argue *s);
char								*ft_putd1step(char *str, t_argue *s);
char								*ft_putd1flag(char *str, t_argue *s);
char								*ft_putdnoflag(char *str, t_argue *s);
int									ft_putdi(char *str, t_argue *s);
unsigned long int					ft_decem_unsi(t_argue *s);
long long int						ft_decem_sign(t_argue *s,
	long long int arg);
int									ft_decemical(t_argue *s);
char								*ft_putstrwid(char *str, t_argue *s);
int									ft_putstri(char *str, t_argue *s);
int									ft_stri(t_argue *s);
int									ft_charik(t_argue *s);
int									ft_point(t_argue *s);
int									ft_get_arg(t_argue *s, char id);
int									ft_obnul(t_argue *s, char id);
int									ft_ftosubafter(char *gets, char id,
	int i, t_argue *s);
int									ft_get(char *gets, t_argue *s, char id);
int									isnt_valid(char str);
int									ft_checker(char *str);
int									ft_boolinval1d(t_argue *s,
	char *str, int i);
int									ft_unic(t_argue *s);
int									ft_unis(t_argue *s);
int									ft_unis_h(t_argue *s, wchar_t *str, int i);
int									ft_checkbitz(wchar_t str, t_argue *s,
													unsigned chr_len);
int									ft_onebit(wchar_t symv, t_argue *s);
int									ft_twobits(wchar_t symv, t_argue *s);
int									ft_3bits(wchar_t symv, t_argue *s);
int									ft_manybits(wchar_t symv, t_argue *s);
wchar_t								*ft_ustrdup(const char *s1);
size_t								ft_ustrlen(wchar_t *s);
int									ft_prec_part2(char *dot,
	char *newgets, t_argue *s, char *g);
int									ft_get_spec_h(char *gets,
	t_argue *s, int i);
int									ft_ps_h(char *str, t_argue *s);
int									ft_unis_h_p2(t_argue *s, wchar_t *str,
	int i, unsigned wi);
int									ft_unis_h_fp2(t_argue *s, wchar_t *str,
	unsigned int wi);

#endif
