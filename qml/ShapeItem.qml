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
import QtQuick 1.0
import "utils.js" as U

ContentItem {
    property string name: ""
    property variant colorTuple: U.randomColor()

    onColorTupleChanged: if (colorTuple !== undefined) color = colorTuple.color

    function initialize(){
        narrator.say(qsTr("%1 %0").format(name, colorTuple.name))
    }
}
