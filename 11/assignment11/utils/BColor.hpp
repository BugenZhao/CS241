//
// Created by Bugen Zhao on 2019/11/24.
//

#ifndef PIECHART_BCOLOR_HPP
#define PIECHART_BCOLOR_HPP

#include <QRandomGenerator>
#include <QColor>

class BColor {
public:
    static QVector<QColor> random(int count) {
        auto h = QRandomGenerator::global()->bounded(360.0);
        auto d = 360.0 / count;
        QVector<QColor> colors(count);
        for (int i = 0; i < count; ++i) {
            colors[i] = QColor::fromHsl(qRound(h + i * d) % 360, 200, 200);
        }
        return colors;
    }
};

#endif //PIECHART_BCOLOR_HPP
