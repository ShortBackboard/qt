import QtQuick
import QtQuick.Controls
import QtQuick.Window

Window {
    id:window
    width: 300
    height: 300
    visible: true

    // Qml信号
    signal qmlSignal(msg : string)

    // 点击事件
    TapHandler
    {
        onTapped: window.qmlSignal("Qml发送信号")
    }
}
