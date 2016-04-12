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

[![asciicast](https://asciinema.org/a/egf9jz3w2weccq0kmhcjcw2ig.png)](https://asciinema.org/a/egf9jz3w2weccq0kmhcjcw2ig)

##  Création d'un nouveau test unitaire ##

Petit tutorial ici : https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

Pour ajouter un nouveau test unitaire, par exemple `test/test_socket.cpp`
Il faut ouvrir `test/CMakeLists.txt` et ajouter `test_socket` dans `TEST_LIST`

Puis il faut regénérer le makefile avec `cmake ..` en étant dans le dossier `build`

## Compiler un test unitaire spécifique ##

Être dans `build/test/`

Puis `make test_foo` pour compiler le test unitaire `test_foo.cpp`

L'exécutable principale est `build/src/exec`
