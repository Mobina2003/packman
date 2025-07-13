#ifndef PACMAN_H
#define PACMAN_H

#include <QLabel>

class PacMan : public QLabel
{
public:
    PacMan(QWidget* parent);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int mapX, mapY;
};

#endif // PACMAN_H
