# VirtualPersitantAutonomousWorld

## Compilation ##

Depuis la racine du projet :

```shell
mkdir build
cd build
cmake ..
make
make doc # permet la compilation de la doc doxygen qui est dans doc/html/index.html
```

https://asciinema.org/a/egf9jz3w2weccq0kmhcjcw2ig

## Gestion des sources ##

Les sources se situent dans `src/`

Le programme principal se situe dans `src/main.cpp`

Chaques modules du programme sont découpés en sous dossier

par exemple : `src/serveur` ; `src/db` ; etc

Le programme compilé est `build/src/exec`

## Test unitaire ##

Syntaxe des tests unitaire : https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

#### Ajouter un nouveau test unitaire ####

Se placer dans un des modules, par exemple pour se placer sur le module `serveur`, aller dans le dossier `test/serveur/`

Puis créer un fichier `test/serveur/test_bar.cpp` qui contiendra le test unitaire `bar`

Puis il faut regénérer le makefile avec `cmake ..` en étant dans le dossier `build`

L'exécutable correspondant au test unitaire `bar` est `build/test/foo/test_bar`

#### Compiler un test unitaire spécifique ####

Être dans `build/test/serveur/`

Puis `make nom_du_test` pour compiler le test unitaire `test/foo/nom_du_test.cpp`
