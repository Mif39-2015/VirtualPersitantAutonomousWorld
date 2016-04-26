#include "serveur_catch.hpp"
#include "reseau/NetworkAdapter.hpp"
#include "reseau/NetworkManager.hpp"

#include <iostream>

TEST_CASE("Test socket", "[foo]")
{
    NetworkManager* netMan = new NetworkManager(NULL);

    // On est obligés de wait ici sinon le programme s'arrête instantanément
    // puisque le NetworkAdapter est lancé dans un thread séparé
    // et que le fil d'exécution du NetworkManager s'arrête.
    while(true);
}
