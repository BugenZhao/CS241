#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scratches/pieview.h"
#include <QAbstractItemModel>


class MainWindow : public QMainWindow {
Q_OBJECT

private:
    QAbstractItemModel *model;
    QAbstractItemView *pie;

public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void openFile();

private:
    void setupModel();

    void setupView();

    void loadFile(const QString &fileName);

    void updateHeaders(const QStringList &headers);

    void updateTitle(const QString &name);
};

#endif // MAINWINDOW_H
