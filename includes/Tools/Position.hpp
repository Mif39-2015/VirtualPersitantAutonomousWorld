#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
public:
	Position(int, int);
	~Position(void);
        
        int getX();
        int getY();
        bool isInCircle(Position* p, int rayon);

private:
	int x;
	int y;
};
#endif
