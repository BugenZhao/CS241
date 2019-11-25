#include "mainwindow.h"
#include "BPieView.h"

#include <QtWidgets>
#include <QRandomGenerator>
#include "utils/BColor.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(tr("Pie Chart"));
    resize(700, 330);

    QMenu *fileMenu = new QMenu(tr("&File"), this);
    QAction *openAction = fileMenu->addAction(tr("&Open..."));
    openAction->setShortcuts(QKeySequence::Open);
    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setShortcuts(QKeySequence::Quit);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    setupModel();
    setupView();

    menuBar()->addMenu(fileMenu);
    statusBar();
}

void MainWindow::openFile() {
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a CSV file"),
                                                          "", "*.csv");
    if (!fileName.isEmpty())
        loadFile(fileName);
}

void MainWindow::setupModel() {
    model = new QStandardItemModel(0, 2, this);
}

void MainWindow::updateHeaders(const QStringList &headers) {
    for (int i = 0; i < headers.size(); ++i) {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }
}

void MainWindow::updateTitle(const QString &name) {
    if (name.isEmpty()) setWindowTitle(tr("Pie Chart"));
    else setWindowTitle(tr("Pie Chart - ") + name);
}

void MainWindow::setupView() {
    auto splitter = new QSplitter;
    auto table = new QTableView(this);
    table->setEditTriggers(QTableView::NoEditTriggers);
    pie = new BPieView(this);

    splitter->addWidget(pie);
    splitter->addWidget(table);
    splitter->setChildrenCollapsible(true);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 0);

    table->setModel(model);
    pie->setModel(model);

    QHeaderView *headerView = table->horizontalHeader();
    headerView->setStretchLastSection(true);

    setCentralWidget(splitter);
}


void MainWindow::loadFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        statusBar()->showMessage(tr("Failed to load ") + file.fileName(), 5000);
        updateTitle("");
        return;
    }

    QTextStream stream(&file);

    QVector<QString> keys;
    QVector<double> values;
    int row = 0;
    try {
        auto headers = stream.readLine().split(',');
        while (!stream.atEnd()) {
            const QString line = stream.readLine();
            if (!line.isEmpty()) {
                const QStringList tokens = line.split(',');
                qInfo() << tokens.value(0) << " " << tokens.value(1);
                keys.append(tokens.value(0));
                values.append(tokens.value(1).toDouble());
                row++;
            }
        };
        updateHeaders(headers);
    } catch (QException &e) {
        statusBar()->showMessage(
                tr("Failed to load ") + file.fileName() + tr(" because of ") + e.what(), 5000);
        return;
    }

    model->removeRows(0, model->rowCount());

    auto colors = BColor::random(row);
    for (int r = 0; r < row; ++r) {
        model->insertRow(r);
        model->setData(model->index(r, 0), keys.value(r));
        model->setData(model->index(r, 1), values.value(r), Qt::DisplayRole);
        model->setData(model->index(r, 0), colors[r], Qt::DecorationRole);
    }

    model->sort(1, Qt::SortOrder::DescendingOrder);

    statusBar()->showMessage(tr("Loaded ") + file.fileName(), 2000);

    updateTitle(file.fileName());
    file.close();
}

MainWindow::~MainWindow() {
    delete model;
    delete pie;
}
