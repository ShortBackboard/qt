import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 600
    height: 450
    visible: true

    onWidthChanged: console.log("width changed")

    Rectangle {
        id:rect
        width: 100
        height: 100
        TapHandler {
            onTapped: (handlerPoint) => {
                rect.color = Qt.rgba(Math.random(),
                                     Math.random(),
                                     Math.random())

                //handlerPoint参数是一个 HandlerPoint 类型的对象,包含了更丰富的事件信息
                console.log("click at ", handlerPoint.position.x,
                            handlerPoint.position.y)
            }
        }
    }


}





















