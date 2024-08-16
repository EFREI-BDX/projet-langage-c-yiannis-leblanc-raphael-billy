# Projet CDataframe

Explication de la structure CDataframe : 
La structure Column contient les attributs suivant : 
- titre
- deux entiers tailles physique et logique
- ainsi qu'un tableau de Data.
Les Column sont stockés sous forme de liste-chaînée dans le CDataframe.
La structure maillon CDLink contient :
- un Column
- la taille de celui-ci
- L'adresse de CDLink suivant

## Liens utiles

 - [Repository](https://github.com/EFREI-BDX/projet-langage-c-yiannis-leblanc-raphael-billy)


## Authors

- [@YiannisLeblanc](https://github.com/YiannisLeblanc)
- [@RaphaelBilly](https://github.com/RaphaelBilly)

## PATCHS

### Upgrade partie 1

L'objectif est "d'encapsuler" efficacement le column.h afin de faciliter la transition vers la généralisation :
- Modifier toutes les fcts du cdataframe.h qui manipules les attributs de la Column;
- Créer des fonctions tel que set_col_value() qui permettrons d'encapsuler la structure;

#### fcts du cdataframe.h à modifier :

- add_line(); OK
- dell_line(); OK
- print_cdata_lines(); OK
- print_cdata_col(); OK
- print_col_names(); à suppr
- nb_ligne(); OK

#### fcts du column.h à rajouter/modifier :

- void insertValue(Column*, void*);
- void set_col_value(Column*, void*);
- int nb_equal_values(Column col, void* x);
- int nb_lower_values(Column col, void* x);
- int nb_higher_values(Column col, void* x);
- int col_len(Column col);
- void* return_value_by_index(Column col, int i);