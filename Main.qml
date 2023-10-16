import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    id:window
    width: 300
    height: 300
    visible: true

    // Qml信号
    signal qmlSignal(obj : QtObject)

    // 点击事件
    // 把window对象作为参数进行传递
    TapHandler
    {
        onTapped: window.qmlSignal(window)
    }
}
