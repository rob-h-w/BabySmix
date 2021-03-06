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
#include "ellipse.h"

#include <QPainter>

Ellipse::Ellipse(QDeclarativeItem *parent) :
    QDeclarativeItem(parent),
    m_color(Qt::white),
    m_borderColor(Qt::black),
    m_borderWidth(1)
{
    setFlag(QGraphicsItem::ItemHasNoContents, false);
}

void Ellipse::setColor(const QColor &color)
{
    if (m_color == color)
        return;

    m_color = color;
    update();
    emit colorChanged();
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QDeclarativeItem::paint(painter, option, widget);
    QPen pen(m_borderColor, m_borderWidth);
    QBrush brush(m_color);

    painter->setBrush(brush);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, smooth());
    painter->setBackgroundMode(Qt::TransparentMode);

    painter->drawEllipse(0, 0, width(), height());
}
