# Rapport projet phase 1 (LDP)

## La fonction `saturated(new_value)`
Cette fonction retourne un `int` selon la formule de la documentation :
$\text{saturated}(n) = \min(\max(n, 0), 2^{16})$.
Pour cela je vais utiliser un système de `if` à 3 cas. 
Si le nombre est plus grand que la valeur max qu'un `uint16_t` peut avoir ($65,536$), alors retourner le max que peut contenir un `uint16_t`. 
Si il est plus petit que la valeur $\max$ d'un `uint16_t` ($0$), alors alors retourner le $\min$ que peut contenir un `uint16_t`. 
Sinon, cela veut dire que le nombre est bien dans les bornes d'un `uint16_t` et on peut donc le retourner sans modification.

A noter que j'ai utiliser la méthode `std::numeric_limits` qui peut me donner la valeur $\max$ et $\min$ d'un type.

## La fonction `parse_opcode(instr)`
Les opcodes (mots clé) sont séparé des opérants (argument) par un espace. 
Je vais alors utiliser la fonction `find(' ')` trouver l'index dans le `string` de l'instruction de où se trouve l'espace, puis utiliser la fonction `substr(0, index du ' ')` qui va retourner le sous-string du début jusqu'à l'espace.

A noté que lorsqu'il n'y a pas d'espace dans la ligne (pour les commandes `PRINT` et `IFNZ`), la fonction find va me retourner la valeur `-1`, considéré comme l'indice universelle pour le dernier élément d'un `string`.

## La fonction `parse_operand(instr)`
Je commence par décomposer l'instruction avec la même méthode que dans `parse_opcode()`, sauf qu'ici je ne met que l'index de l'espace en paramètre, ce qui va me retourner uniquement operant au format `string`. 
Il ne reste plus qu'à le passer dans la fonction `stoi` qui va transformer le `string` en `int`. 
On va finalement passer le résultat dans la fonction `saturated()` pour que retourner une valeur qui tien dans un `uint16_t` comme imposé dans l'énoncé.

## La fonction `exec(program_path)`
On défini `single_register` à $0$ et on réserve dans la mémoire un page pour `instruction` soit la ligne qui va être lue, et `opcode` soit le nom de l'instruction qui va être effectué. 
(Pas besoin de réserve un page pour les opérant étant donné qu'ils sont directement envoyé dans une fonction et le résultat à la fin est stocké dans `single_register`)

La méthode `std::ifstream instructions_file (program_path);` nous permet de pouvoir avec la fonction `getline(instructions_file, instruction)` stocker les lignes une par une dans `instruction`. 
Étant donnée que cette fonction renvoie un equivalent `False` une fois que toutes les lignes ont été lues, on peut la mettre dans la condition de la boucle `while` pour continuer à lire les lignes jusqu'à la dernière. Ce qui va nous permettre d'exécuter les instruction **à la volée** comme le demande la consigne.

Dans la boucle, on va dans un premier temps via `parse_opcode(instruction)` stocker le nom de l'opération dans `opcode`. 
Puis on va le faire passer dans un jeu de `if` `else` pour faire exécuter la bonne fonction. 
Je note qu'un `switch case` aurait été plus optimisé mais cette méthode ne marche que pour les types natifs (`int`, `char`, ...) et pas pour les `string`.

## La fonction `main(int argc, char* argv[])`
Le paramètre `argc` va contenir le nombre d'argument qui ont été noter pour lancer le programme (dans le cas normal, $2$) et `argv[]` stocke dans une liste tout ces argument.
Il faut donc faire passer l'argument en indice $1$ (soit le deuxième) dans la fonction `exec(program_path)` pour que `ifstream` de la fonction `exec` puisse acceder au bon fichier.
(A noter que j'ai fais de la gestion d'erreur même si ce n'est pas demander dans les consigne uniquement pour ne pas avoir le waring de la variable `argc` non-utilisé)


<!-- TODO: demander si il faut préciser derrière le fonctionnement de `find` qui, pour rappel, quand ne retrouve pas le caractère  -->
