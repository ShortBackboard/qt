/*
 * 使用 connections 类型手工连接信号
*/

import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: window
    width: 600
    height: 450
    visible: true

    Button {
        id:button
        anchors.centerIn: parent
        text: "change color"
    }

    Connections {
        target: button
        function onClicked() {
            window.color = Qt.rgba(Math.random(),
                                   Math.random(),
                                   Math.random())
        }

    }


}





















