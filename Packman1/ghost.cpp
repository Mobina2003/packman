#include "ghost.h"


char gMap[12][17] = {
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

int U = 50;

Ghost::Ghost(QWidget* parent) : QLabel(parent)
{
    mapX = 14;
    mapY = 10;
//    QPixmap imgWall("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\wall.png");
//    setPixmap(imgWall);
    setGeometry(700, 500, U, U);
}

void Ghost::move()
{
    int r = rand() % 4;


    //LEFT
    if(r == 0 && gMap[mapY][mapX-1] == '.'){
        setGeometry(geometry().x() - U, geometry().y(), U, U);
        mapX--;
        return;
    }

    //RIGHT
    if(r == 1 && gMap[mapY][mapX+1] == '.'){
        setGeometry(geometry().x() + U, geometry().y(), U, U);
        mapX++;
        return;
    }

    //UP
    if(r == 2 && gMap[mapY-1][mapX] == '.'){
        setGeometry(geometry().x(), geometry().y() - U, U, U);
        mapY--;
        return;
    }

    //DOWN
    if(r == 3 &&gMap[mapY+1][mapX] == '.'){
        setGeometry(geometry().x(), geometry().y() + U, U, U);
        mapY++;
        return;
    }
    move();
}

