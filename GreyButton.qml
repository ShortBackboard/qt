import QtQuick

Rectangle {
    border.width: 5
    radius: 10
    width: 100
    height: 100
    color: "LightGrey"

    // 信号的声明
    signal clickAt(real x, real y)
    signal longClick



    // 信号的使用
    TapHandler {
        onTapped: (eventPoint) => clickAt(eventPoint.position.x,
                                            eventPoint.position.y)

        onLongPressed: longClick()
    }
}
