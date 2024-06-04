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

- add_line();
- dell_line();
- print_cdata_lines();
- print_cdata_col();
- print_col_names
- nb_ligne();
