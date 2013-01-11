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
.pragma library

function randomColor() {
    var returnValue = {}
    var selector = Math.floor(Math.random()*14.99)

    switch(selector) {
    case 0:
        returnValue.name = qsTr("black")
        returnValue.color = "black"
        break
    case 1:
        returnValue.name = qsTr("blue")
        returnValue.color = "blue"
        break
    case 2:
        returnValue.name = qsTr("cyan")
        returnValue.color = "cyan"
        break
    case 3:
        returnValue.name = qsTr("dark Blue")
        returnValue.color = "darkBlue"
        break
    case 4:
        returnValue.name = qsTr("dark Cyan")
        returnValue.color = "darkCyan"
        break
    case 5:
        returnValue.name = qsTr("gray")
        returnValue.color = "darkGray"
        break
    case 6:
        returnValue.name = qsTr("dark Green")
        returnValue.color = "darkGreen"
        break
    case 7:
        returnValue.name = qsTr("dark Magenta")
        returnValue.color = "darkMagenta"
        break
    case 8:
        returnValue.name = qsTr("dark Red")
        returnValue.color = "darkRed"
        break
    case 9:
        returnValue.name = qsTr("dark Gray")
        returnValue.color = "gray"
        break
    case 10:
        returnValue.name = qsTr("green")
        returnValue.color = "green"
        break
    case 11:
        returnValue.name = qsTr("magenta")
        returnValue.color = "magenta"
        break
    case 12:
        returnValue.name = qsTr("red")
        returnValue.color = "red"
        break
    default:
        returnValue.name = qsTr("yellow")
        returnValue.color = "yellow"
        break
    }

    return returnValue
}

function randomMinMax(min, max)
{
    return Math.random()*(max - min) + min
}

function randomPlusMinus(min, max)
{
    var returnValue = Math.random()*max*2 - max
    var positive = returnValue >= 0

    if (Math.abs(returnValue) >= min)
    {
        return returnValue
    }

    if (positive)
    {
        return min
    }

    return -min
}
