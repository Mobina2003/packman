#include "pacman.h"
#include <iostream>
char map[12][17] = {
    "################",
    "#..............#",
    "#.############.#",
    "#..............#",
    "#.#.#.####.#.#.#",
    "#.#.#.#..#.#.#.#",
    "#.#.#.#..#.#.#.#",
    "#.#.#.####.#.#.#",
    "#..............#",
    "#.############.#",
    "#..............#",
    "################",
};


const float UNIT = 50;

PacMan::PacMan(QWidget* parent) : QLabel(parent)
{
    QPixmap imgPacman("C:/Users/Mahdiyar/Desktop/Folders/Programing/AUT/BejaniAP2/Pacman1/Packman1/Resources/player.png");
    setPixmap(imgPacman);
    setGeometry(50, 50, 50, 50);
    mapX = mapY = 1;
}

void PacMan::moveUp()
{
    if(map[mapY-1][mapX] == '.'){
        this->setGeometry(geometry().x(), geometry().y() - UNIT, UNIT, UNIT);
        mapY--;
    }
}

void PacMan::moveDown()
{
    if(map[mapY+1][mapX] == '.'){
        this->setGeometry(geometry().x(), geometry().y() + UNIT, UNIT, UNIT);
        mapY++;
    }
}

void PacMan::moveLeft()
{
    if(map[mapY][mapX-1] == '.'){
        this->setGeometry(geometry().x() - UNIT, geometry().y(), UNIT, UNIT);
        mapX--;
    }

}

void PacMan::moveRight()
{
    if(map[mapY][mapX+1] == '.'){
        this->setGeometry(geometry().x() + UNIT, geometry().y(), UNIT, UNIT);
        mapX++;
    }
}
