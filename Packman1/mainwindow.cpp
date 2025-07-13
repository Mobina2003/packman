#include "mainwindow.h"
#include "ui_mainwindow.h"

const char mwMap[12][17] = {
    "################",
    "#..............#",
    "#.############.#",
    "#..............#",
    "#.#.#.####.#.#.#",
    "#.#.#.#  #.#.#.#",
    "#.#.#.#  #.#.#.#",
    "#.#.#.####.#.#.#",
    "#..............#",
    "#.############.#",
    "#..............#",
    "################",
};

const int u = 50;
int totalDots = 0, collectedDots = 0;
char direction = 'r';

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    setStyleSheet("QMainWindow {background: 'black';}");
    setFixedSize(800, 600);
    gameRunning = true;
    win = false;

    pacMan = new PacMan(this);

//    srand(time(0));

    // Generate Map
    QPixmap imgWall("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\wall.png");
    QPixmap imgDot("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\dot.png");
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 16; j++){
            if(mwMap[i][j] == '#'){
                QLabel* newWall = new QLabel(this);
                newWall->setPixmap(imgWall);
                newWall->setGeometry(j*u, i*u, u, u);
            }else if(mwMap[i][j] == '.'){
                QLabel* newDot = new QLabel(this);
                newDot->setPixmap(imgDot);
                newDot->setGeometry(j*u, i*u, u, u);
                dots.push_back({newDot, j, i, false});
                totalDots++;
            }
        }
    }

    // Summon Ghosts
    QPixmap imgGhosts[4];
    imgGhosts[0] = QPixmap("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\ghost1.png");
    imgGhosts[1] = QPixmap("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\ghost2.png");
    imgGhosts[2] = QPixmap("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\ghost4.png");
    imgGhosts[3] = QPixmap("C:\\Users\\Mahdiyar\\Desktop\\Folders\\Programing\\AUT\\BejaniAP2\\Pacman1\\Packman1\\Resources\\ghost3.png");
    for(int i = 0; i < 4; i++){
        Ghost* newGhost = new Ghost(this);
        newGhost->setPixmap(imgGhosts[i]);
        ghosts[i] = newGhost;
    }
    ui->setupUi(this);
    ui->txtWin->hide();
    ui->txtLost->hide();
//    start();
}



void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_W:
        direction = 'u';
        break;
    case Qt::Key_A:
        direction = 'l';
        break;
    case Qt::Key_S:
        direction = 'd';
        break;
    case Qt::Key_D:
        direction = 'r';
        break;
    }
}

void MainWindow::run()
{

    switch (direction) {
    case 'u':
        pacMan->moveUp();
        break;
    case 'l':
        pacMan->moveLeft();
        break;
    case 'd':
        pacMan->moveDown();
        break;
    case 'r':
        pacMan->moveRight();
        break;
    }

    for(Ghost* ghost: ghosts){
        ghost->move();
        if(ghost->mapX == pacMan->mapX && ghost->mapY == pacMan->mapY){
            pacMan->hide();
            qDebug() << "LOST";
            //LOSE
            gameRunning = false;
            win = false;
            ui->txtLost->show();
        }
    }

    for(Dot& dot: dots){
        if(!dot.eaten && dot.mapX == pacMan->mapX && dot.mapY == pacMan->mapY){
            dot.label->hide();
            collectedDots++;
            if(collectedDots == totalDots){
                //WIN
                ui->txtWin->show();
                qDebug() << "WIN";
                gameRunning = false;
                win = true;
            }
            dot.eaten = true;
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getGameRunning() const
{
    return gameRunning;
}

bool MainWindow::getWin() const
{
    return win;
}

