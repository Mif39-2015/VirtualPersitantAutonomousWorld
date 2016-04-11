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

##  Création d'un nouveau test unitaire ##

Un exemple de test unitaire est `test/test_foo.cpp` associé à la classe `src/foo.hpp`

Petit tutorial ici : https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

Pour ajouter un nouveau test unitaire, par exemple `test/test_bar.cpp`
Il faut ouvrir `test/CMakeLists.txt` et ajouter `test_bar` dans `TEST_LIST` (juste en dessous de `test_foo`)

Puis il faut regénérer un makefile avec `cmake ..` en étant dans le dossier `build`

## Compiler un test unitaire spécifique ##

Être dans `build/test/`

Puis `make test_foo` pour compiler le test unitaire `test_foo.cpp`

L'exécutable principale est `build/src/exec`
