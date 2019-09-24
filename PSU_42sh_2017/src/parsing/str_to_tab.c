/*
** EPITECH PROJECT, 2018
** char_charchar.c
** File description:
** *char to **char
*/

#include "my.h"
#include "shell.h"

int word_nb(const char *str)
{
	int words = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == ' ' || str[i] == '\t') {
			i++;
		} else {
			words++;
			while (str[i] != ' ' && str[i] != '\t'
						&& str[i] != '\0')
				i++;
		}
	}
	return (words);
}

int word_len(char const *str, int ref)
{
	int size = 0;
	int word = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == ' ' || str[i] == '\t') {
			i++;
		} else {
			word++;
			while (str[i] != ' ' && str[i] != '\t'
						&& str[i] != '\0') {
				size++;
				i++;
			}
			if (word == ref)
				return (size);
			else
				size -= size;
		}
	}
	return (size);
}

void fill_array(char **final, char const *str)
{
	int i = 0;
	int j = 0;
	int check = 0;

	if (str == NULL) {
		my_putchar('\n');
		return;
	}
	while (str[i] != '\0') {
		if (str[i] == ' ' || str[i] == '\t') {
			i++;
		} else {
			while (str[i] != ' ' && str[i] != '\t'
						&& str[i] != '\0')
				final[check][j++] = str[i++];
			final[check][j] = '\0';
			check++;
			j = 0;
		}
	}
	final[check] = NULL;
}

char **char_charchar(char const *str)
{
	char **final;
	int wordnb = word_nb(str);

	if (str == NULL)
		return (NULL);
	final = malloc(sizeof(char *) * (wordnb + 1));
	if (final == NULL)
		return (NULL);
	word_len(str, 1);
	for (int i = 1; i <= wordnb; i++)
		final[i - 1] = malloc(sizeof(char) * (word_len(str, i)) + 1);
	fill_array(final, str);
	return (final);
}
