import QtQuick
import QtQuick.Controls

Rectangle {
    // 别名，在别处可以调用
    property alias buttonText: textItem.text

    width: 300
    height: 150
    visible: true

    Text {
        id: textItem
    }
}
