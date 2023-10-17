/*
 * 使用 connect 函数手工连接信号或函数 以及 使用 disconnect 解除连接

   QML 的信号对象还提供了 connect() 函数
   支持将信号与一个方法或者另外的信号连接起来
*/

import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 600
    height: 450
    visible: true

    Rectangle {
        id: rect
        width: 400
        height: 300

        signal send(string message)

        // 连接信号和方法
        Component.onCompleted: {
            rect.send.connect(sendMessage)
            rect.send.connect(receiveMessage)
            rect.send("hello from Qml")
        }


        function sendMessage(message)
        {
            console.log("send message" + message)
        }

        function receiveMessage(message)
        {
            console.log("receive message" + message)
        }

        function disconnectReceiveMessage()
        {
            console.log("disconnect receiveMessage")
            rect.send.disconnect(receiveMessage)
        }


        Button {
            id:con
            anchors.centerIn: parent
            text: "connection"
        }

        Button {
            id:discon
            text: "disconnection"
        }

        Connections {
            target: con
            function onClicked() {
                rect.send("from Button")
            }
        }

        Connections {
            target: discon
            function onClicked() {
                rect.disconnectReceiveMessage()
            }
        }
    }

}





















