import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 840
    height: 600
    visible: true;
    title: ("与C++集成")

    Text {
        id: text
        text: ob.getCurrentDateTime()
    }
}
