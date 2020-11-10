#include <iostream>

class Cell {
    public:
        Cell(int state, int x, int y);
        bool isDead() const;
        bool isAlive() const;
        void setAlive();
        void setDead();
        int getX() const;
        int getY() const;
    private:
        int state;
        int x, y;
        static const int ALIVE = 1;
        static const int DEAD = 2;
};

void Cell::Cell setAlive() {
    state = Cell.ALIVE;
}

int main() {
    Cell c;
    c.setAlive();
    std::cout << c.state;
}