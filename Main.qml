import QtQuick
import QtQuick.Controls
import QtQuick.Window
import "add.js" as Add

ApplicationWindow
{
    width: 500
    height: 500
    visible: true

    Text {
        text: ("1 + 1 = ") + Add.add(1, 1)
    }

}
