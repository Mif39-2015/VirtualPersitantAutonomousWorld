#include <iostream>

#include "tool/CommandLineOptions.hpp"
#include "server/WorldSimulator.hpp"

#include "tool/cJSON.hpp"

namespace po = boost::program_options;


int main(int argc, char** argv)
{
    // Parsing command line
    po::options_description general_opt("Options : ");
    general_opt.add_options()
        ("help,h", "affiche ce message")
        ("v", "sortie verbeuse")
        ("vv", "sortie très verbeuse")
        ("personnage, pe", "log les commandes sur les personnages")
        ("arbre, ab", "log le nombre d'arbres")
        ("period,p", po::value<unsigned int>()->default_value(30), "periode de tic d'horloge pour la boucle principale (en secondes)" );

    // Vérification de la validité des arguments
    bool parse_ok = true;
    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, general_opt), vm);
    } catch(const std::exception& ex) {
        parse_ok = false;
        std::cerr << "Erreur dans les options du programme: " << ex.what() << std::endl;
    }

    po::notify(vm);

    if( !parse_ok || vm.count("help") || argc <= 1 )
    {
        std::cout << "Utilisation: " << argv[0] << " [OPTION] ... \n"
                  << "Virtual Persistant Autonomous World"
                  << general_opt << "\n";
        return 0;
    }

    // Traitement sur les arguments passés

    if(vm.count("personnage"))
    {
        std::cerr << "Log sur les personnages activé" << std::endl;
        // traitement
    }

    if(vm.count("arbre"))
    {
        std::cerr << "Log sur le nombre d'arbre activé" << std::endl;
        // traitement
    }

    if(vm.count("period"))
    {
        std::cerr << "Periode de tic d'horloge : [" << vm["period"].as<unsigned int>() << "s]" << std::endl;
        // traitement
    }

    return 0;
}
