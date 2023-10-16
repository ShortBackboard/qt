import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 840
    height: 600
    visible: true;

    ListView {
        width: 100
        height: 100
        model: myModel
        delegate: Rectangle {
            height: 25
            width: 100
            Text {
                text: modelData
            }
        }
    }
}
