/*
** EPITECH PROJECT, 2017
** shell.h
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_

#define REF_PATH	"PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin"
#define REF_PWD		"PWD="
#define REF_OLDPWD	"OLDPWD="
#define NO_ENV		4

typedef struct env env_t;

struct env {
	int noenv;
	int ret;
	char **env;
	char **paths;
};

char    **create_env(char **env);
char    **fill_env(char **env, char **new);
int     start_env(char **env, env_t *newenv);
void	my_unset(char **ref, env_t *env);
void	setenv_err(void);
void	my_setenv(char **ref, env_t *env);

int     path_nb(char *paths);
int     path_len(char *paths);
void    path_set(char *copy, env_t *env);
void    get_bin(char **envp, env_t *env);
int	check_bin(char *path, env_t *env);

void	errors(int check, env_t *env);
void	exe_func(char *path, char **arg, env_t *env);
int	exe(char **arg, env_t *env);
int	check_file(char *path, env_t *env);
void	cd_dir(char **arg, env_t *env);
int	check_semicolons(char const *str);
int	semicolons(char *str, env_t *newenv);
int	len(char const *str);
char	**str_to_str(char const *str);
int	start_fork(char **arg, env_t *env);
void	free_exit(env_t *env);

char	**char_charchar(char const *str);

#endif
