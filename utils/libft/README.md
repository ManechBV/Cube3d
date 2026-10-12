*This project has been created as part of the 42 curriculum by adarolla*

Libft
Description

Libft est le premier projet du cursus 42. Son objectif est de recréer une partie des fonctions de la bibliothèque standard du langage C afin de mieux comprendre leur fonctionnement interne et d'acquérir de solides bases en programmation bas niveau.

Cette bibliothèque personnelle sera réutilisée dans de nombreux projets du cursus, notamment ft_printf, get_next_line, so_long, push_swap, minishell et cub3D.

Le projet est divisé en trois parties :

Réimplémentation de fonctions de la libc.
Création de fonctions utilitaires supplémentaires.
Implémentation d'une bibliothèque de listes chaînées.
Fonctionnalités
Fonctions de la libc
Vérification de caractères
ft_isalpha
ft_isdigit
ft_isalnum
ft_isascii
ft_isprint
Manipulation de chaînes
ft_strlen
ft_strlcpy
ft_strlcat
ft_strchr
ft_strrchr
ft_strncmp
ft_strnstr
ft_strdup
Manipulation mémoire
ft_memset
ft_bzero
ft_memcpy
ft_memmove
ft_memchr
ft_memcmp
ft_calloc
Conversion
ft_toupper
ft_tolower
ft_atoi
Fonctions supplémentaires
ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
ft_striteri
ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd
Bonus : listes chaînées
ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap
Instructions
Compilation

Compiler la bibliothèque :

make

Compiler la partie bonus :

make bonus

Supprimer les fichiers objets :

make clean

Supprimer les fichiers objets et la bibliothèque :

make fclean

Recompiler entièrement :

make re
Utilisation

Inclure le header dans votre projet :

#include "libft.h"

Compiler votre programme avec la bibliothèque :

cc main.c libft.a

Exemple :

#include "libft.h"

int main(void)
{
	ft_putendl_fd("Hello Libft!", 1);
	return (0);
}
Structure du projet
.
├── Makefile
├── libft.h
├── ft_*.c
├── bonus/
└── README.md
Choix techniques
Respect de la Norminette.
Compilation avec les flags :
Wall
Wextra
Werror
Gestion rigoureuse de la mémoire dynamique.
Création d'une bibliothèque statique nommée libft.a.
Réutilisation maximale des fonctions déjà développées lorsque cela est pertinent.
Ressources
Documentation
Manuel Linux (man)
The Open Group Base Specifications
GNU C Library Documentation
cppreference
Documentation officielle du langage C
Articles et tutoriels
Documentation 42 concernant Libft
Guides sur la gestion mémoire en C
Tutoriels sur les listes chaînées
Utilisation de l'IA

L'intelligence artificielle a été utilisée comme outil d'apprentissage et de compréhension.

Utilisations :

Compréhension du sujet et des exigences.
Explications théoriques concernant les fonctions de la libc.
Compréhension des concepts de gestion mémoire.
Aide à la compréhension des listes chaînées.
Relecture et amélioration de la documentation.

L'implémentation des fonctions, les tests, le débogage et la validation du projet ont été réalisés par l'auteur.

Auteur
adarolla
