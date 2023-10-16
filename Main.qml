import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 840
    height: 600
    visible: true;

    Text {
        anchors.centerIn: parent

        text: msg.author

        Component.onCompleted:
        {
            msg.author = "Tom"
        }
    }
}
