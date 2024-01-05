// ChatItem.qml
import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    width: parent.width
    height: 100
    color: "lightblue"

    property string username: ""
    property string text: ""
    property string avatar: ""

    RowLayout {
        anchors.fill: parent
        spacing: 10
        Image {
            width: 50
            height: 50
            source: avatar
        }
        ColumnLayout {
            Text {
                text: username
                font.bold: true
            }
            Text {
                text: "hello world"
            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (!customInfoModel.judgeLoad(model.id)) {
                customInfoModel.sendMessage("#" + String(customInfoModel.getMyId()) + "#" + String(model.id));
                customInfoModel.setJudgeLoad(model.id);
            }
            toggleBottomBarVisibility(!bottomBar.visible);
            console.log("the user id is :", model.id);
            console.log("the user username is :", model.username);
            stackView.push("ConversationPage.qml", { username: model.username, id: model.id });
        }
    }
}
