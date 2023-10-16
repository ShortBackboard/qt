import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 600
    height: 450
    visible: true

    MyButton {
        id: bt
    }

    Rectangle {
        x:200

        width: 50
        height: 50
        color: "blue"

        TapHandler{
            onTapped: bt.buttonText = "Click Me"
        }
    }

}
