//
// Created by Bugen Zhao on 2019/11/24.
//

#ifndef PIECHART_BPIEVIEW_H
#define PIECHART_BPIEVIEW_H

#include <QAbstractItemView>

class BPieView : public QAbstractItemView {
    unsigned itemCount;
    double totalValue;

    int margin = 10;
    int totalSize = 300;
    int pieSize = totalSize - 2 * margin;

public:
    BPieView(QWidget *parent);

    QRect visualRect(const QModelIndex &index) const override;

    void scrollTo(const QModelIndex &index, ScrollHint hint) override;

    QModelIndex indexAt(const QPoint &point) const override;

protected:
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;

    int horizontalOffset() const override;

    int verticalOffset() const override;

    bool isIndexHidden(const QModelIndex &index) const override;

    void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command) override;

    QRegion visualRegionForSelection(const QItemSelection &selection) const override;

    void paintEvent(QPaintEvent *event) override;


protected slots:

    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) override;

    QRect itemRect(const QModelIndex &index) const;
};


#endif //PIECHART_BPIEVIEW_H
