//    BabySmix - Ubuntu targetted baby game based on and inspired by Scott
//    Hanselman's much-loved Baby Smash! http://www.hanselman.com/babysmash/
//    Copyright (C) 2012  Rob Williamson
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QDeclarativeItem>

class Ellipse : public QDeclarativeItem
{
    Q_OBJECT

//    Q_PROPERTY(qreal width READ width WRITE setWidth NOTIFY widthChanged)
//    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

    QSizeF m_size;
    QColor m_color;
    QColor m_borderColor;
    uint m_borderWidth;

public:
    explicit Ellipse(QDeclarativeItem *parent = 0);

//    qreal width() const { return m_size.width(); }
//    void setWidth(qreal);

//    qreal height() const { return m_size.height(); }
//    void setHeight(qreal);

    QColor color() const { return m_color; }
    void setColor(const QColor& color);

private:
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);


signals:
    void widthChanged();
    void heightChanged();
    void colorChanged();

public slots:

};

QML_DECLARE_TYPE(Ellipse)

#endif // ELLIPSE_H
