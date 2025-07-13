#ifndef GHOST_H
#define GHOST_H

#include <QLabel>
#include <random>


class Ghost : public QLabel
{
public:
    Ghost(QWidget* parent);

    void move();
    int mapX, mapY;
};

#endif // GHOST_H
