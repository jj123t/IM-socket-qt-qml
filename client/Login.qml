import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Login"

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Column {
            anchors.centerIn: parent
            spacing: 10

            TextField {
                id: usernameInput
                placeholderText: "Username"
                width: 200
            }

            TextField {
                id: passwordInput
                placeholderText: "Password"
                width: 200
                echoMode: TextInput.Password
            }

            Button {
                text: "Login"
                onClicked: {
                    customInfoModel.sendMessage("$" + usernameInput.text + "#" + passwordInput.text + "#" + String(customInfoModel.getSockfd()));
                    console.log("the message to server : " + "$" + usernameInput.text + "#" + passwordInput.text + "#" + String(customInfoModel.getSockfd()));
                }
            }
        }
    }

    Connections {
        target: customInfoModel
        function onLoginAccept() {
            //console.log("Signal received with value:", value);
            Qt.createComponent("main.qml").createObject(Qt.application);
            close();
        }
    }

    signal loggedInSignal
}
