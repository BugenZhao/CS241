//
// Created by Bugen Zhao on 2019/11/24.
//

#include <QtWidgets>
#include "BPieView.h"

QRect BPieView::visualRect(const QModelIndex &index) const {
    QRect rect = itemRect(index);
    if (rect.isValid())
        return rect;

    return QRect(rect.left() - horizontalScrollBar()->value(),
                 rect.top() - verticalScrollBar()->value(),
                 rect.width(), rect.height());
}

void BPieView::scrollTo(const QModelIndex &index, QAbstractItemView::ScrollHint hint) {
}

QModelIndex BPieView::indexAt(const QPoint &point) const {
    return QModelIndex();
}

QModelIndex BPieView::moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers) {
    return QModelIndex();
}

int BPieView::horizontalOffset() const {
    return horizontalScrollBar()->value();
}

int BPieView::verticalOffset() const {
    return verticalScrollBar()->value();
}

bool BPieView::isIndexHidden(const QModelIndex &index) const {
    return false;
}

void BPieView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command) {
}

QRegion BPieView::visualRegionForSelection(const QItemSelection &selection) const {
    return QRegion();
}

void BPieView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
    QAbstractItemView::dataChanged(topLeft, bottomRight, roles);

    if (!roles.contains(Qt::DisplayRole))
        return;

    itemCount = 0;
    totalValue = 0.0;

    for (int row = 0; row < model()->rowCount(rootIndex()); ++row) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        double value = model()->data(index, Qt::DisplayRole).toDouble();

        if (value > 0.0) {
            totalValue += value;
            itemCount++;
        }
    }
    viewport()->update();
}

void BPieView::paintEvent(QPaintEvent *event) {
    if (itemCount == 0)
        return;

    QItemSelectionModel *selections = selectionModel();
    QStyleOptionViewItem option = viewOptions();

    QPen foreground(option.palette.color(QPalette::WindowText));

    QPainter painter(viewport());
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(foreground);

    QRect pieRect = QRect(margin, margin, pieSize, pieSize);

    painter.save();
    painter.translate(pieRect.x() - horizontalScrollBar()->value(),
                      pieRect.y() - verticalScrollBar()->value());
    painter.drawEllipse(0, 0, pieSize, pieSize);
    double startAngle = 0.0;
    int row;

    for (row = 0; row < model()->rowCount(rootIndex()); ++row) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        double value = model()->data(index).toDouble();

        if (value > 0.0) {
            double angle = 360 * value / totalValue;

            QModelIndex colorIndex = model()->index(row, 0, rootIndex());
            QColor color = QColor(model()->data(colorIndex, Qt::DecorationRole).toString());

            if (currentIndex() == index)
                painter.setBrush(QBrush(color, Qt::Dense4Pattern));
            else if (selections->isSelected(index))
                painter.setBrush(QBrush(color, Qt::Dense3Pattern));
            else
                painter.setBrush(QBrush(color));

            painter.drawPie(0, 0, pieSize, pieSize, int(startAngle * 16), int(angle * 16));

            startAngle += angle;
        }
    }
    painter.restore();

    int keyNumber = 0;

    for (row = 0; row < model()->rowCount(rootIndex()); ++row) {
        QModelIndex index = model()->index(row, 1, rootIndex());
        double value = model()->data(index).toDouble();

        if (value > 0.0) {
            QModelIndex labelIndex = model()->index(row, 0, rootIndex());

            QStyleOptionViewItem option = viewOptions();
            option.rect = visualRect(labelIndex);
            if (selections->isSelected(labelIndex))
                option.state |= QStyle::State_Selected;
            if (currentIndex() == labelIndex)
                option.state |= QStyle::State_HasFocus;
            itemDelegate()->paint(&painter, option, labelIndex);

            ++keyNumber;
        }
    }
}

QRect BPieView::itemRect(const QModelIndex &index) const {
    if (!index.isValid())
        return QRect();
    if (index.column() != 0)
        return viewport()->rect();

    QModelIndex valueIndex;

    valueIndex = model()->index(index.row(), 1);
    if (model()->data(valueIndex).toDouble() <= 0.0)
        return QRect();

    int validItemCount = 0;
    for (int row = index.row() - 1; row >= 0; --row) {
        if (model()->data(model()->index(row, 1, rootIndex())).toDouble() > 0.0)
            validItemCount++;
    }

    auto itemHeight = QFontMetricsF(viewOptions().font).height() * 1.25;
    return QRect(totalSize, qRound(margin + validItemCount * itemHeight), totalSize - margin,
                 qRound(itemHeight));
}

BPieView::BPieView(QWidget *parent) : QAbstractItemView(parent),
                                      itemCount(0) {}
