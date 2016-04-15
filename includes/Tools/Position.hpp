#ifndef POSITION_HPP
#define POSITION_HPP

class Position{

	public:
		Position(int, int);
		Position(const Position&);
		int getX() const;
		int getY() const;
		bool isInCircle(Position* p, int rayon);
		~Position(void);
		
		

	private:
		int x; /*!<Coordonnées x de la position*/
		int y; /*!<Coordonnées y de la position*/
		
};
#endif
