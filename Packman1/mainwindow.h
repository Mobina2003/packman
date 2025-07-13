#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <thread>
#include "pacman.h"
#include "ghost.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Dot{
    QLabel* label;
    int mapX;
    int mapY;
    bool eaten;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent*) override;
    void run();
    ~MainWindow();

    bool getGameRunning() const;
    bool getWin() const;

private:
    Ui::MainWindow *ui;
    PacMan *pacMan;
    std::vector<Dot> dots;
    Ghost* ghosts[4];
    bool gameRunning;
    bool win;
};
#endif // MAINWINDOW_H
