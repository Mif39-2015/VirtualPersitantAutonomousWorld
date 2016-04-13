Nous avons ajouté la lib msgpack.hpp pour la sérialization des classes
en MessagePack (une sorte de JSon plus efficace).

D'abord, le Makefile n'a pas bouger.
Pour l'installation de la librairie, voilà ce qu'il faut faire :
- Assurer vous d'avoir une version de gcc >= 4.1.0 et de cmake >= 2.8.0 (gcc/cmake --version)

- Mettez vous dans un dossier de votre choix (mais pas dans le dépôt du Git bien sûr)

- Executez ces lignes de commandes :
	$ git clone https://github.com/msgpack/msgpack-c.git
	$ cd msgpack-c
	$ cmake .
	$ make
	$ sudo make install

Normalement, après ça, dans le répertoire usr/local/include, vous avez des fichiers qui correspondent
à la librairie de MessagePack.

Et voilà !

PS :
Voici le site où se trouve toutes ces infos : https://github.com/msgpack/msgpack-c/blob/master/README.md

PPS:
Il y a une autre manière d'installer la lib avec d'autre ligne de commande, mais elle ne marchait pas sur ma machine,
j'ai alors mit la façon qui fonctionnais chez moi.