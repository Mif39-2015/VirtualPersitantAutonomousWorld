#ifndef POSITION_HPP
#define POSITION_HPP
//#include "tool/cJSON.hpp"

/*!
 * \file Position.hpp
 * \brief contient la classe Position
 * \author Groupe IA
 */

/*!
*\class Position
*\brief Classe permettant de représenter une positon dans le monde
*/
class Position {

	public:
		/*!
		 	*\brief Constructeur avec paramètres
		 	*\param x : coordonnée x
		 	*\param y : coordonnée y
		 */
		Position(int, int);

		/*!
		 	*\brief Constructeur par copie
		 	*\param p : la position à copier
		 */
		Position(const Position& p);

		int getX() const;

		int getY() const;

		/*!
		 	*\brief permet de savoir si une position se situe dans la périphérie de la position courante
		 	*\param p : la position à examiner
		 	*\param rayon : le rayon du cercle à considérer
		 */
		bool isInCircle(Position* p, int rayon);
		
		bool operator<(Position const &) const; 
		bool operator==(Position const &) const; 
		
		//cJSON* toJson();
		
		/*!
		 	*\brief Destructeur
		 */
		~Position(void);
		



	private:
		int x; /*!<Coordonnées x de la position*/
		int y; /*!<Coordonnées y de la position*/

};
#endif
