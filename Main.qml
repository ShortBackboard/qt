import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 600
    height: 450
    visible: true

    GreyButton {
        id:greyButton

        // 信号的定义
        onClickAt: (x, y) => {
                    console.log("clicked at (" + x + "," + y + ")")
                   }

        onLongClick: console.log("long clicked")
    }


    // 在别的对象中调用GreyButton的信号
    Rectangle {
        anchors.left: greyButton.right
        width: greyButton.width
        height: greyButton.height
        color: "blue"

        TapHandler {
            onTapped: (eventPoint) => {
                          greyButton.clickAt(eventPoint.position.x,
                                             eventPoint.position.y)
                      }
        }
    }

}





















