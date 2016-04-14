#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
public:
	Position(int, int);
	Position(const Position&);
	~Position(void);
        
        int getX() const;
        int getY() const;
        bool isInCircle(Position* p, int rayon);

private:
	int x;
	int y;
};
#endif
